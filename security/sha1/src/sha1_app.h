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
#pragma once

#define VC690_ADMPCIE7V3_1DDR_GEN2 1
#define M505_LX325T                2

#define XCL_DEVICE M505_LX325T

#define BLOCKS 16384
//#define BLOCKS 8
#define PIPELINE_DEPTH 165 

//#define DEBUG

#ifndef PIPELINE_DEPTH
#    if XCL_DEVICE == VC690_ADMPCIE7V3_1DDR_GEN2
#        define PIPELINE_DEPTH 167
#    elif XCL_DEVICE == M505_LX325T
#        define PIPELINE_DEPTH 167
#    else
         // Better safe than not meeting timing
#        define PIPELINE_DEPTH 512
#    endif
#endif

#ifndef BLOCKS
#    if XCL_DEVICE == VC690_ADMPCIE7V3_1DDR_GEN2
#        define BLOCKS 8192
#    elif XCL_DEVICE == M505_LX325T
#        define BLOCKS 8192 
#    else
         // Better safe than running too many kernel invocations
#        define BLOCKS 256
#    endif
#endif

#define CHANNELS (PIPELINE_DEPTH)

/* Using an int16 for the state */
#define STATEA s0
#define STATEB s1
#define STATEC s2
#define STATED s3
#define STATEE s4

#ifdef __OPENCL_VERSION__

typedef unsigned int u_int32_t;
typedef uint16 buf_t;
typedef uint16 state_t;

#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

void uint16_to_array(uint16 in, u_int32_t out[16]) {
    out[0]  = in.s0;
    out[1]  = in.s1;
    out[2]  = in.s2;
    out[3]  = in.s3;
    out[4]  = in.s4;
    out[5]  = in.s5;
    out[6]  = in.s6;
    out[7]  = in.s7;
    out[8]  = in.s8;
    out[9]  = in.s9;
    out[10] = in.sA;
    out[11] = in.sB;
    out[12] = in.sC;
    out[13] = in.sD;
    out[14] = in.sE;
    out[15] = in.sF;
}

void array_to_uint16(u_int32_t in[16], uint16 out) {
    out.s0 = in[0];
    out.s1 = in[1];
    out.s2 = in[2];
    out.s3 = in[3];
    out.s4 = in[4];
    out.s5 = in[5];
    out.s6 = in[6];
    out.s7 = in[7];
    out.s8 = in[8];
    out.s9 = in[9];
    out.sA = in[10];
    out.sB = in[11];
    out.sC = in[12];
    out.sD = in[13];
    out.sE = in[14];
    out.sF = in[15];
}

void uint_to_char_array(uint in, char out[4]) {
  out[0] = (in & 0x000000FF) >> 0;
  out[1] = (in & 0x0000FF00) >> 8;
  out[2] = (in & 0x00FF0000) >> 16;
  out[3] = (in & 0xFF000000) >> 24;
}

void uint16_to_char_array(uint16 in, char out[64]) {
    uint_to_char_array(in.s0, &out[0]);
    uint_to_char_array(in.s1, &out[4]);
    uint_to_char_array(in.s2, &out[8]);
    uint_to_char_array(in.s3, &out[12]);
    uint_to_char_array(in.s4, &out[16]);
    uint_to_char_array(in.s5, &out[20]);
    uint_to_char_array(in.s6, &out[24]);
    uint_to_char_array(in.s7, &out[28]);
    uint_to_char_array(in.s8, &out[32]);
    uint_to_char_array(in.s9, &out[36]);
    uint_to_char_array(in.sA, &out[40]);
    uint_to_char_array(in.sB, &out[44]);
    uint_to_char_array(in.sC, &out[48]);
    uint_to_char_array(in.sD, &out[52]);
    uint_to_char_array(in.sE, &out[56]);
    uint_to_char_array(in.sF, &out[60]);
}

void int_to_char4(int in, global char *out) {
  out[0] = (in & 0x000000FF) >> 0;
  out[1] = (in & 0x0000FF00) >> 8;
  out[2] = (in & 0x00FF0000) >> 16;
  out[3] = (in & 0xFF000000) >> 24;
}

#else

#include <string>
#include <CL/opencl.h>

typedef cl_uint16 buf_t;
typedef cl_uint16 state_t;

class sha1Runner {
  public:
    sha1Runner(cl_context context, cl_command_queue command_queue, cl_kernel kernel);
    ~sha1Runner();

     cl_event run(const unsigned int *bufs, unsigned int *mds);

  private:
    cl_context mContext;
    cl_command_queue mCommandQueue;
    cl_kernel mKernel;
    cl_mem mDevGBuf;
    cl_mem mDevGState;
    cl_event mEvents[4];
};

class sha1 {
public:
  sha1(std::string Vendor, std::string Device, const char* filename);
  ~sha1();

  sha1Runner createRunner();

private:
  void getVendorPlatform(std::string Vendor);
  void getDeviceIdByName(std::string Device);
  void createContext();
  void createProgram(const char* filename);
  void createKernelByName(std::string kernel_name);
  void createCommandQueue();
  void releaseCommandQueue();

  cl_platform_id mPlatformId;
  cl_device_id mDeviceId;

  cl_context mContext;
  cl_program mProgram;
  cl_kernel mKernel;
  cl_command_queue mCommandQueue;
};

#endif
