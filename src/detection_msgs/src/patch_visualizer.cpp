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

vector<detection_msgs::DetectionConstPtr> detection_buffer;
double cleanup_delay = 0;
int grid_size = 128;
bool update = false;

void detectionsCallback(const detection_msgs::DetectionConstPtr& msg) {

    detection_buffer.push_back(msg);

    update = true;

}


int main(int argc, char** argv) {

	ros::init (argc, argv, "patch_visualizer");
	ros::NodeHandle nh, private_nh("~");

	ros::Subscriber sub_detections = nh.subscribe ("detections", 100, detectionsCallback);

    private_nh.param("cleanup_delay", cleanup_delay, 0.0);
    private_nh.param("grid_size", grid_size, 128);
	cv::namedWindow("Detections", CV_WINDOW_AUTOSIZE);

    cv::Mat canvas(grid_size, grid_size, CV_8UC3);

    while (ros::ok()) {
	    ros::spinOnce();
      	cv::waitKey(25);

        if (update) {

            int max_detections = MIN(32, detection_buffer.size());

            int row_length = 8;
            int row_number = ((max_detections - (max_detections % row_length)) / row_length) + 1;

            int canvas_height = row_number * grid_size;
            int canvas_width = row_length * grid_size;
            
            if (canvas.cols < canvas_width || canvas.rows < canvas_height) {
                canvas = cv::Mat(canvas_height, canvas_width, CV_8UC3);
            }

            canvas.setTo(0);

            for (int i = 0; i < max_detections; i++) {
	            detection_msgs::DetectionConstPtr current = detection_buffer.at(i);
	            cv_bridge::CvImageConstPtr cv_ptr;
	            cv_ptr = cv_bridge::toCvShare(current->image, current, sensor_msgs::image_encodings::BGR8);

                int col = i % row_length;
                int row = (i - col) / row_length;

	            cv::Rect src_region(0, 0, MIN(grid_size, cv_ptr->image.cols), MIN(grid_size, cv_ptr->image.rows));
	            cv::Rect dst_region(col * grid_size, row * grid_size, MIN(grid_size, cv_ptr->image.cols), MIN(grid_size, cv_ptr->image.rows));

                
                cv_ptr->image(src_region).copyTo(canvas(dst_region));
				//image(i * self.grid_size:(i * self.grid_size + self.grid_size), 0:self.face_size] = cv2.resize(self.bridge.imgmsg_to_cv2(data.image, data.encoding), (self.face_size, self.face_size), interpolation=cv2.INTER_LINEAR)

            }

            if (cleanup_delay > 0) {
                ros::Time now = ros::Time::now();

                for (vector<detection_msgs::DetectionConstPtr>::iterator it = detection_buffer.begin(); it != detection_buffer.end(); it++) {
                    double timediff = now.toSec() - (*it)->header.stamp.toSec();
                    if (timediff > cleanup_delay)
                        detection_buffer.erase(it);
                    if (detection_buffer.empty()) break;
                }
            } else {
                detection_buffer.clear();
            }

            cv::imshow("Detections", canvas);
            update = false;
        }

    }

	return 0;
}
