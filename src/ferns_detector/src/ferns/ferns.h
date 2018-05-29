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
#ifndef ferns_h
#define ferns_h

#include <fstream>
using namespace std;

#include "fine_gaussian_pyramid.h"

class ferns
{
 public:
  static const int maximum_number_of_octaves = 10;

  // ds_min and ds_max currently ignored (Always taking ds_min = ds_max = 0)
  ferns(int number_of_ferns, int number_of_tests_per_fern,
        int dx_min, int dx_max, int dy_min, int dy_max, int ds_min = 0, int ds_max = 0);

  ferns(char * filename);
  ferns(ifstream & f);
  bool correctly_read;

  bool save(char * filename);
  bool save(ofstream & f);

  // drop functions:
  // if pyramid->compute_full_resolution_images is set to true => do test on pyramid->full_images The ds in tests ARE CURRENTLY IGNORED.
  // otherwise => do test on pyramid->aztec_pyramid . The ds in tests ARE IGNORED.

  bool drop(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index);

  // Do NOT delete the returned pointer !!!
  int * drop(fine_gaussian_pyramid * pyramid, int x, int y, int level);

  // private:
  void load(ifstream & f);
  void alloc(int number_of_ferns, int number_of_tests_per_fern);
  void pick_random_tests(int dx_min, int dx_max, int dy_min, int dy_max, int ds_min, int ds_max);
  void precompute_D_array(int * D, IplImage * image);

  bool drop_full_images(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index);
  bool drop_aztec_pyramid(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index);

  int width_full_images, height_full_images;
  int width_aztec_pyramid[maximum_number_of_octaves], height_aztec_pyramid[maximum_number_of_octaves];

  int number_of_ferns, number_of_tests_per_fern, number_of_leaves_per_fern;
  int * DX1, * DY1, * DS1;
  int * DX2, * DY2, * DS2;
  int * D_full_images, * D_aztec_pyramid[maximum_number_of_octaves];

  void compute_max_d(void);
  int max_d;

  int * preallocated_leaves_index;
};

#endif
