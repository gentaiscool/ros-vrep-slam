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

#include <zlib.h>
#include "mcv.h"
#include "fern_based_point_classifier.h"

fern_based_point_classifier::fern_based_point_classifier(char * filename)
{
  ifstream f(filename);

  if (!f.is_open()) {
    cerr << "fern_based_point_classifier(char * filename): error reading file " << filename << "." << endl;
    correctly_read = false;
    return;
  }

  load(f);

  f.close();
}

fern_based_point_classifier::fern_based_point_classifier(ifstream & f)
{
  load(f);
}

fern_based_point_classifier::fern_based_point_classifier(int number_of_classes,
                                                         int number_of_ferns, int number_of_tests_per_fern,
                                                         int dx_min, int dx_max,
                                                         int dy_min, int dy_max,
                                                         int ds_min, int ds_max)
{
  this->number_of_classes = number_of_classes;

  Ferns = new ferns(number_of_ferns, number_of_tests_per_fern,
                    dx_min, dx_max, dy_min, dy_max, ds_min, ds_max);

  number_of_samples_for_class = new int[number_of_classes];

  int buffer_size = number_of_classes * Ferns->number_of_ferns * Ferns->number_of_leaves_per_fern;
  leaves_counters = new short[buffer_size];
  leaves_distributions = new float[buffer_size];
  step1 = number_of_classes;
  step2 = step1 * Ferns->number_of_leaves_per_fern;

  preallocated_distribution_for_a_keypoint = new float[number_of_classes];

  set_number_of_ferns_to_use(-1);
}

fern_based_point_classifier::~fern_based_point_classifier()
{
  delete Ferns;
  delete [] leaves_distributions;
  delete [] preallocated_distribution_for_a_keypoint;
  delete [] number_of_samples_for_class;
}

void fern_based_point_classifier::load(ifstream & f)
{
  f >> number_of_classes;

  Ferns = new ferns(f);

  if (!Ferns->correctly_read) {
    cerr << ">! [fern_based_point_classifier::load] Error while reading ferns." << endl;
    correctly_read = false;
    return;
  }

  number_of_samples_for_class = new int[number_of_classes];
  f.read((char *)number_of_samples_for_class, sizeof(int) * number_of_classes);

  int buffer_size = number_of_classes * Ferns->number_of_ferns * Ferns->number_of_leaves_per_fern;
  leaves_distributions = new float[buffer_size];
  leaves_counters = new short[buffer_size];

  cout << "> [fern_based_point_classifier::load] Reading compressed leaves distributions..." << flush;
  int size_of_compressed_buffer, read_buffer_size;
  f >> size_of_compressed_buffer >> read_buffer_size;
  Bytef * compressed_buffer = new Bytef[size_of_compressed_buffer];
  char c; do f.read(&c, 1); while (c != '.');
  f.read((char *)compressed_buffer, size_of_compressed_buffer);
  uLongf uncompressed_buffer_size = buffer_size * sizeof(short);
  (void)uncompress((Bytef*)leaves_counters, &uncompressed_buffer_size, compressed_buffer, size_of_compressed_buffer);
  delete [] compressed_buffer;
  cout << "uncompressed..."<<flush;

  step1 = number_of_classes;
  step2 = step1 * Ferns->number_of_leaves_per_fern;

  finalize_training();

  set_number_of_ferns_to_use(-1);

  preallocated_distribution_for_a_keypoint = new float[number_of_classes];

  correctly_read = true;
  cout << " done." << endl;
}

bool fern_based_point_classifier::save(char * filename)
{
  ofstream f(filename);

  if (!f.is_open()) {
    cerr << "> [fern_based_point_classifier::save] Error while saving file " << filename << "." << endl;

    return false;
  }

  bool result = save(f);

  f.close();

  return result;
}

bool fern_based_point_classifier::save(ofstream & f)
{
  f << number_of_classes << endl;

  Ferns->save(f);

  f.write((char *)number_of_samples_for_class, sizeof(int) * number_of_classes);

  int buffer_size = number_of_classes * Ferns->number_of_ferns * Ferns->number_of_leaves_per_fern;
  //  f.write((char *)leaves_counters, sizeof(short) * buffer_size);

  cout << "> [fern_based_point_classifier::save] Compressing leaves distributions..." << endl;
  Bytef * compressed_buffer = new Bytef[buffer_size * sizeof(short)];
  uLongf size_of_compressed_buffer = buffer_size * sizeof(short);
  int z_error = compress(compressed_buffer, &size_of_compressed_buffer, (Bytef *)leaves_counters, buffer_size * sizeof(short));
  cout << "> [fern_based_point_classifier::save] z_error = " << z_error << endl;
  cout << "> [fern_based_point_classifier::save] size of compressed buffer = " << size_of_compressed_buffer << endl;
  cout << "> [fern_based_point_classifier::save] Ok. Compression ratio = " << float(buffer_size * sizeof(short)) / size_of_compressed_buffer << "." << endl;
  f << size_of_compressed_buffer << " " << buffer_size << endl;
  char dot('.'); f.write(&dot, 1);
  f.write((char *)compressed_buffer, size_of_compressed_buffer);

  delete [] compressed_buffer;

  return true;
}

void fern_based_point_classifier::reset_leaves_distributions(int _prior_number)
{
  int buffer_size = number_of_classes * Ferns->number_of_ferns * Ferns->number_of_leaves_per_fern;

  prior_number = _prior_number;

  for(int i = 0; i < buffer_size; i++)
    leaves_counters[i] = short(prior_number);
  for(int i = 0; i < number_of_classes; i++)
    number_of_samples_for_class[i] = 0;
}

void fern_based_point_classifier::train(keypoint * keypoints, int number_of_keypoints,
                                        int number_of_octaves, int yape_radius,
                                        int number_of_generated_images,
					affine_image_generator06 * image_generator)
{
  fine_gaussian_pyramid * pyramid = new fine_gaussian_pyramid(yape_radius, Ferns->max_d, number_of_octaves);

  image_generator->enable_random_background();

  cout << endl;
  for(int i = 0; i < number_of_generated_images; i++) {
    cout << "  (Generating views " << number_of_generated_images - i << ")              \r" << flush;
    image_generator->generate_random_affine_image();
    pyramid->set_image(image_generator->generated_image);

    for(int j = 0; j < number_of_keypoints; j++) {
      keypoint * K = keypoints + j;
      float fr_gu, fr_gv;
      image_generator->affine_transformation(K->fr_u(), K->fr_v(), fr_gu, fr_gv);

      int gu = int( fine_gaussian_pyramid::convCoordf(fr_gu, 0, int(K->scale)) + 0.5 );
      int gv = int( fine_gaussian_pyramid::convCoordf(fr_gv, 0, int(K->scale)) + 0.5 );
      int level = 4 * int(K->scale) + ((yape_radius == 3) ? 1 : (yape_radius == 5) ? 2 : 3);

      int * leaves_index = Ferns->drop(pyramid, gu, gv, level);
      if (leaves_index != 0) {
        number_of_samples_for_class[K->class_index]++;
        for(int k = 0; k < Ferns->number_of_ferns; k++)
          leaves_counters[k * step2 + leaves_index[k] * step1 + K->class_index]++;
      }
    }
  }

  //delete pyramid;
}

void fern_based_point_classifier::finalize_training(void)
{

#pragma omp parallel for
  for(int i = 0; i < Ferns->number_of_ferns; i++) {
	  double * number_of_samples_for_this_leaf = new double[Ferns->number_of_leaves_per_fern];
	  memset(number_of_samples_for_this_leaf,0,sizeof(double)*Ferns->number_of_leaves_per_fern);

    double number_of_samples_for_this_fern = 0.;
    for(int j = 0; j < Ferns->number_of_leaves_per_fern; j++)
      for(int k = 0; k < number_of_classes; k++)
	number_of_samples_for_this_fern +=
	  double(leaves_counters[i * step2 + j * step1 + k]) / double(number_of_samples_for_class[k]);

    for(int j = 0; j < Ferns->number_of_leaves_per_fern; j++) {
      for(int k = 0; k < number_of_classes; k++) {
	number_of_samples_for_this_leaf[j] +=
	  double(leaves_counters[i * step2 + j * step1 + k]) / double(number_of_samples_for_class[k]);
      }
    }

    for(int k = 0; k < number_of_classes; k++) {
      double sum = 0.;
      for(int j = 0; j < Ferns->number_of_leaves_per_fern; j++)
	sum += double(leaves_counters[i * step2 + j * step1 + k]) / double(number_of_samples_for_class[k]);

      for(int j = 0; j < Ferns->number_of_leaves_per_fern; j++)
	leaves_distributions[i * step2 + j * step1 + k] =
	  float( log( double(leaves_counters[i * step2 + j * step1 + k]) / double(number_of_samples_for_class[k])
		      / sum
		      / (number_of_samples_for_this_leaf[j] / number_of_samples_for_this_fern) ) );
    }
    delete [] number_of_samples_for_this_leaf;
  }

}

float fern_based_point_classifier::test(keypoint * keypoints, int number_of_keypoints,
					int number_of_octaves, int yape_radius,
					int number_of_generated_images,
					affine_image_generator06 * image_generator,
					bool verbose)
{
  int * seen = new int[number_of_classes];
  int * recognized = new int[number_of_classes];

  for(int i = 0; i < number_of_classes; i++)
    seen[i] = recognized[i] = 0;

  fine_gaussian_pyramid * pyramid = new fine_gaussian_pyramid(yape_radius, Ferns->max_d, number_of_octaves);

  image_generator->enable_random_background();

  for(int i = 0; i < number_of_generated_images; i++) {
    cout << "   (Generating views " << number_of_generated_images - i << ")              \r" << flush;

    srand(i);
    image_generator->generate_random_affine_image();

    pyramid->set_image(image_generator->generated_image);

    for(int j = 0; j < number_of_keypoints; j++) {
      keypoint * K = keypoints + j;
      float fr_gu, fr_gv;

      image_generator->affine_transformation(K->fr_u(), K->fr_v(), fr_gu, fr_gv);

      int gu = int( fine_gaussian_pyramid::convCoordf(fr_gu, 0, int(K->scale)) + 0.5 );
      int gv = int( fine_gaussian_pyramid::convCoordf(fr_gv, 0, int(K->scale)) + 0.5 );
      int level = 4 * int(K->scale) + ((yape_radius == 3) ? 1 : (yape_radius == 5) ? 2 : 3);

      int guessed_class_index =
	(verbose) ? recognize_verbose(pyramid, gu, gv, level) : recognize(pyramid, gu, gv, level);

      if (verbose)
	cout << "Guess: " << guessed_class_index << ", True: " << K->class_index << endl;

      if (guessed_class_index >= 0) {
	seen[K->class_index]++;
	if (guessed_class_index == K->class_index)
	  recognized[K->class_index]++;
      }
    }
  }

  cout << "> [fern_based_point_classifier] " << number_of_generated_images << " generated images." << endl;
  cout << "> [fern_based_point_classifier] Results of test:" << endl;
  for(int i = 0; i < number_of_classes; i++)
    cout << "   - class " << i << " seen " << seen[i]
	 << " times, recognized " << recognized[i] << " times (" << (100. * recognized[i]) / seen[i] << "%)."
	 << " (scale = " << keypoints[i].scale << ")" << endl;

  float mean_recognition_rate = 0.;
  int n = 0;
  for(int i = 0; i < number_of_classes; i++)
    if (seen[i] != 0) {
      mean_recognition_rate += (100.0f * recognized[i]) / seen[i];
      n++;
    }
  mean_recognition_rate /= n;
  cout << "  - Mean recognition rate: " << mean_recognition_rate << "%" << endl;

  delete pyramid;
  delete [] seen;
  delete [] recognized;

  return mean_recognition_rate;
}

void fern_based_point_classifier::recognize(fine_gaussian_pyramid * pyramid,
					    keypoint * keypoints, int number_of_keypoints)
{
  for(int i = 0; i < number_of_keypoints; i++)
    recognize(pyramid, keypoints + i);
}

void fern_based_point_classifier::recognize(fine_gaussian_pyramid * pyramid,
					    keypoint * keypoints, int number_of_keypoints,
					    float * distributions)
{
  for(int i = 0; i < number_of_keypoints; i++)
    recognize(pyramid, keypoints + i, distributions + i * number_of_classes);
}

void fern_based_point_classifier::recognize(fine_gaussian_pyramid * pyramid, keypoint * K)
{
  recognize(pyramid, K, preallocated_distribution_for_a_keypoint);
}

float * fern_based_point_classifier::recognize_with_distribution(fine_gaussian_pyramid * pyramid, keypoint * K)
{
  recognize(pyramid, K, preallocated_distribution_for_a_keypoint);

  return preallocated_distribution_for_a_keypoint;
}

void fern_based_point_classifier::recognize(fine_gaussian_pyramid * pyramid, keypoint * K, float * distribution)
{
  for(int i = 0; i < number_of_classes; i++)
    distribution[i] = 0.;

  int * leaves_index = Ferns->drop(pyramid, int(K->u + 0.5), int(K->v + 0.5), pyramid->level_from_scale(K->scale) );
  if (leaves_index == 0) {
    K->class_index = -1;
    K->class_score = -100000.;
    return;
  }

  const int nb_ferns = get_number_of_ferns_to_use();
  for(int i = 0; i < nb_ferns; i++) {
    float * ld = leaves_distributions + i * step2 + leaves_index[i] * step1;
    float * distrib = distribution;
    for(int j = number_of_classes - 1; j >= 0; j--) {
      *distrib += *ld;
      distrib++;
      ld++;
    }
  }

  K->class_index = 0;
  K->class_score = distribution[0];
  for(int i = 0; i < number_of_classes; i++)
    if (distribution[i] > K->class_score) {
      K->class_index = i;
      K->class_score = distribution[i];
    }
}

int fern_based_point_classifier::recognize(fine_gaussian_pyramid * pyramid, int u, int v, int level)
{
  int * leaves_index = Ferns->drop(pyramid, u, v, level);

  if (leaves_index == 0) return -1;

  float * distribution = preallocated_distribution_for_a_keypoint;

  for(int i = 0; i < number_of_classes; i++)
    distribution[i] = 0.;

  const int nb_ferns = get_number_of_ferns_to_use();
  for(int i = 0; i < nb_ferns; i++) {
    float * ld = leaves_distributions + i * step2 + leaves_index[i] * step1;
    for(int j = 0; j < number_of_classes; j++)
      distribution[j] += ld[j];
  }

  int class_index = 0;
  float class_score = distribution[0];
  for(int i = 0; i < number_of_classes; i++)
    if (distribution[i] > class_score) {
      class_index = i;
      class_score = distribution[i];
    }

  return class_index;
}

int fern_based_point_classifier::recognize_verbose(fine_gaussian_pyramid * pyramid, int u, int v, int level)
{
  int * leaves_index = Ferns->drop(pyramid, u, v, level);

  if (leaves_index == 0) return -1;

  float * distribution = preallocated_distribution_for_a_keypoint;

  for(int i = 0; i < number_of_classes; i++)
    distribution[i] = 0.;

  const int nb_ferns = get_number_of_ferns_to_use();
  for(int i = 0; i < nb_ferns; i++) {
    float * ld = leaves_distributions + i * step2 + leaves_index[i] * step1;
    for(int j = 0; j < number_of_classes; j++)
      distribution[j] += ld[j];

    for(int j = 0; j < number_of_classes; j++)
      cout << distribution[j] << "\t";
    cout << endl;
  }

  int class_index = 0;
  float class_score = distribution[0];
  for(int i = 0; i < number_of_classes; i++)
    if (distribution[i] > class_score) {
      class_index = i;
      class_score = distribution[i];
    }

  return class_index;
}

void fern_based_point_classifier::set_number_of_ferns_to_use(int _number_of_ferns_to_use)
{
  number_of_ferns_to_use = _number_of_ferns_to_use;
}

int  fern_based_point_classifier::get_number_of_ferns_to_use(void)
{
  if (number_of_ferns_to_use < 1)
    return Ferns->number_of_ferns;
  else
    return min(Ferns->number_of_ferns, number_of_ferns_to_use);
}


