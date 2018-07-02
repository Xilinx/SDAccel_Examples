// -*- mode:c -*-
// vim:ft=c:

/**********
Copyright (c) 2018, Xilinx, Inc.
Copyright (c) 2018, Akamai Technologies, Inc.
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

//10 round AES ECB SW encrypt and OpenCL HW decrypt
//Implementaiton derived from http://en.wikipedia.org/wiki/Advanced_Encryption_Standard

#define ROUNDS 10

__constant uchar rsbox[256] = {
      0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb\
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


__attribute__((always_inline)) uchar16 SubBytesRSBox(uchar16 input){
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


__attribute__((always_inline)) uchar16 ShiftRowsInv(uchar16 value)
{
  unsigned int i;
  uchar16 tempValue;

  // Do operations on columns, not rows (the AES state matrix is in column-major
  // order)
  
  // Right Rotation 0
  tempValue.s048c = value.s048c;
  // Right Rotation 1
  tempValue.s159d = value.sd159;
  // Right Rotation 2
  tempValue.s26ae = value.sae26;
  // Right Rotation 3
  tempValue.s37bf = value.s7bf3;
  
  return tempValue;
}


//0x1b = 00011011
//b = 14, 9, 13, 11

//14 = 1110b
__attribute__((always_inline)) uchar GALOISMULTIPLICATION_14(aparam) {
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
__attribute__((always_inline)) uchar GALOISMULTIPLICATION_09(aparam) {
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
__attribute__((always_inline)) uchar GALOISMULTIPLICATION_13(aparam) {
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
__attribute__((always_inline)) uchar GALOISMULTIPLICATION_11(aparam) {
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

__attribute__((always_inline)) uchar4 MixColumn16Inv(uchar4 col) {
  uchar4 res;

  res.s0 = GALOISMULTIPLICATION_14(col.s0) ^
    GALOISMULTIPLICATION_11(col.s1) ^
    GALOISMULTIPLICATION_13(col.s2) ^
    GALOISMULTIPLICATION_09(col.s3);
  
  res.s1 = GALOISMULTIPLICATION_09(col.s0) ^
    GALOISMULTIPLICATION_14(col.s1) ^
    GALOISMULTIPLICATION_11(col.s2) ^
    GALOISMULTIPLICATION_13(col.s3);
  
  res.s2 = GALOISMULTIPLICATION_13(col.s0) ^
    GALOISMULTIPLICATION_09(col.s1) ^
    GALOISMULTIPLICATION_14(col.s2) ^
    GALOISMULTIPLICATION_11(col.s3);
  
  res.s3 = GALOISMULTIPLICATION_11(col.s0) ^
    GALOISMULTIPLICATION_13(col.s1) ^
    GALOISMULTIPLICATION_09(col.s2) ^
    GALOISMULTIPLICATION_14(col.s3);

  return res;
}

__attribute__((always_inline)) uchar16 mixColumns16inv(uchar16 block)
{
  uchar16 returnval;

  // Note that this is operating on rows, not columns.  The AES state matrix
  // is in column-major order, and C-style arrays are in row-major order, so
  // this operation must be transposed.
  returnval.s0123 = MixColumn16Inv(block.s0123);
  returnval.s4567 = MixColumn16Inv(block.s4567);
  returnval.s89ab = MixColumn16Inv(block.s89ab);
  returnval.scdef = MixColumn16Inv(block.scdef);

  return returnval;
}

__attribute__((always_inline)) uchar16 AddRoundKey(uchar16 block, unsigned int round, __local uchar16 *roundkey){
  uchar16 output = block ^ roundkey[round];
  return(output);
}


__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_aes_decrypt(__global uchar16 *output, __global uchar16 *input,
		              __global uchar16 *roundKey, uint blocks)
{
  //load key
  int i;

  #ifdef __xilinx__
  	local uchar16 roundkeylocal[ROUNDS+1] __attribute__((xcl_array_partition(complete, 1)));
  #else
  	local uchar16 roundkeylocal[ROUNDS+1];
  #endif
  for(i=0; i<(ROUNDS+1); i++)
    roundkeylocal[i]=roundKey[i];

  //decrypt
  unsigned int blockindex;

  #ifdef __xilinx__
    __attribute__((xcl_pipeline_loop))
  #endif
  for(blockindex = 0; blockindex < blocks; blockindex++) {
    uchar16 block0;

    block0 = input[blockindex];

    //InitialRound
    block0 = AddRoundKey(block0, ROUNDS, roundkeylocal);

    //Rounds
    for(i = (ROUNDS-1); i>=1; i--){
      block0 = ShiftRowsInv(block0); //ShiftRowsInc
      block0 = SubBytesRSBox(block0); //SubBytesRSBox
      block0 = AddRoundKey(block0, i, roundkeylocal); //addRoundKey
      block0  = mixColumns16inv(block0); //mixColumnsInv
    }

    block0 = ShiftRowsInv(block0); //ShiftRowsInv
    block0 = SubBytesRSBox(block0); //SubBytesRSBox
    block0 = AddRoundKey(block0, 0, roundkeylocal); //addRoundKey

    output[blockindex] = block0;
  }
}
