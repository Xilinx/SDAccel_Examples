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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "xcl2.hpp"

#include "linear_search.h"

#ifdef __cplusplus
using namespace std;
#endif


void linear_search_read_datafile(char* filename, float* data, size_t size) {
    FILE* fp = fopen(filename, "r");
    if( fp == NULL) {
        printf("ERROR: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++) {
        fscanf (fp, "%f\n", &data[i]);
    }
    fclose(fp);
}

void linear_search_init( cl::Context *context, cl::CommandQueue *q, cl::Program *program, cl::Kernel *krnl,
        cl::Buffer* dev_targets, cl::Buffer* dev_queries, cl::Buffer* dev_indices,
            float *targets, float *queries, unsigned int *indices)
{
    cl_int err;
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, *context = cl::Context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, *q = cl::CommandQueue(*context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    // find_binary_file() is a utility API which will search the xclbin file for
    // targeted mode (sw_emu/hw_emu/hw) and for targeted platforms.
    std::string binaryFile = xcl::find_binary_file(device_name, "krnl_nearest");

    // import_binary_file() is a utility API which will load the binaryFile
    // and will return Binaries.
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);

    OCL_CHECK(err, *program = cl::Program(*context, devices, bins, NULL, &err));
    OCL_CHECK(err, *krnl = cl::Kernel(*program, "krnl_linear_search", &err));

    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and Device-to-host communication
    /* Create Buffers padded to 512 bit boundry */
    OCL_CHECK(err, *dev_targets = cl::Buffer(*context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            ((TARGETS * DIMS - 1) / 16 + 1) * 16 * sizeof(float), (void*)targets, &err));

    OCL_CHECK(err, *dev_queries = cl::Buffer(*context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            ((QUERIES * DIMS - 1) / 16 + 1) * 16 * sizeof(float), (void*)queries, &err));

    OCL_CHECK(err, *dev_indices = cl::Buffer(*context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            ((QUERIES - 1) / 16 + 1) * 16 * sizeof(unsigned int), (void*)indices, &err));
}

unsigned long linear_search_exec(cl::Context *context, cl::CommandQueue *q, cl::Program *program, cl::Kernel *krnl,
        cl::Buffer* dev_targets, cl::Buffer* dev_queries, cl::Buffer* dev_indices, unsigned int *indices)
{
        cl_int err;    
    cl::Event event;

    OCL_CHECK(err, err = krnl->setArg(0, *dev_targets));
    OCL_CHECK(err, err = krnl->setArg(1, *dev_queries));
    OCL_CHECK(err, err = krnl->setArg(2, *dev_indices));

    OCL_CHECK(err, err = q->enqueueTask(*krnl, NULL, &event));

    unsigned long start, stop;
    OCL_CHECK(err, err = event.getProfilingInfo<unsigned long>(CL_PROFILING_COMMAND_START, &start));
    OCL_CHECK(err, err = event.getProfilingInfo<unsigned long>(CL_PROFILING_COMMAND_END, &stop));

    unsigned long duration = stop - start;

    OCL_CHECK(err, err = q->enqueueReadBuffer(*dev_indices, CL_TRUE, 0, (QUERIES) * sizeof(unsigned int), (void*)indices, NULL, NULL));
    q->finish();
    return duration;
}

int main(int argc, char** argv) {
    if (!(argc == 3 || argc == 4)) {
        printf("usage: %s <queries.txt> <targets.txt> [<ref.txt>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *queries_filename = argv[1];
    char *targets_filename = argv[2];
    char *refs_filename = NULL;

    int check_results = 0;

    if (argc == 4) {
        refs_filename = argv[3];
        check_results = 1;
    }

        std::vector<float,aligned_allocator<float>> queries(QUERIES * DIMS);
        std::vector<float,aligned_allocator<float>> targets(TARGETS * DIMS);
        std::vector<unsigned int,aligned_allocator<unsigned int>> indices(QUERIES);
    
    if (queries.empty() || targets.empty() || indices.empty()) {
        printf("ERROR: Could not allocate memory!\n");
        return EXIT_FAILURE;
    }
      
    linear_search_read_datafile(queries_filename, queries.data(), QUERIES*DIMS);

    for(size_t i = 0; i < QUERIES*DIMS; i++) {
        if (!isfinite(queries[i])) {
            printf("ERROR: Non finite value specified at queries[%ld]\n", i);
            exit(-1);
        }
    }

    linear_search_read_datafile(targets_filename, targets.data(), TARGETS*DIMS);

    for(size_t i = 0; i < TARGETS*DIMS; i++) {
        if (!isfinite(targets[i])) {
            printf("ERROR: Non Finite value specified at targets[%ld]\n", i);
            exit(-1);
        }
    }

    cl::Program program;
    cl::Context context;
    cl::CommandQueue q;
    cl::Kernel krnl;
    cl::Buffer dev_targets, dev_queries, dev_indices;

    linear_search_init(&context, &q, &program, &krnl,
        &dev_targets, &dev_queries, &dev_indices, targets.data(), queries.data(), indices.data());

    unsigned long duration = linear_search_exec(
        &context, &q, &program, &krnl, &dev_targets, &dev_queries, &dev_indices, indices.data());

    printf("Kernel Execution Time: %ld ns\n", duration);

    std::vector<float,aligned_allocator<float>> refs(QUERIES);

    if(check_results == 1) {
        if(refs.empty()) {
            printf("ERROR: Failed to allocate memory!\n");
            return EXIT_FAILURE;
        }
        linear_search_read_datafile(refs_filename, refs.data(), QUERIES);
    }

    int pass = 1;

    for (size_t i = 0; i < QUERIES; i++) {
        size_t j = indices[i];

        if(j > TARGETS) {
            printf("ERROR: target[%lu] invalid\n", j);
            continue;
        }

        float dist_x = queries[DIMS*i + 0] - targets[DIMS*j + 0];
        float dist_y = queries[DIMS*i + 1] - targets[DIMS*j + 1];
        float dist_z = queries[DIMS*i + 2] - targets[DIMS*j + 2];

        float dist = dist_x * dist_x + dist_y * dist_y + dist_z * dist_z;

        printf ("Closest to queries[%5lu] = [% 6.2f % 6.2f % 6.2f] is targets[%5lu] = [% 6.2f % 6.2f % 6.2f] : distance = % 7.2f\n",
                i, queries[DIMS*i + 0],  queries[DIMS*i + 1], queries[DIMS*i + 2],
                j, targets[DIMS*j + 0], targets[DIMS*j + 1], targets[DIMS*j +2],
                dist);

        if (check_results == 1) {
            size_t k = (size_t) refs[i];
            if (j != k) {
                float dist_rx = queries[DIMS*i + 0] - targets[DIMS*k + 0];
                float dist_ry = queries[DIMS*i + 1] - targets[DIMS*k + 1];
                float dist_rz = queries[DIMS*i + 2] - targets[DIMS*k + 2];

                float dist_r = dist_rx * dist_rx + dist_ry * dist_ry + dist_rz * dist_rz;

                if (dist_r < dist) {
                    printf("ERROR: Closer target at targets[%5lu] = [% 6.2f % 6.2f % 6.2f] : distance = % 7.2f\n",
                           k, targets[DIMS*k + 0], targets[DIMS*k + 1], targets[DIMS*k + 2], dist_r);
                    pass = 0;
                }
            }
        }
    }

    if(pass != 1) {
        printf("ERROR: Test Failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Test Passed\n");

    return EXIT_SUCCESS;
}

