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
#include <fstream>
using namespace std;

#include "ferns.h"

// ds_min and ds_max currently ignored. Taking ds_min = ds_max = 0
ferns::ferns(int number_of_ferns, int number_of_tests_per_fern,
             int dx_min, int dx_max, int dy_min, int dy_max, int ds_min, int ds_max)
{
  alloc(number_of_ferns, number_of_tests_per_fern);
  pick_random_tests(dx_min, dx_max, dy_min, dy_max, ds_min, ds_max);

  width_full_images = height_full_images = -1;
  for(int i = 0; i < maximum_number_of_octaves; i++)
    width_aztec_pyramid[i] = height_aztec_pyramid[i] = -1;
}

ferns::ferns(char * filename)
{
  ifstream f(filename);

  if (!f.is_open()) {
    cerr << "ferns::ferns(char * filename): error reading file " << filename << "." << endl;
    correctly_read = false;
    return;
  }

  load(f);

  f.close();
}

ferns::ferns(ifstream & f)
{
  load(f);
}

void ferns::load(ifstream & f)
{
  int nf, nt;

  f >> nf >> nt;
  
  cout << "> [ferns] " << nf << " ferns, " << nt << " tests per fern." << endl;

  alloc(nf, nt);

  char c; do f.read(&c, 1); while (c != '.');

  f.read((char*)DX1, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.read((char*)DY1, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.read((char*)DS1, number_of_ferns * number_of_tests_per_fern * sizeof(int));

  f.read((char*)DX2, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.read((char*)DY2, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.read((char*)DS2, number_of_ferns * number_of_tests_per_fern * sizeof(int));

  compute_max_d();
  correctly_read = true;

  width_full_images = height_full_images = -1;
  for(int i = 0; i < maximum_number_of_octaves; i++)
    width_aztec_pyramid[i] = height_aztec_pyramid[i] = -1;
}

bool ferns::save(char * filename)
{
  ofstream f(filename);
  
  if (!f.is_open()) {
    cerr << "ferns::save(char * filename): error saving file " << filename << "." << endl;

    return false;
  }

  bool result = save(f);

  f.close();

  return result;
}

bool ferns::save(ofstream & f)
{
  f << number_of_ferns << " " << number_of_tests_per_fern << endl;

  char dot('.'); f.write(&dot, 1);

  f.write((char*)DX1, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.write((char*)DY1, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.write((char*)DS1, number_of_ferns * number_of_tests_per_fern * sizeof(int));

  f.write((char*)DX2, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.write((char*)DY2, number_of_ferns * number_of_tests_per_fern * sizeof(int));
  f.write((char*)DS2, number_of_ferns * number_of_tests_per_fern * sizeof(int));

  return true;
}

bool ferns::drop(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index)
{
  if (pyramid->type == fine_gaussian_pyramid::full_pyramid_357)
    return drop_full_images(pyramid, x, y, level, leaves_index);
  else
    return drop_aztec_pyramid(pyramid, x, y, level, leaves_index);
}

bool ferns::drop_full_images(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index)
{
  if (pyramid->full_images[level]->width  != width_full_images ||
      pyramid->full_images[level]->height != height_full_images) {
    precompute_D_array(D_full_images, pyramid->full_images[level]);
    width_full_images  = pyramid->full_images[level]->width;
    height_full_images = pyramid->full_images[level]->height;
  }

  IplImage * smoothed_image = pyramid->full_images[level];
  int shift_x = x + pyramid->border_size;
  int shift_y = y + pyramid->border_size;

  if (shift_x < max_d || shift_y < max_d || shift_x >= smoothed_image->width - max_d  || shift_y >= smoothed_image->height - max_d)
    return false;

  unsigned char * C = (unsigned char *)(smoothed_image->imageData +
                                        shift_y * smoothed_image->widthStep +
                                        shift_x);

  for(int i = 0; i < number_of_ferns; i++) {
    int index = 0;
    int * D_ptr = D_full_images + i * 2 * number_of_tests_per_fern;
    for(int j = 0; j < number_of_tests_per_fern; j++) {
      if (*(C + *D_ptr) < *(C + D_ptr[1])) index++;
      D_ptr += 2;
      if (j < number_of_tests_per_fern - 1) index <<= 1;
    }
    leaves_index[i] = index;
  }

  return true;
}

bool ferns::drop_aztec_pyramid(fine_gaussian_pyramid * pyramid, int x, int y, int level, int * leaves_index)
{
  int octave = level / 4; // 4 -> should not be hardcoded -> should be static const in fine_gaussian_pyramid !!!
  if (pyramid->aztec_pyramid[level]->width  != width_aztec_pyramid[octave] ||
      pyramid->aztec_pyramid[level]->height != height_aztec_pyramid[octave]) {
    precompute_D_array(D_aztec_pyramid[octave], pyramid->aztec_pyramid[level]);
    width_aztec_pyramid[octave]  = pyramid->aztec_pyramid[level]->width;
    height_aztec_pyramid[octave] = pyramid->aztec_pyramid[level]->height;
  }

  IplImage * smoothed_image = pyramid->aztec_pyramid[level];
  int shift_x = x + (pyramid->border_size >> octave);
  int shift_y = y + (pyramid->border_size >> octave);

  if (shift_x < max_d || shift_y < max_d || shift_x >= smoothed_image->width - max_d  || shift_y >= smoothed_image->height - max_d)
    return false;

  unsigned char * C = (unsigned char *)(smoothed_image->imageData +
                                        shift_y * smoothed_image->widthStep +
                                        shift_x);

  for(int i = 0; i < number_of_ferns; i++) {
    int index = 0;
    int * D_ptr = D_aztec_pyramid[octave] + i * 2 * number_of_tests_per_fern;
    for(int j = 0; j < number_of_tests_per_fern; j++) {
      index <<= 1;
      if (*(C + *D_ptr) < *(C + D_ptr[1])) index++;
      D_ptr += 2;
    }
    leaves_index[i] = index;
  }

  return true;
}

int * ferns::drop(fine_gaussian_pyramid * pyramid, int x, int y, int level)
{
  if (drop(pyramid, x, y, level, preallocated_leaves_index))
    return preallocated_leaves_index;
  else
    return 0;
}

// private:
void ferns::alloc(int number_of_ferns, int number_of_tests_per_fern)
{
  this->number_of_ferns = number_of_ferns;
  this->number_of_tests_per_fern = number_of_tests_per_fern;
  number_of_leaves_per_fern = 1 << number_of_tests_per_fern;
  preallocated_leaves_index = new int [number_of_ferns];

  int nb_tests = number_of_ferns * number_of_tests_per_fern;
  DX1 = new int[nb_tests];
  DY1 = new int[nb_tests];
  DS1 = new int[nb_tests];

  DX2 = new int[nb_tests];
  DY2 = new int[nb_tests];
  DS2 = new int[nb_tests];

  D_full_images = new int[2 * nb_tests];
  for(int i = 0; i < maximum_number_of_octaves; i++)
    D_aztec_pyramid[i] = new int[2 * nb_tests];
}

void ferns::pick_random_tests(int dx_min, int dx_max, int dy_min, int dy_max, int /*ds_min*/, int /*ds_max*/)
{
  for(int i = 0; i < number_of_ferns; i++)
    for(int j = 0; j < number_of_tests_per_fern; j++) {
      int k = i * number_of_tests_per_fern + j;

      DX1[k] = dx_min + rand() % (dx_max - dx_min + 1);
      DY1[k] = dy_min + rand() % (dy_max - dy_min + 1);
      DX2[k] = dx_min + rand() % (dx_max - dx_min + 1);
      DY2[k] = dy_min + rand() % (dy_max - dy_min + 1);
      DS1[k] = DS2[k] = 0;
    }

  compute_max_d();
}

void ferns::precompute_D_array(int * D, IplImage * image)
{
  for(int i = 0; i < number_of_ferns; i++)
    for(int j = 0; j < number_of_tests_per_fern; j++) {
      int k = i * number_of_tests_per_fern + j;
      D[2 * k]     = DX1[k] + image->widthStep * DY1[k];
      D[2 * k + 1] = DX2[k] + image->widthStep * DY2[k];
    }
}

void ferns::compute_max_d(void)
{
  max_d = 0;

  for(int i = 0; i < number_of_ferns; i++)
    for(int j = 0; j < number_of_tests_per_fern; j++) {
      int k = i * number_of_tests_per_fern + j;

      if (abs(DX1[k]) > max_d) max_d = abs(DX1[k]);
      if (abs(DY1[k]) > max_d) max_d = abs(DY1[k]);
      if (abs(DX2[k]) > max_d) max_d = abs(DX2[k]);
      if (abs(DY2[k]) > max_d) max_d = abs(DY2[k]);
    }
}
