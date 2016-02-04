/*******************************************************************************
Vendor: Xilinx
Associated Filename: sobel_cpuonly.cpp
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

#include <vector>
#include <cstdlib>
#include "sobel_cpuonly.h"
#include "simplebmp.h"
#include "logger.h"

//BGR
#define BLUE_COMP 0
#define GREEN_COMP 1
#define RED_COMP 2

Sobel::Sobel() {
	// TODO Auto-generated constructor stub

}

Sobel::~Sobel() {
	// TODO Auto-generated destructor stub
}

bool Sobel::apply(const string& input, const string& output) {
	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)input.c_str(), &inputbmp);
	if (err != 0) {
		LogError("failed to read input [%s]", input.c_str());
		return false;
	}

	int nchannels = (inputbmp.header.dibdepth >> 3);
	size_t inputbmpsize = inputbmp.height * inputbmp.width * nchannels;

	struct bmp_t outputbmp;
	outputbmp.pixels = (uint32_t *) malloc(inputbmpsize);
	outputbmp.width = inputbmp.width;
	outputbmp.height = inputbmp.height;
	if (outputbmp.pixels == NULL) {
		LogError("Failed to allocate memory for output.bmp");
		return false;
	}

	bool bres = apply(reinterpret_cast<u8*>(inputbmp.pixels), nchannels, inputbmp.width, inputbmp.height, (u8*)outputbmp.pixels);

	//store
	err = writebmp(const_cast<char*>(output.c_str()), &outputbmp);
	if (err != 0) {
		LogError("failed to write output [%s]", output.c_str());
		bres = false;
	}

	return bres;
}


//bool Sobel::convert_to_packed_rgba(const u8* in_pixels, u8 nchannels, int width, int height, u32* out_packed) {
//
//}

u32 Sobel::pack_from_bgr_to_rgba(const u8* in_pixels) {

	//convert from 24 bits BGR to packed 32 bits RGBA
	u32 pixel = 0;

	//r
	pixel = in_pixels[RED_COMP];
	pixel = pixel << 8;

	//g
	pixel = pixel | (in_pixels[GREEN_COMP]);
	pixel = pixel << 8;

	//b
	pixel = pixel | (in_pixels[BLUE_COMP]);
	pixel = pixel << 8;

	//alpha = full
	pixel = pixel | 0xFF;

	return pixel;
}

void Sobel::unpack_from_rgba_to_bgr(u32 rgba, u8* out_pixels) {

	rgba = rgba >> 8;

	//b
	out_pixels[BLUE_COMP] = (u8)(rgba & 0xFF);
	rgba = rgba >> 8;

	//g
	out_pixels[GREEN_COMP] = (u8)(rgba & 0xFF);
	rgba = rgba >> 8;

	//r
	out_pixels[RED_COMP] = (u8)(rgba & 0xFF);
}


bool Sobel::apply(const u8* in_pixels, u8 nchannels, int width, int height, u8* out_pixels) {

	//GX MASK ROW [1] = -1,  0,  1
	//GX MASK ROW [2] = -2,  0,  2
	//GX MASK ROW [3] = -1,  0,  1
	//GY MASK ROW [1] = -1, -2, -1
	//GY MASK ROW [2] =  0,  0,  0
	//GY MASK ROW [3] =  1,  2,  1
	int GX[3][3] = {
			{-1, 0, 1},
			{-2, 0, 2},
			{-1, 0, 1}
	};

	int GY[3][3] = {
			{-1, -2, -1},
			{ 0, 0, 0},
			{ 1,  2,  1}
	};

	//internal frame format is:
	//1- BGR pixels
	//2- lower-left corner is origin

	int sum = 0;
	int sumx = 0;
	int sumy = 0;

	//loop over height and width
	for(int y=0; y < height; y++) {
		for(int x=0; x < width; x++) {

			//reset for this pixel
			sumx = 0;
			sumy = 0;

			//u32 rgba = pack_from_bgr_to_rgba(&in_pixels[current]);

			//check boundaries
			if(x == 0 || x == width - 1)
				sum = 0;
			else if(y == 0 || y == height - 1)
				sum = 0;
			else
			{
				//approximate the X gradient
				for(int i=-1; i<=1; i++) {
					for(int j=-1; j<=1; j++) {
						//use i offset for x
						//use j offset for y
						int dx = (x + i + (y + j) * width) * nchannels;
						u32 pdx = pack_from_bgr_to_rgba(&in_pixels[dx]);

						//perform convolution
						sumx += GX[i + 1][j + 1] * pdx;
					}
				}


				//approximate the Y gradient
				for(int i=-1; i<=1; i++) {
					for(int j=-1; j<=1; j++) {
						//use i offset for x
						//use j offset for y
						int dy = (x + i + (y + j) * width) * nchannels;
						u32 pdy = pack_from_bgr_to_rgba(&in_pixels[dy]);

						//perform convolution
						sumy += GY[i + 1][j + 1] * pdy;
					}
				}

				//sum
				sum = abs(sumx) + abs(sumy);

				//clamp
				if(sum > 255)
					sum = 255;
				if(sum < 0)
					sum = 0;
			}

			//store
			int current = (x + y * width) * nchannels;
			out_pixels[current] = 255 - (u8)(sum);
			out_pixels[current+1] = 255 - (u8)(sum);
			out_pixels[current+2] = 255 - (u8)(sum);
		}
	}

	return true;
}

