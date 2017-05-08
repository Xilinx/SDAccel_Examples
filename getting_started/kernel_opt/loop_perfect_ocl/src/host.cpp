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

Description: 

    This is a nearest neighbor of a point example showcases how making a loop
    nest perfect or semi-perfect can help improve performance.

*******************************************************************************/
//OpenCL utility layer include
#include "xcl2.hpp"
#include <vector>
#include <limits.h>

// Maximum possible distance between two points
#define INFINITY ULONG_MAX

#define SQUARE(x) ((x)*(x))

// Maximum #Dimensions for a point
#define MAX_DIM 16

// Maximum size of point array
#define MAX_SIZE 16384

// Current #Dimension and size of point array
#define DATA_DIM 16
#define DATA_SIZE 16384

// Software implementation for finding nearest neighbor
void nearest_sw(
    int *in,   // Input Points Array - represented as integer
    int *point,// Current Point for which the neighbor is found
    int *out,  // Output Point
    int size,     // Size of the input array
    int dim       // #Dimensions of the points
)
{
    unsigned long curr_dist, min_dist = INFINITY;
    for(int i = 0; i < size; i++) {
        curr_dist = 0;
        
        // Calculate distance
        // No need to compute square root as the distances are only compared
        for(int j = 0; j < dim; j++) {
            curr_dist += SQUARE(point[j] - in[i*dim + j]);
        }
        
        // Update minimum distance
        if(curr_dist < min_dist) {
            
            min_dist = curr_dist;
            
            for(int k = 0; k < dim; k++) {
                out[k] = in[i*dim + k];
            }
        }
    }
}  

int main(int argc, char** argv)
{
    if (DATA_DIM > MAX_DIM) {
        std::cout << DATA_DIM << "greater than " << MAX_DIM 
            << "!" << " Please use a smaller DATA_DIM" << std::endl;
        return EXIT_FAILURE;
    }
    
    if (DATA_SIZE > MAX_SIZE) {
        std::cout << DATA_SIZE << "greater than " << MAX_SIZE 
            << "!" << " Please use a smaller DATA_SIZE" << std::endl;
        return EXIT_FAILURE;
    }
    
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE * DATA_DIM;
    std::vector<int,aligned_allocator<int>> source_in(vector_size_bytes);
    std::vector<int,aligned_allocator<int>> source_point(sizeof(int)*DATA_DIM);
    std::vector<int,aligned_allocator<int>> source_hw_result(sizeof(int)*DATA_DIM);
    std::vector<int,aligned_allocator<int>> source_sw_result(sizeof(int)*DATA_DIM);
    
    srand(time(nullptr));

    // Create the test data
    for(int i = 0 ; i < DATA_SIZE*DATA_DIM; i++){
        source_in[i] = rand()%100;
    }
    
    for(int i = 0 ; i < DATA_DIM; i++){
        source_point[i] = rand()%100;
    }
    
    int size = DATA_SIZE;
    int dim = DATA_DIM;
    
//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"nearest_GOOD");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel kernel(program,"nearest");

    //Allocate Buffer in Global Memory
    cl::Buffer buffer_in   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
            vector_size_bytes, source_in.data());
    cl::Buffer buffer_point(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
            sizeof(int)*DATA_DIM, source_point.data());
    cl::Buffer buffer_out  (context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            sizeof(int)*DATA_DIM, source_hw_result.data());
    std::vector<cl::Memory> inBufVec, outBufVec;
    inBufVec.push_back(buffer_in);
    inBufVec.push_back(buffer_point);
    outBufVec.push_back(buffer_out);

    //Copy input data to device global memory
    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

    auto krnl_nearest= cl::KernelFunctor<cl::Buffer&, cl::Buffer&,
         cl::Buffer&, int, int>(kernel);

    //Launch the Kernel
    krnl_nearest(cl::EnqueueArgs(q,cl::NDRange(1,1,1), cl::NDRange(1,1,1)), 
            buffer_in, buffer_point, buffer_out, size, dim);

    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();
//OPENCL HOST CODE AREA END
    
    // Compute Software Results
    nearest_sw(source_in.data(), source_point.data(), 
            source_sw_result.data(), size, dim);
    
    // Compare the nearset distances between software and hardware
    unsigned long dist_sw = 0, dist_hw = 0;
    for(int i = 0; i < dim; i++) {
        dist_sw += SQUARE(source_sw_result[i] - source_point[i]);
        dist_hw += SQUARE(source_hw_result[i] - source_point[i]);
    }
    if(dist_sw != dist_hw)
    {
        std::cout << "TEST FAILED." << std::endl; 
        std::cout << "\tSoftware Min Dist = " << dist_sw << std::endl;
        std::cout << "\tHardware Min Dist = " << dist_hw << std::endl;
        return EXIT_FAILURE;
    }
 
    std::cout << "TEST PASSED." << std::endl;
    return EXIT_SUCCESS;
}
