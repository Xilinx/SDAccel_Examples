/**********
Copyright (c) 2017, Xilinx, Inc.
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

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <CL/opencl.h>
#include <CL/cl_ext.h>

#include "xcl.h"

////////////////////////////////////////////////////////////////////////////////

#define NUM_WORKGROUPS (1)
#define WORKGROUP_SIZE (256)
#define DEPTH 32
#define NUM_OF_ROWS 64
#define NUM_OF_COLS 64
#define PARALLEL_ROWS 32
#define PARALLEL_COLS 32
#define ROW_MULT (NUM_OF_ROWS/PARALLEL_ROWS)
#define COL_MULT (NUM_OF_COLS/PARALLEL_COLS)
#define TWO_KERN false // enable both kernels

////////////////////////////////////////////////////////////////////////////////

int roundup ( int num, int multiple){
	if ( num == 0)
	  return 0;

	int remainder = num % multiple;

	if (remainder == 0)
	 return num;
	else
	 return num + multiple - remainder;

}



int main(int argc, char** argv)
{

    int err = 0;                            // error code returned from api calls
    int check_status = 0;

    short *h_a;
    short *h_b;
    short *h_d;
    short *h_c;

    short *tb_a;
    short *tb_b;
    short *tb_c;

    //------------------------------------------------------------------------------
    // SETUP SDACCEL PLATFROM
    //------------------------------------------------------------------------------

    std::cout << "Creating context..." << std::endl;
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "high_perf_mat_mult0");    // compute programs
    cl_kernel kernelSgemm_0 = xcl_get_kernel(program, "kernelSgemm_0");    // compute kernel

    if (argc != 4) {
        printf("Usage: %s #row, #col, #depth\n", argv[0]);
        return EXIT_FAILURE;
    }

    // round of the input sizes to the GEMM requirement
    int num_of_rows = roundup(atoi(argv[1]), 32);
    int num_of_cols = roundup(atoi(argv[2]), 64);
    int depth       = roundup(atoi(argv[3]), 64);

    int row_mult    = num_of_rows/PARALLEL_ROWS;
    int col_mult    = (num_of_cols/2)/PARALLEL_COLS;

    int row         = row_mult;
    int col         = col_mult;

    int i           = 0;
    int j           = 0;
    int k           = 0;
    printf ("INFO: input matrix size: M= %d, N= %d, K= %d\n",num_of_rows, num_of_cols, depth);
    printf ("INFO: hw matrix size: row= %d, col= %d, depth= %d\n", row, col, depth);


    h_a = (short *) malloc(num_of_rows*depth*sizeof(short));
    h_b = (short *) malloc((num_of_cols/2)*depth*sizeof(short));
    h_d = (short *) malloc((num_of_cols/2)*depth*sizeof(short));
    h_c = (short *) malloc(num_of_rows*num_of_cols*sizeof(short));

    tb_a = (short *) malloc(num_of_rows*depth*sizeof(short));
    tb_b = (short *) malloc(num_of_cols*depth*sizeof(short));
    tb_c = (short *) malloc(num_of_rows*num_of_cols*sizeof(short));

     for ( i = 0; i < row_mult ; i++){
       for( j = 0; j < depth; j++) {
         for ( k = 0; k < PARALLEL_ROWS; k++){
           h_a[(i*depth*PARALLEL_ROWS) + (j*PARALLEL_ROWS) + k] = (i*PARALLEL_ROWS)+k+j;
         }
       }
     }

     for ( i = 0; i < col_mult ; i++){
       for( j = 0; j < depth; j++) {
         for ( k = 0; k < PARALLEL_COLS; k++){
           h_b[(i*depth*PARALLEL_COLS) + (j*PARALLEL_COLS) + k] = (i*PARALLEL_COLS*2)+k;
           h_d[(i*depth*PARALLEL_COLS) + (j*PARALLEL_COLS) + k] = (i*PARALLEL_COLS*2)+k+32;
         }
       }
     }

     for ( i = 0; i < num_of_rows*num_of_cols ; i++){
       h_c[i] = -2;
     }

     // INITIALIZING TEST MATRICES
     for ( int i = 0; i < num_of_rows ; i++){
       for( int j = 0; j < depth; j++) {
         tb_a[i*depth + j] = i+j;
       }
     }

     for ( int j = 0; j < depth; j++) {
       for ( int i = 0; i < num_of_cols ; i++){
         tb_b[j*num_of_cols + i] = i;
       }
     }

     // COMPUTE GOLDEN OUTPUT
     for(int i = 0; i < num_of_rows; i++) {
       for(int j = 0; j < num_of_cols; j++) {
         int sum = 0;
         for(int k = 0; k < depth; k++) {
           int temp= tb_a[i*depth+k] * tb_b[k*num_of_cols+j];
           sum += temp;
         }
         tb_c[i*num_of_cols+j] = (short) (sum>>16); // middle 16 bits are used as output
       }
     }

    // CREATE THE INPUT AND OUTPUT ARRAYS IN DEVICE MEMORY FOR OUR CALCULATION

    cl_mem_ext_ptr_t d_a_ext;
    cl_mem_ext_ptr_t d_b_ext;
    cl_mem_ext_ptr_t d_d_ext;
    cl_mem_ext_ptr_t d_c_ext;

#ifdef VU9P
    d_a_ext.flags = XCL_MEM_DDR_BANK2; //A --> bank2
#else
    d_a_ext.flags = XCL_MEM_DDR_BANK0; //A --> bank0
#endif
    d_a_ext.obj = NULL;// h_a;
    d_a_ext.param = 0;

#ifdef VU9P
    d_b_ext.flags = XCL_MEM_DDR_BANK2; //B0 --> bank2
#else
    d_b_ext.flags = XCL_MEM_DDR_BANK0; //B0 --> bank0
#endif
    d_b_ext.obj = NULL; //h_b;
    d_b_ext.param = 0;

#ifdef VU9P
    d_d_ext.flags = XCL_MEM_DDR_BANK3; //B1 --> bank3
#else
    d_d_ext.flags = XCL_MEM_DDR_BANK1; //B1 --> bank1
#endif
    d_d_ext.obj = NULL; //h_d;
    d_d_ext.param = 0;

#ifdef VU9P
    d_c_ext.flags = XCL_MEM_DDR_BANK3; //C --> bank3
#else
    d_c_ext.flags = XCL_MEM_DDR_BANK1; //C --> bank1
#endif
    d_c_ext.obj = NULL; //h_c;
    d_c_ext.param = 0;

    std::cout << "Creating Buffers..." << std::endl;
    cl_mem d_a;                         // device memory used for a vector
    cl_mem d_b;                         // device memory used for b vector
    cl_mem d_d;                         // device memory used for b vector
    cl_mem d_c;                         // device memory used for c vector

    d_a = clCreateBuffer(world.context, CL_MEM_READ_ONLY |  CL_MEM_EXT_PTR_XILINX, sizeof(short) * num_of_rows * depth, &d_a_ext, &err);
    assert(err == CL_SUCCESS);
    d_b = clCreateBuffer(world.context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * (num_of_cols/2) * depth , &d_b_ext, &err);
    assert(err == CL_SUCCESS);
    d_d = clCreateBuffer(world.context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * (num_of_cols/2) * depth , &d_d_ext, &err);
    assert(err == CL_SUCCESS);
    d_c = clCreateBuffer(world.context, CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * num_of_rows * num_of_cols, &d_c_ext, &err);
    assert(err == CL_SUCCESS);

    std::cout << "Copying Buffers to device...." << std::endl;
    xcl_memcpy_to_device(world,d_a,h_a,sizeof(short) * num_of_rows * depth);
    xcl_memcpy_to_device(world,d_b,h_b,sizeof(short) * (num_of_cols/2) * depth);
    xcl_memcpy_to_device(world,d_d,h_d,sizeof(short) * (num_of_cols/2) * depth);

    // SET THE ARGUMENTS TO COMPUTE FIRST KERNEL
    err |= clSetKernelArg(kernelSgemm_0, 0, sizeof(int), &row);
    err |= clSetKernelArg(kernelSgemm_0, 1, sizeof(int), &col);
    err |= clSetKernelArg(kernelSgemm_0, 2, sizeof(int), &depth);
    err |= clSetKernelArg(kernelSgemm_0, 3, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernelSgemm_0, 4, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernelSgemm_0, 5, sizeof(cl_mem), &d_d);
    err |= clSetKernelArg(kernelSgemm_0, 6, sizeof(cl_mem), &d_c);

    // EXECUTE THE KERNEL OVER THE INPUT DATA SET
    cl_event ks_0_event;
    err = clEnqueueTask(world.command_queue, kernelSgemm_0, 0, NULL, &ks_0_event);
    if (err) {
            printf("Error: Failed to execute kernelSgemm_0! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    err = clFinish(world.command_queue);
    assert(err == CL_SUCCESS);

    std::cout << "Copying results to host...." << std::endl;
    // READ BACK THE RESULTS FROM THE DEVICE TO VERIFY THE OUTPUT
    xcl_memcpy_from_device(world, h_c, d_c, sizeof(short) * num_of_rows * num_of_cols);

    printf ("INFO: Execution done\n");

    int count = 0;

    // CHECK RESULTS
    for ( int i = 0 ; i < num_of_rows/PARALLEL_ROWS ; i++) {
      for ( int j = 0 ; j < num_of_cols/64; j++) {
        for ( int k = 0 ; k < PARALLEL_ROWS; k++){
          for ( int h = 0; h < 64; h++){
            int index = ((i*PARALLEL_ROWS) + k )*num_of_cols + (j*64) + h;

            if (tb_c[index] != h_c[count]) {
              printf("ERROR in - %d - actual=%d, expected=%d\n", count, h_c[count], tb_c[index]);
              check_status = 1;
              goto DONE; 
            }

            count++;
         }
       }
     }
   }

   //--------------------------------------------------------------------------
   // SHUTDOWN AND CLEANUP
   //--------------------------------------------------------------------------
DONE:
   // COMPUTE KERNEL TIME AND EFFICIENCY
   size_t ks_0_start, ks_0_end, time_start, time_end;
   clGetEventProfilingInfo(ks_0_event, CL_PROFILING_COMMAND_SUBMIT,
                           sizeof(ks_0_start), &ks_0_start, NULL);
   clGetEventProfilingInfo(ks_0_event, CL_PROFILING_COMMAND_END,
                           sizeof(ks_0_end), &ks_0_end, NULL);

   time_start = ks_0_start;
   time_end   = ks_0_end;

   double numOps     = num_of_rows*num_of_cols*depth*2;
   double total_time = (time_end - time_start)/1000000000.0;
   double efficiency = (numOps / total_time)/1000000000.0;
   printf("INFO: kernel time %f seconds numOfOps %f Efficiency: %f GOPs\n",total_time, numOps, efficiency);

   clReleaseMemObject(d_a);
   clReleaseMemObject(d_b);
   clReleaseMemObject(d_d);
   clReleaseMemObject(d_c);
   clReleaseProgram(program);
   clReleaseKernel(kernelSgemm_0);
   xcl_release_world(world);

   free(h_a);
   free(h_b);
   free(h_c);

   free(tb_a);
   free(tb_b);
   free(tb_c);

   if (check_status) {
     printf("INFO: Test Failed\n");
     return EXIT_FAILURE;
   } else {
     printf("INFO: Test Passed\n");
   }
}
