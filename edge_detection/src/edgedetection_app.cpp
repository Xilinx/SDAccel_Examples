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
}


//bool EdgeDetectFilter::run(int idevice, int nruns) {
//
//}

bool EdgeDetectFilter::run(const string& strInput, string& strOutput) {
	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)strInput.c_str(), &inputbmp);
	if (err != 0) {
		LogError("failed to read imput.bmp");
		return false;
	}
	size_t inputbmpsize = inputbmp.height * inputbmp.width * 3;

	return false;
}
