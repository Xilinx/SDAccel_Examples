#include "ap_axi_sdata.h"
#include "hls_stream.h"
#include <ap_int.h>
#include <stdio.h>

typedef qdma_axis<32,0,0,0> pkt;
typedef ap_uint<1> final_data_type;

void read_inputs(hls::stream<pkt> &a, hls::stream<pkt> &b, hls::stream<int> &a_int, hls::stream<int> &b_int, hls::stream<final_data_type> &last_data)
{
    final_data_type final_data;
    READ_LOOP: do {
        #pragma HLS PIPELINE II=1
        pkt tempA = a.read();
        pkt tempB = b.read();
        a_int << tempA.get_data();
        b_int << tempB.get_data();
        final_data = tempA.get_last();
        last_data.write(final_data);
    } while(final_data!=1);        
}

void compute(hls::stream<int> &a_int, hls::stream<int> &b_int, hls::stream<int> &out_int, hls::stream<final_data_type> &last_data, hls::stream<final_data_type> &last_data_extend) {
    final_data_type final_data;

    COMPUTE_LOOP: do {
        #pragma HLS PIPELINE II=1
        int a_val = a_int.read();
        int b_val = b_int.read();
        out_int << a_val + b_val;
        final_data = last_data.read();
        last_data_extend.write(final_data);
    } while(final_data!=1); 
}

void write_output(hls::stream<int> &out_int, hls::stream<pkt> &output, hls::stream<final_data_type> &last_data_extend) {

    final_data_type final_data;

    WRITE_LOOP: do {
        #pragma HLS PIPELINE II=1
        pkt t;
        int t_data = out_int.read();
        t.set_data(t_data);
        t.set_keep(-1);   // keep flag -1, all bytes are valid        
        final_data = last_data_extend.read();
        t.set_last(final_data);
        output.write(t);
    } while(final_data!=1);
}

extern "C" {
void krnl_vadd (hls::stream<pkt> &a, hls::stream<pkt> &b, hls::stream<pkt> &output){

    #pragma HLS interface axis port=a    
    #pragma HLS interface axis port=b    
    #pragma HLS interface axis port=output    
    #pragma HLS interface s_axilite port=return bundle=control

    hls::stream<int> a_int;
    hls::stream<int> b_int;
    hls::stream<int> out_int;
    hls::stream<final_data_type> last_data;
    hls::stream<final_data_type> last_data_extend;    

    #pragma HLS STREAM variable=a_int depth=2
    #pragma HLS STREAM variable=b_int depth=2
    #pragma HLS STREAM variable=out_int depth=2
    #pragma HLS STREAM variable=last_data depth=2
    #pragma HLS STREAM variable=last_data_extend depth=2

    #pragma HLS DATAFLOW
    read_inputs(a, b, a_int, b_int, last_data);
    compute(a_int, b_int, out_int, last_data, last_data_extend);
    write_output(out_int, output, last_data_extend);
  }
}
