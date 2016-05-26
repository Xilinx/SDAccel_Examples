# BEGIN Vivado Commands 
set vivado_ver [version -short]
set fpo_ver 7.1
if {[regexp -nocase {2015\.1.*} $vivado_ver match]} {
    set fpo_ver 7.0
}
create_ip -name floating_point -version $fpo_ver -vendor xilinx.com -library ip -module_name krnl_sobel_ap_faddfsub_6_full_dsp_32
# BEGIN Vivado Commands 
# BEGIN Vivado Parameters
set_property -dict [list CONFIG.a_precision_type Single \
                          CONFIG.a_tuser_width 1 \
                          CONFIG.add_sub_value Both \
                          CONFIG.b_tuser_width 1 \
                          CONFIG.c_a_exponent_width 8 \
                          CONFIG.c_a_fraction_width 24 \
                          CONFIG.c_compare_operation Programmable \
                          CONFIG.c_has_divide_by_zero false \
                          CONFIG.c_has_invalid_op false \
                          CONFIG.c_has_overflow false \
                          CONFIG.c_has_underflow false \
                          CONFIG.c_latency 6 \
                          CONFIG.c_mult_usage Full_Usage \
                          CONFIG.c_optimization Speed_Optimized \
                          CONFIG.c_rate 1 \
                          CONFIG.c_result_exponent_width 8 \
                          CONFIG.c_result_fraction_width 24 \
                          CONFIG.component_name krnl_sobel_ap_faddfsub_6_full_dsp_32 \
                          CONFIG.flow_control NonBlocking \
                          CONFIG.has_a_tlast false \
                          CONFIG.has_a_tuser false \
                          CONFIG.has_aclken true \
                          CONFIG.has_aresetn false \
                          CONFIG.has_b_tlast false \
                          CONFIG.has_b_tuser false \
                          CONFIG.has_operation_tlast false \
                          CONFIG.has_operation_tuser false \
                          CONFIG.has_result_tready false \
                          CONFIG.maximum_latency false \
                          CONFIG.operation_tuser_width 1 \
                          CONFIG.operation_type Add_Subtract \
                          CONFIG.result_precision_type Single \
                          CONFIG.result_tlast_behv Null] -objects [get_ips krnl_sobel_ap_faddfsub_6_full_dsp_32] -quiet
# END Vivado Parameters
set_property generate_synth_checkpoint false [get_files krnl_sobel_ap_faddfsub_6_full_dsp_32.xci]
generate_target {synthesis simulation} [get_files krnl_sobel_ap_faddfsub_6_full_dsp_32.xci]
