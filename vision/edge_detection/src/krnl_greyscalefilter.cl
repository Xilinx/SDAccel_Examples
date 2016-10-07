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
#ifdef __ECLIPSE__
#define kernel
#define global
#define __constant
#endif

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef			 char		i8;
typedef			 short		i16;
typedef			 int		i32;

/*!
 * Input is an RGBA image with 24 or 32 bits per pixel format
 * Output is the greyscale image with 8 bits per pixel
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_greyscale(global unsigned char* in_pixels, int nchannels, int width, int height, global unsigned char* out_pixels)
{
	#ifdef __xilinx__
		__attribute__((xcl_pipeline_loop))
	#endif
	for(int y=0; y < height; y++) {
		for(int x=0; x < width; x++) {
			int current = (x + y * width) * nchannels;
			
			u32 intensity = 0; 			
			for(int k=0; k < nchannels; k++)
				intensity += (in_pixels[current + k] * in_pixels[current + k]);

			out_pixels[current] = (u8)sqrt((float)intensity / (float)nchannels);
        }
    }   

}
