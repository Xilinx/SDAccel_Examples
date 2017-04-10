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
//OpenCL utility layer include
#include "xcl2.hpp"
#include <vector>

int main(int argc, char** argv)
{
    if (argc != 1)
    {
        std::cout << "Usage: " << argv[0] << std::endl;
        return EXIT_FAILURE;
    }

    size_t data_size = 1024*1024;

    /* Reducing the data size for emulation mode */
    std::string xcl_mode = getenv("XCL_EMULATION_MODE");
    if (xcl_mode.size() != 0){
        data_size = 1024;  
    }

    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * data_size;

    std::vector<int> source_input     (data_size);
    std::vector<int> source_hw_results(data_size);
    std::vector<int> source_sw_results(data_size);

    // Create the test data and Software Result 
    for(size_t i = 0 ; i < data_size; i++){
        source_input[i] = i;
        source_sw_results[i] = i + INCR_VALUE;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    //CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE command queue is needed to run
    //multiple kernels concurrently.
    cl::CommandQueue q(context, device,CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    //Create Program and Kernel
    cl::Program::Binaries bins = xcl::import_binary(device_name,"adder");
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl_adder_stage(program,"adder_stage");
    cl::Kernel krnl_input_stage(program,"input_stage");
    cl::Kernel krnl_output_stage(program,"output_stage");
    
    //Allocate Buffer in Global Memory
    cl::Buffer buffer_output(context, CL_MEM_WRITE_ONLY, vector_size_bytes);
    cl::Buffer buffer_input(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
            vector_size_bytes, source_input.data(), nullptr);
    cl::Event write_event;
    // Using enqueueMigrateMemObjects() instead of enqueueWriteBuffer() to avoid
    // deadlock in real hardware which can be noticed only for large dataset.
    // Rootcause: design leads to a deadlock when host->DDR and 
    // output_stage->DDR causes a contention and deadlock. In small dataset, the 
    // data gets transferred from host-> DDR in 1 burst and hence no deadlock.
    // Solution: Start output_stage when host->DDR data transfer is completed.
    // enqueueMigrateMemObject() event is used for all three kernels to avoid deadlock.
    
    //Copy input data to device global memory
    std::vector<cl::Memory> bufferList;
    bufferList.push_back(buffer_input);
    q.enqueueMigrateMemObjects(bufferList,0 /* flags, 0 means from host*/,
                nullptr,&write_event);

    //Wait
    q.finish();

    int inc = INCR_VALUE;
    int size = data_size;
    //Set the Kernel Arguments
    krnl_input_stage.setArg(0,buffer_input);
    krnl_input_stage.setArg(1,size);
    krnl_adder_stage.setArg(0,inc);
    krnl_adder_stage.setArg(1,size);
    krnl_output_stage.setArg(0,buffer_output);
    krnl_output_stage.setArg(1,size);

    //Launch the Kernel
    std::vector<cl::Event> eventList;
    eventList.push_back(write_event);
    q.enqueueTask(krnl_input_stage, &eventList, nullptr);
    q.enqueueTask(krnl_adder_stage, &eventList, nullptr);
    q.enqueueTask(krnl_output_stage,&eventList, nullptr);

    //wait for all kernels to finish their operations
    q.finish();

    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueReadBuffer(buffer_output,CL_TRUE,0,vector_size_bytes, source_hw_results.data());
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
