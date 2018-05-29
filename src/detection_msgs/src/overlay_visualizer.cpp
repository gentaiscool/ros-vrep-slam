#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <vector>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <detection_msgs/Detection.h>

using namespace std;

vector<detection_msgs::Detection> detection_buffer;
double cleanup_delay = 0;

void detectionsCallback(const detection_msgs::Detection& msg) {

	detection_buffer.push_back(msg);

}

void imageCallback(const sensor_msgs::ImageConstPtr& cam_msg) {
	cv_bridge::CvImagePtr cv_ptr;
	const unsigned long upsample_amount = 0;

	try {
		cv_ptr = cv_bridge::toCvCopy(cam_msg, sensor_msgs::image_encodings::BGR8);
	}
	catch (cv_bridge::Exception& e) {
		return;
	}

	for (int i = 0; i < detection_buffer.size(); i++) {
		detection_msgs::Detection current = detection_buffer.at(i);
		cv::Rect r(current.x, current.y, current.width, current.height);
		cv::rectangle(cv_ptr->image, r, cv::Scalar(255, 255, 255), 2);
        string label = cv::format("%s (%.2f)", current.source.c_str(), current.confidence);
		cv::putText(cv_ptr->image, label, cv::Point(current.x + 5, current.y + current.width / 2 - 20),
		            cv::FONT_HERSHEY_SIMPLEX, 0.2, cv::Scalar(255, 255, 255), 1);
	}

    if (cleanup_delay > 0) {
        ros::Time now = ros::Time::now();

        for (vector<detection_msgs::Detection>::iterator it = detection_buffer.begin(); it != detection_buffer.end(); it++) {
            double timediff = now.toSec() - (*it).header.stamp.toSec();
            if (timediff > cleanup_delay)
                detection_buffer.erase(it);
            if (detection_buffer.empty()) break;
	    }
    } else {
        detection_buffer.clear();
    }

	cv::imshow("Detections visualizer", cv_ptr->image);

}

int main(int argc, char** argv) {

	ros::init (argc, argv, "overlay_visualizer");
	ros::NodeHandle nh, private_nh("~");

	ros::Subscriber sub_camera = nh.subscribe ("camera", 1, imageCallback);
	ros::Subscriber sub_detections = nh.subscribe ("detections", 100, detectionsCallback);

    private_nh.param("cleanup_delay", cleanup_delay, 0.0);
    
	cv::namedWindow("Detections visualizer", CV_WINDOW_AUTOSIZE);

    while (ros::ok()) {
	    ros::spinOnce();
      	cv::waitKey(10);
    }

	return 0;
}
