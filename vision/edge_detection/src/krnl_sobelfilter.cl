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


//#define MAX_IMAGE_ROW_WIDTH 4096 
//fixed image width height
#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 1895
//#define nchannels 1
//#define szrow width * nchannels
#define FILTER_WIDTH 3
#define FILTER_HEIGHT 3
#define B (16)
#define M(x) (((x)-1)/(B) + 1)
#define REG_WIDTH (M(FILTER_WIDTH+B-1)*B)

#if(B == 32)
typedef uint8 bus_t;
#elif(B == 16)
typedef uint4 bus_t;
#elif(B == 8)
typedef uint2 bus_t;
#elif(B == 4)
typedef uint bus_t;
#endif

typedef union {
	bus_t b;
	uchar s[B];
} bus_to_char_t;

void bus_to_char(bus_t in, uchar out[B]) {
	bus_to_char_t val;

	val.b = in;

	for(int i = 0; i < B; i++) {
		out[i] = val.s[i];
	}
}

bus_t char_to_bus(uchar in[B]) {
	bus_to_char_t val;

	for(int i = 0; i < B; i++) {
		val.s[i] = in[i];
	}

	return val.b;
}


/*!
 * Input is a greyscaled image with 8 bits per pixel format
 * Output is the sobel image and in the same format as input
 * Optimize: pipelined and used async mem copy to minimize memory access
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_sobel(global bus_t* in_pixels, global bus_t* out_pixels)
{
	
    /* Pad registers to align line_buf read/write */
	short line_reg[FILTER_HEIGHT][REG_WIDTH]
		__attribute__((xcl_array_partition(complete,1)))
		__attribute__((xcl_array_partition(complete,2)));
	/* Line buffers to store values */
	short line_buf[FILTER_HEIGHT-1][M(IMAGE_WIDTH-REG_WIDTH)*B]
		__attribute__((xcl_array_partition(complete, 1)))
		__attribute__((xcl_array_partition(cyclic, B, 2)));


	//original sobel weights
	int GX[3][3] = {
			{-1, 0, 1},
			{-2, 0, 2},
			{-1, 0, 1}
	};

	int GY[3][3] = {
			{1, 2, 1},
			{ 0, 0, 0},
			{ -1,  -2,  -1}
};



	//internal frame format is:
	//1- greyscale 8 bits per pixel
    //const float threshold = 50.0f;
    	
    	float ming = FLT_MAX;
	float maxg = FLT_MIN;

    //init resbuf
   /*for(int i=0; i < IMAGE_WIDTH; i++)
	resbuf[i] = 255;
 */

	//loop over height and width and compute min and max gradients
	__attribute__((xcl_pipeline_loop))
	for(int y=0; y < M(IMAGE_HEIGHT*IMAGE_WIDTH); y++) {
                 uchar input_buf[B];

		/* Read pixels from the input image */
		bus_to_char(in_pixels[y], input_buf);

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

   	for(size_t x=0;x<B;x++){
			u16 sumx = 0;
                        u16 sumy = 0;

			//approximate the gradients
		for(size_t k = 0; k < FILTER_HEIGHT; k++) {
				for(size_t l = 0; l < FILTER_WIDTH; l++) {
					const size_t offset = REG_WIDTH - FILTER_WIDTH - B + 1;
					short val = line_reg[k][offset + l + x];

					sumx  += (u16) GX[k*FILTER_WIDTH + l] * (u16) val;
				        sumy  += (u16) GY[k*FILTER_WIDTH + l] * (u16) val;
		} }

           float sum = native_sqrt((float)(sumx*sumx) + (float)(sumy*sumy)); 
            
            if(sum > maxg)
                maxg = sum;
            if(sum < ming)
                ming = sum;
   	}
	}

        __attribute__((xcl_pipeline_loop))
	for(int y=0; y < M(IMAGE_WIDTH*IMAGE_HEIGHT); y++) {
	 uchar input_buf[B];

		/* Read pixels from the input image */
		bus_to_char(in_pixels[y], input_buf);

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
			
       uchar resbuf[B];

       for(size_t x=0;x<B;x++){
			//reset for this pixel
			u16 sumx = 0;
			u16 sumy = 0;
			for(size_t k = 0; k < FILTER_HEIGHT; k++) {
				for(size_t l = 0; l < FILTER_WIDTH; l++) {
					const size_t offset = REG_WIDTH - FILTER_WIDTH - B + 1;
					short val = line_reg[k][offset + l + x];

					sumx += (u16) GX[k*FILTER_WIDTH + l] * (u16) val;
					sumy += (u16) GY[k*FILTER_WIDTH + l] * (u16) val;
					 
		}
				
			}

           float sum = native_sqrt((float)(sumx*sumx) + (float)(sumy*sumy));
			//store
	  u8 intensity = (u8)(255.0f * (sum -  ming) / (maxg - ming));
          resbuf[x] = 255 - intensity;
       }

    		out_pixels[y] = char_to_bus(resbuf);
	}

}
