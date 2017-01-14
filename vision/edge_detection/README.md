Edge Detection
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
Implementation of a Sobel Filter for edge detection.

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
Alpha Data ADM-PCIE-KU3|xilinx:adm-pcie-ku3:2ddr-xpr:3.2|SDAccel 2016.3|nx1


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
|-- _xocc_krnl_sobelfilter_krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1.dir
|   `-- impl
|       |-- build
|       |   |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1_xclbincat.log
|       |   `-- system
|       |       `-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1
|       |           `-- bitstream
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1.xml
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1_ipi
|       |               |   |-- hd_visual
|       |               |   |   |-- pblock_u_ocl_region_AllTiles.tcl
|       |               |   |   |-- pblock_u_ocl_region_FrameTiles.tcl
|       |               |   |   |-- pblock_u_ocl_region_GlitchTiles.tcl
|       |               |   |   `-- pblock_u_ocl_region_RangedSites.tcl
|       |               |   |-- ipiimpl
|       |               |   |   |-- ipiimpl.cache
|       |               |   |   |   `-- wt
|       |               |   |   |       |-- project.wpc
|       |               |   |   |       `-- webtalk_pa.xml
|       |               |   |   |-- ipiimpl.hw
|       |               |   |   |   `-- ipiimpl.lpr
|       |               |   |   |-- ipiimpl.ip_user_files
|       |               |   |   |-- ipiimpl.runs
|       |               |   |   |   `-- impl_1
|       |               |   |   |       |-- ISEWrap.js
|       |               |   |   |       |-- ISEWrap.sh
|       |               |   |   |       |-- gen_run.xml
|       |               |   |   |       |-- hd_visual
|       |               |   |   |       |   |-- blockedBelsRouteThrus.tcl
|       |               |   |   |       |   |-- blockedPins.tcl
|       |               |   |   |       |   |-- blockedSitesInputs.tcl
|       |               |   |   |       |   |-- pblock_u_ocl_region_AllTiles.tcl
|       |               |   |   |       |   |-- pblock_u_ocl_region_FrameTiles.tcl
|       |               |   |   |       |   |-- pblock_u_ocl_region_GlitchTiles.tcl
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
|       |               |   |   |       |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_cc_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_krnl_sobel_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.vds
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |       |-- vivado.jou
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
|       |               |   |   |               |   |-- opencldesign_krnl_sobel_1_0
|       |               |   |   |               |   |   |-- constraints
|       |               |   |   |               |   |   |   `-- krnl_sobel_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_krnl_sobel_1_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_krnl_sobel_1_0.v
|       |               |   |   |               |   |-- opencldesign_m_axi_interconnect_M_AXI_0
|       |               |   |   |               |   |   |-- opencldesign_m_axi_interconnect_M_AXI_0.xci
|       |               |   |   |               |   |   `-- opencldesign_m_axi_interconnect_M_AXI_0.xml
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
|       |               |   |   |               |   |-- opencldesign_s_axi_interconnect_0_0
|       |               |   |   |               |   |   |-- opencldesign_s_axi_interconnect_0_0.xci
|       |               |   |   |               |   |   `-- opencldesign_s_axi_interconnect_0_0.xml
|       |               |   |   |               |   `-- opencldesign_slave_bridge_0
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0.dcp
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0.xci
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0.xml
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0_sim_netlist.v
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0_sim_netlist.vhdl
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0_stub.v
|       |               |   |   |               |       |-- opencldesign_slave_bridge_0_stub.vhdl
|       |               |   |   |               |       |-- sim
|       |               |   |   |               |       |   `-- opencldesign_slave_bridge_0.vhd
|       |               |   |   |               |       `-- synth
|       |               |   |   |               |           `-- opencldesign_slave_bridge_0.vhd
|       |               |   |   |               |-- ipshared
|       |               |   |   |               |   `-- xilinx.com
|       |               |   |   |               |       |-- axi_clock_converter_v2_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- axi_clock_converter_v2_1_axi_clock_converter.v
|       |               |   |   |               |       |           |-- axi_clock_converter_v2_1_axic_sample_cycle_ratio.v
|       |               |   |   |               |       |           `-- axi_clock_converter_v2_1_axic_sync_clock_converter.v
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
|       |               |   |   |               |       |-- axi_utils_v2_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- axi_utils_v2_0_vh_rfs.vhd
|       |               |   |   |               |       |-- blk_mem_gen_v8_3
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- blk_mem_gen_v8_3.vhd
|       |               |   |   |               |       |   |   `-- blk_mem_gen_v8_3_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- blk_mem_gen_v8_3.v
|       |               |   |   |               |       |-- fifo_generator_v13_1
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1.vhd
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.v
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.vhd
|       |               |   |   |               |       |   |   `-- fifo_generator_v13_1_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- fifo_generator_vlog_beh.v
|       |               |   |   |               |       |-- floating_point_v7_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- floating_point_v7_1_vh_rfs.vhd
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
|       |               |   |   |               |       |-- krnl_sobel_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- ip
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|       |               |   |   |               |       |       |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- krnl_sobel.v
|       |               |   |   |               |       |           |-- krnl_sobel_control_s_axi.v
|       |               |   |   |               |       |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|       |               |   |   |               |       |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|       |               |   |   |               |       |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|       |               |   |   |               |       |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|       |               |   |   |               |       |           |-- krnl_sobel_gmem_m_axi.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_31ns_32s_32_7.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_32s_32s_32_7.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_mul_16ns_16ns_32_1.v
|       |               |   |   |               |       |           |-- krnl_sobel_pos_1.v
|       |               |   |   |               |       |           |-- krnl_sobel_pos_1_ram.dat
|       |               |   |   |               |       |           |-- krnl_sobel_resbuf.v
|       |               |   |   |               |       |           |-- krnl_sobel_resbuf_ram.dat
|       |               |   |   |               |       |           `-- krnl_sobel_sitofp_32ns_32_6.v
|       |               |   |   |               |       |-- lib_cdc_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- src
|       |               |   |   |               |       |           `-- vhdl
|       |               |   |   |               |       |               `-- cdc_sync.vhd
|       |               |   |   |               |       |-- mult_gen_v12_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- mult_gen_v12_0.vhd
|       |               |   |   |               |       |       `-- mult_gen_v12_0_vh_rfs.vhd
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
|       |               |   |   |               |       |-- xbip_bram18k_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_bram18k_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_addsub_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_dsp48_addsub_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_multadd_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_dsp48_multadd_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_wrapper_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_pipe_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_pipe_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|       |               |   |   |               |       `-- xbip_utils_v3_0
|       |               |   |   |               |           `-- hdl
|       |               |   |   |               |               `-- xbip_utils_v3_0_vh_rfs.vhd
|       |               |   |   |               |-- opencldesign.bd
|       |               |   |   |               |-- opencldesign.bxml
|       |               |   |   |               `-- opencldesign_ooc.xdc
|       |               |   |   `-- ipiprj.xpr
|       |               |   |-- ipirun.tcl
|       |               |   |-- map.tcl
|       |               |   |-- opencldesign.dcp
|       |               |   |-- opencldesign.xdc
|       |               |   |-- partial.bit
|       |               |   |-- post_init.tcl
|       |               |   |-- vivado.jou
|       |               |   |-- vivado.log
|       |               |   |-- vivado.pb
|       |               |   |-- vivado_9459.backup.log
|       |               |   `-- vivado_user.tcl
|       |               `-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1_regiongen.log
|       `-- kernels
|           `-- krnl_sobel
|               |-- ISEWrap.js
|               |-- ISEWrap.sh
|               |-- htr.txt
|               |-- krnl_sobel
|               |   |-- hls_transform.tcl
|               |   |-- ip
|               |   |   |-- autoimpl.log
|               |   |   |-- auxiliary.xml
|               |   |   |-- bd
|               |   |   |-- component.xml
|               |   |   |-- constraints
|               |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |-- doc
|               |   |   |   `-- ReleaseNotes.txt
|               |   |   |-- drivers
|               |   |   |   `-- krnl_sobel_v1_0
|               |   |   |       |-- data
|               |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |       `-- src
|               |   |   |           |-- Makefile
|               |   |   |           |-- xkrnl_sobel.c
|               |   |   |           |-- xkrnl_sobel.h
|               |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |-- example
|               |   |   |   |-- ipi_example.sh
|               |   |   |   `-- ipi_example.tcl
|               |   |   |-- hdl
|               |   |   |   |-- ip
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |-- verilog
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   `-- vhdl
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_1.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |-- krnl_sobel_info.xml
|               |   |   |-- misc
|               |   |   |   `-- logo.png
|               |   |   |-- pack.sh
|               |   |   |-- run_ippack.tcl
|               |   |   |-- subcore
|               |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |-- tmp.cache
|               |   |   |   `-- wt
|               |   |   |       `-- project.wpc
|               |   |   |-- tmp.hw
|               |   |   |   `-- tmp.lpr
|               |   |   |-- tmp.ip_user_files
|               |   |   |-- tmp.srcs
|               |   |   |   `-- sources_1
|               |   |   |       `-- ip
|               |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |               |-- axi_utils_v2_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |               |-- floating_point_v7_1_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |               |-- mult_gen_v12_0_11
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |               |-- sim
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- synth
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |                   `-- hdl
|               |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |-- tmp.xpr
|               |   |   |-- vivado.jou
|               |   |   |-- vivado.log
|               |   |   |-- xgui
|               |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |-- kernel.xml
|               |   |-- krnl_sobel.clc.00.bc
|               |   |-- krnl_sobel.design.xml
|               |   |-- krnl_sobel_clang.log
|               |   |-- krnl_sobel_hls_transform.log
|               |   |-- krnl_sobel_kernelinfohash.log
|               |   |-- solution_OCL_REGION_0
|               |   |   |-- impl
|               |   |   |   |-- ip
|               |   |   |   |   |-- autoimpl.log
|               |   |   |   |   |-- auxiliary.xml
|               |   |   |   |   |-- bd
|               |   |   |   |   |-- component.xml
|               |   |   |   |   |-- constraints
|               |   |   |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |   |   |-- doc
|               |   |   |   |   |   `-- ReleaseNotes.txt
|               |   |   |   |   |-- drivers
|               |   |   |   |   |   `-- krnl_sobel_v1_0
|               |   |   |   |   |       |-- data
|               |   |   |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |   |   |       `-- src
|               |   |   |   |   |           |-- Makefile
|               |   |   |   |   |           |-- xkrnl_sobel.c
|               |   |   |   |   |           |-- xkrnl_sobel.h
|               |   |   |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |   |   |-- example
|               |   |   |   |   |   |-- ipi_example.sh
|               |   |   |   |   |   `-- ipi_example.tcl
|               |   |   |   |   |-- hdl
|               |   |   |   |   |   |-- ip
|               |   |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |   |-- verilog
|               |   |   |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |   `-- vhdl
|               |   |   |   |   |       |-- krnl_sobel.vhd
|               |   |   |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |   |   |-- krnl_sobel_info.xml
|               |   |   |   |   |-- misc
|               |   |   |   |   |   `-- logo.png
|               |   |   |   |   |-- pack.sh
|               |   |   |   |   |-- run_ippack.tcl
|               |   |   |   |   |-- subcore
|               |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- tmp.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- tmp.hw
|               |   |   |   |   |   `-- tmp.lpr
|               |   |   |   |   |-- tmp.ip_user_files
|               |   |   |   |   |-- tmp.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- tmp.xpr
|               |   |   |   |   |-- vivado.jou
|               |   |   |   |   |-- vivado.log
|               |   |   |   |   |-- xgui
|               |   |   |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |   |   |-- sdaccel
|               |   |   |   |   |-- kernel.xml
|               |   |   |   |   `-- kernel.xo
|               |   |   |   |-- verilog
|               |   |   |   |   |-- extraction.tcl
|               |   |   |   |   |-- impl.sh
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel.xdc
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |-- project.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- project.hw
|               |   |   |   |   |   `-- project.lpr
|               |   |   |   |   |-- project.ip_user_files
|               |   |   |   |   |-- project.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- project.xpr
|               |   |   |   |   |-- run_vivado.tcl
|               |   |   |   |   `-- settings.tcl
|               |   |   |   `-- vhdl
|               |   |   |       |-- extraction.tcl
|               |   |   |       |-- impl.sh
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel.xdc
|               |   |   |       |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_1.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       |-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |       |-- project.cache
|               |   |   |       |   `-- wt
|               |   |   |       |       `-- project.wpc
|               |   |   |       |-- project.hw
|               |   |   |       |   `-- project.lpr
|               |   |   |       |-- project.ip_user_files
|               |   |   |       |-- project.srcs
|               |   |   |       |   `-- sources_1
|               |   |   |       |       `-- ip
|               |   |   |       |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |       |               |-- axi_utils_v2_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |               |-- floating_point_v7_1_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |       |               |-- mult_gen_v12_0_11
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- mult_gen_v12_0.vhd
|               |   |   |       |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |               |-- sim
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- synth
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- xbip_bram18k_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_pipe_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |               `-- xbip_utils_v3_0_6
|               |   |   |       |                   `-- hdl
|               |   |   |       |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |-- project.xpr
|               |   |   |       |-- run_vivado.tcl
|               |   |   |       `-- settings.tcl
|               |   |   |-- solution_OCL_REGION_0.aps
|               |   |   |-- solution_OCL_REGION_0.directive
|               |   |   |-- solution_OCL_REGION_0.log
|               |   |   `-- syn
|               |   |       |-- report
|               |   |       |   |-- krnl_sobel_csynth.rpt
|               |   |       |   `-- krnl_sobel_csynth.xml
|               |   |       |-- systemc
|               |   |       |   |-- ACMP_faddfsub.h
|               |   |       |   |-- ACMP_fcmp_comb.h
|               |   |       |   |-- ACMP_fdiv.h
|               |   |       |   |-- ACMP_fmul.h
|               |   |       |   |-- ACMP_mul_ss.h
|               |   |       |   |-- ACMP_mul_us.h
|               |   |       |   |-- ACMP_sitofp.h
|               |   |       |   |-- ACMP_smul_uu.h
|               |   |       |   |-- AESL_pkg.h
|               |   |       |   |-- krnl_sobel.h
|               |   |       |   |-- krnl_sobel_1.cpp
|               |   |       |   |-- krnl_sobel_10.cpp
|               |   |       |   |-- krnl_sobel_11.cpp
|               |   |       |   |-- krnl_sobel_12.cpp
|               |   |       |   |-- krnl_sobel_13.cpp
|               |   |       |   |-- krnl_sobel_14.cpp
|               |   |       |   |-- krnl_sobel_15.cpp
|               |   |       |   |-- krnl_sobel_2.cpp
|               |   |       |   |-- krnl_sobel_3.cpp
|               |   |       |   |-- krnl_sobel_4.cpp
|               |   |       |   |-- krnl_sobel_5.cpp
|               |   |       |   |-- krnl_sobel_6.cpp
|               |   |       |   |-- krnl_sobel_7.cpp
|               |   |       |   |-- krnl_sobel_8.cpp
|               |   |       |   |-- krnl_sobel_9.cpp
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.h
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.h
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.h
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.h
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_1.h
|               |   |       |   |-- krnl_sobel_pos_1.h
|               |   |       |   |-- krnl_sobel_resbuf.h
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.h
|               |   |       |-- verilog
|               |   |       |   |-- krnl_sobel.v
|               |   |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_control_s_axi.v
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |       |   |-- krnl_sobel_gmem_m_axi.v
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_1.v
|               |   |       |   |-- krnl_sobel_pos_1.v
|               |   |       |   |-- krnl_sobel_pos_1_ram.dat
|               |   |       |   |-- krnl_sobel_resbuf.v
|               |   |       |   |-- krnl_sobel_resbuf_ram.dat
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |       `-- vhdl
|               |   |           |-- krnl_sobel.vhd
|               |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_control_s_axi.vhd
|               |   |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |           |-- krnl_sobel_gmem_m_axi.vhd
|               |   |           |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_mul_16ns_16ns_32_1.vhd
|               |   |           |-- krnl_sobel_pos_1.vhd
|               |   |           |-- krnl_sobel_resbuf.vhd
|               |   |           `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |-- vivado_hls.app
|               |   `-- vivado_hls.log
|               |-- krnl_sobel.tcl
|               |-- rundef.js
|               |-- runme.bat
|               |-- runme.log
|               |-- runme.sh
|               `-- vivado_hls.log
|-- _xocc_krnl_sobelfilter_krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1.dir
|   `-- impl
|       |-- build
|       |   |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1_xclbincat.log
|       |   `-- system
|       |       `-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1
|       |           `-- bitstream
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1.xml
|       |               |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1_ipi
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
|       |               |   |   |       |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_auto_cc_1_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_kernel_sys_reset_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_krnl_sobel_1_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- dont_touch.xdc
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.dcp
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.tcl
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0.vds
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_krnl_sobel_1_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   |-- vivado.pb
|       |               |   |   |   |   `-- xgd_oracle_744FFBB
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
|       |               |   |   |   |   `-- vivado.pb
|       |               |   |   |   |-- opencldesign_xlconstant_zero_34_0_synth_1
|       |               |   |   |   |   |-- ISEWrap.js
|       |               |   |   |   |   |-- ISEWrap.sh
|       |               |   |   |   |   |-- gen_run.xml
|       |               |   |   |   |   |-- htr.txt
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_34_0.dcp
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_34_0.tcl
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_34_0.vds
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_34_0_utilization_synth.pb
|       |               |   |   |   |   |-- opencldesign_xlconstant_zero_34_0_utilization_synth.rpt
|       |               |   |   |   |   |-- rundef.js
|       |               |   |   |   |   |-- runme.bat
|       |               |   |   |   |   |-- runme.log
|       |               |   |   |   |   |-- runme.sh
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |   |   |-- vivado.jou
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
|       |               |   |   |       |-- vivado.jou
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
|       |               |   |   |               |   |-- opencldesign_krnl_sobel_1_0
|       |               |   |   |               |   |   |-- constraints
|       |               |   |   |               |   |   |   `-- krnl_sobel_ooc.xdc
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xci
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xml
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0_stub.vhdl
|       |               |   |   |               |   |   |-- sim
|       |               |   |   |               |   |   |   `-- opencldesign_krnl_sobel_1_0.vhd
|       |               |   |   |               |   |   `-- synth
|       |               |   |   |               |   |       `-- opencldesign_krnl_sobel_1_0.v
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
|       |               |   |   |               |   |-- opencldesign_xlconstant_zero_34_0
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0.dcp
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0.xci
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0.xml
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0_sim_netlist.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0_sim_netlist.vhdl
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0_stub.v
|       |               |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0_stub.vhdl
|       |               |   |   |               |   |   `-- sim
|       |               |   |   |               |   |       `-- opencldesign_xlconstant_zero_34_0.v
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
|       |               |   |   |               |       |-- axi_utils_v2_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- axi_utils_v2_0_vh_rfs.vhd
|       |               |   |   |               |       |-- blk_mem_gen_v8_3
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- blk_mem_gen_v8_3.vhd
|       |               |   |   |               |       |   |   `-- blk_mem_gen_v8_3_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- blk_mem_gen_v8_3.v
|       |               |   |   |               |       |-- fifo_generator_v13_1
|       |               |   |   |               |       |   |-- hdl
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1.vhd
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.v
|       |               |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.vhd
|       |               |   |   |               |       |   |   `-- fifo_generator_v13_1_vhsyn_rfs.vhd
|       |               |   |   |               |       |   `-- simulation
|       |               |   |   |               |       |       `-- fifo_generator_vlog_beh.v
|       |               |   |   |               |       |-- floating_point_v7_1
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- floating_point_v7_1_vh_rfs.vhd
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
|       |               |   |   |               |       |-- krnl_sobel_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- ip
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|       |               |   |   |               |       |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|       |               |   |   |               |       |       |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|       |               |   |   |               |       |       `-- verilog
|       |               |   |   |               |       |           |-- krnl_sobel.v
|       |               |   |   |               |       |           |-- krnl_sobel_control_s_axi.v
|       |               |   |   |               |       |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|       |               |   |   |               |       |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|       |               |   |   |               |       |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|       |               |   |   |               |       |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|       |               |   |   |               |       |           |-- krnl_sobel_gmem_m_axi.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_31ns_32s_32_7.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_32s_32s_32_7.v
|       |               |   |   |               |       |           |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|       |               |   |   |               |       |           |-- krnl_sobel_pos_1.v
|       |               |   |   |               |       |           |-- krnl_sobel_pos_1_ram.dat
|       |               |   |   |               |       |           |-- krnl_sobel_resbuf.v
|       |               |   |   |               |       |           |-- krnl_sobel_resbuf_ram.dat
|       |               |   |   |               |       |           `-- krnl_sobel_sitofp_32ns_32_6.v
|       |               |   |   |               |       |-- lib_cdc_v1_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- src
|       |               |   |   |               |       |           `-- vhdl
|       |               |   |   |               |       |               `-- cdc_sync.vhd
|       |               |   |   |               |       |-- mult_gen_v12_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- mult_gen_v12_0.vhd
|       |               |   |   |               |       |       `-- mult_gen_v12_0_vh_rfs.vhd
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
|       |               |   |   |               |       |-- xbip_bram18k_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_bram18k_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_addsub_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_dsp48_addsub_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_multadd_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_dsp48_multadd_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_dsp48_wrapper_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_pipe_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       |-- xbip_pipe_v3_0.vhd
|       |               |   |   |               |       |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|       |               |   |   |               |       |-- xbip_utils_v3_0
|       |               |   |   |               |       |   `-- hdl
|       |               |   |   |               |       |       `-- xbip_utils_v3_0_vh_rfs.vhd
|       |               |   |   |               |       `-- xlconstant_v1_1
|       |               |   |   |               |           `-- xlconstant.v
|       |               |   |   |               |-- opencldesign.bd
|       |               |   |   |               |-- opencldesign.bxml
|       |               |   |   |               `-- opencldesign_ooc.xdc
|       |               |   |   `-- ipiprj.xpr
|       |               |   |-- ipirun.tcl
|       |               |   |-- map.tcl
|       |               |   |-- opencldesign.dcp
|       |               |   |-- opencldesign.xdc
|       |               |   |-- partial.bit
|       |               |   |-- partial_clear.bit
|       |               |   |-- post_init.tcl
|       |               |   |-- vivado.jou
|       |               |   |-- vivado.log
|       |               |   |-- vivado.pb
|       |               |   |-- vivado_24377.backup.log
|       |               |   `-- vivado_user.tcl
|       |               `-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1_regiongen.log
|       `-- kernels
|           `-- krnl_sobel
|               |-- ISEWrap.js
|               |-- ISEWrap.sh
|               |-- htr.txt
|               |-- krnl_sobel
|               |   |-- hls_transform.tcl
|               |   |-- ip
|               |   |   |-- autoimpl.log
|               |   |   |-- auxiliary.xml
|               |   |   |-- bd
|               |   |   |-- component.xml
|               |   |   |-- constraints
|               |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |-- doc
|               |   |   |   `-- ReleaseNotes.txt
|               |   |   |-- drivers
|               |   |   |   `-- krnl_sobel_v1_0
|               |   |   |       |-- data
|               |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |       `-- src
|               |   |   |           |-- Makefile
|               |   |   |           |-- xkrnl_sobel.c
|               |   |   |           |-- xkrnl_sobel.h
|               |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |-- example
|               |   |   |   |-- ipi_example.sh
|               |   |   |   `-- ipi_example.tcl
|               |   |   |-- hdl
|               |   |   |   |-- ip
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |-- verilog
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   `-- vhdl
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |-- krnl_sobel_info.xml
|               |   |   |-- misc
|               |   |   |   `-- logo.png
|               |   |   |-- pack.sh
|               |   |   |-- run_ippack.tcl
|               |   |   |-- subcore
|               |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |-- tmp.cache
|               |   |   |   `-- wt
|               |   |   |       `-- project.wpc
|               |   |   |-- tmp.hw
|               |   |   |   `-- tmp.lpr
|               |   |   |-- tmp.ip_user_files
|               |   |   |-- tmp.srcs
|               |   |   |   `-- sources_1
|               |   |   |       `-- ip
|               |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |               |-- axi_utils_v2_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |               |-- floating_point_v7_1_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |               |-- mult_gen_v12_0_11
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |               |-- sim
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- synth
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |                   `-- hdl
|               |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |-- tmp.xpr
|               |   |   |-- vivado.jou
|               |   |   |-- vivado.log
|               |   |   |-- xgui
|               |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |-- kernel.xml
|               |   |-- krnl_sobel.clc.00.bc
|               |   |-- krnl_sobel.design.xml
|               |   |-- krnl_sobel_clang.log
|               |   |-- krnl_sobel_hls_transform.log
|               |   |-- krnl_sobel_kernelinfohash.log
|               |   |-- solution_OCL_REGION_0
|               |   |   |-- impl
|               |   |   |   |-- ip
|               |   |   |   |   |-- autoimpl.log
|               |   |   |   |   |-- auxiliary.xml
|               |   |   |   |   |-- bd
|               |   |   |   |   |-- component.xml
|               |   |   |   |   |-- constraints
|               |   |   |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |   |   |-- doc
|               |   |   |   |   |   `-- ReleaseNotes.txt
|               |   |   |   |   |-- drivers
|               |   |   |   |   |   `-- krnl_sobel_v1_0
|               |   |   |   |   |       |-- data
|               |   |   |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |   |   |       `-- src
|               |   |   |   |   |           |-- Makefile
|               |   |   |   |   |           |-- xkrnl_sobel.c
|               |   |   |   |   |           |-- xkrnl_sobel.h
|               |   |   |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |   |   |-- example
|               |   |   |   |   |   |-- ipi_example.sh
|               |   |   |   |   |   `-- ipi_example.tcl
|               |   |   |   |   |-- hdl
|               |   |   |   |   |   |-- ip
|               |   |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |   |-- verilog
|               |   |   |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |   `-- vhdl
|               |   |   |   |   |       |-- krnl_sobel.vhd
|               |   |   |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |   |   |-- krnl_sobel_info.xml
|               |   |   |   |   |-- misc
|               |   |   |   |   |   `-- logo.png
|               |   |   |   |   |-- pack.sh
|               |   |   |   |   |-- run_ippack.tcl
|               |   |   |   |   |-- subcore
|               |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- tmp.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- tmp.hw
|               |   |   |   |   |   `-- tmp.lpr
|               |   |   |   |   |-- tmp.ip_user_files
|               |   |   |   |   |-- tmp.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- tmp.xpr
|               |   |   |   |   |-- vivado.jou
|               |   |   |   |   |-- vivado.log
|               |   |   |   |   |-- xgui
|               |   |   |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |   |   |-- sdaccel
|               |   |   |   |   |-- kernel.xml
|               |   |   |   |   `-- kernel.xo
|               |   |   |   |-- verilog
|               |   |   |   |   |-- extraction.tcl
|               |   |   |   |   |-- impl.sh
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel.xdc
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |-- project.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- project.hw
|               |   |   |   |   |   `-- project.lpr
|               |   |   |   |   |-- project.ip_user_files
|               |   |   |   |   |-- project.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- project.xpr
|               |   |   |   |   |-- run_vivado.tcl
|               |   |   |   |   `-- settings.tcl
|               |   |   |   `-- vhdl
|               |   |   |       |-- extraction.tcl
|               |   |   |       |-- impl.sh
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel.xdc
|               |   |   |       |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       |-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |       |-- project.cache
|               |   |   |       |   `-- wt
|               |   |   |       |       `-- project.wpc
|               |   |   |       |-- project.hw
|               |   |   |       |   `-- project.lpr
|               |   |   |       |-- project.ip_user_files
|               |   |   |       |-- project.srcs
|               |   |   |       |   `-- sources_1
|               |   |   |       |       `-- ip
|               |   |   |       |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |       |               |-- axi_utils_v2_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |               |-- floating_point_v7_1_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |       |               |-- mult_gen_v12_0_11
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- mult_gen_v12_0.vhd
|               |   |   |       |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |               |-- sim
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- synth
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- xbip_bram18k_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_pipe_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |               `-- xbip_utils_v3_0_6
|               |   |   |       |                   `-- hdl
|               |   |   |       |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |-- project.xpr
|               |   |   |       |-- run_vivado.tcl
|               |   |   |       `-- settings.tcl
|               |   |   |-- solution_OCL_REGION_0.aps
|               |   |   |-- solution_OCL_REGION_0.directive
|               |   |   |-- solution_OCL_REGION_0.log
|               |   |   `-- syn
|               |   |       |-- report
|               |   |       |   |-- krnl_sobel_csynth.rpt
|               |   |       |   `-- krnl_sobel_csynth.xml
|               |   |       |-- systemc
|               |   |       |   |-- ACMP_faddfsub.h
|               |   |       |   |-- ACMP_fcmp_comb.h
|               |   |       |   |-- ACMP_fdiv.h
|               |   |       |   |-- ACMP_fmul.h
|               |   |       |   |-- ACMP_mul_ss.h
|               |   |       |   |-- ACMP_mul_us.h
|               |   |       |   |-- ACMP_mul_uu.h
|               |   |       |   |-- ACMP_sitofp.h
|               |   |       |   |-- AESL_pkg.h
|               |   |       |   |-- krnl_sobel.h
|               |   |       |   |-- krnl_sobel_1.cpp
|               |   |       |   |-- krnl_sobel_10.cpp
|               |   |       |   |-- krnl_sobel_11.cpp
|               |   |       |   |-- krnl_sobel_12.cpp
|               |   |       |   |-- krnl_sobel_13.cpp
|               |   |       |   |-- krnl_sobel_14.cpp
|               |   |       |   |-- krnl_sobel_15.cpp
|               |   |       |   |-- krnl_sobel_2.cpp
|               |   |       |   |-- krnl_sobel_3.cpp
|               |   |       |   |-- krnl_sobel_4.cpp
|               |   |       |   |-- krnl_sobel_5.cpp
|               |   |       |   |-- krnl_sobel_6.cpp
|               |   |       |   |-- krnl_sobel_7.cpp
|               |   |       |   |-- krnl_sobel_8.cpp
|               |   |       |   |-- krnl_sobel_9.cpp
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.h
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.h
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.h
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.h
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.h
|               |   |       |   |-- krnl_sobel_pos_1.h
|               |   |       |   |-- krnl_sobel_resbuf.h
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.h
|               |   |       |-- verilog
|               |   |       |   |-- krnl_sobel.v
|               |   |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_control_s_axi.v
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |       |   |-- krnl_sobel_gmem_m_axi.v
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |       |   |-- krnl_sobel_pos_1.v
|               |   |       |   |-- krnl_sobel_pos_1_ram.dat
|               |   |       |   |-- krnl_sobel_resbuf.v
|               |   |       |   |-- krnl_sobel_resbuf_ram.dat
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |       `-- vhdl
|               |   |           |-- krnl_sobel.vhd
|               |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_control_s_axi.vhd
|               |   |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |           |-- krnl_sobel_gmem_m_axi.vhd
|               |   |           |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |           |-- krnl_sobel_pos_1.vhd
|               |   |           |-- krnl_sobel_resbuf.vhd
|               |   |           `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |-- vivado_hls.app
|               |   `-- vivado_hls.log
|               |-- krnl_sobel.tcl
|               |-- rundef.js
|               |-- runme.bat
|               |-- runme.log
|               |-- runme.sh
|               `-- vivado_hls.log
|-- _xocc_krnl_sobelfilter_krnl_edge.hw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.dir
|   `-- impl
|       |-- build
|       `-- kernels
|           `-- krnl_sobel
|               `-- krnl_sobel
|                   |-- hls_transform.tcl
|                   |-- kernel.xml
|                   |-- krnl_sobel.clc.00.bc
|                   |-- krnl_sobel_clang.log
|                   |-- krnl_sobel_hls_transform.log
|                   `-- vivado_hls.log
|-- _xocc_krnl_sobelfilter_krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.dir
|   `-- impl
|       |-- build
|       |   |-- hw_em
|       |   |   `-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1
|       |   |       `-- sv
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.gpp_so.log
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.ipiMapping
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.so
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xml
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_ipi
|       |   |           |   |-- ipiprj
|       |   |           |   |   |-- ipiprj.cache
|       |   |           |   |   |   `-- wt
|       |   |           |   |   |       |-- project.wpc
|       |   |           |   |   |       `-- xsim.wdf
|       |   |           |   |   |-- ipiprj.hw
|       |   |           |   |   |   `-- ipiprj.lpr
|       |   |           |   |   |-- ipiprj.ip_user_files
|       |   |           |   |   |   |-- README.txt
|       |   |           |   |   |   |-- bd
|       |   |           |   |   |   |   `-- opencldesign
|       |   |           |   |   |   |       |-- hdl
|       |   |           |   |   |   |       |   `-- opencldesign.v
|       |   |           |   |   |   |       |-- ip
|       |   |           |   |   |   |       |   |-- opencldesign_auto_cc_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_auto_cc_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_auto_cc_1
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_auto_cc_1.v
|       |   |           |   |   |   |       |   |-- opencldesign_auto_us_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_auto_us_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_c0_ddr_clk_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_c0_ddr_clk_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_c0_kernel_clk_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_c0_kernel_clk_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_c0_ui_clk_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_c0_ui_clk_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_c1_ddr_clk_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_c1_ddr_clk_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_krnl_sobel_1_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_krnl_sobel_1_0.vhd
|       |   |           |   |   |   |       |   |-- opencldesign_master_bridge_0_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_master_bridge_0_0.vhd
|       |   |           |   |   |   |       |   |-- opencldesign_master_bridge_1_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_master_bridge_1_0.vhd
|       |   |           |   |   |   |       |   |-- opencldesign_s00_regslice_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_s00_regslice_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_sdaccel_generic_pcie_0_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_sdaccel_generic_pcie_0_0.sv
|       |   |           |   |   |   |       |   |-- opencldesign_slave_bridge_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_slave_bridge_0.vhd
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_1_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_1_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_2_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_2_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_34_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_34_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_3_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_3_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_4_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_4_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_512_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_512_0.v
|       |   |           |   |   |   |       |   |-- opencldesign_xlconstant_zero_64_0
|       |   |           |   |   |   |       |   |   `-- sim
|       |   |           |   |   |   |       |   |       `-- opencldesign_xlconstant_zero_64_0.v
|       |   |           |   |   |   |       |   `-- opencldesign_xlconstant_zero_8_0
|       |   |           |   |   |   |       |       `-- sim
|       |   |           |   |   |   |       |           `-- opencldesign_xlconstant_zero_8_0.v
|       |   |           |   |   |   |       `-- ipshared
|       |   |           |   |   |   |           `-- xilinx.com
|       |   |           |   |   |   |               |-- clk_gen_v1_0
|       |   |           |   |   |   |               |   `-- hdl
|       |   |           |   |   |   |               |       `-- clk_gen.v
|       |   |           |   |   |   |               |-- krnl_sobel_v1_0
|       |   |           |   |   |   |               |   `-- hdl
|       |   |           |   |   |   |               |       `-- verilog
|       |   |           |   |   |   |               |           |-- krnl_sobel_pos_1_ram.dat
|       |   |           |   |   |   |               |           `-- krnl_sobel_resbuf_ram.dat
|       |   |           |   |   |   |               |-- ocl_axifull_bridge_v1_0
|       |   |           |   |   |   |               |   `-- hdl
|       |   |           |   |   |   |               |       `-- axifull_bridge.vhd
|       |   |           |   |   |   |               |-- ocl_axilite_bridge_v1_0
|       |   |           |   |   |   |               |   `-- hdl
|       |   |           |   |   |   |               |       `-- axilite_bridge.vhd
|       |   |           |   |   |   |               |-- sdaccel_generic_pcie_v1_0
|       |   |           |   |   |   |               |   `-- sim
|       |   |           |   |   |   |               |       `-- cmodel
|       |   |           |   |   |   |               |           |-- libperformance_monitor.so
|       |   |           |   |   |   |               |           `-- libsdaccel_generic_pcie.so
|       |   |           |   |   |   |               `-- xlconstant_v1_1
|       |   |           |   |   |   |                   `-- xlconstant.v
|       |   |           |   |   |   |-- ipstatic
|       |   |           |   |   |   |   |-- axi_clock_converter_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_clock_converter_v2_1_axi_clock_converter.v
|       |   |           |   |   |   |   |           |-- axi_clock_converter_v2_1_axic_sample_cycle_ratio.v
|       |   |           |   |   |   |   |           `-- axi_clock_converter_v2_1_axic_sync_clock_converter.v
|       |   |           |   |   |   |   |-- axi_data_fifo_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_data_fifo_v2_1_axi_data_fifo.v
|       |   |           |   |   |   |   |           |-- axi_data_fifo_v2_1_axic_fifo.v
|       |   |           |   |   |   |   |           |-- axi_data_fifo_v2_1_axic_reg_srl_fifo.v
|       |   |           |   |   |   |   |           |-- axi_data_fifo_v2_1_axic_srl_fifo.v
|       |   |           |   |   |   |   |           |-- axi_data_fifo_v2_1_fifo_gen.v
|       |   |           |   |   |   |   |           `-- axi_data_fifo_v2_1_ndeep_srl.v
|       |   |           |   |   |   |   |-- axi_dwidth_converter_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_a_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_a_upsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_axi4lite_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_axi4lite_upsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_axi_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_axi_upsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_b_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_r_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_r_upsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_r_upsizer_pktfifo.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_top.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_w_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_dwidth_converter_v2_1_w_upsizer.v
|       |   |           |   |   |   |   |           `-- axi_dwidth_converter_v2_1_w_upsizer_pktfifo.v
|       |   |           |   |   |   |   |-- axi_infrastructure_v1_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_infrastructure_v1_1_0_header.vh
|       |   |           |   |   |   |   |           |-- axi_infrastructure_v1_1_axi2vector.v
|       |   |           |   |   |   |   |           |-- axi_infrastructure_v1_1_axic_srl_fifo.v
|       |   |           |   |   |   |   |           `-- axi_infrastructure_v1_1_vector2axi.v
|       |   |           |   |   |   |   |-- axi_protocol_converter_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_a_axi3_conv.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_axi3_conv.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_axi_protocol_converter.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_axilite_conv.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_ar_channel.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_aw_channel.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_b_channel.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_cmd_translator.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_incr_cmd.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_r_channel.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_simple_fifo.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b2s_wrap_cmd.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_b_downsizer.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_decerr_slave.v
|       |   |           |   |   |   |   |           |-- axi_protocol_converter_v2_1_r_axi3_conv.v
|       |   |           |   |   |   |   |           `-- axi_protocol_converter_v2_1_w_axi3_conv.v
|       |   |           |   |   |   |   |-- axi_register_slice_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- axi_register_slice_v2_1_axi_register_slice.v
|       |   |           |   |   |   |   |           `-- axi_register_slice_v2_1_axic_register_slice.v
|       |   |           |   |   |   |   |-- axi_utils_v2_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- blk_mem_gen_v8_3
|       |   |           |   |   |   |   |   `-- simulation
|       |   |           |   |   |   |   |       `-- blk_mem_gen_v8_3.v
|       |   |           |   |   |   |   |-- fifo_generator_v13_1
|       |   |           |   |   |   |   |   |-- hdl
|       |   |           |   |   |   |   |   |   |-- fifo_generator_v13_1_rfs.v
|       |   |           |   |   |   |   |   |   `-- fifo_generator_v13_1_rfs.vhd
|       |   |           |   |   |   |   |   `-- simulation
|       |   |           |   |   |   |   |       `-- fifo_generator_vlog_beh.v
|       |   |           |   |   |   |   |-- floating_point_v7_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- floating_point_v7_1_vh_rfs.vhd
|       |   |           |   |   |   |   |-- generic_baseblocks_v2_1
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_carry.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_carry_and.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_carry_latch_and.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_carry_latch_or.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_carry_or.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_command_fifo.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_mask.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_mask_static.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_sel.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_sel_mask.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_sel_mask_static.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_sel_static.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_comparator_static.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_mux.v
|       |   |           |   |   |   |   |           |-- generic_baseblocks_v2_1_mux_enc.v
|       |   |           |   |   |   |   |           `-- generic_baseblocks_v2_1_nto1_mux.v
|       |   |           |   |   |   |   |-- krnl_sobel_v1_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- ip
|       |   |           |   |   |   |   |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|       |   |           |   |   |   |   |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|       |   |           |   |   |   |   |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|       |   |           |   |   |   |   |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|       |   |           |   |   |   |   |       |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|       |   |           |   |   |   |   |       `-- verilog
|       |   |           |   |   |   |   |           |-- krnl_sobel.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_control_s_axi.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_gmem_m_axi.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_mul_31ns_32s_32_7.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_mul_32s_32s_32_7.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_pos_1.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_pos_1_ram.dat
|       |   |           |   |   |   |   |           |-- krnl_sobel_resbuf.v
|       |   |           |   |   |   |   |           |-- krnl_sobel_resbuf_ram.dat
|       |   |           |   |   |   |   |           `-- krnl_sobel_sitofp_32ns_32_6.v
|       |   |           |   |   |   |   |-- mult_gen_v12_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- mult_gen_v12_0.vhd
|       |   |           |   |   |   |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- xbip_bram18k_v3_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- xbip_bram18k_v3_0.vhd
|       |   |           |   |   |   |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- xbip_dsp48_addsub_v3_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|       |   |           |   |   |   |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- xbip_dsp48_multadd_v3_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|       |   |           |   |   |   |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- xbip_dsp48_wrapper_v3_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|       |   |           |   |   |   |   |-- xbip_pipe_v3_0
|       |   |           |   |   |   |   |   `-- hdl
|       |   |           |   |   |   |   |       |-- xbip_pipe_v3_0.vhd
|       |   |           |   |   |   |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|       |   |           |   |   |   |   `-- xbip_utils_v3_0
|       |   |           |   |   |   |       `-- hdl
|       |   |           |   |   |   |           `-- xbip_utils_v3_0_vh_rfs.vhd
|       |   |           |   |   |   `-- mem_init_files
|       |   |           |   |   |       |-- krnl_sobel_pos_1_ram.dat
|       |   |           |   |   |       `-- krnl_sobel_resbuf_ram.dat
|       |   |           |   |   |-- ipiprj.sim
|       |   |           |   |   |   `-- sim_1
|       |   |           |   |   |       |-- behav
|       |   |           |   |   |       |   |-- compile.log
|       |   |           |   |   |       |   |-- compile.sh
|       |   |           |   |   |       |   |-- elaborate.log
|       |   |           |   |   |       |   |-- elaborate.sh
|       |   |           |   |   |       |   |-- elaborate_sysemulation.sh
|       |   |           |   |   |       |   |-- glbl.v
|       |   |           |   |   |       |   |-- krnl_sobel_pos_1_ram.dat
|       |   |           |   |   |       |   |-- krnl_sobel_resbuf_ram.dat
|       |   |           |   |   |       |   |-- libperformance_monitor.so
|       |   |           |   |   |       |   |-- libsdaccel_generic_pcie.so
|       |   |           |   |   |       |   |-- libsls.so
|       |   |           |   |   |       |   |-- opencldesign.tcl
|       |   |           |   |   |       |   |-- opencldesign_vhdl.prj
|       |   |           |   |   |       |   |-- opencldesign_vlog.prj
|       |   |           |   |   |       |   |-- simulate.log
|       |   |           |   |   |       |   |-- simulate.sh
|       |   |           |   |   |       |   |-- simulate_sysemulation.sh
|       |   |           |   |   |       |   |-- xelab.pb
|       |   |           |   |   |       |   |-- xsim.dir
|       |   |           |   |   |       |   |   |-- axi_clock_converter_v2_1_7
|       |   |           |   |   |       |   |   |   |-- axi_clock_converter_v2_1_7.rlx
|       |   |           |   |   |       |   |   |   |-- axi_clock_converter_v2_1_7_axi_clock_converter.sdb
|       |   |           |   |   |       |   |   |   |-- axi_clock_converter_v2_1_7_axic_sample_cycle_ratio.sdb
|       |   |           |   |   |       |   |   |   `-- axi_clock_converter_v2_1_7_axic_sync_clock_converter.sdb
|       |   |           |   |   |       |   |   |-- axi_data_fifo_v2_1_7
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7.rlx
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7_axi_data_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7_axic_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7_axic_reg_srl_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7_axic_srl_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_data_fifo_v2_1_7_fifo_gen.sdb
|       |   |           |   |   |       |   |   |   `-- axi_data_fifo_v2_1_7_ndeep_srl.sdb
|       |   |           |   |   |       |   |   |-- axi_dwidth_converter_v2_1_8
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8.rlx
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_a_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_a_upsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_axi4lite_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_axi4lite_upsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_axi_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_axi_upsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_b_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_r_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_r_upsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_r_upsizer_pktfifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_top.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_w_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_dwidth_converter_v2_1_8_w_upsizer.sdb
|       |   |           |   |   |       |   |   |   `-- axi_dwidth_converter_v2_1_8_w_upsizer_pktfifo.sdb
|       |   |           |   |   |       |   |   |-- axi_infrastructure_v1_1_0
|       |   |           |   |   |       |   |   |   |-- axi_infrastructure_v1_1_0.rlx
|       |   |           |   |   |       |   |   |   |-- axi_infrastructure_v1_1_0_axi2vector.sdb
|       |   |           |   |   |       |   |   |   |-- axi_infrastructure_v1_1_0_axic_srl_fifo.sdb
|       |   |           |   |   |       |   |   |   `-- axi_infrastructure_v1_1_0_vector2axi.sdb
|       |   |           |   |   |       |   |   |-- axi_protocol_converter_v2_1_8
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8.rlx
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_a_axi3_conv.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_axi3_conv.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_axi_protocol_converter.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_axilite_conv.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_ar_channel.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_aw_channel.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_b_channel.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_cmd_translator.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_incr_cmd.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_r_channel.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_rd_cmd_fsm.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_simple_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_wr_cmd_fsm.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b2s_wrap_cmd.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_b_downsizer.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_decerr_slave.sdb
|       |   |           |   |   |       |   |   |   |-- axi_protocol_converter_v2_1_8_r_axi3_conv.sdb
|       |   |           |   |   |       |   |   |   `-- axi_protocol_converter_v2_1_8_w_axi3_conv.sdb
|       |   |           |   |   |       |   |   |-- axi_register_slice_v2_1_8
|       |   |           |   |   |       |   |   |   |-- axi_register_slice_v2_1_8.rlx
|       |   |           |   |   |       |   |   |   |-- axi_register_slice_v2_1_8_axi_register_slice.sdb
|       |   |           |   |   |       |   |   |   |-- axi_register_slice_v2_1_8_axic_register_slice.sdb
|       |   |           |   |   |       |   |   |   `-- axi_register_slice_v2_1_8_srl_rtl.sdb
|       |   |           |   |   |       |   |   |-- axi_utils_v2_0_2
|       |   |           |   |   |       |   |   |   |-- axi_slave_2to1.vdb
|       |   |           |   |   |       |   |   |   |-- axi_slave_3to1.vdb
|       |   |           |   |   |       |   |   |   |-- axi_slave_4to1.vdb
|       |   |           |   |   |       |   |   |   |-- axi_utils_comps.vdb
|       |   |           |   |   |       |   |   |   |-- axi_utils_v2_0_2.rlx
|       |   |           |   |   |       |   |   |   |-- axi_utils_v2_0_2_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- glb_ifx_master.vdb
|       |   |           |   |   |       |   |   |   |-- glb_ifx_slave.vdb
|       |   |           |   |   |       |   |   |   |-- glb_srl_fifo.vdb
|       |   |           |   |   |       |   |   |   `-- global_util_pkg.vdb
|       |   |           |   |   |       |   |   |-- blk_mem_gen_v8_3_2
|       |   |           |   |   |       |   |   |   |-- @s@t@a@t@e_@l@o@g@i@c_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- beh_vlog_ff_ce_clr_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- beh_vlog_ff_clr_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- beh_vlog_ff_pre_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- beh_vlog_muxf7_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_axi_read_wrapper_beh_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_axi_regs_fwd_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_axi_write_wrapper_beh_v8_3.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_gen_v8_3_2.rlx
|       |   |           |   |   |       |   |   |   |-- blk_mem_gen_v8_3_2.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_gen_v8_3_2_mem_module.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_gen_v8_3_2_output_stage.sdb
|       |   |           |   |   |       |   |   |   |-- blk_mem_gen_v8_3_2_softecc_output_reg_stage.sdb
|       |   |           |   |   |       |   |   |   |-- read_netlist_v8_3.sdb
|       |   |           |   |   |       |   |   |   `-- write_netlist_v8_3.sdb
|       |   |           |   |   |       |   |   |-- fifo_generator_v13_1_0
|       |   |           |   |   |       |   |   |   |-- axi_reg_slice.vdb
|       |   |           |   |   |       |   |   |   |-- bin_cntr.vdb
|       |   |           |   |   |       |   |   |   |-- bram_fifo_rstlogic.vdb
|       |   |           |   |   |       |   |   |   |-- bram_sync_reg.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_extdepth.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_extdepth_low_latency.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_extdepth_v6.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_prim.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_prim_v6.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_top.vdb
|       |   |           |   |   |       |   |   |   |-- builtin_top_v6.vdb
|       |   |           |   |   |       |   |   |   |-- clk_x_pntrs_builtin.vdb
|       |   |           |   |   |       |   |   |   |-- delay.vdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_top.vdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0.rlx
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_@c@o@n@v_@v@e@r.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_axic_reg_slice.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_beh_ver_ll_afifo.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_bhv_ver_as.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_bhv_ver_preload0.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_bhv_ver_ss.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_builtin.vdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_sync_stage.sdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_v13_1_0_synth.vdb
|       |   |           |   |   |       |   |   |   |-- fifo_generator_vlog_beh.sdb
|       |   |           |   |   |       |   |   |   |-- input_blk.vdb
|       |   |           |   |   |       |   |   |   |-- logic_builtin.vdb
|       |   |           |   |   |       |   |   |   |-- output_blk.vdb
|       |   |           |   |   |       |   |   |   |-- rd_pe_as.vdb
|       |   |           |   |   |       |   |   |   |-- rd_pe_ss.vdb
|       |   |           |   |   |       |   |   |   |-- reset_blk_ramfifo.vdb
|       |   |           |   |   |       |   |   |   |-- reset_builtin.vdb
|       |   |           |   |   |       |   |   |   |-- shft_ram.vdb
|       |   |           |   |   |       |   |   |   |-- shft_wrapper.vdb
|       |   |           |   |   |       |   |   |   |-- synchronizer_ff.vdb
|       |   |           |   |   |       |   |   |   |-- wr_pf_as.vdb
|       |   |           |   |   |       |   |   |   `-- wr_pf_ss.vdb
|       |   |           |   |   |       |   |   |-- floating_point_v7_1_2
|       |   |           |   |   |       |   |   |   |-- addsub.vdb
|       |   |           |   |   |       |   |   |   |-- addsub_dsp.vdb
|       |   |           |   |   |       |   |   |   |-- addsub_logic.vdb
|       |   |           |   |   |       |   |   |   |-- addsubshfw.vdb
|       |   |           |   |   |       |   |   |   |-- addsubshgw.vdb
|       |   |           |   |   |       |   |   |   |-- addsubw.vdb
|       |   |           |   |   |       |   |   |   |-- addw.vdb
|       |   |           |   |   |       |   |   |   |-- align_add.vdb
|       |   |           |   |   |       |   |   |   |-- align_add_dsp48e1_hp.vdb
|       |   |           |   |   |       |   |   |   |-- align_add_dsp48e1_sgl.vdb
|       |   |           |   |   |       |   |   |   |-- alignment.vdb
|       |   |           |   |   |       |   |   |   |-- andw.vdb
|       |   |           |   |   |       |   |   |   |-- carry_chain.vdb
|       |   |           |   |   |       |   |   |   |-- cntrlgen.vdb
|       |   |           |   |   |       |   |   |   |-- cntrlgen2.vdb
|       |   |           |   |   |       |   |   |   |-- compare.vdb
|       |   |           |   |   |       |   |   |   |-- compare_eq.vdb
|       |   |           |   |   |       |   |   |   |-- compare_eq_im.vdb
|       |   |           |   |   |       |   |   |   |-- compare_ge.vdb
|       |   |           |   |   |       |   |   |   |-- compare_gt.vdb
|       |   |           |   |   |       |   |   |   |-- compare_ne_im.vdb
|       |   |           |   |   |       |   |   |   |-- compw.vdb
|       |   |           |   |   |       |   |   |   |-- delay.vdb
|       |   |           |   |   |       |   |   |   |-- delay_s.vdb
|       |   |           |   |   |       |   |   |   |-- delays.vdb
|       |   |           |   |   |       |   |   |   |-- delayw.vdb
|       |   |           |   |   |       |   |   |   |-- dsp48e1_wrapper.vdb
|       |   |           |   |   |       |   |   |   |-- dsp48e2_wrapper.vdb
|       |   |           |   |   |       |   |   |   |-- dsp48mult.vdb
|       |   |           |   |   |       |   |   |   |-- dsp48multaline.vdb
|       |   |           |   |   |       |   |   |   |-- equalw.vdb
|       |   |           |   |   |       |   |   |   |-- fdgs.vdb
|       |   |           |   |   |       |   |   |   |-- fdgw.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_dsp48e1_dbl.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_dsp48e1_lat_dbl.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_dsp48e1_sgl.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_dsp48e2_dbl.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_qq.vdb
|       |   |           |   |   |       |   |   |   |-- fix_mult_xx.vdb
|       |   |           |   |   |       |   |   |   |-- fix_to_flt_conv.vdb
|       |   |           |   |   |       |   |   |   |-- fix_to_flt_conv_exp.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2.rlx
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_comp.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_consts.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_exp_table_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_table_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_viv.vdb
|       |   |           |   |   |       |   |   |   |-- floating_point_v7_1_2_viv_comp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_accum.vdb
|       |   |           |   |   |       |   |   |   |-- flt_accum_bit_encode.vdb
|       |   |           |   |   |       |   |   |   |-- flt_accum_flt_to_fix.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_dsp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_exp_hp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_exp_sp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_lat.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_lat_align_add.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_lat_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_lat_norm.vdb
|       |   |           |   |   |       |   |   |   |-- flt_add_logic.vdb
|       |   |           |   |   |       |   |   |   |-- flt_dec_op.vdb
|       |   |           |   |   |       |   |   |   |-- flt_dec_op_lat.vdb
|       |   |           |   |   |       |   |   |   |-- flt_div.vdb
|       |   |           |   |   |       |   |   |   |-- flt_div_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_div_mant.vdb
|       |   |           |   |   |       |   |   |   |-- flt_div_mant_addsub.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_ccm.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_dp_poly.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_e2a.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_e2zmzm1.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_hp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_hp_table_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_recomb.vdb
|       |   |           |   |   |       |   |   |   |-- flt_exp_specialcase.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_add.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_add_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_add_logic.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_addsub.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_addsub_dsp1.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_addsub_dsp2.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_align_add.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_alignment.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_mul.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_norm_logic.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_renorm_and_round_logic.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_round_bit.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_special_detect.vdb
|       |   |           |   |   |       |   |   |   |-- flt_fma_specialcase.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_addsub.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_addsub_taylor_combiner_fabric.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_addsub_taylor_fabric.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_inproc.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_l_block_memory.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_l_block_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_lead_zero_encode.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_norm.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_normalize.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_recomb.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_rnd.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_rr.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_rr_mul.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_rr_mul_iter.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_shift_msb_first.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_single_one_detect.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_specialcase.vdb
|       |   |           |   |   |       |   |   |   |-- flt_log_taylor.vdb
|       |   |           |   |   |       |   |   |   |-- flt_mant_lookup_hp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_mult.vdb
|       |   |           |   |   |       |   |   |   |-- flt_mult_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_mult_round.vdb
|       |   |           |   |   |       |   |   |   |-- flt_pt_log_l_block.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_approx.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_eval.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_nr.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_postprocess.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_recomb.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_reduction_calc.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recip_specialcase.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recipsqrt_dp_m_calc.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recipsqrt_dp_recsqrt_r_rom.vdb
|       |   |           |   |   |       |   |   |   |-- flt_recipsqrt_sp_sqrt_r_rom.vdb
|       |   |           |   |   |       |   |   |   |-- flt_round_bit.vdb
|       |   |           |   |   |       |   |   |   |-- flt_round_dsp_opt_full.vdb
|       |   |           |   |   |       |   |   |   |-- flt_round_dsp_opt_part.vdb
|       |   |           |   |   |       |   |   |   |-- flt_sqrt.vdb
|       |   |           |   |   |       |   |   |   |-- flt_sqrt_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_sqrt_mant.vdb
|       |   |           |   |   |       |   |   |   |-- flt_sqrt_mant_addsub.vdb
|       |   |           |   |   |       |   |   |   |-- flt_to_fix_conv.vdb
|       |   |           |   |   |       |   |   |   |-- flt_to_flt_conv.vdb
|       |   |           |   |   |       |   |   |   |-- flt_to_flt_conv_exp.vdb
|       |   |           |   |   |       |   |   |   |-- flt_utils.vdb
|       |   |           |   |   |       |   |   |   |-- fp_cmp.vdb
|       |   |           |   |   |       |   |   |   |-- lead_zero_encode.vdb
|       |   |           |   |   |       |   |   |   |-- lead_zero_encode_shift.vdb
|       |   |           |   |   |       |   |   |   |-- lead_zero_encode_shift_hp.vdb
|       |   |           |   |   |       |   |   |   |-- lutn.vdb
|       |   |           |   |   |       |   |   |   |-- lutnmuxs.vdb
|       |   |           |   |   |       |   |   |   |-- luts.vdb
|       |   |           |   |   |       |   |   |   |-- lutv.vdb
|       |   |           |   |   |       |   |   |   |-- mult18.vdb
|       |   |           |   |   |       |   |   |   |-- multadd.vdb
|       |   |           |   |   |       |   |   |   |-- mux4.vdb
|       |   |           |   |   |       |   |   |   |-- mux_bus2.vdb
|       |   |           |   |   |       |   |   |   |-- norm_and_round_dsp48e1_hp.vdb
|       |   |           |   |   |       |   |   |   |-- norm_and_round_dsp48e1_sgl.vdb
|       |   |           |   |   |       |   |   |   |-- norm_and_round_logic.vdb
|       |   |           |   |   |       |   |   |   |-- norm_zero_det.vdb
|       |   |           |   |   |       |   |   |   |-- normalize.vdb
|       |   |           |   |   |       |   |   |   |-- orw.vdb
|       |   |           |   |   |       |   |   |   |-- ppgenr8.vdb
|       |   |           |   |   |       |   |   |   |-- ppgenr8msb2.vdb
|       |   |           |   |   |       |   |   |   |-- renorm_and_round_logic.vdb
|       |   |           |   |   |       |   |   |   |-- shift_msb_first.vdb
|       |   |           |   |   |       |   |   |   |-- special_detect.vdb
|       |   |           |   |   |       |   |   |   |-- srl16es.vdb
|       |   |           |   |   |       |   |   |   |-- srl16ew.vdb
|       |   |           |   |   |       |   |   |   |-- twos_comp.vdb
|       |   |           |   |   |       |   |   |   |-- vm2comps.vdb
|       |   |           |   |   |       |   |   |   |-- vm2utils.vdb
|       |   |           |   |   |       |   |   |   |-- vmroundw.vdb
|       |   |           |   |   |       |   |   |   |-- vmsmultcore.vdb
|       |   |           |   |   |       |   |   |   |-- vt2mcomps.vdb
|       |   |           |   |   |       |   |   |   |-- vt2mutils.vdb
|       |   |           |   |   |       |   |   |   |-- wideembedmult.vdb
|       |   |           |   |   |       |   |   |   |-- wideembedmult16.vdb
|       |   |           |   |   |       |   |   |   |-- wideembedmult4.vdb
|       |   |           |   |   |       |   |   |   |-- xmult.vdb
|       |   |           |   |   |       |   |   |   `-- zero_det_sel.vdb
|       |   |           |   |   |       |   |   |-- generic_baseblocks_v2_1_0
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0.rlx
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_carry.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_carry_and.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_carry_latch_and.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_carry_latch_or.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_carry_or.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_command_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_mask.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_mask_static.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_sel.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_sel_mask.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_sel_mask_static.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_sel_static.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_comparator_static.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_mux.sdb
|       |   |           |   |   |       |   |   |   |-- generic_baseblocks_v2_1_0_mux_enc.sdb
|       |   |           |   |   |       |   |   |   `-- generic_baseblocks_v2_1_0_nto1_mux.sdb
|       |   |           |   |   |       |   |   |-- mult_gen_v12_0_11
|       |   |           |   |   |       |   |   |   |-- cc_compare.vdb
|       |   |           |   |   |       |   |   |   |-- ccm.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_dist_mem.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_dp_block_mem.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_operation.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_scaled_adder.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_sp_block_mem.vdb
|       |   |           |   |   |       |   |   |   |-- ccm_syncmem.vdb
|       |   |           |   |   |       |   |   |   |-- delay_line.vdb
|       |   |           |   |   |       |   |   |   |-- dsp.vdb
|       |   |           |   |   |       |   |   |   |-- dsp_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- hybrid.vdb
|       |   |           |   |   |       |   |   |   |-- luts.vdb
|       |   |           |   |   |       |   |   |   |-- mult18.vdb
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11.rlx
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11.vdb
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11_comp.vdb
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11_viv.vdb
|       |   |           |   |   |       |   |   |   |-- mult_gen_v12_0_11_viv_comp.vdb
|       |   |           |   |   |       |   |   |   |-- multmxn_lut6.vdb
|       |   |           |   |   |       |   |   |   |-- op_resize.vdb
|       |   |           |   |   |       |   |   |   `-- three_input_adder.vdb
|       |   |           |   |   |       |   |   |-- opencldesign_behav
|       |   |           |   |   |       |   |   |   |-- Compile_Options.txt
|       |   |           |   |   |       |   |   |   |-- xsim.dbg
|       |   |           |   |   |       |   |   |   |-- xsim.mem
|       |   |           |   |   |       |   |   |   |-- xsim.reloc
|       |   |           |   |   |       |   |   |   |-- xsim.rtti
|       |   |           |   |   |       |   |   |   |-- xsim.svtype
|       |   |           |   |   |       |   |   |   |-- xsim.type
|       |   |           |   |   |       |   |   |   |-- xsim.xdbg
|       |   |           |   |   |       |   |   |   `-- xsimk
|       |   |           |   |   |       |   |   |-- xbip_bram18k_v3_0_2
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_hdl_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_rtl.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_synth.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_v3_0_2.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_v3_0_2.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_v3_0_2_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_bram18k_v3_0_2_viv.vdb
|       |   |           |   |   |       |   |   |   `-- xbip_bram18k_v3_0_2_viv_comp.vdb
|       |   |           |   |   |       |   |   |-- xbip_dsp48_addsub_v3_0_2
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_rtl.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_synth.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_v3_0_2.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_v3_0_2.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_v3_0_2_comp.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_v3_0_2_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_addsub_v3_0_2_viv.vdb
|       |   |           |   |   |       |   |   |   `-- xbip_dsp48_addsub_v3_0_2_viv_comp.vdb
|       |   |           |   |   |       |   |   |-- xbip_dsp48_multadd_v3_0_2
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_rtl.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_synth.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_v3_0_2.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_v3_0_2.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_v3_0_2_comp.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_v3_0_2_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_multadd_v3_0_2_viv.vdb
|       |   |           |   |   |       |   |   |   `-- xbip_dsp48_multadd_v3_0_2_viv_comp.vdb
|       |   |           |   |   |       |   |   |-- xbip_dsp48_wrapper_v3_0_4
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_wrapper_v3_0_4.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_wrapper_v3_0_4.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48_wrapper_v3_0_4_pkg.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48a1_wrapper_v3_0.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48a_wrapper_v3_0.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48e1_wrapper_v3_0.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_dsp48e2_wrapper_v3_0.vdb
|       |   |           |   |   |       |   |   |   `-- xbip_dsp48e_wrapper_v3_0.vdb
|       |   |           |   |   |       |   |   |-- xbip_pipe_v3_0_2
|       |   |           |   |   |       |   |   |   |-- xbip_pipe_v3_0_2.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_pipe_v3_0_2.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_pipe_v3_0_2_comp.vdb
|       |   |           |   |   |       |   |   |   |-- xbip_pipe_v3_0_2_viv.vdb
|       |   |           |   |   |       |   |   |   `-- xbip_pipe_v3_0_2_viv_comp.vdb
|       |   |           |   |   |       |   |   |-- xbip_utils_v3_0_6
|       |   |           |   |   |       |   |   |   |-- xbip_utils_v3_0_6.rlx
|       |   |           |   |   |       |   |   |   |-- xbip_utils_v3_0_6_pkg.vdb
|       |   |           |   |   |       |   |   |   `-- xcc_utils_v3_0.vdb
|       |   |           |   |   |       |   |   |-- xil_defaultlib
|       |   |           |   |   |       |   |   |   |-- $unit_1.sdb
|       |   |           |   |   |       |   |   |   |-- @o@c@l_@region_0_imp_11@y@r@h@r@e.sdb
|       |   |           |   |   |       |   |   |   |-- axifull_bridge.vdb
|       |   |           |   |   |       |   |   |   |-- axilite_bridge.vdb
|       |   |           |   |   |       |   |   |   |-- clk_gen.sdb
|       |   |           |   |   |       |   |   |   |-- glbl.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32.vdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_control_s_axi.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_buffer.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_decoder.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_fifo.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_read.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_reg_slice.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_throttl.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_gmem_m_axi_write.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7_@muln@s_1.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_32s_32s_32_7_@muln@s_0.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2_@d@s@p48_0.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_pos_1.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_pos_1_ram.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_resbuf.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_resbuf_ram.sdb
|       |   |           |   |   |       |   |   |   |-- krnl_sobel_sitofp_32ns_32_6.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_auto_cc_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_auto_cc_1.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_auto_us_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_c0_ddr_clk_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_c0_kernel_clk_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_c0_ui_clk_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_c1_ddr_clk_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_krnl_sobel_1_0.vdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_m_axi_interconnect_@m00_@a@x@i_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_master_bridge_0_0.vdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_master_bridge_1_0.vdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_s00_regslice_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_s_axi_interconnect_0_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_sdaccel_generic_pcie_0_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_slave_bridge_0.vdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_1_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_2_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_34_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_3_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_4_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_512_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_64_0.sdb
|       |   |           |   |   |       |   |   |   |-- opencldesign_xlconstant_zero_8_0.sdb
|       |   |           |   |   |       |   |   |   |-- s00_couplers_imp_13@g@m@k@v@a.sdb
|       |   |           |   |   |       |   |   |   |-- s00_couplers_imp_@z@k@u@n@r@b.sdb
|       |   |           |   |   |       |   |   |   |-- xil_defaultlib.rlx
|       |   |           |   |   |       |   |   |   |-- xlconstant.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_base.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_dpdistram.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_dprom.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_sdpram.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_spram.sdb
|       |   |           |   |   |       |   |   |   |-- xpm_memory_sprom.sdb
|       |   |           |   |   |       |   |   |   `-- xpm_memory_tdpram.sdb
|       |   |           |   |   |       |   |   |-- xpm
|       |   |           |   |   |       |   |   |   |-- vcomponents.vdb
|       |   |           |   |   |       |   |   |   `-- xpm.rlx
|       |   |           |   |   |       |   |   `-- xsim.svtype
|       |   |           |   |   |       |   |-- xsim.ini
|       |   |           |   |   |       |   |-- xvhdl.log
|       |   |           |   |   |       |   |-- xvhdl.pb
|       |   |           |   |   |       |   |-- xvlog.log
|       |   |           |   |   |       |   `-- xvlog.pb
|       |   |           |   |   |       `-- behav.xcix
|       |   |           |   |   |-- ipiprj.srcs
|       |   |           |   |   |   `-- sources_1
|       |   |           |   |   |       `-- bd
|       |   |           |   |   |           `-- opencldesign
|       |   |           |   |   |               |-- hdl
|       |   |           |   |   |               |   |-- opencldesign.hwdef
|       |   |           |   |   |               |   |-- opencldesign.v
|       |   |           |   |   |               |   `-- opencldesign_wrapper.v
|       |   |           |   |   |               |-- hw_handoff
|       |   |           |   |   |               |   |-- opencldesign.hwh
|       |   |           |   |   |               |   `-- opencldesign_bd.tcl
|       |   |           |   |   |               |-- ip
|       |   |           |   |   |               |   |-- opencldesign_auto_cc_0
|       |   |           |   |   |               |   |   |-- opencldesign_auto_cc_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_auto_cc_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_auto_cc_0.v
|       |   |           |   |   |               |   |-- opencldesign_auto_cc_1
|       |   |           |   |   |               |   |   |-- opencldesign_auto_cc_1.xci
|       |   |           |   |   |               |   |   |-- opencldesign_auto_cc_1.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_auto_cc_1.v
|       |   |           |   |   |               |   |-- opencldesign_auto_us_0
|       |   |           |   |   |               |   |   |-- opencldesign_auto_us_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_auto_us_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_auto_us_0.v
|       |   |           |   |   |               |   |-- opencldesign_c0_ddr_clk_0
|       |   |           |   |   |               |   |   |-- opencldesign_c0_ddr_clk_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_c0_ddr_clk_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_c0_ddr_clk_0.v
|       |   |           |   |   |               |   |-- opencldesign_c0_kernel_clk_0
|       |   |           |   |   |               |   |   |-- opencldesign_c0_kernel_clk_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_c0_kernel_clk_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_c0_kernel_clk_0.v
|       |   |           |   |   |               |   |-- opencldesign_c0_ui_clk_0
|       |   |           |   |   |               |   |   |-- opencldesign_c0_ui_clk_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_c0_ui_clk_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_c0_ui_clk_0.v
|       |   |           |   |   |               |   |-- opencldesign_c1_ddr_clk_0
|       |   |           |   |   |               |   |   |-- opencldesign_c1_ddr_clk_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_c1_ddr_clk_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_c1_ddr_clk_0.v
|       |   |           |   |   |               |   |-- opencldesign_krnl_sobel_1_0
|       |   |           |   |   |               |   |   |-- constraints
|       |   |           |   |   |               |   |   |   `-- krnl_sobel_ooc.xdc
|       |   |           |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_krnl_sobel_1_0.xml
|       |   |           |   |   |               |   |   |-- sim
|       |   |           |   |   |               |   |   |   `-- opencldesign_krnl_sobel_1_0.vhd
|       |   |           |   |   |               |   |   `-- synth
|       |   |           |   |   |               |   |       `-- opencldesign_krnl_sobel_1_0.v
|       |   |           |   |   |               |   |-- opencldesign_m_axi_interconnect_M00_AXI_0
|       |   |           |   |   |               |   |   |-- opencldesign_m_axi_interconnect_M00_AXI_0.xci
|       |   |           |   |   |               |   |   `-- opencldesign_m_axi_interconnect_M00_AXI_0.xml
|       |   |           |   |   |               |   |-- opencldesign_master_bridge_0_0
|       |   |           |   |   |               |   |   |-- opencldesign_master_bridge_0_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_master_bridge_0_0.xml
|       |   |           |   |   |               |   |   |-- sim
|       |   |           |   |   |               |   |   |   `-- opencldesign_master_bridge_0_0.vhd
|       |   |           |   |   |               |   |   `-- synth
|       |   |           |   |   |               |   |       `-- opencldesign_master_bridge_0_0.vhd
|       |   |           |   |   |               |   |-- opencldesign_master_bridge_1_0
|       |   |           |   |   |               |   |   |-- opencldesign_master_bridge_1_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_master_bridge_1_0.xml
|       |   |           |   |   |               |   |   |-- sim
|       |   |           |   |   |               |   |   |   `-- opencldesign_master_bridge_1_0.vhd
|       |   |           |   |   |               |   |   `-- synth
|       |   |           |   |   |               |   |       `-- opencldesign_master_bridge_1_0.vhd
|       |   |           |   |   |               |   |-- opencldesign_s00_regslice_0
|       |   |           |   |   |               |   |   |-- opencldesign_s00_regslice_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_s00_regslice_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_s00_regslice_0.v
|       |   |           |   |   |               |   |-- opencldesign_s_axi_interconnect_0_0
|       |   |           |   |   |               |   |   |-- opencldesign_s_axi_interconnect_0_0.xci
|       |   |           |   |   |               |   |   `-- opencldesign_s_axi_interconnect_0_0.xml
|       |   |           |   |   |               |   |-- opencldesign_sdaccel_generic_pcie_0_0
|       |   |           |   |   |               |   |   |-- opencldesign_sdaccel_generic_pcie_0_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_sdaccel_generic_pcie_0_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_sdaccel_generic_pcie_0_0.sv
|       |   |           |   |   |               |   |-- opencldesign_slave_bridge_0
|       |   |           |   |   |               |   |   |-- opencldesign_slave_bridge_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_slave_bridge_0.xml
|       |   |           |   |   |               |   |   |-- sim
|       |   |           |   |   |               |   |   |   `-- opencldesign_slave_bridge_0.vhd
|       |   |           |   |   |               |   |   `-- synth
|       |   |           |   |   |               |   |       `-- opencldesign_slave_bridge_0.vhd
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_1_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_1_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_1_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_2_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_2_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_2_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_34_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_34_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_34_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_3_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_3_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_3_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_4_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_4_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_4_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_512_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_512_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_512_0.v
|       |   |           |   |   |               |   |-- opencldesign_xlconstant_zero_64_0
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0.xci
|       |   |           |   |   |               |   |   |-- opencldesign_xlconstant_zero_64_0.xml
|       |   |           |   |   |               |   |   `-- sim
|       |   |           |   |   |               |   |       `-- opencldesign_xlconstant_zero_64_0.v
|       |   |           |   |   |               |   `-- opencldesign_xlconstant_zero_8_0
|       |   |           |   |   |               |       |-- opencldesign_xlconstant_zero_8_0.xci
|       |   |           |   |   |               |       |-- opencldesign_xlconstant_zero_8_0.xml
|       |   |           |   |   |               |       `-- sim
|       |   |           |   |   |               |           `-- opencldesign_xlconstant_zero_8_0.v
|       |   |           |   |   |               |-- ipshared
|       |   |           |   |   |               |   `-- xilinx.com
|       |   |           |   |   |               |       |-- axi_clock_converter_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_clock_converter_v2_1_axi_clock_converter.v
|       |   |           |   |   |               |       |           |-- axi_clock_converter_v2_1_axic_sample_cycle_ratio.v
|       |   |           |   |   |               |       |           `-- axi_clock_converter_v2_1_axic_sync_clock_converter.v
|       |   |           |   |   |               |       |-- axi_data_fifo_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_data_fifo_v2_1_axi_data_fifo.v
|       |   |           |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_fifo.v
|       |   |           |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_reg_srl_fifo.v
|       |   |           |   |   |               |       |           |-- axi_data_fifo_v2_1_axic_srl_fifo.v
|       |   |           |   |   |               |       |           |-- axi_data_fifo_v2_1_fifo_gen.v
|       |   |           |   |   |               |       |           `-- axi_data_fifo_v2_1_ndeep_srl.v
|       |   |           |   |   |               |       |-- axi_dwidth_converter_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_a_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_a_upsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi4lite_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi4lite_upsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_axi_upsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_b_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_upsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_r_upsizer_pktfifo.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_top.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_w_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_dwidth_converter_v2_1_w_upsizer.v
|       |   |           |   |   |               |       |           `-- axi_dwidth_converter_v2_1_w_upsizer_pktfifo.v
|       |   |           |   |   |               |       |-- axi_infrastructure_v1_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_infrastructure_v1_1_0_header.vh
|       |   |           |   |   |               |       |           |-- axi_infrastructure_v1_1_axi2vector.v
|       |   |           |   |   |               |       |           |-- axi_infrastructure_v1_1_axic_srl_fifo.v
|       |   |           |   |   |               |       |           `-- axi_infrastructure_v1_1_vector2axi.v
|       |   |           |   |   |               |       |-- axi_protocol_converter_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_a_axi3_conv.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_axi3_conv.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_axi_protocol_converter.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_axilite_conv.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_ar_channel.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_aw_channel.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_b_channel.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_cmd_translator.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_incr_cmd.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_r_channel.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_simple_fifo.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b2s_wrap_cmd.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_b_downsizer.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_decerr_slave.v
|       |   |           |   |   |               |       |           |-- axi_protocol_converter_v2_1_r_axi3_conv.v
|       |   |           |   |   |               |       |           `-- axi_protocol_converter_v2_1_w_axi3_conv.v
|       |   |           |   |   |               |       |-- axi_register_slice_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- axi_register_slice_v2_1_axi_register_slice.v
|       |   |           |   |   |               |       |           `-- axi_register_slice_v2_1_axic_register_slice.v
|       |   |           |   |   |               |       |-- axi_utils_v2_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- axi_utils_v2_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- blk_mem_gen_v8_3
|       |   |           |   |   |               |       |   `-- simulation
|       |   |           |   |   |               |       |       `-- blk_mem_gen_v8_3.v
|       |   |           |   |   |               |       |-- clk_gen_v1_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- clk_gen.v
|       |   |           |   |   |               |       |-- fifo_generator_v13_1
|       |   |           |   |   |               |       |   |-- hdl
|       |   |           |   |   |               |       |   |   |-- fifo_generator_v13_1_rfs.v
|       |   |           |   |   |               |       |   |   `-- fifo_generator_v13_1_rfs.vhd
|       |   |           |   |   |               |       |   `-- simulation
|       |   |           |   |   |               |       |       `-- fifo_generator_vlog_beh.v
|       |   |           |   |   |               |       |-- floating_point_v7_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- floating_point_v7_1_vh_rfs.vhd
|       |   |           |   |   |               |       |-- generic_baseblocks_v2_1
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_carry.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_and.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_latch_and.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_latch_or.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_carry_or.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_command_fifo.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_mask.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_mask_static.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_mask.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_mask_static.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_sel_static.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_comparator_static.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_mux.v
|       |   |           |   |   |               |       |           |-- generic_baseblocks_v2_1_mux_enc.v
|       |   |           |   |   |               |       |           `-- generic_baseblocks_v2_1_nto1_mux.v
|       |   |           |   |   |               |       |-- krnl_sobel_v1_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- ip
|       |   |           |   |   |               |       |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|       |   |           |   |   |               |       |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|       |   |           |   |   |               |       |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|       |   |           |   |   |               |       |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|       |   |           |   |   |               |       |       |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|       |   |           |   |   |               |       |       `-- verilog
|       |   |           |   |   |               |       |           |-- krnl_sobel.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_control_s_axi.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_gmem_m_axi.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_mul_31ns_32s_32_7.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_mul_32s_32s_32_7.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_pos_1.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_pos_1_ram.dat
|       |   |           |   |   |               |       |           |-- krnl_sobel_resbuf.v
|       |   |           |   |   |               |       |           |-- krnl_sobel_resbuf_ram.dat
|       |   |           |   |   |               |       |           `-- krnl_sobel_sitofp_32ns_32_6.v
|       |   |           |   |   |               |       |-- mult_gen_v12_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- mult_gen_v12_0.vhd
|       |   |           |   |   |               |       |       `-- mult_gen_v12_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- ocl_axifull_bridge_v1_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- axifull_bridge.vhd
|       |   |           |   |   |               |       |-- ocl_axilite_bridge_v1_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- axilite_bridge.vhd
|       |   |           |   |   |               |       |-- sdaccel_generic_pcie_v1_0
|       |   |           |   |   |               |       |   `-- sim
|       |   |           |   |   |               |       |       `-- cmodel
|       |   |           |   |   |               |       |           |-- libperformance_monitor.so
|       |   |           |   |   |               |       |           `-- libsdaccel_generic_pcie.so
|       |   |           |   |   |               |       |-- xbip_bram18k_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- xbip_bram18k_v3_0.vhd
|       |   |           |   |   |               |       |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- xbip_dsp48_addsub_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- xbip_dsp48_addsub_v3_0.vhd
|       |   |           |   |   |               |       |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- xbip_dsp48_multadd_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- xbip_dsp48_multadd_v3_0.vhd
|       |   |           |   |   |               |       |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- xbip_dsp48_wrapper_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- xbip_pipe_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       |-- xbip_pipe_v3_0.vhd
|       |   |           |   |   |               |       |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       |-- xbip_utils_v3_0
|       |   |           |   |   |               |       |   `-- hdl
|       |   |           |   |   |               |       |       `-- xbip_utils_v3_0_vh_rfs.vhd
|       |   |           |   |   |               |       `-- xlconstant_v1_1
|       |   |           |   |   |               |           `-- xlconstant.v
|       |   |           |   |   |               |-- opencldesign.bd
|       |   |           |   |   |               |-- opencldesign.bxml
|       |   |           |   |   |               `-- opencldesign_ooc.xdc
|       |   |           |   |   `-- ipiprj.xpr
|       |   |           |   |-- ipirun.tcl
|       |   |           |   |-- map.tcl
|       |   |           |   |-- opencldesign.xdc
|       |   |           |   |-- vivado.jou
|       |   |           |   |-- vivado.log
|       |   |           |   `-- vivado_5646.backup.log
|       |   |           |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_regiongen.log
|       |   |           `-- krnl_sobel
|       |   |               |-- hls_transform.tcl
|       |   |               |-- krnl_sobel.ar.log
|       |   |               |-- krnl_sobel.clc.bc
|       |   |               |-- krnl_sobel.clc.noopt.bc
|       |   |               |-- krnl_sobel.clc.offline.bc
|       |   |               |-- krnl_sobel.clc.offline.o
|       |   |               |-- krnl_sobel.clc.offline.s
|       |   |               |-- krnl_sobel.gcc_archive.log
|       |   |               |-- krnl_sobel.hls.log
|       |   |               |-- krnl_sobel.llc.log
|       |   |               |-- krnl_sobel.llvmlink.log
|       |   |               |-- krnl_sobel.objcopy.log
|       |   |               |-- krnl_sobel.offline.a
|       |   |               |-- krnl_sobel.offline.o
|       |   |               |-- krnl_sobel.opt.log
|       |   |               |-- krnl_sobelfilter.cl
|       |   |               |-- krnl_sobelfilter.clang.log
|       |   |               |-- krnl_sobelfilterclc.00.bc
|       |   |               `-- vivado_hls.log
|       |   `-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_xclbincat.log
|       `-- kernels
|           `-- krnl_sobel
|               |-- ISEWrap.js
|               |-- ISEWrap.sh
|               |-- htr.txt
|               |-- krnl_sobel
|               |   |-- hls_transform.tcl
|               |   |-- ip
|               |   |   |-- autoimpl.log
|               |   |   |-- auxiliary.xml
|               |   |   |-- bd
|               |   |   |-- component.xml
|               |   |   |-- constraints
|               |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |-- doc
|               |   |   |   `-- ReleaseNotes.txt
|               |   |   |-- drivers
|               |   |   |   `-- krnl_sobel_v1_0
|               |   |   |       |-- data
|               |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |       `-- src
|               |   |   |           |-- Makefile
|               |   |   |           |-- xkrnl_sobel.c
|               |   |   |           |-- xkrnl_sobel.h
|               |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |-- example
|               |   |   |   |-- ipi_example.sh
|               |   |   |   `-- ipi_example.tcl
|               |   |   |-- hdl
|               |   |   |   |-- ip
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |-- verilog
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   `-- vhdl
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |-- krnl_sobel_info.xml
|               |   |   |-- misc
|               |   |   |   `-- logo.png
|               |   |   |-- pack.sh
|               |   |   |-- run_ippack.tcl
|               |   |   |-- subcore
|               |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |-- tmp.cache
|               |   |   |   `-- wt
|               |   |   |       `-- project.wpc
|               |   |   |-- tmp.hw
|               |   |   |   `-- tmp.lpr
|               |   |   |-- tmp.ip_user_files
|               |   |   |-- tmp.srcs
|               |   |   |   `-- sources_1
|               |   |   |       `-- ip
|               |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |           |   |-- sim
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- synth
|               |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |           |   |   `-- hdl
|               |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |           |       `-- hdl
|               |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |               |-- axi_utils_v2_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |               |-- floating_point_v7_1_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |               |-- mult_gen_v12_0_11
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |               |-- sim
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- synth
|               |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |               |   `-- hdl
|               |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |               |   `-- hdl
|               |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |                   `-- hdl
|               |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |-- tmp.xpr
|               |   |   |-- vivado.jou
|               |   |   |-- vivado.log
|               |   |   |-- xgui
|               |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |-- kernel.xml
|               |   |-- krnl_sobel.clc.00.bc
|               |   |-- krnl_sobel.design.xml
|               |   |-- krnl_sobel_clang.log
|               |   |-- krnl_sobel_hls_transform.log
|               |   |-- krnl_sobel_kernelinfohash.log
|               |   |-- solution_OCL_REGION_0
|               |   |   |-- impl
|               |   |   |   |-- ip
|               |   |   |   |   |-- autoimpl.log
|               |   |   |   |   |-- auxiliary.xml
|               |   |   |   |   |-- bd
|               |   |   |   |   |-- component.xml
|               |   |   |   |   |-- constraints
|               |   |   |   |   |   `-- krnl_sobel_ooc.xdc
|               |   |   |   |   |-- doc
|               |   |   |   |   |   `-- ReleaseNotes.txt
|               |   |   |   |   |-- drivers
|               |   |   |   |   |   `-- krnl_sobel_v1_0
|               |   |   |   |   |       |-- data
|               |   |   |   |   |       |   |-- krnl_sobel.mdd
|               |   |   |   |   |       |   `-- krnl_sobel.tcl
|               |   |   |   |   |       `-- src
|               |   |   |   |   |           |-- Makefile
|               |   |   |   |   |           |-- xkrnl_sobel.c
|               |   |   |   |   |           |-- xkrnl_sobel.h
|               |   |   |   |   |           |-- xkrnl_sobel_hw.h
|               |   |   |   |   |           |-- xkrnl_sobel_linux.c
|               |   |   |   |   |           `-- xkrnl_sobel_sinit.c
|               |   |   |   |   |-- example
|               |   |   |   |   |   |-- ipi_example.sh
|               |   |   |   |   |   `-- ipi_example.tcl
|               |   |   |   |   |-- hdl
|               |   |   |   |   |   |-- ip
|               |   |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |   |-- verilog
|               |   |   |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |   |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |   `-- vhdl
|               |   |   |   |   |       |-- krnl_sobel.vhd
|               |   |   |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |   |   |       `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |   |   |-- krnl_sobel_info.xml
|               |   |   |   |   |-- misc
|               |   |   |   |   |   `-- logo.png
|               |   |   |   |   |-- pack.sh
|               |   |   |   |   |-- run_ippack.tcl
|               |   |   |   |   |-- subcore
|               |   |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- tmp.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- tmp.hw
|               |   |   |   |   |   `-- tmp.lpr
|               |   |   |   |   |-- tmp.ip_user_files
|               |   |   |   |   |-- tmp.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- tmp.xpr
|               |   |   |   |   |-- vivado.jou
|               |   |   |   |   |-- vivado.log
|               |   |   |   |   |-- xgui
|               |   |   |   |   |   `-- krnl_sobel_v1_0.tcl
|               |   |   |   |   `-- xilinx_com_hls_krnl_sobel_1_0.zip
|               |   |   |   |-- sdaccel
|               |   |   |   |   |-- kernel.xml
|               |   |   |   |   `-- kernel.xo
|               |   |   |   |-- verilog
|               |   |   |   |   |-- extraction.tcl
|               |   |   |   |   |-- impl.sh
|               |   |   |   |   |-- krnl_sobel.v
|               |   |   |   |   |-- krnl_sobel.xdc
|               |   |   |   |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |   |   |-- krnl_sobel_control_s_axi.v
|               |   |   |   |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |   |   |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |   |   |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |   |   |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |   |   |   |-- krnl_sobel_gmem_m_axi.v
|               |   |   |   |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |   |   |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |   |   |   |-- krnl_sobel_pos_1.v
|               |   |   |   |   |-- krnl_sobel_pos_1_ram.dat
|               |   |   |   |   |-- krnl_sobel_resbuf.v
|               |   |   |   |   |-- krnl_sobel_resbuf_ram.dat
|               |   |   |   |   |-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |   |   |   |-- project.cache
|               |   |   |   |   |   `-- wt
|               |   |   |   |   |       `-- project.wpc
|               |   |   |   |   |-- project.hw
|               |   |   |   |   |   `-- project.lpr
|               |   |   |   |   |-- project.ip_user_files
|               |   |   |   |   |-- project.srcs
|               |   |   |   |   |   `-- sources_1
|               |   |   |   |   |       `-- ip
|               |   |   |   |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |   |   |           |   |-- axi_utils_v2_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- floating_point_v7_1_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |   |   |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |   |   |           |   |-- mult_gen_v12_0_11
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- sim
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- synth
|               |   |   |   |   |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |   |   |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   |-- xbip_pipe_v3_0_2
|               |   |   |   |   |           |   |   `-- hdl
|               |   |   |   |   |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |           |   `-- xbip_utils_v3_0_6
|               |   |   |   |   |           |       `-- hdl
|               |   |   |   |   |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |   |   |               |-- axi_utils_v2_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |   |   |               |-- floating_point_v7_1_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |   |   |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |   |   |               |-- mult_gen_v12_0_11
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- mult_gen_v12_0.vhd
|               |   |   |   |   |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |   |   |               |-- sim
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- synth
|               |   |   |   |   |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |   |   |               |-- xbip_bram18k_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |   |   |               |-- xbip_pipe_v3_0_2
|               |   |   |   |   |               |   `-- hdl
|               |   |   |   |   |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |   |   |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |   |   |               `-- xbip_utils_v3_0_6
|               |   |   |   |   |                   `-- hdl
|               |   |   |   |   |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |   |   |-- project.xpr
|               |   |   |   |   |-- run_vivado.tcl
|               |   |   |   |   `-- settings.tcl
|               |   |   |   `-- vhdl
|               |   |   |       |-- extraction.tcl
|               |   |   |       |-- impl.sh
|               |   |   |       |-- krnl_sobel.vhd
|               |   |   |       |-- krnl_sobel.xdc
|               |   |   |       |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |   |       |-- krnl_sobel_control_s_axi.vhd
|               |   |   |       |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |   |       |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |   |       |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |   |       |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |   |       |-- krnl_sobel_gmem_m_axi.vhd
|               |   |   |       |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |   |       |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |   |       |-- krnl_sobel_pos_1.vhd
|               |   |   |       |-- krnl_sobel_resbuf.vhd
|               |   |   |       |-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |   |       |-- project.cache
|               |   |   |       |   `-- wt
|               |   |   |       |       `-- project.wpc
|               |   |   |       |-- project.hw
|               |   |   |       |   `-- project.lpr
|               |   |   |       |-- project.ip_user_files
|               |   |   |       |-- project.srcs
|               |   |   |       |   `-- sources_1
|               |   |   |       |       `-- ip
|               |   |   |       |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_faddfsub_6_full_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fcmp_0_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fdiv_14_no_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           |-- krnl_sobel_ap_fmul_3_max_dsp_32
|               |   |   |       |           |   |-- axi_utils_v2_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |           |   |-- floating_point_v7_1_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xci
|               |   |   |       |           |   |-- krnl_sobel_ap_fmul_3_max_dsp_32.xml
|               |   |   |       |           |   |-- mult_gen_v12_0_11
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- mult_gen_v12_0.vhd
|               |   |   |       |           |   |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |           |   |-- sim
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- synth
|               |   |   |       |           |   |   `-- krnl_sobel_ap_fmul_3_max_dsp_32.vhd
|               |   |   |       |           |   |-- xbip_bram18k_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |           |   |-- xbip_pipe_v3_0_2
|               |   |   |       |           |   |   `-- hdl
|               |   |   |       |           |   |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |           |   |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |           |   `-- xbip_utils_v3_0_6
|               |   |   |       |           |       `-- hdl
|               |   |   |       |           |           `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |           `-- krnl_sobel_ap_sitofp_4_no_dsp_32
|               |   |   |       |               |-- axi_utils_v2_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- axi_utils_v2_0_vh_rfs.vhd
|               |   |   |       |               |-- floating_point_v7_1_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- floating_point_v7_1_vh_rfs.vhd
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xci
|               |   |   |       |               |-- krnl_sobel_ap_sitofp_4_no_dsp_32.xml
|               |   |   |       |               |-- mult_gen_v12_0_11
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- mult_gen_v12_0.vhd
|               |   |   |       |               |       `-- mult_gen_v12_0_vh_rfs.vhd
|               |   |   |       |               |-- sim
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- synth
|               |   |   |       |               |   `-- krnl_sobel_ap_sitofp_4_no_dsp_32.vhd
|               |   |   |       |               |-- xbip_bram18k_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_bram18k_v3_0.vhd
|               |   |   |       |               |       `-- xbip_bram18k_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_addsub_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_addsub_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_addsub_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_multadd_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_dsp48_multadd_v3_0.vhd
|               |   |   |       |               |       `-- xbip_dsp48_multadd_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_dsp48_wrapper_v3_0_4
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       `-- xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
|               |   |   |       |               |-- xbip_pipe_v3_0_2
|               |   |   |       |               |   `-- hdl
|               |   |   |       |               |       |-- xbip_pipe_v3_0.vhd
|               |   |   |       |               |       `-- xbip_pipe_v3_0_vh_rfs.vhd
|               |   |   |       |               `-- xbip_utils_v3_0_6
|               |   |   |       |                   `-- hdl
|               |   |   |       |                       `-- xbip_utils_v3_0_vh_rfs.vhd
|               |   |   |       |-- project.xpr
|               |   |   |       |-- run_vivado.tcl
|               |   |   |       `-- settings.tcl
|               |   |   |-- solution_OCL_REGION_0.aps
|               |   |   |-- solution_OCL_REGION_0.directive
|               |   |   |-- solution_OCL_REGION_0.log
|               |   |   `-- syn
|               |   |       |-- report
|               |   |       |   |-- krnl_sobel_csynth.rpt
|               |   |       |   `-- krnl_sobel_csynth.xml
|               |   |       |-- systemc
|               |   |       |   |-- ACMP_faddfsub.h
|               |   |       |   |-- ACMP_fcmp_comb.h
|               |   |       |   |-- ACMP_fdiv.h
|               |   |       |   |-- ACMP_fmul.h
|               |   |       |   |-- ACMP_mul_ss.h
|               |   |       |   |-- ACMP_mul_us.h
|               |   |       |   |-- ACMP_mul_uu.h
|               |   |       |   |-- ACMP_sitofp.h
|               |   |       |   |-- AESL_pkg.h
|               |   |       |   |-- krnl_sobel.h
|               |   |       |   |-- krnl_sobel_1.cpp
|               |   |       |   |-- krnl_sobel_10.cpp
|               |   |       |   |-- krnl_sobel_11.cpp
|               |   |       |   |-- krnl_sobel_12.cpp
|               |   |       |   |-- krnl_sobel_13.cpp
|               |   |       |   |-- krnl_sobel_14.cpp
|               |   |       |   |-- krnl_sobel_15.cpp
|               |   |       |   |-- krnl_sobel_2.cpp
|               |   |       |   |-- krnl_sobel_3.cpp
|               |   |       |   |-- krnl_sobel_4.cpp
|               |   |       |   |-- krnl_sobel_5.cpp
|               |   |       |   |-- krnl_sobel_6.cpp
|               |   |       |   |-- krnl_sobel_7.cpp
|               |   |       |   |-- krnl_sobel_8.cpp
|               |   |       |   |-- krnl_sobel_9.cpp
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.h
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.h
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.h
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.h
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.h
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.h
|               |   |       |   |-- krnl_sobel_pos_1.h
|               |   |       |   |-- krnl_sobel_resbuf.h
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.h
|               |   |       |-- verilog
|               |   |       |   |-- krnl_sobel.v
|               |   |       |   |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |       |   |-- krnl_sobel_control_s_axi.v
|               |   |       |   |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.v
|               |   |       |   |-- krnl_sobel_fcmp_32ns_32ns_1_1.v
|               |   |       |   |-- krnl_sobel_fdiv_32ns_32ns_32_16.v
|               |   |       |   |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.v
|               |   |       |   |-- krnl_sobel_gmem_m_axi.v
|               |   |       |   |-- krnl_sobel_mul_31ns_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_32s_32s_32_7.v
|               |   |       |   |-- krnl_sobel_mul_mul_16ns_16ns_32_2.v
|               |   |       |   |-- krnl_sobel_pos_1.v
|               |   |       |   |-- krnl_sobel_pos_1_ram.dat
|               |   |       |   |-- krnl_sobel_resbuf.v
|               |   |       |   |-- krnl_sobel_resbuf_ram.dat
|               |   |       |   `-- krnl_sobel_sitofp_32ns_32_6.v
|               |   |       `-- vhdl
|               |   |           |-- krnl_sobel.vhd
|               |   |           |-- krnl_sobel_ap_faddfsub_6_full_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fcmp_0_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fdiv_14_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_fmul_3_max_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_ap_sitofp_4_no_dsp_32_ip.tcl
|               |   |           |-- krnl_sobel_control_s_axi.vhd
|               |   |           |-- krnl_sobel_faddfsub_32ns_32ns_32_8_full_dsp.vhd
|               |   |           |-- krnl_sobel_fcmp_32ns_32ns_1_1.vhd
|               |   |           |-- krnl_sobel_fdiv_32ns_32ns_32_16.vhd
|               |   |           |-- krnl_sobel_fmul_32ns_32ns_32_5_max_dsp.vhd
|               |   |           |-- krnl_sobel_gmem_m_axi.vhd
|               |   |           |-- krnl_sobel_mul_31ns_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_32s_32s_32_7.vhd
|               |   |           |-- krnl_sobel_mul_mul_16ns_16ns_32_2.vhd
|               |   |           |-- krnl_sobel_pos_1.vhd
|               |   |           |-- krnl_sobel_resbuf.vhd
|               |   |           `-- krnl_sobel_sitofp_32ns_32_6.vhd
|               |   |-- vivado_hls.app
|               |   `-- vivado_hls.log
|               |-- krnl_sobel.tcl
|               |-- rundef.js
|               |-- runme.bat
|               |-- runme.log
|               |-- runme.sh
|               `-- vivado_hls.log
|-- _xocc_krnl_sobelfilter_krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.dir
|   `-- impl
|       |-- build
|       |   |-- cpu_em
|       |   |   `-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1
|       |   |       `-- csim
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.so
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xml
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1_regiongen.log
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1_top_gpp.log
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1_xcl_top_gpp.log
|       |   |           |-- krnl_sobel
|       |   |           |   |-- hls_transform.tcl
|       |   |           |   |-- krnl_sobel.clc.01.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu-opt.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu-opt.s
|       |   |           |   |-- krnl_sobel.clc.csim_cu.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu.o
|       |   |           |   |-- krnl_sobel.csim_cu.a
|       |   |           |   |-- krnl_sobel.csim_cu.o
|       |   |           |   |-- krnl_sobel_ar.log
|       |   |           |   |-- krnl_sobel_gpp.log
|       |   |           |   |-- krnl_sobel_hls_transform.log
|       |   |           |   |-- krnl_sobel_krnl_sobelfilter_clang.log
|       |   |           |   |-- krnl_sobel_llc.log
|       |   |           |   |-- krnl_sobel_llvmlink.log
|       |   |           |   |-- krnl_sobel_objcopy.log
|       |   |           |   |-- krnl_sobel_opt.log
|       |   |           |   |-- krnl_sobelfilter.clc.00.bc
|       |   |           |   `-- vivado_hls.log
|       |   |           |-- obj
|       |   |           |   |-- xcl_top.CXXd
|       |   |           |   `-- xcl_top.o
|       |   |           `-- xcl_top.cpp
|       |   `-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1_xclbincat.log
|       `-- kernels
|           `-- krnl_sobel
|               `-- krnl_sobel
|                   |-- hls_transform.tcl
|                   |-- kernel.xml
|                   |-- krnl_sobel.clc.00.bc
|                   |-- krnl_sobel_clang.log
|                   |-- krnl_sobel_hls_transform.log
|                   |-- krnl_sobel_kernelinfohash.log
|                   `-- vivado_hls.log
|-- _xocc_krnl_sobelfilter_krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.dir
|   `-- impl
|       |-- build
|       |   |-- cpu_em
|       |   |   `-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1
|       |   |       `-- csim
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.so
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xml
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_regiongen.log
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_top_gpp.log
|       |   |           |-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_xcl_top_gpp.log
|       |   |           |-- krnl_sobel
|       |   |           |   |-- hls_transform.tcl
|       |   |           |   |-- krnl_sobel.clc.01.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu-opt.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu-opt.s
|       |   |           |   |-- krnl_sobel.clc.csim_cu.bc
|       |   |           |   |-- krnl_sobel.clc.csim_cu.o
|       |   |           |   |-- krnl_sobel.csim_cu.a
|       |   |           |   |-- krnl_sobel.csim_cu.o
|       |   |           |   |-- krnl_sobel_ar.log
|       |   |           |   |-- krnl_sobel_gpp.log
|       |   |           |   |-- krnl_sobel_hls_transform.log
|       |   |           |   |-- krnl_sobel_krnl_sobelfilter_clang.log
|       |   |           |   |-- krnl_sobel_llc.log
|       |   |           |   |-- krnl_sobel_llvmlink.log
|       |   |           |   |-- krnl_sobel_objcopy.log
|       |   |           |   |-- krnl_sobel_opt.log
|       |   |           |   |-- krnl_sobelfilter.clc.00.bc
|       |   |           |   `-- vivado_hls.log
|       |   |           |-- obj
|       |   |           |   |-- xcl_top.CXXd
|       |   |           |   `-- xcl_top.o
|       |   |           `-- xcl_top.cpp
|       |   `-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1_xclbincat.log
|       `-- kernels
|           `-- krnl_sobel
|               `-- krnl_sobel
|                   |-- hls_transform.tcl
|                   |-- kernel.xml
|                   |-- krnl_sobel.clc.00.bc
|                   |-- krnl_sobel_clang.log
|                   |-- krnl_sobel_hls_transform.log
|                   |-- krnl_sobel_kernelinfohash.log
|                   `-- vivado_hls.log
|-- benchapp.log
|-- data
|   |-- input
|   |   |-- CF000221.jpg
|   |   |-- Thumbs.db
|   |   |-- eiffel.bmp
|   |   |-- eiffel.bmp_cpu_grey.png
|   |   |-- eiffel.bmp_edges_cpuonly.png
|   |   |-- lola.bmp
|   |   `-- vase.bmp
|   `-- output
|       |-- Thumbs.db
|       `-- lola.bmp
|-- description.json
|-- edge_X86.exe
|-- opts.yml
|-- opts.yml~
|-- runtime
|   |-- lib
|   |   `-- x86_64
|   |       |-- libOpenCL.so
|   |       |-- libOpenCL.so.1
|   |       |-- libOpenCL.so.1.2
|   |       |-- liblmx6.0.so
|   |       |-- libstdc++.so.6
|   |       `-- libxilinxopencl.so
|   `-- platforms
|       `-- xilinx_adm-pcie-ku3_2ddr_2_1
|           |-- driver
|           |   |-- libxcldrv.so
|           |   `-- xcldma.zip
|           `-- dsa.xml
|-- sda_run.sh
|-- sdaccel_profile_summary.csv
|-- sdaccel_profile_summary.html
|-- src
|   |-- edge.cpp
|   |-- edge.h
|   |-- krnl_sobelfilter.cl
|   |-- krnl_sobelfilter.ll
|   `-- krnl_sobelfilter0.cl
|-- xclbin
|   |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|   |-- krnl_edge.hw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|   |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   `-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|-- xclbin-p0
|   |-- krnl_edge.hw.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   |-- krnl_edge.hw.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|   |-- krnl_edge.hw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   |-- krnl_edge.hw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
|   |-- krnl_edge.sw_emu.xilinx_adm-pcie-7v3_1ddr_2.1.xclbin
|   `-- krnl_edge.sw_emu.xilinx_adm-pcie-ku3_2ddr_2.1.xclbin
`-- xiaozhuNotes.txt

2078 directories, 3998 files
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
export XCL_EMULATION_MODE=<sw_emu|hw_emu>
emconfigutil --xdevice 'xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2' --nd 1
```
Once the environment has been configured, the application can be executed by
```
./edge data/input/eiffel.bmp
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
../../utility/nimbix/nimbix-run.py -- ./edge data/input/eiffel.bmp
```

***Copy the application files from the Developer to Runtime instances on Nimbix***
* Copy the application *.exe file and xclbin directory to the /data directory
* Launch the application using the Nimbix web interface as described in [Nimbix Getting Started Guide][]
* Make sure that the application launch options in the Nimbix web interface reflect the applications command line syntax
```
./edge data/input/eiffel.bmp
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
