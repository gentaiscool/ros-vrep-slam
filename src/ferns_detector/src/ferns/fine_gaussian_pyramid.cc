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
using namespace std;

#include <assert.h>
#include <stdlib.h>

#include "mcv.h"
#include "mcvGaussianSmoothing.h"
#include "fine_gaussian_pyramid.h"
// #include "linear_filter.h"

fine_gaussian_pyramid::fine_gaussian_pyramid(int type, int outer_border, int number_of_octaves, int inner_border)
{
  this->type = type;

  this->outer_border = outer_border;
  this->inner_border = inner_border;
  this->border_size = outer_border + inner_border;
  this->number_of_octaves = number_of_octaves;

  width = height = -1;

  original_image = 0;
  aztec_pyramid = 0;
  full_images = 0;
  coeffs = 0;
  add_a_row = 0;
  add_a_col = 0;

  intermediate_int_image = 0;
}

fine_gaussian_pyramid::fine_gaussian_pyramid(int type, IplImage * image, int outer_border, int number_of_octaves, int inner_border)
{
  this->type = type;

  original_image = 0;
  aztec_pyramid = 0;
  full_images = 0;
  coeffs = 0;
  add_a_row = 0;
  add_a_col = 0;

  intermediate_int_image = 0;

  alloc(image->width - 2 * inner_border, image->height - 2 * inner_border, outer_border, number_of_octaves, inner_border);
  set_image(image);
}

fine_gaussian_pyramid::fine_gaussian_pyramid(int type, char * image_name, int outer_border, int number_of_octaves, int inner_border)
{
  this->type = type;

  original_image = 0;
  aztec_pyramid = 0;
  full_images = 0;
  coeffs = 0;
  add_a_row = 0;
  add_a_col = 0;

  intermediate_int_image = 0;

  IplImage * image = mcvLoadImage(image_name, 0);
  alloc(image->width - 2 * inner_border, image->height - 2 * inner_border, outer_border, number_of_octaves, inner_border);
  set_image(image);
  cvReleaseImage(&image);
}

fine_gaussian_pyramid::~fine_gaussian_pyramid()
{
  free();
}

void fine_gaussian_pyramid::free(void)
{
  if (original_image != 0)
    cvReleaseImage(&original_image);

  if (aztec_pyramid != 0) {
    for(int i = 0; i < 4 * number_of_octaves; i++)
      if (aztec_pyramid[i] != 0)
	cvReleaseImage(&aztec_pyramid[i]);
    delete [] aztec_pyramid;
  }

  if (full_images != 0) {
    for(int i = 0; i < 4 * number_of_octaves; i++)
      cvReleaseImage(&full_images[i]);
    delete [] full_images;
  }

  delete [] coeffs;
  delete [] add_a_row;
  delete [] add_a_col;

  aztec_pyramid = 0;
  full_images = 0;
  coeffs = 0;
  add_a_row = 0;
  add_a_col = 0;

  intermediate_int_image = 0;
}

int fine_gaussian_pyramid::level_from_scale(float scale)
{
  switch(type) {
  case yape_pyramid_3: return 1 + 4 * int(scale);
  case yape_pyramid_5: return 2 + 4 * int(scale);
  case yape_pyramid_7: return 3 + 4 * int(scale);
  default:
    cerr << "Warning fine_gaussian_pyramid::level_from_scale function called while type = " << type << endl;
    return 2 + 4 * int(scale);
  }
}

int fine_gaussian_pyramid::convCoord(int x, int from, int to, unsigned max)
{
  if (max == 2)
    return (convCoord(x, from, to, 0) + convCoord(x, from, to, 1)) >> 1;

  if (to == from)
    return x;

  if (to < from) {
    if (max == 1) {
      int r = x;
      for (int i = from; i < to; i++)
        r = r*2 + 1;      return r;
    }
    return x << ( from - to );
  }

  return x >> ( to - from );
}

float fine_gaussian_pyramid::convCoordf(float x, int from, int to)
{
  if (to == from)
    return x;

  if (to < from)
    return x * float(1 << (from - to));

  return x / float(1 << (to - from));
}

unsigned char * fine_gaussian_pyramid::full_image_row(int level, int y)
{
  return mcvRow(full_images[level], y + border_size, unsigned char) + border_size;
}

int * fine_gaussian_pyramid::full_image_row_int(int level, int y)
{
  return mcvRow(full_images[level], y + border_size, int) + border_size;
}


void fine_gaussian_pyramid::alloc(int width, int height, int outer_border, int number_of_octaves, int inner_border)
{
  this->outer_border = outer_border;
  this->inner_border = inner_border;
  this->border_size = outer_border + inner_border;
  this->number_of_octaves = number_of_octaves;
  this->width  = width;
  this->height = height;

  int octave_total_width  = total_width  = width  + 2 * border_size;
  int octave_total_height = total_height = height + 2 * border_size;

  aztec_pyramid = new IplImage*[number_of_octaves * 4];
  full_images = new IplImage*[number_of_octaves * 4];
  coeffs = new float[number_of_octaves * 4];

  add_a_row = new bool[number_of_octaves * 4];
  add_a_col = new bool[number_of_octaves * 4];

  original_image = cvCreateImage(cvSize(width + 2 * inner_border, height + 2 * inner_border), IPL_DEPTH_8U, 1);
  intermediate_int_image = cvCreateImage(cvSize(total_width, total_height), IPL_DEPTH_32S, 1);
  widthStep_int  = intermediate_int_image->widthStep / sizeof(int);

  switch(type) {
  case yape_pyramid_3: {
    float c = 1.F;
    int n = 0;
    for(int i = 0; i < number_of_octaves * 4; i++) {
      if (i > 0 && i % 4 == 0) {
	add_a_col[n] = (octave_total_width % 2 == 1);
	add_a_row[n] = (octave_total_height % 2 == 1);
	n++;

	octave_total_width /= 2;
	octave_total_height /= 2;
	c /= 2;
      }

      if (i % 4 == 1)
	aztec_pyramid[i] = cvCreateImage(cvSize(octave_total_width, octave_total_height), IPL_DEPTH_8U, 1);
      else
	aztec_pyramid[i] = 0;
      full_images[i] = 0;
      coeffs[i] = c;
    }
    break;
  }
  case yape_pyramid_7: {
    float c = 1.F;
    int n = 0;
    for(int i = 0; i < number_of_octaves * 4; i++) {
      if (i > 0 && i % 4 == 0) {
	add_a_col[n] = (octave_total_width % 2 == 1);
	add_a_row[n] = (octave_total_height % 2 == 1);
	n++;

	octave_total_width /= 2;
	octave_total_height /= 2;
	c /= 2;
      }

      if (i % 4 == 3 || i % 4 == 0)
	aztec_pyramid[i] = cvCreateImage(cvSize(octave_total_width, octave_total_height), IPL_DEPTH_8U, 1);
      else
	aztec_pyramid[i] = 0;
      full_images[i] = 0;
      coeffs[i] = c;
    }
    break;
  }
  case full_pyramid_333:
  case full_pyramid_357:
    {
      float c = 1.F;
      int n = 0;
      for(int i = 0; i < number_of_octaves * 4; i++) {
	if (i > 0 && i % 4 == 0) {
	  add_a_col[n] = (octave_total_width % 2 == 1);
	  add_a_row[n] = (octave_total_height % 2 == 1);
	  n++;

	  octave_total_width /= 2;
	  octave_total_height /= 2;
	  c /= 2;
	}

	full_images[i]   = cvCreateImage(cvSize(total_width,        total_height),        IPL_DEPTH_8U, 1);
	aztec_pyramid[i] = cvCreateImage(cvSize(octave_total_width, octave_total_height), IPL_DEPTH_8U, 1);
	coeffs[i] = c;
      }
      break;
    }
  default: ;
  }
}

void fine_gaussian_pyramid::set_image(const IplImage * image)
{
  if (width + 2 * inner_border != image->width || height + 2 * inner_border != image->height) {
    free();
    alloc(image->width - 2 * inner_border, image->height - 2 * inner_border, outer_border, number_of_octaves, inner_border);
  }

  cvCopy(image, original_image);

  CvRect dest_roi = cvRect(outer_border, outer_border, image->width, image->height);
  cvSetImageROI(aztec_pyramid[0], dest_roi);
  CvRect src_roi = cvRect(0, 0, image->width, image->height);
  IplROI * image_roi = image->roi;

  // An ugly trick to use const on image. I swear the image is actually not modified !!!
  IplImage * tmp_image = (IplImage *)((int*)image);
  cvSetImageROI(tmp_image, src_roi);
  cvCopy(tmp_image, aztec_pyramid[0]);
  cvFree(&(aztec_pyramid[0]->roi));
  cvFree(&(tmp_image->roi));
  tmp_image->roi = image_roi;

  // Create border
  for(int i = 0; i < outer_border; i++) {
    unsigned char * border = mcvRow(aztec_pyramid[0], i, unsigned char);
    unsigned char * first_row = mcvRow(image, 0, unsigned char);
    for(int j = 0; j < image->width; j++)
      border[outer_border + j] = first_row[j];
  }
  for(int i = outer_border + image->height; i < total_height; i++) {
    unsigned char * border = mcvRow(aztec_pyramid[0], i, unsigned char);
    unsigned char * last_row = mcvRow(image, image->height - 1, unsigned char);
    for(int j = 0; j < width; j++)
      border[outer_border + j] = last_row[j];
  }
  int j_step = aztec_pyramid[0]->widthStep;
  for(int i = 0; i < outer_border; i++) {
    unsigned char * border = mcvRow(aztec_pyramid[0], 0, unsigned char) + i;
    unsigned char * first_row = mcvRow(aztec_pyramid[0], 0, unsigned char) + outer_border;
    for(int j = 0; j < total_height; j++) {
      *border = *first_row;
      border += j_step;
      first_row += j_step;
    }
  }
  for(int i = outer_border + image->width; i < total_width; i++) {
    unsigned char * border = mcvRow(aztec_pyramid[0], 0, unsigned char) + i;
    unsigned char * first_row = mcvRow(aztec_pyramid[0], 0, unsigned char) + image->width + outer_border - 1;
    for(int j = 0; j < total_height; j++) {
      *border = *first_row;
      border += j_step;
      first_row += j_step;
    }
  }

  compute_from_level0();
}

bool fine_gaussian_pyramid::load_image(char * image_name, int i)
{
  char image_name_i[1000];
  sprintf(image_name_i, image_name, i);
  return load_image(image_name_i);
}

bool fine_gaussian_pyramid::load_image(char * image_name)
{
  IplImage * image = mcvLoadImage(image_name, 0);

  if (image == 0) return false;

  set_image(image);
  cvReleaseImage(&image);

  return true;
}

void fine_gaussian_pyramid::compute_from_level0(void)
{
  // Could save time here yape_pyramid_3, yape_pyramid_3, and yape_pyramid_7
  // cvPyrDown and cvSmooth should be done in one pass. Does it really save time ?? ??????

  switch(type) {
  case yape_pyramid_3:
    for(int i = 0; i < number_of_octaves; i++) {
      cvSmooth(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 1], CV_GAUSSIAN, 3, 3);
      if (i < number_of_octaves - 1) cvPyrDown(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 4]);
    }
    break;
  case yape_pyramid_5:
    for(int i = 0; i < number_of_octaves; i++) {
      cvSmooth(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 2], CV_GAUSSIAN, 5, 5);
      if (i < number_of_octaves - 1) cvPyrDown(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 4]);
    }
    break;
  case yape_pyramid_7:
    for(int i = 0; i < number_of_octaves; i++) {
      mcvGaussianSmoothing_7x7(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 3], intermediate_int_image);
      if (i < number_of_octaves - 1) cvPyrDown(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 4]);
    }
    break;
  case full_pyramid_333: {
    // Build aztec pyramid:
    for(int i = 0; i < number_of_octaves; i++) {
      mcvGaussianSmoothing_dsigma_0_sigma_0_Scales_4(aztec_pyramid[4 * i],     aztec_pyramid[4 * i + 1], intermediate_int_image);
      mcvGaussianSmoothing_dsigma_1_sigma_0_Scales_4(aztec_pyramid[4 * i + 1], aztec_pyramid[4 * i + 2], intermediate_int_image);
      //      mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4(aztec_pyramid[4 * i + 2], aztec_pyramid[4 * i + 3], intermediate_int_image);
      mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4_5x5(aztec_pyramid[4 * i + 2], aztec_pyramid[4 * i + 3], intermediate_int_image);

      if (i < number_of_octaves - 1)
        rawReduce(aztec_pyramid[4 * i + 3], aztec_pyramid[4 * i + 4]); // reducing 4 * i + 3 instead of 4 * i + 2 seems to produce better results
    }
    // Build full images:
    for(int i = 0; i < 4; i++)
      cvCopy(aztec_pyramid[i], full_images[i]);
    int n = 0;
    for(int i = 4; i < 4 * number_of_octaves; i++) {
      if (i % 4 == 0) n++;
      expand(aztec_pyramid[i], full_images[i], n);
    }
    break;
  }
  case full_pyramid_357: {
    // Build aztec pyramid:
    for(int i = 0; i < number_of_octaves; i++) {
      mcvGaussianSmoothing_3x3(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 1], intermediate_int_image);
      mcvGaussianSmoothing_5x5(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 2], intermediate_int_image);
      mcvGaussianSmoothing_7x7(aztec_pyramid[4 * i], aztec_pyramid[4 * i + 3], intermediate_int_image);
      if (i < number_of_octaves - 1)
        rawReduce(aztec_pyramid[4 * i + 2], aztec_pyramid[4 * i + 4]);
    }
    // Build full images:
    for(int i = 0; i < 4; i++)
      cvCopy(aztec_pyramid[i], full_images[i]);
    int n = 0;
    for(int i = 4; i < 4 * number_of_octaves; i++) {
      if (i % 4 == 0) n++;
      expand(aztec_pyramid[i], full_images[i], n);
    }
    break;
  }
  default:
    cerr << "fine_gaussian_pyramid::compute_from_level0 wrong type == " << type << endl;
    exit(0);
  }
}

int fine_gaussian_pyramid::save(char * filename)
{
  int result = 0;

  for(int i = 0; i < 4 * number_of_octaves; i++)
    result += mcvSaveImage(filename, i, full_images[i]);

  return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void fine_gaussian_pyramid::rawReduce(IplImage * original_image, IplImage * halfsize_image)
{
  for(int y = 0; y < halfsize_image->height; y++)
    {
      unsigned char * orig = mcvRow(original_image, 2 * y, unsigned char);
      unsigned char * half = mcvRow(halfsize_image,     y, unsigned char);

      int x2 = 0;
      for(int x = 0; x < halfsize_image->width; x++, x2 += 2)
        half[x] = orig[x2];
    }
}

void fine_gaussian_pyramid::expand(IplImage * original_image, IplImage * dblesize_image, int width, int height)
{
  const int width2  = width << 1;
  const int height2 = height << 1;

  // First pass: make use of intermediate_int_image
  for(int y = 0; y < height; y++) {
    unsigned char * orig = mcvRow(original_image, y,  unsigned char);
    int * ints = mcvRow(intermediate_int_image, y, int);

    ints[0] = 6 * int(orig[0]) + int(orig[0]) + int(orig[1]);
    ints[1] = 4 * (int(orig[0]) + int(orig[1]));
    int x = 1;
    for(int x2 = 2; x2 < width2 - 2; x2 += 2, x++) {
      const int ox = int(orig[x]), ox1 = int(orig[x + 1]);
      ints[x2] = 6 * ox + int(orig[x - 1]) + ox1;
      ints[x2 + 1] = 4 * (ox + ox1);
    }
    ints[width2 - 2] = 6 * int(orig[width - 1]) + int(orig[width - 2]) + int(orig[width - 1]);
    ints[width2 - 1] = 4 * (int(orig[width - 1]) + int(orig[width - 2]));
  }

  // Second pass:
  const int widthStep_char = dblesize_image->widthStep;
  for(int x2 = 0; x2 < width2; x2++) {
    int * ints = mcvRow(intermediate_int_image, 0, int) + x2;
    unsigned char * dest = mcvRow(dblesize_image, 0,  unsigned char) + x2;

    *dest = (unsigned char)( (6 * (*ints) + (*ints) + ints[widthStep_int] + (1 << 5)) >> 6 );
    dest += widthStep_char;
    *dest = (unsigned char)( ((*ints) + ints[widthStep_int] + (1 << 3)) >> 4 );
    dest += widthStep_char;
    ints += widthStep_int;

    for(int y2 = 2; y2 < height2 - 2; y2 += 2) {
      int i0 = *ints, i1 = ints[widthStep_int];
      *dest = (unsigned char)( ( 6 * i0 + ints[-widthStep_int] + i1 + (1 << 5)) >> 6 );
      dest += widthStep_char;

      *dest = (unsigned char)( (i0 + i1 + (1 << 3)) >> 4 );
      dest += widthStep_char;

      ints += widthStep_int;
    }

    *dest = (unsigned char)( (6 * (*ints) + (*ints) + ints[-widthStep_int] + (1 << 5)) >> 6 );
    dest += widthStep_char;
    *dest = (unsigned char)( ((*ints) + (1 << 2)) >> 3 );
  }
}

void fine_gaussian_pyramid::expand(IplImage * original_image, IplImage * dblesize_image)
{
  expand(original_image, dblesize_image, original_image->width, original_image->height);
}

void fine_gaussian_pyramid::expand(IplImage * original_image, IplImage * final_image, int n)
{
  expand(original_image, final_image);

  int width  = 2 * original_image->width;
  int height = 2 * original_image->height;

  if (add_a_row[n - 1])
    {
      unsigned char * dest1 = mcvRow(final_image, 2 * original_image->height - 1, unsigned char);
      unsigned char * dest2 = mcvRow(final_image, 2 * original_image->height, unsigned char);

      for(int x = 0; x < 2 * original_image->width; x++)
        dest2[x] = dest1[x];

      height++;
    }

  for(int i = 1; i < n; i++) {
    expand(final_image, final_image, width, height);
    width *= 2;
    height *= 2;
  }
}
