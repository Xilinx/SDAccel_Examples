/**********
Copyright (c) 2018, Xilinx, Inc.
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
#include <assert.h>
#include <string>
#include <stdio.h>
#include <vector>
#include "logger.h"
#include "aes_app.h"
#include "aes_ecb.h"


#if defined(__linux__) || defined(linux)
	#include "sys/time.h"
#elif defined(WIN32)
	#include "windows.h"
#endif

#define ROUNDS 10
//ROUNDS <= 10 valid


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

static double computeEventDurationInMS(const cl::Event& event) {
	cl_ulong ts_start = 0, ts_end = 0;
	double duration = 0;
	cl_int err;
	OCL_CHECK(err, err = event.getProfilingInfo(CL_PROFILING_COMMAND_START,&ts_start));
	OCL_CHECK(err, err = event.getProfilingInfo(CL_PROFILING_COMMAND_END,&ts_end));
	duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

	return duration;
}
/////////////////////////////////////////////////////////////////////////////////
AesApp::AesApp(const string& strFileFP, bool validateGoldFile,const std::string& strGoldFileFP = "") {
	cl_int err;
	m_strFileFP = strFileFP;
	m_validateGoldFile = validateGoldFile;
	m_strGoldFileFP = strGoldFileFP;

	std::vector<cl::Device> devices = xcl::get_xil_devices();
	cl::Device device = devices[0];

	
	OCL_CHECK(err, m_context = new cl::Context(device, NULL, NULL, NULL, &err));
	OCL_CHECK(err, m_q = new cl::CommandQueue(*m_context, device, CL_QUEUE_PROFILING_ENABLE, &err));
	OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err)); 

	std::string binaryFile = xcl::find_binary_file(device_name,"krnl_aes");
	cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
	devices.resize(1);
    	OCL_CHECK(err, m_program = new cl::Program(*m_context, devices, bins, NULL, &err));

    	OCL_CHECK(err, m_kernel = new cl::Kernel(*m_program,"krnl_aes_decrypt", &err));

}

AesApp::~AesApp() {
	delete m_context;
	delete m_q;
	delete m_program;
	delete m_kernel;
}


bool AesApp::run() {

	size_t datasize;
	size_t result;
	cl_int err;
	FILE *inputFileFp=fopen(m_strFileFP.c_str(),"r");
	if(inputFileFp==NULL) {
	 	printf("Error : failed to open file : %s\n",m_strFileFP.c_str());
		return false;
	}

	fseek(inputFileFp, 0, SEEK_END);
	datasize = ftell(inputFileFp);
	rewind (inputFileFp);
	
	std::vector<unsigned char, aligned_allocator<unsigned char>> *buffer = new std::vector<unsigned char,aligned_allocator<unsigned char>> (datasize);
	if (buffer == NULL) {
		printf("Error : failed to allocate memory :buffer\n");
		return false;
	}

	result = fread (buffer->data(),1,datasize,inputFileFp);
	if (result != datasize) {
		printf("Error : failed to read file :%s\n",m_strFileFP.c_str());
		return false;
	}

	fclose(inputFileFp);

	//AES ECB encryption in software
	std::vector<unsigned char, aligned_allocator<unsigned char>> *swencryptintput = new std::vector<unsigned char,aligned_allocator<unsigned char>> (datasize);
	if (swencryptintput == NULL) {
		printf("Error : failed to allocate memory :swencryptintput\n");
		return false;
	}

	//128 bit encryption key
	unsigned char key[] = "Xilinx SDAccel .";

	//perform SW encryption
	aesecb_encrypt(key, ((unsigned char *) buffer->data()),
			((unsigned char *) swencryptintput->data()), datasize, ROUNDS);

	//AES ECB decryption in hardware
	std::vector<unsigned char,aligned_allocator<unsigned char>> *hwdecryptintput = new std::vector<unsigned char,aligned_allocator<unsigned char>> (datasize);
	if (hwdecryptintput == NULL) {
		printf("Error : failed to allocate memory :hwdecryptintput\n");
		return false;
	}

	FILE *encFp=fopen("encryptedData.txt","w");
	if(encFp==NULL) {
		printf("Error : failed to open file :ecn.txt\n");
		return false;
	}
	size_t res = fwrite (swencryptintput->data(),1,datasize,encFp);
	if (res != datasize) {
		printf("Error : failed to write encrypted file\n");
		return false;
	}
	fclose(encFp);

	double startMS = timestamp();

	//compute expanded roundkey
	vector<unsigned char,aligned_allocator<unsigned char>> roundkey((ROUNDS + 1) * 16);
	std::copy(key, key + 16, roundkey.begin());	
	KeyExpansion(roundkey.data());

	//create input and output buffers
	OCL_CHECK(err, cl::Buffer input_buffer(*m_context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, datasize,swencryptintput->data(), &err));
	OCL_CHECK(err, cl::Buffer roundkey_buffer(*m_context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,(ROUNDS + 1) * 16,roundkey.data(), &err));
	OCL_CHECK(err, cl::Buffer output_buffer(*m_context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, datasize,hwdecryptintput->data(), &err));
	
	
	std::vector<cl::Memory> inBufVec, outBufVec;
	inBufVec.push_back(input_buffer);
	inBufVec.push_back(roundkey_buffer);
	outBufVec.push_back(output_buffer);

	OCL_CHECK(err, err = m_q->enqueueMigrateMemObjects(inBufVec, 0/* 0 means from host*/));
	OCL_CHECK(err, err = m_q->finish());

	//execute kernel
//	void AESDecrypt(__global uchar16  *output,__global uchar16  *input,
//	                __global  uchar16  *roundKey, uint blocks)

	unsigned int blocks = datasize / 16;
	int narg=0;
	OCL_CHECK(err, err = m_kernel->setArg(narg++,output_buffer));
	OCL_CHECK(err, err = m_kernel->setArg(narg++,input_buffer));
	OCL_CHECK(err, err = m_kernel->setArg(narg++,roundkey_buffer));
	OCL_CHECK(err, err = m_kernel->setArg(narg++,blocks));
	
	cl::Event event_host_write;
	cl::Event event_host_read;

	OCL_CHECK(err, err = m_q->enqueueTask(*m_kernel, NULL, &event_host_write));
        OCL_CHECK(err, err = m_q->finish());
	
	cl::Event ndrangeevent;
	OCL_CHECK(err, err = m_q->enqueueTask(*m_kernel, NULL, &ndrangeevent));
        OCL_CHECK(err, err = m_q->finish());

	OCL_CHECK(err, err = m_q->enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST,NULL,&event_host_read));
	OCL_CHECK(err, err = m_q->finish());

	//print profiling information
	uint64_t nstimequeued, nstimeend;
	OCL_CHECK(err, err = ndrangeevent.getProfilingInfo(CL_PROFILING_COMMAND_QUEUED, &nstimequeued));
	OCL_CHECK(err, err = ndrangeevent.getProfilingInfo(CL_PROFILING_COMMAND_END, &nstimeend));

	uint64_t nsduration = nstimeend - nstimequeued;
	LogInfo("START %ul END %ul DURATION %ul", nstimequeued, nstimeend, nsduration);

	//set stats to valid data
	double tHostWriteMS = computeEventDurationInMS(event_host_write);
	double tHostReadMS = computeEventDurationInMS(event_host_read);


	double dnsduration = ((double) nsduration);
	double dmsduration = dnsduration / ((double) 1000000);
	double dsduration = dmsduration / ((double) 1000);
	double dbytes = datasize;
	double dmbytes = dbytes / (((double) 1024) * ((double) 1024));
	double bpersec = (dbytes / dsduration);
	double mbpersec = bpersec / ((double) 1024 * 1024);
	double d2h_rate = 0;
	double h2d_rate = 0;

	//compute transfer rate
	if(tHostWriteMS > 0) {
		//bits per second
		double tmp = (datasize * 8.0) / (tHostWriteMS / 1000.0);

		//mega-bits per second
		h2d_rate = tmp / (1024.0 * 1024.0);
	}

	if(tHostReadMS > 0) {
		//bits per second
		double tmp = (datasize * 8.0) / (tHostReadMS / 1000.0);

		//mega-bits per second
		d2h_rate = tmp / (1024.0 * 1024.0);
	}

	//validate
	LogInfo("Validating OpenCL output");
	size_t vi;
	for (vi = 0; vi < datasize; vi++) {
		unsigned char result = hwdecryptintput->at(vi);
		unsigned char ref = buffer->at(vi);
		if (result != ref) {
			LogError("HW decrypted data (0x%X) != input data (0x%X) at offset %ld",
					result, ref, vi);
			LogError("Test failed");
			return false;
		}
	}

	if(m_validateGoldFile) {
		size_t gdatasize;
		size_t res;
		FILE *goldFileFp=fopen(m_strGoldFileFP.c_str(),"r");
		if(goldFileFp==NULL) {
		 	printf("Error : failed to open gold file :%s\n",m_strGoldFileFP.c_str());
			return false;
		}

		fseek(goldFileFp, 0, SEEK_END);
		gdatasize = ftell(goldFileFp);
		rewind (goldFileFp);

		if(gdatasize <= 0) {
			LogError("Gold File len (%d)",gdatasize);
			LogError("Test failed");
			return false;
		}
		std::vector<unsigned char> *gbuffer = new std::vector<unsigned char> (gdatasize);
		if (gbuffer == NULL) {
			printf("Error : failed to allocate memory :gbuffer\n");
			return false;
		}

		res = fread(gbuffer->data(),1,gdatasize,goldFileFp);
		if (res != gdatasize) {
			printf("Error : failed to read gold file\n");
			return false;
		}

		fclose(goldFileFp);
		if(datasize != gdatasize) {
			LogError("Gold File len (%d) != enxrypted data len (%d)",
					gdatasize, datasize);
			LogError("Test failed");
			return false;
		}
		for (size_t i = 0; i < datasize; i++) {
			unsigned char result = swencryptintput->at(i);
			unsigned char ref = gbuffer->at(i);
			if (result != ref) {
				LogError("Sw encrypted data (0x%X) != Gold File data (0x%X) at offset %ld",
						result, ref, i);
				LogError("Test failed");
				return false;
			}
		}
		delete gbuffer;
	}
	LogInfo("Test passed!");



	//set stats to valid data
	LogInfo("Total time in [ms] = %f", timestamp() - startMS);
	LogInfo("Host write [ms] = %f", tHostWriteMS);
	LogInfo("Kernel exec [ms] = %f", dmsduration);
	LogInfo("Host read [ms] = %f", tHostReadMS);
	LogInfo("Dataset size = %f (MB) ", dmbytes);
	LogInfo("Decrypt throughput  = %f (MB/sec) ", mbpersec);

	LogInfo("TX rate host --> device [mbps] = %f", h2d_rate);
	LogInfo("TX rate device --> host [mbps] = %f", d2h_rate);

	delete buffer;
	delete swencryptintput;
	delete hwdecryptintput; 

	return true;
}
