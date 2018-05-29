#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <ferns_detector/Detection.h>
#include <ferns_detector/DetectedPoint.h>
#include <ferns_detector/ModelStatus.h>
#include "ferns/mcv.h"
#include "ferns/planar_pattern_detector_builder.h"
#include "ferns/template_matching_based_tracker.h"

using namespace cv;
using namespace std;
using namespace ferns_detector;
namespace enc = sensor_msgs::image_encodings;

const int max_filename = 1000;

enum source_type {webcam_source, sequence_source, video_source};

/*
0: Detect when tracking fails or for initialization then track.
1: Track only
2: Detect only (DEFAULT)
3: Detect + track in every frame
*/
int mode = 2;
//Show CV window with ferns detections
bool show_tracked_locations = true;
bool show_keypoints = false;


void draw_quadrangle(Mat& frame, int u0, int v0, int u1, int v1,int u2, int v2, int u3, int v3, Scalar color, int thickness, Detection& detection) {

  //Create msgs to publish detections on a topic
  detection.top_left.x = u0; detection.top_left.y = v0;
	detection.top_right.x = u1; detection.top_right.y = v1;
	detection.bottom_right.x = u2; detection.bottom_right.y = v2;
	detection.bottom_left.x = u3; detection.bottom_left.y = v3;

  cv::line(frame, cv::Point(u0, v0), cv::Point(u1, v1), color, thickness);
  cv::line(frame, cv::Point(u1, v1), cv::Point(u2, v2), color, thickness);
  cv::line(frame, cv::Point(u2, v2), cv::Point(u3, v3), color, thickness);
  cv::line(frame, cv::Point(u3, v3), cv::Point(u0, v0), color, thickness);

}

void draw_detected_position(Mat& frame, planar_pattern_detector* detector, Detection& detection)
{
  draw_quadrangle(frame,
		  detector->detected_u_corner[0], detector->detected_v_corner[0],
		  detector->detected_u_corner[1], detector->detected_v_corner[1],
		  detector->detected_u_corner[2], detector->detected_v_corner[2],
		  detector->detected_u_corner[3], detector->detected_v_corner[3],
		  cvScalar(255), 3, detection);
}

void draw_initial_rectangle(Mat& frame, template_matching_based_tracker* tracker, Detection& detection)
{
  draw_quadrangle(frame,
		  tracker->u0[0], tracker->u0[1],
		  tracker->u0[2], tracker->u0[3],
		  tracker->u0[4], tracker->u0[5],
		  tracker->u0[6], tracker->u0[7],
		  cvScalar(128), 3, detection);
}

void draw_tracked_position(Mat& frame, template_matching_based_tracker* tracker, Detection& detection)
{
  draw_quadrangle(frame,
		  tracker->u[0], tracker->u[1],
		  tracker->u[2], tracker->u[3],
		  tracker->u[4], tracker->u[5],
		  tracker->u[6], tracker->u[7],
		  cvScalar(255), 3, detection);
}

void draw_tracked_locations(Mat& frame, template_matching_based_tracker * tracker)
{
  for(int i = 0; i < tracker->nx * tracker->ny; i++) {
    int x1, y1;
    tracker->f.transform_point(tracker->m[2 * i], tracker->m[2 * i + 1], x1, y1);
    cv::circle(frame, cv::Point(x1, y1), 3, cv::Scalar(255, 255, 255), 1);
  }
}

void draw_detected_keypoints(Mat& frame, planar_pattern_detector * detector)
{
  for(int i = 0; i < detector->number_of_detected_points; i++)
    cv::circle(frame,
	     cv::Point(detector->detected_points[i].fr_u(),
		     detector->detected_points[i].fr_v()),
	     16 * (1 << int(detector->detected_points[i].scale)),
	     cv::Scalar(100), 1);
}

void draw_recognized_keypoints(Mat& frame, planar_pattern_detector * detector)
{
  for(int i = 0; i < detector->number_of_model_points; i++)
    if (detector->model_points[i].class_score > 0)
      cv::circle(frame,
	       cv::Point(detector->model_points[i].potential_correspondent->fr_u(),
		       detector->model_points[i].potential_correspondent->fr_v()),
	       16 * (1 << int(detector->detected_points[i].scale)),
	       cv::Scalar(255, 255, 255), 1);
}


bool detect_and_draw(planar_pattern_detector * detector,
        template_matching_based_tracker * tracker, Mat& frame, Detection& detection, Mat& canvas) {

	static bool last_frame_ok=false;

    IplImage iplFrame = frame;

	if (mode == 1 || ((mode==0) && last_frame_ok)) {
		bool ok = tracker->track(&iplFrame);
		last_frame_ok=ok;

		if (!ok) {
			if (mode==0) {
                detect_and_draw(detector, tracker, frame, detection, canvas);
                return true;
        } else {
				if (!canvas.empty()) draw_initial_rectangle(canvas, tracker, detection);
				tracker->initialize();
			}
		} else {

			if (!canvas.empty()) draw_tracked_position(canvas, tracker, detection);
			if (!canvas.empty() && show_tracked_locations) draw_tracked_locations(canvas, tracker);

		}

	} else {
		detector->detect(&iplFrame);

		if (detector->pattern_is_detected) {

			last_frame_ok=true;

			tracker->initialize(detector->detected_u_corner[0], detector->detected_v_corner[0],
					detector->detected_u_corner[1], detector->detected_v_corner[1],
					detector->detected_u_corner[2], detector->detected_v_corner[2],
					detector->detected_u_corner[3], detector->detected_v_corner[3]);

			if (mode == 3 && tracker->track(&iplFrame)) {

                if (!canvas.empty()) {
				    if (show_keypoints) {
					    draw_detected_keypoints(canvas, detector);
					    draw_recognized_keypoints(canvas, detector);
				    }
			        draw_tracked_position(canvas, tracker, detection);

				    if (show_tracked_locations) draw_tracked_locations(canvas, tracker);
                }
			} else {
                if (!canvas.empty()) {
				    if (show_keypoints) {
					    draw_detected_keypoints(canvas, detector);
					    draw_recognized_keypoints(canvas, detector);
				    }
				    draw_detected_position(canvas, detector, detection);
                }
			}
		} else {
			last_frame_ok=false;
			if (!canvas.empty() && show_keypoints) draw_detected_keypoints(canvas, detector);

		}
	}
  
  return last_frame_ok;
}

void
split( vector<string> & theStringVector,  /* Altered/returned value */
       const string & theString, const string & theDelimiter)
{
    size_t  start = 0, end = 0;

    while ( end != string::npos)
    {
        end = theString.find( theDelimiter, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        theStringVector.push_back( theString.substr(start, (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = (( end > (string::npos - theDelimiter.size()) ) ? string::npos  :  end + theDelimiter.size());
    }
}

typedef struct {
    string name;
    string path;
    planar_pattern_detector * detector;
    template_matching_based_tracker * tracker;
    bool loaded;
    bool loading;
    bool active;
} Model;

cv_bridge::CvImagePtr bridge;

bool SHOW_CV_WINDOW;
bool LOAD_AT_START;
bool ACTIVATE_AT_START;
string IMAGE_TOPIC;
Mat canvas;

ros::Publisher detection;
ros::Publisher status;

std::map<string, Model> models;

void parseModels(string input) {

    vector<string> n;

    split(n, input, string(";"));

    for (int i = 0; i < n.size(); i++) {

        string name("default");
        string path = n[i];
        size_t j = n[i].find("=");

        if (j != string::npos) {
            name = n[i].substr(0, j);
            path = n[i].substr(j+1, string::npos);
        }

        Model model;
        model.name = name;
        model.path = path;
        model.detector = NULL;
        model.tracker = NULL;
        model.loaded = false;
        model.loading = false;
        model.active = false;

        models[name] = model;

    }

}

bool loadModel(string name) {

    if (!models.count(name)) return false;

    Model model = models[name];

    if (model.loading) return false;

    if (model.loaded) return true;

    ROS_INFO("Loading model '%s'", name.c_str());

    model.loading = true;

    string detector_model = model.path + string(".detector_data");

    model.detector = planar_pattern_detector_builder::just_load(detector_model.c_str());

    if (!model.detector) {
        ROS_ERROR("Unable to load detector for image '%s'", model.path.c_str());
        return false;
    }

    model.detector->set_maximum_number_of_points_to_detect(1000);
    model.tracker = new template_matching_based_tracker();

    string tracker_model = model.path + string(".tracker_data");

    if (!model.tracker->load(tracker_model.c_str())) {
        ROS_ERROR("Unable to load tracker for image '%s'", model.path.c_str());
        delete model.detector;
        return false;    
    }

    model.tracker->initialize();

    model.loading = false;
    model.loaded = true;

    models[name] = model;

    ROS_INFO("Loaded model '%s'", name.c_str());

    return true;
}

bool unloadModel(string name) {

    if (!models.count(name)) return false;

    Model model = models[name];

    if (!model.loaded) return false;

    ROS_INFO("Unloading model '%s'", name.c_str());

    model.active = false;
    model.loaded = false;

    delete model.detector;
    delete model.tracker;

    models[name] = model;

    return true;
}

bool activateModel(string name) {

    if (!models.count(name)) return false;

    Model model = models[name];

    if (!model.loaded) return false;

    ROS_INFO("Activating model '%s'", name.c_str());

    model.active = true;

    models[name] = model;

    return true;
}

bool deactivateModel(string name) {

    if (!models.count(name)) return false;

    Model model = models[name];

    if (!model.loaded) return false;

    ROS_INFO("Deactivating model '%s'", name.c_str());

    model.active = false;

    models[name] = model;

    return true;
}


/*Callback for color image from kinect*/
void imageReceiver(const sensor_msgs::ImageConstPtr& image) { 
 
    try{
        bridge = cv_bridge::toCvCopy(image, enc::MONO8);
    }
    catch (cv_bridge::Exception& e){
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }  

    if(SHOW_CV_WINDOW) {
        bridge->image.copyTo(canvas);
    }

    std::map<string, Model>::iterator it;

    for (std::map<string, Model>::iterator it=models.begin(); it!=models.end(); ++it) {

        if (!it->second.active) continue;

        Detection detectionMsg;

        if(detect_and_draw(it->second.detector, it->second.tracker, bridge->image, detectionMsg, canvas)) {
            detectionMsg.header = image->header;
            detectionMsg.model = it->first;	
            detection.publish(detectionMsg);
        }

    }

    // Show ferns detections in CV window.
    if(SHOW_CV_WINDOW) {
	    cv::imshow("Ferns", canvas);
        cv::waitKey(1);
    }

}

void statusReceiver(const ModelStatus& newStatus) { 

    ROS_INFO("New status %s ", newStatus.model.c_str());

    if (!models.count(newStatus.model)) return;

    Model model = models[newStatus.model];

    if (newStatus.active && !newStatus.loaded) {

        ModelStatus statusMsg;

        statusMsg.model = model.name;
        statusMsg.active = model.active;
        statusMsg.loaded = model.loaded;

        status.publish(statusMsg);

        return;
    }

    if (newStatus.loaded) {
        loadModel(newStatus.model);

        if (newStatus.active) {

            activateModel(newStatus.model);

        } else {

            deactivateModel(newStatus.model);

        }
    }
    else {
        unloadModel(newStatus.model);
    }

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ferns_detector");

    string models_path;

    ros::NodeHandle n;

    n.param("ferns_detector/show_cv_window", SHOW_CV_WINDOW, true);
    n.param("ferns_detector/load_at_start", LOAD_AT_START, true);
    n.param("ferns_detector/activate_at_start", ACTIVATE_AT_START, true);
    n.param("ferns_detector/image_topic", IMAGE_TOPIC, string("/camera/rgb/image_color"));
    n.param("ferns_detector/model", models_path, string("model.jpg"));

    parseModels(models_path);

    if (LOAD_AT_START) {

        std::map<string, Model>::iterator it;

        for (std::map<string, Model>::iterator it=models.begin(); it!=models.end(); ++it) {
            loadModel(it->first);
            if (ACTIVATE_AT_START) activateModel(it->first);
        }

    }


  //ROS handle has to be after detector initialization. Otherwise we get seg fault because of Ferns library!
  //ros::NodeHandle n;


    if (SHOW_CV_WINDOW) {
      cv::namedWindow("Ferns", CV_WINDOW_AUTOSIZE); 
    }

    detection = n.advertise<Detection>("detection", 1000);
    status = n.advertise<ModelStatus>("get_status", 1000);
    ros::Subscriber image_sub = n.subscribe(IMAGE_TOPIC, 10, imageReceiver);
    ros::Subscriber stat_sub = n.subscribe("set_status", 10, statusReceiver);

	ros::spin(); 

	if(!ros::ok())
	{
		clog << endl;
        std::map<string, Model>::iterator it;

        for (std::map<string, Model>::iterator it=models.begin(); it!=models.end(); ++it) {
            unloadModel(it->first);
        }

		if (SHOW_CV_WINDOW) cvDestroyWindow("Ferns");
	}


  return 0;
  
}

