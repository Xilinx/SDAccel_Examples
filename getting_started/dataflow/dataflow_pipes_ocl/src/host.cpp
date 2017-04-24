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

/*******************************************************************************
Description: SDx Vector Addition using Blocking Pipes Operation
*******************************************************************************/

#define INCR_VALUE 10

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>

//OpenCL utility layer include
#include "xcl.h"
#include "oclHelper.h"


#define OCL_CHECK(call)                                                        \
  do {                                                                         \
    cl_int err = call;                                                         \
    if (err != CL_SUCCESS) {                                                   \
      printf("Error calling " #call ", error: %s\n", oclErrorCode(err));       \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0);

template <typename T>
struct aligned_allocator
{
  using value_type = T;
  T* allocate(std::size_t num)
  {
    void* ptr = nullptr;
    if (posix_memalign(&ptr,4096,num*sizeof(T)))
      throw std::bad_alloc();
    return reinterpret_cast<T*>(ptr);
  }
  void deallocate(T* p, std::size_t num)
  {
    free(p);
  }
};

int main(int argc, char** argv)
{
    size_t data_size = 1024*1024;

    /* Reducing the data size for emulation mode */
    char *xcl_mode = getenv("XCL_EMULATION_MODE");
    if (xcl_mode != NULL){
        data_size = 1024;  
    }

    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * data_size;
    std::vector<int,aligned_allocator<int>> source_input     (data_size);
    std::vector<int,aligned_allocator<int>> source_hw_results(data_size);
    std::vector<int,aligned_allocator<int>> source_sw_results(data_size);

    // Create the test data and Software Result 
    for(size_t i = 0 ; i < data_size; i++){
        source_input[i] = i;
        source_sw_results[i] = i + INCR_VALUE;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernels. 
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world,"adder");
    cl_kernel krnl_adder_stage   = xcl_get_kernel(program, "adder_stage");
    //Creating additional Kernels
    cl_kernel krnl_input_stage   = xcl_get_kernel(program, "input_stage");
    cl_kernel krnl_output_stage  = xcl_get_kernel(program, "output_stage");
    
    
    // By-default xcl_world_single create command queues with sequential command.
    // For this example, user to replace command queue with out of order command queue
    clReleaseCommandQueue(world.command_queue);
    int err;
    world.command_queue = clCreateCommandQueue(world.context, world.device_id,
            CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE,
            &err);
    if (err != CL_SUCCESS){
        std::cout << "Error: Failed to create a command queue!" << std::endl;
        std::cout << "Test failed" << std::endl;
        return EXIT_FAILURE;
    }


    //Allocate Buffer in Global Memory
    cl_mem buffer_output = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);
    cl_mem buffer_input = clCreateBuffer(world.context,
            CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
            vector_size_bytes, source_input.data(), NULL);
    
    cl_event write_event;
    // Using clEnqueueMigrateMemObjects() instead of clEnqueueWriteBuffer() to avoid
    // deadlock in real hardware which can be noticed only for large dataset.
    // Rootcause: design leads to a deadlock when host->DDR and 
    // output_stage->DDR causes a contention and deadlock. In small dataset, the 
    // data gets transferred from host-> DDR in 1 burst and hence no deadlock.
    // Solution: Start output_stage when host->DDR data transfer is completed.
    // clEnqueueMigrateMemObject() event is used for all three kernels to avoid deadlock.
    
    //Copy input data to device global memory
    OCL_CHECK(clEnqueueMigrateMemObjects(world.command_queue,1, &buffer_input,
                0 /* flags, 0 means from host*/,0, NULL,&write_event));

    //Wait
    clFinish(world.command_queue);

    int inc = INCR_VALUE;
    int size = data_size;
    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_input_stage,0,sizeof(cl_mem),&buffer_input);
    xcl_set_kernel_arg(krnl_input_stage,1,sizeof(int),&size);
    xcl_set_kernel_arg(krnl_adder_stage,0,sizeof(int),&inc);
    xcl_set_kernel_arg(krnl_adder_stage,1,sizeof(int),&size);
    xcl_set_kernel_arg(krnl_output_stage,0,sizeof(cl_mem),&buffer_output);
    xcl_set_kernel_arg(krnl_output_stage,1,sizeof(int),&size);

    //Launch the Kernel
    OCL_CHECK(clEnqueueTask(world.command_queue,krnl_input_stage, 1, &write_event, NULL));
    OCL_CHECK(clEnqueueTask(world.command_queue,krnl_adder_stage, 1, &write_event, NULL));
    OCL_CHECK(clEnqueueTask(world.command_queue,krnl_output_stage,1, &write_event, NULL));

    //wait for all kernels to finish their operations
    clFinish(world.command_queue);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, source_hw_results.data(), buffer_output,vector_size_bytes);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_input);
    clReleaseMemObject(buffer_output);
    clReleaseKernel(krnl_input_stage);
    clReleaseKernel(krnl_adder_stage);
    clReleaseKernel(krnl_output_stage);
    clReleaseProgram(program);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (size_t i = 0 ; i < data_size; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }
    }

    if (match){
        std::cout << "TEST FAILED" << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "TEST PASSED" << std::endl;
    return EXIT_SUCCESS; 
}
