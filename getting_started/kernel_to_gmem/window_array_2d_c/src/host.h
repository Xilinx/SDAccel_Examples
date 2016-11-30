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
#include <hls_stream.h>
//Parameters Description:
//         NUM_ROWS:            matrix height
//         WORD_GROUP_PER_ROW:  number of groups/partitions of matrix row
//         WORD_GROUP_SIZE:     number of words in each group/partition
//         TILE_PER_COLUMN:     number of tiles/windows of matrix column
//         TILE_HEIGHT:         number of rows in matrix tile/window
//         BLOCK_SIZE:          number of words in an array

#define NUM_ROWS   64
#define WORD_GROUP_PER_ROW 4
#define WORD_GROUP_SIZE 16
#define TILE_PER_COLUMN 8
#define TILE_HEIGHT 8
#define BLOCK_SIZE (WORD_GROUP_SIZE*WORD_GROUP_PER_ROW*NUM_ROWS)

// default datatype is integer
typedef int DTYPE;
// use HLS stream library for easy use of AXI-stream interface
typedef hls::stream<DTYPE> my_data_fifo;
