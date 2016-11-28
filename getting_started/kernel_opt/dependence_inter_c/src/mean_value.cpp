/*******************************************************************************
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
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/*******************************************************************************
Description: 
    This Example to demostrate HLS Dependence Pragma. Using HLS DEPENDECE pragma 
    user can provide additional dependency details to compiler which allow 
    compiler to implement unrolling/pipelining with optimized way.
*******************************************************************************/

//Includes 
#include <hls_stream.h>
#include <ap_int.h>

#define MAX_SIZE 1024
extern "C" {
/*
    Vector Mean Value Calculation 
    Arguments:
        in   (input)  --> Input Vector
        out  (output) --> Output Mean Vector
        size  (input)  --> Size of Vector in Integer
   */
void mean_value(int *in, int *out, int size)
{
#pragma HLS INTERFACE m_axi port=in  offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=in  bundle=control
#pragma HLS INTERFACE s_axilite port=out bundle=control
#pragma HLS INTERFACE s_axilite port=size bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    //Taking double size of MAX_SIZE as same local buffer will be used to store
    //input data as well as result value of mean_value. 
    int local_buffer[2 * MAX_SIZE];

    //burst read of input data
    mem_rd: for (int i = 0 ; i < size ; i++){
        local_buffer[i] = in[i];
    }

    //Calculating Mean Value
execution: for (int i = 1 ; i < size -1 ; i++) {
    #pragma HLS DEPENDENCE variable=local_buffer inter false
    //HLS Dependence pragma provide extra dependency information to compiler.
    //For exmaple here local_buffer has false inter dependency. Which means 
    //each iteration of loop is independent for local_buffer access. 
    //It allow compiler to ignore dependency of local_buffer and generate 
    //a pipeline with lower II count. If user do not provide this pragma, compiler 
    //will assume a dependency of local_buffer across iteration and will try to schedule
    //accordingly. As a result, compiler will increase the loop II and will reduce 
    //the performance.
        local_buffer[i + MAX_SIZE] = (local_buffer[i-1] + local_buffer[i] + local_buffer[i+1])/3;
    }

    //Calculating Average for Boundary Case values
    local_buffer[MAX_SIZE]  = (local_buffer[0] + local_buffer[1]) / 2 ;
    local_buffer[MAX_SIZE + size-1] = (local_buffer[size-1] + local_buffer[size-2]) /2 ;

    //burst Write of result
    mem_wr:for (int i = 0 ; i < size ; i++){
        out[i] = local_buffer[i+MAX_SIZE];
    }
}
}
