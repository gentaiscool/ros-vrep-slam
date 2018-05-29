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

#include "buffer_management.h"
#include "mcvGaussianSmoothing.h"


//   Weight Computation:

//   How to compute more precise weights by linear interpolation of the intensities of the image to be convolved ?

//   We write
//   G o I = \sum_{i =-oo}^{+oo} \Int_{i-1/2}^i G(x) * linear_interpolation(I_{i-1}, I_i, x) dx + \Int_i^{i+1/2} G(x) * linear_interpolation(I_i, I_{i+1}, x) dx

//   = \sum_{i =-oo}^{+oo} \Int_{i-1/2}^i G(x) * [(-x+i)I_{i-1} + (x+1-i)I_i] dx + \Int_i^{i+1/2} G(x) * [(-x+1+i)I_i + (x-i)I_{i+1}] dx

//   = \sum_{i =-oo}^{+oo} ( \Int_{i-1}^{i+1} G(x)f(x) dx ) I_i

//   with f(x) =
//   (x+1-i)  if  i-1 <= x < i-1/2
//   (x+1-i)  if  i-1/2 <= x < i
//   (-x+1+i) if  i <= x < i+1/2
//   (-x+i+1) if  i+1/2 <= x < i+1
//   0 otherwise

//   ie f(x) =
//   (x+1-i)  if  i-1 <= x < i
//   (-x+1+i) if  i <= x < i+1
//   0 otherwise

//   We can check that f(x) is continuous at i.


void gaussianKernelWeightComputation(double sigma, int kernel_size, int shift)
{
  const int N = 100;

  cout << "Sigma = " << sigma << ". Using a shift of " << shift << " bits." << endl;
  // True weights:
  double sum = 0;
  for(int i = -kernel_size/2; i <= +kernel_size/2; i++) {
    double weight = 0;
    for(int j = 0; j < N; j++) {
      double x = 2.0 / N * j + i - 1;
      double f = (x < i) ? x + 1 - i : -x + 1 + i;
      double dx = 2.0 / N;
      double G = 1. / (sqrt(2 * 3.14159) * sigma) * exp(-x*x / (2 * sigma * sigma));

      weight += G * f * dx;
    }
    sum += weight;
  }

  // Correction so that sum weights = 1:
  int sum_w = 0;
  for(int i = -kernel_size/2; i <= +kernel_size/2; i++) {
    double weight = 0;
    for(int j = 0; j < N; j++) {
      double x = 2.0 / N * j + i - 1;
      double f = (x < i) ? x + 1 - i : -x + 1 + i;
      double dx = 2.0 / N;
      double G = 1. / (sqrt(2 * 3.14159) * sigma) * exp(-x*x / (2 * sigma * sigma));

      weight += G * f * dx;
    }
    weight /= sum;
    cout << " " << i << " -> " << weight << " -> " << int(weight * (1 << (shift / 2)) + 0.5) << endl;
    sum_w += int(weight * (1 << (shift / 2)) + 0.5);
  }

  if (sum_w != (1 << shift / 2))
    cout << "These weights are not correct: you still have to ensure that sum(weights) = 1 << "
	 << shift/2 << " = " << (1 << shift/2) << endl;
}

inline void mcvGaussianSmoothing_3x3(IplImage * im_src, IplImage * im_dst, const int w, const int h, IplImage * im_int_buffer, const int W0, const int W1, const int shift)
{
  // First pass: make use of intermediate_int_image
  for(int y = 0; y < h; y++) {
    unsigned char * src = mcvRow(im_src, y,  unsigned char);
    int * ints = mcvRow(im_int_buffer, y, int);

    for(int x = 1; x < w - 1; x++)
      ints[x] = W0 * int(src[x]) + W1 * (int(src[x - 1]) + int(src[x + 1]));

    ints[0] = ints[1];
    ints[w - 1] = ints[w - 2];
  }

  // Second pass:
  const int delta = 1 << (shift - 1);
  for(int y = 1; y < h - 1; y++) {
    int * row0 = mcvRow(im_int_buffer, y - 1, int);
    int * row1 = (int *)((char*)row0 + im_int_buffer->widthStep);
    int * row2 = (int *)((char*)row1 + im_int_buffer->widthStep);

    unsigned char * dest = mcvRow(im_dst, y, unsigned char);

    for(int x = 0; x < w; x++)
      dest[x] = (unsigned char)(( W0 * row1[x] + W1 * (row0[x] + row2[x]) + delta) >> shift);
  }

  // Second pass: borders...
  unsigned char * dest0 = mcvRow(im_dst, 0, unsigned char);
  unsigned char * dest1 = dest0 + im_dst->widthStep;
  unsigned char * destw1 = mcvRow(im_dst, h - 1, unsigned char);
  unsigned char * destw2 = destw1 - im_dst->widthStep;

  for(int x = 0; x < w; x++) {
    dest0[x]  = dest1[x];
    destw1[x] = destw2[x];
  }
}

inline void mcvGaussianSmoothing_5x5(IplImage * im_src, IplImage * im_dst, const int w, const int h, IplImage * im_int_buffer, const int W0, const int W1, const int W2, const int shift)
{
  // First pass: make use of intermediate_int_image
  for(int y = 0; y < h; y++) {
    unsigned char * src = mcvRow(im_src, y,  unsigned char);
    int * ints = mcvRow(im_int_buffer, y, int);

    for(int x = 2; x < w - 2; x++)
      ints[x] = W0 * int(src[x]) + W1 * (int(src[x - 1]) + int(src[x + 1])) + W2 * (int(src[x - 2]) + int(src[x + 2]));

    ints[0] = ints[1] = ints[2];
    ints[w - 1] = ints[w - 2] = ints[w - 3];
  }

  // Second pass:
  const int delta = 1 << (shift - 1);
  for(int y = 2; y < h - 2; y++) {
    int * row0 = mcvRow(im_int_buffer, y - 2, int);
    int * row1 = (int *)((char*)row0 + im_int_buffer->widthStep);
    int * row2 = (int *)((char*)row1 + im_int_buffer->widthStep);
    int * row3 = (int *)((char*)row2 + im_int_buffer->widthStep);
    int * row4 = (int *)((char*)row3 + im_int_buffer->widthStep);

    unsigned char * dest = mcvRow(im_dst, y, unsigned char);

    for(int x = 0; x < w; x++)
      dest[x] = (unsigned char)(( W0 * row2[x] + W1 * (row1[x] + row3[x]) + W2 * (row0[x] + row4[x]) + delta) >> shift);
  }

  // Second pass: borders...
  unsigned char * dest0 = mcvRow(im_dst, 0, unsigned char);
  unsigned char * dest1 = dest0 + im_dst->widthStep;
  unsigned char * dest2 = dest1 + im_dst->widthStep;
  unsigned char * destw1 = mcvRow(im_dst, h - 1, unsigned char);
  unsigned char * destw2 = destw1 - im_dst->widthStep;
  unsigned char * destw3 = destw2 - im_dst->widthStep;

  for(int x = 0; x < w; x++) {
    dest0[x]  = dest1[x]  = dest2[x];
    destw1[x] = destw2[x] = destw3[x];
  }
}

inline void mcvGaussianSmoothing_7x7_standard_weights(IplImage * im_src, IplImage * im_dst,
						      const int w, const int h,
						      IplImage * im_int_buffer,
						      const int width_int_buffer)
{
  // First pass: make use of intermediate_int_image

  for(int y = 0; y < h; y++) {
    unsigned char * src = mcvRow(im_src, y,  unsigned char);
    int * ints = mcvRow(im_int_buffer, y, int);

    for(int x = 3; x < w - 3; x++)
      ints[x] =
	2 * (9 * int(src[x]) +	7 * (int(src[x - 1]) + int(src[x + 1])) + int(src[x - 3]) + int(src[x + 3])) +
	7 * (int(src[x - 2]) + int(src[x + 2]));

    ints[0] = ints[1] = ints[2] = ints[3];
    ints[w - 1] = ints[w - 2] = ints[w - 3] = ints[w - 4];
  }

  // Second pass:
  const int delta = 1 << (12 - 1);
  const int D = width_int_buffer;
  for(int y = 3; y < h - 3; y++) {
    int * row0 = mcvRow(im_int_buffer, y - 3, int);
    unsigned char * dest = mcvRow(im_dst, y, unsigned char);

    for(int x = 0; x < w; x++)
      dest[x] = (unsigned char)((2 * (9 * (row0 + 3 * D)[x] +
				      7 * ((row0 + 2 * D)[x] + (row0 + 4 * D)[x]) +
				      row0[x] + (row0 + 6 * D)[x]) +
				 7 * ((row0 +     D)[x] + (row0 + 5 * D)[x]) + delta) >> 12);
  }

  // Second pass: borders...
  unsigned char * dest0 = mcvRow(im_dst, 0, unsigned char);
  unsigned char * dest1 = dest0 + im_dst->widthStep;
  unsigned char * dest2 = dest1 + im_dst->widthStep;
  unsigned char * dest3 = dest2 + im_dst->widthStep;
  unsigned char * destw1 = mcvRow(im_dst, h - 1, unsigned char);
  unsigned char * destw2 = destw1 - im_dst->widthStep;
  unsigned char * destw3 = destw2 - im_dst->widthStep;
  unsigned char * destw4 = destw3 - im_dst->widthStep;

  for(int x = 0; x < w; x++) {
    dest0[x] = dest1[x] = dest2[x] = dest3[x];
    destw1[x] = destw2[x] = destw3[x] = destw4[x];
  }
}

inline void mcvGaussianSmoothing_7x7(IplImage * im_src, IplImage * im_dst,
				     const int w, const int h,
				     IplImage * im_int_buffer,
				     const int W0, const int W1, const int W2, const int W3, const int shift)
{
  // First pass: make use of intermediate_int_image

  for(int y = 0; y < h; y++) {
    unsigned char * src = mcvRow(im_src, y,  unsigned char);
    int * ints = mcvRow(im_int_buffer, y, int);

    for(int x = 3; x < w - 3; x++)
      ints[x] =
	W0 * int(src[x]) +
	W1 * (int(src[x - 1]) + int(src[x + 1])) +
	W2 * (int(src[x - 2]) + int(src[x + 2])) +
	W3 * (int(src[x - 3]) + int(src[x + 3]));

    ints[0] = ints[1] = ints[2] = ints[3];
    ints[w - 1] = ints[w - 2] = ints[w - 3] = ints[w - 4];
  }

  // Second pass:
  const int delta = 1 << (shift - 1);
  const int D = im_int_buffer->widthStep / 4;
  for(int y = 3; y < h - 3; y++) {
    int * row0 = mcvRow(im_int_buffer, y - 3, int);
    unsigned char * dest = mcvRow(im_dst, y, unsigned char);

    for(int x = 0; x < w; x++)
      dest[x] = (unsigned char)(( W0 *  (row0 + 3 * D)[x] +
				  W1 * ((row0 + 2 * D)[x] + (row0 + 4 * D)[x]) +
				  W2 * ((row0 +     D)[x] + (row0 + 5 * D)[x]) +
				  W3 * ( row0         [x] + (row0 + 6 * D)[x]) + delta) >> shift);
  }

  // Second pass: borders...
  unsigned char * dest0 = mcvRow(im_dst, 0, unsigned char);
  unsigned char * dest1 = dest0 + im_dst->widthStep;
  unsigned char * dest2 = dest1 + im_dst->widthStep;
  unsigned char * dest3 = dest2 + im_dst->widthStep;
  unsigned char * destw1 = mcvRow(im_dst, h - 1, unsigned char);
  unsigned char * destw2 = destw1 - im_dst->widthStep;
  unsigned char * destw3 = destw2 - im_dst->widthStep;
  unsigned char * destw4 = destw3 - im_dst->widthStep;

  for(int x = 0; x < w; x++) {
    dest0[x] = dest1[x] = dest2[x] = dest3[x];
    destw1[x] = destw2[x] = destw3[x] = destw4[x];
  }
}

void mcvGaussianSmoothing_3x3(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_3x3(src, dst, 640, 480, int_buffer, 2, 1, 4);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_3x3(src, dst, 320, 240, int_buffer, 2, 1, 4);
  else                           mcvGaussianSmoothing_3x3(src, dst,   w,   h, int_buffer, 2, 1, 4);
}

void mcvGaussianSmoothing_5x5(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_5x5(src, dst, 640, 480, int_buffer, 6, 4, 1, 8);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_5x5(src, dst, 320, 240, int_buffer, 6, 4, 1, 8);
  else                           mcvGaussianSmoothing_5x5(src, dst,   w,   h, int_buffer, 6, 4, 1, 8);
}

void mcvGaussianSmoothing_7x7(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;
  const int bw = int_buffer->widthStep / 4;

  if (bw == 704) {
    if      (w == 704 && h == 544) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 704, 544, int_buffer, 704);
    else if (w == 352 && h == 272) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 352, 272, int_buffer, 704);
    else if (w == 176 && h == 136) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 176, 136, int_buffer, 704);
    else                           mcvGaussianSmoothing_7x7_standard_weights(src, dst,   w,   h, int_buffer, 704);
  } else {
    if      (w == 784 && h == 640) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 784, 640, int_buffer, bw);
    else if (w == 704 && h == 544) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 352, 272, int_buffer, bw);
    else if (w == 640 && h == 480) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 640, 480, int_buffer, bw);
    else if (w == 392 && h == 320) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 392, 320, int_buffer, bw);
    else if (w == 352 && h == 272) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 352, 272, int_buffer, bw);
    else if (w == 320 && h == 240) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 320, 240, int_buffer, bw);
    else if (w == 196 && h == 160) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 196, 160, int_buffer, bw);
    else if (w == 176 && h == 136) mcvGaussianSmoothing_7x7_standard_weights(src, dst, 176, 136, int_buffer, bw);
    else                           mcvGaussianSmoothing_7x7_standard_weights(src, dst,   w,   h, int_buffer, bw);
  }
}

void mcvGaussianSmoothing_dsigma_0_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_3x3(src, dst, 640, 480, int_buffer, 138, 59, 16);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_3x3(src, dst, 320, 240, int_buffer, 138, 59, 16);
  else                          mcvGaussianSmoothing_3x3(src, dst,   w,   h, int_buffer, 138, 59, 16);
}

void mcvGaussianSmoothing_dsigma_1_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_3x3(src, dst, 640, 480, int_buffer, 126, 65, 16);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_3x3(src, dst, 320, 240, int_buffer, 126, 65, 16);
  else                          mcvGaussianSmoothing_3x3(src, dst,   w,   h, int_buffer, 126, 65, 16);
}

void mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_3x3(src, dst, 640, 480, int_buffer, 116, 70, 16);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_3x3(src, dst, 320, 240, int_buffer, 116, 70, 16);
  else                          mcvGaussianSmoothing_3x3(src, dst,   w,   h, int_buffer, 116, 70, 16);
}

void mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4_5x5(IplImage * src, IplImage * dst, IplImage * int_buffer)
{
  const int w = src->width;
  const int h = src->height;

  if (w == 640 && h == 480)      mcvGaussianSmoothing_5x5(src, dst, 640, 480, int_buffer, 102, 63, 14, 16);
  else if (w == 320 && h == 240) mcvGaussianSmoothing_5x5(src, dst, 320, 240, int_buffer, 102, 63, 14, 16);
  else                          mcvGaussianSmoothing_5x5(src, dst,   w,   h, int_buffer, 102, 63, 14, 16);
}

