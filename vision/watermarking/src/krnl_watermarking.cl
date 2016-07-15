/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_watermarking.cl
Purpose: SDAccel 10x10 watermarking kernel for image processing
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
