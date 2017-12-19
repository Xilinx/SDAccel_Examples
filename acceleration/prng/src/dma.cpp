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

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "prng.h"
#include "dma.h"

//______________________________________________________________________________
void initQ (data_t *Q, data_t* din, int j) {

	L_copy:  for (int i=0;i<CMWC_CYCLE;i++)
#pragma HLS pipeline
					 Q[i] = din[j*CMWC_CYCLE+i];
}

//______________________________________________________________________________
void dma (dout_t *mem_out, data_t *mem_in, int nofBlock) {

#pragma HLS INTERFACE m_axi port=mem_in   bundle=din  depth = CMWC_CYCLE   offset=slave
#pragma HLS INTERFACE m_axi port=mem_out  bundle=dout depth = maxNofSample offset=slave

#pragma HLS INTERFACE s_axilite port=return      bundle=control
#pragma HLS INTERFACE s_axilite port=mem_in     bundle=control
#pragma HLS INTERFACE s_axilite port=mem_out    bundle=control
#pragma HLS INTERFACE s_axilite port=nofBlock   bundle=control

	assert(0<nofBlock && nofBlock <= maxNofBlock);

	static randCMWC<CMWC_CYCLE, data_t> R0;
	static randCMWC<CMWC_CYCLE, data_t> R1;
	static randCMWC<CMWC_CYCLE, data_t> R2;
	static randCMWC<CMWC_CYCLE, data_t> R3;
	static randCMWC<CMWC_CYCLE, data_t> R4;
	static randCMWC<CMWC_CYCLE, data_t> R5;
	static randCMWC<CMWC_CYCLE, data_t> R6;
	static randCMWC<CMWC_CYCLE, data_t> R7;
	static randCMWC<CMWC_CYCLE, data_t> R8;
	static randCMWC<CMWC_CYCLE, data_t> R9;
	static randCMWC<CMWC_CYCLE, data_t> R10;
	static randCMWC<CMWC_CYCLE, data_t> R11;
	static randCMWC<CMWC_CYCLE, data_t> R12;
	static randCMWC<CMWC_CYCLE, data_t> R13;
	static randCMWC<CMWC_CYCLE, data_t> R14;
	static randCMWC<CMWC_CYCLE, data_t> R15;

	data_t Q0[CMWC_CYCLE];
	data_t Q1[CMWC_CYCLE];
	data_t Q2[CMWC_CYCLE];
	data_t Q3[CMWC_CYCLE];
	data_t Q4[CMWC_CYCLE];
	data_t Q5[CMWC_CYCLE];
	data_t Q6[CMWC_CYCLE];
	data_t Q7[CMWC_CYCLE];
	data_t Q8[CMWC_CYCLE];
	data_t Q9[CMWC_CYCLE];
	data_t Q10[CMWC_CYCLE];
	data_t Q11[CMWC_CYCLE];
	data_t Q12[CMWC_CYCLE];
	data_t Q13[CMWC_CYCLE];
	data_t Q14[CMWC_CYCLE];
	data_t Q15[CMWC_CYCLE];

// theoretically these can happen concurrently
	initQ(Q0, mem_in, 0);  R0.init(Q0);
	initQ(Q1, mem_in, 1);  R1.init(Q1);
	initQ(Q2, mem_in, 2);  R2.init(Q2);
	initQ(Q3, mem_in, 3);  R3.init(Q3);
	initQ(Q4, mem_in, 4);  R4.init(Q4);
	initQ(Q5, mem_in, 5);  R5.init(Q5);
	initQ(Q6, mem_in, 6);  R6.init(Q6);
	initQ(Q7, mem_in, 7);  R7.init(Q7);
	initQ(Q8, mem_in, 8);  R8.init(Q8);
	initQ(Q9, mem_in, 9);  R9.init(Q9);
	initQ(Q10,mem_in, 10); R10.init(Q10);
	initQ(Q11,mem_in, 11); R11.init(Q11);
	initQ(Q12,mem_in, 12); R12.init(Q12);
	initQ(Q13,mem_in, 13); R13.init(Q13);
	initQ(Q14,mem_in, 14); R14.init(Q14);
	initQ(Q15,mem_in, 15); R15.init(Q15);

// generate sequence one at a time
	L_output: for (int i=0; i<nofBlock*maxSizeOfBlock; i++ ) {
#pragma HLS LOOP_TRIPCOUNT min=1 max = maxNofSample
#pragma HLS pipeline II=1

		data_t t0  = R0.makeOne( );
		data_t t1  = R1.makeOne( );
		data_t t2  = R2.makeOne( );
		data_t t3  = R3.makeOne( );
		data_t t4  = R4.makeOne( );
		data_t t5  = R5.makeOne( );
		data_t t6  = R6.makeOne( );
		data_t t7  = R7.makeOne( );
		data_t t8  = R8.makeOne( );
		data_t t9  = R9.makeOne( );
		data_t t10 = R10.makeOne( );
		data_t t11 = R11.makeOne( );
		data_t t12 = R12.makeOne( );
		data_t t13 = R13.makeOne( );
		data_t t14 = R14.makeOne( );
		data_t t15 = R15.makeOne( );

		mem_out[i] = ( t15,t14,t13,t12,t11,t10,t9,t8,t7,t6,t5,t4,t3,t2,t1,t0 );

	}

}
