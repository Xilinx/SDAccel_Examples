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
#include "assert.h"
#include "sw.h"
#include <ap_int.h>
#include <stdio.h>
#include <string.h>
typedef ap_uint<2> uint2_t;
typedef ap_uint<1> uint1_t;

void simpleSW(uint2_t refSeq[MAXCOL],
              uint2_t readSeq[MAXROW],
              short *maxr,
              short *maxc,
              short *maxv) {
#pragma HLS inline region off
    *maxv = MINVAL;
    int row, col;
    short mat[MAXROW][MAXCOL];
    for (col = 0; col < MAXCOL; col++) {
        short d = refSeq[col];
        for (row = 0; row < MAXROW; ++row) {
            short n, nw, w;
            if (row == 0) {
                n = 0;
            } else {
                n = mat[row - 1][col];
            }
            if (col == 0) {
                w = 0;
            } else {
                w = mat[row][col - 1];
            }

            if (row > 0 && col > 0) {
                nw = mat[row - 1][col - 1];
            } else {
                nw = 0;
            }

            short q = readSeq[row];
            short max = 0;
            short match = (d == q) ? MATCH : MISS_MATCH;
            short t1 = (nw + match > max) ? nw + match : max;
            short t2 = (n + GAP > w + GAP) ? n + GAP : w + GAP;
            max = t1 > t2 ? t1 : t2;
            mat[row][col] = max;
            if (max > *maxv) {
                *maxv = max;
                *maxr = row;
                *maxc = col;
            }
        }
    }
}

void sw(uint2_t d[MAXCOL],
        uint2_t q[MAXROW],
        short *maxr,
        short *maxc,
        short *maxv) {
#pragma HLS inline region off
    simpleSW(d, q, maxr, maxc, maxv);
}

template <int BUFFERSZ>
void intTo2bit(unsigned int *buffer, uint2_t *buffer2b) {
    int i, j;
#pragma HLS PIPELINE
    for (i = 0; i < BUFFERSZ; ++i) {
        for (j = 0; j < 16; ++j) {
            buffer2b[16 * i + j] = (buffer[i] & (3 << (2 * j))) >> (2 * j);
        }
    }
}

template <int FACTOR>
void swInt(unsigned int *readRefPacked, short *maxr, short *maxc, short *maxv) {
#pragma HLS function_instantiate variable = maxv
    uint2_t d2bit[MAXCOL];
    uint2_t q2bit[MAXROW];
#pragma HLS array partition variable = d2bit cyclic factor = FACTOR
#pragma HLS array partition variable = q2bit cyclic factor = FACTOR

    intTo2bit<MAXCOL / 16>((readRefPacked + MAXROW / 16), d2bit);
    intTo2bit<MAXROW / 16>(readRefPacked, q2bit);
    sw(d2bit, q2bit, maxr, maxc, maxv);
}

void swMaxScore(unsigned int readRefPacked[NUMPACKED][PACKEDSZ],
                short out[NUMPACKED][3]) {
    /*instantiate NUMPACKED PE*/
    for (int i = 0; i < NUMPACKED; ++i) {
       #pragma HLS UNROLL
        swInt<MAXPE>(readRefPacked[i], &out[i][0], &out[i][1], &out[i][2]);
    }
}
//#ifndef HLS_COMPILE
extern "C" {
//#endif
void opencl_sw_maxscore(unsigned int *input, unsigned int *output, int *size) {
#pragma HLS inline region off
#pragma HLS INTERFACE m_axi port = input offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = size offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = input bundle = control
#pragma HLS INTERFACE s_axilite port = output bundle = control
#pragma HLS INTERFACE s_axilite port = size bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control
    unsigned int inbuf[PACKEDSZ * NUMPACKED];
    unsigned int outbuf[3 * NUMPACKED];
    unsigned int readRefPacked[NUMPACKED][PACKEDSZ];
    short out[NUMPACKED][3];
    int numIter;
#pragma HLS array partition variable = readRefPacked dim = 1
#pragma HLS array partition variable = out dim = 0
    numIter = *size;
    int loop = 0;
    for (loop = 0; loop < numIter; loop++) {
        /*read from device memory to BRAM*/
        memcpy(readRefPacked,
               (unsigned int *)(input + loop * PACKEDSZ * NUMPACKED),
               UINTSZ * PACKEDSZ * NUMPACKED);
        swMaxScore(readRefPacked, out);
        /*PE OUT to outbuf*/
        for (int i = 0; i < NUMPACKED; ++i) {
#pragma HLS PIPELINE
            outbuf[3 * i] = out[i][0];
            outbuf[3 * i + 1] = out[i][1];
            outbuf[3 * i + 2] = out[i][2];
        }
        /*outbuf to device memory*/
        memcpy((unsigned int *)(output + 3 * NUMPACKED * loop),
               outbuf,
               sizeof(unsigned int) * 3 * NUMPACKED);
    }
    return;
}
}
