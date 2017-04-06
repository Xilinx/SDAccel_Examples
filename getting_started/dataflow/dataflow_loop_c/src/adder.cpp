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
    HLS Loop Dataflow Example using HLS Stream datatype. 
    This is example of vector addition to demonstrate HLS Dataflow Pragma 
    functionality to perform multiple loops parallelism using HLS Stream datatype. 
    HLS dataflow pragma instruct compiler to run loops concurrently. Loops can 
    transfer the data using hls stream. In this Example a vector addition 
    implementation is divided into three loops as below:

    1) Loop1:Memory Read 
        This Loop reads the input vector from Global Memory and writes it into 
        HLS Stream 'inStream' using blocking write command.

    2) Loop2: Execution Loop 
        This Loop reads the input vector from 'inStream' using blocking
        read command and increment the each vector element by user specified value.
        It writes the results into 'outStream' using blocking write command.

    3) Loop3: Memory Write
        This Loop reads the result vector from 'outStream' using blocking read
        command and write the result into Global Memory Location.


     Loop Dataflow based Adder will be implemented as below:
                     _____________
                    |             |<----- Input Vector from Global Memory
                    |   loop1:    |
                    |  (mem_rd)   |       __
                    |_____________|----->|  |
                     _____________       |  | inStream
                    |             |<-----|__|
                    |   loop2:    |
                    |  (execute)  |       __
                    |_____________|----->|  |
                     _____________       |  | outStream
                    |             |<-----|__|
                    |   loop3:    |
                    |  (mem_wr)   |       
                    |_____________|-----> Output result to Global Memory


*******************************************************************************/

//Includes 
#include <hls_stream.h>

extern "C" {
/*
    Vector Addition Kernel Implementation using dataflow on loops
    Arguments:
        in   (input)  --> Input Vector
        out  (output) --> Output Vector
        inc  (input)  --> Increment
        size (input)  --> Size of Vector in Integer 
   */
void adder(unsigned int *in, unsigned int *out, int inc, int size)
{
#pragma HLS INTERFACE m_axi port=in  offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=in  bundle=control
#pragma HLS INTERFACE s_axilite port=out bundle=control
#pragma HLS INTERFACE s_axilite port=inc bundle=control
#pragma HLS INTERFACE s_axilite port=size bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    hls::stream<unsigned int> inStream;
    hls::stream<unsigned int> outStream;
#pragma HLS STREAM variable=inStream  depth=32
#pragma HLS STREAM variable=outStream depth=32
//  HLS STREAM variable=<name> depta=<size> pragma is used to define the Stream 
//  depth. For this example, Depth 32 is defined. Which means that Stream can hold 
//  maximum 32 outstanding elements at a given time. If Stream is full, any further
//  blocking write command from producer will go into wait state until consumer 
//  reads some elements from stream. Similarly if Stream is empty (no element in Stream)
//  any blocking read command from consumer will go into wait state until producer
//  writes elements to Stream. This blocking read and write allow consumer and 
//  producer to synchronize each other.

    //dataflow pragma instruct compiler to run following three 'For' Loops concurrently
#pragma HLS dataflow
    //Loop1: Read Data from Global Memory and write into Stream inStream
    mem_rd: for (int i = 0 ; i < size ; i++){
    //Xilinx HLS by default try to implement pipeline design for loop, 
    //so explicit PIPELINE pragma is not needed
    #pragma HLS LOOP_TRIPCOUNT min=4096 max=4096
        //Blocking write command to inStream 
        inStream << in[i];
    }

    //Loop2: Read Input data from inStream and write the result into outStream
    execute: for (int j = 0 ; j < size ; j++){
    //Xilinx HLS by default try to implement pipeline design for loop, 
    //so explicit PIPELINE pragma is not needed
    #pragma HLS LOOP_TRIPCOUNT min=4096 max=4096
        //Blocking read command from inStream and Blocking write command 
        //to outStream 
        outStream << (inStream.read() + inc);
    }

    //Loop3: Read result from outStream and write the result to Global Memory
    mem_wr: for (int k = 0 ; k < size ; k++) {
    //Xilinx HLS by default try to implement pipeline design for loop, 
    //so explicit PIPELINE pragma is not needed
    #pragma HLS LOOP_TRIPCOUNT min=4096 max=4096
        //Blocking read command from OutStream 
        out[k] = outStream.read();
    }
}
}
