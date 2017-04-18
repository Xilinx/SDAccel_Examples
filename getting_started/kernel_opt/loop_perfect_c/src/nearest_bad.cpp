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

SDx Key Concept :
    
    This is a nearest neighbor of a point example showcases how making a loop
    nest perfect or semi-perfect can help improve performance.

*******************************************************************************/

/*

Kernel Description : [Bad case]
   
    Finding the nearest neighbor of a point from a given set of points (of up to
    MAX_SIZE points). This is the bad version of the kernel where the loop nest 
    is neither perfect nor semi-perfect. Hence automatic flattening of the loop
    nest does not happen and performance drops.
    
    Note : This is the bad version of the kernel. The good version is present in
           nearest_good.cpp
    
    Arguments :
	    
	    int *in     (input )    --> Input Points Array - represented as integer
	    int *point  (input )    --> Current Point for which the nearest neighbor
	                                is found
	    int *out    (output)    --> Output Point
	    int size    (input )    --> Size of the input array
	    int dim     (input )    --> #Dimensions of the points

    Kernel Configuration :
        
        MAX_DIM     - #Dimensions of the input points can be up to MAX_DIM
        MAX_SIZE    - Size of the input array can be up to MAX_SIZE
*/

#include <string.h>
#include <stdio.h>
#include <limits.h>

// Compute distances using unsigned long
// and to avoid square root operation.
// Maximum possible distance between two points
#define INFINITY ULONG_MAX

#define SQUARE(x) ((x)*(x))

// Maximum #Dimensions for a point
#define MAX_DIM 16

// Maximum size of point array
#define MAX_SIZE 16384

extern "C"{
    void nearest(
				    const int *in,      // Input Points Array
				    const int *point,   // Current Point
				    int *out,           // Output Point
				    int size,           // Size of the input array
				    int dim             // #Dimensions of the points
			    )
    {
    #pragma HLS INTERFACE m_axi port=in offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=point offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem

    #pragma HLS INTERFACE s_axilite port=in bundle=control
    #pragma HLS INTERFACE s_axilite port=out bundle=control
    #pragma HLS INTERFACE s_axilite port=size bundle=control
    #pragma HLS INTERFACE s_axilite port=dim bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
       
        // Local memory to store input and output matrices
        // Local memory is implemented as BRAM memory blocks
        
        // Holds the input array of points
        int in_local[MAX_SIZE][MAX_DIM];
        #pragma HLS ARRAY_PARTITION variable=in_local complete dim=2
        
        // Holds the point for which the nearest neighbor is to be found
        int point_local[MAX_DIM];
        #pragma HLS ARRAY_PARTITION variable=point_local complete dim=1
        
        // Holds the current nearest point
        int point_nearest[MAX_DIM];
        #pragma HLS ARRAY_PARTITION variable=point_nearest complete dim=1
        
        // min_dist holds the minimum distance till now
        unsigned long min_dist = INFINITY;
        
        // curr_dist holds the value of distance between point_local and
        // the current point
        unsigned long curr_dist;
        
        // Burst reads on input from global memory, Points are read as
        // an array of integers and saved to in_local. 
        readInput: for(int itr = 0, i = 0, j = 0; itr < size*dim; itr++, j++){
        #pragma HLS LOOP_TRIPCOUNT min=16384*16 max=16384*16
        #pragma HLS PIPELINE
            if(j == dim) { j = 0; i++;}
            in_local[i][j] = in[itr];
        }

        // Burst reads the point for which nearest neighbor is to be found
        readCurrPt: for(int i = 0; i < dim; i++){
        #pragma HLS LOOP_TRIPCOUNT min=16 max=16
        #pragma HLS PIPELINE
            point_local[i] = point[i];
        }
        
        // Find the nearest neighbor
        
        // nearest1 loop goes over all the points
        // nearest2 loop finds the distance between point_local and the current
        // point. Based on this the minimum distance and the closest neighbor 
        // are updated.
        
        // In nearest loop nest, there are intermediate statements between the
        // loops. These statements prevent the loop flatten from happening
        nearest1: for(int i = 0; i < size; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=16384 max=16384
            curr_dist = 0;
            
            nearest2: for(int j = 0; j < dim; j++) {
            #pragma HLS LOOP_TRIPCOUNT min=16 max=16
            #pragma HLS PIPELINE
                curr_dist += SQUARE(point_local[j] - in_local[i][j]);
            }
            
            if(curr_dist < min_dist) {
                min_dist = curr_dist;
                nearest3: for(int k = 0; k < MAX_DIM; k++) {
                #pragma HLS UNROLL
                    point_nearest[k] = in_local[i][k];
                }
            }
        }
        
        // Burst writes the nearest neighbor to out
        wirteOuput: for(int i = 0; i < dim; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=16 max=16
        #pragma HLS PIPELINE
            out[i] = point_nearest[i];
        }
    }
}
