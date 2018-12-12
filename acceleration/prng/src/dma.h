/**********
Copyright (c) 2018, Xilinx, Inc.
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

#ifndef H_DMA_
#define H_DMA_

#include <cstddef>
#include <inttypes.h>
#include <ap_fixed.h>
#include <ap_int.h>

typedef ap_uint<32>   data_t;

const int CMWC_CYCLE = 4096;
//const int maxSizeOfBlock = 16384;
const int maxSizeOfBlock = 1024;   // 32*1k = 1BRAM
//const int maxNofBlock    = 16384;  // 16k * 1k = 16M samples
const int maxNofBlock    = 262144;  // 256 * 1k = 256k samples = 1 GByte

//TRIPCOUNT identifiers
const int maxNofSample   = maxSizeOfBlock * maxNofBlock;
const int minNofSample   = 1;

// number of PRNG units
const int nofPRNG = 16;  // don't go beyond 16, to limit number of bits to 512
typedef   ap_uint<nofPRNG*32>  dout_t;

extern "C" {
	void dma (dout_t *mem_out, data_t *mem_in, int nofBlock);
}

#endif
