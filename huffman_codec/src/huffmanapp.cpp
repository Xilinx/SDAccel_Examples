/*******************************************************************************
Vendor: Xilinx
Associated Filename: huffmanapp.cpp
Purpose: SDAccel huffman codec example
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
#include <stdio.h>
#include "logger.h"
#include "huffmanapp.h"
#include "simplebmp.h"
#include "huffmancodec.h"
#include "huffmancodec_opencl_cpu.h"
#include "xcl.h"

#if defined(__linux__) || defined(linux)
	#include "sys/time.h"
#elif defined(WIN32)
	#include "windows.h"
#endif


#define ROUNDS 10
//ROUNDS <= 10 valid

using namespace sda;
using namespace sda::cl;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//load_file_to_memory


HuffmanApp::HuffmanApp() {
	// TODO Auto-generated constructor stub

}

HuffmanApp::HuffmanApp(const string& vendor_name,
			   const string& device_name,
			   int selected_device,
			   const string& strKernelFP,
			   const string& strBitmapFP)
{
	//store path to input bitmap
	m_strBitmapFP = strBitmapFP;

	if(strstr(strKernelFP.c_str(), ".xclbin") != NULL) {
		LogInfo("order xilinx device");
		m_world = xcl_world_single(CL_DEVICE_TYPE_ACCELERATOR);
	} else {
		LogInfo("order cpu device");
		m_world = xcl_world_single(CL_DEVICE_TYPE_CPU);
	}

	//kernels
    m_clKernelHuffmanEncoder  = xcl_import_binary(m_world, strKernelFP.c_str(), "encode");
    m_clKernelHuffmanDecoder  = xcl_import_binary(m_world, strKernelFP.c_str(), "decode");

}

HuffmanApp::~HuffmanApp() {
	// TODO Auto-generated destructor stub
	cleanup();
}

void HuffmanApp::cleanup() {

	clReleaseKernel(m_clKernelHuffmanDecoder);
	clReleaseKernel(m_clKernelHuffmanEncoder);
	xcl_release_world(m_world);
}

double HuffmanApp::timestamp() {
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

double HuffmanApp::computeEventDurationInMS(const cl_event& event) {
	cl_ulong ts_start = 0, ts_end = 0;
	double duration = 0;
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &ts_start, NULL);
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &ts_end, NULL);
	duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

	return duration;
}

bool HuffmanApp::unit_test_kernel_cpu() {
	string msgs[] = {"AABBCCCC",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};

	LogInfo("Start unit tests for kernels on the CPU");

	HuffmanCodec codec;
	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	u32 ctPassed = 0;
	for(u32 i = 0; i < total; i++) {
		vector<u8> encoded_data;
		string out_str;
		codec.kernel_encode_string(msgs[i], encoded_data);

		codec.kernel_decode_string(encoded_data, out_str);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS", i+1, total);
			ctPassed++;
		}
		else
		{
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", msgs[i].c_str(), out_str.c_str());
		}
	}

	LogInfo("End unit tests for kernels on the CPU");

	return(ctPassed == total);
}

/*!
 * Unit test for the huffman cpu version
 */
bool HuffmanApp::unit_test_naive() {
	string msgs[] = {"aabbcccc",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};


	HuffmanCodec codec;
	u32 ctPassed = 0;
	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	for(u32 i = 0; i < total; i++) {
		vector<u8> data_out;
		string out_str;

		int res = codec.encode_naive(msgs[i], data_out);
		res &= codec.decode_naive(data_out, out_str);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS", i+1, total);
			ctPassed++;
		}
		else
		{
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", msgs[i].c_str(), out_str.c_str());
		}
	}

	return (ctPassed == total);
}

bool HuffmanApp::releaseMemObject(cl_mem &obj)
{
  cl_int   err = 0;
  bool     returnStatus = true;    // true if successful

  if (obj != NULL)  // This means it has been initialized
  {
    err = clReleaseMemObject(obj);
    if (err != CL_SUCCESS)
    {
      cout << "Error releasing variable\n";
      returnStatus |= false;
    }
    else
      obj = NULL; /* memory was released, re-initialize pointer to NULL */
  }

  return returnStatus;
}

bool HuffmanApp::invoke_kernel(bool encode,
							   const vector<u8>& vec_input,
							   vector<u8>& vec_output,
							   cl_event events[evtCount]) {
	if(vec_input.size() == 0)
		return false;

	cl_kernel kernel = encode ? m_clKernelHuffmanEncoder : m_clKernelHuffmanDecoder;

	u32 sz_input = vec_input.size();
	u32 sz_output = 0;

	LogInfo("Creating input/output buffers");
//	__kernel
//	__attribute__ ((reqd_work_group_size(1,1,1)))
//	void encode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only)
//	void decode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only) {
	//create input and output buffers size for 24 bpp image
	cl_int err;
	cl_mem mem_input;

	mem_input = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, sz_input, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Error: Failed to allocate OpenCL source buffer of size %lu", sz_input);
		return false;
	}

	cl_mem mem_output;
	mem_output = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, sz_input, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu",
				sz_input);
		return false;
	}

	cl_mem mem_sz_output;
	mem_sz_output = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, sizeof(u32), NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu",
				sizeof(u32));
		return false;
	}

	LogInfo("Write input data to device buffer");
	//copy input dataset to OpenCL buffer
	err = clEnqueueWriteBuffer(m_world.command_queue, mem_input, CL_TRUE, 0,
							   sz_input, vec_input.data(), 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to copy input dataset to OpenCL buffer");
		return false;
	}

	//finish all memory writes
	clFinish(m_world.command_queue);

	//execute kernel
	/*!
	 * void encode(__global uchar* in_data, uint size_in_data,
	 * 			   __global uchar* out_data, __global uint* size_out_data,
	 * 			   uchar fetch_size_only)
	 *
	 * void decode(__global uchar* in_data, uint size_in_data,
	 * 			   __global uchar* out_data, __global uint* size_out_data,
	 * 			   uchar fetch_size_only)
	 */
	err = 0;
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_input);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [0] input_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 1, sizeof(u32), &sz_input);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [1] sz_input! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mem_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] output_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), &mem_sz_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] sz_output! %d", err);
		LogError("Test failed");
		return false;
	}

	//enable fetch size
	u8 fetch_size_only = 1;
	err |= clSetKernelArg(kernel, 4, sizeof(u8), &fetch_size_only);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] fetch_size_only! %d", err);
		LogError("Test failed");
		return false;
	}

	size_t global[1];
	size_t local[1];
	global[0] = 1;
	local[0] = 1;

	LogInfo("EX1: to make sure all buffers are migrated to device");

	//call once to guarentee that all buffers are migrated to device memory
	err = clEnqueueNDRangeKernel(m_world.command_queue, kernel, 1, NULL, global,
			local, 0, NULL, &events[evtHostWrite]);
	if (err != CL_SUCCESS) {
		LogError("[EX1] Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);


	//read output size
	err = clEnqueueReadBuffer(m_world.command_queue, mem_sz_output, CL_TRUE, 0,
			sizeof(u32), (void *) &sz_output, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);

	//resize output-buffer
	releaseMemObject(mem_output);

	vec_output.resize(sz_output);
	mem_output = clCreateBuffer(m_world.context, CL_MEM_READ_WRITE, sz_output, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu", sz_output);
		return false;
	}

	//set output again
	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mem_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] output_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	//set output size again
	err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), &mem_sz_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] sz_output! %d", err);
		LogError("Test failed");
		return false;
	}

	//disable fetch size
	fetch_size_only = 0;
	err |= clSetKernelArg(kernel, 4, sizeof(u8), &fetch_size_only);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] fetch_size_only! %d", err);
		LogError("Test failed");
		return false;
	}

	LogInfo("EX2: Real execution of the algorithm to fill the output");

	//call a second time to measure on-chip throughput
	err = clEnqueueNDRangeKernel(m_world.command_queue, kernel, 1, NULL, global,
			local, 0, NULL, &events[evtKernelExec]);
	if (err != CL_SUCCESS) {
		LogError("[EX2] Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}

	clFinish(m_world.command_queue);

	//copy results back from OpenCL buffer
	err = clEnqueueReadBuffer(m_world.command_queue, mem_output, CL_TRUE, 0,
			sz_output, (void *) vec_output.data(), 0, NULL, &events[evtHostRead]);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);


	//cleanup
	releaseMemObject(mem_input);
	releaseMemObject(mem_output);
	releaseMemObject(mem_sz_output);

	return true;
}




bool HuffmanApp::run(int idevice, int nruns) {
	if (nruns <= 0)
		return false;

	assert(unit_test_kernel_cpu());


	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)m_strBitmapFP.c_str(), &inputbmp);
	if (err != 0) {
		LogError("Unable to read bitmap file: [%s]", m_strBitmapFP.c_str());
		return false;
	}


	//input buffer size
	u32 szInputBuffer = inputbmp.height * inputbmp.width * 3;
	u8* buffer = reinterpret_cast<u8*>(inputbmp.pixels);
	LogInfo("Read input data successfully. size = %u", szInputBuffer);

	//timings
	cl_event events[evtCount];
	double durations[evtCount];
	for(int i=0; i < evtCount; i++)
		durations[i] = 0.0;

	//start time stamps
	double startMS = timestamp();

	vector<u8> vec_in(buffer, buffer + szInputBuffer);
	vector<u8> vec_encoded_data;
	vector<u8> vec_decoded_data;

	//encode image
	LogInfo("Invoking encoder");
	bool res = invoke_kernel(true, vec_in, vec_encoded_data, &events[0]);
	if(!res) {
		LogError("Failed to encode the input. Test Failed");
		return false;
	}

	//collect times
	for(int i=0; i < evtCount; i++) {
		durations[i] += computeEventDurationInMS(events[i]);
	}


	//decode image
	LogInfo("Invoking decoder");
	res |= invoke_kernel(false, vec_encoded_data, vec_decoded_data, &events[0]);
	if(!res) {
		LogError("Failed to decode the output. Test Failed");
		return false;
	}

	//collect times
	for(int i=0; i < evtCount; i++) {
		durations[i] += computeEventDurationInMS(events[i]);
	}


	//using the standard impl
	/*
	HuffmanCodec codec;
	u32 szEncoded = 0;
	u32 szDecoded = 0;

	//encode
	encode(vec_in.data(), vec_in.size(), vec_encoded_data.data(), &szEncoded, true);
	vec_encoded_data.resize(szEncoded);
	encode(vec_in.data(), vec_in.size(), vec_encoded_data.data(), &szEncoded, false);
	LogInfo("Encoded image. Org Size %u, Compact Size %u", vec_in.size(), vec_encoded_data.size());

	decode(vec_encoded_data.data(), vec_encoded_data.size(), vec_decoded_data.data(), &szDecoded, true);
	vec_decoded_data.resize(szDecoded);
	decode(vec_encoded_data.data(), vec_encoded_data.size(), vec_decoded_data.data(), &szDecoded, false);
	*/


	double h2d_rate = 0.0;
	double d2h_rate = 0.0;


	//compute transfer rate for host write
	if(durations[evtHostWrite] > 0) {
		u32 sz_bytes = vec_in.size() + vec_encoded_data.size();

		//bits per second
		double tmp = (sz_bytes * 8.0) / (durations[evtHostWrite] / 1000.0);

		//mega-bits per second
		h2d_rate = tmp / (1024.0 * 1024.0);
	}

	//compute transfer rate for host read
	if(durations[evtHostRead] > 0) {
		u32 sz_bytes = vec_encoded_data.size() + vec_decoded_data.size();

		//bits per second
		double tmp = (sz_bytes * 8.0) / (durations[evtHostRead] / 1000.0);

		//mega-bits per second
		d2h_rate = tmp / (1024.0 * 1024.0);
	}


	//set stats to valid data
	LogInfo("Number of runs = %d", nruns);
	LogInfo("Total time in [ms] = %f", timestamp() - startMS);
	LogInfo("Host write [ms] = %f", durations[evtHostWrite]);
	LogInfo("Kernel exec [ms] = %f", durations[evtKernelExec]);
	LogInfo("Host read [ms] = %f", durations[evtHostRead]);
	LogInfo("TX rate host --> device [mbps] = %f", h2d_rate);
	LogInfo("TX rate device --> host [mbps] = %f", d2h_rate);


	//write decoded bmp
	string strOutputFP = "decoded.bmp";
	LogInfo("Image decoded OK. Check the output image file: %s", strOutputFP.c_str());
	inputbmp.pixels = reinterpret_cast<uint32_t*>(&vec_decoded_data[0]);
	writebmp((char*)strOutputFP.c_str(), &inputbmp);


	return true;
}

