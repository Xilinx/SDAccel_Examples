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
//Define the size of the pixel neighbourhood for the median computation
#define SIZE      9
//Define the number of color channels to use during the computation
#define CHANNELS  3

// Define the max image width to be processed
// This setting affects the size of the local memory created by the compiler
// in the FPGA fabric
#define MAX_WIDTH 512

#define imin(X, Y) (((X) < (Y)) ? (X) : (Y))
#define imax(X, Y) (((X) > (Y)) ? (X) : (Y))

//
// Median value computation
//
uint getMedian(int channel, uint* rgb) {
  uint mask = 0xFF << (8*channel);

  // Extract next color channel
  uint c[SIZE];
  for (int p = 0; p < SIZE; p++) {
    c[p] = rgb[p] & mask;
  }

  // Perform sort to find median of current channel
  uint minval = imin(c[0], c[1]);
  uint maxval = imax(c[0], c[1]);
  c[0] = minval;
  c[1] = maxval;

  minval = imin(c[3], c[2]);
  maxval = imax(c[3], c[2]);
  c[3] = minval;
  c[2] = maxval;

  minval = imin(c[2], c[0]);
  maxval = imax(c[2], c[0]);
  c[2] = minval;
  c[0] = maxval;

  minval = imin(c[3], c[1]);
  maxval = imax(c[3], c[1]);
  c[3] = minval;
  c[1] = maxval;

  minval = imin(c[1], c[0]);
  maxval = imax(c[1], c[0]);
  c[1] = minval;
  c[0] = maxval;

  minval = imin(c[3], c[2]);
  maxval = imax(c[3], c[2]);
  c[3] = minval;
  c[2] = maxval;

  minval = imin(c[5], c[4]);
  maxval = imax(c[5], c[4]);
  c[5] = minval;
  c[4] = maxval;

  minval = imin(c[7], c[8]);
  maxval = imax(c[7], c[8]);
  c[7] = minval;
  c[8] = maxval;

  minval = imin(c[6], c[8]);
  maxval = imax(c[6], c[8]);
  c[6] = minval;
  c[8] = maxval;

  minval = imin(c[6], c[7]);
  maxval = imax(c[6], c[7]);
  c[6] = minval;
  c[7] = maxval;

  minval = imin(c[4], c[8]);
  maxval = imax(c[4], c[8]);
  c[4] = minval;
  c[8] = maxval;

  minval = imin(c[4], c[6]);
  maxval = imax(c[4], c[6]);
  c[4] = minval;
  c[6] = maxval;

  minval = imin(c[5], c[7]);
  maxval = imax(c[5], c[7]);
  c[5] = minval;
  c[7] = maxval;

  minval = imin(c[4], c[5]);
  maxval = imax(c[4], c[5]);
  c[4] = minval;
  c[5] = maxval;

  minval = imin(c[6], c[7]);
  maxval = imax(c[6], c[7]);
  c[6] = minval;
  c[7] = maxval;

  minval = imin(c[0], c[8]);
  maxval = imax(c[0], c[8]);
  c[0] = minval;
  c[8] = maxval;

  c[4] = imax(c[0], c[4]);
  c[5] = imax(c[1], c[5]);

  c[6] = imax(c[2], c[6]);
  c[7] = imax(c[3], c[7]);

  c[4] = imin(c[4], c[6]);
  c[5] = imin(c[5], c[7]);

  return imin(c[4], c[5]);
}

//
// Median filter kernel
// Kernel processes entire image frame per call to the accelerator
//
__kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void median(__global const uint* input, __global uint* output, int width, int height) {
  local uint linebuf0[MAX_WIDTH];
  local uint linebuf1[MAX_WIDTH];
  local uint linebuf2[MAX_WIDTH];
  local uint lineres[MAX_WIDTH];

  for (int line = 0; line < height; line++) {
    // Fetch Lines
    if (line == 0) {
      async_work_group_copy(linebuf0, input, width, 0);
      async_work_group_copy(linebuf1, input, width, 0);
      async_work_group_copy(linebuf2, input + width, width, 0);
    }
    else if (line < height-1) {
      if (line % 3 == 0)
        async_work_group_copy(linebuf0, input + (line+1)*width, width, 0);
      else if (line % 3 == 1)
        async_work_group_copy(linebuf1, input + (line+1)*width, width, 0);
      else if (line % 3 == 2)
        async_work_group_copy(linebuf2, input + (line+1)*width, width, 0);
    }
    barrier(CLK_LOCAL_MEM_FENCE);

    __attribute__((xcl_pipeline_loop))
    for (int x=0; x < width; x++) {
      // Get pixels within 3x3 aperture
      uint rgb[SIZE];
      rgb[0] = (x == 0) ? linebuf0[x] : linebuf0[x - 1];
      rgb[1] = linebuf0[x];
      rgb[2] = (x == width-1) ? linebuf0[x] : linebuf0[x + 1];

      rgb[3] = (x == 0) ? linebuf1[x] : linebuf1[x - 1];
      rgb[4] = linebuf1[x];
      rgb[5] = (x == width-1) ? linebuf1[x] : linebuf1[x + 1];

      rgb[6] = (x == 0) ? linebuf2[x] : linebuf2[x - 1];
      rgb[7] = linebuf2[x];
      rgb[8] = (x == width-1) ? linebuf2[x] : linebuf2[x + 1];

      uint result = 0;

      // Iterate over all color channels
      for (int channel = 0; channel < CHANNELS; channel++) {
        result |= getMedian(channel, rgb);
      }

      // Store result into memory
      lineres[x] = result;
    }

    async_work_group_copy(output + line*width, lineres, width, 0);
    barrier(CLK_LOCAL_MEM_FENCE);
  }
}
