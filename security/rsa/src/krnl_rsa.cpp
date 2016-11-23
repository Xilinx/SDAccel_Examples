/*******************************************************************************
Vendor: Xilinx
Associated Filename: rsa.cl, implemented CRT and sliding window for 2048 bit decryption
Purpose: SDAccel rsa example
Revision History: June 1st, 2016

*******************************************************************************
Copyright (C) 2016 XILINX, Inc.

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
#define AP_INT_MAX_W 8192 //default maximum bit is 1024 bits
#include "ap_int.h"

//#include <iostream.h>
#include <string.h>
//typedef ap_uint<17> u17;
typedef ap_uint<1024> u1024;
typedef ap_uint<2048> u2048;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef unsigned long u64;

#define N 32


//fix exponent
const u32 pg[32]={0xAAB1A5D1,0xC3CC078D,0x775A18AC,0x5B700DC0,0x72213C96,0xEA9D991B,0xD6B174DF,0x5616A1F8,0x846DBE9D,0xB1A2043D,0x80EBCCED,0xC66C5272,0xE1C2E6CB,0x931BC23C,0x93F06F29,0xE89F261B,0x541422FD,0xEF3AF0EF,0x51672B16,0x2958025C,0x37DD7161,0xE85A90E4,0xEEDC1AE7,0x1AA3FBBA,0x862300C1,0x6A333974,0xD7A55AE3,0x7A484325,0xA86AD5F9,0x73D82B89,0x26BA1D77,0xFE6778BA};

const u32 qg[32]= {0xC5E71F1B,0x142640F2,0x4E06922A,0x8A6C7E60,0xCD3FB5E2,0xD7A6C3D8,0x55BB6578,0xA7346263,0x5134F491,0x0F38C768,0x5A2A7628,0xDC05669C,0x03606860,0xF48D3F52,0x1A11F98E,0x235AF12E,0x02D20C5E,0x91372F75,0xD80FB213,0x677851E8,0xA4AB5B4A,0x0C7B81F3,0xA161F579,0x5E9F5DC7,0xA4AFA89F,0xF3016F9B,0x3ACBB55F,0xFF26AC8E,0xDE9D1EA2,0x41CC053E,0x47CCB78A,0xD2B4F935};

const u32 dmp1g[32] ={0x1AD023C1,0x5AFE374D,0x1E878F43,0xF99E3156,0x23F992E3,0x3AA7C85B,0x8B4927DD,0x2C67C99E,0x0AB7210F,0x54821C36,0x34F4E5FE,0xAE63895D,0x99BA836A,0x37255A10,0xCFF5E791,0x5E1DAB4F,0x7E1939F1,0x029DD6D5,0xFDE6FAB1,0x07EE9283,0x309A1327,0x32426AE2,0x0584B25E,0x3E0698C5,0x32DDF152,0x497C2138,0x40C016C7,0xBD5236AC,0xD75CE33B,0x33BA6BC9,0x5899F460,0x8E869190};

const u32 dmq1g[32] ={0xBB8863C1,0x17882199,0x6D978DA9,0xD98C82B7,0x621AABCE,0x7803DB73,0x434D0772,0x79DCE582,0xB5EBBC76,0xB70B2731,0x943F4899,0x1BB07574,0xFA04E541,0x7D2F38A5,0xE42710F0,0x1ACEA9E6,0x2D40DA85,0xD159E539,0xDE830B3C,0x3854BB2E,0xA6CA282D,0x8E1314D8,0xF1620F63,0x73FE4BE2,0x34040C5D,0x221FCEA1,0x33A03A7F,0x853A1103,0x2EDB4A6A,0xD6AB64CF,0x94484C71,0x77A70D5D};

const u32 iqmpg[32] ={0xA3C23D3C,0xD88A997C,0x5F8B1116,0xB54949A7,0xACF4FF1E,0xA88A0AB9,0xFB080329,0x9AC5221C,0xD8EC22EA,0x982DC0BA,0x55656F3F,0xE2272F79,0x8150CD15,0xB1CBFF98,0x02D8F7D6,0x83940003,0x45D0A6ED,0xD0109969,0x9871BCF0,0x84245961,0x8ECF81A5,0x11E6CD00,0x6141401C,0xEDB9AFB7,0xE6E0D9DE,0xEFA4BDC0,0xBB745ADD,0x0831D642,0x8680879F,0xE65D303A,0x7ED95C88,0x905EE58B};

const u32 r2pg[32] = {0x9FA9D57D,0x15C66B87,0xD8F7F74,0x07E3910E,0x3FC371A7,0x010BD6D8,0x4F1AAE2D,0x86C3A827,0x872468F5,0xC4FEF5AF,0xD3107421,0xB97D1118,0xB2970709,0x88FD9CD0,0x0DE070BC,0x5AFF6C9F,0xEC666419,0xCF7755E3,0xBA304D75,0x5E953339,0xED8C9636,0x90A001CF,0x2C8B32A1,0x4D118E57,0xDD4E7EF3,0x2F07D30D,0xD808EB7E,0xB7DCB631,0x09346607D,0x8CDCFF48,0x18C44087,0xCF3E5FE7};

const u32 r2qg [32] = {0x076EF3C9,0x58AFD386,0x8E0421A9,0xE628BA4D,0xD8D4F79B,0x05DD05F5,0xEC37930A,0xDC0FFD69,0x4F90DC59,0x992A125C,0x329F56F5,0xB48464B8,0xCE923506,0xEE1EDB9B,0xB6EEE6FE,0xB2626DBF,0xC2858D23,0x74CAD2AC,0xDDEF8E75,0x6E30A3FC,0xA79F8C46,0x3172807A,0xB7FCF483,0xEC88C667,0xCEC30EDE,0xFC359A6F,0xE6EAA3F4,0x1B87CAD0,0xEF0FE57A,0xB577F1FF,0x1AFF46CE,0x1BDD9C52};


//the 26x17 unsigned mult C++ example design, which HLS can map it into 1 DSP48E2 in KU115
/*void mult_17x26(ap_uint<17> A,  ap_uint<26> B,  ap_uint<48> &mult_out) {
#pragma HLS PIPELINE
	   mult_out = (ap_uint<48>)(A * B);

    }

*/
// Compute the 2adic inverse of x
//inverse %2^32
int inv2adic(u32 x)

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
int sub_n(u32 *z,  u32 *x,  u32 *y)
{
 	u32 cy=0, temp;
  	int i;
//#pragma HLS PIPELINE
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

int add_32( u32 *z,  u32 *x, u32 *y)
{
  u32 carry = 0;
  u32 new_carry = 0;
  u32 temp;
  unsigned i;
//#pragma HLS PIPELINE
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

int add_64(  u32 *z, u32 *x,   u32 *y)
{
  u32 carry = 0;
  u32 new_carry = 0;
  u32 temp;
  unsigned i;
//#pragma HLS PIPELINE
  for (i=0; i <64; i++)
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
int cmp_ge_n(  u32 *x, u32 *y)

{
	int i;

  	if(x[N]){
	return 1;
 	 }

//#pragma HLS PIPELINE
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
int addmul_1(  u32 *z,   u32 *x,u32 y)
{
  int i;
  u32 cy;
  u64 prod;

  cy = 0;
//#pragma HLS PIPELINE
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
//compare with z=x*y
//mimic openssl bn_mul_normal
 void mul_n(  u32 *z,  u32 *x,   u32 *y)

{
	  u32 *rr;
	 int i=N;

	rr=&(z[N]);
	rr[0]=addmul_1(z,x,y[0]);
//#pragma HLS PIPELINE
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
void mulredc(  u32 *z,  u32 *x,   u32 *y,  u32 *n, const u32 d,   u32 *t)
{
  int i,j;
  u32 m, cy;
  u64 aux;

  for(i=0; i < N+2; i++)
    t[i] = 0;

//#pragma HLS PIPELINE
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
void redc( u32 *z,  u32 *x,  u32 *n, const u32 d,  u32 *t)

{
	int i,j;
  	u32 m;

  for(i=0; i < N; i++)
    t[i] = x[i];

  t[N] = 0;
//#pragma HLS PIPELINE
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

inline void compute(u32 *Cqg, const u32 *r2qg,const u32 *qg,const u32 *dmq1g, u32 *m){
        u32  d;
  	u32 workspace[34]  ;
	u32 dtemp[32];

    u32 expo[32];
  	u32 n[32] ;
  	u32 t[32];
  	u32 a[32];

	int i,j;

     for(i=0;i<32;i++)
{
	t[i]=Cqg[i];
	a[i]=r2qg[i];
  n[i]=qg[i];
      expo[i]=dmq1g[i];



}
	d = inv2adic(n[0]); //C0797221

  	mulredc(t, t, a, n, d, workspace); // t = tr %n=, montgomery multiplicaiton, t ordinary to montgomery form


 	redc(a, a, n, d, workspace); // a = r%n

  for(i=32; i >0 ; --i)
  {


    	for(j=0; j<32; j++)
   	 {
		u32 ex = expo[i-1];
        	mulredc(a, a, a, n, d, workspace);// a=a*a*d%n
		if(ex&(0x80000000>>j))
      		{
				mulredc(a, a, t, n, d, workspace); // a=a*t

		}
    	 }
    }
 	 redc(a,a,n,d, workspace); //a=a%n, montgomery back to ordinary

 	for(i=0;i<32;i++)
		m[i]=a[i]; //store Cq^dq % q

 }


//Cp, Cq is ciphertext, z stores decrypted message, p, q, dmp,dmq,iqmp, r2q,r2q is the constant used in montgomery multilication

extern "C" {
void rsa(u32 *z, u32 *Cpg, u32 *Cqg)
	{
#pragma HLS INTERFACE m_axi port=z offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=Cpg offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=Cqg offset=slave bundle=gmem

#pragma HLS INTERFACE s_axilite port=z bundle=control
#pragma HLS INTERFACE s_axilite port=Cpg bundle=control
#pragma HLS INTERFACE s_axilite port=Cqg bundle=control


#pragma HLS INTERFACE s_axilite port=return bundle=control
	u32  d1;
	u32 dtemp[32]  ;
  	u32 workspace1[34]  ;
  	u32 q[32],p[32];
  	u32 product[64];
  	u32 r2p[32];
  	u32 m1[32];
	u32 mtemp[32];
	u32 temp[32];
  	u32 m2[64] ;
  	u32 iqmp[32];
	int i,j;




//#pragma HLS PIPELINE
	for(i=0;i<64;i++)
	{
		product[i]=0;
		m2[i]=0;
	}


 for(i=0;i<64;i++)
 {
   r2p[i]=r2pg[i];
   q[i]=qg[i];
   p[i]=pg[i];
   iqmp[i]=iqmpg[i];
 }


     compute(Cqg,r2qg,qg,dmq1g,mtemp);

     compute(Cpg,r2pg,pg,dmp1g,m1);

     d1 = inv2adic(pg[0]);

	u32 borrow=sub_n(m1,m1,mtemp);
	if(borrow)
	{
		add_32(m1,m1,temp);

	}

	mulredc(m1,m1,r2p,p,d1,workspace1);
	mulredc(dtemp,iqmp,r2p,p,d1,workspace1);
	mulredc(m1,m1,dtemp,p,d1,workspace1);

	redc(m1,m1,p,d1,workspace1); //h=(m1-m2)iqmp %p
	mul_n(product,m1,q); //h*q

     for(i=0;i<32;i++)
      {
           m2[i]= mtemp[i];
      }

	add_64(product,product,m2);	//m=m2+hq
  	for(i=0;i<64;i++)
      {
           z[i]=product[i];
      }


}

}
