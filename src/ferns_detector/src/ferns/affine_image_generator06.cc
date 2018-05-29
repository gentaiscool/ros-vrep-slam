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
#include <stdlib.h>
#include <math.h>

#include <iostream>
using namespace std;

#include "general.h"
#include "mcv.h"
#include "affine_image_generator06.h"

static const int prime = 307189;

affine_image_generator06::affine_image_generator06(void)
{
  original_image = 0;
  generated_image = 0;
  original_image_with_128_as_background = 0;

  white_noise = new char[prime];
  limited_white_noise = new int[prime];

  set_default_values();

  save_images = false;
}

affine_image_generator06::~affine_image_generator06(void)
{
  if (original_image != 0)  cvReleaseImage(&original_image);
  if (generated_image != 0) cvReleaseImage(&generated_image);
  if (original_image_with_128_as_background) cvReleaseImage(&original_image_with_128_as_background);

  delete [] white_noise;
  delete [] limited_white_noise;
}

void affine_image_generator06::load_transformation_range(ifstream & f)
{
  transformation_range.load(f);
}

void affine_image_generator06::save_transformation_range(ofstream & f)
{
  transformation_range.save(f);
}

void affine_image_generator06::set_transformation_range(affine_transformation_range * range)
{
  transformation_range = *range;
}

void affine_image_generator06::generate_Id_image(void)
{
  generate_Id_affine_transformation();
  generate_affine_image();
}

void affine_image_generator06::generate_random_affine_image(void)
{
  generate_random_affine_transformation();
  generate_affine_image();
}

void affine_image_generator06::save_generated_images(char * generic_name)
{
  save_images = true;
  strcpy(generic_name_of_saved_images, generic_name);
}

void affine_image_generator06::set_default_values(void)
{
  set_noise_level(20);
  set_use_random_background(true);
  set_add_gaussian_smoothing(true);
  set_change_intensities(true);
  add_noise = true;
}

void affine_image_generator06::set_noise_level(int noise_level)
{
  this->noise_level = noise_level;

  index_white_noise = 0;
  for(int i = 0; i < prime; i++) {
    limited_white_noise[i] = rand() % (2 * noise_level) - noise_level;
    white_noise[i] = char(rand() % 256);
  }
}

void affine_image_generator06::set_original_image(IplImage * p_original_image,
                                                  int generated_image_width,
                                                  int generated_image_height)
{
  if (original_image != 0) cvReleaseImage(&original_image);
  original_image = cvCloneImage(p_original_image);

  if (generated_image != 0) cvReleaseImage(&generated_image);
  if (generated_image_width < 0)
    generated_image = cvCloneImage(p_original_image);
  else
    generated_image = cvCreateImage(cvSize(generated_image_width, generated_image_height), IPL_DEPTH_8U, 1);

  if (original_image_with_128_as_background != 0) cvReleaseImage(&original_image_with_128_as_background);
  original_image_with_128_as_background = cvCloneImage(p_original_image);
  mcvReplace(original_image_with_128_as_background, 128, int(127));
}

void affine_image_generator06::set_mask(int x_min, int y_min, int x_max, int y_max)
{
  for(int v = 0; v < original_image_with_128_as_background->height; v++) {
    unsigned char * row = mcvRow(original_image_with_128_as_background, v, unsigned char);
    for(int u = 0; u < original_image_with_128_as_background->width; u++)
      if (u < x_min || u > x_max || v < y_min || v > y_max)
	row[u] = 128;
  }
}

void affine_image_generator06::generate_affine_transformation(float a[6],
                                                              float initialTx, float initialTy,
                                                              float theta, float phi,
                                                              float lambda1, float lambda2,
                                                              float finalTx, float finalTy)
{
  float t1 = cos(theta);
  float t2 = cos(phi);
  float t4 = sin(theta);
  float t5 = sin(phi);
  float t7 = t1 * t2 + t4 * t5;
  float t8 = t7 * lambda1;
  float t12 = t1 * t5 - t4 * t2;
  float t13 = t12 * lambda2;
  float t15 = t8 * t2 + t13 * t5;
  float t18 = -t8 * t5 + t13 * t2;
  float t22 = -t12 * lambda1;
  float t24 = t7 * lambda2;
  float t26 = t22 * t2 + t24 * t5;
  float t29 = -t22 * t5 + t24 * t2;
  a[0] = t15;
  a[1] = t18;
  a[2] = t15 * initialTx + t18 * initialTy + finalTx;
  a[3] = t26;
  a[4] = t29;
  a[5] = t26 * initialTx + t29 * initialTy + finalTy;
}

void affine_image_generator06::generate_random_affine_transformation(void)
{
  float theta, phi, lambda1, lambda2;

  transformation_range.generate_random_parameters(theta, phi, lambda1, lambda2);
  generate_affine_transformation(a, 0, 0, theta, phi, lambda1, lambda2, 0, 0);

  int Tx, Ty;
  float nu0, nv0, nu1, nv1, nu2, nv2, nu3, nv3;

  affine_transformation(0.,                           0.,                            nu0, nv0);
  affine_transformation(float(original_image->width), 0.,                            nu1, nv1);
  affine_transformation(float(original_image->width), float(original_image->height), nu2, nv2);
  affine_transformation(0.,                           float(original_image->height), nu3, nv3);

  if (rand() % 2 == 0) Tx = -(int)min(min(nu0, nu1), min(nu2, nu3));
  else                 Tx = generated_image->width - (int)max(max(nu0, nu1), max(nu2, nu3));
  
  if (rand() % 2 == 0) Ty = -(int)min(min(nv0, nv1), min(nv2, nv3));
  else                 Ty = generated_image->height - (int)max(max(nv0, nv1), max(nv2, nv3));

  generate_affine_transformation(a, 0., 0., theta, phi, lambda1, lambda2, float(Tx), float(Ty));
}

void affine_image_generator06::generate_Id_affine_transformation(void)
{
  generate_affine_transformation(a, 0, 0 , 0, 0, 1, 1, 0, 0);
}

void affine_image_generator06::affine_transformation(float p_a[6],
                                                     float u, float v,
                                                     float & nu, float & nv)
{
  nu = u * p_a[0] + v * p_a[1] + p_a[2];
  nv = u * p_a[3] + v * p_a[4] + p_a[5];
}

void affine_image_generator06::inverse_affine_transformation(float p_a[6],
							     float u, float v,
							     float & nu, float & nv)
{
  float det = p_a[0] * p_a[4] - p_a[3] * p_a[1];

  nu = 1.f / det * ( p_a[4] * (u - p_a[2]) - p_a[1] * (v - p_a[5]));
  nv = 1.f / det * (-p_a[3] * (u - p_a[2]) + p_a[0] * (v - p_a[5]));
}

void affine_image_generator06::affine_transformation(float u, float v, float & nu, float & nv)
{
  affine_transformation(a, u, v, nu, nv);
}

void affine_image_generator06::inverse_affine_transformation(float u, float v, float & nu, float & nv)
{
  inverse_affine_transformation(a, u, v, nu, nv);
}


void affine_image_generator06::add_white_noise(IplImage * image, int gray_level_to_avoid)
{
  for(int y = 0; y < image->height; y++) {
    unsigned char * line = (unsigned char *)(image->imageData + y * image->widthStep);

    int * noise = limited_white_noise + rand() % (prime - image->width);

    for(int x = 0; x < image->width; x++) {
      int p = int(*line);

      if (p != gray_level_to_avoid) {
	p += *noise;

	*line = (p > 255) ? 255 : (p < 0) ? 0 : (unsigned char)p;
      }
      line++;
      noise++;
    }
  }
}

void affine_image_generator06::replace_by_noise(IplImage * image, int value)
{
  for(int y = 0; y < image->height; y++) {
    unsigned char * row = mcvRow(image, y, unsigned char);

    for(int x = 0; x < image->width; x++)
      if (int(row[x]) == value) {
	row[x] = white_noise[index_white_noise];
	index_white_noise++;
	if (index_white_noise >= prime) index_white_noise = 1 + rand() % 6;
      }
  }
}

void affine_image_generator06::generate_affine_image(void)
{
  CvMat A = cvMat(2, 3, CV_32F, a);

  if (use_random_background)
    cvSet(generated_image, cvScalar(128));
  else
    cvSet(generated_image, cvScalar(rand() % 256));

  cvWarpAffine(original_image_with_128_as_background, generated_image, &A,
	       CV_INTER_NN + CV_WARP_FILL_OUTLIERS /* + CV_WARP_INVERSE_MAP*/, cvScalarAll(128));

  if (use_random_background)
    replace_by_noise(generated_image, 128);

  if (add_gaussian_smoothing && rand() % 3 == 0) {
    int aperture = 3 + 2 * (rand() % 3);
    cvSmooth(generated_image, generated_image, CV_GAUSSIAN, aperture, aperture);
  }

  if (change_intensities) cvCvtScale(generated_image, generated_image, rand(0.8f, 1.2f), rand(-10, 10));

  //   mcvSaveImage("g.bmp", generated_image);
  //   exit(0);


  if (noise_level > 0 && add_noise)
    if (use_random_background) add_white_noise(generated_image);
    else add_white_noise(generated_image, 128);

  if (save_images) {
    static int n = 0;
    mcvSaveImage(generic_name_of_saved_images, n, generated_image);
    n++;
  }
}
