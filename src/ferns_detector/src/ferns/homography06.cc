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
#include "homography06.h"


homography06::homography06(void)
{
  initialize();
}

homography06::homography06(const float h11, const float h12, const float h13,
                           const float h21, const float h22, const float h23,
                           const float h31, const float h32, const float h33)
{
  initialize();

  cvmSet(0, 0, h11); cvmSet(0, 1, h12); cvmSet(0, 2, h13);
  cvmSet(1, 0, h21); cvmSet(1, 1, h22); cvmSet(1, 2, h23);
  cvmSet(2, 0, h31); cvmSet(2, 1, h32); cvmSet(2, 2, h33);
}

homography06::homography06(const double h11, const double h12, const double h13,
                           const double h21, const double h22, const double h23,
                           const double h31, const double h32, const double h33)
{
  initialize();

  cvmSet(0, 0, h11); cvmSet(0, 1, h12); cvmSet(0, 2, h13);
  cvmSet(1, 0, h21); cvmSet(1, 1, h22); cvmSet(1, 2, h23);
  cvmSet(2, 0, h31); cvmSet(2, 1, h32); cvmSet(2, 2, h33);
}

void homography06::initialize(void)
{
  type = CV_32FC1;

  type = CV_MAT_MAGIC_VAL | CV_MAT_CONT_FLAG | CV_MAT_TYPE(type);
  cols = 3;
  rows = 3;
  step = cols * CV_ELEM_SIZE(type);
  data.ptr = (uchar*)new float[cols * rows];
  refcount = NULL;
}

homography06::~homography06()
{
  delete [] data.ptr;
}

ostream& operator<< (ostream& o, const homography06& H)
{
  o << cvmGet(&H, 0, 0) << "\t" << cvmGet(&H, 0, 1) << "\t" << cvmGet(&H, 0, 2) << endl;
  o << cvmGet(&H, 1, 0) << "\t" << cvmGet(&H, 1, 1) << "\t" << cvmGet(&H, 1, 2) << endl;
  o << cvmGet(&H, 2, 0) << "\t" << cvmGet(&H, 2, 1) << "\t" << cvmGet(&H, 2, 2) << endl;

  return o;
}

void homography06::transform_point(const int u, const int v, int & up, int & vp)
{
  float inv_k = 1.f / (cvmGet(2, 0) * u + cvmGet(2, 1) * v + cvmGet(2, 2));
  up = int(inv_k * (cvmGet(0, 0) * u + cvmGet(0, 1) * v + cvmGet(0, 2)) + 0.5);
  vp = int(inv_k * (cvmGet(1, 0) * u + cvmGet(1, 1) * v + cvmGet(1, 2)) + 0.5);
}

void homography06::transform_point(float u, float v, float & up, float & vp)
{
  float inv_k = 1.f / (cvmGet(2, 0) * u + cvmGet(2, 1) * v + cvmGet(2, 2));
  up = float(inv_k * (cvmGet(0, 0) * u + cvmGet(0, 1) * v + cvmGet(0, 2)) + 0.5);
  vp = float(inv_k * (cvmGet(1, 0) * u + cvmGet(1, 1) * v + cvmGet(1, 2)) + 0.5);
}

void homography06::transform_point(double u, double v, double & up, double & vp)
{
  double inv_k = 1. / (cvmGet(2, 0) * u + cvmGet(2, 1) * v + cvmGet(2, 2));
  up = double(inv_k * (cvmGet(0, 0) * u + cvmGet(0, 1) * v + cvmGet(0, 2)) + 0.5);
  vp = double(inv_k * (cvmGet(1, 0) * u + cvmGet(1, 1) * v + cvmGet(1, 2)) + 0.5);
}
