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

#include "CL/cl.h"
#include "xcl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <array>
#include <map>
#include <vector>

using std::array;
using std::map;
using std::vector;

static const char *error_message =
    "Error: Result mismatch:\n"
    "i = %d CPU result = %d Device result = %d\n";

// Wrap any OpenCL API calls that return error code(cl_int)
// with the below macro to quickly check for an error
#define OCL_CHECK(call)                                              \
    do {                                                             \
        cl_int err = call;                                           \
        if (err != CL_SUCCESS) {                                     \
            printf("Error from " #call ", error code is %d\n", err); \
            exit(1);                                                 \
        }                                                            \
    } while (0);

// Use the following macro after an OpenCL API call takes
// place that returns non error code objects but takes address
// of an cl_int to return error code
#define OCL_ERR_CHECK(msg, err_code)                                 \
    if (err_code != CL_SUCCESS) {                                    \
        printf("Error from " #msg ", error code is %d\n", err_code); \
        exit(1);                                                     \
    }

cl_program load_cl_binary(const char *file_path, cl_device_id devices,
                          cl_context context);

// This example demonstrates how to split work among multiple devices.
int main(int argc, char **argv) {
    if (argc != 2) {
        printf(
            "The program expects only one argument which is the full path to "
            "the OpenCL kernel binary (xclbin file)\n");
        return EXIT_FAILURE;
    }

    xcl_world world = xcl_world_single();
    char *binary_file_path = argv[1];

    cl_int err = CL_SUCCESS;
    cl_uint device_count = 0;
    OCL_CHECK(clGetDeviceIDs(world.platform_id, CL_DEVICE_TYPE_ALL, 0, nullptr,
                             &device_count));
    vector<cl_device_id> devices(device_count);
    OCL_CHECK(clGetDeviceIDs(world.platform_id, CL_DEVICE_TYPE_ALL,
                             device_count, devices.data(), nullptr));

    static const int elements_per_device = 1 << 10;
    static const int elements = elements_per_device * device_count;

    vector<int> A(elements, 32);
    vector<int> B(elements, 10);
    vector<int> C(elements);

    // One element per device
    vector<cl_context> contexts(device_count);
    vector<cl_program> programs(device_count);
    vector<cl_kernel> kernels(device_count);
    vector<cl_command_queue> queues(device_count);

    vector<cl_mem> buffer_a(device_count);
    vector<cl_mem> buffer_b(device_count);
    vector<cl_mem> buffer_result(device_count);

    size_t size_per_device = elements_per_device * sizeof(int);
    cl_context_properties props[3] = {
        CL_CONTEXT_PLATFORM, (cl_context_properties)world.platform_id, 0};
    printf("Initializing OpenCL objects");
    for (int d = 0; d < (int)device_count; d++) {
        // In this example. We will create a context for each of the devices
        contexts[d] =
            clCreateContext(props, 1, &devices[d], nullptr, nullptr, &err);
        programs[d] = load_cl_binary(binary_file_path, devices[d], contexts[d]);
        kernels[d] = clCreateKernel(programs[d], "vadd", &err);

        // Each device will have it's own command queue. All work queued on the
        // command queue will be performed by the device
        queues[d] = clCreateCommandQueue(contexts[d], devices[d],
                                         CL_QUEUE_PROFILING_ENABLE, &err);

        buffer_a[d] = clCreateBuffer(contexts[d], CL_MEM_READ_ONLY,
                                     size_per_device, nullptr, &err);
        buffer_b[d] = clCreateBuffer(contexts[d], CL_MEM_READ_ONLY,
                                     size_per_device, nullptr, &err);
        buffer_result[d] = clCreateBuffer(contexts[d], CL_MEM_WRITE_ONLY,
                                          size_per_device, nullptr, &err);
    }

    vector<cl_event> events(devices.size());
    for (int d = 0; d < (int)device_count; d++) {
        printf("Enqueueing write buffer on device %d\n", d);
        // Each device will work on a different set of the data
        size_t offset = d * elements_per_device;
        OCL_CHECK(clEnqueueWriteBuffer(queues[d], buffer_a[d], CL_FALSE, 0,
                                       size_per_device, &A[offset], 0, nullptr,
                                       nullptr));
        OCL_CHECK(clEnqueueWriteBuffer(queues[d], buffer_b[d], CL_FALSE, 0,
                                       size_per_device, &B[offset], 0, nullptr,
                                       nullptr));

        OCL_CHECK(clSetKernelArg(kernels[d], 0, sizeof(cl_mem),
                                 (void *)&buffer_result[d]));
        OCL_CHECK(clSetKernelArg(kernels[d], 1, sizeof(cl_mem),
                                 (void *)&buffer_a[d]));
        OCL_CHECK(clSetKernelArg(kernels[d], 2, sizeof(cl_mem),
                                 (void *)&buffer_b[d]));
        OCL_CHECK(clSetKernelArg(kernels[d], 3, sizeof(cl_int),
                                 (void *)&elements_per_device));

        printf("Enqueueing tasks on device %d\n", d);
        OCL_CHECK(clEnqueueTask(queues[d], kernels[d], 0, NULL, &events[d]));

        printf("Enqueueing read buffer on device %d\n", d);
        // It is important to make sure you pass the CL_FALSE as the third
        // parameter. Othewise the operations will be performed sequentially
        OCL_CHECK(clEnqueueReadBuffer(queues[d], buffer_result[d], CL_FALSE, 0,
                                      size_per_device, &C[offset], 0, nullptr,
                                      nullptr));
    }

    int dev = 0;
    for(auto queue : queues) {
      printf("Waiting for work to finish on device %d\n", dev++);
      OCL_CHECK(clFlush(queue));
      OCL_CHECK(clFinish(queue));
    }

    int fail = 0;
    for (int i = 0; i < elements; i++) {
        int host_result = A[i] + B[i];
        if (C[i] != host_result) {
            printf(error_message, i, host_result, C[i]);
            fail = 1;
            break;
        }
    }

    for (int i = 0 ; i < (int)device_count ; i++){
        clReleaseMemObject(buffer_a[i]);
        clReleaseMemObject(buffer_b[i]);
        clReleaseMemObject(buffer_result[i]);
        clReleaseKernel(kernels[i]);
        clReleaseProgram(programs[i]);
        clReleaseCommandQueue(queues[i]);
	    clReleaseContext(contexts[i]);
    }
    if (fail) {
        printf("TEST FAILED\n");
        return EXIT_FAILURE;
    }
    printf("TEST PASSED\n");
    return EXIT_SUCCESS;
}

cl_program load_cl_binary(const char *file_path, cl_device_id device,
                          cl_context context) {
    FILE *file_descriptor = fopen(file_path, "rb");

    if (!file_descriptor) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    fseek(file_descriptor, 0L, SEEK_END);

    size_t bin_size = ftell(file_descriptor);

    rewind(file_descriptor);

    unsigned char *binary_str =
        (unsigned char *)malloc(sizeof(unsigned char) * bin_size);

    if (!binary_str) {
        printf("Error allocating memory for opencl kernel source string\n");
        exit(1);
    }

    if (fread(binary_str, 1, bin_size, file_descriptor) < 1) {
        printf("Error reading entire file\n");
        exit(1);
    }

    // create program object using OpenCL binary source string that
    // we read into a char buffer in the previous step.
    cl_int err = CL_SUCCESS;
    cl_int is_loaded = CL_SUCCESS;

    cl_program program = clCreateProgramWithBinary(
        context, 1, &device, &bin_size, (const unsigned char **)&binary_str,
        &is_loaded, &err);

    OCL_ERR_CHECK("Error from clCreateProgramWithBinary", err);

    printf("Kernel binary loading status: %s\n",
           is_loaded == 0 ? "Success" : "Failure");

    // build kernel program
    OCL_CHECK(clBuildProgram(program, 1, &device, nullptr, nullptr, nullptr));

    // clean up resources used to create cl_program object
    fclose(file_descriptor);
    free(binary_str);

    return program;
}
