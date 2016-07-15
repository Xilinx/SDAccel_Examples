/*******************************************************************************
Vendor: Xilinx
Associated Filename: huffmancodec_optimized_cpuonly.h
Purpose: SDAccel huffman codec example
Revision History: January 29, 2016

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

#ifndef HUFFMANCODEC_OPENCL_CPU_H_
#define HUFFMANCODEC_OPENCL_CPU_H_

#include "huffmancodec_naive.h"

#ifdef __ECLIPSE__
	#define kernel
	#define global
	#define __kernel
	#define __global
#endif



void encode(/* __global */ u8* in_data, u32 size_in_data, /* __global */ u8* out_data, /* __global */ u32* size_out_data, u8 fetch_size_only);
void decode(/* __global */ u8* in_data, u32 size_in_data, /* __global */ u8* out_data, /* __global */ u32* size_out_data, u8 fetch_size_only);

namespace sda {


class HuffmanOptimizedCPUOnly : public ICodec {
public:
	HuffmanOptimizedCPUOnly() {
	}

	virtual ~HuffmanOptimizedCPUOnly() {
	}

	/*!
	 * Encodes canonical huffman
	 */
	int enc(const vector<u8>& in_data, vector<u8>& out_data) {
		u32 size_out_data = 0;
		encode(const_cast<u8 *>(&in_data[0]), in_data.size(), &out_data[0], &size_out_data, true);

		//resize output array
		out_data.resize(size_out_data);
		encode(const_cast<u8 *>(&in_data[0]), in_data.size(), &out_data[0], &size_out_data, false);

		return (int)size_out_data;
	}

	/*!
	 * Decodes canonical huffman
	 */
	int dec(const vector<u8>& in_data, vector<u8>& out_data) {
		u32 size_out_data = 0;
		decode(const_cast<u8*>(&in_data[0]), in_data.size(), &out_data[0], &size_out_data, true);

		//resize output array
		out_data.resize(size_out_data);
		decode(const_cast<u8*>(&in_data[0]), in_data.size(), &out_data[0], &size_out_data, false);

		return (int)size_out_data;
	}

};



}

#endif /* HUFFMANCODEC_OPENCL_CPU_H_ */
