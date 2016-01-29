/*******************************************************************************
Vendor: Xilinx
Associated Filename: bitmap.cpp
Purpose: Bitmap image formate read and write functions

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



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "bitmap.h"

BitmapInterface::BitmapInterface(const char* f) : filename(f) 
{
  core = NULL ;
  dib = NULL ;
  image = NULL ;

  magicNumber = 0 ;
  fileSize = 0 ;
  offsetOfImage = 0 ;

  sizeOfDIB = 0 ;
  sizeOfImage = 0 ;

  height = -1 ;
  width = -1 ;
}

BitmapInterface::~BitmapInterface()
{
  if (core != NULL)
    delete [] core ;
  if (dib != NULL)
    delete [] dib ;
  if (image != NULL)
    delete [] image ;
}

bool BitmapInterface::readBitmapFile()
{
  // First, open the bitmap file
  int fd ;
  int numRead ;
  unsigned int fileSize ;

  fd = open(filename, O_RDONLY) ;
  if (fd < 0)
  {
    std::cerr << "Cannot read image file " << filename << std::endl ;
    return false ;
  }

  core = new char[14] ;
  numRead = read(fd, core, 14) ;
  magicNumber = (*(unsigned short*)(&(core[0]))) ;
  fileSize = (*(unsigned int*)(&(core[2]))) ;
  offsetOfImage = (*(unsigned int*)(&(core[10]))) ;

  // Just read in the DIB, but don't process it
  sizeOfDIB = offsetOfImage - 14 ;
  dib = new char[sizeOfDIB] ;
  numRead = read(fd, dib, sizeOfDIB) ;

  width = (*(int*)(&(dib[4]))) ;
  height = (*(int*)(&(dib[8]))) ;
  
  sizeOfImage = fileSize - 14 - sizeOfDIB ;
  int numPixels = sizeOfImage / 3 ; // RGB

  image = new int[numPixels] ;

  for (int i = 0 ; i < numPixels ; ++i)
  {
    // Use an integer for every pixel even though we might not need that
    //  much space (padding 0 bits in the rest of the integer)
    image[i] = 0 ; 
    read(fd, &(image[i]), 3) ;
  }

  return true ;
}
		    
bool BitmapInterface::writeBitmapFile(int* otherImage)
{
  int fd ;
  fd = open("output.bmp", O_WRONLY | O_CREAT, 0644) ;

  if (fd < 0)
  {
    std::cerr << "Cannot open output.bmp for writing!" << std::endl ;
    return false ;
  }

  write(fd, core, 14) ;
  write(fd, dib, sizeOfDIB) ;

  int numPixels = sizeOfImage / 3 ;

  int* outputImage = otherImage != NULL ? otherImage : image ;
  
  for (int i = 0 ; i < numPixels ; ++i)
  {
    write(fd, &(outputImage[i]), 3) ;
  }

  return true ;
}
