/*******************************************************************************
Vendor: Xilinx
Associated Filename: main.c
#Purpose: An example showing new kernels can be downloaded to FPGA while keeping
#         the data in device memory intact
#*******************************************************************************
Copyright (C) 2016 XILINX, Inc.

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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <xcl.h>

#define NUM_WORKGROUPS (1)
#define WORKGROUP_SIZE (1)
#define LENGTH 16

int main(int argc, char** argv)
{
   int err;                            // error code returned from api calls
   int check_status = 0;

   size_t global[1];                   // global domain size for our calculation
   size_t local[1];                    // local domain size for our calculation

   if (argc != 1) {
      printf("Usage: %s\n", argv[0]);
      return EXIT_FAILURE;
   }

   int h_a[LENGTH];                    // host memory for a vector
   int h_b[LENGTH];                    // host memory for b vector
   int h_c[LENGTH];                    // host memort for c vector

   // Fill our data sets with pattern
   //
   int i = 0;
   for (i = 0; i < LENGTH; i++) {
      h_a[i] = i;
      h_b[i] = i;
      h_c[i] = 0;
   }

   xcl_world world = xcl_world_single();

   cl_mem d_a = xcl_malloc(world, CL_MEM_READ_ONLY, sizeof(int) * LENGTH);
   cl_mem d_b = xcl_malloc(world, CL_MEM_READ_ONLY, sizeof(int) * LENGTH);
   cl_mem d_mul_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, sizeof(int) * LENGTH);

   xcl_memcpy_to_device(world, d_a, h_a, sizeof(int) * LENGTH);
   xcl_memcpy_to_device(world, d_b, h_b, sizeof(int) * LENGTH);

   printf("INFO: loading vmul kernel\n");
   cl_program program_vmul = xcl_import_binary(world, "krnl_vmul");
   cl_kernel  krnl_vmul = xcl_get_kernel(program_vmul, "krnl_vmul");

   err = 0;
   err  = clSetKernelArg(krnl_vmul, 0, sizeof(cl_mem), &d_a);
   err |= clSetKernelArg(krnl_vmul, 1, sizeof(cl_mem), &d_b);
   err |= clSetKernelArg(krnl_vmul, 2, sizeof(cl_mem), &d_mul_c);
   if (err != CL_SUCCESS) {
      printf("Error: Failed to set kernel arguments! %d\n", err);
      return EXIT_FAILURE;
   }

   // Execute the kernel over the entire range of our 1d input data set
   // using the maximum number of work group items for this device
   //
   global[0] = NUM_WORKGROUPS * WORKGROUP_SIZE;
   local[0] = WORKGROUP_SIZE;
   err = clEnqueueNDRangeKernel(world.command_queue, krnl_vmul, 1, NULL,
                                (size_t*)&global, (size_t*)&local, 0, NULL, NULL);

   if (err) {
      printf("Error: Failed to execute kernel! %d\n", err);
      return EXIT_FAILURE;
   }

   xcl_memcpy_from_device(world, h_c, d_mul_c, sizeof(int) * LENGTH);

   // Check Results
   for (int i = 0; i < LENGTH; i++) {
      if ((h_a[i] * h_b[i]) != h_c[i]) {
         printf("ERROR in vmul - %d - a=%d, b=%d, c=%d\n", i, h_a[i], h_b[i], h_c[i]);
         check_status = 1;
      }
   }

   printf("INFO: loading vadd_krnl\n");
   cl_program program_vadd = xcl_import_binary(world, "krnl_vadd");
   cl_kernel krnl_vadd = xcl_get_kernel(program_vadd, "krnl_vadd");

   cl_mem d_add_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, sizeof(int) * LENGTH);

   // Set the arguments to our compute kernel
   //
   err = 0;
   //use the results from vmul as a and b inputs for vadd
   err  = clSetKernelArg(krnl_vadd, 0, sizeof(cl_mem), &d_mul_c);
   err |= clSetKernelArg(krnl_vadd, 1, sizeof(cl_mem), &d_mul_c);
   err |= clSetKernelArg(krnl_vadd, 2, sizeof(cl_mem), &d_add_c);
   if (err != CL_SUCCESS) {
      printf("Error: Failed to set kernel arguments! %d\n", err);
      return EXIT_FAILURE;
   }

   // Execute the kernel over the entire range of our 1d input data set
   // using the maximum number of work group items for this device
   //
   global[0] = NUM_WORKGROUPS * WORKGROUP_SIZE;
   local[0] = WORKGROUP_SIZE;
   err = clEnqueueNDRangeKernel(world.command_queue, krnl_vadd, 1, NULL,
                                 (size_t*)&global, (size_t*)&local, 0, NULL, NULL);
   if (err) {
      printf("Error: Failed to execute kernel! %d\n", err);
      return EXIT_FAILURE;
   }

   xcl_memcpy_from_device(world, h_c, d_add_c, sizeof(int) * LENGTH);

   // Check Results
   for (int i = 0; i < LENGTH; i++) {
      if ((2*(h_a[i] * h_b[i])) != h_c[i]) {
         printf("ERROR in vadd - %d - c=%d\n", i, h_c[i]);
         check_status = 1;
      }
   }

   //--------------------------------------------------------------------------
   // Shutdown and cleanup
   //--------------------------------------------------------------------------
   clReleaseMemObject(d_a);
   clReleaseMemObject(d_b);
   clReleaseMemObject(d_add_c);
   clReleaseMemObject(d_mul_c);
   clReleaseKernel(krnl_vmul);
   clReleaseKernel(krnl_vadd);
   clReleaseProgram(program_vmul);
   clReleaseProgram(program_vadd);
   xcl_release_world(world);

   if (check_status) {
      printf("INFO: Test failed\n");
      return EXIT_FAILURE;
   } else {
      printf("INFO: Test passed\n");
   }
}
