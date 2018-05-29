
#include <dlib/svm.h>
#include <dlib/svm_threaded.h>
#include <dlib/string.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/cmd_line_parser.h>

#include <iostream>
#include <fstream>
#include <set>
#include <vector>

//#include "multiclass.h"

using namespace std;
using namespace dlib;

template <
    typename image_type, 
    typename MM
    >
void load_image_dataset (
    dlib::array<image_type,MM>& images,
    std::vector<std::vector<rectangle> >& object_locations,
    std::vector<std::vector<string > >& object_labels,
    const image_dataset_file& source
)
{
    images.clear();
    object_locations.clear();
    const string old_working_dir = get_current_dir();

    using namespace dlib::image_dataset_metadata;
    dataset data;
    load_image_dataset_metadata(data, source.get_filename());

    // Set the current directory to be the one that contains the
    // metadata file. We do this because the file might contain
    // file paths which are relative to this folder.
    set_current_dir(get_parent_directory(file(source.get_filename())));

    image_type img;
    std::vector<rectangle> rects;
    std::vector<string> labels;
    for (unsigned long i = 0; i < data.images.size(); ++i)
    {
        rects.clear();
        for (unsigned long j = 0; j < data.images[i].boxes.size(); ++j)
        {
            if (source.should_load_box(data.images[i].boxes[j]))
            {
                rects.push_back(data.images[i].boxes[j].rect);
                labels.push_back(data.images[i].boxes[j].label);
            }
        }

        if (!source.should_skip_empty_images() || rects.size() != 0)
        {
            object_locations.push_back(rects);
            object_labels.push_back(labels);
            load_image(img, data.images[i].filename);
            images.push_back(img);
        }
    }

    set_current_dir(old_working_dir);
}

void pick_best_window_size (
    const std::vector<std::vector<rectangle> >& boxes,
    unsigned long& width,
    unsigned long& height,
    const unsigned long target_size
)
{
    // find the average width and height
    running_stats<double> avg_width, avg_height;
    for (unsigned long i = 0; i < boxes.size(); ++i)
    {
        for (unsigned long j = 0; j < boxes[i].size(); ++j)
        {
            avg_width.add(boxes[i][j].width());
            avg_height.add(boxes[i][j].height());
        }
    }

    // now adjust the box size so that it is about target_pixels pixels in size
    double size = avg_width.mean()*avg_height.mean();
    double scale = sqrt(target_size/size);

    width = (unsigned long)(avg_width.mean()*scale+0.5);
    height = (unsigned long)(avg_height.mean()*scale+0.5);
    // make sure the width and height never round to zero.
    if (width == 0)
        width = 1;
    if (height == 0)
        height = 1;
}

bool contains_any_boxes (
    const std::vector<std::vector<rectangle> >& boxes
)
{
    for (unsigned long i = 0; i < boxes.size(); ++i)
    {
        if (boxes[i].size() != 0)
            return true;
    }
    return false;
}

void throw_invalid_box_error_message (
    const string& dataset_filename,
    const std::vector<std::vector<rectangle> >& removed,
    const unsigned long target_size
)
{
    image_dataset_metadata::dataset data;
    load_image_dataset_metadata(data, dataset_filename);

    ostringstream sout;
    sout << "Error!  An impossible set of object boxes was given for training. ";
    sout << "All the boxes need to have a similar aspect ratio and also not be ";
    sout << "smaller than about " << target_size << " pixels in area. ";
    sout << "The following images contain invalid boxes:\n";
    ostringstream sout2;
    for (unsigned long i = 0; i < removed.size(); ++i)
    {
        if (removed[i].size() != 0)
        {
            const string imgname = data.images[i].filename;
            sout2 << "  " << imgname << "\n";
        }
    }
    throw error("\n"+wrap_string(sout.str()) + "\n" + sout2.str());
}

int main(int argc, char** argv)
{  
    try
    {
        command_line_parser parser;
        parser.add_option("h","Display this help message.");
        parser.add_option("t","Train an object detector and save the detector to disk.");
        parser.add_option("separate","If samples with multiple labels are present train separate detector for each class.");
        parser.add_option("test", "Test a trained detector on an image dataset and print the results.");
        parser.add_option("u", "Upsample each input image <arg> times. Each upsampling quadruples the number of pixels in the image (default: 0).", 1);
        parser.set_group_name("training options");
        parser.add_option("v","Be verbose.");
        parser.add_option("c","Set the SVM C parameter to <arg> (default: 1.0).",1);
        parser.add_option("threads", "Use <arg> threads for training <arg> (default: 4).",1);
        parser.add_option("eps", "Set training epsilon to <arg> (default: 0.01).", 1);
        parser.add_option("target-size", "Set size of the sliding window to about <arg> pixels in area (default: 80*80).", 1);

        parser.parse(argc, argv);

        const char* one_time_opts[] = {"h", "v", "t", "c", "separate", "threads", "target-size",
                                        "test", "eps", "u"};
        parser.check_one_time_options(one_time_opts); 
        parser.check_option_arg_range("c", 1e-12, 1e12);
        parser.check_option_arg_range("eps", 1e-5, 1e4);
        parser.check_option_arg_range("threads", 1, 1000);
        parser.check_option_arg_range("u", 0, 8);
        parser.check_option_arg_range("target-size", 4*4, 10000*10000);
        const char* incompatible[] = {"t", "test"};
        parser.check_incompatible_options(incompatible);
        // You are only allowed to give these training_sub_ops if you also give either -t.
        const char* training_ops[] = {"t"};
        const char* training_sub_ops[] = {"v", "c", "threads", "target-size", "eps", "separate"};
        parser.check_sub_options(training_ops, training_sub_ops); 


        if (parser.option("h"))
        {
            cout << "Usage: train_object_detector [options] <image dataset file|image file>\n";
            parser.print_options(); 
                                       
            return EXIT_SUCCESS;
        }


        typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type; 
        // Get the upsample option from the user but use 0 if it wasn't given.
        const unsigned long upsample_amount = get_option(parser, "u", 0);

        typedef array2d<unsigned char> image_type;

        if (parser.option("t"))
        {
            if (parser.number_of_arguments() != 1)
            {
                cout << "You must give an image dataset metadata XML file produced by the imglab tool." << endl;
                cout << "\nTry the -h option for more information." << endl;
                return EXIT_FAILURE;
            }

            dlib::array<image_type> images;
            std::vector<std::vector<rectangle> > object_locations;
            std::vector<std::vector<string > > object_labels;

            cout << "Loading image dataset from metadata file " << parser[0] << endl;
            load_image_dataset(images, object_locations, object_labels, parser[0]);
            cout << "Number of images loaded: " << images.size() << endl;

            std::set<string> labels;
            for (std::vector<std::vector<string> >::iterator it = object_labels.begin(); it != object_labels.end(); it++) {
                labels.insert((*it).begin(), (*it).end());
            }

            cout << "Number of labels in images: " << labels.size() << endl;

            // Get the options from the user, but use default values if they are not
            // supplied.
            const int threads = get_option(parser, "threads", 4);
            const double C   = get_option(parser, "c", 1.0);
            const double eps = get_option(parser, "eps", 0.01);
            const unsigned long target_size = get_option(parser, "target-size", 80*80);

            // Upsample images if the user asked us to do that.
            for (unsigned long i = 0; i < upsample_amount; ++i)
                upsample_image_dataset<pyramid_down<2> >(images, object_locations);


            image_scanner_type scanner;
            unsigned long width, height;
            pick_best_window_size(object_locations, width, height, target_size);
            scanner.set_detection_window_size(width, height); 

            structural_object_detection_trainer<image_scanner_type> trainer(scanner);
            trainer.set_num_threads(threads);
            if (parser.option("v"))
                trainer.be_verbose();
            trainer.set_c(C);
            trainer.set_epsilon(eps);

            // Now make sure all the boxes are obtainable by the scanner.  
            std::vector<std::vector<rectangle> > removed;
            removed = remove_unobtainable_rectangles(trainer, images, object_locations);
            // if we weren't able to get all the boxes to match then throw an error 
            if (contains_any_boxes(removed))
            {
                unsigned long scale = upsample_amount+1;
                scale = scale*scale;
                throw_invalid_box_error_message(parser[0], removed, target_size/scale);
            }

            // Do the actual training and save the results into the detector object.  
            object_detector<image_scanner_type> detector = trainer.train(images, object_locations);

            cout << "Testing detector on training data..." << endl;
            cout << "Test detector (precision,recall,AP): " << test_object_detection_function(detector, images, object_locations) << endl;
        
            cout << "Parameters used: " << endl;
            cout << "  threads:                 "<< threads << endl;
            cout << "  C:                       "<< C << endl;
            cout << "  eps:                     "<< eps << endl;
            cout << "  target-size:             "<< target_size << endl;
            cout << "  detection window width:  "<< width << endl;
            cout << "  detection window height: "<< height << endl;
            cout << "  upsample this many times : "<< upsample_amount << endl;
            cout << endl;

            cout << "Saving trained detector to object_detector.dat" << endl;
            serialize("object_detector.dat") << detector;

/*
            if (labels.size() > 1) {
                cout << "Training multi-class classifier" << endl;

                chip_dims chip_size(80, 80);

                dlib::array<image_type> all_samples;
                std::vector<string> all_labels;
                for (int i = 0; i < images.size(); i++) {
                    std::vector<chip_details> chip_locations;
                    for (std::vector<rectangle>::iterator it = object_locations[i].begin(); it != object_locations[i].end(); it++) {
                        chip_locations.push_back(chip_details(*it, chip_size));
                    }

                    all_labels.insert(all_labels.end(), object_labels[i].begin(), object_labels[i].end());

                    dlib::array<image_type> chips;

                    extract_image_chips(images[i], chip_locations, chips);

                    for (dlib::array<image_type>::iterator it = chips.begin(); it != chips.end(); it++) {
                        all_samples.push_back(*it);
                    }

                }


                fhog_multiclassifier<image_type, string> multiclassifier(200, 200);

                multiclassifier.train(all_samples, all_labels);
                
                cout << "Test classifictation (confusion matrix): " << endl;
                multiclassifier.test(all_samples, all_labels);

                cout << "Saving trained classifer to object_classifier.dat" << endl;
                serialize("object_classifier.dat") << multiclassifier;

            } 
*/
            return EXIT_SUCCESS;
        }

        // The rest of the code is devoted to testing an already trained object detector.

        if (parser.number_of_arguments() == 0)
        {
            cout << "You must give an image or an image dataset metadata XML file produced by the imglab tool." << endl;
            cout << "\nTry the -h option for more information." << endl;
            return EXIT_FAILURE;
        }

        // load a previously trained object detector and try it out on some data
        ifstream fin("object_detector.svm", ios::binary);
        if (!fin)
        {
            cout << "Can't find a trained object detector file object_detector.svm. " << endl;
            cout << "You need to train one using the -t option." << endl;
            cout << "\nTry the -h option for more information." << endl;
            return EXIT_FAILURE;

        }
        object_detector<image_scanner_type> detector;
        deserialize(detector, fin);

        dlib::array<array2d<unsigned char> > images;
        // Check if the command line argument is an XML file
        if (tolower(right_substr(parser[0],".")) == "xml")
        {
            std::vector<std::vector<rectangle> > object_locations, ignore;
            cout << "Loading image dataset from metadata file " << parser[0] << endl;
            ignore = load_image_dataset(images, object_locations, parser[0]);
            cout << "Number of images loaded: " << images.size() << endl;

            // Upsample images if the user asked us to do that.
            for (unsigned long i = 0; i < upsample_amount; ++i)
                upsample_image_dataset<pyramid_down<2> >(images, object_locations, ignore);

            if (parser.option("test"))
            {
                cout << "Testing detector on data..." << endl;
                cout << "Results (precision,recall,AP): " << test_object_detection_function(detector, images, object_locations, ignore) << endl;
                return EXIT_SUCCESS;
            }
        }
        else
        {
            // In this case, the user should have given some image files.  So just
            // load them.
            images.resize(parser.number_of_arguments());
            for (unsigned long i = 0; i < images.size(); ++i)
                load_image(images[i], parser[i]);

            // Upsample images if the user asked us to do that.
            for (unsigned long i = 0; i < upsample_amount; ++i)
            {
                for (unsigned long j = 0; j < images.size(); ++j)
                    pyramid_up(images[j]);
            }
        }


        // Test the detector on the images we loaded and display the results
        // in a window.
        image_window win;
        for (unsigned long i = 0; i < images.size(); ++i)
        {
            // Run the detector on images[i] 
            const std::vector<rectangle> rects = detector(images[i]);
            cout << "Number of detections: "<< rects.size() << endl;

            // Put the image and detections into the window.
            win.clear_overlay();
            win.set_image(images[i]);
            win.add_overlay(rects, rgb_pixel(255,0,0));

            cout << "Hit enter to see the next image.";
            cin.get();
        }


    }
    catch (exception& e)
    {
        cout << "\nexception thrown!" << endl;
        cout << e.what() << endl;
        cout << "\nTry the -h option for more information." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------------------------

