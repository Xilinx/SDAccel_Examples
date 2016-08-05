// File: kernel.cl
// Author: Xiaozhu Kang, Xilinx
// Description:
// Tiny Encryption Algorithm (TEA), a simple block cipher, optimized


kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void tinyEncryption(__global const uint2* my_input, __global uint2* my_output,__global const uint4* my_keys, int my_length) {
   local uint2 linebufInput[8192] __attribute__((xcl_array_partition(cyclic,8,1)));
   local uint4 linebufKeys[8192] __attribute__((xcl_array_partition(cyclic,8,1)));
   local uint2 linebufOutput[8192] __attribute__((xcl_array_partition(cyclic,8,1)));

  const uint delta=0x9e3779b9;
  async_work_group_copy(linebufInput, my_input, 8192, 0);
  async_work_group_copy(linebufKeys, my_keys, 8192, 0);
  __attribute__((xcl_pipeline_loop))
  for(int i=0;i<1024;i++) {
    for(int k=0;k<8;k++){
    uint v0=linebufInput[8*i+k].x, v1=linebufInput[8*i+k].y, sum=0;
    uint k0=linebufKeys[8*i+k].x, k1=linebufKeys[8*i+k].y, k2=linebufKeys[8*i+k].z, k3=linebufKeys[8*i+k].w;
    for (int j=0; j < 32; j++) {
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }
    linebufOutput[8*i+k].x=v0;
    linebufOutput[8*i+k].y=v1;
   }
  }
  async_work_group_copy(my_output, linebufOutput, 8192, 0);
}
