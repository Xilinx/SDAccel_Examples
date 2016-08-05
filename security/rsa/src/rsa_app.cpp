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

bool RSAApp::invoke_kernel(cl_kernel kernel,cl_uint *message,cl_uint *Cp,cl_uint *Cq, cl_uint *p, cl_uint *q, cl_uint *dmp1, cl_uint *dmq1, cl_uint *iqmp, cl_uint *r2p, cl_uint *r2q, cl_event events[evtCount]) {
	
      cl_uint sizeInBytes = 16* sizeof(cl_uint);
      int status;
      int i;

	/////////////////////////////////////////////////////////////////
	// Create OpenCL memory buffers
	/////////////////////////////////////////////////////////////////

cl_mem messageBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
                     2*sizeInBytes,
                      message, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (messageBuffer)\n");
		return false;
	}


cl_mem CpBuffer  = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      Cp, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (CpBuffer)\n");
		return false;
	} 

cl_mem CqBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      Cq, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (CqBuffer)\n");
		return false;
	}    

cl_mem dmp1Buffer= clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      dmp1, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (dmp1Buffer)\n");
		return false;
	} 
       
cl_mem dmq1Buffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      dmq1, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (dmq1Buffer)\n");
		return false;
	} 

cl_mem pBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      p, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (pBuffer)\n");
		return false;
	}    
cl_mem qBuffer = clCreateBuffer(
				     m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      q, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (qBuffer)\n");
		return false;
	} 
cl_mem r2pBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      r2p, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (r2pBuffer)\n");
		return false;
	} 
cl_mem r2qBuffer = clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      r2q, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (r2qBuffer)\n");
		return false;
	} 

cl_mem iqmpBuffer=clCreateBuffer(
				      m_world.context, 
                      CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     sizeInBytes,
                      iqmp, 
                      &status);
    if(status != CL_SUCCESS) 
	{ 
		printf("Error: clCreateBuffer (iqmpBuffer)\n");
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

	err |= clSetKernelArg(kernel, 1, 
                    sizeof(cl_mem), 
                    (void *)&CpBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [1] CpBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 2,  
                    sizeof(cl_mem), 
                    (void *)&CqBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] CqBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 3, 
                    sizeof(cl_mem), 
                    (void *)&pBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] pBuffer! %d", err);
		LogError("Test failed");
		return false;
	}


	err |= clSetKernelArg(kernel, 4, 
                    sizeof(cl_mem), 
                    (void *)&qBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] qBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel,5, 
                    sizeof(cl_mem), 
                    (void *)&dmp1Buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [5] dmp1Buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel,6, 
                    sizeof(cl_mem), 
                    (void *)&dmq1Buffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [6] dmq1Buffer! %d", err);
		LogError("Test failed");
		return false;
	}


	err |= clSetKernelArg(kernel, 7, 
                    sizeof(cl_mem), 
                    (void *)&iqmpBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [7] iqmpBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel,8, 
                    sizeof(cl_mem), 
                    (void *)&r2pBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [8] r2pBuffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel,9, 
                    sizeof(cl_mem), 
                    (void *)&r2qBuffer);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [9] r2qBuffer! %d", err);
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
			 2*sizeInBytes, message,0, NULL, NULL);
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
			2*sizeInBytes,
                message,
			0, NULL, &events[evtHostRead]);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_world.command_queue);


	//cleanup
       
       releaseMemObject(messageBuffer);
       releaseMemObject(CqBuffer);
       releaseMemObject(CpBuffer);
       releaseMemObject(r2qBuffer);
       releaseMemObject(r2pBuffer);
       releaseMemObject(iqmpBuffer);
       releaseMemObject(pBuffer);
       releaseMemObject(qBuffer);
       releaseMemObject(r2pBuffer);
       releaseMemObject(r2qBuffer);

	return true;
}




bool RSAApp::run(int idevice, int nruns) {
	if (nruns <= 0)
		return false;

        cl_uchar  *p, *q, *p_r, *q_r,*dmp1, *dmq1, *iqmp, *dmp1_r,*dmq1_r, *iqmp_r;
	cl_uint r2p[16], r2q[16], Cp[16], Cq[16];
	int p_size = 0, q_size = 0, dmp1_size = 0, dmq1_size = 0, iqmp_size = 0;
         uint message[NUM_WORDS], ciphertext[NUM_WORDS];
	//input ciphertext
	FILE *key_fp = fopen(m_strKeyFP.c_str(), "r");
  	  if(!key_fp) {
     	 printf("Could not locate file: %s\n", m_strKeyFP.c_str());
      	return 1;
   	 }
	

	printf("read in ciphertext\n");
    	read_data(ciphertext, m_strInputFP.c_str());
	print_big_number(ciphertext, 32, "ciphertext");

    	RSA *rsa_key = PEM_read_RSAPrivateKey(key_fp, NULL, NULL, NULL);
	int n_size = BN_num_bytes(rsa_key->n);
    	p = (unsigned char *) malloc(NUM_WORDS*2);
   	 q = (unsigned char *) malloc(NUM_WORDS*2);
   	 dmp1 = (unsigned char *) malloc(NUM_WORDS*2);
   	 dmq1 = (unsigned char *) malloc(NUM_WORDS*2);
   	 iqmp = (unsigned char *) malloc(NUM_WORDS*2);

    	p_r = (unsigned char *) malloc(NUM_WORDS*2);
    	q_r = (unsigned char *) malloc(NUM_WORDS*2);
    	dmp1_r = (unsigned char *) malloc(NUM_WORDS*2);
   	dmq1_r = (unsigned char *) malloc(NUM_WORDS*2);
    	iqmp_r = (unsigned char *) malloc(NUM_WORDS*2);	

        BN_bn2bin(rsa_key->p, p_r);
   	BN_bn2bin(rsa_key->q, q_r);
   	BN_bn2bin(rsa_key->dmp1, dmp1_r);
   	BN_bn2bin(rsa_key->dmq1, dmq1_r);
    	BN_bn2bin(rsa_key->iqmp, iqmp_r);

    	p_size = BN_num_bytes(rsa_key->p);
    	q_size = BN_num_bytes(rsa_key->q);
    	dmp1_size = BN_num_bytes(rsa_key->dmp1);
    	dmq1_size = BN_num_bytes(rsa_key->dmq1);
    	iqmp_size = BN_num_bytes(rsa_key->iqmp);
	
	reverse_array(p, p_r, p_size);
   	reverse_array(q, q_r, q_size);
   	reverse_array(dmp1, dmp1_r, dmp1_size);
    	reverse_array(dmq1, dmq1_r, dmq1_size);
   	reverse_array(iqmp, iqmp_r, iqmp_size);

        //compute r2p=r2 mod p, r2q=r2 mod q
	unsigned char *temp1=(unsigned char *) malloc(128);
	unsigned char *temp2=(unsigned char *) malloc(128);
	unsigned char *temp3=(unsigned char *) malloc(64);
	unsigned char *temp4=(unsigned char *) malloc(64);
	BN_CTX *ctx=NULL;
	if((ctx=BN_CTX_new())==NULL) printf("fail to create a new BN_CTX structure!\n");
	BN_CTX_start(ctx);
	BIGNUM *R2=BN_CTX_get(ctx);
	BIGNUM *R=BN_CTX_get(ctx);
	BN_one(R);
	BN_lshift(R,R,512);

	BN_mul(R2,R,R,ctx);
	BN_mod(R2,R2,rsa_key->p,ctx);
	BN_bn2bin(R2,temp3);
	reverse_array(temp4,temp3,64);
        memcpy(r2p,temp4,64);
       

	BN_mul(R2,R,R,ctx);
	BN_mod(R2,R2,rsa_key->q,ctx);
	BN_bn2bin(R2,temp3);
	reverse_array(temp4,temp3,64);
        memcpy(r2q,temp4,64);


	//prepare C%p, C%q for CRT
	BIGNUM *C1=BN_CTX_get(ctx);
	BIGNUM *C=BN_CTX_get(ctx);
	reverse_array(temp1,(unsigned char *) &ciphertext[0],128);
	BN_bin2bn(temp1,128,C);
	BN_mod(C1,C,rsa_key->p,ctx);
	BN_bn2bin(C1,temp3);
	reverse_array(temp4,temp3,64);
        memcpy(Cp,temp4,64);
	print_big_number(Cp, n_size/8, "\n C mod p");

	BN_mod(C1,C,rsa_key->q,ctx);
	BN_bn2bin(C1,temp3);
	reverse_array(temp4,temp3,64);
        memcpy(Cq,temp4,64);
	print_big_number(Cq, n_size/8, "\n C mod q");
	
        print_big_number((uint *)p, n_size/8, "\n p");
        print_big_number((uint *)q, n_size/8, "\n q");
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);
	
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
	bool res = invoke_kernel(m_clKernelRSA, message, Cp, Cq, (uint *)p,(uint *) q, (uint *)dmp1, (uint *)dmq1, (uint *)iqmp,r2p,r2q,&events[0]);
	if(!res) {
		LogError("Failed to decrypt the ciphertext. Test Failed");
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

	print_big_number(message, 32, "message");
    	output_data_to_file(m_strOutputFP.c_str(), message);
        free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(p);
	free(q);
	free(p_r);
	free(q_r);
	free(dmp1);
	free(dmq1);
	free(iqmp);
	free(dmp1_r);
	free(dmq1_r);
	free(iqmp_r);
	return true;
}

