/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_rsa.cl
Purpose: SDAccel rsa example
Revision History: December 6, 2015

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/



typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef unsigned long u64;
#define N 32

//z[]=z[]+x[]*y
void addmul_1(u32 *z, u32 *x, u32 y)//,int N)
{

	u32 ph, pl, cy, trg, dummy;
	int id = get_local_id(0);  
	int index=3; 
	trg = z[id];

  // multiply
	pl = x[id] * y;
	ph = mul_hi(x[id], y);

  // Add
	dummy = pl + trg; 
	ph += (dummy < pl);
	z[id] = dummy;

  // propagate higher products
	trg = z[id+1];
 	dummy = trg + ph; 
	cy = (dummy < trg);
	z[id+1] = dummy;
	
  // propagate carries from that
	trg = z[id+2];
	dummy = trg + cy; 
  	cy = (dummy < trg);
 	 z[id+2] = dummy;

  // While there are any carries left....should be executed near never
 	 while(cy)//(any(cy != 0))
  	{   
    		if(id+index < 32+2)

    		{
     			trg = z[id+index];
      			dummy = trg + cy; 
  			cy = (dummy < trg);
 			z[id+index] = dummy;
   		 }
   		 ++index;
 	 }
}

 
//z=x-y
void sub_n(u32 *z, u32 *x, u32 *y)//,int N)
{
 	u32 cy;
  	u32 tmp, dummy;
  	int id = get_local_id(0);
  	int index = 2;
 
  // Subtract	
  	tmp = z[id];
   	tmp = x[id] - y[id];
 	cy = (tmp > x[id]);
 	z[id] = tmp;

  // Propagate first set of carries
  	tmp = z[id+1];
	dummy = tmp - cy; 
  	cy = (dummy > tmp);
  	z[id+1] = dummy;
 	 while(cy)//(any(cy))
  	{
   		 if(index+id < 32+2)
    		{
      			tmp = z[id+index];
  			dummy = tmp - cy; 
  			cy = (dummy > tmp);
			z[id+index] = dummy;
    		}
  		++index;
	  }
}

 
//decide if x is greater than y
int cmp_ge_n(u32 *x, u32 *y)//,int N)

{
	int i;

  	if(x[N]){
	return 1;
 	 }


  for(i=N-1; i >= 0; --i){
	if(x[i] > y[i]){
  		return 1;
  		}
	else if(x[i] < y[i]){
    		return 0;
		}
	}

  return 1; // equal

}


 //z=xR(-1)%n montgomery reduction
void redc(u32 *z, u32 *x, u32 *n, const u32 d, u32 *t)//,int N)

{

  int i;
  u32 m;
  int id = get_local_id(0);
  t[id] = x[id];
  t[N] = t[N+1] = 0;
  
for(i=0; i < N; ++i)

  {
	 u32 u;
  	m = t[0]*d;
	addmul_1(t, n, m);//, N);//t=t+n*m

    // right shift
	u = t[id+1];
	t[id] = u;
	t[N] = 0; 
  }

 
  // Final fix --- executed about half the time

  if(cmp_ge_n(t, n))  //,N)){
	{
    	sub_n(t, t, n);//,N);  //t=t-n

	}

  z[id] = t[id]; 

}

 
//z=x*y*d%n
void mulredc(u32 *z, u32 *x, u32 *y, u32 *n, const u32 d, u32 *t)//,int N)

{
 	 int i, id = get_local_id(0);  
  	u32 m, u;
 	t[id] = 0;
  	t[N] = t[N+1] = 0;

 	for(i=0; i < N; ++i)
  	{

    	// t=t+xy[i]
		addmul_1(t, x, y[i]);//, N);
    
	// reduce
		m = d*t[0];
    		addmul_1(t, n, m);//, N);

    // shift
   		u = t[id+1];
    		t[id] = u;
   		u = t[N+1];
    		t[N] = u;
    		t[N+1] = 0;     

  	}

  

	if(cmp_ge_n(t, n))//, N)){
	{
		sub_n(t, t, n);//,N);
	}  

  	z[id] = t[id];   

}

 // Compute the 2adic inverse of x
//inverse %2^32
u32 inv2adic(u32 x)

{

  	u32 a;
  	a = x;
  	x = (((x+2)&4)<<1)+x; // correct to 4 bits
  	x *= 2 - a*x; // 8 bits
 	 x *= 2 - a*x; // 16 bits
	 x *= 2 - a*x; // 32 bits
	 return -x; // -x^-1 mod 2^32

}

 
//x is ciphertext, z is plaintext, exponent, mod, r2 is the constant used in montgomery multilication
//__kernel void g_modexp(__global u32 *z,__global u32 *x, __global u32 *exponent, __global u32 *mod, __global u32 *r2)
__kernel void rsa(__global u32 *z,__global u32 *x, __global u32 *exponent, __global u32 *mod, __global u32 *r2)
{

	u32 d;
  	//u32 N = 32; 
 	int STRIDE = 32; //localworksize
  	int BITS = 1024; //rsa1024

  //__constant
	u32  a[N], n[N], workspace[(N+2)];
  	u32 t[N];
  	int id = get_local_id(0);
 	u32 i,j;  
	u32 ex; 	
  	u32 blockId = get_group_id(0)*STRIDE;
 	t[id] = x[id + blockId ]; //t is ciphertext                          
	a[id] = r2[id + blockId]; //R^2 for montgomery multiplicaiton
  	n[id] = mod[id + blockId];//n is moduli
  	d = inv2adic(n[0]); // d=-1/n%2^32

  	mulredc(t, t, a, n, d, workspace);//, N); // t = tr %n, montgomery multiplicaiton, t ordinary to montgomery form

 	redc(a, a, n, d, workspace);//, N); // a = r%n

//right-to-left binary exponentiation, 1 workgroup compute one RSA decryption
  for(i=0; i < BITS/32; ++i)
  {
   	 ex = exponent[i + blockId]; 
    	for(j=0; j < 32; ++j)
   	 {
      		if(ex&1)
        	mulredc(a, a, t, n, d, workspace);//, N);//montgommultiply, a=a*t
      		mulredc(t, t, t, n, d, workspace);//, N); //square, t=t*t
      		ex >>= 1;
    	 }              

    }

  redc(a,a,n,d, workspace);// N); //a=a%n, montgomery back to ordinary
  z[id + blockId] = a[id];
}
