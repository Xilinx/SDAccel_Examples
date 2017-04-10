/**********
Copyright (c) 2017, Xilinx, Inc.
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
