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
#ifndef fine_gaussian_pyramid_h
#define fine_gaussian_pyramid_h

#include <cv.h>

/*
  Handling borders:

  outer_border
  >+------------<--------------------------------------------------+
  |                                                                |
  |                                                                |
  |<- - - -border_size - - ->¦                                     |
  |                          ¦                                     |
  |                          ¦                                     |
  |             inner_border ¦                                     |
  |            >+-----------<+------------------------+            |
  |             |                                     |            |
  |             |                                     |            |
  |             |<- - - -original_image->width- - - ->|            |
  |             |                                     |            |
  |             |                                     |            |
  |             |                 width               |            |
  |             |            +-------------+          |            |
  |             |            |             |          |            |
  |             |            |             |          |            |
  |             |            |             |          |            |
  ¦             ¦            ¦             ¦          ¦            ¦
  ¦                                                                ¦
  ¦<- total_width - - - - - - - - - - - - - - - - - - - - - - - - >¦


  full_images[k]->width  = total_width
  aztec_images[k]->width = total_width / (2 ^ octave)   octave >= 0

*/

class fine_gaussian_pyramid
{
 public:
  static const int yape_pyramid_3   =    3;
  static const int yape_pyramid_5   =    5;
  static const int yape_pyramid_7   =    7;
  static const int lowe_pyramid_357 =  357;
  static const int lowe_pyramid_333 =  333;
  static const int full_pyramid_357 = 1357;
  static const int full_pyramid_333 = 1333;

  fine_gaussian_pyramid(int type, int outer_border, int number_of_octaves, int inner_border = 0);
  fine_gaussian_pyramid(int type, IplImage * image, int outer_border, int number_of_octaves, int inner_border = 0);
  fine_gaussian_pyramid(int type, char * image_name, int outer_border, int number_of_octaves, int inner_border = 0);

  ~fine_gaussian_pyramid();
  
  bool load_image(char * image_name);
  bool load_image(char * image_name, int i);
  void set_image(const IplImage * image);

  int level_from_scale(float scale);
  //! Convert a coordinate from one level to another.
  /* \param x the coordinate to translate
   * \param from the level in which x is specified
   * \param to the level to translate the coordinate into
   * \param method controls whether to return minimum or maximum possible
   *  coordinate, when translating from high to low levels.
   *  0 : return the minimum possible value
   *  1 : return the maximum possible value
   *  2 : return the average possible value
   * \return the translate coordinate
   */
  static int convCoord(int x, int from, int to = 0, unsigned method = 0);

  //! Convert a subpixel coordinate from one level to another.
  static float convCoordf(float x, int from, int to = 0);


  int save(char * filename);

  unsigned char * full_image_row(int level, int y);
  int * full_image_row_int(int level, int y);

  int width, height, total_width, total_height, border_size, outer_border, inner_border;
  int number_of_octaves;
  IplImage * original_image;
  IplImage ** aztec_pyramid;
  IplImage ** full_images;

  //private:
  int type;

  void compute_from_level0(void);
  void alloc(int width, int height, int outer_border, int nb_levels, int inner_border);
  void free(void);

  void rawReduce(IplImage * original_image, IplImage * halfsize_image);
  void expand(IplImage * original_image, IplImage * dblesize_image);
  void expand(IplImage * original_image, IplImage * dblesize_image, int width, int height);
  void expand(IplImage * original_image, IplImage * final_image, int n);

  IplImage * intermediate_int_image;
  int widthStep_int;
  float * coeffs;
  bool * add_a_row, * add_a_col;
};

#endif
