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
#ifndef mcvGaussianSmoothing_h
#define mcvGaussianSmoothing_h

#include "mcv.h"

// Function useful to determine the weights:
void gaussianKernelWeightComputation(double sigma, int kernel_size, int shift);

// Standard functions (same weights than opencv):
// 3x3 SMOOTHING weights =      1  2  1     (sigma = 1)
// 5x5 SMOOTHING weights =   1  4  6  4 1   (sigma = 1.26 not sure ??? = cubic root of 2)
// 7x7 SMOOTHING weights = 2 7 14 18 14 7 2 (sigma = 1.26 * 1.26)

// dst->depth = IPL_DEPTH_8U
void mcvGaussianSmoothing_3x3(IplImage * src, IplImage * dst, IplImage * int_buffer);
void mcvGaussianSmoothing_5x5(IplImage * src, IplImage * dst, IplImage * int_buffer);
void mcvGaussianSmoothing_7x7(IplImage * src, IplImage * dst, IplImage * int_buffer);

// Functions to compute a pyramid a la lowe:
// Assuming the original image corresponds to the "true image" smoothed by sigma0 = 1.0
// and using 4 "Scales" (Lowe takes 3):
// k^Scales sigma0 = 2 sigma0 => k = pow(2, 1/4) = 1.1892071
// The pyramid first image is the original image ("true image" smoothed by sigma0 = 1.0)
// The second image should be the "true image" smoothed by k sigma0 = 1.1892071
// This second image can be obtained by smoothing the original image by dsigma0 with:
// (k sigma0)^2 = sigma_0^2 + dsigma_0^2
// => dsigma_0 = sqrt(k^2 - 1) sigma = 0.643594
// Smoothing by dsigma0 can be obtained with weights (4 57 134 57 4) (shift = 16) OR (59 138 59) (shift = 16)
//
// (k^2 sigma0)^2 = (k sigma_0)^2 + dsigma_1^2
// dsigma_1 = sqrt(k^2 - 1) k sigma_0 = 0.765367
// Smoothing by dsigma1 can be obtained with weights (8 61 118 61 8) (shift = 16) OR (65 126 65) (shift = 16)
//
// dsigma_2 = sqrt(k^2 - 1) k^2 sigma_0 = 0.91018
// Smoothing by dsigma2 can be obtained with weights (1 14 62 102 62 14 1) (shift = 16)
// OR (14 63 102 63 14) (shift = 16) OR (70 116 70) (shift = 16)
//
// Values obtained with the following code:
//   double sigma0 = 1.0; */

//   double k = pow(2., 1. / 4.); */
//   cout << "k = " << k << endl; */

//   double dsigma0 = sqrt(k*k - 1) * sigma0;
//   gaussianKernelWeightComputation(dsigma0, 3, 16);
//   gaussianKernelWeightComputation(dsigma0, 5, 16);
//   gaussianKernelWeightComputation(dsigma0, 7, 16);

//   double dsigma1 = sqrt(k*k -1) * k * sigma0;
//   gaussianKernelWeightComputation(dsigma1, 3, 16);
//   gaussianKernelWeightComputation(dsigma1, 5, 16);
//   gaussianKernelWeightComputation(dsigma1, 7, 16);

//   double dsigma2 = sqrt(k*k -1) * k * k * sigma0;
//   gaussianKernelWeightComputation(dsigma2, 3, 16);
//   gaussianKernelWeightComputation(dsigma2, 5, 16);
//   gaussianKernelWeightComputation(dsigma2, 7, 16);

void mcvGaussianSmoothing_dsigma_0_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer);
void mcvGaussianSmoothing_dsigma_1_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer);
void mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4(IplImage * src, IplImage * dst, IplImage * int_buffer);
void mcvGaussianSmoothing_dsigma_2_sigma_0_Scales_4_5x5(IplImage * src, IplImage * dst, IplImage * int_buffer);

// Weights customization:
void mcvGaussianSmoothing_3x3(IplImage * src, IplImage * dst, const int w, const int h, IplImage * int_buffer, const int W0, const int W1, const int shift);
void mcvGaussianSmoothing_5x5(IplImage * src, IplImage * dst, const int w, const int h, IplImage * int_buffer, const int W0, const int W1, const int W2, const int shift);
void mcvGaussianSmoothing_7x7(IplImage * src, IplImage * dst, const int w, const int h, IplImage * int_buffer, const int W0, const int W1, const int W2, const int W3, const int shift);

#endif
