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

   printf("INFO: loading vmul kernel\n");
   cl_program program_vmul = xcl_import_binary(world, "krnl_vmul");
   cl_kernel  krnl_vmul = xcl_get_kernel(program_vmul, "krnl_vmul");

   cl_mem d_a = xcl_malloc(world, CL_MEM_READ_ONLY, sizeof(int) * LENGTH);
   cl_mem d_b = xcl_malloc(world, CL_MEM_READ_ONLY, sizeof(int) * LENGTH);
   cl_mem d_mul_c = xcl_malloc(world, CL_MEM_READ_WRITE, sizeof(int) * LENGTH);

   xcl_memcpy_to_device(world, d_a, h_a, sizeof(int) * LENGTH);
   xcl_memcpy_to_device(world, d_b, h_b, sizeof(int) * LENGTH);

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

   //XPR Platform (Xilinx Extended Partial Reconfiguration Platform) supports larger Kernel
   // binaries compare to non-XPR Platform. However this platform has one limitation with
   // respect non-XPR, it does not persist the Global Memory(DDR) content when user switches
   // between multiple binaries. So for such case, user should be responsible to 
   // migrate the required buffer from device to host and later use migrate buffer back to
   // device after second binary is imported
   
   // Migrating Buffer from Device to Host
   err = clEnqueueMigrateMemObjects(world.command_queue, 1, &d_mul_c,CL_MIGRATE_MEM_OBJECT_HOST,
                                   0, NULL, NULL);

   if (err){
      printf("Error: Failed to execute clEnqueueMigrateMemObjects()! %d\n", err);
      return EXIT_FAILURE;
   }

   printf("INFO: loading vadd_krnl\n");
   cl_program program_vadd = xcl_import_binary(world, "krnl_vadd");
   cl_kernel krnl_vadd = xcl_get_kernel(program_vadd, "krnl_vadd");

   cl_mem d_add_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, sizeof(int) * LENGTH);


   //Migrating the buffer from Host to Device
   err = clEnqueueMigrateMemObjects(world.command_queue, 1, &d_mul_c,
                                   0 /* flags, 0 means from host to device */,
                                   0, NULL, NULL);

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
