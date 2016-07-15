/*******************************************************************************
Vendor: Xilinx
Associated Filename: simplebmp.cpp
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "simplebmp.h"



int writebmp(char *filename,struct bmp_t *bitmap){
  //24 bpp uncompressed

  FILE *fp=fopen(filename,"w+b");
  if(fp==NULL) return -1;

  //compute dib entries
  bitmap->header.dibheadersize = 40;
  bitmap->header.dibwidth = bitmap->width;
  bitmap->header.dibheight = bitmap->height;
  bitmap->header.dibplane=1;
  bitmap->header.dibdepth=24;
  bitmap->header.dibcompression=0;
  bitmap->header.dibsize = (bitmap->width)*(bitmap->height)*(bitmap->header.dibdepth/8);
  bitmap->header.dibhor=2835;
  bitmap->header.dibver=2835;
  bitmap->header.dibpal=0;
  bitmap->header.dibimportant=0;


  //compute header entries
  bitmap->header.headerB='B';
  bitmap->header.headerM='M';
  bitmap->header.headerpixelsoffset=54;
  bitmap->header.headerbmpsize=bitmap->header.dibsize+bitmap->header.headerpixelsoffset;
  bitmap->header.headerapp0=0;
  bitmap->header.headerapp1=0;


  //write header
  fwrite(&(bitmap->header.headerB),1,1,fp); 
  fwrite(&(bitmap->header.headerM),1,1,fp); 
  fwrite(&(bitmap->header.headerbmpsize),4,1,fp); 
  fwrite(&(bitmap->header.headerapp0),2,1,fp); 
  fwrite(&(bitmap->header.headerapp1),2,1,fp); 
  fwrite(&(bitmap->header.headerpixelsoffset),4,1,fp); 

  //write dib header
  fwrite(&(bitmap->header.dibheadersize),4,1,fp);
  fwrite(&(bitmap->header.dibwidth),4,1,fp);
  fwrite(&(bitmap->header.dibheight),4,1,fp);
  fwrite(&(bitmap->header.dibplane),2,1,fp);
  fwrite(&(bitmap->header.dibdepth),2,1,fp);
  fwrite(&(bitmap->header.dibcompression),4,1,fp);
  fwrite(&(bitmap->header.dibsize),4,1,fp);
  fwrite(&(bitmap->header.dibhor),4,1,fp);
  fwrite(&(bitmap->header.dibver),4,1,fp);
  fwrite(&(bitmap->header.dibpal),4,1,fp);
  fwrite(&(bitmap->header.dibimportant),4,1,fp);

  //write pixels
  fwrite(bitmap->pixels,bitmap->header.dibsize,1,fp);

  if(ferror(fp)) return -1;
  
  fclose(fp);
  return 0;
}



int readbmp(char *filename,struct bmp_t *bitmap){
  //-1 file access error
  //-2 invalid BMP
  //-3 memory allocation error
  FILE *fp=fopen(filename,"r+b");
  if(fp==NULL) return -1;

  //read header
  fread(&(bitmap->header.headerB),1,1,fp); 
  fread(&(bitmap->header.headerM),1,1,fp); 
  fread(&(bitmap->header.headerbmpsize),4,1,fp); 
  fread(&(bitmap->header.headerapp0),2,1,fp); 
  fread(&(bitmap->header.headerapp1),2,1,fp); 
  fread(&(bitmap->header.headerpixelsoffset),4,1,fp); 
  //read dib header
  fread(&(bitmap->header.dibheadersize),4,1,fp);
  fread(&(bitmap->header.dibwidth),4,1,fp);
  fread(&(bitmap->header.dibheight),4,1,fp);
  fread(&(bitmap->header.dibplane),2,1,fp);
  fread(&(bitmap->header.dibdepth),2,1,fp);
  fread(&(bitmap->header.dibcompression),4,1,fp);
  fread(&(bitmap->header.dibsize),4,1,fp);
  fread(&(bitmap->header.dibhor),4,1,fp);
  fread(&(bitmap->header.dibver),4,1,fp);
  fread(&(bitmap->header.dibpal),4,1,fp);
  fread(&(bitmap->header.dibimportant),4,1,fp);

  if(ferror(fp)) return -1;

  //validate header
  //header
  if(bitmap->header.headerB!='B') return -2;
  if(bitmap->header.headerM!='M') return -2;
  //headerbmpsize
  if(bitmap->header.headerapp0!=0) return -2;
  if(bitmap->header.headerapp1!=0) return -2;
  if(bitmap->header.headerpixelsoffset!=54) return -2;
  //dib header
  if(bitmap->header.dibheadersize!=40) return -2;
  bitmap->width=bitmap->header.dibwidth;
  bitmap->height=bitmap->header.dibheight;
  if(bitmap->header.dibplane!=1) return -2;
  if(bitmap->header.dibdepth!=24) return -2;
  if(bitmap->header.dibcompression!=0) return -2;
  if(bitmap->header.dibsize!=(bitmap->header.dibwidth*bitmap->header.dibheight*3)) return -2;
  //dibsize do nothing yet
  //dibhor unused
  //dibver unused
  if(bitmap->header.dibpal!=0) return -2;
  if(bitmap->header.dibimportant!=0) return -2;

  //read pixels
  bitmap->pixels=(uint32_t *) malloc (bitmap->header.dibsize);
  if(bitmap->pixels==NULL) return -3;
  fread(bitmap->pixels,bitmap->header.dibsize,1,fp);

  if(ferror(fp)) return -1;

  fclose(fp);
  return 0;
}


