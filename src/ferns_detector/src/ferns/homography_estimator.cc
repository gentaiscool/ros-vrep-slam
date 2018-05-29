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
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "buffer_management.h"
#include "homography_estimator.h"
#include "cmphomo.h"

using namespace std;

homography_estimator::homography_estimator(void)
{
  AA = cvCreateMat(8, 9, CV_32FC1);
  W  = cvCreateMat(9, 1, CV_32FC1);
  W8 = cvCreateMat(8, 1, CV_32FC1);
  Ut = cvCreateMat(8, 8, CV_32FC1);
  Vt = cvCreateMat(9, 9, CV_32FC1);

  T1	= cvCreateMat(3, 3, CV_32FC1);
  T2inv = cvCreateMat(3, 3, CV_32FC1);
  tmp   = cvCreateMat(3, 3, CV_32FC1);

  AA2 = cvCreateMat(4, 3, CV_32FC1);
  B2  = cvCreateMat(4, 1, CV_32FC1);
  X2  = cvCreateMat(3, 1, CV_32FC1);

  u_v_up_vp = 0;
  normalized_u_v_up_vp = 0;
  inliers = 0;
  verbose_level = 0;
  scores = 0;
  sorted_ids = 0;
}

homography_estimator::~homography_estimator(void)
{
  cvReleaseMat(&AA);
  cvReleaseMat(&W);
  cvReleaseMat(&W8);
  cvReleaseMat(&Ut);
  cvReleaseMat(&Vt);

  cvReleaseMat(&T1);
  cvReleaseMat(&T2inv);
  cvReleaseMat(&tmp);

  delete_managed_buffer(u_v_up_vp);
  delete_managed_buffer(normalized_u_v_up_vp);
  delete_managed_buffer(inliers);
}

void homography_estimator::set_bottom_right_coefficient_to_one(homography06 * H)
{
  float inv_H33 = 1.f / float( cvmGet(H, 2, 2) );
  for(int i = 0; i < 8; i++)
    H->data.fl[i] *= inv_H33;
  cvmSet(H, 2, 2, 1.);
}


bool homography_estimator::estimate(homography06 * H,
                                    const float u1, const float v1, const float up1, const float vp1,
                                    const float u2, const float v2, const float up2, const float vp2,
                                    const float u3, const float v3, const float up3, const float vp3,
                                    const float u4, const float v4, const float up4, const float vp4)
{
	const float a[] = { u1, v1 };
	const float b[] = { u2, v2 };
	const float c[] = { u3, v3 };
	const float d[] = { u4, v4 };
	const float x[] = { up1, vp1 };
	const float y[] = { up2, vp2 };
	const float z[] = { up3, vp3 };
	const float w[] = { up4, vp4 };
	homography_from_4corresp(a,b,c,d,x,y,z,w, (float (*)[3]) H->data.fl);

  return true;
}

/*
  bool homography_estimator::estimate(homography * A,
  double u1, double v1, double up1, double vp1,
  double u2, double v2, double up2, double vp2,
  double u3, double v3, double up3, double vp3)
  {
  return estimate(A,
  float(u1), float(v1), float(up1), float(vp1),
  float(u2), float(v2), float(up2), float(vp2),
  float(u3), float(v3), float(up3), float(vp3));
  }
*/

void homography_estimator::reset_correspondences(int maximum_number_of_correspondences)
{
  manage_buffer(u_v_up_vp,            4 * maximum_number_of_correspondences, float);
  manage_buffer(normalized_u_v_up_vp, 4 * maximum_number_of_correspondences, float);
  manage_buffer(scores,                   maximum_number_of_correspondences, float);
  manage_buffer(sorted_ids,               maximum_number_of_correspondences, int);

  number_of_correspondences = 0;
}

void homography_estimator::add_correspondence(float u, float v, float up, float vp)
{
  u_v_up_vp[4 * number_of_correspondences    ] = u;
  u_v_up_vp[4 * number_of_correspondences + 1] = v;
  u_v_up_vp[4 * number_of_correspondences + 2] = up;
  u_v_up_vp[4 * number_of_correspondences + 3] = vp;

  number_of_correspondences++;
}

void homography_estimator::add_correspondence(float u, float v, float up, float vp, float score)
{
  u_v_up_vp[4 * number_of_correspondences    ] = u;
  u_v_up_vp[4 * number_of_correspondences + 1] = v;
  u_v_up_vp[4 * number_of_correspondences + 2] = up;
  u_v_up_vp[4 * number_of_correspondences + 3] = vp;
  scores[number_of_correspondences] = score;

  number_of_correspondences++;
}

void homography_estimator::normalize(void)
{
  float u_sum = 0., v_sum = 0., up_sum = 0., vp_sum = 0;

  for(int i = 0; i < number_of_correspondences; i++) {
    u_sum  += u_v_up_vp[4 * i    ];
    v_sum  += u_v_up_vp[4 * i + 1];
    up_sum += u_v_up_vp[4 * i + 2];
    vp_sum += u_v_up_vp[4 * i + 3];
  }

  float u_mean  = u_sum  / number_of_correspondences;
  float v_mean  = v_sum  / number_of_correspondences;
  float up_mean = up_sum / number_of_correspondences;
  float vp_mean = vp_sum / number_of_correspondences;

  // translate mean to origin, compute sum of distances from origin
  float dist_sum = 0, distp_sum = 0;
  for(int i = 0; i < number_of_correspondences; i++) {
    normalized_u_v_up_vp[4 * i    ] = u_v_up_vp[4 * i    ] - u_mean;
    normalized_u_v_up_vp[4 * i + 1] = u_v_up_vp[4 * i + 1] - v_mean;

    dist_sum += sqrt(normalized_u_v_up_vp[4 * i    ] * normalized_u_v_up_vp[4 * i    ] +
                     normalized_u_v_up_vp[4 * i + 1] * normalized_u_v_up_vp[4 * i + 1]);

    normalized_u_v_up_vp[4 * i + 2] = u_v_up_vp[4 * i + 2] - up_mean;
    normalized_u_v_up_vp[4 * i + 3] = u_v_up_vp[4 * i + 3] - vp_mean;

    distp_sum += sqrt(normalized_u_v_up_vp[4 * i + 2] * normalized_u_v_up_vp[4 * i + 2] +
                      normalized_u_v_up_vp[4 * i + 3] * normalized_u_v_up_vp[4 * i + 3]);
  }

  // compute normalizing scale factor ( average distance from origin = sqrt(2) )
  scale  = (sqrt(2.f) * number_of_correspondences) / dist_sum;
  scalep = (sqrt(2.f) * number_of_correspondences) / distp_sum;

  // apply scaling
  for(int i = 0; i < number_of_correspondences; i++) {
    normalized_u_v_up_vp[4 * i    ] *= scale;
    normalized_u_v_up_vp[4 * i + 1] *= scale;
    normalized_u_v_up_vp[4 * i + 2] *= scalep;
    normalized_u_v_up_vp[4 * i + 3] *= scalep;
  }

  // assemble transformation Matrices, used at denormalization
  cvmSet(T1, 0, 0, scale);
  cvmSet(T1, 0, 1, 0.);
  cvmSet(T1, 0, 2, -scale * u_mean);
  cvmSet(T1, 1, 0, 0.);
  cvmSet(T1, 1, 1, scale);
  cvmSet(T1, 1, 2, -scale * v_mean);
  cvmSet(T1, 2, 0, 0.);
  cvmSet(T1, 2, 1, 0.);
  cvmSet(T1, 2, 2, 1.);

  cvmSet(T2inv, 0, 0, 1. / scalep);
  cvmSet(T2inv, 0, 1, 0.);
  cvmSet(T2inv, 0, 2, up_mean);
  cvmSet(T2inv, 1, 0, 0.);
  cvmSet(T2inv, 1, 1, 1. / scalep);
  cvmSet(T2inv, 1, 2, vp_mean);
  cvmSet(T2inv, 2, 0, 0.);
  cvmSet(T2inv, 2, 1, 0.);
  cvmSet(T2inv, 2, 2, 1.);
}

void homography_estimator::denormalize(homography06 * H)
{
  cvMatMul(T2inv, H, tmp);
  cvMatMul(tmp, T1, H);
}

bool homography_estimator::nice_homography(homography06 * H)
{
  double det = cvmGet(H, 0, 0) * cvmGet(H, 1, 1) - cvmGet(H, 1, 0) * cvmGet(H, 0, 1);
  if (det < 0) return false;
  double N1 = sqrt(cvmGet(H, 0, 0) * cvmGet(H, 0, 0) + cvmGet(H, 1, 0) * cvmGet(H, 1, 0));
  if (N1 > 4) return false;
  if (N1 < 0.1) return false;
  double N2 = sqrt(cvmGet(H, 0, 1) * cvmGet(H, 0, 1) + cvmGet(H, 1, 1) * cvmGet(H, 1, 1));
  if (N2 > 4) return false;
  if (N2 < 0.1) return false;
  double N3 = sqrt(cvmGet(H, 2, 0) * cvmGet(H, 2, 0) + cvmGet(H, 2, 1) * cvmGet(H, 2, 1));
  if (N3 > 0.002) return false;
  return true;
}


int homography_estimator::ransac(homography06 * H, const float threshold, const int maximum_number_of_iterations,
                                 const float P, bool prosac_sampling)
{
  if (number_of_correspondences < 4) {
    if (verbose_level >= 1) {
      cerr << "> [homography_estimator::ransac]:" << endl;
      cerr << ">    Can't estimate homography with less than 4 correspondences." << endl;
    }
    return 0;
  }

  normalize();

  int N = maximum_number_of_iterations;

  number_of_inliers = 0;
  manage_buffer(inliers, number_of_correspondences, bool);

  static bool * current_inliers = 0;
  manage_buffer(current_inliers, number_of_correspondences, bool);

  int sample_count = 0;
  int prosac_correspondences = 10;

  if(prosac_sampling) {
    sort_correspondences();
  }

  while (N > sample_count && number_of_inliers < 50) { /// !!!!!!!!!!!!!!!!!!!!!!
    int n1, n2, n3, n4;
    if(prosac_sampling) {
      get_4_prosac_indices(prosac_correspondences, n1, n2, n3, n4);

      // This incrementing strategy is naive and simple but works just fine most of the time.
      if(prosac_correspondences < number_of_correspondences) {
        ++prosac_correspondences;
      }
    }
    else {
      get_4_random_indices(number_of_correspondences, n1, n2, n3, n4);
    }

    bool ok = estimate(H,
                       normalized_u_v_up_vp[4 * n1], normalized_u_v_up_vp[4 * n1 + 1], normalized_u_v_up_vp[4 * n1 + 2], normalized_u_v_up_vp[4 * n1 + 3],
                       normalized_u_v_up_vp[4 * n2], normalized_u_v_up_vp[4 * n2 + 1], normalized_u_v_up_vp[4 * n2 + 2], normalized_u_v_up_vp[4 * n2 + 3],
                       normalized_u_v_up_vp[4 * n3], normalized_u_v_up_vp[4 * n3 + 1], normalized_u_v_up_vp[4 * n3 + 2], normalized_u_v_up_vp[4 * n3 + 3],
                       normalized_u_v_up_vp[4 * n4], normalized_u_v_up_vp[4 * n4 + 1], normalized_u_v_up_vp[4 * n4 + 2], normalized_u_v_up_vp[4 * n4 + 3]);

    if (!ok) return false;

    denormalize(H);
    set_bottom_right_coefficient_to_one(H);

    if (nice_homography(H)) {
      int current_number_of_inliers = compute_inliers(H, current_inliers, threshold);

      if (current_number_of_inliers > number_of_inliers) {
        if (verbose_level >= 2) cout << "> Iteration " << sample_count << ": " << current_number_of_inliers << " inliers. New N = " << N << endl;
        double eps = 1. - double(current_number_of_inliers) / number_of_correspondences;
        int newN = (int)(log(1-P)/log(1-pow((1.-eps), 4)));
        if (newN < N) N = newN;

        number_of_inliers = current_number_of_inliers;
        for (int i = 0; i < number_of_correspondences; i++) inliers[i] = current_inliers[i];
      }
    }

    sample_count++;
  }

  // do estimation with all inliers and loop until inlier_number is not increased anymore
  int old_number_of_inliers = number_of_inliers;
  do {
    bool ok = estimate_from_inliers(H);
    if (!ok) return false;

    old_number_of_inliers = number_of_inliers;
    number_of_inliers = compute_inliers(H, inliers, threshold);
    if (verbose_level >= 2) cout << "> Refining: " << number_of_inliers << " inliers." << endl;
  } while (number_of_inliers > old_number_of_inliers);

  number_of_inliers = compute_inliers(H, inliers, threshold);

  if (verbose_level >= 1) cout << "> homography_estimator::ransac( ) " << number_of_inliers << " inliers found." << endl;

  return number_of_inliers;
}

void homography_estimator::get_4_random_indices(int n_max, int & n1, int & n2, int & n3, int & n4)
{
  n1 = rand() % n_max;
  do n2 = rand() % n_max; while(n2 == n1);
  do n3 = rand() % n_max; while(n3 == n1 || n3 == n2);
  do n4 = rand() % n_max; while(n4 == n1 || n4 == n2 || n4 == n3);
}

void homography_estimator::get_4_prosac_indices(int n_max, int & n1, int & n2, int & n3, int & n4)
{
  n1 = rand() % n_max;
  do n2 = rand() % n_max; while(n2 == n1);
  do n3 = rand() % n_max; while(n3 == n1 || n3 == n2);
  do n4 = rand() % n_max; while(n4 == n1 || n4 == n2 || n4 == n3);

  n1 = sorted_ids[n1];
  n2 = sorted_ids[n2];
  n3 = sorted_ids[n3];
  n4 = sorted_ids[n4];
}

int homography_estimator::compute_inliers(homography06 * H, bool * inliers, float threshold)
{
  int n = 0;

  for(int i = 0; i < number_of_correspondences; i++) {
    float eup, evp;
    H->transform_point(u_v_up_vp[4 * i], u_v_up_vp[4 * i + 1], eup, evp);
    inliers[i] = ((u_v_up_vp[4 * i + 2] - eup) * (u_v_up_vp[4 * i + 2] - eup) +
                  (u_v_up_vp[4 * i + 3] - evp) * (u_v_up_vp[4 * i + 3] - evp)) < threshold * threshold;

    if (inliers[i]) n++;
  }

  return n;
}

bool homography_estimator::estimate_from_inliers(homography06 * H)
{
  if (number_of_inliers < 4) return false;

  CvMat * _AA_ = cvCreateMat(2 * number_of_inliers, 9, CV_32FC1);

  int n = 0;
  for(int i = 0; i < number_of_correspondences; i++)
    if (inliers[i]) {
      cvmSet(_AA_, n, 0, 0.); cvmSet(_AA_, n, 1, 0.); cvmSet(_AA_, n, 2, 0.); cvmSet(_AA_, n, 3, -normalized_u_v_up_vp[4 * i]); cvmSet(_AA_, n, 4, -normalized_u_v_up_vp[4 * i + 1]); cvmSet(_AA_, n, 5, -1.); cvmSet(_AA_, n, 6,  normalized_u_v_up_vp[4 * i + 3] * normalized_u_v_up_vp[4 * i]); cvmSet(_AA_, n, 7,  normalized_u_v_up_vp[4 * i + 3] * normalized_u_v_up_vp[4 * i + 1]); cvmSet(_AA_, n, 8,  normalized_u_v_up_vp[4 * i + 3]);
      cvmSet(_AA_, n + 1, 0, normalized_u_v_up_vp[4 * i]); cvmSet(_AA_, n + 1, 1, normalized_u_v_up_vp[4 * i + 1]); cvmSet(_AA_, n + 1, 2, 1.); cvmSet(_AA_, n + 1, 3,  0.); cvmSet(_AA_, n + 1, 4,  0.); cvmSet(_AA_, n + 1, 5, 0.); cvmSet(_AA_, n + 1, 6, -normalized_u_v_up_vp[4 * i + 2] * normalized_u_v_up_vp[4 * i]); cvmSet(_AA_, n + 1, 7, -normalized_u_v_up_vp[4 * i + 2] * normalized_u_v_up_vp[4 * i + 1]); cvmSet(_AA_, n + 1, 8, -normalized_u_v_up_vp[4 * i + 2]);

      n += 2;
    }

  if(number_of_inliers == 4) {
      cvSVD(_AA_, W8, 0, Vt, CV_SVD_MODIFY_A | CV_SVD_V_T);
  }
  else {
      cvSVD(_AA_, W, 0, Vt, CV_SVD_MODIFY_A | CV_SVD_V_T);
  }

  cvmSet(H, 0, 0, cvmGet(Vt, 8, 0));
  cvmSet(H, 0, 1, cvmGet(Vt, 8, 1));
  cvmSet(H, 0, 2, cvmGet(Vt, 8, 2));

  cvmSet(H, 1, 0, cvmGet(Vt, 8, 3));
  cvmSet(H, 1, 1, cvmGet(Vt, 8, 4));
  cvmSet(H, 1, 2, cvmGet(Vt, 8, 5));

  cvmSet(H, 2, 0, cvmGet(Vt, 8, 6));
  cvmSet(H, 2, 1, cvmGet(Vt, 8, 7));
  cvmSet(H, 2, 2, cvmGet(Vt, 8, 8));

  cvReleaseMat(&_AA_);

  denormalize(H);
  set_bottom_right_coefficient_to_one(H);

  return nice_homography(H);
}

class compare_by_score
{
public:
  compare_by_score(float* s) : scores(s) {}

  bool operator()(int id0, int id1) {  return scores[id0] > scores[id1]; }
  float* scores;
};

void homography_estimator::sort_correspondences()
{
  for(int i = 0; i < number_of_correspondences; i++) {
    sorted_ids[i] = i;
  }

  sort(sorted_ids, sorted_ids + number_of_correspondences, compare_by_score(scores));
}
