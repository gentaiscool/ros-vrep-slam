/*
  Copyright 2007 Computer Vision Lab,
  Ecole Polytechnique Federale de Lausanne (EPFL), Switzerland.
  All rights reserved.

  Author: Vincent Lepetit (http://cvlab.epfl.ch/~lepetit)
          Mustafa Ozuysal (http://cvlab.epfl.ch/~oezuysal)

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
#ifndef homography_estimator_h
#define homography_estimator_h

#include "homography06.h"

class homography_estimator
{
 public:
  homography_estimator(void);
  ~homography_estimator(void);

  bool estimate(homography06 * H,
                const float u1, const float v1, const float up1, const float vp1,
                const float u2, const float v2, const float up2, const float vp2,
                const float u3, const float v3, const float up3, const float vp3,
                const float u4, const float v4, const float up4, const float vp4);

  void reset_correspondences(int maximum_number_of_correspondences);
  void add_correspondence(float u, float v, float up, float vp);
  void add_correspondence(float u, float v, float up, float vp, float score);
  int ransac(homography06 * H, const float threshold, const int maximum_number_of_iterations,
             const float P = 0.99, bool prosac_sampling = true);

  bool * inliers;
  int number_of_inliers;

  int verbose_level;

  //private:
  void normalize(void);
  float scale, scalep;
  void denormalize(homography06 * H);
  void get_4_random_indices(int n_max, int & n1, int & n2, int & n3, int & n4);
  void get_4_prosac_indices(int n_max, int & n1, int & n2, int & n3, int & n4);
  int compute_inliers(homography06 * A, bool * inliers, float threshold);
  bool estimate_from_inliers(homography06 * A);
  bool nice_homography(homography06 * H);
  void sort_correspondences();

  CvMat * AA, * W, * W8, * Ut, * Vt;
  CvMat * T1, * T2inv, * tmp;
  CvMat * AA2, * B2, * X2;
  float * u_v_up_vp, * normalized_u_v_up_vp, * scores;
  int   * sorted_ids;
  int number_of_correspondences;

  void set_bottom_right_coefficient_to_one(homography06 * H);
};

#endif
