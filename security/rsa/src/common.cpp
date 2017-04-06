/**********
Copyright (c) 2017, Xilinx, Inc.
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

#include "common.h"

 uint64_t my_rdtsc()
{
 	uint32_t hi,lo;
	__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
	return (lo| ((uint64_t)hi)<<32);
}

void print_big_number(WORD_TYPE *n, int num_words, const char *name) {
  int i = 0;

  printf("%s = ", name);

  for (i = num_words - 1; i >= 0; i--) {
    printf("%08X", n[i]);
  }

 // printf("\n");
  printf("\n");
}

void pfn_notify(const char *errinfo, const void *private_info, size_t cb, void *user_data)
{
	fprintf(stderr, "OpenCL Error (via pfn_notify): %s\n", errinfo);
}

/***some utility functions****/
//convert file content to a c-style string
const char * convertToString(const char *filename)
 {
    size_t size;
    char*  str;
    const char *s;
    FILE *ifp;
    ifp = fopen(filename, "rb");

    if (ifp != NULL) {
       size_t fileSize;
       fseek(ifp, 0L, SEEK_END);
       size = fileSize = ftell(ifp);
       fseek(ifp, 0L, SEEK_SET);

       str = (char *) malloc((size+1)*sizeof(char));
       if(str == NULL)
       {
           fclose(ifp);
           return NULL;
       }
       fread(str, 1, fileSize, ifp);
       fclose(ifp);
       str[size] = '\0';
       s = str;

       return s;
   }
   return NULL;
}

int read_data(WORD_TYPE *c, const char *filename) {
  int j = 0;
  FILE *f;

  f = fopen(filename, "r");

  if (NULL == f) {
    printf("Error in opening file: %s\n", filename);
    return -1;
  }

  for (j = (NUM_WORDS*4-1); j >=0; j--) {
    *((unsigned char *)c + j) = fgetc(f);
  }

  fclose(f);
  return 0;
}

int output_data_to_file(const char *filename, WORD_TYPE *message) {
  int j = 0;
  FILE *f;

  f = fopen(filename, "w");

  if (NULL == f) {
    printf("Error in opening output file: %s\n", filename);
    return -1;
  }

  for (j = (NUM_WORDS*4-1); j >=0; j--) {
    fputc(*((char *)message + j), f);
  }

  fclose(f);
  return 0;
}

 // Reverses an array of chars. Length is in bytes.
// src and dst must be same length
void reverse_array(unsigned char* dst, unsigned char* src, int length){
  int i = 0;
  int j = length - 1;

  for (i = 0; i < length; i++) {
    dst[i] = src[j];
    j--;
  }
}

void print_usage(char *filename) {
    printf("\nUsage: This executable decrypts a file encrypted with an RSA %d key.\n\n", NUM_WORDS*32);
    printf("    %s [-i|--in] <in_file> [-o|--out] <out_file> [-k|--key] <key_file> [-b|--bench]\n", filename);
    printf("    where,\n");
    printf("        <in_file> - File containing input. Size should be %d bytes. The kind of file created by the -raw switch of OpenSSL.\n", NUM_WORDS*8);
    printf("        <out_file> - File that will contain the decrypted output. Size will be %d bytes.\n", NUM_WORDS*8);
    printf("        <key_file> - File containing the key in PEM format. These can be generated using OpenSSL.\n");
    printf("    All file arguments are required. Use -h or --help to see this message.\n");
}

uint mod_mul(uint x, uint y, uint m)
{
   return (uint)(((ulong)x*(ulong)y)% ((ulong)m));
  
}

uint mod_add(uint x, uint y, uint m)

{
	return (uint)(((ulong)x+(ulong)y)% ((ulong)m));
}

uint mod_subtract(uint x, uint y, uint m)

{
	if(x>y)
	return (uint)(((ulong)x-(ulong)y)% ((ulong)m));
	else
        return (uint)(((ulong)x+(ulong)m-(ulong)y)% ((ulong)m));
}

