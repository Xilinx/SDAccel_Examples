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

#define CL_HPP_CL_1_2_DEFAULT_BUILD
#define CL_HPP_TARGET_OPENCL_VERSION 120
#define CL_HPP_MINIMUM_OPENCL_VERSION 120
#define CL_HPP_ENABLE_PROGRAM_CONSTRUCTION_FROM_ARRAY_COMPATIBILITY 1

#include <CL/cl2.hpp>
#include <iostream>
#include <fstream>

namespace xcl {
std::vector<cl::Device> get_xil_devices();
std::vector<cl::Device> get_devices(const std::string& vendor_name);
/* find_xclbin_file
 *
 *
 * Description:
 *   Find precompiled program (as commonly created by the Xilinx OpenCL
 *   flow). Using search path below.
 *
 *   Search Path:
 *      $XCL_BINDIR/<name>.<target>.<device>.xclbin
 *      $XCL_BINDIR/<name>.<target>.<device_versionless>.xclbin
 *      $XCL_BINDIR/binary_container_1.xclbin
 *      $XCL_BINDIR/<name>.xclbin
 *      xclbin/<name>.<target>.<device>.xclbin
 *      xclbin/<name>.<target>.<device_versionless>.xclbin
 *      xclbin/binary_container_1.xclbin
 *      xclbin/<name>.xclbin
 *      ../<name>.<target>.<device>.xclbin
 *      ../<name>.<target>.<device_versionless>.xclbin
 *      ../binary_container_1.xclbin
 *      ../<name>.xclbin
 *      ./<name>.<target>.<device>.xclbin
 *      ./<name>.<target>.<device_versionless>.xclbin
 *      ./binary_container_1.xclbin
 *      ./<name>.xclbin
 *
 * Inputs:
 *   _device_name - Targeted Device name
 *   xclbin_name - base name of the xclbin to import.
 *
 * Returns:
 *   An opencl program Binaries object that was created from xclbin_name file.
 */
std::string find_binary_file(const std::string& _device_name, const std::string& xclbin_name);
cl::Program::Binaries import_binary_file(std::string xclbin_file_name); 
bool is_emulation () ;

}
