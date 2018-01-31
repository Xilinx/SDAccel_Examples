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

/*
  Performs a simple vector addition on the input and the input
  is provided as a stream of data.
  See host code for additional details about this example
*/

#define BUFFER_SIZE 256

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void vec_add(global int* c,
          global const int* a,
          global const int* b,
          global int* result_size,
          size_t elements
          ) {
    int arrayA[BUFFER_SIZE], arrayB[BUFFER_SIZE];
    int k = 0;
    for (int i = 0 ; i < elements ; i += BUFFER_SIZE)
    {
        int size = BUFFER_SIZE;
        if (i + size > elements) size = elements - i;

        readA: for (int j = 0 ; j < size ; j++) arrayA[j] = a[i+j];
        readB: for (int j = 0 ; j < size ; j++) arrayB[j] = b[i+j];

        writeC: for (int j = 0 ; j < (size-1)/2 + 1 ; j++) c[k+j] = arrayA[2*j] + arrayB[2*j];
        k = k + (size-1)/2 + 1;
    }
    result_size[0] = k;
}
