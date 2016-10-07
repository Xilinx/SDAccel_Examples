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
#include <vector>
#include <cstdlib>
#include <float.h>
#include <math.h>
#include "sobel_cpuonly.h"
#include "simplebmp.h"
#include "logger.h"
#include "lodepng.h"

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

    //convert to grayscale image
    size_t szGrayImage = inputbmp.width * inputbmp.height;
	size_t szColorImage = szGrayImage * nchannels;

    //color to gray    
    vector<unsigned char> vGreyImage;
    vGreyImage.resize(szGrayImage);
    std::fill(vGreyImage.begin(), vGreyImage.end(), 0);

    unsigned char* pbuf = reinterpret_cast<unsigned char*>(inputbmp.pixels);

    for(int j=0; j < inputbmp.height; j++) {
        for(int i=0; i < inputbmp.width; i++) {
            
            size_t pixel_index = j * inputbmp.width + i;
            unsigned char* pd = &pbuf[pixel_index * nchannels];
            
            
            //BGR to grayscale
            vGreyImage[pixel_index] = sqrt((pd[0] * pd[0] + pd[1] * pd[1] + pd[2] * pd[2]) / 3.0);            
        }
    }	

    vector<unsigned char> vSobelImage;
    vSobelImage.resize(szGrayImage);

	bool bres = apply(vGreyImage.data(), 1, inputbmp.width, inputbmp.height, vSobelImage.data());

	//store
    string strGreyFP = input + "_cpu_grey.png";
    int error = lodepng::encode(strGreyFP.c_str(), vGreyImage.data(), inputbmp.width, inputbmp.height, LCT_GREY, 8);
	if (error != 0) {
		LogError("failed to write grey image [%s]", strGreyFP.c_str());
		return false;
	}

    error = lodepng::encode(output.c_str(), vSobelImage.data(), inputbmp.width, inputbmp.height, LCT_GREY, 8);
	if (error != 0) {
		LogError("failed to write grey image [%s]", output.c_str());
		return false;
	}

	return bres;
}


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

    printf("INFO: MIN VAL = %.2f MAX VAL = %.2f \n", ming, maxg);

   
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

	return true;
}

