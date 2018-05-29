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

#include "general.h"
#include "affine_transformation_range.h"

affine_transformation_range::affine_transformation_range(void)
{
  set_range_variation_for_theta(0.f, 2.f * 3.1416f);
  set_range_variation_for_phi(0.f, 3.1516f);
  independent_scaling(0.5, 1.5, 0.5, 1.5);
  //  constrained_scaling(0.7, 1.7, 0.9, 1.1);
}

affine_transformation_range::~affine_transformation_range(void)
{
}

void affine_transformation_range::load(ifstream & f)
{
  f >> min_theta >> max_theta;
  f >> min_phi >> max_phi;
  f >> scaling_method;
  f >> min_lambda1 >> max_lambda1;
  f >> min_lambda2 >> max_lambda2;

  if (scaling_method == 1) f >> min_l1_l2 >> max_l1_l2;

  cout << "> [affine_transformation_range::load] min_theta = " << min_theta << endl;
  cout << "> [affine_transformation_range::load] max_lambda2 = " << max_lambda2 << endl;

  if (scaling_method == 1) {
    cout << "> [affine_transformation_range::load] min_l1_l2 = " << min_l1_l2 << endl;
    cout << "> [affine_transformation_range::load] max_l1_l2 = " << max_l1_l2 << endl;
  }
}

void affine_transformation_range::load_in_degrees(ifstream & f)
{
  f >> min_theta >> max_theta;

  min_theta *= 3.14159 / 180.0;
  max_theta *= 3.14159 / 180.0;

  f >> min_phi >> max_phi;

  min_phi *= 3.14159 / 180.0;
  max_phi *= 3.14159 / 180.0;

  f >> scaling_method;
  f >> min_lambda1 >> max_lambda1;
  f >> min_lambda2 >> max_lambda2;

  if (scaling_method == 1) f >> min_l1_l2 >> max_l1_l2;
}

void affine_transformation_range::save(ofstream & f)
{
  f << min_theta << " " << max_theta << endl;
  f << min_phi << " " <<  max_phi << endl;
  f << scaling_method << endl;
  f << min_lambda1 << " " << max_lambda1 << endl;
  f << min_lambda2 << " " << max_lambda2 << endl;

  if (scaling_method == 1) f << min_l1_l2 << " " << max_l1_l2 << endl;
}

//! Global rotation. Default = [0 : 2Pi]
void affine_transformation_range::set_range_variation_for_theta(float p_min_theta, float p_max_theta){
  min_theta = p_min_theta;
  max_theta = p_max_theta;
}

//! Skew. Default = [0 : Pi]
void affine_transformation_range::set_range_variation_for_phi(float p_min_phi, float p_max_phi)
{
  min_phi = p_min_phi;
  max_phi = p_max_phi;
}

//! Default method. Between 0.5 : 1.5 for both
void affine_transformation_range::independent_scaling(float p_min_lambda1, float p_max_lambda1, float p_min_lambda2, float p_max_lambda2)
{
  scaling_method = 0;

  min_lambda1 = p_min_lambda1;
  max_lambda1 = p_max_lambda1;

  min_lambda2 = p_min_lambda2;
  max_lambda2 = p_max_lambda2;
}

//! Constrained scaling. Adds a constraint on the range of the product of l1 and l2.
void affine_transformation_range::constrained_scaling(float p_min_lambda1, float p_max_lambda1,
						      float p_min_lambda2, float p_max_lambda2,
						      float p_min_l1_l2,   float p_max_l1_l2)
{
  scaling_method = 1;

  min_lambda1 = p_min_lambda1;
  max_lambda1 = p_max_lambda1;

  min_lambda2 = p_min_lambda2;
  max_lambda2 = p_max_lambda2;

  min_l1_l2 = p_min_l1_l2;
  max_l1_l2 = p_max_l1_l2;
}


void affine_transformation_range::generate_random_parameters(float & theta, float & phi, 
							     float & lambda1, float & lambda2)
{
  theta = min_theta + rand_01() * (max_theta - min_theta);
  phi   = min_phi   + rand_01() * (max_phi - min_phi);

  if (scaling_method == 0) {
    lambda1 = min_lambda1 + rand_01() * (max_lambda1 - min_lambda1);
    lambda2 = min_lambda2 + rand_01() * (max_lambda2 - min_lambda2);
  } else
    do {
      lambda1 = min_lambda1 + rand_01() * (max_lambda1 - min_lambda1);
      lambda2 = min_lambda2 + rand_01() * (max_lambda2 - min_lambda2);
    } while (lambda1 * lambda2 < min_l1_l2 || lambda1 * lambda2 > max_l1_l2);
}
