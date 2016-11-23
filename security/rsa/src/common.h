/*******************************************************************************
Vendor: Xilinx
Associated Filename: common.h
Purpose: SDAccel rsa example
Revision History: December 6, 2015

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/


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

#ifdef RSA_2048
#define WORD_TYPE uint
#define NUM_WORDS		64
#define NUM_WORDS_MODULUS	32
#define MESSAGE_WORDS NUM_WORDS
#define CIPHER_WORDS NUM_WORDS
#define EXPONENT_BITS		1024

#endif 



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
