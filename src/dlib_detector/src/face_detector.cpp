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

#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include <detection_msgs/Detection.h>
#include <std_msgs/Bool.h>

using namespace std;
using namespace dlib;

frontal_face_detector detector_face;
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
    std::vector<dlib::rectangle> rects = detector_face(image);

    cv::Rect image_region(0, 0, cv_ptr->image.cols, cv_ptr->image.rows);
	for (int i = 0; i < rects.size(); i++) {
		dlib::rectangle cur = rects[i];
        cv_image<bgr_pixel> chip;
        cv::Rect region(cur.left(), cur.top(), cur.width(), cur.height());
        cv_bridge::CvImage cvi(cv_ptr->header, cv_ptr->encoding, cv_ptr->image(region & image_region));

		detection_msgs::Detection msg = detection_msgs::Detection();
        msg.header.seq = message_counter++;
        msg.header.stamp = cam_msg->header.stamp;
        msg.header.frame_id = cam_msg->header.frame_id;
		msg.x = cur.left();
		msg.y = cur.top();
		msg.height = cur.height();
		msg.width = cur.width();
        msg.confidence = 1;
        msg.source = "dlib face";
        cvi.toImageMsg(msg.image);
		pub.publish(msg);
	}

}

void toggleCallback(const std_msgs::Bool& toggle) {

	active = toggle.data;

}

int main(int argc, char** argv) {

    string detector_file, classifier_file;

	ros::init (argc, argv, "face_detector");
	ros::NodeHandle nh;
	ros::NodeHandle nhp("~");

    detector_face = get_frontal_face_detector();

	ros::Subscriber sub = nh.subscribe ("camera", 1, detectCallback);
    ros::Subscriber tog = nh.subscribe ("toggle", 1, toggleCallback);

	pub = nh.advertise<detection_msgs::Detection> ("detections", 1);

	ros::spin();
	return 0;
}
