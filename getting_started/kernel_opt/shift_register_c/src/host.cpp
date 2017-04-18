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

#include "CL/cl.h"
#include "xcl.h"

#include <algorithm>
#include <random>
#include <string>
#include <vector>
#include <iostream>

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
vector<int> test_fir(xcl_world world, vector<int> signal, vector<int> coeff, int signal_size, 
int coeff_size_in_bytes, int size_in_bytes, bool good) {
    cl_program program = xcl_import_binary(world, good ? "fir_GOOD" : "fir_BAD");
    cl_kernel krnl_fir = xcl_get_kernel(program, "fir_shift_register");
    std::cout << "\n" << std::endl;
    std::cout << "Starting" << (good ? " GOOD" : " BAD") << " Kernel" << std::endl;

    // Allocate Buffer in Global Memory
    cl_mem buffer_signal = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
    cl_mem buffer_coeff = xcl_malloc(world, CL_MEM_READ_ONLY, coeff_size_in_bytes);
    cl_mem buffer_output = xcl_malloc(world, CL_MEM_WRITE_ONLY, size_in_bytes);

    // Copy input data to device global memory
    xcl_memcpy_to_device(world, buffer_signal, signal.data(), size_in_bytes);
    xcl_memcpy_to_device(world, buffer_coeff, coeff.data(), coeff_size_in_bytes);

    vector<int> device_output(signal_size, 0);

    xcl_set_kernel_arg(krnl_fir, 0, sizeof(cl_mem), &buffer_output);
    xcl_set_kernel_arg(krnl_fir, 1, sizeof(cl_mem), &buffer_signal);
    xcl_set_kernel_arg(krnl_fir, 2, sizeof(cl_mem), &buffer_coeff);
    xcl_set_kernel_arg(krnl_fir, 3, sizeof(int), &signal_size);

    
    auto kernel_time = xcl_run_kernel3d(world, krnl_fir, 1, 1, 1);

    if(good == true){
        std::cout << "|-------------------------------------+-------------------------|\n";
        printf("| %-35s | %23lu |\n", "fir_optimized", kernel_time);
        std::cout << "|-------------------------------------+-------------------------|\n";
    }
    else {
        std::cout << "|-------------------------------------+-------------------------|\n";
        printf("| %-35s | %23lu |\n", "fir_naive", kernel_time);
        std::cout << "|-------------------------------------+-------------------------|\n";
    }

    xcl_memcpy_from_device(world, device_output.data(), buffer_output,
                           signal_size * sizeof(int));

    std::cout << "Finished " << (good ? " GOOD" : " BAD") << " Kernel" << std::endl;

    // Release Device Memories and Kernels
    clReleaseMemObject(buffer_signal);
    clReleaseMemObject(buffer_coeff);
    clReleaseMemObject(buffer_output);
    clReleaseKernel(krnl_fir);
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
    xcl_world world = xcl_world_single();
    
    auto device_output =
        test_fir(world, signal, coeff, signal_size, coeff_size_in_bytes, size_in_bytes, true);
    verify(gold, device_output);
    
    device_output =
        test_fir(world, signal, coeff, signal_size, coeff_size_in_bytes, size_in_bytes, false);
    verify(gold, device_output);
     
    std::cout << "\n--------------------------------------+--------------------------\n";
    std::cout << "Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n";
    std::cout << "Please refer to profile summary for kernel execution time for hardware emulation.\n\n";

    xcl_release_world(world);

    print_signal(device_output);
    std::cout << "TEST PASSED\n";
    return EXIT_SUCCESS;
}
