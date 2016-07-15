/*******************************************************************************
Vendor: Xilinx
Associated Filename: simplebmp.h
Purpose: SDAccel huffman codec example
Revision History: January 29, 2016

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

//Read and write uncompressed 24 bit BMP image format image
//based on http://en.wikipedia.org/wiki/BMP_file_formt
//Copyright Xilinx


#ifndef __SIMPLE_BMP
#define __SIMPLE_BMP

struct bmpheader_t{
  //Header
  char headerB;
  char headerM;
  uint32_t headerbmpsize;              
  uint16_t headerapp0;
  uint16_t headerapp1;
  uint32_t headerpixelsoffset;

  //DIB header
  uint32_t dibheadersize;
  uint32_t dibwidth;
  uint32_t dibheight;
  uint16_t dibplane;
  uint16_t dibdepth;
  uint32_t dibcompression;
  uint32_t dibsize; 
  uint32_t dibhor;
  uint32_t dibver;
  uint32_t dibpal;
  uint32_t dibimportant;
  
};


struct bmp_t{
  struct bmpheader_t header;
  uint32_t width;
  uint32_t height;
  uint32_t *pixels;
};

int writebmp(char *filename,struct bmp_t *bitmap);

int readbmp(char *filename,struct bmp_t *bitmap);
//-1 file access error
//-2 invalid BMP
//-3 memory allocation error
 

#endif
