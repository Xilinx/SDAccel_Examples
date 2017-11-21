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

#include <CL/opencl.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

#include "xcl.h"

////////////////////////////////////////////////////////////////////////////////
class Timer {
    std::chrono::high_resolution_clock::time_point mTimeStart;
public:
    Timer() {
        reset();
    }
    long long stop() {
        std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - mTimeStart).count();
    }
    void reset() {
        mTimeStart = std::chrono::high_resolution_clock::now();
    }
};


static int host_to_dev(cl_command_queue commands, int buff_size, std::vector<cl_mem> &mems, std::ostream &strm)
{
    cl_int err = 0;
    Timer timer;
    err = clEnqueueMigrateMemObjects(commands, mems.size(), &mems[0], 0, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        return err;
    }
    err = clFinish(commands);
    if (err != CL_SUCCESS) {
        return err;
    }

    double timer_stop2 = timer.stop();
    double throput = (double)(buff_size * mems.size());
    throput *= 1000000; // convert us to s;
    throput /= 1024 * 1024; // convert to MB
    throput /= timer_stop2;
    std::cout << "OpenCL migration BW host to device: " << throput << " MB/s" <<" for buffer size "<< buff_size << " with " << mems.size()<< " buffers\n";
    strm << "Host to Card, " << buff_size << ", " << mems.size() << ", " << throput << "\n";
    return CL_SUCCESS;
}

static int dev_to_host(cl_command_queue commands, int buff_size, std::vector<cl_mem> &mems, std::ostream &strm)
{
    cl_int err = 0;
    Timer timer;
    err = clEnqueueMigrateMemObjects(commands, mems.size(), &mems[0], CL_MIGRATE_MEM_OBJECT_HOST, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        return err;
    }
    err = clFinish(commands);
    if (err != CL_SUCCESS) {
        return err;
    }

    long long timer_stop2 = timer.stop();
    double throput = (double)(buff_size * mems.size());
    throput *= 1000000; // convert us to s;
    throput /= 1024 * 1024; // convert to MB
    throput /= timer_stop2;
    std::cout << "OpenCL migration BW device to host: " << throput << " MB/s" <<" for buffer size " << buff_size << " with " << mems.size()<< " buffers\n";
    strm << "Card to Host, " << buff_size << ", " << mems.size() << ", " << throput << "\n";
    return CL_SUCCESS;
}

int main(int argc, char** argv)
{
    //Variable-------------------------------------------------------------------------------

    int buff_tab[][2] = {{64,1024},
                         {256,1024},
                         {512,1024},
                         {1024,1024},
                         {4096,1024},
                         {16384,512},
                         {1048576,8},
                         {1048576,64},
                         {1048576,256},
                         {2097152,8},
                         {2097152,64},
                         {2097152,256},
                         {16777216,64},
                         {268435456,4},
                         {536870912,2}};

    int err;
    xcl_world world     = xcl_world_single();
    cl_program program  = xcl_import_binary(world,"krnl_host_global");

    const int dim1 = sizeof(buff_tab)/(2 * 4);

    std::ofstream handle("metric1.csv");
    handle << "Direction, Buffer Size (bytes), Count, Bandwidth (MB/s)\n";
    for(int buff_size_1 = 0; buff_size_1 < dim1; buff_size_1++) {
        int nxtcnt = buff_tab[buff_size_1][0];
        int buff_cnt = buff_tab[buff_size_1][1];
        std::vector<cl_mem> mems(buff_cnt, 0);
        for(int i=mems.size() - 1; i>=0; i--){
            mems[i] = clCreateBuffer(world.context, CL_MEM_READ_WRITE, nxtcnt, NULL, NULL);
            err = clEnqueueFillBuffer(world.command_queue, mems[i], &i, 4, 0, nxtcnt, 0, 0, 0);
            if (err != CL_SUCCESS) {
                break;
            }
        }
        if (err != CL_SUCCESS) {
            break;
        }

        err = clFinish(world.command_queue);
        if (err != CL_SUCCESS) {
            break;
        }

        err = host_to_dev(world.command_queue, nxtcnt, mems, handle);
        if (err != CL_SUCCESS) {
            break;
        }

        err = dev_to_host(world.command_queue, nxtcnt, mems, handle);
        if (err != CL_SUCCESS) {
            break;
        }

        for (cl_mem m : mems){
            clReleaseMemObject(m);
        }
    }

    // Shutdown and cleanup
    handle.close();
    clReleaseProgram(program);
    xcl_release_world(world);
}
