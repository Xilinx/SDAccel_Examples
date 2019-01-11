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
  Please see host.cpp

  NOTE: These kernels are not optimized and will not perform well in real world
  applications.
*/

#define MAX_DIM 64

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void mscale(global int *inout, const int scale, const int dim0, const int dim1) {
    mscale: for (int i = 0; i < dim0 * dim1; ++i) inout[i] = inout[i] * scale;
}

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void madd(global int *c, global const int *a, global const int *b,
          const int dim0, const int dim1) {
    int matA[MAX_DIM * MAX_DIM];
    int matB[MAX_DIM * MAX_DIM];

    __attribute__((xcl_pipeline_loop(1)))
    madd_readA:  for (int i = 0; i < dim0 * dim1; ++i) {
                    matA[i] = a[i]; }

    __attribute__((xcl_pipeline_loop(1)))
    madd_readB:  for (int i = 0; i < dim0 * dim1; ++i) {
                    matB[i] = b[i]; }

    __attribute__((xcl_pipeline_loop(1)))
    madd_writeC: for (int i = 0; i < dim0 * dim1; ++i) {
                    c[i] =  matA[i] + matB[i]; }
}

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void mmult(global int *c, global const int *a, global const int *b,
           const int dim0, const int dim1) {
    int matA[MAX_DIM * MAX_DIM];
    int matB[MAX_DIM * MAX_DIM];

    __attribute__((xcl_pipeline_loop(1)))
    mmult_readA:  for (int i = 0; i < dim0 * dim1; ++i) {
                    matA[i] = a[i]; }

    __attribute__((xcl_pipeline_loop(1)))
    mmult_readB:  for (int i = 0; i < dim0 * dim1; ++i) {
                    matB[i] = b[i]; }

    __attribute__((xcl_pipeline_loop(1)))
    for (int j = 0; j < dim1; ++j) {
        for (int i = 0; i < dim0; ++i) {
            int temp = 0;
            for (int k = 0; k < dim1; ++k)
                temp += matA[k + i * dim0] * matB[j + k * dim0];

            c[i + j * dim0] = temp;
        }
    }
}
