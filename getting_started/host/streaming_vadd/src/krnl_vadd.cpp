#include "ap_axi_sdata.h"
#include "hls_stream.h"
#include <ap_int.h>
#include <stdio.h>

#define D 32
typedef qdma_axis<D,0,0,0> pkt;
typedef ap_uint<1> final_data_type;

extern "C" {
void krnl_vadd (hls::stream<pkt> &a, hls::stream<pkt> &b, hls::stream<pkt> &output){
    #pragma HLS interface axis port=a 
    #pragma HLS interface axis port=b
    #pragma HLS interface axis port=output 
    #pragma HLS interface s_axilite port=return bundle=control

    final_data_type final_data = 0;
    VADD: do {
        #pragma HLS PIPELINE II=1
        pkt a_val = a.read();
        pkt b_val = b.read();
        pkt out_val;
        final_data = a_val.get_last();
        ap_int<D> result = a_val.get_data() + b_val.get_data();
        out_val.set_data(result);
        out_val.set_keep(-1);
        out_val.set_last(final_data);
        output << out_val;
    } while (final_data!=1);
  }
}
