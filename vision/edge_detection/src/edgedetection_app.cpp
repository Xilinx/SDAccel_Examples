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

#include <algorithm>
#include <assert.h>
#include "edgedetection_app.h"
#include "simplebmp.h"
#include "lodepng.h"
#include "logger.h"

using namespace sda;


#if defined(__linux__) || defined(linux)
	#include "sys/time.h"
#elif defined(WIN32)
	#include "windows.h"
#endif


/////////////////////////////////////////////////////////////////////////////////
static double timestamp() {
	double ms = 0.0;
	#if  defined(__linux__) || defined(linux)
		timeval time;
		gettimeofday(&time, NULL);
		ms = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
	#elif defined(WIN32)
		SYSTEMTIME time;
		GetSystemTime(&time);
		ms = (time.wSeconds * 1000) + time.wMilliseconds;
	#endif
	return ms;
}

static double computeEventDurationInMS(const cl_event& event) {
	cl_ulong ts_start = 0, ts_end = 0;
	double duration = 0;
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &ts_start, NULL);
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &ts_end, NULL);
	duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

	return duration;
}

EdgeDetectFilter::EdgeDetectFilter(const string& vendor_name,
		   const string& device_name,
		   int selected_device,
		   const string& strKernelFP) {

	//list available platforms
	xcl_list_platforms();

	//list available devices
	if(xcl_list_devices(vendor_name.c_str()) > 0) {

		//get device by name
		assert(xcl_world_vendor_devtype(vendor_name.c_str(), CL_DEVICE_TYPE_ACCELERATOR, m_world));
	}

	//kernels
    m_clKrnlSobel  = xcl_import_binary(m_world, strKernelFP.c_str(), "krnl_sobel");
    //m_clKrnlGreyScale = xcl_import_binary(m_world, strKernelFP.c_str(), "krnl_greyscale");
}


EdgeDetectFilter::~EdgeDetectFilter() {
	// TODO Auto-generated destructor stub
	clReleaseKernel(m_clKrnlSobel);
	//clReleaseKernel(m_clKrnlGreyScale);	
	xcl_release_world(m_world);
}

bool EdgeDetectFilter::run(const string& strInput, string& strOutput) {
	int error;
	struct bmp_t inputbmp;
	error = readbmp((char*)strInput.c_str(), &inputbmp);
	if (error != 0) {
		LogError("failed to read input [%s]", strInput.c_str());
		return false;
	}

	int nchannels = (inputbmp.header.dibdepth >> 3);
    //convert to grayscale image
        size_t szGreyImage = inputbmp.width * inputbmp.height;
	size_t szColorImage = szGreyImage * nchannels;
	std::cout << "nchannels is : " << nchannels << " width is " << inputbmp.width << "height is "<< inputbmp.height<< std::endl;
    vector<unsigned char> vGreyImage;
    vGreyImage.resize(szGreyImage);

    unsigned char* pbuf = reinterpret_cast<unsigned char*>(inputbmp.pixels);
    for(int j=0; j < inputbmp.height; j++) {
        for(int i=0; i < inputbmp.width; i++) {
            
            size_t pixel_index = j * inputbmp.width + i;
            unsigned char* pd = &pbuf[pixel_index * nchannels];
            
            
            //BGR to grayscale
            vGreyImage[pixel_index] = sqrt((pd[0] * pd[0] + pd[1] * pd[1] + pd[2] * pd[2]) / 3.0);            
        }
    }	

 
	//void krnl_sobel(global u8* in_pixels, int nchannels, int width, int height, global u8* out_pixels)
	//cl_mem buffer_in_rgba = xcl_malloc(m_world, CL_MEM_READ_ONLY, szColorImage);
	cl_mem buffer_in_grey = xcl_malloc(m_world, CL_MEM_READ_ONLY, szGreyImage);
	cl_mem buffer_out_sobel = xcl_malloc(m_world, CL_MEM_WRITE_ONLY, szGreyImage);

	xcl_memcpy_to_device(m_world, buffer_in_grey, &vGreyImage[0], szGreyImage);

	//execute kernel: sobel
    nchannels = 1;
    
    clSetKernelArg(m_clKrnlSobel, 0, sizeof(cl_mem), &buffer_in_grey);
    //clSetKernelArg(m_clKrnlSobel, 1, sizeof(int), &nchannels);
    //clSetKernelArg(m_clKrnlSobel, 2, sizeof(int), &inputbmp.width);
    //clSetKernelArg(m_clKrnlSobel, 3, sizeof(int), &inputbmp.height);
    clSetKernelArg(m_clKrnlSobel, 1, sizeof(cl_mem), &buffer_out_sobel);

    //Launch the kernel
    unsigned long duration = xcl_run_kernel3d(m_world, m_clKrnlSobel, 1, 1, 1);
    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;
    
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//readback grey image    
    //xcl_memcpy_from_device(m_world, vGreyImage.data(), buffer_inout_grey, szGreyImage);

	string strGreyFP = strInput + "grey.png";	
    error = lodepng::encode(strGreyFP.c_str(), vGreyImage.data(), inputbmp.width, inputbmp.height, LCT_GREY, 8);
	if (error != 0) {
		LogError("failed to write grey image [%s]", strGreyFP.c_str());
		return false;
	}

    //readback sobel image
    vector<unsigned char> vSobelImage;
    vSobelImage.resize(szGreyImage);
    xcl_memcpy_from_device(m_world, vSobelImage.data(), buffer_out_sobel, szGreyImage);

    error = lodepng::encode(strOutput.c_str(), vSobelImage.data(), inputbmp.width, inputbmp.height, LCT_GREY, 8);
	if (error != 0) {
		LogError("failed to write output [%s]", strOutput.c_str());
		return false;
	}

    //release all mem buffers
    //clReleaseMemObject(buffer_in_rgba);
	clReleaseMemObject(buffer_in_grey);    
	clReleaseMemObject(buffer_out_sobel);

	//cleanup
	vSobelImage.resize(0);
	vGreyImage.resize(0);
    
	//perf results
	//LogInfo("Kernel exec duration: [%.8f]", duration);

	return true;
}
