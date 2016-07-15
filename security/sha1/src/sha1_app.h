/*******************************************************************************
Vendor: Xilinx
Associated Filename: sha1_app.h
Purpose: SHA1 Example Application 
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
