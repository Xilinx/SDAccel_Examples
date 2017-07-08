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
#include "xcl2.hpp"
#include <vector>

#define LENGTH 16

int main(int argc, char** argv)
{
   int check_status = 0;

   std::vector<int,aligned_allocator<int>> h_a(LENGTH);// host memory for a vector
   std::vector<int,aligned_allocator<int>> h_b(LENGTH);// host memory for b vector
   std::vector<int,aligned_allocator<int>> h_c(LENGTH);// host memort for c vector

   // Fill our data sets with pattern
   //
   int i = 0;
   for (i = 0; i < LENGTH; i++) {
      h_a[i] = i;
      h_b[i] = i;
      h_c[i] = 0;
   }

   std::vector<cl::Device> devices = xcl::get_xil_devices();
   cl::Device device = devices[0];

   //Creating Context and Command Queue for selected Device 
   cl::Context context(device);
   cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
   std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
   std::cout << "Found Device=" << device_name.c_str() << std::endl;

   printf("INFO: loading vmul kernel\n");
   std::string vmulBinaryFile = xcl::find_binary_file(device_name,"krnl_vmul");
   cl::Program::Binaries bins = xcl::import_binary_file(vmulBinaryFile);
   devices.resize(1);
   cl::Program * program_ptr = new cl::Program(context, devices, bins);
   cl::Kernel krnl_vmul(*program_ptr,"krnl_vmul");

   std::vector<cl::Memory> inBufVec, outBufVec;
   cl::Buffer d_a(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
           sizeof(int) * LENGTH, h_a.data());
   cl::Buffer d_b(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
           sizeof(int) * LENGTH, h_b.data());
   cl::Buffer d_mul_c(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, 
           sizeof(int) * LENGTH, h_c.data());
   inBufVec.push_back(d_a);
   inBufVec.push_back(d_b);
   outBufVec.push_back(d_mul_c);

   q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

   krnl_vmul.setArg(0, d_a);
   krnl_vmul.setArg(1, d_b);
   krnl_vmul.setArg(2, d_mul_c);

   // This function will execute the kernel on the FPGA
   q.enqueueTask(krnl_vmul);

   //XPR Platform (Xilinx Expanded Partial Reconfiguration Platform) supports larger Kernel
   // binaries compare to non-XPR Platform. However this platform has one limitation with
   // respect non-XPR, it does not persist the Global Memory(DDR) content when user switches
   // between multiple binaries. So for such case, user should be responsible to 
   // migrate the required buffer from device to host and later use migrate buffer back to
   // device after second binary is imported

   q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
   q.finish();

   // Check Results
   for (int i = 0; i < LENGTH; i++) {
      if ((h_a[i] * h_b[i]) != h_c[i]) {
         printf("ERROR in vmul - %d - a=%d, b=%d, c=%d\n", i, h_a[i], h_b[i], h_c[i]);
         check_status = 1;
      }
   }

   //Deleting existing program object before loading the 2nd program
   delete(program_ptr);
   program_ptr = nullptr;


   printf("INFO: loading vadd_krnl\n");
   std::string vaddBinaryFile = xcl::find_binary_file(device_name,"krnl_vadd");
   cl::Program::Binaries vadd_bins = xcl::import_binary_file(vaddBinaryFile);
   program_ptr = new cl::Program(context, devices, vadd_bins);
   cl::Kernel krnl_vadd(*program_ptr,"krnl_vadd");

   cl::Buffer d_add_c(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, 
            sizeof(int) * LENGTH, h_c.data());

   //Migrating the buffer from Host to Device
   inBufVec.clear();
   outBufVec.clear();
   inBufVec.push_back(d_mul_c);
   outBufVec.push_back(d_add_c);
   q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

   //use the results from vmul as a and b inputs for vadd
   krnl_vadd.setArg(0,d_mul_c);
   krnl_vadd.setArg(1,d_mul_c);
   krnl_vadd.setArg(2,d_add_c);

   // This function will execute the kernel on the FPGA
   q.enqueueTask(krnl_vadd);

   q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
   q.finish();

   // Check Results
   for (int i = 0; i < LENGTH; i++) {
      if ((2*(h_a[i] * h_b[i])) != h_c[i]) {
         printf("ERROR in vadd - %d - c=%d\n", i, h_c[i]);
         check_status = 1;
      }
   }

   //cleanup
   delete(program_ptr);
   program_ptr = nullptr;
   
   std::cout << "TEST " << (check_status ? "FAILED" : "PASSED") << std::endl; 
   return (check_status ? EXIT_FAILURE :  EXIT_SUCCESS);
}
