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

Kernel Description : [Good case]
   
    Finding the nearest neighbor of a point from a given set of points (of up to
    MAX_SIZE points). This is the bad version of the kernel where the loop nest 
    is neither perfect nor semi-perfect. Hence automatic flattening of the loop
    nest does not happen and performance drops.
    
    Note : This is the bad version of the kernel. The good version is present in
           nearest_good.cl
    
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

// Compute distances using unsigned long
// and to avoid square root operation.
// Maximum possible distance between two points
#define INF_DIST ULONG_MAX

#define SQUARE(x) ((x)*(x))

// Maximum #Dimensions for a point
#define MAX_DIM 16

// Maximum size of point array
#define MAX_SIZE 16384

__kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
void nearest(
			    const __global int *in,     // Input Points Array
			    const __global int *point,  // Current Point
			    __global int *out,          // Output Point
			    int size,                   // Size of the input array
			    int dim                     // #Dimensions of the points
		    )
{
    // Local memory to store input and output matrices
    // Local memory is implemented as BRAM memory blocks
    
    // Holds the input array of points
    int in_local[MAX_SIZE][MAX_DIM] __attribute__((xcl_array_partition(complete, 2)));
    
    // Holds the point for which the nearest neighbor is to be found
    int point_local[MAX_DIM] __attribute__((xcl_array_partition(complete, 1)));
    
    // Holds the current nearest point
    int point_nearest[MAX_DIM] __attribute__((xcl_array_partition(complete, 1)));
    
    // min_dist holds the minimum distance till now
    unsigned long min_dist = INF_DIST;
    
    // curr_dist holds the value of distance between point_local and
    // the current point
    unsigned long curr_dist;
    
    // Burst reads on input from global memory, Points are read as
    // an array of integers and saved to in_local. 
    __attribute__((xcl_pipeline_loop))
    readInput: for(int itr = 0, i = 0, j = 0; itr < size*dim; itr++, j++){
        if(j == dim) { j = 0; i++;}
        in_local[i][j] = in[itr];
    }
    
    // Burst reads the point for which nearest neighbor is to be found
    __attribute__((xcl_pipeline_loop))
    readCurrPt: for(int i = 0; i < dim; i++){
        point_local[i] = point[i];
    }
    
    // Find the nearest neighbor
        
    // nearest1 loop goes over all the points
    // nearest2 loop finds the distance between point_local and the current
    // point. Based on this the minimum distance and the closest neighbor 
    // are updated.
    
    // In nearest2 loop, there are specific conditions like if(j==0).
    // This is for enabling loop flatten to improve performance.
    nearest1: for(int i = 0; i < size; i++) {
        curr_dist = 0;
        
        __attribute__((xcl_pipeline_loop))
        nearest2: for(int j = 0; j < dim; j++) {
            curr_dist += SQUARE(point_local[j] - in_local[i][j]);
        }
        
        if(curr_dist < min_dist) {
            min_dist = curr_dist;
            
            __attribute__((opencl_unroll_hint))
            nearest3: for(int k = 0; k < MAX_DIM; k++) {
                point_nearest[k] = in_local[i][k];
            }
        }
    }
    
    // Burst writes the nearest neighbor to out
    __attribute__((xcl_pipeline_loop))
    wirteOuput: for(int i = 0; i < dim; i++) {
        out[i] = point_nearest[i];
    }
}
