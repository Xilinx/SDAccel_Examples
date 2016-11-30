/*******************************************************************************
Copyright (c) 2016, Xilinx, Inc.
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include <CL/cl.h>
#include <xcl.h>

#include <cstdio>
#include <vector>

using std::vector;

static const int DATA_SIZE = 256;
static const char *error_message =
    "Error: Result mismatch:\n"
    "i = %d CPU result = %d Device result = %d\n";

// This example illustrates the very simple OpenCL example that performs
// an addition on two vectors
int main(int argc, char **argv) {
    // compute the size of array in bytes
    int size_in_bytes = DATA_SIZE * sizeof(int);

    // The xlc_world struct consists of several types of OpenCL objects
    // including the cl_platform, cl_device_id, cl_context and cl_command_queue.
    // These objects manage different aspects of the system and can be used to
    // manage memory and determine where the application will execute the
    // OpenCL functions.
    xcl_world world = xcl_world_single();

    // This command will load the OpenCL binary created using the xocc compiler
    // and load it onto the FPGA fabric. It is referred to as a program in
    // OpenCL and it can contain many functions which can be executed on the
    // device.
    cl_program program = xcl_import_binary(world, "vector_addition");

    // These commands will allocate memory on the FPGA. The cl_mem objects can
    // be used to reference the memory locations on the device. The cl_mem
    // object cannot be referenced directly and must be passed to other OpenCL
    // functions.
    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
    cl_mem buffer_b = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
    cl_mem buffer_result = xcl_malloc(world, CL_MEM_WRITE_ONLY, size_in_bytes);

    // Creates a vector of DATA_SIZE elements with an initial value of 10 and 32
    vector<int> source_a(DATA_SIZE, 10);
    vector<int> source_b(DATA_SIZE, 32);
    vector<int> source_results(DATA_SIZE);

    // These commands will load the source_a and source_b vectors from the host
    // application and into the buffer_a and buffer_b cl_mem objects. The data
    // will be be transferred from system memory over PCIe to the FPGA on-board
    // DDR memory.
    xcl_memcpy_to_device(world, buffer_a, source_a.data(), size_in_bytes);
    xcl_memcpy_to_device(world, buffer_b, source_b.data(), size_in_bytes);

    // This call will extract a kernel out of the program we loaded in the
    // previous line. A kernel is an OpenCL function that is executed on the
    // FPGA. This function is defined in the src/vetor_addition.cl file.
    cl_kernel krnl_vector_add = xcl_get_kernel(program, "vector_add");

    // The parameters of the kernel can be set using these function calls.
    xcl_set_kernel_arg(krnl_vector_add, 0, sizeof(cl_mem), &buffer_result);
    xcl_set_kernel_arg(krnl_vector_add, 1, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(krnl_vector_add, 2, sizeof(cl_mem), &buffer_b);
    xcl_set_kernel_arg(krnl_vector_add, 3, sizeof(int), &DATA_SIZE);

    // This function will execute the kernel on the FPGA
    xcl_run_kernel3d_nb(world, krnl_vector_add);

    // The result of the previous kernel execution will need to be retrieved in
    // order to view the results. This call will write the data from the
    // buffer_result cl_mem object to the source_results vector
    xcl_memcpy_from_device(world, source_results.data(), buffer_result,
                           size_in_bytes);

    // These functions will release the OpenCL resources.
    clReleaseMemObject(buffer_a);
    clReleaseMemObject(buffer_b);
    clReleaseMemObject(buffer_result);
    clReleaseKernel(krnl_vector_add);
    clReleaseProgram(program);
    xcl_release_world(world);

    int match = 0;
    printf("Result = \n");
    for (int i = 0; i < DATA_SIZE; i++) {
        int host_result = source_a[i] + source_b[i];
        if (source_results[i] != host_result) {
            printf(error_message, i, host_result, source_results[i]);
            match = 1;
            break;
        } else {
          printf("%d ", source_results[i]);
          if (((i + 1) % 16) == 0) printf("\n");
        }
    }

    if (match) {
        printf("TEST FAILED.\n");
        return EXIT_FAILURE;
    } else {
        printf("TEST PASSED.\n");
        return EXIT_SUCCESS;
    }
}
