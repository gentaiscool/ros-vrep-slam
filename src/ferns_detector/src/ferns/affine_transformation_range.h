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
#ifndef affine_transformation_range_h
#define affine_transformation_range_h

#include <fstream>
using namespace std;

class affine_transformation_range
{
 public:
  affine_transformation_range(void);
  ~affine_transformation_range(void);

  void load(ifstream & f);
  void load_in_degrees(ifstream & f);
  void save(ofstream & f);

  //! Global rotation. Default = [0 : 2Pi]
  void set_range_variation_for_theta(float min_theta, float max_theta);
  //! Skew. Default = [0 : Pi]
  void set_range_variation_for_phi(float min_phi, float max_phi);
  //! Default method. Between 0.5 : 1.5 for both
  void independent_scaling(float min_lambda1, float max_lambda1, float min_lambda2, float max_lambda2);
  //! Constrained scaling. Adds a constraint on the range of the product of l1 and l2.
  void constrained_scaling(float min_lambda1, float max_lambda1,
			   float min_lambda2, float max_lambda2,
			   float min_l1_l2, float max_l1_l2);

  void generate_random_parameters(float & theta, float & phi, float & lambda1, float & lambda2);

  //  private:
  float min_theta, max_theta;
  float min_phi, max_phi;
  int scaling_method;
  float min_lambda1, max_lambda1;
  float min_lambda2, max_lambda2;
  float min_l1_l2, max_l1_l2;     // for scaling method = 1 only (constrained scaling)
};

#endif
