/*******************************************************************************
Vendor: Xilinx
Associated Filename: aes_app.cpp
Purpose: AES Decrypt SDAccel Application Example
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

#include <assert.h>
#include <string.h>

#include "logger.h"
#include "aes_app.h"
#include "aes_ecb.h"

#include "simplebmp.h"

#if defined(__linux__) || defined(linux)
	#include "sys/time.h"
#elif defined(WIN32)
	#include "windows.h"
#endif

#define ROUNDS 10
//ROUNDS <= 10 valid

using namespace sda::cl;

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

/////////////////////////////////////////////////////////////////////////////////
AesApp::AesApp(const string& vendor_name,
			   const string& device_name,
			   int selected_device,
			   const string& strKernelFP,
			   const string& strBitmapFP) {

	//list available platforms
	xcl_list_platforms();

	//list available devices
	if(xcl_list_devices(vendor_name.c_str()) > 0) {

		//get device by name
		assert(xcl_world_vendor_devtype(vendor_name.c_str(), CL_DEVICE_TYPE_ACCELERATOR, m_world));
	}

	m_clKernelAesDecrypt = xcl_import_binary(m_world, strKernelFP.c_str(), "krnl_aes_decrypt");

	//store path to bitmap
	m_strBitmapFP = strBitmapFP;
}

AesApp::~AesApp() {
	// TODO Auto-generated destructor stub
	cleanup();
}

void AesApp::cleanup() {

	clReleaseKernel(m_clKernelAesDecrypt);
	xcl_release_world(m_world);
}

bool AesApp::run(int idevice, int nruns) {
	if (nruns <= 0)
		return false;

//	size_t local[] = { 1 };
//	size_t global[] = { m_nPoints };
//
//	if (m_full_device_names[0] == "fpga0") {
//		LogInfo("Set local workgroup size to %d for fpga", m_nPoints);
//		local[0] = m_nPoints;
//	}


	//load "input.bmp"
	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)m_strBitmapFP.c_str(), &inputbmp);
	if (err != 0) {
		printf("Error : failed to read imput.bmp\n");
		return false;
	}
	size_t inputbmpsize = inputbmp.height * inputbmp.width * 3;

	//AES ECB encryption in software
	//encrypted image setup
	struct bmp_t swencryptbmp;
	swencryptbmp.pixels = (uint32_t *) malloc(inputbmpsize);
	swencryptbmp.width = inputbmp.width;
	swencryptbmp.height = inputbmp.height;
	if (swencryptbmp.pixels == NULL) {
		printf(
				"Error : failed to allocate memory for sw encrypted swencrypted.bmp\n");
		return false;
	}

	//128 bit encryption key
	unsigned char key[] = "Xilinx SDAccel  ";

	//perform SW encryption
	//Xilinx
	aesecb_encrypt(key, ((unsigned char *) inputbmp.pixels),
			((unsigned char *) swencryptbmp.pixels), inputbmpsize, ROUNDS);
	//write "swencrypted.bmp"
	char swencryptbmpfile[] = "swencrypt.bmp";
	writebmp(swencryptbmpfile, &swencryptbmp);

	//AES ECB decryption in hardware
	//decrypted image setup
	struct bmp_t hwdecryptbmp;
	hwdecryptbmp.pixels = (uint32_t *) malloc(inputbmpsize);
	hwdecryptbmp.width = inputbmp.width;
	hwdecryptbmp.height = inputbmp.height;
	if (hwdecryptbmp.pixels == NULL) {
		printf("Error : failed to allocate memory for sw encrypted hwdecrypted.bmp\n");
		return false;
	}

	//start
	double startMS = timestamp();

	unsigned int datasetsize = inputbmpsize;

	//create input and output buffers size for 24 bpp image
	cl_mem input_buffer;
	input_buffer = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, datasetsize,
			NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Error: Failed to allocate OpenCL source buffer of size %lu",
				inputbmpsize);
		return false;
	}

	cl_mem roundkey_buffer;
	roundkey_buffer = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE,
			(ROUNDS + 1) * 16, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Error: Failed to allocate OpenCL source buffer of size %lu",
				inputbmpsize);
		return false;
	}

	cl_mem output_buffer;
	output_buffer = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, datasetsize,
			NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu",
				inputbmpsize);
		return false;
	}

	//compute expanded roundkey
	unsigned char roundkey[(10 + 1) * 16];
	strcpy(((char *) roundkey), ((char *) key));
	KeyExpansion(roundkey);

	//copy input dataset to OpenCL buffer
	err = clEnqueueWriteBuffer(m_world.command_queue, input_buffer, CL_TRUE, 0,
			inputbmpsize, swencryptbmp.pixels, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to copy input dataset to OpenCL buffer");
		LogError("Test failed");
		return false;
	}

	//copy roundkey to OpenCL buffer
	err = clEnqueueWriteBuffer(m_world.command_queue, roundkey_buffer, CL_TRUE, 0,
			(ROUNDS + 1) * 16, roundkey, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to copy input dataset to OpenCL buffer");
		LogError("Test failed");
		return false;
	}

	clFinish(m_world.command_queue);

	//execute kernel
//	void AESDecrypt(__global uchar16  *output,__global uchar16  *input,
//	                __global  uchar16  *roundKey, uint blocks)

	err = 0;
	err = clSetKernelArg(m_clKernelAesDecrypt, 0, sizeof(cl_mem), &output_buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [0] output_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(m_clKernelAesDecrypt, 1, sizeof(cl_mem), &input_buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [1] input_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(m_clKernelAesDecrypt, 2, sizeof(cl_mem), &roundkey_buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] roundkey_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	unsigned int blocks = datasetsize / 16;	
	err |= clSetKernelArg(m_clKernelAesDecrypt, 3, sizeof(unsigned int), &blocks);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] blocks! %d", err);
		LogError("Test failed");
		return false;
	}

	size_t global[1];
	size_t local[1];
	global[0] = 1;
	local[0] = 1;

	cl_event event_host_write;
	cl_event event_host_read;


	//call once to guarentee that all buffers are migrated to device memory
	err = clEnqueueNDRangeKernel(m_world.command_queue, m_clKernelAesDecrypt, 1, NULL, global,
			local, 0, NULL, &event_host_write);
	if (err != CL_SUCCESS) {
		LogError("Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);

	//call a second time to measure on-chip throughput
	cl_event ndrangeevent;
	err = clEnqueueNDRangeKernel(m_world.command_queue, m_clKernelAesDecrypt, 1, NULL, global,
			local, 0, NULL, &ndrangeevent);
	if (err != CL_SUCCESS) {
		LogError("Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}

	clFinish(m_world.command_queue);

	//copy results back from OpenCL buffer
	err = clEnqueueReadBuffer(m_world.command_queue, output_buffer, CL_TRUE, 0,
			inputbmpsize, (void *) hwdecryptbmp.pixels, 0, NULL, &event_host_read);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);

	//write "hwdecrypt.bmp"
	char hwdecryptbmpfile[] = "hwdecrypt.bmp";
	writebmp(hwdecryptbmpfile, &hwdecryptbmp);

	//print profiling information
	uint64_t nstimequeued, nstimeend;
	clGetEventProfilingInfo(ndrangeevent, CL_PROFILING_COMMAND_QUEUED,
			sizeof(uint64_t), ((void *) (&nstimequeued)), NULL);
	clGetEventProfilingInfo(ndrangeevent, CL_PROFILING_COMMAND_END,
			sizeof(uint64_t), ((void *) (&nstimeend)), NULL);

	uint64_t nsduration = nstimeend - nstimequeued;
	LogInfo("START %ul END %ul DURATION %ul", nstimequeued, nstimeend, nsduration);

	//set stats to valid data
	double tHostWriteMS = computeEventDurationInMS(event_host_write);
	double tHostReadMS = computeEventDurationInMS(event_host_read);


	double dnsduration = ((double) nsduration);
	double dmsduration = dnsduration / ((double) 1000000);
	double dsduration = dmsduration / ((double) 1000);
	double dbytes = datasetsize;
	double dmbytes = dbytes / (((double) 1024) * ((double) 1024));
	double bpersec = (dbytes / dsduration);
	double mbpersec = bpersec / ((double) 1024 * 1024);
    double d2h_rate = 0;
    double h2d_rate = 0;

	//compute transfer rate
	if(tHostWriteMS > 0) {
		//bits per second
		double tmp = (inputbmpsize * 8.0) / (tHostWriteMS / 1000.0);

		//mega-bits per second
		h2d_rate = tmp / (1024.0 * 1024.0);
	}

	if(tHostReadMS > 0) {
		//bits per second
		double tmp = (inputbmpsize * 8.0) / (tHostReadMS / 1000.0);

		//mega-bits per second
		d2h_rate = tmp / (1024.0 * 1024.0);
	}

	//validate
	LogInfo("Validating OpenCL output");
	size_t vi;
	for (vi = 0; vi < inputbmpsize; vi++) {
		unsigned char result = ((unsigned char *) hwdecryptbmp.pixels)[vi];
		unsigned char ref = ((unsigned char *) inputbmp.pixels)[vi];
		if (result != ref) {
			LogError("HW decrypted data (0x%X) != input data (0x%X) at offset %ld",
					result, ref, vi);
			LogError("Test failed");
			return false;
		}
	}

	LogInfo("Test passed!");



	//set stats to valid data
	LogInfo("Number of runs = %d", nruns);
	LogInfo("Total time in [ms] = %f", timestamp() - startMS);
	LogInfo("Host write [ms] = %f", tHostWriteMS);
	LogInfo("Kernel exec [ms] = %f", dmsduration);
	LogInfo("Host read [ms] = %f", tHostReadMS);
	LogInfo("Dataset size = %f (MB) ", dmbytes);
	LogInfo("Decrypt throughput  = %f (MB/sec) ", mbpersec);

	LogInfo("TX rate host --> device [mbps] = %f", h2d_rate);
	LogInfo("TX rate device --> host [mbps] = %f", d2h_rate);





	return true;
}

