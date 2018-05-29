/*
  Copyright 2007, 2008 Computer Vision Lab,
  Ecole Polytechnique Federale de Lausanne (EPFL), Switzerland.
  All rights reserved.

  Authors: Julien Pilet (http://cvlab.epfl.ch/~jpilet)

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
#ifndef CMPHOMO_H
#define CMPHOMO_H

void homography_transform(const float a[2], const float H[3][3], float r[2]);

/* computes the homography sending [0,0] , [0,1], [1,1] and [1,0]
 * to x,y,z and w.
 */
void homography_from_4pt(const float *x, const float *y, const float *z, const float *w, float cgret[8]);

/*
 * computes the homography sending a,b,c,d to x,y,z,w
 */
void homography_from_4corresp(
		const float *a, const float *b, const float *c, const float *d,
		const float *x, const float *y, const float *z, const float *w, float R[3][3]);

#endif
