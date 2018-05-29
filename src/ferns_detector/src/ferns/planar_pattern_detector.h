/*
  Copyright 2007 Computer Vision Lab,
  Ecole Polytechnique Federale de Lausanne (EPFL), Switzerland.
  All rights reserved.

  Author: Vincent Lepetit (http://cvlab.epfl.ch/~lepetit)

  This file is part of the ferns_demo software.

  ferns_demo is free software; you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation; either version 2 of the License, or (at your option) any later
  version.

  ferns_demo is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE. See the GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along with
  ferns_demo; if not, write to the Free Software Foundation, Inc., 51 Franklin
  Street, Fifth Floor, Boston, MA 02110-1301, USA
*/
#ifndef planar_pattern_detector_h
#define planar_pattern_detector_h

#include <fstream>
#include <vector>
using namespace std;

#include <cv.h>

#include "keypoint.h"

#include "pyr_yape06.h"
#include "fine_gaussian_pyramid.h"
#include "homography_estimator.h"

#include "affine_image_generator06.h"
#include "fern_based_point_classifier.h"

class planar_pattern_detector
{
 public:
  //! Empty constructor. call build, load or buildWithCache before use.
  planar_pattern_detector(void);

  ~planar_pattern_detector(void);

  bool load(const char * detector_data_filename);
  bool save(const char * detector_data_filename);
  bool load(ifstream & f);
  bool save(ofstream & f);

  void save_image_of_model_points(const char * filename, int patch_size);

  //! set the maximum number of points we want to detect
  void set_maximum_number_of_points_to_detect(int max);

  bool detect(const IplImage * input_image);

  IplImage * create_image_of_matches(void);

  keypoint * model_points, * detected_points;
  int number_of_model_points, number_of_detected_points;
  int maximum_number_of_points_to_detect;

  // Is it still necessary ??
  float ** match_probabilities;

  bool pattern_is_detected;

  bool estimate_H(void);
  homography06 H;
  homography_estimator * H_estimator;
  int u_corner[4], v_corner[4];
  int detected_u_corner[4], detected_v_corner[4];
  int number_of_matches;

  affine_image_generator06 * image_generator;

  //private:
  void learn(IplImage * model_image,
             int maximum_number_of_points_on_model,
             int number_of_generated_images_to_find_stable_points,
             double minimum_number_of_views_rate,
             int patch_size, int yape_radius, int number_of_octaves,
             int number_of_ferns, int number_of_tests_per_fern,
             int number_of_samples_for_refinement, int number_of_samples_for_test);

  void detect_most_stable_model_points(int maximum_number_of_points_on_model,
                                       int yape_radius, int number_of_octaves, int number_of_generated_images,
                                       double minimum_number_of_views_rate);

  pair<keypoint, int> * search_for_existing_model_point(vector< pair<keypoint, int> > * tmp_model_points,
                                                        float cu, float cv, int scale);
  void detect_points(fine_gaussian_pyramid * pyramid);
  void match_points(void);

  //! test()
  void test(int number_of_samples_for_test, bool verbose = false);

  char image_name[1000];
  pyr_yape06 * point_detector;
  fern_based_point_classifier * classifier;
  float mean_recognition_rate;
  fine_gaussian_pyramid * pyramid;
  IplImage * model_image;

  int patch_size, yape_radius, number_of_octaves;
};

#endif
