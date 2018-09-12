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

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS

#include <CL/opencl.h>

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

static void* smalloc(size_t size) {
  void* ptr;
  
  ptr = malloc(size);
  
  if (ptr == NULL) {
    printf("Error: Cannot allocate memory\n");
    exit(EXIT_FAILURE);
  }
  
  return ptr;
}


static int load_file_to_memory(const char *filename, char **result) {
  unsigned int size;
  
  FILE *f = fopen(filename, "rb");
  if (f == NULL) {
    *result = NULL;
    printf("Error: Could not read file %s\n", filename);
    exit(EXIT_FAILURE);
  }
  
  fseek(f, 0, SEEK_END);
  size = ftell(f);
  fseek(f, 0, SEEK_SET);
  
  *result = (char *) smalloc(sizeof(char)*(size+1));
  
  if (size != fread(*result, sizeof(char), size, f)) {
    free(*result);
    printf("Error: read of kernel failed\n");
    exit(EXIT_FAILURE);
  }
  
  fclose(f);
  (*result)[size] = 0;
  
  return size;
}



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


    if (argc != 5) {
      printf("Usage: %s <xclbin> #row #col #depth\n", argv[0]);
      return EXIT_FAILURE;

    }
    
    char* xclbin_file_name = argv[1];
      
    // round of the input sizes to the GEMM requirement
    int num_of_rows = roundup(atoi(argv[2]), 32);
    int num_of_cols = roundup(atoi(argv[3]), 64);
    int depth       = roundup(atoi(argv[4]), 64);

    //------------------------------------------------------------------------------
    // SETUP SDACCEL PLATFROM
    //------------------------------------------------------------------------------

    std::cout << "Creating context..." << std::endl;
    cl_context context;
    cl_platform_id platform_id;
    cl_device_id device_id;
    cl_command_queue command_queue;
    char *device_name;

    cl_uint num_platforms;

    err = clGetPlatformIDs(0, NULL, &num_platforms);
    if (err != CL_SUCCESS) {
      printf("Error: no platforms available or OpenCL install broken\n");
      exit(EXIT_FAILURE);
    }

    cl_platform_id *platform_ids = (cl_platform_id *) malloc(sizeof(cl_platform_id) * num_platforms);
    if (platform_ids == NULL) {
      printf("Error: Out of Memory\n");
      exit(EXIT_FAILURE);
    }

    err = clGetPlatformIDs(num_platforms, platform_ids, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to find an OpenCL platform!\n");
      exit(EXIT_FAILURE);
    }

    size_t index;
    for(index = 0; index < num_platforms; index++) {
      size_t platform_name_size;
      err = clGetPlatformInfo(platform_ids[index], CL_PLATFORM_NAME, 
			      0, NULL, &platform_name_size);
      if( err != CL_SUCCESS) {
	printf("Error: Could not determine platform name!\n");
	exit(EXIT_FAILURE);
      }

      char *platform_name = (char*) malloc(sizeof(char)*platform_name_size);
      if(platform_name == NULL) {
	printf("Error: out of memory!\n");
	exit(EXIT_FAILURE);
      }

      err = clGetPlatformInfo(platform_ids[index], CL_PLATFORM_NAME,
			      platform_name_size, platform_name, NULL);
      if(err != CL_SUCCESS) {
	printf("Error: could not determine platform name!\n");
	exit(EXIT_FAILURE);
      }

      if (!strcmp(platform_name, "Xilinx")) {
	free(platform_name);
	platform_id = platform_ids[index];
	break;
      }
      
      free(platform_name);
    }

    free(platform_ids);

    if (index == num_platforms) {
      printf("Error: Failed to find Xilinx platform\n");
      exit(EXIT_FAILURE);
    }

    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL,
			 1, &device_id, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: could not get device ids\n");
      exit(EXIT_FAILURE);
    }

    size_t device_name_size;
    err = clGetDeviceInfo(device_id, CL_DEVICE_NAME,
			  0, NULL, &device_name_size);
    if(err != CL_SUCCESS) {
      printf("Error: could not determine device name\n");
      exit(EXIT_FAILURE);
    }

    device_name = (char*) malloc(sizeof(char)*device_name_size);
    
    if(device_name == NULL) {
      printf("Error: Out of Memory!\n");
      exit(EXIT_FAILURE);
    }
    
    err = clGetDeviceInfo(device_id, CL_DEVICE_NAME,
			  device_name_size, device_name, NULL);
    if(err != CL_SUCCESS) {
      printf("Error: could not determine device name\n");
      exit(EXIT_FAILURE);
    }
    
    context = clCreateContext(0, 1, &device_id,
			      NULL, NULL, &err);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to create a compute context!\n");
      exit(EXIT_FAILURE);
    }
    
    command_queue = clCreateCommandQueue(context,
					 device_id,
					 CL_QUEUE_PROFILING_ENABLE,
					 &err);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to create a command queue!\n");
      exit(EXIT_FAILURE);
    }

    printf("INFO: Importing %s\n", xclbin_file_name);
    
    if(access(xclbin_file_name, R_OK) != 0) {
      printf("ERROR: %s xclbin not available please build\n", xclbin_file_name);
      exit(EXIT_FAILURE);
    }

    char *krnl_bin;
    const size_t krnl_size = load_file_to_memory(xclbin_file_name, &krnl_bin);
    printf("INFO: Loaded file\n");

    cl_program program = clCreateProgramWithBinary(context, 1,
						   &device_id, &krnl_size,
						   (const unsigned char**) &krnl_bin,
						   NULL, &err);
    if ((!program) || (err!=CL_SUCCESS)) {
      printf("Error: Failed to create compute program from binary %d!\n",
	     err);
      printf("Test failed\n");
      exit(EXIT_FAILURE);
    }

    printf("INFO: Created Binary\n");

    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
      size_t len;
      char buffer[2048];
      
      clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG,
			    sizeof(buffer), buffer, &len);
      printf("%s\n", buffer);
      printf("Error: Failed to build program executable!\n");
      exit(EXIT_FAILURE);
    }

    printf("INFO: Built Program\n");

    free(krnl_bin);
    const char *krnl_name = "kernelSgemm_0";
    cl_kernel kernelSgemm_0 = clCreateKernel(program, krnl_name, &err);
    if (!kernelSgemm_0 || err != CL_SUCCESS) {
      printf("Error: Failed to create kernel for %s: %d\n", krnl_name, err);
      exit(EXIT_FAILURE);
    }

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

    cl_mem_ext_ptr_t d_a_ext={0};
    cl_mem_ext_ptr_t d_b_ext={0};
    cl_mem_ext_ptr_t d_d_ext={0};
    cl_mem_ext_ptr_t d_c_ext={0};

    d_a_ext.flags = XCL_MEM_DDR_BANK3; //A --> bank3
    d_a_ext.obj = NULL;// h_a;
    d_a_ext.param = 0;

    d_b_ext.flags = XCL_MEM_DDR_BANK3; //B0 --> bank3
    d_b_ext.obj = NULL; //h_b;
    d_b_ext.param = 0;

#if defined(VU9P) || defined(VCU1525) || defined(U200) || defined(U250)    
    d_d_ext.flags = XCL_MEM_DDR_BANK1; //B1 --> bank1
    d_d_ext.obj = NULL; //h_d;
    d_d_ext.param = 0;

    d_c_ext.flags = XCL_MEM_DDR_BANK1; //C --> bank1
    d_c_ext.obj = NULL; //h_c;
    d_c_ext.param = 0;
#else
    d_d_ext.flags = XCL_MEM_DDR_BANK2; //B1 --> bank2
    d_d_ext.obj = NULL; //h_d;
    d_d_ext.param = 0;

    d_c_ext.flags = XCL_MEM_DDR_BANK2; //C --> bank2
    d_c_ext.obj = NULL; //h_c;
    d_c_ext.param = 0;
#endif
    
    std::cout << "Creating Buffers..." << std::endl;
    cl_mem d_a;                         // device memory used for a vector
    cl_mem d_b;                         // device memory used for b vector
    cl_mem d_d;                         // device memory used for b vector
    cl_mem d_c;                         // device memory used for c vector

    d_a = clCreateBuffer(context, CL_MEM_READ_ONLY |  CL_MEM_EXT_PTR_XILINX, sizeof(short) * num_of_rows * depth, &d_a_ext, &err);
    assert(err == CL_SUCCESS);
    d_b = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * (num_of_cols/2) * depth , &d_b_ext, &err);
    assert(err == CL_SUCCESS);
    d_d = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * (num_of_cols/2) * depth , &d_d_ext, &err);
    assert(err == CL_SUCCESS);
    d_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX,  sizeof(short) * num_of_rows * num_of_cols, &d_c_ext, &err);
    assert(err == CL_SUCCESS);

    std::cout << "Copying Buffers to device...." << std::endl;
    err = clEnqueueWriteBuffer(command_queue, d_a, CL_TRUE, 0, sizeof(short) * num_of_rows * depth,
			       h_a, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to write to source array! %d\n", err);
      exit(EXIT_FAILURE);
    }
    err = clEnqueueWriteBuffer(command_queue, d_b, CL_TRUE, 0, sizeof(short) * (num_of_cols/2) * depth,
			       h_b, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to write to source array! %d\n", err);
      exit(EXIT_FAILURE);
    }
    err = clEnqueueWriteBuffer(command_queue, d_d, CL_TRUE, 0, sizeof(short) * (num_of_cols/2) * depth,
			       h_d, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to write to source array! %d\n", err);
      exit(EXIT_FAILURE);
    }

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
    err = clEnqueueTask(command_queue, kernelSgemm_0, 0, NULL, &ks_0_event);
    if (err) {
            printf("Error: Failed to execute kernelSgemm_0! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    err = clFinish(command_queue);
    assert(err == CL_SUCCESS);

    std::cout << "Copying results to host...." << std::endl;
    // READ BACK THE RESULTS FROM THE DEVICE TO VERIFY THE OUTPUT
    err = clEnqueueReadBuffer(command_queue, d_c, CL_TRUE, 0, sizeof(short) * num_of_rows * num_of_cols,
			      h_c, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
      printf("Error: Failed to read output array! %d\n", err);
      exit(EXIT_FAILURE);
    }

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
   clReleaseCommandQueue(command_queue);
   clReleaseContext(context);
   free(device_name);

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
