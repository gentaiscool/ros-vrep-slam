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
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#include "mcv.h"
#include "buffer_management.h"
#include "pyr_yape06.h"

const int pyr_yape06::Maximum_number_of_points = 50000;

//const int pyr_yape06::R = 3, pyr_yape06::Rp = 2; // -> 3450 to 879
const int pyr_yape06::R = 5, pyr_yape06::Rp = 3; // -> 3890 to 1479
//const int pyr_yape06::R = 5, pyr_yape06::Rp = 4; // -> 3700 to 1215
//const int pyr_yape06::R = 7, pyr_yape06::Rp = 5; // -> 3704 to 1102


pyr_yape06::pyr_yape06(void)
{
  all_keypoints = new keypoint[Maximum_number_of_points];
  laplacian = 0;

  //   set_laplacian_threshold(10);
  //   set_min_eigenvalue_threshold(10);
  set_laplacian_threshold(30);
  set_min_eigenvalue_threshold(25);
}

pyr_yape06::~pyr_yape06(void)
{
  delete [] all_keypoints;
  release_managed_image(&laplacian);
}


int pyr_yape06::detect(fine_gaussian_pyramid * pyramid, keypoint * keypoints, int max_number_of_keypoints)
{
  number_of_points = 0;
  for(int i = 0; i < pyramid->number_of_octaves; i++) {
    compute_Ds(pyramid->aztec_pyramid[3 + i * 4]);
    compute_laplacian(pyramid->aztec_pyramid[3 + i * 4]);
    add_local_extrema(pyramid, pyramid->aztec_pyramid[3 + i * 4], i);
  }

  sort_keypoints();

  return copy_keypoints(keypoints, max_number_of_keypoints);
}

void pyr_yape06::compute_Ds(IplImage * smoothed_image)
{
  Dxx = R, Dyy = R * smoothed_image->widthStep;
  Dxy = Rp + Rp * smoothed_image->widthStep, Dyx = Rp - Rp * smoothed_image->widthStep;
  DXY = 1  + 1  * smoothed_image->widthStep, DYX = 1  - 1  * smoothed_image->widthStep;
}

inline void pyr_yape06::compute_laplacian(IplImage * smoothed_image, IplImage * laplacian,
					  const int w, const int h,
					  const int Dxx, const int Dyy,
					  const int /*Dxy*/, const int /*Dyx*/)
{
  for(int y = Dxx; y < h - Dxx; y++) {
    unsigned char * image_row = mcvRow(smoothed_image, y, unsigned char);
    int * laplacian_row = mcvRow(laplacian, y, int);
    for(int x = w - Dxx; x >= Dxx; x--) {
      *laplacian_row = -4 * *image_row +
	*(image_row + Dxx) + *(image_row - Dxx) + *(image_row + Dyy) + *(image_row - Dyy);

      laplacian_row++;
      image_row++;
    }
  }
}

void pyr_yape06::compute_laplacian(IplImage * smoothed_image)
{
  manage_image(&laplacian, smoothed_image->width, smoothed_image->height, IPL_DEPTH_32S, 1);
  cvSetZero(laplacian);

  const int w = smoothed_image->width;
  const int h = smoothed_image->height;
  if (w == 784 && h == 640)
    compute_laplacian(smoothed_image, laplacian, 784, 640, R, R * 784, Rp + Rp * 784, Rp - Rp * 784);
  else if (w == 768 && h == 640)
    compute_laplacian(smoothed_image, laplacian, 768, 640, R, R * 768, Rp + Rp * 768, Rp - Rp * 768);
  else if (w == 704 && h == 544)
    compute_laplacian(smoothed_image, laplacian, 704, 544, R, R * 704, Rp + Rp * 704, Rp - Rp * 704);
  else if (w == 392 && h == 320)
    compute_laplacian(smoothed_image, laplacian, 392, 320, R, R * 392, Rp + Rp * 392, Rp - Rp * 392);
  else if (w == 384 && h == 320)
    compute_laplacian(smoothed_image, laplacian, 384, 320, R, R * 384, Rp + Rp * 384, Rp - Rp * 384);
  else if (w == 352 && h == 272)
    compute_laplacian(smoothed_image, laplacian, 352, 272, R, R * 352, Rp + Rp * 352, Rp - Rp * 352);
  else if (w == 196 && h == 160)
    compute_laplacian(smoothed_image, laplacian, 196, 160, R, R * 196, Rp + Rp * 196, Rp - Rp * 196);
  else if (w == 192 && h == 160)
    compute_laplacian(smoothed_image, laplacian, 192, 160, R, R * 192, Rp + Rp * 192, Rp - Rp * 192);
  else if (w == 176 && h == 136)
    compute_laplacian(smoothed_image, laplacian, 176, 136, R, R * 176, Rp + Rp * 176, Rp - Rp * 176);
  else {
    static bool warned = false;
    if (!warned) {
      cerr << ">! Warning: pyr_yape06 not optimized for " << w << " x " << h << " images." << endl;
      cerr << ">! You may want add this size to the pyr_yape06::compute_laplacian member function for more efficiency." << endl;
      warned = true;
    }

    compute_laplacian(smoothed_image, laplacian, w, h, Dxx, Dyy, Dxy, Dyx);
  }
}

inline int pyr_yape06::hessian_min_eigen_value(IplImage * smoothed_image, const int tr, const int x, const int y)
{
  unsigned char * image_ptr = mcvRow(smoothed_image, y, unsigned char) + x;
  const int Ixx = -2 * *image_ptr + *(image_ptr + Dxx) + *(image_ptr - Dxx);
  const int Iyy = -2 * *image_ptr + *(image_ptr + Dyy) + *(image_ptr - Dyy);
  const int Ixy = *(image_ptr + Dxy) + *(image_ptr - Dxy) - *(image_ptr + Dyx) - *(image_ptr - Dyx);
  const int sqrt_delta = int( sqrt(double((Ixx - Iyy) * (Ixx - Iyy) + 4 * Ixy * Ixy) ) );

  return min(abs(tr - sqrt_delta), abs(-(tr + sqrt_delta)));
}

inline bool pyr_yape06::laplacian_hessian_criteria(IplImage * laplacian,
						   const int x, const int y)
{
  int * image_ptr = mcvRow(laplacian, y, int) + x;
  const int D = laplacian->widthStep / 4;
  const int Lxx = -2 * *image_ptr + *(image_ptr + 1) + *(image_ptr - 1);
  const int Lyy = -2 * *image_ptr + *(image_ptr + D) + *(image_ptr - D);
  const int Lxy = *(image_ptr + D + 1) + *(image_ptr - D - 1) - *(image_ptr + D - 1) - *(image_ptr - D + 1);
  const int det = Lxx * Lyy - Lxy * Lxy;
  const int trace = Lxx + Lyy;

  const float k = 0.1;

  //   cout << det << " " << trace * trace << endl;

  return float(det) > k * float(trace * trace);
}

void pyr_yape06::add_local_extrema(fine_gaussian_pyramid * pyramid, IplImage * smoothed_image, int scale)
{
  const int w = laplacian->width;
  const int dy = laplacian->widthStep / sizeof(int);

  //   mcvSaveImage("lap.bmp", laplacian);
  //   save_eigen_value1(smoothed_image, laplacian);
  //   save_eigen_value2(smoothed_image, laplacian);
  //   exit(0);

  for(int y = 1; y < laplacian->height - 1; y++) {
    int * lap_row = mcvRow(laplacian, y, int);
    for(int x = 1; x < w - 1; x++) {
      if ((lap_row[x] < -lap_threshold &&
	   lap_row[x] < lap_row[x - 1]      && lap_row[x] < lap_row[x + 1] &&
	   lap_row[x] < lap_row[x - dy]     && lap_row[x] < lap_row[x + dy] &&
	   lap_row[x] < lap_row[x - dy - 1] && lap_row[x] < lap_row[x + dy - 1] &&
	   lap_row[x] < lap_row[x - dy + 1] && lap_row[x] < lap_row[x + dy + 1])
	  ||
	  (lap_row[x] > +lap_threshold &&
	   lap_row[x] > lap_row[x - 1]      && lap_row[x] > lap_row[x + 1] &&
	   lap_row[x] > lap_row[x - dy]     && lap_row[x] > lap_row[x + dy] &&
	   lap_row[x] > lap_row[x - dy - 1] && lap_row[x] > lap_row[x + dy - 1] &&
	   lap_row[x] > lap_row[x - dy + 1] && lap_row[x] > lap_row[x + dy + 1])
	  )
	{
	  const int min_eigen_value = hessian_min_eigen_value(smoothed_image, lap_row[x], x, y);
	  //	  cout << x << "x" << y << " -> " << lap_row[x] << "; " << min_eigen_value << endl;
	  if (min_eigen_value > min_ev_threshold) {
	    //if (laplacian_hessian_criteria(laplacian, x, y)) {
	    all_keypoints[number_of_points].u = float(x - (pyramid->border_size >> scale));
	    all_keypoints[number_of_points].v = float(y - (pyramid->border_size >> scale));
	    all_keypoints[number_of_points].scale = float(scale);
	    all_keypoints[number_of_points].score = float(min_eigen_value);

	    number_of_points++;
	    if (number_of_points >= Maximum_number_of_points) return;
	  }
	}
    }
  }
}

static bool cmp_keypoints(const keypoint & k1, const keypoint & k2)
{
  return k1.score > k2.score;
}

void pyr_yape06::sort_keypoints(void)
{
  sort(all_keypoints, all_keypoints + number_of_points, cmp_keypoints);
}

int pyr_yape06::copy_keypoints(keypoint * keypoints, int max_number_of_keypoints)
{
  int returned_number_of_keypoints = min(max_number_of_keypoints, number_of_points);
  memcpy(keypoints, all_keypoints, sizeof(keypoint) * returned_number_of_keypoints);
  return returned_number_of_keypoints;
}

IplImage * pyr_yape06::draw_keypoints(fine_gaussian_pyramid * pyramid, keypoint * keypoints, int number_of_keypoints)
{
  IplImage * result = mcvGrayToColor(pyramid->original_image);

  for(int i = 0; i < number_of_keypoints; i++)
    cvCircle(result, mcvPoint(keypoints[i]), 16 << int(keypoints[i].scale), mcvRainbowColor(int(keypoints[i].scale)));

  return result;
}

/////////////////////////////////////////////

void pyr_yape06::save_eigen_value1(IplImage * smoothed_image, IplImage * laplacian)
{
  IplImage * result = cvCreateImage(cvSize(smoothed_image->width, smoothed_image->height), IPL_DEPTH_32S, 1);

  const int w = laplacian->width;
  for(int y = 1; y < laplacian->height - 1; y++) {
    int * lap_row = mcvRow(laplacian, y, int);
    unsigned char * image_row = mcvRow(smoothed_image, y, unsigned char);
    int * result_row = mcvRow(result, y, int);
    for(int x = 1; x < w - 1; x++) {
      int tr = lap_row[x];
      const int Ixx = -2 * image_row[x] + *(image_row + x + Dxx) + *(image_row + x - Dxx);
      const int Iyy = -2 * image_row[x] + *(image_row + x + Dyy) + *(image_row + x - Dyy);
      const int Ixy = *(image_row + x + Dxy) + *(image_row + x - Dxy) - *(image_row + x + Dyx) - *(image_row + x - Dyx);
      const int sqrt_delta = int( sqrt(double((Ixx - Iyy) * (Ixx - Iyy) + 4 * Ixy * Ixy) ) );

      if (abs(tr - sqrt_delta) < abs(-(tr + sqrt_delta)))
	result_row[x] = tr - sqrt_delta;
      else
	result_row[x] = -(tr + sqrt_delta);
    }
  }

  mcvSaveImage("ev1.bmp", result);
}

void pyr_yape06::save_eigen_value2(IplImage * smoothed_image, IplImage * laplacian)
{
  IplImage * result = cvCreateImage(cvSize(smoothed_image->width, smoothed_image->height), IPL_DEPTH_32S, 1);

  const int w = laplacian->width;
  for(int y = 1; y < laplacian->height - 1; y++) {
    int * lap_row = mcvRow(laplacian, y, int);
    unsigned char * image_row = mcvRow(smoothed_image, y, unsigned char);
    int * result_row = mcvRow(result, y, int);
    for(int x = 1; x < w - 1; x++) {
      int tr = lap_row[x];
      const int Ixx = -2 * image_row[x] + *(image_row + x + Dxx) + *(image_row + x - Dxx);
      const int Iyy = -2 * image_row[x] + *(image_row + x + Dyy) + *(image_row + x - Dyy);
      const int Ixy = *(image_row + x + Dxy) + *(image_row + x - Dxy) - *(image_row + x + Dyx) - *(image_row + x - Dyx);
      const int sqrt_delta = int( sqrt(double((Ixx - Iyy) * (Ixx - Iyy) + 4 * Ixy * Ixy) ) );

      result_row[x] = max(abs(tr - sqrt_delta), abs(-(tr + sqrt_delta)));
    }
  }

  mcvSaveImage("ev2.bmp", result);
}
