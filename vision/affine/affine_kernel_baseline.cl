/**********
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
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/
#define PI     3.14159265359f
#define WHITE  (short)(1)
#define BLACK  (short)(0)

#define X_SIZE 512
#define Y_SIZE 512


#ifdef C_COMPILE
void affine_kernel(float *x_rot,   float *y_rot, 
                   float *x_expan, float *y_expan, 
                   int   *x_move,  int   *y_move,
                   unsigned short *image1,
                   unsigned short *image2
                  )
#else
__kernel __attribute__ ((reqd_work_group_size(1, 1, 1)))
/*
void affine_kernel(__global float *x_rot,   __global float *y_rot, 
                   __global float *x_expan, __global float *y_expan, 
                   __global int   *x_move,  __global int   *y_move,
                   __global unsigned short *image1,
                   __global unsigned short *image2
                  )
*/
void affine_kernel(__global unsigned short *image1,
                   __global unsigned short *image2
                  )
#endif
{
/*
   float    lx_rot   = *x_rot;
   float    ly_rot   = *y_rot; 
   float    lx_expan = *x_expan;
   float    ly_expan = *y_expan; 
   int      lx_move  = *x_move;
   int      ly_move  = *y_move;
*/
   float    lx_rot   = 30.0f;
   float    ly_rot   = 0.0f; 
   float    lx_expan = 0.5f;
   float    ly_expan = 0.5f; 
   int      lx_move  = 0;
   int      ly_move  = 0;

   float    affine[2][2];
   float    i_affine[2][2];
   float    beta[2];
   float    i_beta[2];
   float    det;
   float    x_new, y_new;
   float    x_frac, y_frac;
   float    gray_new;
   int      x, y, m, n;
  
   // forward affine transformation
   affine[0][0] = lx_expan * cos((float)(lx_rot*PI/180.0f));
   affine[0][1] = ly_expan * sin((float)(ly_rot*PI/180.0f));
   affine[1][0] = lx_expan * sin((float)(lx_rot*PI/180.0f));
   affine[1][1] = ly_expan * cos((float)(ly_rot*PI/180.0f));
   beta[0]      = lx_move;
   beta[1]      = ly_move;
  
   // determination of inverse affine transformation
   det = (affine[0][0] * affine[1][1]) - (affine[0][1] * affine[1][0]);
   if (det == 0.0f)
   {
      i_affine[0][0]   = 1.0f;
      i_affine[0][1]   = 0.0f;
      i_affine[1][0]   = 0.0f;
      i_affine[1][1]   = 1.0f;
      i_beta[0]        = -beta[0];
      i_beta[1]        = -beta[1];
   } 
   else 
   {
      i_affine[0][0]   =  affine[1][1]/det;
      i_affine[0][1]   = -affine[0][1]/det;
      i_affine[1][0]   = -affine[1][0]/det;
      i_affine[1][1]   =  affine[0][0]/det;
      i_beta[0]        = -i_affine[0][0]*beta[0]-i_affine[0][1]*beta[1];
      i_beta[1]        = -i_affine[1][0]*beta[0]-i_affine[1][1]*beta[1];
   }
  
   // Output image generation by inverse affine transformation and bilinear transformation
   for (y = 0; y < Y_SIZE; y++)
   {
      for (x = 0; x < X_SIZE; x++)
      {
         x_new    = i_beta[0] + i_affine[0][0]*(x-X_SIZE/2.0f) + i_affine[0][1]*(y-Y_SIZE/2.0f) + X_SIZE/2.0f;
         y_new    = i_beta[1] + i_affine[1][0]*(x-X_SIZE/2.0f) + i_affine[1][1]*(y-Y_SIZE/2.0f) + Y_SIZE/2.0f;

         m        = (int)floor(x_new);
         n        = (int)floor(y_new);

         x_frac   = x_new - m;
         y_frac   = y_new - n;
      
         if ((m >= 0) && (m + 1 < X_SIZE) && (n >= 0) && (n+1 < Y_SIZE))
         {
		      gray_new = (1.0f - y_frac) * ((1.0f - x_frac) * (image1[(n * X_SIZE) + m])       + x_frac * (image1[(n * X_SIZE) + m + 1])) + 
                               y_frac  * ((1.0f - x_frac) * (image1[((n + 1) * X_SIZE) + m]) + x_frac * (image1[((n + 1) * X_SIZE) + m + 1]));
		      image2[(y * X_SIZE) + x] = (unsigned short)gray_new;
         } 
         else if (((m + 1 == X_SIZE) && (n >= 0) && (n < Y_SIZE)) || ((n + 1 == Y_SIZE) && (m >= 0) && (m < X_SIZE))) 
         {
		      image2[(y * X_SIZE) + x] = image1[(n * X_SIZE) + m];
         } 
         else 
         {
		      image2[(y * X_SIZE) + x] = WHITE;
         }
      }
   }
}
