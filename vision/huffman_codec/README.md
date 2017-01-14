Huffman Encoding/Decoding
======================

This README file contains the following sections:

1. OVERVIEW
2. HOW TO DOWLOAD THE REPOSITORY
3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
4. DESIGN FILE HIERARCHY
5. COMPILATION AND EXECUTION ON X86 SERVERS
6. COMPILATION AND EXECUTION ON IBM POWER SERVERS
7. SUPPORT
8. LICENSE AND CONTRIBUTING TO THE REPOSITORY
9. ACKNOWLEDGEMENTS
10. REVISION HISTORY


## 1. OVERVIEW
This is an implementation of a huffman encoding/decoding algorithm targeting execution on an SDAccel supported FPGA acceleration card.

## 2. HOW TO DOWNLOAD THE REPOSITORY
To get a local copy of the SDAccel example repository, clone this repository to the local system with the following command:
```
git clone https://github.com/Xilinx/SDAccel_Examples examples
```
where examples is the name of the directory where the repository will be stored on the local system.This command needs to be executed only once to retrieve the latest version of all SDAccel examples. The only required software is a local installation of git.

*NOTE: If the destination of the repository is the user home directory in the Nimbix SDAccel developer instance, the command will need to be executed for every session. Contents of the user home directory in the Nimbix SDAccel developer instance are not preserved between user sessions. Only files placed in the /data directory are kept between SDAccel development sessions.*
## 3. SOFTWARE AND SYSTEM REQUIREMENTS
Board | Device Name | Software Version | NIMBIX Machine Type
------|-------------|------------------|--------------------
Alpha Data ADM-PCIE-7V3|xilinx:adm-pcie-7v3:1ddr:3.0|SDAccel 2016.3|nx2


Board targeted by default = ***Alpha Data ADM-PCIE-KU3***

*NOTE:* The board/device used for compilation can be changed by adding the DEVICES variable to the make command as shown below
```
make DEVICES=<device name>
```
where the *DEVICES* variable accepts either 1 device from the table above or a comma separated list of device names.
## 4. DESIGN FILE HIERARCHY
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
.
|-- Makefile
|-- README.md
|-- _xocc_krnl_huffman_singleptr_krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1.dir
|   `-- impl
|       |-- build
|       |   |-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1_xclbincat.log
|       |   `-- system
|       |       `-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1
|       |           `-- bitstream
|       |               |-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin
|       |               |-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1.xml
|       |               |-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1_ipi
|       |               |   |-- hd_visual
|       |               |   |   |-- pblock_u_ocl_region_AllTiles.tcl
|       |               |   |   |-- pblock_u_ocl_region_FrameTiles.tcl
|       |               |   |   `-- pblock_u_ocl_region_RangedSites.tcl
|       |               |   |-- ipiimpl
|       |               |   |   |-- ipiimpl.cache
|       |               |   |   |   `-- wt
|       |               |   |   |       `-- project.wpc
|       |               |   |   |-- ipiimpl.hw
|       |               |   |   |   `-- ipiimpl.lpr
|       |               |   |   |-- ipiimpl.ip_user_files
|       |               |   |   |-- ipiimpl.runs
|       |               |   |   |   `-- impl_1
|       |               |   |   |       |-- ISEWrap.js
|       |               |   |   |       |-- ISEWrap.sh
|       |               |   |   |       |-- debug_nets.ltx
|       |               |   |   |       |-- gen_run.xml
|       |               |   |   |       |-- hd_visual
|       |               |   |   |       |   |-- blockedBelsOutputs.tcl
|       |               |   |   |       |   |-- blockedBelsRouteThrus.tcl
|       |               |   |   |       |   |-- blockedPins.tcl
|       |               |   |   |       |   |-- blockedSitesInputs.tcl
|       |               |   |   |       |   |-- pblock_u_ocl_region_AllTiles.tcl
|       |               |   |   |       |   |-- pblock_u_ocl_region_FrameTiles.tcl
|       |               |   |   |       |   `-- pblock_u_ocl_region_RangedSites.tcl
|       |               |   |   |       |-- htr.txt
|       |               |   |   |       |-- init_design.pb
|       |               |   |   |       |-- opt_design.pb
|       |               |   |   |       |-- place_design.pb
|       |               |   |   |       |-- project.wdf
|       |               |   |   |       |-- route_design.pb
|       |               |   |   |       |-- rundef.js
|       |               |   |   |       |-- runme.bat
|       |               |   |   |       |-- runme.log
|       |               |   |   |       |-- runme.sh
|       |               |   |   |       |-- sdaccel.jou
|       |               |   |   |       |-- vivado.pb
|       |               |   |   |       |-- xcl_design_wrapper.dcp
|       |               |   |   |       |-- xcl_design_wrapper.hwdef
|       |               |   |   |       |-- xcl_design_wrapper.tcl
|       |               |   |   |       |-- xcl_design_wrapper.vdi
|       |               |   |   |       |-- xcl_design_wrapper_clock_utilization_routed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_control_sets_placed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_drc_opted.rpt
|       |               |   |   |       |-- xcl_design_wrapper_drc_routed.pb
|       |               |   |   |       |-- xcl_design_wrapper_drc_routed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_io_placed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_power_routed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_power_routed.rpx
|       |               |   |   |       |-- xcl_design_wrapper_power_summary_routed.pb
|       |               |   |   |       |-- xcl_design_wrapper_route_status.pb
|       |               |   |   |       |-- xcl_design_wrapper_route_status.rpt
|       |               |   |   |       |-- xcl_design_wrapper_routed.dcp
|       |               |   |   |       |-- xcl_design_wrapper_timing_summary_routed.rpt
|       |               |   |   |       |-- xcl_design_wrapper_timing_summary_routed.rpx
|       |               |   |   |       |-- xcl_design_wrapper_utilization_placed.pb
|       |               |   |   |       `-- xcl_design_wrapper_utilization_placed.rpt
|       |               |   |   |-- ipiimpl.xpr
|       |               |   |   |-- usage_statistics_webtalk.html
|       |               |   |   `-- usage_statistics_webtalk.xml
|       |               |   |-- ipiprj
|       |               |   |   |-- ipiprj.cache
|       |               |   |   |   |-- ip
|       |               |   |   |   |   |-- 03f0beb07e076295
|       |               |   |   |   |   |   |-- 03f0beb07e076295.xci
|       |               |   |   |   |   |   |-- opencldesign_auto_rs_w_1.dcp
|       |               |   |   |   |   |   |-- opencldesign_auto_rs_w_1_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_auto_rs_w_1_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_auto_rs_w_1_stub.v
|       |               |   |   |   |   |   `-- opencldesign_auto_rs_w_1_stub.vhdl
|       |               |   |   |   |   |-- 03f0beb07e076295.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 0a8829c0c6aadc2d
|       |               |   |   |   |   |   |-- 0a8829c0c6aadc2d.xci
|       |               |   |   |   |   |   |-- opencldesign_s00_regslice_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_s00_regslice_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_s00_regslice_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_s00_regslice_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_s00_regslice_0_stub.vhdl
|       |               |   |   |   |   |-- 0a8829c0c6aadc2d.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 0f432551a1684654
|       |               |   |   |   |   |   |-- 0f432551a1684654.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_512_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_512_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_512_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_512_0_stub.vhdl
|       |               |   |   |   |   |-- 0f432551a1684654.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 1c763c00501c6150
|       |               |   |   |   |   |   |-- 1c763c00501c6150.xci
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_1_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_1_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_1_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_1_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_master_bridge_1_0_stub.vhdl
|       |               |   |   |   |   |-- 1c763c00501c6150.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 22a511385e9e1e9b
|       |               |   |   |   |   |   |-- 22a511385e9e1e9b.xci
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_auto_cc_0_stub.vhdl
|       |               |   |   |   |   |-- 22a511385e9e1e9b.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 42e8716777b35574
|       |               |   |   |   |   |   |-- 42e8716777b35574.xci
|       |               |   |   |   |   |   |-- opencldesign_xbar_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xbar_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xbar_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xbar_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xbar_0_stub.vhdl
|       |               |   |   |   |   |-- 42e8716777b35574.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 46781133e2066e2e
|       |               |   |   |   |   |   |-- 46781133e2066e2e.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_2_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_2_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_2_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_2_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_2_0_stub.vhdl
|       |               |   |   |   |   |-- 46781133e2066e2e.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 4a1b0ece5ace1d65
|       |               |   |   |   |   |   |-- 4a1b0ece5ace1d65.xci
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_0_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_0_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_0_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_master_bridge_0_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_master_bridge_0_0_stub.vhdl
|       |               |   |   |   |   |-- 4a1b0ece5ace1d65.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 4fda614070c4d35e
|       |               |   |   |   |   |   |-- 4fda614070c4d35e.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_64_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_64_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_64_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_64_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_64_0_stub.vhdl
|       |               |   |   |   |   |-- 4fda614070c4d35e.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 6bcd06da69b9caa9
|       |               |   |   |   |   |   |-- 6bcd06da69b9caa9.xci
|       |               |   |   |   |   |   |-- opencldesign_slave_bridge_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_slave_bridge_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_slave_bridge_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_slave_bridge_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_slave_bridge_0_stub.vhdl
|       |               |   |   |   |   |-- 6bcd06da69b9caa9.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 6fcc674fe27a135d
|       |               |   |   |   |   |   |-- 6fcc674fe27a135d.xci
|       |               |   |   |   |   |   |-- opencldesign_interconnect_sys_reset_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_interconnect_sys_reset_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_interconnect_sys_reset_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_interconnect_sys_reset_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_interconnect_sys_reset_0_stub.vhdl
|       |               |   |   |   |   |-- 6fcc674fe27a135d.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 724175b62653da18
|       |               |   |   |   |   |   |-- 724175b62653da18.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_8_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_8_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_8_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_8_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_8_0_stub.vhdl
|       |               |   |   |   |   |-- 724175b62653da18.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 753a051537aabee5
|       |               |   |   |   |   |   |-- 753a051537aabee5.xci
|       |               |   |   |   |   |   |-- opencldesign_encode_1_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_encode_1_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_encode_1_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_encode_1_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_encode_1_0_stub.vhdl
|       |               |   |   |   |   |-- 753a051537aabee5.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 7e148e41779288fa
|       |               |   |   |   |   |   |-- 7e148e41779288fa.xci
|       |               |   |   |   |   |   |-- opencldesign_decode_1_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_decode_1_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_decode_1_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_decode_1_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_decode_1_0_stub.vhdl
|       |               |   |   |   |   |-- 7e148e41779288fa.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 8e23dfab24b9ca56
|       |               |   |   |   |   |   |-- 8e23dfab24b9ca56.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_1_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_1_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_1_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_1_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_1_0_stub.vhdl
|       |               |   |   |   |   |-- 8e23dfab24b9ca56.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- 943f6de9c693104d
|       |               |   |   |   |   |   |-- 943f6de9c693104d.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_4_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_4_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_4_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_4_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_4_0_stub.vhdl
|       |               |   |   |   |   |-- 943f6de9c693104d.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- acf7680209971147
|       |               |   |   |   |   |   |-- acf7680209971147.xci
|       |               |   |   |   |   |   |-- opencldesign_auto_us_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_auto_us_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_auto_us_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_auto_us_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_auto_us_0_stub.vhdl
|       |               |   |   |   |   |-- acf7680209971147.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- ba1b453f8102287f
|       |               |   |   |   |   |   |-- ba1b453f8102287f.xci
|       |               |   |   |   |   |   |-- opencldesign_m01_regslice_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_m01_regslice_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_m01_regslice_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_m01_regslice_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_m01_regslice_0_stub.vhdl
|       |               |   |   |   |   |-- ba1b453f8102287f.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- c01ef41d38cae077
|       |               |   |   |   |   |   |-- c01ef41d38cae077.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_3_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_3_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_3_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_3_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_3_0_stub.vhdl
|       |               |   |   |   |   |-- c01ef41d38cae077.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- c2714c47cd82fbce
|       |               |   |   |   |   |   |-- c2714c47cd82fbce.xci
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_1.dcp
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_1_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_1_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_auto_cc_1_stub.v
|       |               |   |   |   |   |   `-- opencldesign_auto_cc_1_stub.vhdl
|       |               |   |   |   |   |-- c2714c47cd82fbce.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- c4ac4c5f656e337c
|       |               |   |   |   |   |   |-- c4ac4c5f656e337c.xci
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_38_0.dcp
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_38_0_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_38_0_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xlconstant_zero_38_0_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xlconstant_zero_38_0_stub.vhdl
|       |               |   |   |   |   |-- c4ac4c5f656e337c.logs
|       |               |   |   |   |   |   `-- runme.log
|       |               |   |   |   |   |-- cae5823c7fff53f4
|       |               |   |   |   |   |   |-- cae5823c7fff53f4.xci
|       |               |   |   |   |   |   |-- opencldesign_xbar_1.dcp
|       |               |   |   |   |   |   |-- opencldesign_xbar_1_sim_netlist.v
|       |               |   |   |   |   |   |-- opencldesign_xbar_1_sim_netlist.vhdl
|       |               |   |   |   |   |   |-- opencldesign_xbar_1_stub.v
|       |               |   |   |   |   |   `-- opencldesign_xbar_1_stub.vhdl
|       |               |   |   |   |   `-- cae5823c7fff53f4.logs
|       |               |   |   |   |       `-- runme.log
|       |               |   |   |   `-- wt
|       |               |   |   |       |-- project.wpc
|       |               |   |   |       `-- synthesis.wdf
|       |               |   |   |-- ipiprj.hw
|       |               |   |   |   `-- ipiprj.lpr
|       |               |   |   |-- ipiprj.ip_user_files
|       |               |   |   |-- ipiprj.runs
|       |               |   |   |   |-- opencldesign_auto_cc_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_cc_0.dcp
|       |               |   |   |   |   |-- opencldesign_auto_cc_0.tcl
|       |               |   |   |   |   |-- opencldesign_auto_cc_0.vds
|       |               |   |   |   |   |-- opencldesign_auto_cc_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_auto_cc_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_cc_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- fsm_encoding.os
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_cc_1.dcp
|       |               |   |   |   |   |-- opencldesign_auto_cc_1.tcl
|       |               |   |   |   |   |-- opencldesign_auto_cc_1.vds
|       |               |   |   |   |   |-- opencldesign_auto_cc_1_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_auto_cc_1_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_rs_w_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0.dcp
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0.tcl
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0.vds
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_sim_netlist.v
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_sim_netlist.vhdl
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_stub.v
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_stub.vhdl
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_rs_w_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_1.dcp
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_1.tcl
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_1.vds
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_1_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_auto_rs_w_1_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_us_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_us_0.dcp
|       |               |   |   |   |   |-- opencldesign_auto_us_0.tcl
|       |               |   |   |   |   |-- opencldesign_auto_us_0.vds
|       |               |   |   |   |   |-- opencldesign_auto_us_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_auto_us_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_us_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_auto_us_1.dcp
|       |               |   |   |   |   |-- opencldesign_auto_us_1.tcl
|       |               |   |   |   |   |-- opencldesign_auto_us_1.vds
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_decode_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_decode_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_decode_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_decode_1_0.vds
|       |               |   |   |   |   |-- opencldesign_decode_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_decode_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_encode_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_encode_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_encode_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_encode_1_0.vds
|       |               |   |   |   |   |-- opencldesign_encode_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_encode_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_interconnect_sys_reset_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_interconnect_sys_reset_0.dcp
|       |               |   |   |   |   |-- opencldesign_interconnect_sys_reset_0.tcl
|       |               |   |   |   |   |-- opencldesign_interconnect_sys_reset_0.vds
|       |               |   |   |   |   |-- opencldesign_interconnect_sys_reset_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_interconnect_sys_reset_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_kernel_sys_reset_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0.dcp
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0.tcl
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0.vds
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_sim_netlist.v
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_stub.v
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_stub.vhdl
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_m00_regslice_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0.dcp
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0.tcl
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0.vds
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_sim_netlist.v
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_sim_netlist.vhdl
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_stub.v
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_stub.vhdl
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_m00_regslice_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_m01_regslice_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_m01_regslice_0.dcp
|       |               |   |   |   |   |-- opencldesign_m01_regslice_0.tcl
|       |               |   |   |   |   |-- opencldesign_m01_regslice_0.vds
|       |               |   |   |   |   |-- opencldesign_m01_regslice_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_m01_regslice_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_master_bridge_0_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_master_bridge_0_0.dcp
|       |               |   |   |   |   |-- opencldesign_master_bridge_0_0.tcl
|       |               |   |   |   |   |-- opencldesign_master_bridge_0_0.vds
|       |               |   |   |   |   |-- opencldesign_master_bridge_0_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_master_bridge_0_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_master_bridge_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_master_bridge_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_master_bridge_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_master_bridge_1_0.vds
|       |               |   |   |   |   |-- opencldesign_master_bridge_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_master_bridge_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_s00_regslice_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_s00_regslice_0.dcp
|       |               |   |   |   |   |-- opencldesign_s00_regslice_0.tcl
|       |               |   |   |   |   |-- opencldesign_s00_regslice_0.vds
|       |               |   |   |   |   |-- opencldesign_s00_regslice_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_s00_regslice_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_s01_regslice_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_s01_regslice_0.dcp
|       |               |   |   |   |   |-- opencldesign_s01_regslice_0.tcl
|       |               |   |   |   |   |-- opencldesign_s01_regslice_0.vds
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_slave_bridge_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_slave_bridge_0.dcp
|       |               |   |   |   |   |-- opencldesign_slave_bridge_0.tcl
|       |               |   |   |   |   |-- opencldesign_slave_bridge_0.vds
|       |               |   |   |   |   |-- opencldesign_slave_bridge_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_slave_bridge_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xbar_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- fsm_encoding.os
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xbar_0.dcp
|       |               |   |   |   |   |-- opencldesign_xbar_0.tcl
|       |               |   |   |   |   |-- opencldesign_xbar_0.vds
|       |               |   |   |   |   |-- opencldesign_xbar_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xbar_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xbar_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xbar_1.dcp
|       |               |   |   |   |   |-- opencldesign_xbar_1.tcl
|       |               |   |   |   |   |-- opencldesign_xbar_1.vds
|       |               |   |   |   |   |-- opencldesign_xbar_1_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xbar_1_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_1_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_2_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_2_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_2_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_2_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_2_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_2_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_38_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_38_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_38_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_38_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_38_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_38_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_3_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_3_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_3_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_3_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_3_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_3_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_4_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_4_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_4_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_4_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_4_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_4_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_512_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_512_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_512_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_512_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_512_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_512_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_64_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_64_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_64_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_64_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_64_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_64_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_8_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_8_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_8_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_8_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_8_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_8_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- sdaccel.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   `-- synth_1
|       |               |   |   |       |-- ISEWrap.js
|       |               |   |   |       |-- ISEWrap.sh
|       |               |   |   |       |-- dont_touch.xdc
|       |               |   |   |       |-- gen_run.xml
|       |               |   |   |       |-- htr.txt
|       |               |   |   |       |-- opencldesign_wrapper.dcp
|       |               |   |   |       |-- opencldesign_wrapper.tcl
|       |               |   |   |       |-- opencldesign_wrapper.vds
|       |               |   |   |       |-- opencldesign_wrapper_utilization_synth.pb
|       |               |   |   |       |-- opencldesign_wrapper_utilization_synth.rpt
|       |               |   |   |       |-- project.wdf
|       |               |   |   |       |-- rundef.js
|       |               |   |   |       |-- runme.bat
|       |               |   |   |       |-- runme.log
|       |               |   |   |       |-- runme.sh
|       |               |   |   |       |-- sdaccel.jou
|       |               |   |   |       `-- vivado.pb
|       |               |   |   |-- ipiprj.srcs
|       |               |   |   |   `-- sources_1
|       |               |   |   |       `-- bd
|       |               |   |   |           `-- opencldesign
|       |               |   |   |               |-- hdl
|       |               |   |   |               |   |-- opencldesign.hwdef
|       |               |   |   |               |   |-- opencldesign.v
|       |               |   |   |               |   `-- opencldesign_wrapper.v
|       |               |   |   |               |-- hw_handoff
|       |               |   |   |               |   |-- opencldesign.hwh
|       |               |   |   |               |   `-- opencldesign_bd.tcl
|       |               |   |   |               |-- ip
|       |               |   |   |               |   |-- opencldesign_auto_cc_0
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_clocks.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_cc_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_cc_0.v
|       |               |   |   |               |   |-- opencldesign_auto_cc_1
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_clocks.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_cc_1_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_cc_1.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_cc_1.v
|       |               |   |   |               |   |-- opencldesign_auto_rs_w_0
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_rs_w_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_rs_w_0.v
|       |               |   |   |               |   |-- opencldesign_auto_rs_w_1
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_rs_w_1_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_rs_w_1.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_rs_w_1.v
|       |               |   |   |               |   |-- opencldesign_auto_us_0
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_clocks.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_us_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_us_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_us_0.v
|       |               |   |   |               |   |-- opencldesign_auto_us_1
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1.dcp
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1.xci
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1.xml
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_clocks.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_stub.v
|       |               |   |   |               |   |   |-- opencldesign_auto_us_1_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_auto_us_1.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_auto_us_1.v
|       |               |   |   |               |   |-- opencldesign_decode_1_0
|       |               |   |   |               |   |   |-- constraints
|       |               |   |   |               |   |   |   `-- decode_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_decode_1_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_decode_1_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_decode_1_0.v
|       |               |   |   |               |   |-- opencldesign_encode_1_0
|       |               |   |   |               |   |   |-- constraints
|       |               |   |   |               |   |   |   `-- encode_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_encode_1_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_encode_1_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_encode_1_0.v
|       |               |   |   |               |   |-- opencldesign_interconnect_sys_reset_0
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0.xci
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0.xdc
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0.xml
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_board.xdc
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_interconnect_sys_reset_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_interconnect_sys_reset_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_interconnect_sys_reset_0.vhd
|       |               |   |   |               |   |-- opencldesign_kernel_sys_reset_0
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0.xci
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0.xdc
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0.xml
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_board.xdc
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_kernel_sys_reset_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_kernel_sys_reset_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_kernel_sys_reset_0.vhd
|       |               |   |   |               |   |-- opencldesign_m00_regslice_0
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0.xci
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0.xml
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_m00_regslice_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_m00_regslice_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_m00_regslice_0.v
|       |               |   |   |               |   |-- opencldesign_m01_regslice_0
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0.xci
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0.xml
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_m01_regslice_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_m01_regslice_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_m01_regslice_0.v
|       |               |   |   |               |   |-- opencldesign_m_axi_interconnect_M00_AXI_0
|       |               |   |   |               |   |   |-- opencldesign_m_axi_interconnect_M00_AXI_0.xci
|       |               |   |   |               |   |   `-- opencldesign_m_axi_interconnect_M00_AXI_0.xml
|       |               |   |   |               |   |-- opencldesign_master_bridge_0_0
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0.xci
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0.xml
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_0_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_master_bridge_0_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_master_bridge_0_0.vhd
|       |               |   |   |               |   |-- opencldesign_master_bridge_1_0
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_master_bridge_1_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_master_bridge_1_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_master_bridge_1_0.vhd
|       |               |   |   |               |   |-- opencldesign_s00_regslice_0
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0.xci
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0.xml
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_s00_regslice_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_s00_regslice_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_s00_regslice_0.v
|       |               |   |   |               |   |-- opencldesign_s01_regslice_0
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0.xci
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0.xml
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_s01_regslice_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_s01_regslice_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_s01_regslice_0.v
|       |               |   |   |               |   |-- opencldesign_s_axi_interconnect_0_0
|       |               |   |   |               |   |   |-- opencldesign_s_axi_interconnect_0_0.xci
|       |               |   |   |               |   |   `-- opencldesign_s_axi_interconnect_0_0.xml
|       |               |   |   |               |   |-- opencldesign_slave_bridge_0
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0.xci
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0.xml
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_slave_bridge_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_slave_bridge_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_slave_bridge_0.vhd
|       |               |   |   |               |   |-- opencldesign_xbar_0
|       |               |   |   |               |   |   |-- opencldesign_xbar_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xbar_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xbar_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xbar_0_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_xbar_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xbar_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xbar_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xbar_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_xbar_0.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_xbar_0.v
|       |               |   |   |               |   |-- opencldesign_xbar_1
|       |               |   |   |               |   |   |-- opencldesign_xbar_1.dcp
|       |               |   |   |               |   |   |-- opencldesign_xbar_1.xci
|       |               |   |   |               |   |   |-- opencldesign_xbar_1.xml
|       |               |   |   |               |   |   |-- opencldesign_xbar_1_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_xbar_1_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xbar_1_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xbar_1_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xbar_1_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_xbar_1.v
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_xbar_1.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_1_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_1_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_2_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_2_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_38_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_38_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_38_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_3_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_3_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_4_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_4_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_512_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_512_0.v
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_64_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_64_0.v
|       |               |   |   |               |   `-- opencldesign_xlconstant_zero_8_0
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0.dcp
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0.xci
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0.xml
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0_sim_netlist.v
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0_sim_netlist.vhdl
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0_stub.v
|       |               |   |   |               |       |-- opencldesign_xlconstant_zero_8_0_stub.vhdl
|       |               |   |   |               |       `-- sim
|       |               |   |   |               |           `-- opencldesign_xlconstant_zero_8_0.v
|       |               |   |   |               |-- ipshared
|       |               |   |   |               |   `-- xilinx.com
|       |               |   |   |               |       |-- axi_clock_converter_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_clock_converter_v2_1_axi_clock_converter.v
|       |               |   |   |               |       |           |-- axi_clock_converter_v2_1_axic_sample_cycle_ratio.v
|       |               |   |   |               |       |           `-- axi_clock_converter_v2_1_axic_sync_clock_converter.v
|       |               |   |   |               |       |-- axi_crossbar_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_addr_arbiter.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_addr_arbiter_sasd.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_addr_decoder.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_arbiter_resp.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_axi_crossbar.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_crossbar.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_crossbar_sasd.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_decerr_slave.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_si_transactor.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_splitter.v
|       |               |   |   |               |       |           |-- axi_crossbar_v2_1_wdata_mux.v
|       |               |   |   |               |       |           `-- axi_crossbar_v2_1_wdata_router.v
|       |               |   |   |               |       |-- axi_data_fifo_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_data_fifo_v2_1_axi_data_fifo.v
|       |               |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_fifo.v
|       |               |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_reg_srl_fifo.v
|       |               |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_srl_fifo.v
|       |               |   |   |               |       |           |-- axi_data_fifo_v2_1_fifo_gen.v
|       |               |   |   |               |       |           `-- axi_data_fifo_v2_1_ndeep_srl.v
|       |               |   |   |               |       |-- axi_dwidth_converter_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_a_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_a_upsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi4lite_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi4lite_upsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi_upsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_b_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_upsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_upsizer_pktfifo.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_top.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_w_downsizer.v
|       |               |   |   |               |       |           |-- axi_dwidth_converter_v2_1_w_upsizer.v
|       |               |   |   |               |       |           `-- axi_dwidth_converter_v2_1_w_upsizer_pktfifo.v
|       |               |   |   |               |       |-- axi_infrastructure_v1_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_infrastructure_v1_1_0_header.vh
|       |               |   |   |               |       |           |-- axi_infrastructure_v1_1_axi2vector.v
|       |               |   |   |               |       |           |-- axi_infrastructure_v1_1_axic_srl_fifo.v
|       |               |   |   |               |       |           `-- axi_infrastructure_v1_1_vector2axi.v
|       |               |   |   |               |       |-- axi_protocol_converter_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_a_axi3_conv.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_axi3_conv.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_axi_protocol_converter.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_axilite_conv.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_ar_channel.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_aw_channel.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_b_channel.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_cmd_translator.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_incr_cmd.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_r_channel.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_simple_fifo.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_wrap_cmd.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_b_downsizer.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_decerr_slave.v
|       |               |   |   |               |       |           |-- axi_protocol_converter_v2_1_r_axi3_conv.v
|       |               |   |   |               |       |           `-- axi_protocol_converter_v2_1_w_axi3_conv.v
|       |               |   |   |               |       |-- axi_register_slice_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_register_slice_v2_1_axi_register_slice.v
|       |               |   |   |               |       |           `-- axi_register_slice_v2_1_axic_register_slice.v
|       |               |   |   |               |       |-- blk_mem_gen_v8_3
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- blk_mem_gen_v8_3.vhd
|       |               |   |   |               |       |   |   `-- blk_mem_gen_v8_3_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- blk_mem_gen_v8_3.v
|       |               |   |   |               |       |-- decode_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- decode.v
|       |               |   |   |               |       |           |-- decode_control_s_axi.v
|       |               |   |   |               |       |           |-- decode_gmem_m_axi.v
|       |               |   |   |               |       |           |-- decode_ht.v
|       |               |   |   |               |       |           |-- decode_leaf_bitcodes.v
|       |               |   |   |               |       |           `-- decode_leaf_symbols.v
|       |               |   |   |               |       |-- encode_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- encode.v
|       |               |   |   |               |       |           |-- encode_alphabet_to_htree_node.v
|       |               |   |   |               |       |           |-- encode_alphabet_usage.v
|       |               |   |   |               |       |           |-- encode_control_s_axi.v
|       |               |   |   |               |       |           |-- encode_gmem_m_axi.v
|       |               |   |   |               |       |           |-- encode_ht.v
|       |               |   |   |               |       |           `-- encode_visited.v
|       |               |   |   |               |       |-- fifo_generator_v13_1
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1.vhd
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.v
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.vhd
|       |               |   |   |               |       |   |   `-- fifo_generator_v13_1_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- fifo_generator_vlog_beh.v
|       |               |   |   |               |       |-- generic_baseblocks_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_carry.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_and.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_latch_and.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_latch_or.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_or.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_command_fifo.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_mask.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_mask_static.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_mask.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_mask_static.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_static.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_static.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_mux.v
|       |               |   |   |               |       |           |-- generic_baseblocks_v2_1_mux_enc.v
|       |               |   |   |               |       |           `-- generic_baseblocks_v2_1_nto1_mux.v
|       |               |   |   |               |       |-- lib_cdc_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- src
|       |               |   |   |               |       |           `-- vhdl
|       |               |   |   |               |       |               `-- cdc_sync.vhd
|       |               |   |   |               |       |-- ocl_axifull_bridge_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- axifull_bridge.vhd
|       |               |   |   |               |       |-- ocl_axilite_bridge_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- axilite_bridge.vhd
|       |               |   |   |               |       |-- proc_sys_reset_v5_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- src
|       |               |   |   |               |       |           `-- vhdl
|       |               |   |   |               |       |               |-- lpf.vhd
|       |               |   |   |               |       |               |-- proc_sys_reset.vhd
|       |               |   |   |               |       |               |-- sequence_psr.vhd
|       |               |   |   |               |       |               `-- upcnt_n.vhd
|       |               |   |   |               |       `-- xlconstant_v1_1
|       |               |   |   |               |           `-- xlconstant.v
|       |               |   |   |               |-- opencldesign.bd
|       |               |   |   |               |-- opencldesign.bxml
|       |               |   |   |               `-- opencldesign_ooc.xdc
|       |               |   |   `-- ipiprj.xpr
|       |               |   |-- ipirun.tcl
|       |               |   |-- map.tcl
|       |               |   |-- opencldesign.dcp
|       |               |   |-- opencldesign_ooc_copy.xdc
|       |               |   |-- partial.bit
|       |               |   |-- partial_clear.bit
|       |               |   |-- post_init.tcl
|       |               |   |-- sdaccel.jou
|       |               |   |-- sdaccel.log
|       |               |   |-- vivado.log
|       |               |   |-- vivado.pb
|       |               |   `-- vivado_user.tcl
|       |               `-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1_regiongen.log
|       `-- kernels
|           |-- decode
|           |   |-- ISEWrap.js
|           |   |-- ISEWrap.sh
|           |   |-- decode
|           |   |   |-- decode.clc.00.bc
|           |   |   |-- decode.design.xml
|           |   |   |-- decode_clang.log
|           |   |   |-- decode_hls_transform.log
|           |   |   |-- decode_kernelinfohash.log
|           |   |   |-- hls_transform.tcl
|           |   |   |-- ip
|           |   |   |   |-- autoimpl.log
|           |   |   |   |-- auxiliary.xml
|           |   |   |   |-- bd
|           |   |   |   |-- component.xml
|           |   |   |   |-- constraints
|           |   |   |   |   `-- decode_ooc.xdc
|           |   |   |   |-- decode_info.xml
|           |   |   |   |-- doc
|           |   |   |   |   `-- ReleaseNotes.txt
|           |   |   |   |-- drivers
|           |   |   |   |   `-- decode_v1_0
|           |   |   |   |       |-- data
|           |   |   |   |       |   |-- decode.mdd
|           |   |   |   |       |   `-- decode.tcl
|           |   |   |   |       `-- src
|           |   |   |   |           |-- Makefile
|           |   |   |   |           |-- xdecode.c
|           |   |   |   |           |-- xdecode.h
|           |   |   |   |           |-- xdecode_hw.h
|           |   |   |   |           |-- xdecode_linux.c
|           |   |   |   |           `-- xdecode_sinit.c
|           |   |   |   |-- example
|           |   |   |   |   |-- ipi_example.sh
|           |   |   |   |   `-- ipi_example.tcl
|           |   |   |   |-- hdl
|           |   |   |   |   |-- verilog
|           |   |   |   |   |   |-- decode.v
|           |   |   |   |   |   |-- decode_control_s_axi.v
|           |   |   |   |   |   |-- decode_gmem_m_axi.v
|           |   |   |   |   |   |-- decode_ht.v
|           |   |   |   |   |   |-- decode_leaf_bitcodes.v
|           |   |   |   |   |   `-- decode_leaf_symbols.v
|           |   |   |   |   `-- vhdl
|           |   |   |   |       |-- decode.vhd
|           |   |   |   |       |-- decode_control_s_axi.vhd
|           |   |   |   |       |-- decode_gmem_m_axi.vhd
|           |   |   |   |       |-- decode_ht.vhd
|           |   |   |   |       |-- decode_leaf_bitcodes.vhd
|           |   |   |   |       `-- decode_leaf_symbols.vhd
|           |   |   |   |-- misc
|           |   |   |   |   `-- logo.png
|           |   |   |   |-- pack.sh
|           |   |   |   |-- run_ippack.tcl
|           |   |   |   |-- subcore
|           |   |   |   |-- vivado.jou
|           |   |   |   |-- vivado.log
|           |   |   |   |-- xgui
|           |   |   |   |   `-- decode_v1_0.tcl
|           |   |   |   `-- xilinx_com_hls_decode_1_0.zip
|           |   |   |-- kernel.xml
|           |   |   |-- kernel.xml.orig
|           |   |   |-- solution_OCL_REGION_0
|           |   |   |   |-- impl
|           |   |   |   |   |-- ip
|           |   |   |   |   |   |-- autoimpl.log
|           |   |   |   |   |   |-- auxiliary.xml
|           |   |   |   |   |   |-- bd
|           |   |   |   |   |   |-- component.xml
|           |   |   |   |   |   |-- constraints
|           |   |   |   |   |   |   `-- decode_ooc.xdc
|           |   |   |   |   |   |-- decode_info.xml
|           |   |   |   |   |   |-- doc
|           |   |   |   |   |   |   `-- ReleaseNotes.txt
|           |   |   |   |   |   |-- drivers
|           |   |   |   |   |   |   `-- decode_v1_0
|           |   |   |   |   |   |       |-- data
|           |   |   |   |   |   |       |   |-- decode.mdd
|           |   |   |   |   |   |       |   `-- decode.tcl
|           |   |   |   |   |   |       `-- src
|           |   |   |   |   |   |           |-- Makefile
|           |   |   |   |   |   |           |-- xdecode.c
|           |   |   |   |   |   |           |-- xdecode.h
|           |   |   |   |   |   |           |-- xdecode_hw.h
|           |   |   |   |   |   |           |-- xdecode_linux.c
|           |   |   |   |   |   |           `-- xdecode_sinit.c
|           |   |   |   |   |   |-- example
|           |   |   |   |   |   |   |-- ipi_example.sh
|           |   |   |   |   |   |   `-- ipi_example.tcl
|           |   |   |   |   |   |-- hdl
|           |   |   |   |   |   |   |-- verilog
|           |   |   |   |   |   |   |   |-- decode.v
|           |   |   |   |   |   |   |   |-- decode_control_s_axi.v
|           |   |   |   |   |   |   |   |-- decode_gmem_m_axi.v
|           |   |   |   |   |   |   |   |-- decode_ht.v
|           |   |   |   |   |   |   |   |-- decode_leaf_bitcodes.v
|           |   |   |   |   |   |   |   `-- decode_leaf_symbols.v
|           |   |   |   |   |   |   `-- vhdl
|           |   |   |   |   |   |       |-- decode.vhd
|           |   |   |   |   |   |       |-- decode_control_s_axi.vhd
|           |   |   |   |   |   |       |-- decode_gmem_m_axi.vhd
|           |   |   |   |   |   |       |-- decode_ht.vhd
|           |   |   |   |   |   |       |-- decode_leaf_bitcodes.vhd
|           |   |   |   |   |   |       `-- decode_leaf_symbols.vhd
|           |   |   |   |   |   |-- misc
|           |   |   |   |   |   |   `-- logo.png
|           |   |   |   |   |   |-- pack.sh
|           |   |   |   |   |   |-- run_ippack.tcl
|           |   |   |   |   |   |-- subcore
|           |   |   |   |   |   |-- vivado.jou
|           |   |   |   |   |   |-- vivado.log
|           |   |   |   |   |   |-- xgui
|           |   |   |   |   |   |   `-- decode_v1_0.tcl
|           |   |   |   |   |   `-- xilinx_com_hls_decode_1_0.zip
|           |   |   |   |   |-- sdaccel
|           |   |   |   |   |   |-- kernel.xml
|           |   |   |   |   |   `-- kernel.xo
|           |   |   |   |   |-- verilog
|           |   |   |   |   |   |-- decode.v
|           |   |   |   |   |   |-- decode.xdc
|           |   |   |   |   |   |-- decode_control_s_axi.v
|           |   |   |   |   |   |-- decode_gmem_m_axi.v
|           |   |   |   |   |   |-- decode_ht.v
|           |   |   |   |   |   |-- decode_leaf_bitcodes.v
|           |   |   |   |   |   |-- decode_leaf_symbols.v
|           |   |   |   |   |   |-- extraction.tcl
|           |   |   |   |   |   |-- impl.sh
|           |   |   |   |   |   |-- project.cache
|           |   |   |   |   |   |   `-- wt
|           |   |   |   |   |   |       `-- project.wpc
|           |   |   |   |   |   |-- project.hw
|           |   |   |   |   |   |   `-- project.lpr
|           |   |   |   |   |   |-- project.ip_user_files
|           |   |   |   |   |   |-- project.xpr
|           |   |   |   |   |   |-- run_vivado.tcl
|           |   |   |   |   |   `-- settings.tcl
|           |   |   |   |   `-- vhdl
|           |   |   |   |       |-- decode.vhd
|           |   |   |   |       |-- decode.xdc
|           |   |   |   |       |-- decode_control_s_axi.vhd
|           |   |   |   |       |-- decode_gmem_m_axi.vhd
|           |   |   |   |       |-- decode_ht.vhd
|           |   |   |   |       |-- decode_leaf_bitcodes.vhd
|           |   |   |   |       |-- decode_leaf_symbols.vhd
|           |   |   |   |       |-- extraction.tcl
|           |   |   |   |       |-- impl.sh
|           |   |   |   |       |-- project.cache
|           |   |   |   |       |   `-- wt
|           |   |   |   |       |       `-- project.wpc
|           |   |   |   |       |-- project.hw
|           |   |   |   |       |   `-- project.lpr
|           |   |   |   |       |-- project.ip_user_files
|           |   |   |   |       |-- project.xpr
|           |   |   |   |       |-- run_vivado.tcl
|           |   |   |   |       `-- settings.tcl
|           |   |   |   |-- solution_OCL_REGION_0.aps
|           |   |   |   |-- solution_OCL_REGION_0.directive
|           |   |   |   |-- solution_OCL_REGION_0.log
|           |   |   |   `-- syn
|           |   |   |       |-- report
|           |   |   |       |   |-- decode_csynth.rpt
|           |   |   |       |   `-- decode_csynth.xml
|           |   |   |       |-- systemc
|           |   |   |       |   |-- decode.h
|           |   |   |       |   |-- decode_1.cpp
|           |   |   |       |   |-- decode_2.cpp
|           |   |   |       |   |-- decode_3.cpp
|           |   |   |       |   |-- decode_4.cpp
|           |   |   |       |   |-- decode_ht.h
|           |   |   |       |   |-- decode_leaf_bitcodes.h
|           |   |   |       |   `-- decode_leaf_symbols.h
|           |   |   |       |-- verilog
|           |   |   |       |   |-- decode.v
|           |   |   |       |   |-- decode_control_s_axi.v
|           |   |   |       |   |-- decode_gmem_m_axi.v
|           |   |   |       |   |-- decode_ht.v
|           |   |   |       |   |-- decode_leaf_bitcodes.v
|           |   |   |       |   `-- decode_leaf_symbols.v
|           |   |   |       `-- vhdl
|           |   |   |           |-- decode.vhd
|           |   |   |           |-- decode_control_s_axi.vhd
|           |   |   |           |-- decode_gmem_m_axi.vhd
|           |   |   |           |-- decode_ht.vhd
|           |   |   |           |-- decode_leaf_bitcodes.vhd
|           |   |   |           `-- decode_leaf_symbols.vhd
|           |   |   |-- vivado_hls.app
|           |   |   |-- vivado_hls.log
|           |   |   |-- xcl_tmp.bc
|           |   |   `-- xcl_tmp.cpp
|           |   |-- decode.tcl
|           |   |-- htr.txt
|           |   |-- rundef.js
|           |   |-- runme.bat
|           |   |-- runme.log
|           |   |-- runme.sh
|           |   `-- vivado_hls.log
|           `-- encode
|               |-- ISEWrap.js
|               |-- ISEWrap.sh
|               |-- encode
|               |   |-- encode.clc.00.bc
|               |   |-- encode.design.xml
|               |   |-- encode_clang.log
|               |   |-- encode_hls_transform.log
|               |   |-- encode_kernelinfohash.log
|               |   |-- hls_transform.tcl
|               |   |-- ip
|               |   |   |-- autoimpl.log
|               |   |   |-- auxiliary.xml
|               |   |   |-- bd
|               |   |   |-- component.xml
|               |   |   |-- constraints
|               |   |   |   `-- encode_ooc.xdc
|               |   |   |-- doc
|               |   |   |   `-- ReleaseNotes.txt
|               |   |   |-- drivers
|               |   |   |   `-- encode_v1_0
|               |   |   |       |-- data
|               |   |   |       |   |-- encode.mdd
|               |   |   |       |   `-- encode.tcl
|               |   |   |       `-- src
|               |   |   |           |-- Makefile
|               |   |   |           |-- xencode.c
|               |   |   |           |-- xencode.h
|               |   |   |           |-- xencode_hw.h
|               |   |   |           |-- xencode_linux.c
|               |   |   |           `-- xencode_sinit.c
|               |   |   |-- encode_info.xml
|               |   |   |-- example
|               |   |   |   |-- ipi_example.sh
|               |   |   |   `-- ipi_example.tcl
|               |   |   |-- hdl
|               |   |   |   |-- verilog
|               |   |   |   |   |-- encode.v
|               |   |   |   |   |-- encode_alphabet_to_htree_node.v
|               |   |   |   |   |-- encode_alphabet_usage.v
|               |   |   |   |   |-- encode_control_s_axi.v
|               |   |   |   |   |-- encode_gmem_m_axi.v
|               |   |   |   |   |-- encode_ht.v
|               |   |   |   |   `-- encode_visited.v
|               |   |   |   `-- vhdl
|               |   |   |       |-- encode.vhd
|               |   |   |       |-- encode_alphabet_to_htree_node.vhd
|               |   |   |       |-- encode_alphabet_usage.vhd
|               |   |   |       |-- encode_control_s_axi.vhd
|               |   |   |       |-- encode_gmem_m_axi.vhd
|               |   |   |       |-- encode_ht.vhd
|               |   |   |       `-- encode_visited.vhd
|               |   |   |-- misc
|               |   |   |   `-- logo.png
|               |   |   |-- pack.sh
|               |   |   |-- run_ippack.tcl
|               |   |   |-- subcore
|               |   |   |-- vivado.jou
|               |   |   |-- vivado.log
|               |   |   |-- xgui
|               |   |   |   `-- encode_v1_0.tcl
|               |   |   `-- xilinx_com_hls_encode_1_0.zip
|               |   |-- kernel.xml
|               |   |-- kernel.xml.orig
|               |   |-- solution_OCL_REGION_0
|               |   |   |-- impl
|               |   |   |   |-- ip
|               |   |   |   |   |-- autoimpl.log
|               |   |   |   |   |-- auxiliary.xml
|               |   |   |   |   |-- bd
|               |   |   |   |   |-- component.xml
|               |   |   |   |   |-- constraints
|               |   |   |   |   |   `-- encode_ooc.xdc
|               |   |   |   |   |-- doc
|               |   |   |   |   |   `-- ReleaseNotes.txt
|               |   |   |   |   |-- drivers
|               |   |   |   |   |   `-- encode_v1_0
|               |   |   |   |   |       |-- data
|               |   |   |   |   |       |   |-- encode.mdd
|               |   |   |   |   |       |   `-- encode.tcl
|               |   |   |   |   |       `-- src
|               |   |   |   |   |           |-- Makefile
|               |   |   |   |   |           |-- xencode.c
|               |   |   |   |   |           |-- xencode.h
|               |   |   |   |   |           |-- xencode_hw.h
|               |   |   |   |   |           |-- xencode_linux.c
|               |   |   |   |   |           `-- xencode_sinit.c
|               |   |   |   |   |-- encode_info.xml
|               |   |   |   |   |-- example
|               |   |   |   |   |   |-- ipi_example.sh
|               |   |   |   |   |   `-- ipi_example.tcl
|               |   |   |   |   |-- hdl
|               |   |   |   |   |   |-- verilog
|               |   |   |   |   |   |   |-- encode.v
|               |   |   |   |   |   |   |-- encode_alphabet_to_htree_node.v
|               |   |   |   |   |   |   |-- encode_alphabet_usage.v
|               |   |   |   |   |   |   |-- encode_control_s_axi.v
|               |   |   |   |   |   |   |-- encode_gmem_m_axi.v
|               |   |   |   |   |   |   |-- encode_ht.v
|               |   |   |   |   |   |   `-- encode_visited.v
|               |   |   |   |   |   `-- vhdl
|               |   |   |   |   |       |-- encode.vhd
|               |   |   |   |   |       |-- encode_alphabet_to_htree_node.vhd
|               |   |   |   |   |       |-- encode_alphabet_usage.vhd
|               |   |   |   |   |       |-- encode_control_s_axi.vhd
|               |   |   |   |   |       |-- encode_gmem_m_axi.vhd
|               |   |   |   |   |       |-- encode_ht.vhd
|               |   |   |   |   |       `-- encode_visited.vhd
|               |   |   |   |   |-- misc
|               |   |   |   |   |   `-- logo.png
|               |   |   |   |   |-- pack.sh
|               |   |   |   |   |-- run_ippack.tcl
|               |   |   |   |   |-- subcore
|               |   |   |   |   |-- vivado.jou
|               |   |   |   |   |-- vivado.log
|               |   |   |   |   |-- xgui
|               |   |   |   |   |   `-- encode_v1_0.tcl
|               |   |   |   |   `-- xilinx_com_hls_encode_1_0.zip
|               |   |   |   |-- sdaccel
|               |   |   |   |   |-- kernel.xml
|               |   |   |   |   `-- kernel.xo
|               |   |   |   |-- verilog
|               |   |   |   |   |-- encode.v
|               |   |   |   |   |-- encode.xdc
|               |   |   |   |   |-- encode_alphabet_to_htree_node.v
|               |   |   |   |   |-- encode_alphabet_usage.v
|               |   |   |   |   |-- encode_control_s_axi.v
|               |   |   |   |   |-- encode_gmem_m_axi.v
|               |   |   |   |   |-- encode_ht.v
|               |   |   |   |   |-- encode_visited.v
|               |   |   |   |   |-- extraction.tcl
|               |   |   |   |   |-- impl.sh
|               |   |   |   |   |-- project.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- project.hw
|               |   |   |   |   |   `-- project.lpr
|               |   |   |   |   |-- project.ip_user_files
|               |   |   |   |   |-- project.xpr
|               |   |   |   |   |-- run_vivado.tcl
|               |   |   |   |   `-- settings.tcl
|               |   |   |   `-- vhdl
|               |   |   |       |-- encode.vhd
|               |   |   |       |-- encode.xdc
|               |   |   |       |-- encode_alphabet_to_htree_node.vhd
|               |   |   |       |-- encode_alphabet_usage.vhd
|               |   |   |       |-- encode_control_s_axi.vhd
|               |   |   |       |-- encode_gmem_m_axi.vhd
|               |   |   |       |-- encode_ht.vhd
|               |   |   |       |-- encode_visited.vhd
|               |   |   |       |-- extraction.tcl
|               |   |   |       |-- impl.sh
|               |   |   |       |-- project.cache
|               |   |   |       |   `-- wt
|               |   |   |       |       `-- project.wpc
|               |   |   |       |-- project.hw
|               |   |   |       |   `-- project.lpr
|               |   |   |       |-- project.ip_user_files
|               |   |   |       |-- project.xpr
|               |   |   |       |-- run_vivado.tcl
|               |   |   |       `-- settings.tcl
|               |   |   |-- solution_OCL_REGION_0.aps
|               |   |   |-- solution_OCL_REGION_0.directive
|               |   |   |-- solution_OCL_REGION_0.log
|               |   |   `-- syn
|               |   |       |-- report
|               |   |       |   |-- encode_csynth.rpt
|               |   |       |   `-- encode_csynth.xml
|               |   |       |-- systemc
|               |   |       |   |-- encode.h
|               |   |       |   |-- encode_1.cpp
|               |   |       |   |-- encode_2.cpp
|               |   |       |   |-- encode_3.cpp
|               |   |       |   |-- encode_4.cpp
|               |   |       |   |-- encode_alphabet_to_htree_node.h
|               |   |       |   |-- encode_alphabet_usage.h
|               |   |       |   |-- encode_ht.h
|               |   |       |   `-- encode_visited.h
|               |   |       |-- verilog
|               |   |       |   |-- encode.v
|               |   |       |   |-- encode_alphabet_to_htree_node.v
|               |   |       |   |-- encode_alphabet_usage.v
|               |   |       |   |-- encode_control_s_axi.v
|               |   |       |   |-- encode_gmem_m_axi.v
|               |   |       |   |-- encode_ht.v
|               |   |       |   `-- encode_visited.v
|               |   |       `-- vhdl
|               |   |           |-- encode.vhd
|               |   |           |-- encode_alphabet_to_htree_node.vhd
|               |   |           |-- encode_alphabet_usage.vhd
|               |   |           |-- encode_control_s_axi.vhd
|               |   |           |-- encode_gmem_m_axi.vhd
|               |   |           |-- encode_ht.vhd
|               |   |           `-- encode_visited.vhd
|               |   |-- vivado_hls.app
|               |   |-- vivado_hls.log
|               |   |-- xcl_tmp.bc
|               |   `-- xcl_tmp.cpp
|               |-- encode.tcl
|               |-- htr.txt
|               |-- rundef.js
|               |-- runme.bat
|               |-- runme.log
|               |-- runme.sh
|               `-- vivado_hls.log
|-- benchapp.log
|-- data
|   |-- input.bmp
|   |-- rect_1024.bmp
|   |-- rect_32.bmp
|   |-- rect_512.bmp
|   |-- rect_64.bmp
|   `-- sdaccel.bmp
|-- description.json
|-- huffman
|-- src
|   |-- bit_io.cpp
|   |-- bit_io.h
|   |-- huffmancodec_naive.cpp
|   |-- huffmancodec_naive.h
|   |-- huffmancodec_optimized.cpp
|   |-- huffmancodec_optimized.h
|   |-- huffmancodec_optimized_cpuonly.cpp
|   |-- huffmancodec_optimized_cpuonly.h
|   |-- krnl_huffman.cl
|   |-- krnl_huffman_singleptr.cl
|   |-- krnl_huffman_singleptr.ll
|   `-- main.cpp
`-- xclbin
    `-- krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin

334 directories, 1375 files
```

## 5. COMPILATION AND EXECUTION FOR X86 SERVERS
### Compiling for Application Emulation
As part of the capabilities available to an application developer, SDAccel includes environments to test the correctness of an application at both a software functional level and a hardware emulated level.
These modes, which are named sw_emu and hw_emu, allow the developer to profile and evaluate the performance of a design before compiling for board execution.
It is recommended that all applications are executed in at least the sw_emu mode before being compiled and executed on an FPGA board.
```
make TARGETS=<sw_emu|hw_emu> all
```
where
```
	sw_emu = software emulation
	hw_emu = hardware emulation
```
*NOTE:* The software emulation flow is a functional correctness check only. It does not estimate the performance of the application in hardware.
The hardware emulation flow is a cycle accurate simulation of the hardware generated for the application. As such, it is expected for this simulation to take a long time.
It is recommended that for this example the user skips running hardware emulation or modifies the example to work on a reduced data set.
### Executing Emulated Application 
***Recommended Execution Flow for Example Applications in Emulation*** 

The makefile for the application can directly executed the application with the following command:
```
make TARGETS=<sw_emu|hw_emu> check

```
where
```
	sw_emu = software emulation
	hw_emu = hardware emulation
```
If the application has not been previously compiled, the check makefile rule will compile and execute the application in the emulation mode selected by the user.

***Alternative Execution Flow for Example Applications in Emulation*** 

An emulated application can also be executed directly from the command line without using the check makefile rule as long as the user environment has been properly configured.
To manually configure the environment to run the application, set the following
```
export LD_LIBRARY_PATH=$XILINX_SDX/runtime/lib/x86_64/:$LD_LIBRARY_PATH
export XCL_EMULATION_MODE=true
emconfigutil --xdevice 'xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2' --nd 1
```
Once the environment has been configured, the application can be executed by
```
./huffman -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:3.1' --kernel ./xclbin/krnl_huffman.<emulation type>.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin data/rect_1024.bmp
```
This is the same command executed by the check makefile rule
### Compiling for Application Execution in the FPGA Accelerator Card
The command to compile the application for execution on the FPGA acceleration board is
```
make all
```
The default target for the makefile is to compile for hardware. Therefore, setting the TARGETS option is not required.
*NOTE:* Compilation for application execution in hardware generates custom logic to implement the functionality of the kernels in an application.It is typical for hardware compile times to range from 30 minutes to a couple of hours.
### Executing the Application in the FPGA Accelerator Card
The developer instance hosting the SDAccel tools on Nimbix is not directly connected to an FPGA accelerator card.
FPGA Accelerator cards are available as part of the SDAccel Runtime application. There are several ways of executing an application on the available cards:

***Submit the application from the developer to runtime instances (recommended flow)***
* Create a credentials file for the runtime machine based on your Nimbix username and API key. For more information on how to obtain the API key, refer to [Nimbix Application Submission README][]. The credentials file ( ~/.nimbix_creds.json ) should look like
```
{
	"username": "<username>",
	"api-key": "<apikey>"
}
```

where the values for username and apikey have been set to the values from your Nimbix account.

*NOTE:* The home directory of a SDAccel developer instance is not persistent across sessions. Only files stored in the /data directory are kept between sessions.It is recommended that a copy of the nimbix_creds.json file be stored in the /data directory and copied to the appropriate location in the home directory at the start of each development session.
* Launch the application
```
make check
```
***Launch the application from a remote system outside of the Nimbix environment***
* Follow the instructions in [Nimbix Application Submission README][]

* Use the following command to launch the application from the users terminal (on a system outside of the Nimbix environment)
```
../../utility/nimbix/nimbix-run.py -- ./huffman -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:2.1' --kernel ./xclbin/krnl_huffman.hw.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin data/rect_1024.bmp
```

***Copy the application files from the Developer to Runtime instances on Nimbix***
* Copy the application *.exe file and xclbin directory to the /data directory
* Launch the application using the Nimbix web interface as described in [Nimbix Getting Started Guide][]
* Make sure that the application launch options in the Nimbix web interface reflect the applications command line syntax
```
./huffman -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:3.1' --kernel ./xclbin/krnl_huffman.<emulation type>.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin data/rect_1024.bmp
```

## 6. COMPILATION AND EXECUTION FOR IBM POWER SERVERS
View the SuperVessel [Walkthrough Video][] to become familiar with the environment.

Compile the application with the following command
```
make ARCH=POWER all
```

## 7. SUPPORT
For more information about SDAccel check the [SDAccel User Guides][]

For questions and to get help on this project or your own projects, visit the [SDAccel Forums][].

To execute this example using the SDAccel GUI, follow the setup instructions in [SDAccel GUI README][]


## 8. LICENSE AND CONTRIBUTING TO THE REPOSITORY
The source for this project is licensed under the [3-Clause BSD License][]

To contribute to this project, follow the guidelines in the [Repository Contribution README][]

## 9. ACKNOWLEDGEMENTS
This example is written by developers at
- [Xilinx](http://www.xilinx.com)

## 10. REVISION HISTORY
Date | README Version | Description
-----|----------------|------------
FEB2016|1.0|Initial Xilinx Release
JUL2016|2.0|Conversion to Makefile based compilation
DEC2016|3.0|Update for SDAccel 2016.3

[3-Clause BSD License]:../../LICENSE.txt
[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx
[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation
[Nimbix Getting Started Guide]: http://www.xilinx.com/support/documentation/sw_manuals/xilinx2016_2/ug1240-sdaccel-nimbix-getting-started.pdf
[Walkthrough Video]: http://bcove.me/6pp0o482
[Nimbix Application Submission README]:../../utility/nimbix/README.md
[Repository Contribution README]:../../CONTRIBUTING.md
[SDaccel GUI README]:../../GUIREADME.md
