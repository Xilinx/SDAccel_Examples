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

#include "edge.h"

typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;

#define FILTER_WIDTH (3)
#define FILTER_HEIGHT (3)

#define B (64)
#define M(x) (((x)-1)/(B) + 1)
#define REG_WIDTH (M(FILTER_WIDTH+B-1)*B)

#if(B == 64)
typedef uint16 bus_t;
#elif(B == 32)
typedef uint8 bus_t;
#elif(B == 16)
typedef uint4 bus_t;
#elif(B == 8)
typedef uint2 bus_t;
#elif(B == 4)
typedef uint bus_t;
#elif(B == 2)
typedef u16 bus_t;
#elif(B == 1)
typedef u8 bus_t;
#endif

typedef union {
	bus_t b;
	u8 a[B];
} bus_to_u8_t;

void bus_to_u8(bus_t in, u8 out[B]) {
	bus_to_u8_t val;

	val.b = in;

	for(size_t i = 0; i < B; i++) {
		out[i] = val.a[i];
	}
}

bus_t u8_to_bus(u8 in[B]) {
	bus_to_u8_t val;

	for(size_t i = 0; i < B; i++) {
		val.a[i] = in[i];
	}

	return val.b;
}

/*
 * Input is a greyscaled image with 8 bits per pixel format
 * Output is the sobel image and in the same format as input
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_sobel(global bus_t* in_pixels, global bus_t* out_pixels) {
	/* Pad registers to align line_buf read/write */
	u8 line_reg[FILTER_HEIGHT][REG_WIDTH]
	      __attribute__((xcl_array_partition(complete,1)))
	      __attribute__((xcl_array_partition(complete,2)));
	/* Line buffers to store values */
	u8 line_buf[FILTER_HEIGHT-1][M(IMAGE_WIDTH-REG_WIDTH)*B]
	      __attribute__((xcl_array_partition(complete, 1)))
	      __attribute__((xcl_array_partition(cyclic, B, 2)));

#if (FILTER_HEIGHT == 3) && (FILTER_WIDTH == 3)
	s8 const GX[3*3] __attribute__((xcl_array_partition(complete,0))) = {
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1
	};

	s8 const GY[3*3] __attribute__((xcl_array_partition(complete,0))) = {
		 1, 2, 1,
		 0, 0, 0,
		-1,-2,-1
	};
#endif

	// loop over height and width and compute min and max gradients
	__attribute__((xcl_pipeline_loop))
	for(size_t y=0; y < M(IMAGE_HEIGHT*IMAGE_WIDTH); y++) {
		u8 input_buf[B];

		/* Read pixels from the input image */
		bus_to_u8(in_pixels[y], input_buf);

		/* Rotate Buffers */
		for(size_t i = 0; i < FILTER_HEIGHT-1; i++) {
			/* Move the line reg B pixels at a time */
			for(size_t x = 0; x < REG_WIDTH - B; x++) {
				line_reg[i][x] = line_reg[i][x+B];
			}
			/* Add values from line_buf to end of regs */
			for(size_t j = 0; j < B; j++) {
				line_reg[i][(REG_WIDTH - B) + j] = line_buf[i][j + B*(y % (M(IMAGE_WIDTH-REG_WIDTH)))];
			}
			/* Write values from the start of the next line to the line_buf */
			for(size_t j = 0; j < B; j++) {
				line_buf[i][j + B*(y % (M(IMAGE_WIDTH-REG_WIDTH)))] = line_reg[i+1][j];
			}
		}
		/* On last line rotate regs */
		for(size_t x = 0; x < ((M(FILTER_WIDTH+B)-1)*B); x++) {
			line_reg[FILTER_HEIGHT-1][x] = line_reg[FILTER_HEIGHT-1][x+B];
		}
		/* Add the new input data to the end */
		for(size_t j = 0; j < B; j++) {
			line_reg[FILTER_HEIGHT-1][(REG_WIDTH - B) + j] = input_buf[j];
		}

		u8 resbuf[B];

		for(size_t x=0;x<B;x++){
			s16 sumx = 0;
			s16 sumy = 0;

			// Convolution of GX and GY
			for(size_t k = 0; k < FILTER_HEIGHT; k++) {
				for(size_t l = 0; l < FILTER_WIDTH; l++) {
					const size_t offset = REG_WIDTH - FILTER_WIDTH - B + 1;
					u8 val = line_reg[k][offset + l + x];

					sumx  += (s16) GX[k*FILTER_WIDTH + l] * (s16) val;
					sumy  += (s16) GY[k*FILTER_WIDTH + l] * (s16) val;
				}
			}
			
			// Absolute Value
			u16 asumx = (sumx >= 0) ? sumx : -sumx;
			u16 asumy = (sumy >= 0) ? sumy : -sumy;

			// Sum of Absolute Values
			u16 sum = asumx + asumy;

			u8 res;
			// Clamp on max
			if(sum > 0xFF) {
				res = 0xFF;
			} else {
				res = (u8) sum;
			}

			resbuf[x] = res;
		}

		out_pixels[y] = u8_to_bus(resbuf);
	}
}

