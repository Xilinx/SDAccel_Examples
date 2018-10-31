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
#include <string.h>
#include <stdio.h>
#include "logger.h"
#include "rsa_app.h"
#include "xcl2.hpp"

#if defined(__linux__) || defined(linux)
	#include "sys/time.h"
#elif defined(WIN32)
	#include "windows.h"
#endif


#define ROUNDS 10

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
	cl_int err;
	//store path to input bitmap
	m_strInputFP = strInputFP;
	m_strOutputFP = strOutputFP;
	m_strKeyFP = strKeyFP;

	std::vector<cl::Device> devices = xcl::get_xil_devices();
	cl::Device device = devices[0];

	OCL_CHECK(err, m_context = cl::Context(device, NULL, NULL, NULL, &err));
	OCL_CHECK(err, m_q = cl::CommandQueue(m_context, device, CL_QUEUE_PROFILING_ENABLE, &err));
	OCL_CHECK(err, std::string deviceName = device.getInfo<CL_DEVICE_NAME>(&err));

	std::string binaryFile = xcl::find_binary_file(deviceName,"krnl_rsa");

	cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
	devices.resize(1);
	OCL_CHECK(err, m_program = cl::Program(m_context, devices, bins, NULL, &err));
	OCL_CHECK(err, m_clKernelRSA = cl::Kernel(m_program,"rsa", &err));
}

RSAApp::~RSAApp() {
	// TODO Auto-generated destructor stub
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

double RSAApp::computeEventDurationInMS(const cl::Event& event) {
	cl_int err;
	cl_ulong ts_start = 0, ts_end = 0;
	double duration = 0;
    OCL_CHECK(err, err = event.getProfilingInfo<cl_ulong>(CL_PROFILING_COMMAND_START, &ts_start));
    OCL_CHECK(err, err = event.getProfilingInfo<cl_ulong>(CL_PROFILING_COMMAND_END, &ts_end));

    duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

	return duration;
}

bool RSAApp::invoke_kernel(cl::Kernel kernel, cl_uint *message, cl_uint *Cp, cl_uint *Cq,
							cl_uint *p, cl_uint *q, cl_uint *dmp1, cl_uint *dmq1, cl_uint *iqmp,
							cl_uint *r2p, cl_uint *r2q, cl::Event events[evtCount]) {

    cl_uint sizeInBytes = 32* sizeof(cl_uint);
    cl_int err;

	/////////////////////////////////////////////////////////////////
	// Create OpenCL memory buffers
	/////////////////////////////////////////////////////////////////

    OCL_CHECK(err, cl::Buffer messageBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_WRITE,
    		  	  	  2*sizeInBytes, message, &err));

    OCL_CHECK(err, cl::Buffer CpBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, Cp, &err));

    OCL_CHECK(err, cl::Buffer CqBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, Cq, &err));

    OCL_CHECK(err, cl::Buffer dmp1Buffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, dmp1, &err));

    OCL_CHECK(err, cl::Buffer dmq1Buffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, dmq1, &err));

    OCL_CHECK(err, cl::Buffer pBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, p, &err));

    OCL_CHECK(err, cl::Buffer qBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, q, &err));

    OCL_CHECK(err, cl::Buffer r2pBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, r2p, &err));

    OCL_CHECK(err, cl::Buffer r2qBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
        		  	  sizeInBytes, r2q, &err));

    OCL_CHECK(err, cl::Buffer iqmpBuffer (m_context,CL_MEM_COPY_HOST_PTR | CL_MEM_READ_WRITE,
        		  	  sizeInBytes, iqmp, &err));

	//execute kernel
	OCL_CHECK(err, err = kernel.setArg(0, messageBuffer));
	OCL_CHECK(err, err = kernel.setArg(1, CpBuffer));
	OCL_CHECK(err, err = kernel.setArg(2, CqBuffer));
	OCL_CHECK(err, err = kernel.setArg(3, pBuffer));
	OCL_CHECK(err, err = kernel.setArg(4, qBuffer));
	OCL_CHECK(err, err = kernel.setArg(5, dmp1Buffer));
	OCL_CHECK(err, err = kernel.setArg(6, dmq1Buffer));
	OCL_CHECK(err, err = kernel.setArg(7, iqmpBuffer));
	OCL_CHECK(err, err = kernel.setArg(8, r2pBuffer));
	OCL_CHECK(err, err = kernel.setArg(9, r2qBuffer));

	LogInfo("EX1: to make sure all buffers are migrated to device");

	//call once to guarentee that all buffers are migrated to device memory
	OCL_CHECK(err, err = m_q.enqueueTask(kernel, NULL, &events[evtHostWrite]));

	//read output size
	OCL_CHECK(err, err = m_q.enqueueReadBuffer(messageBuffer, CL_TRUE, 0, 2*sizeInBytes, message, NULL, NULL));

	LogInfo("EX2: Real execution of the algorithm to fill the output");

	//call a second time to measure on-chip throughput
	OCL_CHECK(err, err = m_q.enqueueTask(kernel, NULL, &events[evtKernelExec]));

	//copy results back from OpenCL buffer
	OCL_CHECK(err, err = m_q.enqueueReadBuffer(messageBuffer, CL_TRUE, 0, 2*sizeInBytes, message, NULL, &events[evtHostRead]));

	m_q.finish();
	return true;
}

bool RSAApp::run(int idevice, int nruns) {
	if (nruns <= 0)
		return false;

    cl_uchar  *p, *q, *p_r, *q_r,*dmp1, *dmq1, *iqmp, *dmp1_r,*dmq1_r, *iqmp_r;
	cl_uint r2p[32], r2q[32], Cp[32], Cq[32];
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
	print_big_number(ciphertext, 64, "ciphertext");

    RSA *rsa_key = PEM_read_RSAPrivateKey(key_fp, NULL, NULL, NULL);
	printf("n is \n");
	BN_print_fp(stdout, rsa_key->n);  
	printf("d is\n"); 
	BN_print_fp(stdout, rsa_key->d);  
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
	unsigned char *temp1=(unsigned char *) malloc(128*2);
	unsigned char *temp2=(unsigned char *) malloc(128*2);
	unsigned char *temp3=(unsigned char *) malloc(64*2);
	unsigned char *temp4=(unsigned char *) malloc(64*2);
	BN_CTX *ctx=NULL;
	if((ctx=BN_CTX_new())==NULL) printf("fail to create a new BN_CTX structure!\n");
	BN_CTX_start(ctx);
	BIGNUM *R2=BN_CTX_get(ctx);
	BIGNUM *R=BN_CTX_get(ctx);
	BN_one(R);
	BN_lshift(R,R,1024);

	BN_mul(R2,R,R,ctx);
	BN_mod(R2,R2,rsa_key->p,ctx);
	BN_bn2bin(R2,temp3);
	reverse_array(temp4,temp3,128);
    memcpy(r2p,temp4,128);

	BN_mul(R2,R,R,ctx);
	BN_mod(R2,R2,rsa_key->q,ctx);
	BN_bn2bin(R2,temp3);
	reverse_array(temp4,temp3,128);
    memcpy(r2q,temp4,128);

	//prepare C%p, C%q for CRT
	BIGNUM *C1=BN_CTX_get(ctx);
	BIGNUM *C=BN_CTX_get(ctx);
	reverse_array(temp1,(unsigned char *) &ciphertext[0],128*2);
	BN_bin2bn(temp1,128*2,C);
	BN_mod(C1,C,rsa_key->p,ctx);
	BN_bn2bin(C1,temp3);
	reverse_array(temp4,temp3,64*2);
    memcpy(Cp,temp4,64*2);
	print_big_number(Cp, n_size/8, "\n C mod p");

	BN_mod(C1,C,rsa_key->q,ctx);
	BN_bn2bin(C1,temp3);
	reverse_array(temp4,temp3,64*2);
    memcpy(Cq,temp4,64*2);
	print_big_number(Cq, n_size/8, "\n C mod q");

    print_big_number((uint *)p, n_size/8, "\n p");
    print_big_number((uint *)q, n_size/8, "\n q");
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	printf("start running kernel \n");

	//timings
	cl::Event events[evtCount];
	double durations[evtCount];
	for(int i=0; i < evtCount; i++)
		durations[i] = 0.0;

	//start time stamps
	double startMS = timestamp();


	//encode image
	LogInfo("Invoking rsa");
	bool res = invoke_kernel(m_clKernelRSA, message, Cp, Cq, (uint *)p,(uint *) q, (uint *)dmp1, (uint *)dmq1,
								(uint *)iqmp,r2p,r2q,&events[0]);
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
		uint sz_bytes = 32*4*2;

	    //bits per second
	    double tmp = (sz_bytes * 8.0) / (durations[evtHostWrite] / 1000.0);

	    //mega-bits per second
	    h2d_rate = tmp / (1024.0 * 1024.0);
	}

	//compute transfer rate for host read
	if(durations[evtHostRead] > 0) {
		uint sz_bytes = 32*4*2;

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

	print_big_number(message, 64, "message");
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

