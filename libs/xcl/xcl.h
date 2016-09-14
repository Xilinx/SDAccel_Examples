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

#include <xcl.h>
#include <CL/opencl.h>

typedef struct {
	char *mode;
	char *device_name;
	cl_context context;
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_command_queue command_queue;
} xcl_world;

/* xcl_world_single
 *
 * Description:
 *   Setup an xcl_world for the case when there is a single
 *   device in the system.
 *
 * Inputs:
 *
 * Returns:
 *   A struct containing the platform_id, device_id, context, and command
 *   queue.
 */
xcl_world xcl_world_single();

/* xcl_release_world
 *
 * Description:
 *   Release memory used by xcl_world struct.
 *
 * Inputs:
 *   world - xcl_world to release memory from.
 */
void xcl_release_world(xcl_world world);

/* xcl_import_binary
 *
 * Description:
 *   Import precompiled program (as commonly created by the Xilinx OpenCL
 *   flow).
 *
 * Inputs:
 *   world - xcl_world to import into.
 *   xclbin_file - base name of the xclbin to import.
 *   krnl_name - name of kernel.
 *
 * Returns:
 *   An opencl program object that was created from krnl_name file.
 */
cl_program xcl_import_binary(xcl_world world, const char *xclbin_file);

/* xcl_import_source
 *
 * Description:
 *   Import opencl source code.
 *
 * Inputs:
 *   world - xcl_world to import into.
 *   krnl_file - file name of the kernel to import.
 *   krnl_name - name of kernel.
 *
 * Returns:
 *   An opencl program object that was created from krnl_name file.
 */
cl_program xcl_import_source(xcl_world world, const char *krnl_file);

/* xcl_get_kernel
 *
 * Description:
 *   Get kernel from program
 *
 * Input:
 *   program - program that was built
 *   krnl_name - name of kernel
 *
 * Returns:
 *   An opencl kernel object that was created from the krnl_name
 */
cl_kernel xcl_get_kernel(cl_program program, const char *krnl_name);

/* xcl_set_kernel_arg
 *
 * Description:
 *   Set kernel arguments
 *
 * Inputs:
 *   krnl - kernel to set values for
 *   num  - which kernel arg to set
 *   size - size of argument
 *   ptr  - address of value
 */
void xcl_set_kernel_arg(cl_kernel krnl, cl_uint num, size_t size, const void *ptr);

/* xcl_malloc
 *
 * Description:
 *   Allocate memory for a buffer on the FPGA device.  Exit program on
 *   error.
 *
 * Inputs:
 *   world - xcl_world of the device to create buffer on.
 *   flags - passed to clCreateBuffer.
 *   size  - buffer size in bytes (like malloc).
 */
cl_mem xcl_malloc(xcl_world world, cl_mem_flags flags, size_t size);

/* xcl_memcpy_to_device/xcl_memcpy_from_device
 *
 * Description:
 *   Copy memory from the host to the FPGA device (or vice a verse.)  The
 *   memory on the FPGA must be allocated with xcl_malloc (or the lower
 *   level opencl functions)
 *
 * Inputs:
 *   world - xcl_world to copy the buffer into.
 *   dest  - memory address on the FPGA to copy to.
 *   src   - memory address on the host to copy from.
 *   size  - number of bytes in src to copy to dest.
 */
void xcl_memcpy_to_device(xcl_world world, cl_mem dest, void* src,
                          size_t size);
void xcl_memcpy_from_device(xcl_world world, void* dest, cl_mem src,
                            size_t size);

/* xcl_run_kernel3d
 *
 * Description:
 *   Run a kernel with a 3 dimensional thread array. In this configuration,
 *   there will be x*y*z threads created with a rank in each dimension.
 *
 * Inputs:
 *   world - xcl_world to use for running the kernel.
 *   krnl  - application to run on the device.
 *   x     - number of threads in the x direction.
 *   y     - number of threads in the y direction.
 *   z     - number of threads in the z direction.
 *
 * Returns:
 *   For purposes of benchmarking, the return of this program is the length of
 *   time that the kernel took to run to completion.
 */
unsigned long xcl_run_kernel3d(xcl_world world, cl_kernel krnl,
                               size_t x, size_t y, size_t z);
