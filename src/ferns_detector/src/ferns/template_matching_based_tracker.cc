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
#include <fstream>
using namespace std;

#include "homography_estimator.h"

#include "template_matching_based_tracker.h"
#include "mcv.h"

template_matching_based_tracker::template_matching_based_tracker(void)
{
}

bool template_matching_based_tracker::load(const char * filename)
{

  ifstream f(filename);

  if (!f.good()) 
	  return false;

  cout << "Loading " << filename << "..." << endl;

  U0 = cvCreateMat(8, 1, CV_32F);
  u0 = U0->data.fl;
  for(int i = 0; i < 8; i++)
    f >> u0[i];
  f >> nx >> ny;
  m = new int[2 * nx * ny];
  for(int i = 0; i < nx * ny; i++)
    f >> m[2 * i] >> m[2 * i + 1];

  U = cvCreateMat(8, 1, CV_32F);
  u = U->data.fl;

  I0 = cvCreateMat(nx * ny, 1, CV_32F);
  i0 = I0->data.fl;

  for(int i = 0; i < nx * ny; i++)
    f >> i0[i];

  I1 = cvCreateMat(nx * ny, 1, CV_32F);
  i1 = I1->data.fl;
  DI = cvCreateMat(nx * ny, 1, CV_32F);
  DU = cvCreateMat(8, 1, CV_32F);
  du = DU->data.fl;

  f >> number_of_levels;

  As = new CvMat*[number_of_levels];
  for(int i = 0; i < number_of_levels; i++) {
    As[i] = cvCreateMat(8, nx * ny, CV_32F);
    for(int j = 0; j < 8; j++)
      for(int k = 0; k < nx * ny; k++) {
	float v;
	f >> v;
	cvmSet(As[i], j, k, v);
      }
  }

  if (!f.good()) 
	  return false;

  cout << "Done." << endl;
  return true;
}

void template_matching_based_tracker::save(const char * filename)
{
  ofstream f(filename);

  for(int i = 0; i < 8; i++)
    f << u0[i] << " ";
  f << endl;
  f << nx << " " << ny << endl;
  for(int i = 0; i < nx * ny; i++)
    f << m[2 * i] << " " << m[2 * i + 1] << endl;
  for(int i = 0; i < nx * ny; i++)
    f << i0[i] << " ";
  f << endl;
  f << number_of_levels << endl;
  for(int i = 0; i < number_of_levels; i++) {
    for(int j = 0; j < 8; j++) {
      for(int k = 0; k < nx * ny; k++)
	f << cvmGet(As[i], j, k) << " ";
      f << endl;
    }
  }
  f.close();
}

void template_matching_based_tracker::move(int x, int y, float & x2, float & y2, int amp)
{
  int d = rand() % amp;
  float a = float(rand() % 720) * 3.14159 * 2.0 / 720;

  x2 = x + d * cosf(a);
  y2 = y + d * sinf(a);
}

bool template_matching_based_tracker::normalize(CvMat * V)
{
  float sum = 0.0, sum2 = 0.0;
  float * v = V->data.fl;

  for(int i = 0; i < V->rows; i++) {
    sum += v[i];
    sum2 += v[i] * v[i];
  }

  // Not enough contrast,  better not put this sample into the training set:
  if (sum < (V->rows * 10))
    return false;

  float mean = sum / V->rows;
  float inv_sigma = 1.0 / sqrt(sum2 / V->rows - mean * mean);

  // Not enough contrast,  better not put this sample into the training set:
  if (!finite(inv_sigma))
    return false;

  for(int i = 0; i < V->rows; i++)
    v[i] = inv_sigma * (v[i] - mean);

  return true;
}

void template_matching_based_tracker::add_noise(CvMat * V)
{
  float * v = V->data.fl;

  float gamma = 0.5 + (3 - 0.7) * float(rand()) / RAND_MAX;
  for(int i = 0; i < V->rows; i++) {
    v[i] = pow(v[i], gamma) + rand() % 10 - 5;
    if (v[i] < 0) v[i] = 0;
    if (v[i] > 255) v[i] = 255;
  }
}

IplImage * template_matching_based_tracker::compute_gradient(IplImage * image)
{
  IplImage * dx = cvCreateImage(cvSize(image->width, image->height),
				IPL_DEPTH_16S, 1);
  IplImage * dy = cvCreateImage(cvSize(image->width, image->height),
				IPL_DEPTH_16S, 1);
  IplImage * result = cvCreateImage(cvSize(image->width, image->height),
				    IPL_DEPTH_16S, 1);
  cvSobel(image, dx, 1, 0, 3);
  cvSobel(image, dy, 0, 1, 3);
  cvMul(dx, dx, dx);
  cvMul(dy, dy, dy);
  cvAdd(dx, dy, result);

  cvReleaseImage(&dx);
  cvReleaseImage(&dy);

  return result;
}

void template_matching_based_tracker::get_local_maximum(IplImage * G,
							int xc, int yc, int w, int h,
							int & xm, int & ym)
{
  int max = -1;
  for(int v = yc - h / 2; v <= yc + h / 2; v++) {
    short * row = mcvRow(G, v, short);
    for(int u = xc - w / 2; u <= xc + w / 2; u++)
      if (row[u] > max) {
	max = row[u];
	xm = u;
	ym = v;
      }
  }
}

void template_matching_based_tracker::find_2d_points(IplImage * image, int bx, int by)
{
  IplImage * gradient = compute_gradient(image);

  const float stepx = float(u0[2] - u0[0] - 2 * bx) / (nx - 1);
  const float stepy = float(u0[5] - u0[1] - 2 * by) / (ny - 1);
  for(int j = 0; j < ny; j++)
    for(int i = 0; i < nx; i++)
      get_local_maximum(gradient,
			int(u0[0] + bx + i * stepx + 0.5),
			int(u0[1] + by + j * stepy + 0.5),
			int(stepx), int(stepy),
			m[2 * (j * nx + i)],
			m[2 * (j * nx + i) + 1]);

  cvReleaseImage(&gradient);
}

void template_matching_based_tracker::compute_As_matrices(IplImage * image, int max_motion, int Ns)
{
  As = new CvMat*[number_of_levels];

  CvMat * Y = cvCreateMat(8, Ns, CV_32F);
  CvMat * H = cvCreateMat(nx * ny, Ns, CV_32F);
  CvMat * HHt = cvCreateMat(nx * ny, nx * ny, CV_32F);
  CvMat * HHt_inv = cvCreateMat(nx * ny, nx * ny, CV_32F);
  CvMat * Ht_HHt_inv = cvCreateMat(Ns, nx * ny, CV_32F);

  homography06 ft;

  for(int level = 0; level < number_of_levels; level++) {

    int n = 0;
    while(n < Ns) {
      cout << "Level: " << level << " (" << n << "/" << Ns << " samples done)" << char(13) << flush;

      float u1[8];

      float k = exp(1. / (number_of_levels - 1) * log(5.0 / max_motion));
      float amp = pow(k, float(level)) * max_motion;

      for(int i = 0; i < 4; i++)
	move(u0[2 * i], u0[2 * i + 1], u1[2 * i], u1[2 * i + 1], amp);

      for(int i = 0; i < 8; i++)
	cvmSet(Y, i, n, u1[i] - u0[i]);

      he.estimate(&ft,
		  u0[0], u0[1], u1[0], u1[1],
		  u0[2], u0[3], u1[2], u1[3],
		  u0[4], u0[5], u1[4], u1[5],
		  u0[6], u0[7], u1[6], u1[7]);

      for(int i = 0; i < nx * ny; i++) {
	int x1, y1;

	ft.transform_point(m[2 * i], m[2 * i + 1], x1, y1);
	i1[i] = mcvRow(image, y1, unsigned char)[x1];
      }
      add_noise(I1);
      bool ok = normalize(I1);
      if (ok) {
	for(int i = 0; i < nx * ny; i++)
	  cvmSet(H, i, n, i1[i] - i0[i]);
	n++;
      }
    }

    cout << "Level: " << level << "                                        " << endl;
    cout << " - " << n << " training samples generated." << endl;

    As[level] = cvCreateMat(8, nx * ny, CV_32F);

    cout << " - computing HHt..." << flush;
    cvGEMM(H, H, 1.0, 0, 0.0, HHt, CV_GEMM_B_T);
    cout << "done." << endl;

    cout << " - inverting HHt..." << flush;
    if (cvInvert(HHt, HHt_inv, CV_SVD_SYM) == 0) {
      cerr << "> In template_matching_based_tracker::compute_As_matrices :" << endl;
      cerr << " Can't compute HHt matrix inverse!" << endl;
      cerr << " damn!" << endl;
      exit(-1);
    }
    cout << "done." << endl;

    cout << " - computing H(HHt)^-1..." << flush;
    cvGEMM(H, HHt_inv, 1.0, 0, 0.0, Ht_HHt_inv, CV_GEMM_A_T);
    cout << "done." << endl;
    
    cout << " - computing YH(HHt)^-1..." << flush;
    cvMatMul(Y, Ht_HHt_inv, As[level]);
    cout << "done." << endl;
  }

  cvReleaseMat(&Y);
  cvReleaseMat(&H);
  cvReleaseMat(&HHt);
  cvReleaseMat(&HHt_inv);
  cvReleaseMat(&Ht_HHt_inv);
}

void template_matching_based_tracker::learn(IplImage * image,
					    int number_of_levels, int max_motion, int nx, int ny,
					    int xUL, int yUL,
					    int xBR, int yBR,
					    int bx, int by,
					    int Ns)
{
  this->number_of_levels = number_of_levels;
  this->nx = nx;
  this->ny = ny;

  m = new int[2 * nx * ny];
  U0 = cvCreateMat(8, 1, CV_32F);
  u0 = U0->data.fl;
  u0[0] = xUL; u0[1] = yUL;
  u0[2] = xBR; u0[3] = yUL;
  u0[4] = xBR; u0[5] = yBR;
  u0[6] = xUL; u0[7] = yBR;

  find_2d_points(image, bx, by);

  U = cvCreateMat(8, 1, CV_32F);
  u = U->data.fl;

  I0 = cvCreateMat(nx * ny, 1, CV_32F);
  i0 = I0->data.fl;

  for(int i = 0; i < nx * ny; i++)
    i0[i] = mcvRow(image, m[2 * i + 1], unsigned char)[ m[2 * i] ];
  bool ok = normalize(I0);
  if (!ok) {
    cerr << "> in template_matching_based_tracker::learn :" << endl;
    cerr << "> Template matching: image has not enough contrast." << endl;
    return ;
  }

  I1 = cvCreateMat(nx * ny, 1, CV_32F);
  i1 = I1->data.fl;
  DI = cvCreateMat(nx * ny, 1, CV_32F);
  DU = cvCreateMat(8, 1, CV_32F);
  du = DU->data.fl;

  compute_As_matrices(image, max_motion, Ns);
}

void template_matching_based_tracker::initialize(void)
{
  cvCopy(U0, U);

  // Set f to Id:
  he.estimate(&f,
	      u0[0], u0[1], u[0], u[1],
	      u0[2], u0[3], u[2], u[3],
	      u0[4], u0[5], u[4], u[5],
	      u0[6], u0[7], u[6], u[7]);
}

void template_matching_based_tracker::initialize(int x0, int y0,
						 int x1, int y1,
						 int x2, int y2,
						 int x3, int y3)
{
  u[0] = x0;  u[1] = y0;
  u[2] = x1;  u[3] = y1;
  u[4] = x2;  u[5] = y2;
  u[6] = x3;  u[7] = y3;

  he.estimate(&f,
	      u0[0], u0[1], u[0], u[1],
	      u0[2], u0[3], u[2], u[3],
	      u0[4], u0[5], u[4], u[5],
	      u0[6], u0[7], u[6], u[7]);
}

// void homography_from_4pt(const float *x, const float *y, const float *z, const float *w, float cgret[8])
// {
//         double t1 = x[0];
//         double t2 = z[0];
//         double t4 = y[1];
//         double t5 = t1 * t2 * t4;
//         double t6 = w[1];
//         double t7 = t1 * t6;
//         double t8 = t2 * t7;
//         double t9 = z[1];
//         double t10 = t1 * t9;
//         double t11 = y[0];
//         double t14 = x[1];
//         double t15 = w[0];
//         double t16 = t14 * t15;
//         double t18 = t16 * t11;
//         double t20 = t15 * t11 * t9;
//         double t21 = t15 * t4;
//         double t24 = t15 * t9;
//         double t25 = t2 * t4;
//         double t26 = t6 * t2;
//         double t27 = t6 * t11;
//         double t28 = t9 * t11;
//         double t30 = 0.1e1 / (-t24 + t21 - t25 + t26 - t27 + t28);
//         double t32 = t1 * t15;
//         double t35 = t14 * t11;
//         double t41 = t4 * t1;
//         double t42 = t6 * t41;
//         double t43 = t14 * t2;
//         double t46 = t16 * t9;
//         double t48 = t14 * t9 * t11;
//         double t51 = t4 * t6 * t2;
//         double t55 = t6 * t14;
//         cgret[0] = -(-t5 + t8 + t10 * t11 - t11 * t7 - t16 * t2 + t18 - t20 + t21 * t2) * t30;
//         cgret[1] = (t5 - t8 - t32 * t4 + t32 * t9 + t18 - t2 * t35 + t27 * t2 - t20) * t30;
//         cgret[2] = t1;
//         cgret[3] = (-t9 * t7 + t42 + t43 * t4 - t16 * t4 + t46 - t48 + t27 * t9 - t51) * t30;
//         cgret[4] = (-t42 + t41 * t9 - t55 * t2 + t46 - t48 + t55 * t11 + t51 - t21 * t9) * t30;
//         cgret[5] = t14;
//         cgret[6] = (-t10 + t41 + t43 - t35 + t24 - t21 - t26 + t27) * t30;
//         cgret[7] = (-t7 + t10 + t16 - t43 + t27 - t28 - t21 + t25) * t30;
//         //cgret[8] = 1;
// 	}

bool template_matching_based_tracker::track(IplImage * input_frame)
{
  homography06 fs;

  for(int level = 0; level < number_of_levels; level++) {
    for(int iter = 0; iter < 5; iter++) {
      for(int i = 0; i < nx * ny; i++) {
	int x1, y1;

	f.transform_point(m[2 * i], m[2 * i + 1], x1, y1);
	if (x1 < 0 || y1 < 0 || x1 >= input_frame->width || y1 >= input_frame->height)
	  return false;

	i1[i] = mcvRow(input_frame, y1, unsigned char)[x1];
      }
      normalize(I1);
      cvSub(I1, I0, DI);

      cvMatMul(As[level], DI, DU);
      he.estimate(&fs,
		  u0[0],  u0[1],  u0[0] - du[0], u0[1] - du[1],
		  u0[2],  u0[3],  u0[2] - du[2], u0[3] - du[3],
		  u0[4],  u0[5],  u0[4] - du[4], u0[5] - du[5],
		  u0[6],  u0[7],  u0[6] - du[6], u0[7] - du[7]);

      cvMatMul(&f, &fs, &f);

      float norm = 0;
      for(int i = 0; i < 9; i++) norm += f.data.fl[i] * f.data.fl[i];
      norm = sqrtf(norm);
      for(int i = 0; i < 9; i++) f.data.fl[i] /= norm;
    }
  }

  f.transform_point(u0[0], u0[1], u[0], u[1]);
  f.transform_point(u0[2], u0[3], u[2], u[3]);
  f.transform_point(u0[4], u0[5], u[4], u[5]);
  f.transform_point(u0[6], u0[7], u[6], u[7]);

  return true;
}
