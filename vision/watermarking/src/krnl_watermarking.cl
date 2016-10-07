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
#define height 64
#define width 64

int saturatedAdd(int x, int y)
{
  // Separate into the different channels
  int redX = x & 0xff ;
  int redY = y & 0xff ;
  int redOutput ;

  int greenX = (x & 0xff00) >> 8 ;
  int greenY = (y & 0xff00) >> 8 ;
  int greenOutput ;

  int blueX = (x & 0xff0000) >> 16 ;
  int blueY = (y & 0xff0000) >> 16 ;
  int blueOutput ;

  int combinedOutput = 0 ;

  if (redX + redY > 255)
  {
    redOutput = 255 ;
  }
  else 
  {
    redOutput = redX + redY ;
  }

  if (greenX + greenY > 255)
  {
    greenOutput = 255 ;
  }
  else 
  {
    greenOutput = greenX + greenY ;
  }

  if (blueX + blueY > 255)
  {
    blueOutput = 255 ;
  }
  else 
  {
    blueOutput = blueX + blueY ;
  }

  combinedOutput |= redOutput ;
  combinedOutput |= (greenOutput << 8) ;
  combinedOutput |= (blueOutput << 16) ;
  return combinedOutput ;

}

__kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void applyWatermark(__global const uint* input, __global uint* output) {

  const int watermark[WATERMARK_HEIGHT][WATERMARK_WIDTH] = 
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
  } ;

 local uint linebuf[MAX_WIDTH];
 
 local uint lineres[MAX_WIDTH];
 uint temp;

  // Process the whole image
  __attribute__((xcl_pipeline_loop))
  for (int y = 0 ; y < height-WATERMARK_HEIGHT ; y += WATERMARK_HEIGHT)
  {
     
    __attribute__((opencl_unroll_hint))
   
    for (int i = 0 ; i < WATERMARK_HEIGHT ; ++i)
    {
      temp = width*(y+i) ; //compute when need
      async_work_group_copy(linebuf, input+temp, width, 0);


      for(int x = 0 ; x < width-WATERMARK_WIDTH ; x += WATERMARK_WIDTH)
      {

        for (int j = 0 ; j < WATERMARK_WIDTH ; ++j)
        {
          
          lineres[x + j] = 
            saturatedAdd(linebuf[x + j], watermark[i][j]) ;
        }
       
      }
     
      async_work_group_copy(output + temp, lineres, width, 0);
      
     }

      // Finish off the last columns
     //__attribute__((xcl_pipeline_loop))
     for (int i = 0 ; i < WATERMARK_HEIGHT ; ++i)
     {
       temp = width*(y+i) ;   
       async_work_group_copy(lineres+width-WATERMARK_WIDTH, input+temp+width-WATERMARK_WIDTH, WATERMARK_WIDTH, 0);
       
       async_work_group_copy(output+temp+width-WATERMARK_WIDTH,lineres+width-WATERMARK_WIDTH, WATERMARK_WIDTH, 0);
       
     }
   
  }
  // Finish off the last rows

  //__attribute__((xcl_pipeline_loop))
 
  for (int y = height - WATERMARK_HEIGHT ; y < height ; ++y)
  {
     async_work_group_copy(linebuf, input+y*width, width, 0);
     
     async_work_group_copy(output + y*width, linebuf, width, 0);
     
   }
}
