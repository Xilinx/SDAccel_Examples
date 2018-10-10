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

/*******************************************************************************
Description: 

    This is a CNN (Convolutional Neural Network) convolutional layer based
    example to showcase the effectiveness of using multiple compute units when
    the base algorithm consists of multiple nested loops with large loop count.    

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <unistd.h>

//OpenCL utility layer include
#include "xcl2.hpp"
#include "defns.h"

#define WORK_GROUP 4 
#define WORK_ITEM_PER_GROUP 1

#define DATA_SIZE OChan * OSize * OSize

uint64_t get_duration_ns (const cl::Event &event) {
    uint64_t nstimestart, nstimeend;
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
    return(nstimeend-nstimestart);
}

// Software solution
void convGolden(int *weight, int *image, int *out, int i_chan, int o_chan)
{
    // Runs over output filters
    for(int output = 0; output < o_chan; output++){
        // Runs over output pixel in Y-direction
        for(int y = 0; y < OSize; y++){
            // Runs over output pixel in X-direction
            for(int x = 0; x < OSize; x++){
                short acc = 0;
                // Runs over each input channel of input feature map
                for(int input = 0; input < i_chan; input++){
                    // Runs over filter window 
                    for(int i = 0; i < WSize; i++){
                        // Runs over filter windows 
                        for(int j = 0; j < WSize; j++){

                            // Calculate input padding boundaries
                            int xVal = x*Stride + j-Padding, yVal = y*Stride + i-Padding;

                            // Convolution operation
                            if(yVal >= 0 && yVal < ISize && xVal >= 0 && xVal < ISize){
                                acc += (short) image[(input*ISize + yVal)*ISize + xVal] * 
                                       (short) weight[((output*WInChan + input)*WSize + i)*WSize + j];
                            }
                        }
                        // Update each output pixel / output filter
                        out[(output*OSize + y)*OSize + x] = acc;
                    }
                }
            }
        }
    }
}


uint64_t run_opencl_cnn(
    std::vector<cl::Device> &devices,
    cl::CommandQueue &q,
    cl::Context &context,
    std::string &device_name,
    bool good,
    int size,
    std::vector<int, aligned_allocator<int>> &weight,
    std::vector<int, aligned_allocator<int>> &image,
    std::vector<int, aligned_allocator<int>> &output,
    int i_chan,
    int o_chan
) {
    std::string binaryFile;

    if (good) {
        binaryFile = xcl::find_binary_file(device_name, "cnn_GOOD");
    } 
    else {
        binaryFile = xcl::find_binary_file(device_name,"cnn_BAD");
        if(access(binaryFile.c_str(), R_OK) != 0) {
            std::cout << "WARNING: vadd_BAD xclbin not built" << std::endl;
            return false;
        }
    }

    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl_cnn_conv;
    if (good) krnl_cnn_conv = cl::Kernel(program,"cnn_GOOD");
    else krnl_cnn_conv = cl::Kernel(program, "cnn_BAD");

    std::cout << "Starting " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    size_t image_size_bytes  = sizeof(int) * i_chan * ISize * ISize;
    size_t weight_size_bytes = sizeof(int) * o_chan * WInChan * WSize * WSize;
    size_t output_size_bytes = sizeof(int) * o_chan * OSize * OSize;

    // Allocate Buffer in Global Memory
    std::vector<cl::Memory> inBufVec, outBufVec;
    cl::Buffer buffer_image (context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                            image_size_bytes, image.data());
    cl::Buffer buffer_weight(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                            weight_size_bytes, weight.data());
    cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                                output_size_bytes, output.data());

    inBufVec.push_back(buffer_image);
    inBufVec.push_back(buffer_weight);
    outBufVec.push_back(buffer_output);

    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

    //Set the Kernel Arguments
    int narg = 0;
    krnl_cnn_conv.setArg(narg++, buffer_image);
    krnl_cnn_conv.setArg(narg++, buffer_weight);
    krnl_cnn_conv.setArg(narg++, buffer_output);
    krnl_cnn_conv.setArg(narg++, size);
    krnl_cnn_conv.setArg(narg++, i_chan);
    krnl_cnn_conv.setArg(narg++, o_chan);

    std::cout << "Begin " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    uint64_t duration = 0;
    cl::Event event;

    if(good) {
        int work_group = WORK_GROUP;
        int work_item_per_group = WORK_ITEM_PER_GROUP;
    
        //Set global & local grids
        cl::NDRange global_size = work_group;
        cl::NDRange local_size  = work_item_per_group;

        q.enqueueNDRangeKernel(krnl_cnn_conv, 0, global_size, local_size, NULL, &event);
        q.finish();

        duration = get_duration_ns(event);
    } 
    else {
        q.enqueueTask(krnl_cnn_conv, NULL, &event);
        q.finish();

        duration = get_duration_ns(event);
    }

    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();

    std::cout << "Finished " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;
    return duration;
}
int main(int argc, char** argv)
{
    int i_chan = IChan;
    int o_chan = OChan;

    int size = DATA_SIZE;

    const char *xcl_emu = getenv("XCL_EMULATION_MODE");
    if(xcl_emu && !strcmp(xcl_emu, "hw_emu")) {
        i_chan = 1;
        o_chan = 1;

        size = o_chan * OSize * OSize;

        printf("\nOriginal Dataset is Reduced for Faster Execution of Hardware Emulation Flow\n");
        printf("\t#Input_Channels (IChan)            = %d (Original : 96 )\n", i_chan);
        printf("\t#Weight_Output_Channels (WOutChan) = %d (Original : 256)\n\n", o_chan);
    }

    // Allocate Memory in Host (Image, Weights and Output)
    size_t image_size_bytes  = sizeof(int) * i_chan * ISize * ISize;
    size_t weight_size_bytes = sizeof(int) * o_chan * WInChan * WSize * WSize;
    size_t output_size_bytes = sizeof(int) * o_chan * OSize * OSize;

    std::vector<int,aligned_allocator<int>> image(image_size_bytes);
    std::vector<int,aligned_allocator<int>> weight(weight_size_bytes);
    std::vector<int,aligned_allocator<int>> source_good_hw_results(output_size_bytes);
    std::vector<int,aligned_allocator<int>> source_bad_hw_results(output_size_bytes);
    std::vector<int,aligned_allocator<int>> source_sw_results(output_size_bytes);

    // Initialize Image, Weights & Output Host Buffers
    for(int i = 0; i < i_chan*ISize*ISize; i++)
        image[i] = i%255;

    for(int i = 0; i < o_chan*WInChan*WSize*WSize; i++)
        weight[i] = i%255;

    for(int i = 0; i < o_chan*OSize*OSize; i++)
        source_sw_results[i] = source_good_hw_results[i] = source_bad_hw_results[i] = 0;

    convGolden(weight.data(), image.data(), source_sw_results.data(), i_chan, o_chan);

//OPENCL HOST CODE AREA START
    //Create Program and Kernels
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];
    
    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>();

    uint64_t bad_duration = run_opencl_cnn(devices, q, context, device_name,
            false, size, weight, image, source_bad_hw_results, i_chan, o_chan);

    uint64_t good_duration = run_opencl_cnn(devices, q, context, device_name, 
            true, size, weight, image, source_good_hw_results, i_chan, o_chan);
//OPENCL HOST CODE AREA END

    // Compare the results of the Device to the simulation
    bool match = true;
    for (int i = 0 ; i < size; i++){
        /* if bad_duration is 0 then the kernel was unable to be produced for
         * the hardware thus there's no reason to check the results */
        if (bad_duration != 0) {
            if (source_bad_hw_results[i] != source_sw_results[i]){
                std::cout << "Error: Result mismatch in bad kernel" << std::endl;
                std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                          << " Device result = " << source_bad_hw_results[i] << std::endl;
                match = false;
                break;
            }
        }
        if (source_good_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch in good kernel" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_good_hw_results[i] << std::endl;
            match = false;
            break;
        }
    }

    if (bad_duration != 0) {
        std::cout << "BAD duration = "  << bad_duration  << " ns" << std::endl;
    }
    std::cout << "GOOD duration = " << good_duration << " ns" << std::endl;

    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl; 
    return (match ? EXIT_SUCCESS :  EXIT_FAILURE);
}
