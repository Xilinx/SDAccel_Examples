/*******************************************************************************
Vendor: Xilinx
Associated Filename: cmdlineparser.cpp
Purpose: SDAccel rsa example
Revision History: Feb 2, 2016

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
#include "rsa_app.h"
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


RSAApp::RSAApp() {
	// TODO Auto-generated constructor stub

}

RSAApp::RSAApp(const string& vendor_name,
		    const string& device_name,
		    int selected_device,
		    const string& strKernelFP,
	            const string& strInputFP,
                    const string& strOutputFP,
                    const string& strKeyFP)
{
	//store path to input bitmap
     m_strInputFP = strInputFP;
     m_strOutputFP = strOutputFP;
     m_strKeyFP = strKeyFP;
     xcl_list_platforms();
     if(xcl_list_devices(vendor_name.c_str()) > 0) {
               //get device by name
               assert(xcl_world_vendor_devtype(vendor_name.c_str(),CL_DEVICE_TYPE_ACCELERATOR,m_world));
 	}

	//kernels
    m_clKernelRSA  = xcl_import_binary(m_world, strKernelFP.c_str(), "rsa");

}

RSAApp::~RSAApp() {
	// TODO Auto-generated destructor stub
	cleanup();
}

void RSAApp::cleanup() {

	clReleaseKernel(m_clKernelRSA);
	xcl_release_world(m_world);
}

double RSAApp::timestamp() {
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

double RSAApp::computeEventDurationInMS(const cl_event& event) {
	cl_ulong ts_start = 0, ts_end = 0;
	double duration = 0;
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &ts_start, NULL);
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &ts_end, NULL);
	duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

	return duration;
}

bool RSAApp::releaseMemObject(cl_mem &obj)
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

bool RSAApp::invoke_kernel(cl_kernel kernel,uint *message, uint * ciphertext, uint * d, uint * n,uint * r2, cl_event events[evtCount]) {
	
      cl_uint sizeInBytes = 32 * sizeof(cl_uint);
      int status;
      int i;
	/////////////////////////////////////////////////////////////////
	// Allocate and initialize memory used by host 
	/////////////////////////////////////////////////////////////////
       cl_uint * messagearray = (cl_uint *) malloc(sizeInBytes);
	if(messagearray == NULL)
	{
		printf("Error: Failed to allocate output memory on host (messagearray)\n");
		return false; 
	}


      cl_uint * ciphertextarray = (cl_uint *) malloc(sizeInBytes);
	if(ciphertextarray == NULL)
	{
		printf("Error: Failed to allocate output memory on host (ciphertextarray)\n");
		return false; 
	}

      cl_uint * darray = (cl_uint *) malloc(sizeInBytes);
	if(darray == NULL)
	{
		printf("Error: Failed to allocate output memory on host (darray)\n");
		return false; 
	}
      cl_uint * narray = (cl_uint *) malloc(sizeInBytes);
	if(narray == NULL)
	{
		printf("Error: Failed to allocate output memory on host (narray)\n");
		return false; 
	}
     cl_uint * r2array = (cl_uint *) malloc(sizeInBytes);
	if(r2array == NULL)
	{
		printf("Error: Failed to allocate output memory on host (r2array)\n");
		return false; 
	}

	memset(messagearray, 0, sizeInBytes);
	 for(i=0;i<32;i++)
	{
		ciphertextarray[i]=ciphertext[i%32];
		darray[i]=d[i%32];
		narray[i]=n[i%32];
		r2array[i]=r2[i%32];
	
	}


	/////////////////////////////////////////////////////////////////
	// Create OpenCL memory buffers
	/////////////////////////////////////////////////////////////////

cl_mem messageBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      messagearray, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (messageBuffer)\n");
		return false;
	}

cl_mem ciphertextBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      ciphertextarray, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (ciphertextBuffer)\n");
		return false;
	}

cl_mem exponentBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      darray, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (exponentBuffer)\n");
		return false;
	} 

cl_mem modBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      narray, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (modBuffer)\n");
		return false;
	}    

cl_mem r2Buffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      r2array, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (r2Buffer)\n");
		return false;
	} 
       

	//execute kernel
	cl_int err = 0;
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &messageBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [0] messageBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), 
                    (void *)&ciphertextBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [1] ciphertextBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&exponentBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] exponentBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&modBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] modBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	//enable fetch size
	err |= clSetKernelArg(kernel, 4,sizeof(cl_mem), 
                    (void *)&r2Buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] r2Buffer! %d", err);
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
	err = clEnqueueReadBuffer(m_world.command_queue, messageBuffer, CL_TRUE, 0,
			 sizeInBytes, messagearray,0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output messageBuffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);

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
	err = clEnqueueReadBuffer(m_world.command_queue, messageBuffer, CL_TRUE, 0,
			sizeInBytes,
                messagearray,
			0, NULL, &events[evtHostRead]);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);


	//cleanup
       releaseMemObject(ciphertextBuffer);
       releaseMemObject(messageBuffer);
       releaseMemObject(modBuffer);
       releaseMemObject(exponentBuffer);
       releaseMemObject(r2Buffer);


	return true;
}




bool RSAApp::run(int idevice, int nruns) {
	if (nruns <= 0)
		return false;

        unsigned char *n_r, *d_r, *n, *d;
	cl_uint *exponent, *mod,*r2;
         uint message[NUM_WORDS], ciphertext[NUM_WORDS];
	//input ciphertext
	FILE *key_fp = fopen(m_strKeyFP.c_str(), "r");
  	  if(!key_fp) {
     	 printf("Could not locate file: %s\n", m_strKeyFP.c_str());
      	return 1;
   	 }
		
    	RSA *rsa_key = PEM_read_RSAPrivateKey(key_fp, NULL, NULL, NULL);
    	//RSA_print_fp(stdout, rsa_key, 0);

//extract modula d and private key d as BIGNUM, BN_print_fp print the little endian format, same as real N,d
	//BN_print_fp(stdout, rsa_key->n); 
	//BN_print_fp(stdout, rsa_key->d); 
	
	int n_size = BN_num_bytes(rsa_key->n);
	int d_size=  BN_num_bytes(rsa_key->d);
     	printf("n_size = %d\n", n_size);
    	printf("d_size = %d\n", d_size);

    	//printf("n is %s\n", BN_bn2hex(rsa_key->n));
    	//BN_print_fp(stdout, rsa_key->d);
    	//printf("d %s\n", BN_bn2hex(rsa_key->d));
	
	n = (unsigned char *) malloc(n_size);
	n_r = (unsigned char *) malloc(n_size);
	d = (unsigned char *) malloc(d_size);
	d_r = (unsigned char *) malloc(d_size);
	
   	BN_bn2bin(rsa_key->n, n_r);
    	BN_bn2bin(rsa_key->d, d_r);
   	//print_big_number((WORD_TYPE *)n_r, n_size/4, "bignum N");
    	//print_big_number((WORD_TYPE *)d_r, d_size/4, "bignum d");
	
	reverse_array(n, n_r, n_size);
    	reverse_array(d, d_r, d_size);
	exponent=(WORD_TYPE *)d;
	mod=(WORD_TYPE *)n;
    	print_big_number((WORD_TYPE *)mod, n_size/4, "real N");
    	print_big_number((WORD_TYPE *)exponent, d_size/4, "real d");
	
	
	//compute r2_N=r2 mod n
	BN_CTX *ctx=NULL;
	if((ctx=BN_CTX_new())==NULL) printf("fail to create a new BN_CTX structure!\n");
	BN_CTX_start(ctx);
	BIGNUM *R2=BN_CTX_get(ctx);
	BIGNUM *R=BN_CTX_get(ctx);
	BN_one(R);
	BN_lshift(R,R,1024);
	BN_print_fp(stdout,R);
	BN_mul(R2,R,R,ctx);
	BN_mod(R2,R2,rsa_key->n,ctx);
	unsigned char *temp1=(unsigned char *) malloc(128);
	unsigned char *temp2=(unsigned char *) malloc(128);
	BN_bn2bin(R2,temp1);
	reverse_array(temp2,temp1,128);
        r2=(WORD_TYPE *)temp2;
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);
	print_big_number(r2, n_size/4, "\nr2 mod N");

	printf("read in ciphertext\n");
    	read_data(ciphertext, m_strInputFP.c_str());
	print_big_number(ciphertext, 32, "ciphertext");
	printf("start running kernel");



	//timings
	cl_event events[evtCount];
	double durations[evtCount];
	for(int i=0; i < evtCount; i++)
		durations[i] = 0.0;

	//start time stamps
	double startMS = timestamp();


	//encode image
	LogInfo("Invoking rsa");
	bool res = invoke_kernel(m_clKernelRSA,message,ciphertext, exponent, mod,r2,&events[0]);
	if(!res) {
		LogError("Failed to encode the input. Test Failed");
		return false;
	}

	//collect times
	for(int i=0; i < evtCount; i++) {
		durations[i] += computeEventDurationInMS(events[i]);
	}

	double h2d_rate = 0.0;
	double d2h_rate = 0.0;


	//compute transfer rate for host write
	if(durations[evtHostWrite] > 0) {
		uint sz_bytes = 32*4;

		//bits per second
		double tmp = (sz_bytes * 8.0) / (durations[evtHostWrite] / 1000.0);

		//mega-bits per second
		h2d_rate = tmp / (1024.0 * 1024.0);
	}

	//compute transfer rate for host read
	if(durations[evtHostRead] > 0) {
		uint sz_bytes = 32*4;

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
      
   //memcpy(message, messagearray,32);
	print_big_number(message, 32, "message");
    	output_data_to_file(m_strOutputFP.c_str(), message);

	return true;
}

