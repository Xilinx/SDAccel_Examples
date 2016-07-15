/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_aes.cl
Purpose: AES-128 ECB Encrypt in Software followed by OpenCL Decrpyt
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

///10 round AES ECB SW encrypt and OpenCL HW decrypt
//Implementaiton derived from http://en.wikipedia.org/wiki/Advanced_Encryption_Standard


#define ROUNDS 10

__constant uchar rsbox[256] = { 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb\
    , 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb\
    , 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e\
    , 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25\
    , 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92\
    , 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84\
    , 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06\
    , 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b\
    , 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73\
    , 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e\
    , 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b\
    , 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4\
    , 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f\
    , 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef\
    , 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61\
    , 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};


inline uchar16 SubBytesRSBox(uchar16 input){
  uchar16 output;
  output.s0=rsbox[input.s0];
  output.s1=rsbox[input.s1];
  output.s2=rsbox[input.s2];
  output.s3=rsbox[input.s3];
  output.s4=rsbox[input.s4];
  output.s5=rsbox[input.s5];
  output.s6=rsbox[input.s6];
  output.s7=rsbox[input.s7];
  output.s8=rsbox[input.s8];
  output.s9=rsbox[input.s9];
  output.sa=rsbox[input.sa];
  output.sb=rsbox[input.sb];
  output.sc=rsbox[input.sc];
  output.sd=rsbox[input.sd];
  output.se=rsbox[input.se];
  output.sf=rsbox[input.sf];
  return(output);
}


uchar16 ShiftRowsInv(uchar16 value)
{
  unsigned int i;
  uchar16 tempValue;
  tempValue.s0123 = value.s0123;
  tempValue.s4567 = value.s7456;
  tempValue.s89ab = value.sab89;
  tempValue.scdef = value.sdefc;
  return tempValue;
}


//0x1b = 00011011
//b = 14, 9, 13, 11

//14 = 1110b
inline uchar GALOISMULTIPLICATION_14(aparam) {
  uchar a=aparam;
  uchar p = 0;
  uchar res;
  /* 0 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 1 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 2 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 3 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 4 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 5 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 6 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 7 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  res=p;
  return(res);
}

//9 = 1001b
inline uchar GALOISMULTIPLICATION_09(aparam) {
  uchar a=aparam;
  uchar p = 0;
  uchar res;
  /* 0 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 1 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 2 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 3 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 4 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 5 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 6 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 7 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  res=p;
  return(res);
}

//13 = 1101b
inline uchar GALOISMULTIPLICATION_13(aparam) {
  unsigned char a=aparam;
  unsigned char p = 0;
  uchar res;
  /* 0 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 1 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 2 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 3 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 4 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 5 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 6 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 7 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  res=p;
  return(res);
}

//11 = 1011b
inline uchar GALOISMULTIPLICATION_11(aparam) {
  unsigned char a=aparam;
  unsigned char p = 0;
  uchar res;
  /* 0 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 1 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 2 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 3 */
  p = p ^ a;
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 4 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 5 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 6 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  /* 7 */
  a = (a&0x80) ? (a<<1) ^ 0x1b : (a<<1);
  res=p;
  return(res);
}


inline uchar16 mixColumns16inv(uchar16 block)
{

  uchar16 r0,r1,r2,r3,returnval;

  //row0
  //i=0 j=0
  r0.s0=GALOISMULTIPLICATION_14(block.s0);   //0
  r1.s0=GALOISMULTIPLICATION_09(block.sc);   //3
  r2.s0=GALOISMULTIPLICATION_13(block.s8);   //2
  r3.s0=GALOISMULTIPLICATION_11(block.s4);   //1
  returnval.s0 = r0.s0 ^ r1.s0 ^ r2.s0 ^ r3.s0;

  //i=0 j=1
  r0.s1=GALOISMULTIPLICATION_14(block.s1);   //0
  r1.s1=GALOISMULTIPLICATION_09(block.sd);   //3
  r2.s1=GALOISMULTIPLICATION_13(block.s9);   //2
  r3.s1=GALOISMULTIPLICATION_11(block.s5);   //1
  returnval.s1 = r0.s1 ^ r1.s1 ^ r2.s1 ^ r3.s1;

  //i=0 j=2
  r0.s2=GALOISMULTIPLICATION_14(block.s2);   //0
  r1.s2=GALOISMULTIPLICATION_09(block.se);   //3
  r2.s2=GALOISMULTIPLICATION_13(block.sa);   //2
  r3.s2=GALOISMULTIPLICATION_11(block.s6);   //1
  returnval.s2 = r0.s2 ^ r1.s2 ^ r2.s2 ^ r3.s2;

  //i=0 j=3
  r0.s3=GALOISMULTIPLICATION_14(block.s3);   //0
  r1.s3=GALOISMULTIPLICATION_09(block.sf);   //3
  r2.s3=GALOISMULTIPLICATION_13(block.sb);   //2
  r3.s3=GALOISMULTIPLICATION_11(block.s7);   //1
  returnval.s3 = r0.s3 ^ r1.s3 ^ r2.s3 ^ r3.s3;

  //row1
  //i=1 j=0
  r0.s4=GALOISMULTIPLICATION_14(block.s4);   //1
  r1.s4=GALOISMULTIPLICATION_09(block.s0);   //0
  r2.s4=GALOISMULTIPLICATION_13(block.sc);   //3
  r3.s4=GALOISMULTIPLICATION_11(block.s8);   //2
  returnval.s4 = r0.s4 ^ r1.s4 ^ r2.s4 ^ r3.s4;

  //i=1 j=1
  r0.s5=GALOISMULTIPLICATION_14(block.s5);   //1
  r1.s5=GALOISMULTIPLICATION_09(block.s1);   //0
  r2.s5=GALOISMULTIPLICATION_13(block.sd);   //3
  r3.s5=GALOISMULTIPLICATION_11(block.s9);   //2
  returnval.s5 = r0.s5 ^ r1.s5 ^ r2.s5 ^ r3.s5;

  //i=1 j=2
  r0.s6=GALOISMULTIPLICATION_14(block.s6);   //1
  r1.s6=GALOISMULTIPLICATION_09(block.s2);   //0
  r2.s6=GALOISMULTIPLICATION_13(block.se);   //3
  r3.s6=GALOISMULTIPLICATION_11(block.sa);   //2
  returnval.s6 = r0.s6 ^ r1.s6 ^ r2.s6 ^ r3.s6;

  //i=1 j=3
  r0.s7=GALOISMULTIPLICATION_14(block.s7);   //1
  r1.s7=GALOISMULTIPLICATION_09(block.s3);   //0
  r2.s7=GALOISMULTIPLICATION_13(block.sf);   //3
  r3.s7=GALOISMULTIPLICATION_11(block.sb);   //2
  returnval.s7 = r0.s7 ^ r1.s7 ^ r2.s7 ^ r3.s7;

  //row2
  //i=2 j=0
  r0.s8=GALOISMULTIPLICATION_14(block.s8);   //2
  r1.s8=GALOISMULTIPLICATION_09(block.s4);   //1
  r2.s8=GALOISMULTIPLICATION_13(block.s0);   //0
  r3.s8=GALOISMULTIPLICATION_11(block.sc);   //3
  returnval.s8 = r0.s8 ^ r1.s8 ^ r2.s8 ^ r3.s8;

  //i=2 j=1
  r0.s9=GALOISMULTIPLICATION_14(block.s9);   //2
  r1.s9=GALOISMULTIPLICATION_09(block.s5);   //1
  r2.s9=GALOISMULTIPLICATION_13(block.s1);   //0
  r3.s9=GALOISMULTIPLICATION_11(block.sd);   //3
  returnval.s9 = r0.s9 ^ r1.s9 ^ r2.s9 ^ r3.s9;

  //i=2 j=2
  r0.sa=GALOISMULTIPLICATION_14(block.sa);   //2
  r1.sa=GALOISMULTIPLICATION_09(block.s6);   //1
  r2.sa=GALOISMULTIPLICATION_13(block.s2);   //0
  r3.sa=GALOISMULTIPLICATION_11(block.se);   //3
  returnval.sa = r0.sa ^ r1.sa ^ r2.sa ^ r3.sa;

  //i=2 j=3
  r0.sb=GALOISMULTIPLICATION_14(block.sb);   //2
  r1.sb=GALOISMULTIPLICATION_09(block.s7);   //1
  r2.sb=GALOISMULTIPLICATION_13(block.s3);   //0
  r3.sb=GALOISMULTIPLICATION_11(block.sf);   //3
  returnval.sb = r0.sb ^ r1.sb ^ r2.sb ^ r3.sb;

  //row3
  //i=3 j=0
  r0.sc=GALOISMULTIPLICATION_14(block.sc);   //2
  r1.sc=GALOISMULTIPLICATION_09(block.s8);   //1
  r2.sc=GALOISMULTIPLICATION_13(block.s4);   //0
  r3.sc=GALOISMULTIPLICATION_11(block.s0);   //3
  returnval.sc = r0.sc ^ r1.sc ^ r2.sc ^ r3.sc;

  //i=3 j=1
  r0.sd=GALOISMULTIPLICATION_14(block.sd);   //2
  r1.sd=GALOISMULTIPLICATION_09(block.s9);   //1
  r2.sd=GALOISMULTIPLICATION_13(block.s5);   //0
  r3.sd=GALOISMULTIPLICATION_11(block.s1);   //3
  returnval.sd = r0.sd ^ r1.sd ^ r2.sd ^ r3.sd;

  //i=3 j=2
  r0.se=GALOISMULTIPLICATION_14(block.se);   //2
  r1.se=GALOISMULTIPLICATION_09(block.sa);   //1
  r2.se=GALOISMULTIPLICATION_13(block.s6);   //0
  r3.se=GALOISMULTIPLICATION_11(block.s2);   //3
  returnval.se = r0.se ^ r1.se ^ r2.se ^ r3.se;

  //i=3 j=3
  r0.sf=GALOISMULTIPLICATION_14(block.sf);   //2
  r1.sf=GALOISMULTIPLICATION_09(block.sb);   //1
  r2.sf=GALOISMULTIPLICATION_13(block.s7);   //0
  r3.sf=GALOISMULTIPLICATION_11(block.s3);   //3
  returnval.sf = r0.sf ^ r1.sf ^ r2.sf ^ r3.sf;
  return(returnval);
}

uchar16 AddRoundKey(uchar16 block,unsigned int round,local uchar16 *roundkey){
  uchar16 output = block ^ roundkey[round];
  return(output);
}


__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_aes_decrypt(__global uchar16  *output,__global uchar16  *input,
		               __global  uchar16  *roundKey, uint blocks)
{
  //load key
  int i;

  #ifdef __xilinx__
  	local uchar16 roundkeylocal[ROUNDS+1] __attribute__((xcl_array_partition(complete,1)));
  #else
  	local uchar16 roundkeylocal[ROUNDS+1];
  #endif
  for(i=0;i<(ROUNDS+1);i++) roundkeylocal[i]=roundKey[i];

  //decrypt
  unsigned int blockindex;

  #ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
  #endif
  for(blockindex=0;blockindex<blocks;blockindex++){
    uchar16 block0;

    block0 = input[blockindex];

    //InitialRound
    block0 = AddRoundKey(block0,ROUNDS,roundkeylocal);

    //Rounds
    for(i=(ROUNDS-1); i>=1;i--){
      block0 = ShiftRowsInv(block0); //ShiftRowsInc
      block0 = SubBytesRSBox(block0); //SubBytesRSBox
      block0 = AddRoundKey(block0,i,roundkeylocal); //addRoundKey
      block0  = mixColumns16inv(block0); //mixColumnsInv
    }

    block0 = ShiftRowsInv(block0); //ShiftRowsInv
    block0 = SubBytesRSBox(block0); //SubBytesRSBox
    block0 = AddRoundKey(block0,0,roundkeylocal); //addRoundKey

    output[blockindex] = block0;
  }
}
