/* HOG DETECTOR
 *
 */

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

#include <dlib/svm_threaded.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/image_transforms.h>
#include <dlib/opencv.h>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include <detection_msgs/Detection.h>
#include <std_msgs/Bool.h>

//#include "multiclass.h"

using namespace std;
using namespace dlib;

typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;
object_detector<image_scanner_type> object_detector_function;
ros::Publisher pub;
unsigned long message_counter = 0;
bool active = true;

void detectCallback(const sensor_msgs::ImageConstPtr& cam_msg) {
	if (!active) return;

	cv_bridge::CvImagePtr cv_ptr;
	const unsigned long upsample_amount = 0;
	try {
		cv_ptr = cv_bridge::toCvCopy(cam_msg, sensor_msgs::image_encodings::BGR8);
	}
	catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}

	// dlib wrapper for OpenCV
	cv_image<bgr_pixel> image = cv_image<bgr_pixel>(cv_ptr->image);
	std::vector<std::pair<double, rectangle> > rects;
    object_detector_function(image, rects);

    cv::Rect image_region(0, 0, cv_ptr->image.cols, cv_ptr->image.rows);

	for (int i = 0; i < rects.size(); i++) {
		std::pair<double, rectangle> cur = rects[i];
        cv_image<bgr_pixel> chip;
        cv::Rect region(cur.second.left(), cur.second.top(), cur.second.width(), cur.second.height());
        cv_bridge::CvImage cvi(cv_ptr->header, cv_ptr->encoding, cv_ptr->image(region & image_region));

		detection_msgs::Detection msg = detection_msgs::Detection();
        msg.header.seq = message_counter++;
        msg.header.stamp = cam_msg->header.stamp;
        msg.header.frame_id = cam_msg->header.frame_id;
		msg.x = cur.second.left();
		msg.y = cur.second.top();
		msg.height = cur.second.height();
		msg.width = cur.second.width();
        msg.confidence = cur.first;
        msg.source = "dlib";
        cvi.toImageMsg(msg.image);
		pub.publish(msg);
	}

}

void toggleCallback(const std_msgs::Bool& toggle) {

	active = toggle.data;

}

int main(int argc, char** argv) {

    string detector_file, classifier_file;

	ros::init (argc, argv, "object_detector");
	ros::NodeHandle nh;
	ros::NodeHandle nhp("~");

	ros::Subscriber sub = nh.subscribe ("camera", 1, detectCallback);
    ros::Subscriber tog = nh.subscribe ("toggle", 1, toggleCallback);

	pub = nh.advertise<detection_msgs::Detection> ("detections", 1);

    nhp.param<string>("detector", detector_file, string(""));

    if (detector_file.empty())
        return -1;

	dlib::deserialize (detector_file) >> object_detector_function;

	ros::spin();
	return 0;
}
