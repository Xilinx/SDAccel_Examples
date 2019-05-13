/**********
Copyright (c) 2018, Xilinx, Inc.
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
*/
#include "ap_int.h"
#include "ap_axi_sdata.h"
#include "hls_stream.h"

#define DWIDTH 32

typedef qdma_axis<DWIDTH, 0, 0, 0> pkt;

extern "C" {
void krnl_stream_vadd(hls::stream<pkt> &a, hls::stream<pkt> &b, hls::stream<pkt> &output)
{
    #pragma HLS interface axis port=a
    #pragma HLS interface axis port=b
    #pragma HLS interface axis port=output
    #pragma HLS interface s_axilite port=return bundle=control

    vadd: while (true) {
    #pragma HLS PIPELINE II=1
        pkt t1 = a.read();
        pkt t2 = b.read();
        pkt t_out;
        ap_uint<DWIDTH> tmp_out;
        t_out.set_last(0);
        t_out.set_data(t1.get_data() + t2.get_data());
        t_out.set_keep(-1);        
        if (t2.get_last()) { t_out.set_last(1); }
        output.write(t_out);
        if(t_out.get_last()) { break; }
    }
}
}
