/*
 * EdgeDetectionApp.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: pouryas
 */

#include <assert.h>
#include "edgedetection_app.h"
#include "simplebmp.h"
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
}


EdgeDetectFilter::~EdgeDetectFilter() {
	// TODO Auto-generated destructor stub
	clReleaseKernel(m_clKrnlSobel);
	xcl_release_world(m_world);
}


bool EdgeDetectFilter::run(const string& strInput, string& strOutput) {
	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)strInput.c_str(), &inputbmp);
	if (err != 0) {
		LogError("failed to read input [%s]", strInput.c_str());
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


	//void krnl_sobel(global u8* in_pixels, int nchannels, int width, int height, global u8* out_pixels)
	cl_mem buffer_inpixels = xcl_malloc(m_world, CL_MEM_READ_ONLY, inputbmpsize);
	cl_mem buffer_outpixels = xcl_malloc(m_world, CL_MEM_WRITE_ONLY, inputbmpsize);

	//copy input to device
    xcl_memcpy_to_device(m_world, buffer_inpixels, inputbmp.pixels, inputbmpsize);

	//bool bres = apply(reinterpret_cast<u8*>(inputbmp.pixels), nchannels, inputbmp.width, inputbmp.height, (u8*)outputbmp.pixels);
    clSetKernelArg(m_clKrnlSobel, 0, sizeof(cl_mem), &buffer_inpixels);
    clSetKernelArg(m_clKrnlSobel, 1, sizeof(int), &nchannels);
    clSetKernelArg(m_clKrnlSobel, 2, sizeof(int), &inputbmp.width);
    clSetKernelArg(m_clKrnlSobel, 3, sizeof(int), &inputbmp.height);
    clSetKernelArg(m_clKrnlSobel, 4, sizeof(cl_mem), &buffer_outpixels);

    //Launch the kernel
    unsigned long duration = xcl_run_kernel3d(m_world, m_clKrnlSobel, 1, 1, 1);

    //Copy result to local buffer
    xcl_memcpy_from_device(m_world, outputbmp.pixels, buffer_outpixels, inputbmpsize);

    //release all mem buffers
    clReleaseMemObject(buffer_inpixels);
    clReleaseMemObject(buffer_outpixels);


	//store
	err = writebmp(const_cast<char*>(strOutput.c_str()), &outputbmp);
	if (err != 0) {
		LogError("failed to write output [%s]", strOutput.c_str());
		return false;
	}


	//cleanup
	free(outputbmp.pixels);

	//perf results
	LogInfo("Kernel exec duration: [%.2f]", duration);


	return true;
}
