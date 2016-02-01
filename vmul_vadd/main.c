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

////////////////////////////////////////////////////////////////////////////////

#define NUM_WORKGROUPS (1)
#define WORKGROUP_SIZE (1)
#define LENGTH 16

////////////////////////////////////////////////////////////////////////////////

int
load_file_to_memory(const char *filename, char **result)
{
    int size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        {
            *result = NULL;
            return -1; // -1 means file opening fail
        }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    *result = (char *)malloc(size+1);
    if (size != fread(*result, sizeof(char), size, f))
        {
            free(*result);
            return -2; // -2 means file reading fail
        }
    fclose(f);
    (*result)[size] = 0;
    return size;
}

int main(int argc, char** argv)
{
    int err;                            // error code returned from api calls
    int check_status = 0;

    int h_a[LENGTH];                    // host memory for a vector
    int h_b[LENGTH];                    // host memory for b vector
    int h_c[LENGTH];                    // host memort for c vector

    size_t global[1];                   // global domain size for our calculation
    size_t local[1];                    // local domain size for our calculation

    cl_platform_id platform_id;         // platform id
    cl_device_id device_id;             // compute device id
    cl_context context;                 // compute context
    cl_command_queue commands;          // compute command queue
    cl_program program0, program1;      // compute programs
    cl_kernel kernel;                   // compute kernel

    char cl_platform_vendor[1001];
    char cl_platform_name[1001];

    cl_mem d_a;                         // device memory used for a vector
    cl_mem d_b;                         // device memory used for b vector
    cl_mem d_mul_c;                     // device memory used for c vector from vmul
    cl_mem d_add_c;                     // device memory used for c vector from vadd

    if (argc != 3) {
        printf("Usage: %s xclbin0 xclbin1\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Fill our data sets with pattern
    //
    int i = 0;
    for(i = 0; i < LENGTH; i++) {
        h_a[i] = i;
        h_b[i] = i;
        h_c[i] = 0;
    }


    // Connect to first platform
    //
    err = clGetPlatformIDs(1,&platform_id,NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to find an OpenCL platform!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    err = clGetPlatformInfo(platform_id,CL_PLATFORM_VENDOR,1000,(void *)cl_platform_vendor,NULL);
    if (err != CL_SUCCESS) {
        printf("Error: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    printf("INFO: CL_PLATFORM_VENDOR %s\n",cl_platform_vendor);
    err = clGetPlatformInfo(platform_id,CL_PLATFORM_NAME,1000,(void *)cl_platform_name,NULL);
    if (err != CL_SUCCESS) {
        printf("Error: clGetPlatformInfo(CL_PLATFORM_NAME) failed!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    printf("INFO: CL_PLATFORM_NAME %s\n",cl_platform_name);

    // Connect to a compute device
    //
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR,
                         1, &device_id, NULL);
    if (err != CL_SUCCESS) {
            printf("Error: Failed to create a device group!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Create a compute context
    //
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context) {
        printf("Error: Failed to create a compute context!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create a command commands
    //
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands) {
        printf("Error: Failed to create a command commands!\n");
        printf("Error: code %i\n",err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    int status;

    // Create Program Objects
    //

    // Load binary from disk
    unsigned char *kernelbinary0, *kernelbinary1;
    char *xclbin0 = argv[1];
    char *xclbin1 = argv[2];

    //------------------------------------------------------------------------------
    // xclbin 0
    //------------------------------------------------------------------------------
    printf("INFO: loading xclbin0 %s\n", xclbin0);
    int n_i0 = load_file_to_memory(xclbin0, (char **) &kernelbinary0);
    if (n_i0 < 0) {
        printf("failed to load kernel from xclbin0: %s\n", xclbin0);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    size_t n0 = n_i0;

    // Create the compute program from offline
    program0 = clCreateProgramWithBinary(context, 1, &device_id, &n0,
                                        (const unsigned char **) &kernelbinary0, &status, &err);

    if ((!program0) || (err!=CL_SUCCESS)) {
        printf("Error: Failed to create compute program0 from binary %d!\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Build the program executable
    //
    err = clBuildProgram(program0, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program0, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create the compute kernel in the program we wish to run
    //
    kernel = clCreateKernel(program0, "krnl_vmul", &err);
    if (!kernel || err != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create the input and output arrays in device memory for our calculation
    //
    d_a = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * LENGTH, NULL, NULL);
    d_b = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * LENGTH, NULL, NULL);
    d_mul_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY,  sizeof(int) * LENGTH, NULL, NULL);
    if (!d_a || !d_b || !d_mul_c) {
        printf("Error: Failed to allocate device memory!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Write our data set into the input array in device memory
    //
    err = clEnqueueWriteBuffer(commands, d_a, CL_TRUE, 0, sizeof(int) * LENGTH, h_a, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to write to source array a!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Write our data set into the input array in device memory
    //
    err = clEnqueueWriteBuffer(commands, d_b, CL_TRUE, 0, sizeof(int) * LENGTH, h_b, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to write to source array b!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Set the arguments to our compute kernel
    //
    err = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_mul_c);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device
    //

#ifdef C_KERNEL
    err = clEnqueueTask(commands, kernel, 0, NULL, NULL);
#else
    global[0] = NUM_WORKGROUPS * WORKGROUP_SIZE;
    local[0] = WORKGROUP_SIZE;
    err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL,
                                 (size_t*)&global, (size_t*)&local, 0, NULL, NULL);
#endif
    if (err) {
            printf("Error: Failed to execute kernel! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Read back the results from the device to verify the output
    //
    cl_event readevent;
    err = clEnqueueReadBuffer( commands, d_mul_c, CL_TRUE, 0, sizeof(int) * LENGTH, h_c, 0, NULL, &readevent );
    if (err != CL_SUCCESS) {
            printf("Error: Failed to read output array! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    clWaitForEvents(1, &readevent);

    // Check Results
    for (int i = 0; i < LENGTH; i++) {
        if ((h_a[i] * h_b[i]) != h_c[i]) {
            printf("ERROR in vmul - %d - a=%d, b=%d, c=%d\n", i, h_a[i], h_b[i], h_c[i]);
            check_status = 1;
        }
        //printf("i=%d, c=%d\n", i, h_c[i]);
    }


    //------------------------------------------------------------------------------
    // xclbin 1
    //------------------------------------------------------------------------------
    printf("INFO: loading xclbin1 %s\n", xclbin1);
    int n_i1 = load_file_to_memory(xclbin1, (char **) &kernelbinary1);
    if (n_i1 < 0) {
        printf("failed to load kernel from xclbin0: %s\n", xclbin1);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    size_t n1 = n_i1;
    // Create the compute program from offline
    program1 = clCreateProgramWithBinary(context, 1, &device_id, &n1,
                                        (const unsigned char **) &kernelbinary1, &status, &err);
    if ((!program1) || (err!=CL_SUCCESS)) {
        printf("Error: Failed to create compute program1 from binary %d!\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }


    // Build the program executable
    //
    err = clBuildProgram(program1, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program1, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create the compute kernel in the program we wish to run
    //
    kernel = clCreateKernel(program1, "krnl_vadd", &err);
    if (!kernel || err != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create output array in device memory for vadd
    d_add_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY,  sizeof(int) * LENGTH, NULL, NULL);
    if (!d_add_c) {
        printf("Error: Failed to allocate device memory!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Set the arguments to our compute kernel
    //
    err = 0;
    //use the results from vmul as a and b inputs for vadd
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_mul_c);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_mul_c);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_add_c);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device
    //

#ifdef C_KERNEL
    err = clEnqueueTask(commands, kernel, 0, NULL, NULL);
#else
    global[0] = NUM_WORKGROUPS * WORKGROUP_SIZE;
    local[0] = WORKGROUP_SIZE;
    err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL,
                                 (size_t*)&global, (size_t*)&local, 0, NULL, NULL);
#endif
    if (err) {
            printf("Error: Failed to execute kernel! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Read back the results from the device to verify the output
    //
    err = clEnqueueReadBuffer( commands, d_add_c, CL_TRUE, 0, sizeof(int) * LENGTH, h_c, 0, NULL, &readevent );
    if (err != CL_SUCCESS) {
            printf("Error: Failed to read output array! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    clWaitForEvents(1, &readevent);

    // Check Results
    for (int i = 0; i < LENGTH; i++) {
        if ((2*(h_a[i] * h_b[i])) != h_c[i]) {
            printf("ERROR in vadd - %d - c=%d\n", i, h_c[i]);
            check_status = 1;
        }
        //printf("i=%d, c=%d\n", i, h_c[i]);
    }

    //--------------------------------------------------------------------------
    // Shutdown and cleanup
    //--------------------------------------------------------------------------
    clReleaseMemObject(d_a);
    clReleaseMemObject(d_b);
    clReleaseMemObject(d_add_c);
    clReleaseMemObject(d_mul_c);
    clReleaseProgram(program0);
    clReleaseProgram(program1);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);

    if (check_status) {
        printf("INFO: Test failed\n");
        return EXIT_FAILURE;
    } else {
        printf("INFO: Test passed\n");
    }
}
