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

/*
 * Systolic implementation of smith-waterman
 */

#include <stdio.h>
#include <string.h>
#include "sw.h"
#include <ap_int.h>
#include "assert.h"

typedef ap_uint<2> uint2_t;
typedef ap_uint<1> uint1_t;

typedef struct _pe{
    short d;
    short p;
}pe;

void initPE(pe *pex){
#pragma HLS PIPELINE II=1
	for(int i = 0; i < MAXPE; i++){
		pex[i].d = 0;
		pex[i].p = 0;
	}
}

#ifdef _COMPUTE_FULL_MATRIX
short **localMat;
static short  colIter = 0;
#endif


void updatePE(pe *pex, uint2_t d, uint2_t q, short n, short nw, short w, short r, short c){
#pragma HLS PIPELINE II=1
    short max = 0;
    short match = (d == q) ? MATCH : MISS_MATCH;
    short x1 = nw+match;
    short t1 = (x1 > max) ? x1 : max;
    short x2 = w+GAP;
    short t2 = (x2 > t1 ) ? x2 : t1;
    short x3 = n+GAP;
    max = (x3 > t2) ? x3 : t2;
    pex->p = max;
    pex->d = n;
#ifdef _COMPUTE_FULL_MATRIX
    localMat[r][colIter*MAXPE + c] = max;
#endif

}


void executePE(short r,short c,pe *pex, pe*ppex, uint2_t *d, uint2_t *q){
#pragma HLS PIPELINE II=1
    short nw, w, n;

    if (r == 0){
        n = 0;
        nw = 0;
    }else{
        n = pex->p;
        nw = ppex->d;
    }
    w = ppex->p;
    uint2_t d1 = d[c];
    uint2_t q1 = q[r];
    updatePE(pex, d1, q1, n, nw, w, r, c);
}

void executeFirstPE(short r,short c,pe *p, uint2_t *d, uint2_t *q, short nw, short w){
#pragma HLS PIPELINE II=1
    short  n;
    if (r == 0){
        n = 0;
    }else{
        n = p->p;

    }
    uint2_t d1 = d[c];
    uint2_t q1 = q[r];
    updatePE(p, d1, q1, n, nw, w, r, c);
}

template <int FACTOR>
void swCoreB(uint2_t *d, uint2_t *q, short *maxr, short *maxc, short *maxv, short *iterB, pe *myPE, short stripe, short rows){
#pragma HLS inline
#pragma HLS array partition variable=d cyclic factor=FACTOR
	int i, loop;
    short w = 0; // Initial condition at the start of a row
    d+= stripe*MAXPE;
	initPE(myPE);
    for(loop = 0; loop < rows; ++loop){
    #pragma HLS PIPELINE II=1
        short rowmaxv = MINVAL;
        short rowmaxpe = 0;
        for(i = 0; i < MAXPE; i++){
        #pragma HLS inline region recursive
            if(i == 0){
                short nw = w;
                w = (stripe == 0) ? 0 : iterB[loop];
                executeFirstPE(loop,i,&myPE[i], d, q, nw, w);
            }else{
                executePE(loop,i,&myPE[i], &myPE[i-1], d, q);
            }
			if(i == MAXPE-1){
                iterB[loop] = myPE[i].p;
			}
            if (myPE[i].p > rowmaxv){
                rowmaxv = myPE[i].p;
                rowmaxpe = i;
            }
        }

        if (rowmaxv > *maxv){
            *maxv = rowmaxv;
            *maxc = rowmaxpe + stripe*MAXPE; // log2(MAXPE);
            *maxr = loop;
        }
    }
}

/*Only columns*/
void swSystolicBlocking(uint2_t d[MAXCOL], uint2_t q[MAXROW], short *maxr, short *maxc, short *maxv, short rows, short cols){
pe  myPE[MAXPE];
short iterB[MAXROW];
#pragma HLS inline 
#pragma HLS RESOURCE variable=iterB core=RAM_S2P_LUTRAM
#pragma HLS RESOURCE variable=q core=RAM_S2P_LUTRAM
	*maxc = MINVAL;
	*maxv = MINVAL;
	*maxr = MINVAL;
    short stripes = MAXCOL / MAXPE;
    assert(stripes <= (MAXCOL+MAXPE-1)/MAXPE);
    assert(rows <= MAXROW);
#pragma HLS array partition variable=myPE
	for(short stripe = 0; stripe < stripes; stripe = stripe + 1){
#ifdef _COMPUTE_FULL_MATRIX
		colIter = stripe;
#endif
        swCoreB<MAXPE>(d, q, maxr, maxc, maxv, iterB, myPE, stripe, rows);
	}

}


void simpleSW(uint2_t refSeq[MAXCOL], uint2_t readSeq[MAXROW], short *maxr, short *maxc, short *maxv){
#pragma HLS inline region off
	*maxv = MINVAL;
    int row, col;
    short mat[MAXROW][MAXCOL];
	for(col = 0; col < MAXCOL; col++){
		short d = refSeq[col];
		for(row = 0; row < MAXROW; ++row){
			short n, nw, w;
			 if (row == 0){
				 n = 0;
			 }else{
			     n = mat[row-1][col];
			 }
			 if(col == 0){
				 w = 0;
			 }else{
				 w = mat[row][col-1];
			 }

			 if(row > 0 && col > 0){
				 nw = mat[row-1][col-1];
			 }else{
				 nw = 0;
			 }

			 short q = readSeq[row];
			 short max = 0;
			 short match = (d == q) ? MATCH : MISS_MATCH;
			 short t1 = (nw + match > max) ? nw + match : max;
			 short t2 = (n + GAP > w + GAP) ? n + GAP : w + GAP;
			 max = t1 > t2 ? t1 : t2;
			 mat[row][col] = max;
			 if(max > *maxv){
				 *maxv = max;
				 *maxr = row;
				 *maxc = col;
			 }
		}
	}


}

void sw(uint2_t d[MAXCOL], uint2_t q[MAXROW], short *maxr, short *maxc, short *maxv){
#pragma HLS inline region off
	swSystolicBlocking(d, q, maxr, maxc, maxv, MAXROW, MAXCOL);
}

template <int BUFFERSZ>
void intTo2bit(unsigned int *buffer, uint2_t *buffer2b){
 int i, j;
#pragma HLS PIPELINE II=1
 for(i = 0; i < BUFFERSZ; ++i){
        for(j = 0; j < 16; ++j){
            buffer2b[16*i+j] = (buffer[i] & (3 << (2*j)))>>(2*j);
        }
    }
}

template <int FACTOR>
void swInt(unsigned int *readRefPacked, short *maxr, short *maxc, short *maxv){
#pragma HLS function_instantiate variable=maxv
    uint2_t d2bit[MAXCOL];
    uint2_t q2bit[MAXROW];
#pragma HLS array partition variable=d2bit,q2bit cyclic factor=FACTOR

    intTo2bit<MAXCOL/16>((readRefPacked + MAXROW/16), d2bit);
    intTo2bit<MAXROW/16>(readRefPacked, q2bit);
    sw(d2bit, q2bit, maxr, maxc, maxv);
}

void swMaxScore(unsigned int readRefPacked[NUMPACKED][PACKEDSZ], short out[NUMPACKED][3]){
	/*instantiate NUMPACKED PE*/
	for(int i = 0; i < NUMPACKED;++i){
	#pragma HLS UNROLL
		swInt<MAXPE>(readRefPacked[i], &out[i][0], &out[i][1], &out[i][2]);
	}
}
//#ifndef HLS_COMPILE
extern "C" {
//#endif
    void opencl_sw_maxscore(unsigned int *input, unsigned int  *output, int *size) {
#pragma HLS inline region off
#pragma HLS INTERFACE m_axi port=input offset=slave bundle=gmem 
#pragma HLS INTERFACE m_axi port=output offset=slave bundle=gmem 
#pragma HLS INTERFACE m_axi port=size offset=slave bundle=gmem 
#pragma HLS INTERFACE s_axilite port=input bundle=control
#pragma HLS INTERFACE s_axilite port=output bundle=control
#pragma HLS INTERFACE s_axilite port=size bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control
        unsigned int inbuf[PACKEDSZ*NUMPACKED];
        unsigned int outbuf[3*NUMPACKED];
        unsigned int readRefPacked[NUMPACKED][PACKEDSZ];
        short out[NUMPACKED][3];
        int numIter;
#pragma HLS array partition variable=readRefPacked  dim=1
#pragma HLS array partition variable=out dim=0
        numIter = *size;
        int loop = 0;
        for(loop = 0; loop < numIter; loop++){
            /*read from device memory to BRAM*/
            memcpy(readRefPacked, 
                (unsigned int *)(input + loop*PACKEDSZ*NUMPACKED),
                UINTSZ*PACKEDSZ*NUMPACKED);
            swMaxScore(readRefPacked, out);
            /*PE OUT to outbuf*/
            for(int i = 0; i < NUMPACKED; ++i){
            #pragma HLS PIPELINE
                outbuf[3*i] = out[i][0];
                outbuf[3*i+1] = out[i][1];
                outbuf[3*i+2] = out[i][2];
            }
            /*outbuf to device memory*/
            memcpy((unsigned int *)(output + 3*NUMPACKED*loop), 
                outbuf, sizeof(unsigned int)*3*NUMPACKED);
        }
        return;
    }
}
