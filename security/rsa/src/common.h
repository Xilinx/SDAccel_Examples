/**********
Copyright (c) 2016, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include "sys_info.h"

#include <CL/cl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#ifdef RSA_1024
#define WORD_TYPE uint
#define NUM_WORDS		32
#define NUM_WORDS_MODULUS	16
#define MESSAGE_WORDS NUM_WORDS
#define CIPHER_WORDS NUM_WORDS
#define EXPONENT_BITS		512

#endif // RSA_1024



#define CPU_SYNC 	{ __asm__ __volatile__ ("xorl %eax, %eax\n\t"\
						"cpuid");}

//#define CPU_GET_CYCLES(low)			{low = my_rdtsc();}

//#define TABLE_SIZE		32
//#define WINDOW_SIZE		5		//for constant window this has to divide the BITS_PER_WORD value
//#define WINDOW_MASK		0x1f

#define CL_CHECK(_expr)                                                         \
   do {                                                                         \
     cl_int _err = _expr;                                                       \
     if (_err == CL_SUCCESS)                                                    \
       break;                                                                   \
     fprintf(stderr, "OpenCL Error: '%s' returned %d!\n", #_expr, (int)_err);   \
     abort();                                                                   \
   } while (0)

#define CL_CHECK_ERR(_expr)                                                     \
   ({                                                                           \
     cl_int _err = CL_INVALID_VALUE;                                            \
     typeof(_expr) _ret = _expr;                                                \
     if (_err != CL_SUCCESS) {                                                  \
       fprintf(stderr, "OpenCL Error: '%s' returned %d!\n", #_expr, (int)_err); \
       abort();                                                                 \
     }                                                                          \
     _ret;                                                                      \
   })

uint64_t my_rdtsc();

void pfn_notify(const char *errinfo, const void *private_info, size_t cb, void *user_data);

void print_big_number(WORD_TYPE *n, int num_words, const char *name);

const char * convertToString(const char *filename); //read in .cl file and store in a C string

int read_data(WORD_TYPE *c, const char *filename);

int output_data_to_file(const char *filename, WORD_TYPE *message);

void reverse_array(unsigned char* dst, unsigned char* src, int length);

void print_usage(char *filename);

uint mod_mul(uint x, uint y, uint m);

uint mod_add(uint x, uint y, uint m);

uint mod_subtract(uint x, uint y, uint m);

#endif // __COMMON_H__

