/*
 * huffmancodec_opencl_cpu.h
 *
 *  Created on: Sep 17, 2015
 *      Author: pouryas
 */

#ifndef HUFFMANCODEC_OPENCL_CPU_H_
#define HUFFMANCODEC_OPENCL_CPU_H_

#ifdef __ECLIPSE__
	#define kernel
	#define global
	#define __kernel
	#define __global
#endif

#include "bit_io.h"

void encode(/* __global */ u8* in_data, u32 size_in_data, /* __global */ u8* out_data, /* __global */ u32* size_out_data, u8 fetch_size_only);
void decode(/* __global */ u8* in_data, u32 size_in_data, /* __global */ u8* out_data, /* __global */ u32* size_out_data, u8 fetch_size_only);

#endif /* HUFFMANCODEC_OPENCL_CPU_H_ */
