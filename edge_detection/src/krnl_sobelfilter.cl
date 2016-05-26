/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_sobelfilter.cl
Purpose: SDAccel edge detection example
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
 * Input is a greyscaled image with 8 bits per pixel format
 * Output is the sobel image and in the same format as input
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_sobel(global unsigned char* in_pixels, int nchannels, int width, int height, global unsigned char* out_pixels)
{

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
	float sum = 0;
    float ming = FLT_MAX;
    float maxg = FLT_MIN;

    //reset output to zero
	for(int y=0; y < height; y++) {
		for(int x=0; x < width; x++) {
			int current = (x + y * width) * nchannels;
			out_pixels[current] = 255;
        }
    }   

	//loop over height and width and compute min and max gradients
	for(int y=1; y < height - 1; y++) {
		for(int x=1; x < width - 1; x++) {

			//reset for this pixel
			sumx = 0;
			sumy = 0;

			//approximate the X gradient
			for(int i=-1; i<=1; i++) {
				for(int j=-1; j<=1; j++) {

					//use j offset for y
					//use i offset for x
					int dx = (x + i + (y + j) * width) * nchannels;
					u8 pdx = in_pixels[dx];

					//perform convolution
					sumx += GX[i+1][j+1] * pdx;
					sumy += GY[i+1][j+1] * pdx;
				}
			}

            sum = sqrt((float)(sumx*sumx) + (float)(sumy*sumy));            
            if(sum > maxg) 
                maxg = sum;
            if(sum < ming)
                ming = sum;
		}
	}

    //printf("INFO: MIN VAL = %.2f MAX VAL = %.2f \n", ming, maxg);
	for(int y=1; y < height - 1; y++) {
		for(int x=1; x < width - 1; x++) {

			//reset for this pixel
			sumx = 0;
			sumy = 0;

			//approximate the X gradient
			for(int j=-1; j<=1; j++) {
			    for(int i=-1; i<=1; i++) {
					//use j offset for y
					//use i offset for x
					int dx = (x + i + (y + j) * width) * nchannels;
					u8 pdx = in_pixels[dx];

					//perform convolution
					sumx += GX[i+1][j+1] * pdx;
				    sumy += GY[i+1][j+1] * pdx;
				}
			}

            sum = sqrt((float)(sumx*sumx) + (float)(sumy*sumy));
            
			//store
			int current = (x + y * width) * nchannels;
			u8 intensity = (u8)(255.0f * (sum -  ming) / (maxg - ming));
			out_pixels[current] = 255 - intensity;

		}
	}

}


