#define VC690_ADMPCIE7V3_1DDR_GEN2 1
#define M505_LX325T                2

#define XCL_DEVICE M505_LX325T

#define BLOCKS 16384
//#define BLOCKS 8
//#define PIPELINE_DEPTH 83
#define PIPELINE_DEPTH 165

//#define DEBUG

#ifndef PIPELINE_DEPTH
#    if XCL_DEVICE == VC690_ADMPCIE7V3_1DDR_GEN2
#        define PIPELINE_DEPTH 167
#    elif XCL_DEVICE == M505_LX325T
#        define PIPELINE_DEPTH 167
#    else
         // Better safe than not meeting timing
#        define PIPELINE_DEPTH 512
#    endif
#endif

#ifndef BLOCKS
#    if XCL_DEVICE == VC690_ADMPCIE7V3_1DDR_GEN2
#        define BLOCKS 8192
#    elif XCL_DEVICE == M505_LX325T
#        define BLOCKS 8192 
#    else
         // Better safe than running too many kernel invocations
#        define BLOCKS 256
#    endif
#endif

#define CHANNELS (PIPELINE_DEPTH)

/* Using an int16 for the state */
#define STATEA s0
#define STATEB s1
#define STATEC s2
#define STATED s3
#define STATEE s4


typedef unsigned int u_int32_t;
typedef uint16 buf_t;
typedef uint16 state_t;

#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

void uint16_to_array(uint16 in, u_int32_t out[16]) {
    out[0]  = in.s0;
    out[1]  = in.s1;
    out[2]  = in.s2;
    out[3]  = in.s3;
    out[4]  = in.s4;
    out[5]  = in.s5;
    out[6]  = in.s6;
    out[7]  = in.s7;
    out[8]  = in.s8;
    out[9]  = in.s9;
    out[10] = in.sA;
    out[11] = in.sB;
    out[12] = in.sC;
    out[13] = in.sD;
    out[14] = in.sE;
    out[15] = in.sF;
}

void array_to_uint16(u_int32_t in[16], uint16 out) {
    out.s0 = in[0];
    out.s1 = in[1];
    out.s2 = in[2];
    out.s3 = in[3];
    out.s4 = in[4];
    out.s5 = in[5];
    out.s6 = in[6];
    out.s7 = in[7];
    out.s8 = in[8];
    out.s9 = in[9];
    out.sA = in[10];
    out.sB = in[11];
    out.sC = in[12];
    out.sD = in[13];
    out.sE = in[14];
    out.sF = in[15];
}

void uint_to_char_array(uint in, char out[4]) {
  out[0] = (in & 0x000000FF) >> 0;
  out[1] = (in & 0x0000FF00) >> 8;
  out[2] = (in & 0x00FF0000) >> 16;
  out[3] = (in & 0xFF000000) >> 24;
}

void uint16_to_char_array(uint16 in, char out[64]) {
    uint_to_char_array(in.s0, &out[0]);
    uint_to_char_array(in.s1, &out[4]);
    uint_to_char_array(in.s2, &out[8]);
    uint_to_char_array(in.s3, &out[12]);
    uint_to_char_array(in.s4, &out[16]);
    uint_to_char_array(in.s5, &out[20]);
    uint_to_char_array(in.s6, &out[24]);
    uint_to_char_array(in.s7, &out[28]);
    uint_to_char_array(in.s8, &out[32]);
    uint_to_char_array(in.s9, &out[36]);
    uint_to_char_array(in.sA, &out[40]);
    uint_to_char_array(in.sB, &out[44]);
    uint_to_char_array(in.sC, &out[48]);
    uint_to_char_array(in.sD, &out[52]);
    uint_to_char_array(in.sE, &out[56]);
    uint_to_char_array(in.sF, &out[60]);
}

void int_to_char4(int in, global char *out) {
  out[0] = (in & 0x000000FF) >> 0;
  out[1] = (in & 0x0000FF00) >> 8;
  out[2] = (in & 0x00FF0000) >> 16;
  out[3] = (in & 0xFF000000) >> 24;
}


void dev_sha1_transform(u_int32_t state[5], u_int32_t buffer[16]) {
  u_int32_t a, b, c, d, e;

  a = state[0];
  b = state[1];
  c = state[2];
  d = state[3];
  e = state[4];

  for (int n = 0; n < 80; n++) {
    u_int32_t k, f, w;

    if(n < 16) {
       /* Little to Big Endian Conversion */
       w = (rol(buffer[n],24) & 0xFF00FF00) |
           (rol(buffer[n], 8) & 0x00FF00FF);
    } else {
       w = rol(buffer[(n + 13) & 15] ^
               buffer[(n + 8)  & 15] ^
               buffer[(n + 2)  & 15] ^
               buffer[(n + 0)  & 15], 1);
    }

    buffer[n & 15] = w;

    u_int32_t sub = c^d;
    u_int32_t f1  = ((b&(sub))^d);
    u_int32_t f2  = (b^sub);
    u_int32_t f3  = (((b|c)&d)|(b&c));

    if (n < 20) {
      k = 0x5A827999;
      f = f1;
    } else if (n < 40) {
      k = 0x6ED9EBA1;
      f = f2;
    } else if (n < 60) {
      k = 0x8F1BBCDC;
      f = f3;
    } else {
      k = 0xCA62C1D6;
      f = f2;
    }

    u_int32_t temp = k + f + e + w + rol(a,5);
    e = d;
    d = c;
    c = rol(b,30);
    b = a;
    a = temp;
  }

  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
  state[4] += e;
}

#ifdef __xilinx__
__attribute__ ((reqd_work_group_size(1, 1, 1)))
#endif
kernel void dev_sha1_update(global buf_t *gbuf, global state_t *gstate) {
  local state_t lstate[PIPELINE_DEPTH];

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH; i++) {
    lstate[i] = gstate[i];
#ifdef DEBUG
    u_int32_t state[5];
    state[0] = gstate[i].STATEA;
    state[1] = gstate[i].STATEB;
    state[2] = gstate[i].STATEC;
    state[3] = gstate[i].STATED;
    state[4] = gstate[i].STATEE;
    printf("chan = %3d, state = %8x %8x %8x %8x %8x\n",
            i, state[0], state[1], state[2], state[3], state[4]);
#endif
  }

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH*BLOCKS; i++) {
    u_int32_t state[5] __attribute__((xcl_array_partition(complete, 1)));

    state[0] = lstate[i%PIPELINE_DEPTH].STATEA;
    state[1] = lstate[i%PIPELINE_DEPTH].STATEB;
    state[2] = lstate[i%PIPELINE_DEPTH].STATEC;
    state[3] = lstate[i%PIPELINE_DEPTH].STATED;
    state[4] = lstate[i%PIPELINE_DEPTH].STATEE;

    uint16 lbuf __attribute__((xcl_array_partition(complete, 1)));
    lbuf = gbuf[i];

    u_int32_t buf[16] __attribute__((xcl_array_partition(complete, 1)));

    uint16_to_array(lbuf, buf);

#ifdef DEBUG
    if(i%PIPELINE_DEPTH == 0) {
      printf("sha1_transform: init chan = %d, state = %x %x %x %x %x\n",
             i%PIPELINE_DEPTH, state[0], state[1], state[2], state[3], state[4]);
      printf("  buf = ");
      char cbuf[64];
      uint16_to_char_array(lbuf, cbuf);
      for (int j = 0; j < 64; j++) {
        printf("%02x", cbuf[j] & 0xFF);
      }
      printf("\n");
    }
#endif

    dev_sha1_transform(state, buf);

 #ifdef DEBUG
    if(i%PIPELINE_DEPTH == 0) {
      printf("sha1_transform: exit chan = %d, state = %x %x %x %x %x\n",
             i%PIPELINE_DEPTH, state[0], state[1], state[2], state[3], state[4]);
    }
#endif

    lstate[i%PIPELINE_DEPTH].STATEA = state[0];
    lstate[i%PIPELINE_DEPTH].STATEB = state[1];
    lstate[i%PIPELINE_DEPTH].STATEC = state[2];
    lstate[i%PIPELINE_DEPTH].STATED = state[3];
    lstate[i%PIPELINE_DEPTH].STATEE = state[4];
  }

#ifdef __xilinx__
  __attribute__((xcl_pipeline_loop))
#endif
  for(size_t i = 0; i < PIPELINE_DEPTH; i++) {
    gstate[i] = lstate[i];
  }

}

