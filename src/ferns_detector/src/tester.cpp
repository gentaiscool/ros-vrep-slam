#include "ros/ros.h"
#include <sstream>
#include <string.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "ferns/mcv.h"
#include "ferns/planar_pattern_detector_builder.h"
#include "ferns/template_matching_based_tracker.h"

using namespace std;
using namespace cv;

planar_pattern_detector * detector;
template_matching_based_tracker * tracker;

#define TITLE "Test"

void showimage(Mat& image, string title, bool halt) {

    namedWindow(title,CV_WINDOW_AUTOSIZE);
    imshow(title, image);

    if (halt) {
        while(true) {
            char key = waitKey(30);
            if(key >= 0) break;
        }
    }
}



int main(int argc, char **argv) {

  ros::init(argc, argv, "trainer");

  if (argc < 2) {
    ROS_ERROR("No training image provided. Exiting.");
    return -1;
  }

  string model_image = string(argv[1]);

  string detector_model = model_image + string(".detector_data");

  detector = planar_pattern_detector_builder::just_load(detector_model.c_str());

  if (!detector) {
    ROS_ERROR("Unable to load detector for image '%s'", model_image.c_str());
    return -1;
  }

  detector->set_maximum_number_of_points_to_detect(1000);
  tracker = new template_matching_based_tracker();

  string tracker_model = model_image + string(".tracker_data");

  if (!tracker->load(tracker_model.c_str())) {
    ROS_ERROR("Unable to load tracker for image '%s'", model_image.c_str());
    return -1;    
  }

  Mat image = imread(model_image);
  Mat frame;
  cvtColor(image, frame, CV_RGB2GRAY);
  IplImage iplFrame = frame;

  detector->detect(&iplFrame);

  ROS_INFO("Tracker built successfully.");

  return 0;
  
}

