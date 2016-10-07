/**********
Copyright (c) 2016, Xilinx, Inc.
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
// File: kernel.cl
// Author: Xiaozhu Kang, Xilinx
// Description:
// Tiny Encryption Algorithm (TEA), a simple block cipher, optimized


kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void tinyEncryption(__global const uint2* my_input, __global uint2* my_output,__global const uint4* my_keys, int my_length) {
   local uint2 linebufInput[8192] __attribute__((xcl_array_partition(cyclic,8,1)));
   local uint4 linebufKeys[8192] __attribute__((xcl_array_partition(cyclic,8,1)));
   local uint2 linebufOutput[8192] __attribute__((xcl_array_partition(cyclic,8,1)));

  const uint delta=0x9e3779b9;
  async_work_group_copy(linebufInput, my_input, 8192, 0);
  async_work_group_copy(linebufKeys, my_keys, 8192, 0);
  __attribute__((xcl_pipeline_loop))
  for(int i=0;i<1024;i++) {
    for(int k=0;k<8;k++){
    uint v0=linebufInput[8*i+k].x, v1=linebufInput[8*i+k].y, sum=0;
    uint k0=linebufKeys[8*i+k].x, k1=linebufKeys[8*i+k].y, k2=linebufKeys[8*i+k].z, k3=linebufKeys[8*i+k].w;
    for (int j=0; j < 32; j++) {
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }
    linebufOutput[8*i+k].x=v0;
    linebufOutput[8*i+k].y=v1;
   }
  }
  async_work_group_copy(my_output, linebufOutput, 8192, 0);
}
