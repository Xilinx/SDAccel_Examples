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

/*******************************************************************************

Description: 

    This is a nearest neighbor of a point example showcases how making a loop
    nest perfect or semi-perfect can help improve performance.

*******************************************************************************/

#include <iostream>
#include <cstring>

#include <time.h>
#include <limits.h>
#include <stdlib.h>

//OpenCL utility layer include
#include "xcl.h"

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
				    int *in,      // Input Points Array - represented as integer
				    int *point,   // Current Point for which the neighbor is found
				    int *out,     // Output Point
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
        std::cout << DATA_DIM << "greater than " << MAX_DIM << "!" << " Please use a smaller DATA_DIM" << std::endl;
        return EXIT_FAILURE;
    }
    
    if (DATA_SIZE > MAX_SIZE) {
        std::cout << DATA_SIZE << "greater than " << MAX_SIZE << "!" << " Please use a smaller DATA_SIZE" << std::endl;
        return EXIT_FAILURE;
    }
    
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE * DATA_DIM;

    int *source_in  = (int*) malloc(vector_size_bytes);
    int *source_point = (int*) malloc(sizeof(int)*DATA_DIM);
    int *source_hw_result = (int*) malloc(sizeof(int)*DATA_DIM);
    int *source_sw_result = (int*) malloc(sizeof(int)*DATA_DIM);
    
    srand(time(NULL));

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
    //Create Program and Kernels
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "nearest");
    cl_kernel krnl_nearest = xcl_get_kernel(program, "nearest");

    //Allocate Buffer in Global Memory
    cl_mem buffer_in    = xcl_malloc(world, CL_MEM_READ_ONLY,  vector_size_bytes);
    cl_mem buffer_point = xcl_malloc(world, CL_MEM_READ_ONLY,  sizeof(int)*DATA_DIM);
    cl_mem buffer_out   = xcl_malloc(world, CL_MEM_WRITE_ONLY, sizeof(int)*DATA_DIM);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world, buffer_in, source_in, vector_size_bytes);
    xcl_memcpy_to_device(world, buffer_point, source_point, sizeof(int)*DATA_DIM);

    //Set the Kernel Arguments
    int narg = 0;
    
    xcl_set_kernel_arg(krnl_nearest, narg++, sizeof(cl_mem), &buffer_in);
    xcl_set_kernel_arg(krnl_nearest, narg++, sizeof(cl_mem), &buffer_point);
    xcl_set_kernel_arg(krnl_nearest, narg++, sizeof(cl_mem), &buffer_out);
    xcl_set_kernel_arg(krnl_nearest, narg++, sizeof(int), &size);
    xcl_set_kernel_arg(krnl_nearest, narg++, sizeof(int), &dim);

    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_nearest,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, source_hw_result, buffer_out, sizeof(int)*DATA_DIM);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_in);
    clReleaseMemObject(buffer_point);
    clReleaseMemObject(buffer_out);
    clReleaseKernel(krnl_nearest);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END
    
    // Compute Software Results
    nearest_sw(source_in, source_point, source_sw_result, size, dim);
    
    // Compare the nearset distances between software and hardware
    unsigned long dist_sw = 0, dist_hw = 0;
    for(int i = 0; i < dim; i++) {
        dist_sw += SQUARE(source_sw_result[i] - source_point[i]);
        dist_hw += SQUARE(source_sw_result[i] - source_point[i]);
    }
    
    /* Release Memory from Host Memory*/
    free(source_in);
    free(source_point);
    free(source_hw_result);
    free(source_sw_result);
   
    if(dist_sw != dist_hw)
    {
        std::cout << "TEST FAILED." << std::endl; 
        std::cout << "\tSoftware Min Dist = " << dist_sw << std::endl;
        std::cout << "\tHardware Min Dist = " << dist_hw << std::endl;
        return -1;
    }
 
    std::cout << "TEST PASSED." << std::endl;
    return 0;
}
