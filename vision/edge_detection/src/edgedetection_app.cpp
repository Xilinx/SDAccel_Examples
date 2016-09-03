/*******************************************************************************
Vendor: Xilinx
Associated Filename: edgedetection_app.cpp
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
       std::cout << "nchannels is : " << nchannels << " width is " << inputbmp.width << "height is "<< inputbmp.height<< std::endl;
    //convert to grayscale image
    size_t szGreyImage = inputbmp.width * inputbmp.height;
	size_t szColorImage = szGreyImage * nchannels;
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

	/*
	//copy input to device
    xcl_memcpy_to_device(m_world, buffer_in_rgba, pbuf, szColorImage);

	//execute kernel: greyscale
    clSetKernelArg(m_clKrnlGreyScale, 0, sizeof(cl_mem), &buffer_in_rgba);
    clSetKernelArg(m_clKrnlGreyScale, 1, sizeof(int), &nchannels);
    clSetKernelArg(m_clKrnlGreyScale, 2, sizeof(int), &inputbmp.width);
    clSetKernelArg(m_clKrnlGreyScale, 3, sizeof(int), &inputbmp.height);
    clSetKernelArg(m_clKrnlGreyScale, 4, sizeof(cl_mem), &buffer_inout_grey);

    //Launch the kernel
    unsigned long duration = xcl_run_kernel3d(m_world, m_clKrnlGreyScale, 1, 1, 1);
	*/

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
