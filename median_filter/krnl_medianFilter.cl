/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_medianFilter.cl
Purpose: SDAccel 3x3 median filter kernel for image processing
Revision History: November 25, 2015

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/


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
