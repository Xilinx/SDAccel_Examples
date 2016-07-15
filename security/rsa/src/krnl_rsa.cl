/*******************************************************************************
Vendor: Xilinx
Associated Filename: rsa.cl, implemented CRT and sliding window for 1024 bit decryption
Purpose: SDAccel rsa example
Revision History: Feb 2, 2016

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
#define N 16

 // Compute the 2adic inverse of x
//inverse %2^32
inline u32 inv2adic(u32 x)

{

  	u32 a;
  	a = x;
  	x = (((x+2)&4)<<1)+x; // correct to 4 bits
  	x *= 2 - a*x; // 8 bits
 	 x *= 2 - a*x; // 16 bits
	 x *= 2 - a*x; // 32 bits
	 return -x; // -x^-1 mod 2^32

}

//z=x-y
inline u32 sub_n(local u32 *z, local u32 *x, local u32 *y)
{
 	u32 cy=0, temp;
  	int i;
__attribute__((xcl_pipeline_loop))
   for (i=0; i<N; i++)
  {
    //Use temp to handle the case where the output variable is the same as
    //one of the inputs
    temp = x[i] - y[i] - cy;
    cy = (temp > x[i]);
    z[i] = temp;
  }
	return cy;
}

inline u32 add_16(local u32 *z,local  u32 *x, local u32 *y)
{
  u32 carry = 0;
  u32 new_carry = 0;
  u32 temp;
  unsigned i;
__attribute__((xcl_pipeline_loop))
  for (i=0; i <N; i++)
  {
    //Broken into two steps to handle the case where one of the operands
    //is also the result variable
    temp = x[i] + y[i];
    new_carry = (temp < x[i]);

   z[i] = temp + carry;
    //Check for new_carry first as the probability that it will be
    //true is higher. And if it is, then the second compare can be skipped
    carry = (new_carry || (z[i] < temp));
  }

  return carry;
}

inline u32 add_32(local u32 *z,local  u32 *x, local u32 *y)
{
  u32 carry = 0;
  u32 new_carry = 0;
  u32 temp;
  unsigned i;
__attribute__((xcl_pipeline_loop))
  for (i=0; i <32; i++)
  {
    //Broken into two steps to handle the case where one of the operands
    //is also the result variable
    temp = x[i] + y[i];
    new_carry = (temp < x[i]);

   z[i] = temp + carry;
    //Check for new_carry first as the probability that it will be
    //true is higher. And if it is, then the second compare can be skipped
    carry = (new_carry || (z[i] < temp));
  }

  return carry;
}

//decide if x is greater than y
inline int cmp_ge_n(local u32 *x, local u32 *y)

{
	int i;

  	if(x[N]){
	return 1;
 	 }

__attribute__((xcl_pipeline_loop))
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

//z[]=z[]+x[]y
inline u32 addmul_1(local u32 *z, local u32 *x,u32 y)
{
  int i;
  u32 cy;
  u64 prod;

  cy = 0;
__attribute__((xcl_pipeline_loop))
  for(i=0; i < N; i++)
  {
    prod = (u64)x[i]*(u64)y;
    prod += cy;
    prod += z[i];
    z[i] = (u32)prod;
    cy = (u32)(prod>>32);
  }
  return cy;
}

//mimic openssl bn_mul_normal
 void mul_n(local u32 *z,local u32 *x, local u32 *y)

{
	local u32 *rr;
	 int i=N;

	rr=&(z[N]);
	rr[0]=addmul_1(z,x,y[0]);
__attribute__((xcl_pipeline_loop))
	for(;;)
	{
  		if(--i<=0)return;
   	 		rr[1] = addmul_1(&(z[1]) , x, y[1]);
		if(--i<=0)return;
			rr[2] = addmul_1(&(z[2]), x, y[2]);
		if(--i<=0)return;
			rr[3] = addmul_1(&(z[3]), x, y[3]);
		if(--i<=0)return;
			rr[4] = addmul_1(&(z[4]), x, y[4]);
		rr+=4;
		z+=4;
		y+=4;

	}
}

//z=x*y/R%n
void mulredc(local u32 *z, local u32 *x, local u32 *y, local u32 *n, const u32 d, local u32 *t)
{
	//k+=1;
  int i,j;
  u32 m, cy;
  u64 aux;

  for(i=0; i < N+2; i++)
    t[i] = 0;

__attribute__((xcl_pipeline_loop))
  for(i=0; i < N; i++)
  {
    cy = addmul_1(t, x, y[i]); // t += x*y[i]

    aux = (u64)t[N] + cy;
    t[N] = aux;
    t[N+1] = aux>>32;

    m = t[0]*d;

    cy = addmul_1(t, n, m);//t+=n*t[0]*d
    aux = (u64)t[N] + cy;

    t[N] = aux;
    t[N+1] = aux>>32;



    for(j=0; j <= N; j++) // shift,i.e./2^32
      t[j] = t[j+1];

    }

// Final fix --- executed about half the time

  if(cmp_ge_n(t, n)){

    	sub_n(t, t, n);  //t=t-n

	}

  for(i=0; i < N; i++)
    z[i] = t[i];
}

//z=xR(-1)%n montgomery reduction
void redc(local u32 *z,local u32 *x,local u32 *n, const u32 d,local u32 *t)

{
	int i,j;
  	u32 m;

  for(i=0; i < N; i++)
    t[i] = x[i];

  t[N] = 0;
__attribute__((xcl_pipeline_loop))
 for(i=0; i < N; i++)
  {
    m = t[0]*d;
    t[N] = addmul_1(t, n, m);

    for(j=0; j < N; j++) // shift,/2^32
      t[j] = t[j+1];

    t[N] = 0;
  }

if(cmp_ge_n(t, n)){

	sub_n(t, t, n);

	}

  for(i=0; i < N; i++)
    z[i] = t[i];

  }

//Cp, Cq is ciphertext, z stores decrypted message, p, q, dmp,dmq,iqmp, r2q,r2q is the constant used in montgomery multilication
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void rsa(__global u32 *z,__global u32 *Cpg, __global u32 *Cqg, __global u32 *pg, __global u32 *qg, __global u32 *dmp1g,__global u32 *dmq1g,__global u32 *iqmpg,__global u32 *r2pg,__global u32 *r2qg)
	{

	u32  d,ex;
	local u32 dtemp[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 workspace[18] __attribute__((xcl_array_partition(complete,1)));
        local u32 expo[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 q[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 product[32] __attribute__((xcl_array_partition(complete,1)));
        local u32 r2p[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 m1[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 m2[32] __attribute__((xcl_array_partition(complete,1)));
        local u32 n[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 t[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 iqmp[16] __attribute__((xcl_array_partition(complete,1)));
        local u32 a[16] __attribute__((xcl_array_partition(complete,1)));
	int i,j;
__attribute__((xcl_pipeline_loop))
	for(i=0;i<32;i++)
	{
		product[i]=0;
		m2[i]=0;
	}
	int id = get_global_id(0);

                async_work_group_copy(q, qg+16*id, 16, 0);
                async_work_group_copy(iqmp, iqmpg+16*id, 16, 0);
                async_work_group_copy(r2p, r2pg+16*id, 16, 0);

		async_work_group_copy(t, Cqg+16*id, 16, 0);
		async_work_group_copy(a, r2qg+16*id, 16, 0);
		async_work_group_copy(n, qg+16*id, 16, 0);
		async_work_group_copy(expo, dmq1g+16*id, 16, 0);

	d = inv2adic(n[0]); //C0797221

  	mulredc(t, t, a, n, d, workspace); // t = tr %n=, montgomery multiplicaiton, t ordinary to montgomery form


 	redc(a, a, n, d, workspace); // a = r%n

  for(i=16; i >0 ; --i)
  {
   	 ex = expo[i-1];

    	for(j=0; j<32; j++)
   	 {

        	mulredc(a, a, a, n, d, workspace);// a=a*a*d%n

		if(ex&(0x80000000>>j))
      		{mulredc(a, a, t, n, d, workspace); // a=a*t

		}
    	 }
    }
 	 redc(a,a,n,d, workspace); //a=a%n, montgomery back to ordinary

 	for(i=0;i<16;i++)
		m2[i]=a[i]; //store Cq^dq % q

		async_work_group_copy(t, Cpg+16*id, 16, 0);
		async_work_group_copy(a, r2pg+16*id, 16, 0);
		async_work_group_copy(n, pg+16*id, 16, 0);
		async_work_group_copy(expo, dmp1g+16*id, 16, 0);


	d = inv2adic(n[0]);

  	mulredc(t, t, a, n, d, workspace); // t = tr %n=, montgomery multiplicaiton, t ordinary to montgomery form


 	redc(a, a, n, d, workspace); // a = r%n

//left-to-right binary exponentiation

  for(i=16; i >0 ; --i)
  {
   	 ex = expo[i-1];

    	for(j=0; j<32; j++)
   	 {

        	mulredc(a, a, a, n, d, workspace);// a=a*a*d%n

		if(ex&(0x80000000>>j))
      		{mulredc(a, a, t, n, d, workspace); // a=a*t

		}
    	 }

    }

  redc(a,a,n,d, workspace); //a=a%n, montgomery back to ordinary

__attribute__((xcl_pipeline_loop))
 for(i=0;i<16;i++)
		m1[i]=a[i]; //store Cp^dp % p

	u32 borrow=sub_n(m1,m1,m2);
	if(borrow)
	{
		add_16(m1,m1,n);

	}

	mulredc(m1,m1,r2p,n,d,workspace);
	mulredc(dtemp,iqmp,r2p,n,d,workspace);
	mulredc(m1,m1,dtemp,n,d,workspace);
	redc(m1,m1,n,d,workspace); //h=(m1-m2)iqmp %p
	mul_n(product,m1,q); //h*q
	add_32(product,product,m2);	//m=m2+hq

        async_work_group_copy(z+32*id, product, 32, 0);


}
