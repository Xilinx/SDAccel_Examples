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

#define CHANNELS  3
#define WATERMARK_HEIGHT 10
#define WATERMARK_WIDTH 10
#define MAX_WIDTH  512

uint saturatedAdd(uint x, uint y)
{
  // Separate into the different channels
  uchar redX = x & 0xff;
  uchar redY = y & 0xff;
  uchar redOutput;

  uchar greenX = (x & 0xff00) >> 8;
  uchar greenY = (y & 0xff00) >> 8;
  uchar greenOutput;

  uchar blueX = (x & 0xff0000) >> 16;
  uchar blueY = (y & 0xff0000) >> 16;
  uchar blueOutput;

  
  if (redX + redY > 255)
  {
    redOutput = 255;
  }
  else
  {
    redOutput = redX + redY;
  }

  if (greenX + greenY > 255)
  {
    greenOutput = 255;
  }
  else
  {
    greenOutput = greenX + greenY;
  }

  if (blueX + blueY > 255)
  {
    blueOutput = 255;
  }
  else 
  {
    blueOutput = blueX + blueY;
  }

  uint combinedOutput = 0;

  combinedOutput |= (uint) redOutput;
  combinedOutput |= ((uint) greenOutput << 8);
  combinedOutput |= ((uint) blueOutput << 16);

  return combinedOutput;

}

__kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void applyWatermark(__global const uint* input, __global uint* output, const uint gwidth, const uint gheight) {

  const uint watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH] =
  {
    { 0, 0,        0, 0, 0, 0, 0, 0, 0,        0 },
    { 0, 0x0f0f0f, 0, 0, 0, 0, 0, 0, 0x0f0f0f, 0 },
    { 0, 0, 0x0f0f0f, 0, 0, 0, 0, 0x0f0f0f, 0, 0 },
    { 0, 0, 0, 0x0f0f0f, 0, 0, 0x0f0f0f, 0, 0, 0 },
    { 0, 0, 0, 0, 0x0f0f0f, 0x0f0f0f, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0x0f0f0f, 0x0f0f0f, 0, 0, 0, 0 },
    { 0, 0, 0, 0x0f0f0f, 0, 0, 0x0f0f0f, 0, 0, 0 },
    { 0, 0, 0x0f0f0f, 0, 0, 0, 0, 0x0f0f0f, 0, 0 },
    { 0, 0x0f0f0f, 0, 0, 0, 0, 0, 0, 0x0f0f0f, 0 },
    { 0, 0,        0, 0, 0, 0, 0, 0, 0,        0 }
  };

  const uint width = gwidth;
  const uint height = gheight;

  uint row = 0, col = 0;
  uint wrow = 0, wcol = 0;

  __attribute__((xcl_pipeline_loop))
  for (size_t p = 0; p < height*width; p++)
  {
    output[p] = 
      saturatedAdd(input[p], watermark[wcol][wrow]);

    col = (col == width-1) ? 0 : col+1;
    wcol = (wcol == WATERMARK_WIDTH-1 || col == width-1) ? 0 : wcol+1;
    row = (col == width-1) ? row+1 : row;
    wrow = (col == width-1) ? ((wrow == WATERMARK_HEIGHT-1) ? 0 : wrow+1) : wrow;
  }
}
