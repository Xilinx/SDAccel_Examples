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
#include "clSha1.h"

void dev_sha1_transform(u_int32_t state[5], u_int32_t buffer[16]) {
  u_int32_t a, b, c, d, e;

  a = state[0];
  b = state[1];
  c = state[2];
  d = state[3];
  e = state[4];

  for (int n = 0; n < 80; n++) {
    u_int32_t k, f, w;

    if(n < 16) {
       /* Little to Big Endian Conversion */
       w = (rol(buffer[n],24) & 0xFF00FF00) |
           (rol(buffer[n], 8) & 0x00FF00FF);
    } else {
       w = rol(buffer[(n + 13) & 15] ^
               buffer[(n + 8)  & 15] ^
               buffer[(n + 2)  & 15] ^
               buffer[(n + 0)  & 15], 1);
    }

    buffer[n & 15] = w;

    u_int32_t sub = c^d;
    u_int32_t f1  = ((b&(sub))^d);
    u_int32_t f2  = (b^sub);
    u_int32_t f3  = (((b|c)&d)|(b&c));

    if (n < 20) {
      k = 0x5A827999;
      f = f1;
    } else if (n < 40) {
      k = 0x6ED9EBA1;
      f = f2;
    } else if (n < 60) {
      k = 0x8F1BBCDC;
      f = f3;
    } else {
      k = 0xCA62C1D6;
      f = f2;
    }

    u_int32_t temp = k + f + e + w + rol(a,5);
    e = d;
    d = c;
    c = rol(b,30);
    b = a;
    a = temp;
  }

  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
  state[4] += e;
}

#ifdef __xilinx__
__attribute__ ((reqd_work_group_size(1, 1, 1)))
#endif
kernel void dev_sha1_update(global buf_t *gbuf, global state_t *gstate) {
  local state_t lstate[PIPELINE_DEPTH];

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH; i++) {
    lstate[i] = gstate[i];
#ifdef DEBUG
    u_int32_t state[5];
    state[0] = gstate[i].STATEA;
    state[1] = gstate[i].STATEB;
    state[2] = gstate[i].STATEC;
    state[3] = gstate[i].STATED;
    state[4] = gstate[i].STATEE;
    printf("chan = %3d, state = %8x %8x %8x %8x %8x\n",
            i, state[0], state[1], state[2], state[3], state[4]);
#endif
  }

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH*BLOCKS; i++) {
    u_int32_t state[5] __attribute__((xcl_array_partition(complete, 1)));

    state[0] = lstate[i%PIPELINE_DEPTH].STATEA;
    state[1] = lstate[i%PIPELINE_DEPTH].STATEB;
    state[2] = lstate[i%PIPELINE_DEPTH].STATEC;
    state[3] = lstate[i%PIPELINE_DEPTH].STATED;
    state[4] = lstate[i%PIPELINE_DEPTH].STATEE;

    uint16 lbuf __attribute__((xcl_array_partition(complete, 1)));
    lbuf = gbuf[i];

    u_int32_t buf[16] __attribute__((xcl_array_partition(complete, 1)));

    uint16_to_array(lbuf, buf);

#ifdef DEBUG
    if(i%PIPELINE_DEPTH == 0) {
      printf("sha1_transform: init chan = %d, state = %x %x %x %x %x\n",
             i%PIPELINE_DEPTH, state[0], state[1], state[2], state[3], state[4]);
      printf("  buf = ");
      char cbuf[64];
      uint16_to_char_array(lbuf, cbuf);
      for (int j = 0; j < 64; j++) {
        printf("%02x", cbuf[j] & 0xFF);
      }
      printf("\n");
    }
#endif

    dev_sha1_transform(state, buf);

 #ifdef DEBUG
    if(i%PIPELINE_DEPTH == 0) {
      printf("sha1_transform: exit chan = %d, state = %x %x %x %x %x\n",
             i%PIPELINE_DEPTH, state[0], state[1], state[2], state[3], state[4]);
    }
#endif

    lstate[i%PIPELINE_DEPTH].STATEA = state[0];
    lstate[i%PIPELINE_DEPTH].STATEB = state[1];
    lstate[i%PIPELINE_DEPTH].STATEC = state[2];
    lstate[i%PIPELINE_DEPTH].STATED = state[3];
    lstate[i%PIPELINE_DEPTH].STATEE = state[4];
  }

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH; i++) {
    gstate[i] = lstate[i];
  }

}

