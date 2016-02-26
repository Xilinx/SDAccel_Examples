#Copyright (c) 2016, Xilinx, Inc.
#All rights reserved.
#
#Redistribution and use in source and binary forms, with or without modification,
#are permitted provided that the following conditions are met:
#
#1. Redistributions of source code must retain the above copyright notice,
#this list of conditions and the following disclaimer.
#
#2. Redistributions in binary form must reproduce the above copyright notice,
#this list of conditions and the following disclaimer in the documentation
#and/or other materials provided with the distribution.
#
#3. Neither the name of the copyright holder nor the names of its contributors
#may be used to endorse or promote products derived from this software
#without specific prior written permission.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
#OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# SDAccel Application Example - Hello World

create_solution -name hello_app -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

# Execution arguments for the application
set args "bin_hello.xclbin"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)" -objects [current_solution]

# Host source files
add_files "hello.cpp"
add_files "xcl.c"
add_files "hello.h"
set_property file_type "c header files" [get_files "hello.h"]
add_files "xcl.h"
set_property file_type "c header files" [get_files "xcl.h"]

# Kernel Definition
create_kernel krnl_hello -type clc
add_files -kernel [get_kernels krnl_hello] "krnl_hello.cl"

# Define Binary Containers
create_opencl_binary bin_hello
set_property region "OCL_REGION_0" [get_opencl_binary bin_hello]
create_compute_unit -opencl_binary [get_opencl_binary bin_hello] -kernel [get_kernels krnl_hello] -name cu_hello0

# Compile the design for CPU based emulation
compile_emulation -flow cpu
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system
