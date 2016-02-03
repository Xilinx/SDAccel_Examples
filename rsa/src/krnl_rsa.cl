/*
 *  RSACoarse.cl, corresponding to rsa_decrypt_cpu2.c,with crt only
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef unsigned long u64;
//static u32 k; //k record # of multiplication needed

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

//z=x-y
u32 sub_n(u32 *z, u32 *x, u32 *y,int N)
{
 	u32 cy=0, temp;
  	int i;
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
  
u32 add_n(u32 *z, u32 *x, u32 *y,int N) 
{
  u32 carry = 0;
  u32 new_carry = 0;
  u32 temp;
  unsigned i;

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

//decide if x is greater than y
int cmp_ge_n(u32 *x, u32 *y,int N)

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

//z[]=z[]+x[]y
u32 addmul_1(u32 *z, u32 *x, u32 y, int N)
{
  int i;
  u32 cy;
  u64 prod;

  cy = 0;
//#pragma unroll
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
 void mul_n(u32 *z,u32 *x, u32 *y, int N)

{
	u32 *rr;
	 int i=N;
	
	rr=&(z[N]);
	rr[0]=addmul_1(z,x,y[0],N);
	for(;;)
	{	
  		if(--i<=0)return;
   	 		rr[1] = addmul_1(&(z[1]) , x, y[1],N); 
		if(--i<=0)return;
			rr[2] = addmul_1(&(z[2]), x, y[2],N);
		if(--i<=0)return;
			rr[3] = addmul_1(&(z[3]), x, y[3],N);
		if(--i<=0)return;
			rr[4] = addmul_1(&(z[4]), x, y[4],N);
		rr+=4;
		z+=4;
		y+=4;

	}
}

//z=x*y/R%n
void mulredc(u32 *z, u32 *x, u32 *y, u32 *n, const u32 d, u32 *t,int N)
{
	//k+=1;
  int i,j;
  u32 m, cy;
  u64 aux;
//#pragma unroll
  for(i=0; i < N+2; i++)
    t[i] = 0;

//#pragma unroll
  for(i=0; i < N; i++)
  {
    cy = addmul_1(t, x, y[i],N); // t += x*y[i]
	
    aux = (u64)t[N] + cy;
    t[N] = aux;
    t[N+1] = aux>>32;
	
    m = t[0]*d;
	
    cy = addmul_1(t, n, m,N);//t+=n*t[0]*d
    aux = (u64)t[N] + cy;
	
    t[N] = aux;
    t[N+1] = aux>>32;
	
    

    for(j=0; j <= N; j++) // shift,i.e./2^32
      t[j] = t[j+1];

    }

// Final fix --- executed about half the time

  if(cmp_ge_n(t, n,N)){
	
    	sub_n(t, t, n,N);  //t=t-n
	
	}

  for(i=0; i < N; i++)
    z[i] = t[i];
}

//z=xR(-1)%n montgomery reduction
void redc(u32 *z, u32 *x, u32 *n, const u32 d, u32 *t,int N)

{
	int i,j;
  	u32 m;

  for(i=0; i < N; i++)
    t[i] = x[i];

  t[N] = 0;

 for(i=0; i < N; i++)
  {
    m = t[0]*d;
    t[N] = addmul_1(t, n, m,N);
                       
    for(j=0; j < N; j++) // shift,/2^32
      t[j] = t[j+1];

    t[N] = 0;
  }

if(cmp_ge_n(t, n, N)){
	
	sub_n(t, t, n,N);
	
	} 

  for(i=0; i < N; i++)
    z[i] = t[i];

  }

//Cp, Cq is ciphertext, z stores decrypted message, p, q, dmp,dmq,iqmp, r2q,r2q is the constant used in montgomery multilication

__kernel void rsa(__global u32 *z,__global u32 *Cpg, __global u32 *Cqg, __global u32 *pg, __global u32 *qg, __global u32 *dmp1g,__global u32 *dmq1g,__global u32 *iqmpg,__global u32 *r2pg,__global u32 *r2qg)
	{
	
	u32  d,ex,expo[16],product[32],m1[16],m2[32],workspace[18],dtemp[16],a[16],q[16],r2p[16], n[16],t[16],iqmp[16];
	int i,j;
	for(i=0;i<32;i++)
	{
		product[i]=0;
		m2[i]=0;
	}
	int id = get_global_id(0);

	for(i=0; i < 16; i++)
	{
		q[i] = qg[i+16*id];	
		iqmp[i]=iqmpg[i+16*id];
		r2p[i]=r2pg[i+16*id];
	}

	for(i=0; i < 16; i++)
	{
    		t[i] =Cqg[i+16*id];//t is ciphertext  
		a[i]=r2qg[i+16*id];//R^2 for montgomery multiplicaiton
		n[i]=qg[i+16*id];//n is moduli
		expo[i]=dmq1g[i+16*id];//expo is exponent
	}

	d = inv2adic(n[0]); //C0797221

  	mulredc(t, t, a, n, d, workspace, 16); // t = tr %n=, montgomery multiplicaiton, t ordinary to montgomery form
	

 	redc(a, a, n, d, workspace,16); // a = r%n
		

  for(i=16; i >0 ; --i)
  {
   	 ex = expo[i-1]; 
	
    	for(j=0; j<32; j++)
   	 {
      		
        	mulredc(a, a, a, n, d, workspace, 16);// a=a*a*d%n
		
		if(ex&(0x80000000>>j))
      		{mulredc(a, a, t, n, d, workspace, 16); // a=a*t
      		
		}
    	 }              
    }
 	 redc(a,a,n,d, workspace,16); //a=a%n, montgomery back to ordinary

 	for(i=0;i<16;i++)
		m2[i]=a[i]; //store Cq^dq % q

	for(i=0; i < 16; i++)
	{
    		t[i] =Cpg[i+16*id];//t is ciphertext  
		a[i]=r2pg[i+16*id];//R^2 for montgomery multiplicaiton
		n[i]=pg[i+16*id];//n is moduli
		expo[i]=dmp1g[i+16*id];//expo is exponent
	}

	d = inv2adic(n[0]); //

  	mulredc(t, t, a, n, d, workspace, 16); // t = tr %n=, montgomery multiplicaiton, t ordinary to montgomery form
	

 	redc(a, a, n, d, workspace,16); // a = r%n
	
//left-to-right binary exponentiation

  for(i=16; i >0 ; --i)
  {
   	 ex = expo[i-1]; 
	
    	for(j=0; j<32; j++)
   	 {
      		
        	mulredc(a, a, a, n, d, workspace, 16);// a=a*a*d%n
		
		if(ex&(0x80000000>>j))
      		{mulredc(a, a, t, n, d, workspace, 16); // a=a*t
      		
		}
    	 }              
	
    }

  redc(a,a,n,d, workspace,16); //a=a%n, montgomery back to ordinary

 for(i=0;i<16;i++)
		m1[i]=a[i]; //store Cp^dp % p

	u32 borrow=sub_n(m1,m1,m2,16);
	if(borrow)
	{
		add_n(m1,m1,n,16);

	}

	mulredc(m1,m1,r2p,n,d,workspace,16);
	mulredc(dtemp,iqmp,r2p,n,d,workspace,16);
	mulredc(m1,m1,dtemp,n,d,workspace,16);
	redc(m1,m1,n,d,workspace,16); //h=(m1-m2)iqmp %p
	mul_n(product,m1,q,16); //h*q
	add_n(product,product,m2,32);	//m=m2+hq

 	for(i=0; i < 32; i++)
    		z[i+32*id] =product[i];
	
}
 
