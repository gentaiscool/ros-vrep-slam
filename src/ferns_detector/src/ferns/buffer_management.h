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
#ifndef buffer_management_h
#define buffer_management_h

// #include <emmintrin.h>
#include <zlib.h>

#include <iostream>
#include <fstream>
using namespace std;

#include <cv.h>

#define MANAGED_MEMORY_DEBUGGING 0

// The 6 following functions are defined using macros (see below):
/*
  void manage_buffer(void * buffer, int required_size, type);
  void delete_managed_buffer(void * buffer);

  void save_buffer_in_pakfile(ofstream & f, void * buffer, int size, type);
  void save_managed_buffer_in_pakfile(ofstream & f, void * buffer, type);
  bool load_managed_buffer_in_pakfile(ifstream & f, void * buffer, int & size, type);
*/

bool manage_image(IplImage ** image, int width, int height, int depth, int nChannels);
bool load_managed_image(char * filename, IplImage ** image, int code);
void free_managed_image(IplImage ** image);
void release_managed_image(IplImage ** image);

void save_image_in_pakfile(ofstream & f, IplImage * image);
void save_managed_image_in_pakfile(ofstream & f, IplImage * image);

bool load_managed_image_in_pakfile(ifstream & f, IplImage ** image);

char * aligned_and_managed_new(size_t size, size_t align_size);
void aligned_and_managed_delete(void * ptr);

////////////////////////////////////////////////////////////////////////////////////////////////////////

char * aligned_and_managed_new16b(size_t size);

// Macros for the functions defined above:

#define manage_buffer(buffer, required_size, type)			\
  if ((buffer) != 0 && ( *(int*)(((char*)(buffer)) - sizeof(void*) - sizeof(int)) < (required_size)) ) { \
    aligned_and_managed_delete(buffer);					\
    (buffer) = 0;							\
  }									\
  if ((buffer) == 0) {							\
    int size = (required_size) * sizeof(type);				\
    buffer = (type*)(aligned_and_managed_new16b(size));			\
    if (MANAGED_MEMORY_DEBUGGING)					\
      cout << endl							\
	   << "[MANAGED_MEMORY_DEBUGGING: allocating "			\
	   << (required_size) << " x " << sizeof(type)			\
	   << " bytes at \t" << (void*)(buffer) << "]" << endl;		\
    if ((buffer) == 0)							\
      cerr << ">! [buffer_management] MACRO manage_buffer: can't alloc " << size << " bytes." << endl; \
    else								\
      *(int*)(((char*)buffer) - sizeof(void*) - sizeof(int)) = required_size; \
  }

#define delete_managed_buffer(buffer) aligned_and_managed_delete(buffer)


extern Bytef * __managed_compressed_buffer;

#define save_buffer_in_pakfile(f, buffer, size, type)			\
  if ((size) < (1L << 10)) {						\
    f << "0 " << size << endl;						\
    char dot('.'); f.write(&dot, 1);					\
    f.write((char *)buffer, (size) * sizeof(type));			\
  } else {								\
    int max_required_size = (size) * sizeof(type);			\
    manage_buffer(__managed_compressed_buffer, max_required_size, Bytef); \
    uLongf size_of_compressed_buffer = max_required_size;		\
    int z_error = compress(__managed_compressed_buffer, &size_of_compressed_buffer, \
			   (Bytef *)buffer, max_required_size);		\
    cout << "> save_buffer_in_pakfile: (zlib error = " << z_error;	\
    cout << "). Compression ratio = "					\
         << float(max_required_size) / size_of_compressed_buffer << "." << endl; \
    f << "1 " << size_of_compressed_buffer << " " << size << endl;	\
    char dot('.'); f.write(&dot, 1);					\
    f.write((char *)__managed_compressed_buffer, size_of_compressed_buffer); \
  }


#define save_managed_buffer_in_pakfile(f, buffer, type) save_buffer_in_pakfile(f, buffer, buffer[-2], type)

#define load_managed_buffer_in_pakfile(f, buffer, size, type)	\
  {                                                             \
    bool compressed;                                            \
    								\
    f >> compressed;							\
    if (!compressed) {							\
      f >> size;							\
      manage_buffer(buffer, size, type);				\
      f.read((char *)buffer, size * sizeof(type));			\
    } else {								\
      cout << "> [buffer_management] Reading compressed buffer..." << flush; \
      int size_of_compressed_buffer;					\
      f >> size_of_compressed_buffer >> size;				\
      char c; do f.read(&c, 1); while (c != '.');			\
      manage_buffer(__managed_compressed_buffer, size_of_compressed_buffer, Bytef); \
      f.read((char *)__managed_compressed_buffer, size_of_compressed_buffer); \
      uLongf uncompressed_buffer_size = size * sizeof(type);		\
      manage_buffer(buffer, size, type);				\
      int z_error = uncompress((Bytef*)buffer, &uncompressed_buffer_size, __managed_compressed_buffer, size_of_compressed_buffer); \
      cout << " (zlib error = " << z_error << ")" << endl;		\
    }									\
  }

#endif //buffer_management_h
