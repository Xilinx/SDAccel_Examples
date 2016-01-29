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

#include "base.h"

void encode(/* __global */ uchar* in_data, uint size_in_data, /* __global */ uchar* out_data, /* __global */ uint* size_out_data, uchar fetch_size_only);
void decode(/* __global */ uchar* in_data, uint size_in_data, /* __global */ uchar* out_data, /* __global */ uint* size_out_data, uchar fetch_size_only);

#endif /* HUFFMANCODEC_OPENCL_CPU_H_ */
