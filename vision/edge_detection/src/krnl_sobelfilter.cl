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

#define MAX_IMAGE_ROW_WIDTH 4096 

/*!
 * Input is a greyscaled image with 8 bits per pixel format
 * Output is the sobel image and in the same format as input
 * Optimize: pipelined and used async mem copy to minimize memory access
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_sobel(global unsigned char* in_pixels, int nchannels, int width, int height, global unsigned char* out_pixels)
{
    local uchar rowbuf0[MAX_IMAGE_ROW_WIDTH];
    local uchar rowbuf1[MAX_IMAGE_ROW_WIDTH];
    local uchar rowbuf2[MAX_IMAGE_ROW_WIDTH];
    local uchar resbuf[MAX_IMAGE_ROW_WIDTH];

	local uchar* prow0;
	local uchar* prow1;
	local uchar* prow2;    


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
	u16 sumx = 0;
	u16 sumy = 0;
    //const float threshold = 50.0f;
	float sum = 0;
    float ming = FLT_MAX;
    float maxg = FLT_MIN;

    //init resbuf
    for(int i=0; i < MAX_IMAGE_ROW_WIDTH; i++)
        resbuf[i] = 255;

    int szrow = width * nchannels;

    //init output
	for(int y=0; y < height; y++) {
        async_work_group_copy(&out_pixels[y * szrow], resbuf, szrow, 0);
        barrier(CLK_LOCAL_MEM_FENCE);
    }   


	//read first two lines
    async_work_group_copy(rowbuf0, in_pixels, szrow, 0);
    async_work_group_copy(rowbuf1, in_pixels + szrow, szrow, 0);
	prow0 = rowbuf0;
	prow1 = rowbuf1;

	//loop over height and width and compute min and max gradients
	for(int y=1; y < height - 1; y++) {

        // load 1 line only
        async_work_group_copy(rowbuf2, &in_pixels[ (y+1) * szrow ], szrow, 0);

        //sync all reads
        barrier(CLK_LOCAL_MEM_FENCE);
		prow2 = rowbuf2;        

        __attribute__ ((xcl_pipeline_loop))
		for(int x=1; x < width - 1; x++) {

			//reset for this pixel
			sumx = 0;
			sumy = 0;

			//approximate the gradients
			for(int i=-1; i<=1; i++) {
                sumx += GX[i+1][0] * prow0[x + i];                
                sumx += GX[i+1][1] * prow1[x + i];
                sumx += GX[i+1][2] * prow2[x + i];

                sumy += GY[i+1][0] * prow0[x + i];                
                sumy += GY[i+1][1] * prow1[x + i];
                sumy += GY[i+1][2] * prow2[x + i];
            }

            sum = sqrt((float)(sumx*sumx) + (float)(sumy*sumy));            
            if(sum > maxg) 
                maxg = sum;
            if(sum < ming)
                ming = sum;
		}


		//swap buffers
		prow0 = prow1;
		prow1 = prow2;
	}

    //printf("INFO: MIN VAL = %.2f MAX VAL = %.2f \n", ming, maxg);

	//read first two lines
    async_work_group_copy(rowbuf0, in_pixels, szrow, 0);
    async_work_group_copy(rowbuf1, in_pixels + szrow, szrow, 0);
	prow0 = rowbuf0;
	prow1 = rowbuf1;

	for(int y=1; y < height - 1; y++) {

        // load 1 line only
        async_work_group_copy(rowbuf2, &in_pixels[ (y+1) * szrow ], szrow, 0);

        //sync all reads
        barrier(CLK_LOCAL_MEM_FENCE);
		prow2 = rowbuf2;        

        __attribute__ ((xcl_pipeline_loop))
		for(int x=1; x < width - 1; x++) {

			//reset for this pixel
			sumx = 0;
			sumy = 0;

			//approximate the gradients
			for(int i=-1; i<=1; i++) {
                sumx += GX[i+1][0] * prow0[x + i];                
                sumx += GX[i+1][1] * prow1[x + i];
                sumx += GX[i+1][2] * prow2[x + i];

                sumy += GY[i+1][0] * prow0[x + i];                
                sumy += GY[i+1][1] * prow1[x + i];
                sumy += GY[i+1][2] * prow2[x + i];
            }


            sum = sqrt((float)(sumx*sumx) + (float)(sumy*sumy));
            
			//store
			u8 intensity = (u8)(255.0f * (sum -  ming) / (maxg - ming));
            resbuf[x] = 255 - intensity;
		}

        async_work_group_copy(&out_pixels[y * szrow], resbuf, szrow, 0);
        barrier(CLK_LOCAL_MEM_FENCE);

		//swap buffers
		prow0 = prow1;
		prow1 = prow2;
	}

}


