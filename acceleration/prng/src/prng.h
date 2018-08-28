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

#ifndef _PRNG_
#define _PRNG_

#include <cstddef>
#include <inttypes.h>

template <int CYCLE, typename T >
class randCMWC {

	T        Q[CYCLE];
	uint32_t c;       // must be limited with CMWC_C_MAX
	uint16_t i_cycle;

public:

//_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	void init ( T* Q_init ) {

	for (int idx=0; idx<CYCLE; idx++) {
#pragma HLS pipeline
		Q[idx] = Q_init[idx];  // set to rand() in Wikipedia source
    }

	i_cycle = CYCLE - 1;
	c = 362436;  // should be a variable setting, set to rand() in Wikipedia source
}


//_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
T makeOne ( void ) {

#pragma HLS inline

#pragma HLS RESOURCE   variable=Q core = RAM_T2P_BRAM
//#pragma HLS dependence variable=Q inter false

	const  uint64_t a = 18782;
	const  uint32_t m = 0xfffffffe;

	uint64_t t;
	uint32_t x;

	i_cycle = (i_cycle+1)% CYCLE;
	t = a * Q[i_cycle] + c;
	c = t >> 32;
	x = t + c;
	if (x < c) {
		x++;
		c++;
	}
	T tmp = m - x;
	Q[i_cycle] = tmp;

	return tmp;
}


//_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void make ( T* dout, const unsigned int nofSample ) {

	for (int idx=0; idx<nofSample; idx++) {
#pragma HLS pipeline
		dout[idx] = makeOne();
}

}

};


#endif
