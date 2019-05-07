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

  Stream_access Host Code
  There are many applications where all of the data cannot reside in an FPGA.
  For example, the data is too big to fit in an FPGA or the data is being
  streamed from a sensor or the network. In these situations data must be
  transferred as chunks from the host memory to FPGA before the computation can be
  performed on FPGA and vice-versa to copy back the result.
  Because PCIe is an full-duplex interconnect, you can transfer data to and from
  the FPGA simultaneously. Xilinx FPGAs can also perform computations during
  these data transfers. Performing all three of these operations at the same
  time allows you to keep the FPGA busy and take full advantage of all of the
  hardware on your system.
  Many OpenCL commands are asynchronous. This means that whenever you call an
  OpenCL function, the function will return before the operation has completed.
  Asynchronous nature of OpenCL allows you to simultaneously perform tasks on
  the host CPU as well as the FPGA.
*******************************************************************/
#include "streams_vadd.h"
////////////////////RESET FUNCTION//////////////////////////////////
int reset(int* a, int*b, int* sw_results, int* hw_results, int size)
{
    //Fill the input vectors with data
    for(int i = 0; i < size; i++)
    {
        a[i] = rand() % size;
        b[i] = rand() % size;
        hw_results[i] = 0;
        sw_results[i] = a[i] + b[i];
    }
    return 0;
}
///////////////////VERIFY FUNCTION///////////////////////////////////
int verify(int* a, int*b, int* sw_results, int* hw_results, int size)
{
    bool match = true;
    for (int i = 0; i < size; i++){
        std::cout << "i: " << i << "\ta: " << a[i] << "\tb: " << b[i] << "\tsw: " << sw_results[i] << "\thw: " << hw_results[i] << std::endl;
        if(sw_results[i] != hw_results[i]){
            match = false;
            break;
        }
    }
    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;    
    return match;
}
////////MAIN FUNCTION//////////
int main(int argc, char** argv)
{
    int size = DATA_SIZE;

    // I/O Data Vectors
    std::vector<int,aligned_allocator<int>> h_a(size);
    std::vector<int,aligned_allocator<int>> h_b(size);
    std::vector<int,aligned_allocator<int>> hw_results(size);
    std::vector<int> sw_results(size);

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
		return EXIT_FAILURE;
	}

    auto binaryFile = argv[1];
    std::cout << "Vector Addition of elements " << DATA_SIZE << std::endl;

    // Reset the data vectors
    reset(h_a.data(), h_b.data(), sw_results.data(), hw_results.data(), size);

    // OpenCL Setup: xdevice_vadd is a class that contains all the OpenCL objects, necessary functions and the application.
    xdevice_vadd x_vadd(binaryFile);

    // Running the Kernel with blocking Stream APIs 
    std::cout << "############################################################\n";
    std::cout << "                     Blocking Stream                        \n";
    std::cout << "############################################################\n";
    x_vadd.run_blocking(h_a.data(), h_b.data(), hw_results.data());

    // Compare the results
    verify(h_a.data(), h_b.data(), sw_results.data(), hw_results.data(), size);
    
    // Reset the data vectors
    reset(h_a.data(), h_b.data(), sw_results.data(), hw_results.data(), size);

    //Running the kernel with non-blocking Stream APIs
    std::cout << "############################################################\n";
    std::cout << "                  Non-Blocking Stream                       \n";
    std::cout << "############################################################\n";
    x_vadd.run_non_blocking(h_a.data(), h_b.data(), hw_results.data());

    // Compare the device results with software results
    verify(h_a.data(), h_b.data(), sw_results.data(), hw_results.data(), size);

    return 0;
}
