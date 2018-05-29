#include "ros/ros.h"
#include <sstream>
#include <string.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ferns/mcv.h"
#include "ferns/planar_pattern_detector_builder.h"
#include "ferns/template_matching_based_tracker.h"

using namespace std;
using namespace cv;

planar_pattern_detector * detector;
template_matching_based_tracker * tracker;

#define TITLE "Enter four ROI points"

typedef struct {
  int current_point;
  Point2f points[4];
} Region;

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


void _mousecallback(int event, int x, int y, int flags, void *param) {
    Region *r = (Region*) param;


    if (event == CV_EVENT_RBUTTONDOWN) {

      r->current_point--;
      return;

    }

    if (event == CV_EVENT_LBUTTONDOWN) {
 
      if (r->current_point > -1 && r->current_point < 4) {
        r->points[r->current_point].x = x;
        r->points[r->current_point].y = y;
        r->current_point++;
      }

    }

}

bool queryrect(string name, Mat& image, Region& rect) {

    Region r;
    r.current_point = 0;

    Mat clone;

    cvSetMouseCallback(name.c_str(), _mousecallback, (void*) &r);

    while(true) {

        image.copyTo(clone);

        Point prev = r.points[0];
        for (int i = 1; i < r.current_point; i++) {
          line(clone, prev, r.points[i], Scalar(0, 0, 255), 3);
          prev = r.points[i];
        }

        for (int i = 0; i < r.current_point; i++) {
          circle(clone, r.points[i], 5, Scalar(0, 255, 0), 4);
        }

        imshow(TITLE, clone);

        char key = waitKey(10);
        if(key >= 0 || r.current_point < 0 || r.current_point > 3) break;        

    }

    cvSetMouseCallback(name.c_str(), NULL, NULL);

    if (r.current_point > -1) {
        rect = r;
        return true;
    }

    return false;
}



int main(int argc, char **argv) {

  ros::init(argc, argv, "trainer");

  if (argc < 2) {
    ROS_ERROR("No training image provided. Exiting.");
    return -1;
  }

  string model_image = string(argv[1]);

  if( access( model_image.c_str(), F_OK ) == -1 ) {
    ROS_ERROR("Image does not exist. Exiting.");
    return -1;
  }

  string model_region = model_image + string(".roi");

  if( access( model_region.c_str(), F_OK ) == -1 ) {
    namedWindow(TITLE,CV_WINDOW_AUTOSIZE);
    Mat image = imread(model_image);
    Region region;
    if (queryrect(TITLE, image, region)) {
      ofstream out(model_region.c_str(), ofstream::out);
      for (int i = 0; i < 4; i++)
        out << region.points[i].x << " " << region.points[i].y << "\n";
      out.close();
    } else return 0;

    cvDestroyWindow(TITLE);
  }

  affine_transformation_range range;

  string tracker_model = model_image + string(".tracker_data");

  detector = planar_pattern_detector_builder::force_build(model_image.c_str(),
							       &range,
							       400,
							       5000,
							       0.0,
							       32, 7, 4,
							       30, 12,
							       10000, 200);

  if (!detector) {
    ROS_ERROR("Unable to build a detector!");
    return -1;
  }

  ROS_INFO("Detector built successfully.");

  ROS_INFO("Training template matching ...");

  tracker = new template_matching_based_tracker();

  tracker->learn(detector->model_image,
	   5, // number of used matrices (coarse-to-fine)
	   40, // max motion in pixel used to train to coarser matrix
	   20, 20, // defines a grid. Each cell will have one tracked point.
	   detector->u_corner[0], detector->v_corner[1],
	   detector->u_corner[2], detector->v_corner[2],
	   40, 40, // neighbordhood for local maxima selection
	   10000 // number of training samples
	   );
  tracker->save(tracker_model.c_str());

  ROS_INFO("Tracker built successfully.");

  return 0;
  
}

