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
#ifndef affine_image_generator06_h
#define affine_image_generator06_h

#include <cv.h>

#include <fstream>
using namespace std;

#include "affine_transformation_range.h"

//! An affine image generator.
class affine_image_generator06
{
 public:
  affine_image_generator06(void);
  ~affine_image_generator06(void);

  void load_transformation_range(ifstream & f);
  void save_transformation_range(ofstream & f);
  void set_transformation_range(affine_transformation_range * range);

  void set_original_image(IplImage * original_image,
                          int generated_image_image_width = -1, int generated_image_image_height = -1);
  void set_mask(int x_min, int y_min, int x_max, int y_max);

  void generate_Id_image(void);
  void generate_random_affine_image(void);

  //! (ou, ov) in original image; (gu, gv) in generated image
  void affine_transformation(float ou, float ov, float & gu, float & gv);
  void inverse_affine_transformation(float gu, float gv, float & ou, float & ov);

  static void affine_transformation(float a[6], float u, float v, float & nu, float & nv);
  static void inverse_affine_transformation(float a[6], float u, float v, float & nu, float & nv);

  //! For debugging purposes
  void save_generated_images(char * generic_name);

  //! Default = 20
  void set_noise_level(int noise_level);
  //! Default = true;
  void set_use_random_background(bool use_random_background) { this->use_random_background = use_random_background; }
  void enable_random_background(void) { set_use_random_background(true); }
  void disable_random_background(void) { set_use_random_background(false); }
  void enable_noise(void) { add_noise = true; }
  void disable_noise(void) { add_noise = false; }

  //! Default true.
  void set_add_gaussian_smoothing(bool p_add_gaussian_smoothing)
    { add_gaussian_smoothing = p_add_gaussian_smoothing; }
  //! Default true.
  void set_change_intensities(bool p_change_intensities)
    { change_intensities = p_change_intensities; }

  //private:
  void generate_affine_image(void);

  void generate_affine_transformation(float a[6],
				      float initialTx, float initialTy,
				      float theta, float phi,
				      float lambda1, float lambda2,
				      float finalTx, float finalTy);

  void generate_random_affine_transformation(void);
  void generate_Id_affine_transformation(void);

  void set_default_values(void);

  void add_white_noise(IplImage * image, int gray_level_to_avoid = -1);
  void replace_by_noise(IplImage * image, int value);
  char * white_noise;
  int * limited_white_noise;
  int index_white_noise;
  int noise_level;

  bool use_random_background, change_intensities, add_gaussian_smoothing, add_noise;

  affine_transformation_range transformation_range;

  IplImage * original_image,  * original_image_with_128_as_background, * generated_image;
  float a[6];

  // for debugging:
  bool save_images;
  char generic_name_of_saved_images[1000];
};

#endif
