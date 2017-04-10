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

 /*
   Shift Register

   This example demonstrates how to perform a shift register operation to
   implement a Finite Impulse Response(FIR) filter.

   NOTE: See the fir.cl file for additional information.
  */
#include "xcl2.hpp"

#include <algorithm>
#include <random>
#include <string>
#include <vector>

using std::default_random_engine;
using std::inner_product;
using std::string;
using std::uniform_int_distribution;
using std::vector;

// Finite Impulse Response Filter
void fir(vector<int> &output, const vector<int> &signal,
         const vector<int> &coeff) {
    auto out_iter = begin(output);
    auto rsignal_iter = signal.rend() - 1;

    int i = 0;
    while (rsignal_iter != signal.rbegin() - 1) {
        int elements = std::min((int)coeff.size(), i++);
        *(out_iter++) = inner_product(begin(coeff), begin(coeff) + elements,
                                      rsignal_iter--, 0);
    }
}

int gen_random() {
    static default_random_engine e;
    static uniform_int_distribution<int> dist(0, 100);

    return dist(e);
}

void print_signal(vector<int> &device_output) {
    for (auto val : device_output) {
        printf("%d ", val);
    }
    printf("\n");
}

// Verifies the gold and the out data are equal
void verify(const vector<int> &gold, const vector<int> &out) {
    bool match = equal(begin(gold), end(gold), begin(out));
    if (!match) {
        printf("TEST FAILED\n");
        exit(EXIT_FAILURE);
    }
}

// Launches the Finite Impulse Response(FIR) kernel and prints the execution time
vector<int> test_fir(cl::CommandQueue &q, cl::Program &program, string kernel_name,
                     cl::Buffer &buffer_output, cl::Buffer &buffer_signal,
                     cl::Buffer &buffer_coeff, int signal_size) 
{
    vector<int> device_output(signal_size, 0);
    cl::Kernel kernel(program, kernel_name.c_str());

    kernel.setArg(0,buffer_output);
    kernel.setArg(1,buffer_signal);
    kernel.setArg(2,buffer_coeff);
    kernel.setArg(3,signal_size);

    cl::Event event;
    uint64_t nstimestart, nstimeend;
    q.enqueueTask(kernel,NULL,&event);
    q.finish();
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
    auto kernel_time = nstimeend-nstimestart;

    printf("| %-30s | %23lu |\n", kernel_name.c_str(), kernel_time);
    q.enqueueReadBuffer(buffer_output, CL_TRUE, 0, signal_size * sizeof(int), 
            device_output.data());

    return device_output;
}

int main(int argc, char **argv) {
    size_t signal_size = 32;
    vector<int> signal(signal_size);
    generate(begin(signal), end(signal), gen_random);
    vector<int> coeff = {{53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53}};
    vector<int> gold(signal_size, 0);

    fir(gold, signal, coeff);

    size_t size_in_bytes = signal_size * sizeof(int);
    size_t coeff_size_in_bytes = coeff.size() * sizeof(int);

    // Initialize OpenCL context and load xclbin binary
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context,device,CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    //Create Program 
    cl::Program::Binaries bins = xcl::import_binary(device_name,"fir");
    devices.resize(1);
    cl::Program program(context, devices, bins);

    cl::Buffer buffer_signal(context, CL_MEM_READ_ONLY, size_in_bytes);
    cl::Buffer buffer_coeff (context, CL_MEM_READ_ONLY, coeff_size_in_bytes);
    cl::Buffer buffer_output(context, CL_MEM_WRITE_ONLY,size_in_bytes);

    q.enqueueWriteBuffer(buffer_signal,CL_TRUE, 0,size_in_bytes, signal.data());
    q.enqueueWriteBuffer(buffer_coeff, CL_TRUE, 0,coeff_size_in_bytes, coeff.data());

    printf( "|--------------------------------+-------------------------|\n"
            "| Kernel                         |    Wall-Clock Time (ns) |\n"
            "|--------------------------------+-------------------------|\n");
    auto device_output = test_fir(q,program, "fir_naive", buffer_output,
                                  buffer_signal, buffer_coeff, signal_size);
    verify(gold, device_output);

    device_output = test_fir(q,program, "fir_shift_register", buffer_output,
                                  buffer_signal, buffer_coeff, signal_size);
    verify(gold, device_output);

    printf("|--------------------------------+-------------------------|\n");
    printf("Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n");
    printf("Please refer to profile summary for kernel execution time for hardware emulation.\n\n");

    print_signal(device_output);
    printf("TEST PASSED\n");
    return EXIT_SUCCESS;
}
