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

//10 round AES ECB encrypt
//Implementaiton derived from http://en.wikipedia.org/wiki/Advanced_Encryption_Standard  

#include <stdlib.h>
#include <stdio.h>

const unsigned char sbox[256] = 
{
  0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
  0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
  0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
  0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
  0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
  0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
  0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
  0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
  0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
  0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
  0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
  0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
  0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
  0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
  0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
  0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};


/////////////////////////////////////////////////////////////////////////////////
//KeyExpansion
//Rijndael's key scheduler as per http://www.samiam.org/key-schedule.html

unsigned char rcon(unsigned char in) {
  unsigned char c=1;
  if(in == 0)  
    return 0; 
  while(in != 1) {
    unsigned char b;
    b = c & 0x80;
    c <<= 1;
    if(b == 0x80) {
      c ^= 0x1b;
    }
    in--;
  }
  return c;
}

static void rotate(unsigned char *in) {
  unsigned char a,c;
  a = in[0];
  for(c=0;c<3;c++) 
    in[c] = in[c + 1];
  in[3] = a;
  return;
}

void schedule_core(unsigned char *in, unsigned char i) {
  char a;
  /* Rotate the input 8 bits to the left */
  rotate(in);
  /* Apply Rijndael's s-box on all 4 bytes */
  for(a = 0; a < 4; a++) 
    in[a] = sbox[in[a]];
  /* On just the first byte, add 2^i to the byte */
  in[0] ^= rcon(i);
}

void KeyExpansion(unsigned char *in) {
  unsigned char t[4];
  /* c is 16 because the first sub-key is the user-supplied key */
  unsigned char c = 16;
  unsigned char i = 1;
  unsigned char a;
  /* We need 11 sets of sixteen bytes each for 128-bit mode */
  while(c < 176) {
    /* Copy the temporary variable over from the last 4-byte
     * block */
    for(a = 0; a < 4; a++) 
      t[a] = in[a + c - 4];
    /* Every four blocks (of four bytes), 
     * do a complex calculation */
    if(c % 16 == 0) {
      schedule_core(t,i);
      i++;
    }
    for(a = 0; a < 4; a++) {
      in[c] = in[c - 16] ^ t[a];
      c++;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////
//ShiftRows
void ShiftRows(unsigned char *block){
  unsigned char shiftout0, shiftout1, shiftout2;
  //row 0 no shift
  //row 1 shift left 1
  shiftout0 = block[4];
  block[4]=block[5];
  block[5]=block[6];
  block[6]=block[7];
  block[7]=shiftout0;
  //row 2 shift left 2
  shiftout0 = block[8];
  shiftout1 = block[9];
  block[8] = block[10];
  block[9] = block[11];
  block[10] = shiftout0;
  block[11] = shiftout1;
  //row 3 shift left 3
  shiftout0 = block[12];
  shiftout1 = block[13];
  shiftout2 = block[14];
  block[12] = block[15];
  block[13] = shiftout0;
  block[14] = shiftout1;
  block[15] = shiftout2;
}

/////////////////////////////////////////////////////////////////////////////////
//Mix Columns
//Rijndael mix columns as per http://en.wikipedia.org/wiki/Rijndael_mix_columns
void gmix_column(unsigned char *r) {
  unsigned char a[4];
  unsigned char b[4];
  unsigned char c;
  unsigned char h;
  /* The array 'a' is simply a copy of the input array 'r'
   * The array 'b' is each element of the array 'a' multiplied by 2
   * in Rijndael's Galois field
   * a[n] ^ b[n] is element n multiplied by 3 in Rijndael's Galois field */ 
  for(c=0;c<4;c++) {
    a[c] = r[c];
    /* h is 0xff if the high bit of r[c] is set, 0 otherwise */
    h = (unsigned char)((signed char)r[c] >> 7); /* arithmetic right shift, thus shifting in either zeros or ones */
    b[c] = r[c] << 1; /* implicitly removes high bit because b[c] is an 8-bit char, so we xor by 0x1b and not 0x11b in the next line */
    b[c] ^= 0x1B & h; /* Rijndael's Galois field */
  }
  r[0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1]; /* 2 * a0 + a3 + a2 + 3 * a1 */
  r[1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2]; /* 2 * a1 + a0 + a3 + 3 * a2 */
  r[2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3]; /* 2 * a2 + a1 + a0 + 3 * a3 */
  r[3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0]; /* 2 * a3 + a2 + a1 + 3 * a0 */
}

void MixColumns(unsigned char *block){
  unsigned int j,i;
  unsigned char column[4];
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      column[j]=block[j*4+i];
    }
    gmix_column(column);
    for(j=0;j<4;j++){
      block[j*4+i]=column[j];
    }
  }
}


/////////////////////////////////////////////////////////////////////////////////
//AddRoundKey
void AddRoundKey(unsigned char *block,unsigned int round,unsigned char *roundkey){
  const int blocksize = 128/8;
  unsigned int j;
  for(j=0;j<blocksize;j++) block[j]=block[j] ^ roundkey[round*blocksize+j];
}
    

/////////////////////////////////////////////////////////////////////////////////
//Electronic Code Book AES encryption 
//aes_encrypt
//Return value 
// 0    Success
//-1    Inputsize is not a multiple of 128 bit AES block size
int aesecb_encrypt(unsigned char *key, unsigned char *input, unsigned char *output, size_t inputsize,const int rounds){

  const int blocksize = 128/8;

  //check input size is a multiple of 128 bit AES block size
  if((inputsize % blocksize) != 0 ) return -1;

  //KeyExpansion
  int i;
  unsigned char roundkey[(10+1) * blocksize];
  for(i=0;i<blocksize;i++) roundkey[i]=key[i];
  KeyExpansion(roundkey);

  //block loop
  size_t j,k;
  size_t blocks = inputsize / blocksize;
  unsigned char block[blocksize];
  for(i=0;i<blocks;i++){

    for(j=0;j<blocksize;j++) block[j]=input[i*blocksize+j];

    //InitialRound
    AddRoundKey(block,0,roundkey);
    //Rounds 
    for(j=0;j<rounds-1;j++){
      //SubBytes
      for(k=0;k<blocksize;k++) block[k]=sbox[block[k]];
      //ShiftRows
      ShiftRows(block);
      //MixColumns
      MixColumns(block);
      //AddRoundKey
      AddRoundKey(block,j+1,roundkey);
    }
    //FinalRound
    //SubBytes
    for(k=0;k<blocksize;k++) block[k]=sbox[block[k]];
    //ShiftRows
    ShiftRows(block);
    //AddRoundKey
    AddRoundKey(block,rounds,roundkey);

    for(j=0;j<blocksize;j++) output[i*blocksize+j]=block[j];
  }

}




