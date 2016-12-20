Parallel Prefix Sum
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
Example of parallel prefix sum

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
├── description.json
├── emconfig.json
├── Makefile
├── README.md
├── sdaccel_profile_summary.csv
├── sdaccel_profile_summary.html
├── src
│   ├── krnl_sum_scan.cl
│   ├── krnl_sum_scan.ll
│   └── sum_scan.cpp
├── sum_scan
├── TempConfig
├── xclbin
│   ├── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0.xclbin
│   ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0.xclbin
│   ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin
│   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.xclbin
├── _xocc_krnl_sum_scan_krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0.dir
│   └── impl
│       ├── build
│       │   ├── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0_xclbincat.log
│       │   └── system
│       │       └── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0
│       │           └── bitstream
│       │               ├── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0_ipi
│       │               │   ├── dont_partition.xdc
│       │               │   ├── hd_visual
│       │               │   │   ├── pblock_u_ocl_region_AllTiles.tcl
│       │               │   │   ├── pblock_u_ocl_region_FrameTiles.tcl
│       │               │   │   ├── pblock_u_ocl_region_GlitchTiles.tcl
│       │               │   │   └── pblock_u_ocl_region_RangedSites.tcl
│       │               │   ├── ipiimpl
│       │               │   │   ├── ipiimpl.cache
│       │               │   │   │   └── wt
│       │               │   │   │       ├── project.wpc
│       │               │   │   │       └── webtalk_pa.xml
│       │               │   │   ├── ipiimpl.hw
│       │               │   │   │   └── ipiimpl.lpr
│       │               │   │   ├── ipiimpl.ip_user_files
│       │               │   │   ├── ipiimpl.runs
│       │               │   │   │   └── impl_1
│       │               │   │   │       ├── gen_run.xml
│       │               │   │   │       ├── hd_visual
│       │               │   │   │       │   ├── blockedBelsRouteThrus.tcl
│       │               │   │   │       │   ├── blockedPins.tcl
│       │               │   │   │       │   ├── blockedSitesInputs.tcl
│       │               │   │   │       │   ├── pblock_u_ocl_region_AllTiles.tcl
│       │               │   │   │       │   ├── pblock_u_ocl_region_FrameTiles.tcl
│       │               │   │   │       │   ├── pblock_u_ocl_region_GlitchTiles.tcl
│       │               │   │   │       │   └── pblock_u_ocl_region_RangedSites.tcl
│       │               │   │   │       ├── htr.txt
│       │               │   │   │       ├── init_design.pb
│       │               │   │   │       ├── ISEWrap.js
│       │               │   │   │       ├── ISEWrap.sh
│       │               │   │   │       ├── krnl_sum_scan_utilization_placed.rpt
│       │               │   │   │       ├── opt_design.pb
│       │               │   │   │       ├── place_design.pb
│       │               │   │   │       ├── platform_utilization_placed.rpt
│       │               │   │   │       ├── project.wdf
│       │               │   │   │       ├── route_design.pb
│       │               │   │   │       ├── rundef.js
│       │               │   │   │       ├── runme.bat
│       │               │   │   │       ├── runme.log
│       │               │   │   │       ├── runme.sh
│       │               │   │   │       ├── vivado.jou
│       │               │   │   │       ├── vivado.pb
│       │               │   │   │       ├── xcl_design_wrapper_clock_utilization_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_control_sets_placed.rpt
│       │               │   │   │       ├── xcl_design_wrapper.dcp
│       │               │   │   │       ├── xcl_design_wrapper_drc_opted.rpt
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.pb
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper.hwdef
│       │               │   │   │       ├── xcl_design_wrapper_io_placed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_methodology_drc_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_methodology_drc_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_power_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_power_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_power_summary_routed.pb
│       │               │   │   │       ├── xcl_design_wrapper_routed.dcp
│       │               │   │   │       ├── xcl_design_wrapper_route_status.pb
│       │               │   │   │       ├── xcl_design_wrapper_route_status.rpt
│       │               │   │   │       ├── xcl_design_wrapper.tcl
│       │               │   │   │       ├── xcl_design_wrapper_timing_summary_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_timing_summary_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_utilization_placed.pb
│       │               │   │   │       ├── xcl_design_wrapper_utilization_placed.rpt
│       │               │   │   │       └── xcl_design_wrapper.vdi
│       │               │   │   └── ipiimpl.xpr
│       │               │   ├── ipiprj
│       │               │   │   ├── ipiprj.cache
│       │               │   │   │   ├── ip
│       │               │   │   │   │   ├── 0f1168dd029b595b
│       │               │   │   │   │   │   ├── 0f1168dd029b595b.xci
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_slave_bridge_0_stub.vhdl
│       │               │   │   │   │   ├── 0f1168dd029b595b.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 74d98a21eec853a2
│       │               │   │   │   │   │   ├── 74d98a21eec853a2.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_cc_1_stub.vhdl
│       │               │   │   │   │   ├── 74d98a21eec853a2.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── a46d8c7c1c6e8a0e
│       │               │   │   │   │   │   ├── a46d8c7c1c6e8a0e.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_cc_0_stub.vhdl
│       │               │   │   │   │   ├── a46d8c7c1c6e8a0e.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── a6fe547741ff13ff
│       │               │   │   │   │   │   ├── a6fe547741ff13ff.xci
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_master_bridge_0_0_stub.vhdl
│       │               │   │   │   │   ├── a6fe547741ff13ff.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── afd1cfea2fbd0193
│       │               │   │   │   │   │   ├── afd1cfea2fbd0193.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_us_0_stub.vhdl
│       │               │   │   │   │   ├── afd1cfea2fbd0193.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── cc0553cc073a9270
│       │               │   │   │   │   │   ├── cc0553cc073a9270.xci
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_s00_regslice_0_stub.vhdl
│       │               │   │   │   │   ├── cc0553cc073a9270.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── d5d6afd98d0c278c
│       │               │   │   │   │   │   ├── d5d6afd98d0c278c.xci
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_krnl_sum_scan_1_0_stub.vhdl
│       │               │   │   │   │   ├── d5d6afd98d0c278c.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── ec052f6e551cbfff
│       │               │   │   │   │   │   ├── ec052f6e551cbfff.xci
│       │               │   │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_interconnect_sys_reset_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_interconnect_sys_reset_0_stub.vhdl
│       │               │   │   │   │   └── ec052f6e551cbfff.logs
│       │               │   │   │   │       └── runme.log
│       │               │   │   │   └── wt
│       │               │   │   │       ├── project.wpc
│       │               │   │   │       └── synthesis.wdf
│       │               │   │   ├── ipiprj.hw
│       │               │   │   │   └── ipiprj.lpr
│       │               │   │   ├── ipiprj.ip_user_files
│       │               │   │   ├── ipiprj.runs
│       │               │   │   │   ├── opencldesign_auto_cc_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.tcl
│       │               │   │   │   │   ├── opencldesign_auto_cc_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_cc_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_auto_cc_1_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── fsm_encoding.os
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.tcl
│       │               │   │   │   │   ├── opencldesign_auto_cc_1_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_cc_1_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_auto_us_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │   │   ├── opencldesign_auto_us_0.tcl
│       │               │   │   │   │   ├── opencldesign_auto_us_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_us_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_us_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_interconnect_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.dcp
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.tcl
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_kernel_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.dcp
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.v
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_stub.v
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_stub.vhdl
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.tcl
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_krnl_sum_scan_1_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_0_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_s00_regslice_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.tcl
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_slave_bridge_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.tcl
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   └── synth_1
│       │               │   │   │       ├── dont_touch.xdc
│       │               │   │   │       ├── gen_run.xml
│       │               │   │   │       ├── htr.txt
│       │               │   │   │       ├── ISEWrap.js
│       │               │   │   │       ├── ISEWrap.sh
│       │               │   │   │       ├── opencldesign_wrapper.dcp
│       │               │   │   │       ├── opencldesign_wrapper.tcl
│       │               │   │   │       ├── opencldesign_wrapper_utilization_synth.pb
│       │               │   │   │       ├── opencldesign_wrapper_utilization_synth.rpt
│       │               │   │   │       ├── opencldesign_wrapper.vds
│       │               │   │   │       ├── project.wdf
│       │               │   │   │       ├── rundef.js
│       │               │   │   │       ├── runme.bat
│       │               │   │   │       ├── runme.log
│       │               │   │   │       ├── runme.sh
│       │               │   │   │       ├── vivado.jou
│       │               │   │   │       └── vivado.pb
│       │               │   │   ├── ipiprj.srcs
│       │               │   │   │   └── sources_1
│       │               │   │   │       └── bd
│       │               │   │   │           └── opencldesign
│       │               │   │   │               ├── hdl
│       │               │   │   │               │   ├── opencldesign.hwdef
│       │               │   │   │               │   ├── opencldesign.v
│       │               │   │   │               │   └── opencldesign_wrapper.v
│       │               │   │   │               ├── hw_handoff
│       │               │   │   │               │   ├── opencldesign_bd.tcl
│       │               │   │   │               │   └── opencldesign.hwh
│       │               │   │   │               ├── ip
│       │               │   │   │               │   ├── opencldesign_auto_cc_0
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   ├── opencldesign_auto_cc_1
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_cc_1.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_cc_1.v
│       │               │   │   │               │   ├── opencldesign_auto_us_0
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_us_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_us_0.v
│       │               │   │   │               │   ├── opencldesign_interconnect_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_interconnect_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_interconnect_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_kernel_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_kernel_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_kernel_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_krnl_sum_scan_1_0
│       │               │   │   │               │   │   ├── constraints
│       │               │   │   │               │   │   │   └── krnl_sum_scan_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_krnl_sum_scan_1_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_krnl_sum_scan_1_0.v
│       │               │   │   │               │   ├── opencldesign_master_bridge_0_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   ├── opencldesign_m_axi_interconnect_M_AXI_0
│       │               │   │   │               │   │   ├── opencldesign_m_axi_interconnect_M_AXI_0.xci
│       │               │   │   │               │   │   └── opencldesign_m_axi_interconnect_M_AXI_0.xml
│       │               │   │   │               │   ├── opencldesign_s00_regslice_0
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xci
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   ├── opencldesign_s_axi_interconnect_0_0
│       │               │   │   │               │   │   ├── opencldesign_s_axi_interconnect_0_0.xci
│       │               │   │   │               │   │   └── opencldesign_s_axi_interconnect_0_0.xml
│       │               │   │   │               │   └── opencldesign_slave_bridge_0
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0_sim_netlist.v
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0_sim_netlist.vhdl
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0_stub.v
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0_stub.vhdl
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0.xci
│       │               │   │   │               │       ├── opencldesign_slave_bridge_0.xml
│       │               │   │   │               │       ├── sim
│       │               │   │   │               │       │   └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               │       └── synth
│       │               │   │   │               │           └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               ├── ipshared
│       │               │   │   │               │   ├── 04b4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── proc_sys_reset_v5_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 10b8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_data_fifo_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 1193
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axifull_bridge.vhd
│       │               │   │   │               │   ├── 1e87
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 218a
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── ip
│       │               │   │   │               │   │       │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│       │               │   │   │               │   │       └── verilog
│       │               │   │   │               │   │           ├── krnl_sum_scan_control_s_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_gmem_m_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_sums.v
│       │               │   │   │               │   │           └── krnl_sum_scan.v
│       │               │   │   │               │   ├── 403d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_bram18k_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 43f5
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_utils_v2_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 4a86
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_dwidth_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   │       └── axi_dwidth_converter_v2_1_vlsyn_rfs.v
│       │               │   │   │               │   ├── 4a8b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_protocol_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 52cb
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── lib_cdc_v1_0_rfs.vhd
│       │               │   │   │               │   ├── 59b0
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   └── blk_mem_gen_v8_3_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── blk_mem_gen_v8_3.v
│       │               │   │   │               │   ├── 6fc3
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_utils_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 779d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7db8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_pipe_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7e3a
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_infrastructure_v1_1_0.vh
│       │               │   │   │               │   │       └── axi_infrastructure_v1_1_vl_rfs.v
│       │               │   │   │               │   ├── 7ee0
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── generic_baseblocks_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 7efe
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_register_slice_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── a807
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.v
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.vhd
│       │               │   │   │               │   │   │   └── fifo_generator_v13_1_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── fifo_generator_vlog_beh.v
│       │               │   │   │               │   ├── ad02
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── floating_point_v7_1_vh_rfs.vhd
│       │               │   │   │               │   ├── b96d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axilite_bridge.vhd
│       │               │   │   │               │   ├── c9c4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── cf3b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_clock_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   └── f0ab
│       │               │   │   │               │       └── hdl
│       │               │   │   │               │           └── mult_gen_v12_0_vh_rfs.vhd
│       │               │   │   │               ├── opencldesign.bd
│       │               │   │   │               ├── opencldesign.bxml
│       │               │   │   │               └── opencldesign_ooc.xdc
│       │               │   │   └── ipiprj.xpr
│       │               │   ├── ipirun.tcl
│       │               │   ├── krnl_sum_scan_utilization_routed.rpt
│       │               │   ├── krnl_sum_scan_utilization_synthed.rpt
│       │               │   ├── map.tcl
│       │               │   ├── opencldesign.dcp
│       │               │   ├── opencldesign_ooc_copy.xdc
│       │               │   ├── opencldesign_routed.dcp
│       │               │   ├── opencldesign_timing_summary.rpt
│       │               │   ├── partial.bit
│       │               │   ├── platform_utilization_routed.rpt
│       │               │   ├── platform_utilization_synthed.rpt
│       │               │   ├── post_init.tcl
│       │               │   ├── _sdx_post_place.tcl
│       │               │   ├── _sdx_pre_place.tcl
│       │               │   ├── vivado_20524.backup.log
│       │               │   ├── vivado.jou
│       │               │   ├── vivado.log
│       │               │   ├── vivado.pb
│       │               │   ├── vivado_user.tcl
│       │               │   └── vivado_warning.txt
│       │               ├── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0_regiongen.log
│       │               ├── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0.xclbin
│       │               └── krnl_sum_scan.hw.xilinx_adm-pcie-7v3_1ddr_3_0.xml
│       └── kernels
│           └── krnl_sum_scan
│               ├── htr.txt
│               ├── ISEWrap.js
│               ├── ISEWrap.sh
│               ├── krnl_sum_scan
│               │   ├── hls_transform.tcl
│               │   ├── ip
│               │   │   ├── autoimpl.log
│               │   │   ├── auxiliary.xml
│               │   │   ├── bd
│               │   │   ├── component.xml
│               │   │   ├── constraints
│               │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   ├── doc
│               │   │   │   └── ReleaseNotes.txt
│               │   │   ├── drivers
│               │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │       ├── data
│               │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │       └── src
│               │   │   │           ├── Makefile
│               │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   ├── example
│               │   │   │   ├── ipi_example.sh
│               │   │   │   └── ipi_example.tcl
│               │   │   ├── hdl
│               │   │   │   ├── ip
│               │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   ├── verilog
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   └── vhdl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       └── krnl_sum_scan.vhd
│               │   │   ├── krnl_sum_scan_info.xml
│               │   │   ├── misc
│               │   │   │   └── logo.png
│               │   │   ├── pack.sh
│               │   │   ├── run_ippack.tcl
│               │   │   ├── subcore
│               │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   ├── tmp.cache
│               │   │   │   └── wt
│               │   │   │       └── project.wpc
│               │   │   ├── tmp.hw
│               │   │   │   └── tmp.lpr
│               │   │   ├── tmp.ip_user_files
│               │   │   ├── tmp.srcs
│               │   │   │   └── sources_1
│               │   │   │       └── ip
│               │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │               ├── hdl
│               │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │               ├── sim
│               │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │               └── synth
│               │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   ├── tmp.xpr
│               │   │   ├── vivado.jou
│               │   │   ├── vivado.log
│               │   │   ├── xgui
│               │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   ├── kernel.xml
│               │   ├── kernel.xml.orig
│               │   ├── krnl_sum_scan_clang.log
│               │   ├── krnl_sum_scan.clc.00.bc
│               │   ├── krnl_sum_scan.design.xml
│               │   ├── krnl_sum_scan_hls_transform.log
│               │   ├── krnl_sum_scan_hls_transform.pb
│               │   ├── krnl_sum_scan_kernelinfohash.log
│               │   ├── solution_OCL_REGION_0
│               │   │   ├── impl
│               │   │   │   ├── ip
│               │   │   │   │   ├── autoimpl.log
│               │   │   │   │   ├── auxiliary.xml
│               │   │   │   │   ├── bd
│               │   │   │   │   ├── component.xml
│               │   │   │   │   ├── constraints
│               │   │   │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   │   │   ├── doc
│               │   │   │   │   │   └── ReleaseNotes.txt
│               │   │   │   │   ├── drivers
│               │   │   │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │   │   │       ├── data
│               │   │   │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │   │   │       └── src
│               │   │   │   │   │           ├── Makefile
│               │   │   │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   │   │   ├── example
│               │   │   │   │   │   ├── ipi_example.sh
│               │   │   │   │   │   └── ipi_example.tcl
│               │   │   │   │   ├── hdl
│               │   │   │   │   │   ├── ip
│               │   │   │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │   ├── verilog
│               │   │   │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   │   │   └── vhdl
│               │   │   │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │   │   │       └── krnl_sum_scan.vhd
│               │   │   │   │   ├── krnl_sum_scan_info.xml
│               │   │   │   │   ├── misc
│               │   │   │   │   │   └── logo.png
│               │   │   │   │   ├── pack.sh
│               │   │   │   │   ├── run_ippack.tcl
│               │   │   │   │   ├── subcore
│               │   │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │   │   ├── tmp.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── tmp.hw
│               │   │   │   │   │   └── tmp.lpr
│               │   │   │   │   ├── tmp.ip_user_files
│               │   │   │   │   ├── tmp.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   ├── tmp.xpr
│               │   │   │   │   ├── vivado.jou
│               │   │   │   │   ├── vivado.log
│               │   │   │   │   ├── xgui
│               │   │   │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   │   │   ├── sdaccel
│               │   │   │   │   ├── kernel.xml
│               │   │   │   │   └── kernel.xo
│               │   │   │   ├── verilog
│               │   │   │   │   ├── extraction.tcl
│               │   │   │   │   ├── impl.sh
│               │   │   │   │   ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   ├── krnl_sum_scan.v
│               │   │   │   │   ├── krnl_sum_scan.xdc
│               │   │   │   │   ├── project.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── project.hw
│               │   │   │   │   │   └── project.lpr
│               │   │   │   │   ├── project.ip_user_files
│               │   │   │   │   ├── project.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   ├── project.xpr
│               │   │   │   │   ├── run_vivado.tcl
│               │   │   │   │   └── settings.tcl
│               │   │   │   └── vhdl
│               │   │   │       ├── extraction.tcl
│               │   │   │       ├── impl.sh
│               │   │   │       ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       ├── krnl_sum_scan.vhd
│               │   │   │       ├── krnl_sum_scan.xdc
│               │   │   │       ├── project.cache
│               │   │   │       │   └── wt
│               │   │   │       │       └── project.wpc
│               │   │   │       ├── project.hw
│               │   │   │       │   └── project.lpr
│               │   │   │       ├── project.ip_user_files
│               │   │   │       ├── project.srcs
│               │   │   │       │   └── sources_1
│               │   │   │       │       └── ip
│               │   │   │       │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │       │               ├── hdl
│               │   │   │       │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │       │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │       │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │       │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │       │               ├── sim
│               │   │   │       │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │       │               └── synth
│               │   │   │       │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │       ├── project.xpr
│               │   │   │       ├── run_vivado.tcl
│               │   │   │       └── settings.tcl
│               │   │   ├── solution_OCL_REGION_0.aps
│               │   │   ├── solution_OCL_REGION_0.directive
│               │   │   ├── solution_OCL_REGION_0.log
│               │   │   └── syn
│               │   │       ├── report
│               │   │       │   ├── krnl_sum_scan_csynth.rpt
│               │   │       │   └── krnl_sum_scan_csynth.xml
│               │   │       ├── systemc
│               │   │       │   ├── ACMP_fadd.h
│               │   │       │   ├── AESL_comp.h
│               │   │       │   ├── AESL_pkg.h
│               │   │       │   ├── krnl_sum_scan_1.cpp
│               │   │       │   ├── krnl_sum_scan_2.cpp
│               │   │       │   ├── krnl_sum_scan_3.cpp
│               │   │       │   ├── krnl_sum_scan_4.cpp
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.h
│               │   │       │   ├── krnl_sum_scan.h
│               │   │       │   └── krnl_sum_scan_sums.h
│               │   │       ├── verilog
│               │   │       │   ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │       │   ├── krnl_sum_scan_control_s_axi.v
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │       │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │       │   ├── krnl_sum_scan_sums.v
│               │   │       │   └── krnl_sum_scan.v
│               │   │       └── vhdl
│               │   │           ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │           ├── krnl_sum_scan_control_s_axi.vhd
│               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │           ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │           ├── krnl_sum_scan_sums.vhd
│               │   │           └── krnl_sum_scan.vhd
│               │   ├── vivado_hls.app
│               │   └── vivado_hls.log
│               ├── krnl_sum_scan.tcl
│               ├── rundef.js
│               ├── runme.bat
│               ├── runme.log
│               ├── runme.sh
│               ├── vivado_hls.log
│               └── vivado_hls.pb
├── _xocc_krnl_sum_scan_krnl_sum_scan.hw.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.dir
│   └── impl
│       ├── build
│       │   └── system
│       │       └── krnl_sum_scan.hw.xilinx_adm-pcie-ku3_2ddr-xpr_3_2
│       │           └── bitstream
│       │               ├── krnl_sum_scan.hw.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_ipi
│       │               │   ├── dont_partition.xdc
│       │               │   ├── ipiimpl
│       │               │   │   ├── ipiimpl.cache
│       │               │   │   │   └── wt
│       │               │   │   │       └── project.wpc
│       │               │   │   ├── ipiimpl.hw
│       │               │   │   │   └── ipiimpl.lpr
│       │               │   │   ├── ipiimpl.ip_user_files
│       │               │   │   ├── ipiimpl.runs
│       │               │   │   │   └── impl_1
│       │               │   │   │       ├── gen_run.xml
│       │               │   │   │       ├── hd_visual
│       │               │   │   │       │   ├── blockedBelsOutputs.tcl
│       │               │   │   │       │   ├── blockedBelsRouteThrus.tcl
│       │               │   │   │       │   ├── blockedPins.tcl
│       │               │   │   │       │   ├── blockedSitesInputs.tcl
│       │               │   │   │       │   ├── pblock_u_ocl_region_Placement_AllTiles.tcl
│       │               │   │   │       │   └── pblock_u_ocl_region_Routing_AllTiles.tcl
│       │               │   │   │       ├── htr.txt
│       │               │   │   │       ├── init_design.pb
│       │               │   │   │       ├── ISEWrap.js
│       │               │   │   │       ├── ISEWrap.sh
│       │               │   │   │       ├── krnl_sum_scan_utilization_placed.rpt
│       │               │   │   │       ├── opt_design.pb
│       │               │   │   │       ├── place_design.pb
│       │               │   │   │       ├── platform_utilization_placed.rpt
│       │               │   │   │       ├── project.wdf
│       │               │   │   │       ├── route_design.pb
│       │               │   │   │       ├── rundef.js
│       │               │   │   │       ├── runme.bat
│       │               │   │   │       ├── runme.log
│       │               │   │   │       ├── runme.sh
│       │               │   │   │       ├── vivado.jou
│       │               │   │   │       ├── vivado.pb
│       │               │   │   │       ├── xcl_design_wrapper_clock_utilization_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_control_sets_placed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_drc_opted.rpt
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.pb
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_drc_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper.hwdef
│       │               │   │   │       ├── xcl_design_wrapper_io_placed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_methodology_drc_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_methodology_drc_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_opt.dcp
│       │               │   │   │       ├── xcl_design_wrapper_placed.dcp
│       │               │   │   │       ├── xcl_design_wrapper_post_rci.dcp
│       │               │   │   │       ├── xcl_design_wrapper_power_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_power_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_power_summary_routed.pb
│       │               │   │   │       ├── xcl_design_wrapper_routed.dcp
│       │               │   │   │       ├── xcl_design_wrapper_route_status.pb
│       │               │   │   │       ├── xcl_design_wrapper_route_status.rpt
│       │               │   │   │       ├── xcl_design_wrapper.tcl
│       │               │   │   │       ├── xcl_design_wrapper_timing_summary_routed.rpt
│       │               │   │   │       ├── xcl_design_wrapper_timing_summary_routed.rpx
│       │               │   │   │       ├── xcl_design_wrapper_utilization_placed.pb
│       │               │   │   │       ├── xcl_design_wrapper_utilization_placed.rpt
│       │               │   │   │       └── xcl_design_wrapper.vdi
│       │               │   │   └── ipiimpl.xpr
│       │               │   ├── ipiprj
│       │               │   │   ├── ipiprj.cache
│       │               │   │   │   ├── ip
│       │               │   │   │   │   ├── 21b6f803ccd9a243
│       │               │   │   │   │   │   ├── 21b6f803ccd9a243.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_38_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_38_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_38_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_38_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_38_0_stub.vhdl
│       │               │   │   │   │   ├── 21b6f803ccd9a243.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 250f80ab3495f24c
│       │               │   │   │   │   │   ├── 250f80ab3495f24c.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_512_0_stub.vhdl
│       │               │   │   │   │   ├── 250f80ab3495f24c.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 4693c413b32165e5
│       │               │   │   │   │   │   ├── 4693c413b32165e5.xci
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_s00_regslice_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_s00_regslice_0_stub.vhdl
│       │               │   │   │   │   ├── 4693c413b32165e5.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 4f0b0aa931b20900
│       │               │   │   │   │   │   ├── 4f0b0aa931b20900.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_8_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_8_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_8_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_8_0_stub.vhdl
│       │               │   │   │   │   ├── 4f0b0aa931b20900.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 50ced8879548c2e0
│       │               │   │   │   │   │   ├── 50ced8879548c2e0.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_4_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_4_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_4_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_4_0_stub.vhdl
│       │               │   │   │   │   ├── 50ced8879548c2e0.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 58dd451b6e0b15e8
│       │               │   │   │   │   │   ├── 58dd451b6e0b15e8.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_1_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_1_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_1_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_1_0_stub.vhdl
│       │               │   │   │   │   ├── 58dd451b6e0b15e8.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 5f2c3190c735a710
│       │               │   │   │   │   │   ├── 5f2c3190c735a710.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_2_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_2_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_2_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_2_0_stub.vhdl
│       │               │   │   │   │   ├── 5f2c3190c735a710.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 71e32279cf517ddf
│       │               │   │   │   │   │   ├── 71e32279cf517ddf.xci
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_krnl_sum_scan_1_0_stub.vhdl
│       │               │   │   │   │   ├── 71e32279cf517ddf.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 9a0350651d62b52c
│       │               │   │   │   │   │   ├── 9a0350651d62b52c.xci
│       │               │   │   │   │   │   ├── opencldesign_kernel_sys_reset_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_kernel_sys_reset_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_kernel_sys_reset_0_stub.vhdl
│       │               │   │   │   │   ├── 9a0350651d62b52c.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 9c2cbd4f388624c9
│       │               │   │   │   │   │   ├── 9c2cbd4f388624c9.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_3_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_3_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_3_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_3_0_stub.vhdl
│       │               │   │   │   │   ├── 9c2cbd4f388624c9.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── 9dc3cc0593fb99cc
│       │               │   │   │   │   │   ├── 9dc3cc0593fb99cc.xci
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_master_bridge_0_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_master_bridge_0_0_stub.vhdl
│       │               │   │   │   │   ├── 9dc3cc0593fb99cc.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── b609b1a0875288fd
│       │               │   │   │   │   │   ├── b609b1a0875288fd.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_us_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_us_0_stub.vhdl
│       │               │   │   │   │   ├── b609b1a0875288fd.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── bf887a5c3771b81d
│       │               │   │   │   │   │   ├── bf887a5c3771b81d.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_64_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_64_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_64_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_64_0_stub.vhdl
│       │               │   │   │   │   ├── bf887a5c3771b81d.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── c01fd55ea76fb788
│       │               │   │   │   │   │   ├── c01fd55ea76fb788.xci
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_slave_bridge_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_slave_bridge_0_stub.vhdl
│       │               │   │   │   │   ├── c01fd55ea76fb788.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── eeb5f79491ea20d4
│       │               │   │   │   │   │   ├── eeb5f79491ea20d4.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_1_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_cc_1_stub.vhdl
│       │               │   │   │   │   ├── eeb5f79491ea20d4.logs
│       │               │   │   │   │   │   └── runme.log
│       │               │   │   │   │   ├── f27b28f890f9ae40
│       │               │   │   │   │   │   ├── f27b28f890f9ae40.xci
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_auto_cc_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_auto_cc_0_stub.vhdl
│       │               │   │   │   │   └── f27b28f890f9ae40.logs
│       │               │   │   │   │       └── runme.log
│       │               │   │   │   └── wt
│       │               │   │   │       ├── project.wpc
│       │               │   │   │       └── synthesis.wdf
│       │               │   │   ├── ipiprj.hw
│       │               │   │   │   └── ipiprj.lpr
│       │               │   │   ├── ipiprj.ip_user_files
│       │               │   │   ├── ipiprj.runs
│       │               │   │   │   ├── opencldesign_auto_cc_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.tcl
│       │               │   │   │   │   ├── opencldesign_auto_cc_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_cc_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_auto_cc_1_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── fsm_encoding.os
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.tcl
│       │               │   │   │   │   ├── opencldesign_auto_cc_1_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_cc_1_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_cc_1.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_auto_us_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │   │   ├── opencldesign_auto_us_0.tcl
│       │               │   │   │   │   ├── opencldesign_auto_us_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_auto_us_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_auto_us_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_interconnect_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.dcp
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.tcl
│       │               │   │   │   │   ├── opencldesign_interconnect_sys_reset_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_kernel_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.dcp
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.tcl
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_kernel_sys_reset_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_krnl_sum_scan_1_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_0_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_1_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0.dcp
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_sim_netlist.v
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_sim_netlist.vhdl
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_stub.v
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_stub.vhdl
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_s00_regslice_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.tcl
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_slave_bridge_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.tcl
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_1_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_2_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_3_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_38_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_38_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_38_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_38_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_38_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_38_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_4_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_512_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_64_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_8_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   └── synth_1
│       │               │   │   │       ├── dont_touch.xdc
│       │               │   │   │       ├── gen_run.xml
│       │               │   │   │       ├── htr.txt
│       │               │   │   │       ├── ISEWrap.js
│       │               │   │   │       ├── ISEWrap.sh
│       │               │   │   │       ├── opencldesign_wrapper.dcp
│       │               │   │   │       ├── opencldesign_wrapper.tcl
│       │               │   │   │       ├── opencldesign_wrapper_utilization_synth.pb
│       │               │   │   │       ├── opencldesign_wrapper_utilization_synth.rpt
│       │               │   │   │       ├── opencldesign_wrapper.vds
│       │               │   │   │       ├── project.wdf
│       │               │   │   │       ├── rundef.js
│       │               │   │   │       ├── runme.bat
│       │               │   │   │       ├── runme.log
│       │               │   │   │       ├── runme.sh
│       │               │   │   │       ├── vivado.jou
│       │               │   │   │       └── vivado.pb
│       │               │   │   ├── ipiprj.srcs
│       │               │   │   │   └── sources_1
│       │               │   │   │       └── bd
│       │               │   │   │           └── opencldesign
│       │               │   │   │               ├── hdl
│       │               │   │   │               │   ├── opencldesign.hwdef
│       │               │   │   │               │   ├── opencldesign.v
│       │               │   │   │               │   └── opencldesign_wrapper.v
│       │               │   │   │               ├── hw_handoff
│       │               │   │   │               │   ├── opencldesign_bd.tcl
│       │               │   │   │               │   └── opencldesign.hwh
│       │               │   │   │               ├── ip
│       │               │   │   │               │   ├── opencldesign_auto_cc_0
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   ├── opencldesign_auto_cc_1
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_1.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_cc_1.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_cc_1.v
│       │               │   │   │               │   ├── opencldesign_auto_us_0
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_us_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_us_0.v
│       │               │   │   │               │   ├── opencldesign_interconnect_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_interconnect_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_interconnect_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_interconnect_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_kernel_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_kernel_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_kernel_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_kernel_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_krnl_sum_scan_1_0
│       │               │   │   │               │   │   ├── constraints
│       │               │   │   │               │   │   │   └── krnl_sum_scan_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_krnl_sum_scan_1_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_krnl_sum_scan_1_0.v
│       │               │   │   │               │   ├── opencldesign_master_bridge_0_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   ├── opencldesign_master_bridge_1_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_1_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_1_0.vhd
│       │               │   │   │               │   ├── opencldesign_m_axi_interconnect_M00_AXI_0
│       │               │   │   │               │   │   ├── opencldesign_m_axi_interconnect_M00_AXI_0.xci
│       │               │   │   │               │   │   └── opencldesign_m_axi_interconnect_M00_AXI_0.xml
│       │               │   │   │               │   ├── opencldesign_s00_regslice_0
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xci
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   ├── opencldesign_s_axi_interconnect_0_0
│       │               │   │   │               │   │   ├── opencldesign_s_axi_interconnect_0_0.xci
│       │               │   │   │               │   │   └── opencldesign_s_axi_interconnect_0_0.xml
│       │               │   │   │               │   ├── opencldesign_slave_bridge_0
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0.xci
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_1_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_1_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_2_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_2_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_3_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_3_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_38_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_38_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_4_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_4_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_512_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_512_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_64_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_64_0.v
│       │               │   │   │               │   └── opencldesign_xlconstant_zero_8_0
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.dcp
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0_sim_netlist.v
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0_sim_netlist.vhdl
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0_stub.v
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0_stub.vhdl
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xci
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xml
│       │               │   │   │               │       └── sim
│       │               │   │   │               │           └── opencldesign_xlconstant_zero_8_0.v
│       │               │   │   │               ├── ipshared
│       │               │   │   │               │   ├── 04b4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── proc_sys_reset_v5_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 10b8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_data_fifo_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 1193
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axifull_bridge.vhd
│       │               │   │   │               │   ├── 1e87
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 218a
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── ip
│       │               │   │   │               │   │       │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│       │               │   │   │               │   │       └── verilog
│       │               │   │   │               │   │           ├── krnl_sum_scan_control_s_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_gmem_m_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_sums.v
│       │               │   │   │               │   │           └── krnl_sum_scan.v
│       │               │   │   │               │   ├── 403d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_bram18k_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 43f5
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_utils_v2_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 4a86
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_dwidth_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   │       └── axi_dwidth_converter_v2_1_vlsyn_rfs.v
│       │               │   │   │               │   ├── 4a8b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_protocol_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 52cb
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── lib_cdc_v1_0_rfs.vhd
│       │               │   │   │               │   ├── 59b0
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   └── blk_mem_gen_v8_3_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── blk_mem_gen_v8_3.v
│       │               │   │   │               │   ├── 6fc3
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_utils_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 779d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7db8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_pipe_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7e3a
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_infrastructure_v1_1_0.vh
│       │               │   │   │               │   │       └── axi_infrastructure_v1_1_vl_rfs.v
│       │               │   │   │               │   ├── 7ee0
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── generic_baseblocks_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 7efe
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_register_slice_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── a807
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.v
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.vhd
│       │               │   │   │               │   │   │   └── fifo_generator_v13_1_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── fifo_generator_vlog_beh.v
│       │               │   │   │               │   ├── ad02
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── floating_point_v7_1_vh_rfs.vhd
│       │               │   │   │               │   ├── b96d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axilite_bridge.vhd
│       │               │   │   │               │   ├── c9c4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── cf3b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_clock_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── e147
│       │               │   │   │               │   │   └── xlconstant.v
│       │               │   │   │               │   └── f0ab
│       │               │   │   │               │       └── hdl
│       │               │   │   │               │           └── mult_gen_v12_0_vh_rfs.vhd
│       │               │   │   │               ├── opencldesign.bd
│       │               │   │   │               ├── opencldesign.bxml
│       │               │   │   │               └── opencldesign_ooc.xdc
│       │               │   │   └── ipiprj.xpr
│       │               │   ├── ipirun.tcl
│       │               │   ├── krnl_sum_scan_utilization_routed.rpt
│       │               │   ├── krnl_sum_scan_utilization_synthed.rpt
│       │               │   ├── map.tcl
│       │               │   ├── opencldesign.dcp
│       │               │   ├── opencldesign_ooc_copy.xdc
│       │               │   ├── opencldesign_routed.dcp
│       │               │   ├── opencldesign_timing_summary.rpt
│       │               │   ├── platform_utilization_routed.rpt
│       │               │   ├── platform_utilization_synthed.rpt
│       │               │   ├── post_init.tcl
│       │               │   ├── _sdx_post_place.tcl
│       │               │   ├── _sdx_pre_place.tcl
│       │               │   ├── updated_full_design.dcp
│       │               │   ├── vivado_20425.backup.log
│       │               │   ├── vivado_error.txt
│       │               │   ├── vivado.jou
│       │               │   ├── vivado.log
│       │               │   ├── vivado.pb
│       │               │   └── vivado_user.tcl
│       │               ├── krnl_sum_scan.hw.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_regiongen.log
│       │               └── krnl_sum_scan.hw.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.xml
│       └── kernels
│           └── krnl_sum_scan
│               ├── htr.txt
│               ├── ISEWrap.js
│               ├── ISEWrap.sh
│               ├── krnl_sum_scan
│               │   ├── hls_transform.tcl
│               │   ├── ip
│               │   │   ├── autoimpl.log
│               │   │   ├── auxiliary.xml
│               │   │   ├── bd
│               │   │   ├── component.xml
│               │   │   ├── constraints
│               │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   ├── doc
│               │   │   │   └── ReleaseNotes.txt
│               │   │   ├── drivers
│               │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │       ├── data
│               │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │       └── src
│               │   │   │           ├── Makefile
│               │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   ├── example
│               │   │   │   ├── ipi_example.sh
│               │   │   │   └── ipi_example.tcl
│               │   │   ├── hdl
│               │   │   │   ├── ip
│               │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   ├── verilog
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   └── vhdl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       └── krnl_sum_scan.vhd
│               │   │   ├── krnl_sum_scan_info.xml
│               │   │   ├── misc
│               │   │   │   └── logo.png
│               │   │   ├── pack.sh
│               │   │   ├── run_ippack.tcl
│               │   │   ├── subcore
│               │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   ├── tmp.cache
│               │   │   │   └── wt
│               │   │   │       └── project.wpc
│               │   │   ├── tmp.hw
│               │   │   │   └── tmp.lpr
│               │   │   ├── tmp.ip_user_files
│               │   │   ├── tmp.srcs
│               │   │   │   └── sources_1
│               │   │   │       └── ip
│               │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │               ├── hdl
│               │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │               ├── sim
│               │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │               └── synth
│               │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   ├── tmp.xpr
│               │   │   ├── vivado.jou
│               │   │   ├── vivado.log
│               │   │   ├── xgui
│               │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   ├── kernel.xml
│               │   ├── kernel.xml.orig
│               │   ├── krnl_sum_scan_clang.log
│               │   ├── krnl_sum_scan.clc.00.bc
│               │   ├── krnl_sum_scan.design.xml
│               │   ├── krnl_sum_scan_hls_transform.log
│               │   ├── krnl_sum_scan_hls_transform.pb
│               │   ├── krnl_sum_scan_kernelinfohash.log
│               │   ├── solution_OCL_REGION_0
│               │   │   ├── impl
│               │   │   │   ├── ip
│               │   │   │   │   ├── autoimpl.log
│               │   │   │   │   ├── auxiliary.xml
│               │   │   │   │   ├── bd
│               │   │   │   │   ├── component.xml
│               │   │   │   │   ├── constraints
│               │   │   │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   │   │   ├── doc
│               │   │   │   │   │   └── ReleaseNotes.txt
│               │   │   │   │   ├── drivers
│               │   │   │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │   │   │       ├── data
│               │   │   │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │   │   │       └── src
│               │   │   │   │   │           ├── Makefile
│               │   │   │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   │   │   ├── example
│               │   │   │   │   │   ├── ipi_example.sh
│               │   │   │   │   │   └── ipi_example.tcl
│               │   │   │   │   ├── hdl
│               │   │   │   │   │   ├── ip
│               │   │   │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │   ├── verilog
│               │   │   │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   │   │   └── vhdl
│               │   │   │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │   │   │       └── krnl_sum_scan.vhd
│               │   │   │   │   ├── krnl_sum_scan_info.xml
│               │   │   │   │   ├── misc
│               │   │   │   │   │   └── logo.png
│               │   │   │   │   ├── pack.sh
│               │   │   │   │   ├── run_ippack.tcl
│               │   │   │   │   ├── subcore
│               │   │   │   │   │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │   │   ├── tmp.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── tmp.hw
│               │   │   │   │   │   └── tmp.lpr
│               │   │   │   │   ├── tmp.ip_user_files
│               │   │   │   │   ├── tmp.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   ├── tmp.xpr
│               │   │   │   │   ├── vivado.jou
│               │   │   │   │   ├── vivado.log
│               │   │   │   │   ├── xgui
│               │   │   │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   │   │   ├── sdaccel
│               │   │   │   │   ├── kernel.xml
│               │   │   │   │   └── kernel.xo
│               │   │   │   ├── verilog
│               │   │   │   │   ├── extraction.tcl
│               │   │   │   │   ├── impl.sh
│               │   │   │   │   ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   ├── krnl_sum_scan.v
│               │   │   │   │   ├── krnl_sum_scan.xdc
│               │   │   │   │   ├── project.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── project.hw
│               │   │   │   │   │   └── project.lpr
│               │   │   │   │   ├── project.ip_user_files
│               │   │   │   │   ├── project.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │   │   ├── project.xpr
│               │   │   │   │   ├── run_vivado.tcl
│               │   │   │   │   └── settings.tcl
│               │   │   │   └── vhdl
│               │   │   │       ├── extraction.tcl
│               │   │   │       ├── impl.sh
│               │   │   │       ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       ├── krnl_sum_scan.vhd
│               │   │   │       ├── krnl_sum_scan.xdc
│               │   │   │       ├── project.cache
│               │   │   │       │   └── wt
│               │   │   │       │       └── project.wpc
│               │   │   │       ├── project.hw
│               │   │   │       │   └── project.lpr
│               │   │   │       ├── project.ip_user_files
│               │   │   │       ├── project.srcs
│               │   │   │       │   └── sources_1
│               │   │   │       │       └── ip
│               │   │   │       │           └── krnl_sum_scan_ap_fadd_6_full_dsp_32
│               │   │   │       │               ├── hdl
│               │   │   │       │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │       │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │       │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │       │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xci
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_6_full_dsp_32.xml
│               │   │   │       │               ├── sim
│               │   │   │       │               │   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │       │               └── synth
│               │   │   │       │                   └── krnl_sum_scan_ap_fadd_6_full_dsp_32.vhd
│               │   │   │       ├── project.xpr
│               │   │   │       ├── run_vivado.tcl
│               │   │   │       └── settings.tcl
│               │   │   ├── solution_OCL_REGION_0.aps
│               │   │   ├── solution_OCL_REGION_0.directive
│               │   │   ├── solution_OCL_REGION_0.log
│               │   │   └── syn
│               │   │       ├── report
│               │   │       │   ├── krnl_sum_scan_csynth.rpt
│               │   │       │   └── krnl_sum_scan_csynth.xml
│               │   │       ├── systemc
│               │   │       │   ├── ACMP_fadd.h
│               │   │       │   ├── AESL_comp.h
│               │   │       │   ├── AESL_pkg.h
│               │   │       │   ├── krnl_sum_scan_1.cpp
│               │   │       │   ├── krnl_sum_scan_2.cpp
│               │   │       │   ├── krnl_sum_scan_3.cpp
│               │   │       │   ├── krnl_sum_scan_4.cpp
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.h
│               │   │       │   ├── krnl_sum_scan.h
│               │   │       │   └── krnl_sum_scan_sums.h
│               │   │       ├── verilog
│               │   │       │   ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │       │   ├── krnl_sum_scan_control_s_axi.v
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.v
│               │   │       │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │       │   ├── krnl_sum_scan_sums.v
│               │   │       │   └── krnl_sum_scan.v
│               │   │       └── vhdl
│               │   │           ├── krnl_sum_scan_ap_fadd_6_full_dsp_32_ip.tcl
│               │   │           ├── krnl_sum_scan_control_s_axi.vhd
│               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_8_full_dsp.vhd
│               │   │           ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │           ├── krnl_sum_scan_sums.vhd
│               │   │           └── krnl_sum_scan.vhd
│               │   ├── vivado_hls.app
│               │   └── vivado_hls.log
│               ├── krnl_sum_scan.tcl
│               ├── rundef.js
│               ├── runme.bat
│               ├── runme.log
│               ├── runme.sh
│               ├── vivado_hls.log
│               └── vivado_hls.pb
├── _xocc_krnl_sum_scan_krnl_sum_scan.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr_3_2.dir
│   └── impl
│       ├── build
│       │   └── system
│       │       └── krnl_sum_scan.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr_3_2
│       │           └── bitstream
│       │               ├── krnl_sum_scan.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr_3_2_ipi
│       │               │   ├── ipiprj
│       │               │   │   ├── ipiprj.cache
│       │               │   │   │   ├── ip
│       │               │   │   │   │   ├── 354ecbbfa6e74abb
│       │               │   │   │   │   │   ├── 354ecbbfa6e74abb.xci
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.v
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
│       │               │   │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_stub.v
│       │               │   │   │   │   │   └── opencldesign_xlconstant_zero_512_0_stub.vhdl
│       │               │   │   │   │   └── 354ecbbfa6e74abb.logs
│       │               │   │   │   │       └── runme.log
│       │               │   │   │   └── wt
│       │               │   │   │       ├── project.wpc
│       │               │   │   │       └── synthesis.wdf
│       │               │   │   ├── ipiprj.hw
│       │               │   │   │   └── ipiprj.lpr
│       │               │   │   ├── ipiprj.ip_user_files
│       │               │   │   ├── ipiprj.runs
│       │               │   │   │   ├── opencldesign_auto_cc_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_cc_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_auto_rs_w_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_rs_w_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_auto_us_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_auto_us_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_control_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_control_sys_reset_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_data_sys_reset_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_data_sys_reset_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_krnl_sum_scan_1_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_krnl_sum_scan_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_0_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_0_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_1_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_2_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_2_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_2_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_master_bridge_3_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_master_bridge_3_0.tcl
│       │               │   │   │   │   ├── opencldesign_master_bridge_3_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_s00_regslice_0_synth_1
│       │               │   │   │   │   ├── dont_touch.xdc
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_s00_regslice_0.tcl
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   └── runme.sh
│       │               │   │   │   ├── opencldesign_slave_bridge_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.tcl
│       │               │   │   │   │   ├── opencldesign_slave_bridge_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_1_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_1_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_2_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_2_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_3_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_3_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_34_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_34_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_34_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_4_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_4_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_512_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_utilization_synth.pb
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0_utilization_synth.rpt
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_512_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_64_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_64_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   ├── opencldesign_xlconstant_zero_8_0_synth_1
│       │               │   │   │   │   ├── gen_run.xml
│       │               │   │   │   │   ├── htr.txt
│       │               │   │   │   │   ├── ISEWrap.js
│       │               │   │   │   │   ├── ISEWrap.sh
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.tcl
│       │               │   │   │   │   ├── opencldesign_xlconstant_zero_8_0.vds
│       │               │   │   │   │   ├── rundef.js
│       │               │   │   │   │   ├── runme.bat
│       │               │   │   │   │   ├── runme.log
│       │               │   │   │   │   ├── runme.sh
│       │               │   │   │   │   ├── vivado.jou
│       │               │   │   │   │   └── vivado.pb
│       │               │   │   │   └── synth_1
│       │               │   │   │       ├── dont_touch.xdc
│       │               │   │   │       ├── gen_run.xml
│       │               │   │   │       ├── htr.txt
│       │               │   │   │       ├── ISEWrap.js
│       │               │   │   │       ├── ISEWrap.sh
│       │               │   │   │       ├── opencldesign_wrapper.tcl
│       │               │   │   │       ├── project.wdf
│       │               │   │   │       ├── rundef.js
│       │               │   │   │       ├── runme.bat
│       │               │   │   │       └── runme.sh
│       │               │   │   ├── ipiprj.srcs
│       │               │   │   │   └── sources_1
│       │               │   │   │       └── bd
│       │               │   │   │           └── opencldesign
│       │               │   │   │               ├── hdl
│       │               │   │   │               │   ├── opencldesign.hwdef
│       │               │   │   │               │   ├── opencldesign.v
│       │               │   │   │               │   └── opencldesign_wrapper.v
│       │               │   │   │               ├── hw_handoff
│       │               │   │   │               │   ├── opencldesign_bd.tcl
│       │               │   │   │               │   └── opencldesign.hwh
│       │               │   │   │               ├── ip
│       │               │   │   │               │   ├── opencldesign_auto_cc_0
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_cc_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_cc_0.v
│       │               │   │   │               │   ├── opencldesign_auto_rs_w_0
│       │               │   │   │               │   │   ├── opencldesign_auto_rs_w_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_rs_w_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_rs_w_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_rs_w_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_rs_w_0.v
│       │               │   │   │               │   ├── opencldesign_auto_us_0
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_clocks.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xci
│       │               │   │   │               │   │   ├── opencldesign_auto_us_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_auto_us_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_auto_us_0.v
│       │               │   │   │               │   ├── opencldesign_control_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_control_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_control_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_control_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_control_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_control_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_control_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_control_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_data_sys_reset_0
│       │               │   │   │               │   │   ├── opencldesign_data_sys_reset_0_board.xdc
│       │               │   │   │               │   │   ├── opencldesign_data_sys_reset_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_data_sys_reset_0.xci
│       │               │   │   │               │   │   ├── opencldesign_data_sys_reset_0.xdc
│       │               │   │   │               │   │   ├── opencldesign_data_sys_reset_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_data_sys_reset_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_data_sys_reset_0.vhd
│       │               │   │   │               │   ├── opencldesign_krnl_sum_scan_1_0
│       │               │   │   │               │   │   ├── constraints
│       │               │   │   │               │   │   │   └── krnl_sum_scan_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_krnl_sum_scan_1_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_krnl_sum_scan_1_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_krnl_sum_scan_1_0.v
│       │               │   │   │               │   ├── opencldesign_master_bridge_0_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_0_0.vhd
│       │               │   │   │               │   ├── opencldesign_master_bridge_1_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_1_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_1_0.vhd
│       │               │   │   │               │   ├── opencldesign_master_bridge_2_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_2_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_2_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_2_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_2_0.vhd
│       │               │   │   │               │   ├── opencldesign_master_bridge_3_0
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_3_0.xci
│       │               │   │   │               │   │   ├── opencldesign_master_bridge_3_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_master_bridge_3_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_master_bridge_3_0.vhd
│       │               │   │   │               │   ├── opencldesign_m_axi_interconnect_M00_AXI_0
│       │               │   │   │               │   │   ├── opencldesign_m_axi_interconnect_M00_AXI_0.xci
│       │               │   │   │               │   │   └── opencldesign_m_axi_interconnect_M00_AXI_0.xml
│       │               │   │   │               │   ├── opencldesign_s00_regslice_0
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0_ooc.xdc
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xci
│       │               │   │   │               │   │   ├── opencldesign_s00_regslice_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_s00_regslice_0.v
│       │               │   │   │               │   ├── opencldesign_s_axi_interconnect_0_0
│       │               │   │   │               │   │   ├── opencldesign_s_axi_interconnect_0_0.xci
│       │               │   │   │               │   │   └── opencldesign_s_axi_interconnect_0_0.xml
│       │               │   │   │               │   ├── opencldesign_slave_bridge_0
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0.xci
│       │               │   │   │               │   │   ├── opencldesign_slave_bridge_0.xml
│       │               │   │   │               │   │   ├── sim
│       │               │   │   │               │   │   │   └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               │   │   └── synth
│       │               │   │   │               │   │       └── opencldesign_slave_bridge_0.vhd
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_1_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_1_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_2_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_2_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_3_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_3_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_34_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_34_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_34_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_34_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_4_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_4_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_512_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.dcp
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_sim_netlist.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_stub.v
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0_stub.vhdl
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_512_0.v
│       │               │   │   │               │   ├── opencldesign_xlconstant_zero_64_0
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xci
│       │               │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xml
│       │               │   │   │               │   │   └── sim
│       │               │   │   │               │   │       └── opencldesign_xlconstant_zero_64_0.v
│       │               │   │   │               │   └── opencldesign_xlconstant_zero_8_0
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xci
│       │               │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xml
│       │               │   │   │               │       └── sim
│       │               │   │   │               │           └── opencldesign_xlconstant_zero_8_0.v
│       │               │   │   │               ├── ipshared
│       │               │   │   │               │   ├── 04b4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── proc_sys_reset_v5_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 10b8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_data_fifo_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 1193
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axifull_bridge.vhd
│       │               │   │   │               │   ├── 1e87
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 403d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_bram18k_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 43f5
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_utils_v2_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 4a86
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_dwidth_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   │       └── axi_dwidth_converter_v2_1_vlsyn_rfs.v
│       │               │   │   │               │   ├── 4a8b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_protocol_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 52cb
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── lib_cdc_v1_0_rfs.vhd
│       │               │   │   │               │   ├── 59b0
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   └── blk_mem_gen_v8_3_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── blk_mem_gen_v8_3.v
│       │               │   │   │               │   ├── 5f77
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── ip
│       │               │   │   │               │   │       │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│       │               │   │   │               │   │       └── verilog
│       │               │   │   │               │   │           ├── krnl_sum_scan_control_s_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_gmem_m_axi.v
│       │               │   │   │               │   │           ├── krnl_sum_scan_sums.v
│       │               │   │   │               │   │           └── krnl_sum_scan.v
│       │               │   │   │               │   ├── 6fc3
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_utils_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 779d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7db8
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_pipe_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── 7e3a
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       ├── axi_infrastructure_v1_1_0.vh
│       │               │   │   │               │   │       └── axi_infrastructure_v1_1_vl_rfs.v
│       │               │   │   │               │   ├── 7ee0
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── generic_baseblocks_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── 7efe
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_register_slice_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── a807
│       │               │   │   │               │   │   ├── hdl
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.v
│       │               │   │   │               │   │   │   ├── fifo_generator_v13_1_rfs.vhd
│       │               │   │   │               │   │   │   └── fifo_generator_v13_1_vhsyn_rfs.vhd
│       │               │   │   │               │   │   └── simulation
│       │               │   │   │               │   │       └── fifo_generator_vlog_beh.v
│       │               │   │   │               │   ├── ad02
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── floating_point_v7_1_vh_rfs.vhd
│       │               │   │   │               │   ├── b96d
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axilite_bridge.vhd
│       │               │   │   │               │   ├── c9c4
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│       │               │   │   │               │   ├── cf3b
│       │               │   │   │               │   │   └── hdl
│       │               │   │   │               │   │       └── axi_clock_converter_v2_1_vl_rfs.v
│       │               │   │   │               │   ├── e147
│       │               │   │   │               │   │   └── xlconstant.v
│       │               │   │   │               │   └── f0ab
│       │               │   │   │               │       └── hdl
│       │               │   │   │               │           └── mult_gen_v12_0_vh_rfs.vhd
│       │               │   │   │               ├── opencldesign.bd
│       │               │   │   │               ├── opencldesign.bxml
│       │               │   │   │               └── opencldesign_ooc.xdc
│       │               │   │   └── ipiprj.xpr
│       │               │   ├── ipirun.tcl
│       │               │   ├── map.tcl
│       │               │   ├── opencldesign_ooc_copy.xdc
│       │               │   ├── post_init.tcl
│       │               │   ├── vivado_11514.backup.log
│       │               │   ├── vivado.jou
│       │               │   ├── vivado.log
│       │               │   ├── vivado.pb
│       │               │   └── vivado_user.tcl
│       │               ├── krnl_sum_scan.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr_3_2_regiongen.log
│       │               └── krnl_sum_scan.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr_3_2.xml
│       └── kernels
│           └── krnl_sum_scan
│               ├── htr.txt
│               ├── ISEWrap.js
│               ├── ISEWrap.sh
│               ├── krnl_sum_scan
│               │   ├── hls_transform.tcl
│               │   ├── ip
│               │   │   ├── autoimpl.log
│               │   │   ├── auxiliary.xml
│               │   │   ├── bd
│               │   │   ├── component.xml
│               │   │   ├── constraints
│               │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   ├── doc
│               │   │   │   └── ReleaseNotes.txt
│               │   │   ├── drivers
│               │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │       ├── data
│               │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │       └── src
│               │   │   │           ├── Makefile
│               │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   ├── example
│               │   │   │   ├── ipi_example.sh
│               │   │   │   └── ipi_example.tcl
│               │   │   ├── hdl
│               │   │   │   ├── ip
│               │   │   │   │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   ├── verilog
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   └── vhdl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       └── krnl_sum_scan.vhd
│               │   │   ├── krnl_sum_scan_info.xml
│               │   │   ├── misc
│               │   │   │   └── logo.png
│               │   │   ├── pack.sh
│               │   │   ├── run_ippack.tcl
│               │   │   ├── subcore
│               │   │   │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │   ├── tmp.cache
│               │   │   │   └── wt
│               │   │   │       └── project.wpc
│               │   │   ├── tmp.hw
│               │   │   │   └── tmp.lpr
│               │   │   ├── tmp.ip_user_files
│               │   │   ├── tmp.srcs
│               │   │   │   └── sources_1
│               │   │   │       └── ip
│               │   │   │           └── krnl_sum_scan_ap_fadd_9_full_dsp_32
│               │   │   │               ├── hdl
│               │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xci
│               │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xml
│               │   │   │               ├── sim
│               │   │   │               │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │               └── synth
│               │   │   │                   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   ├── tmp.xpr
│               │   │   ├── vivado.jou
│               │   │   ├── vivado.log
│               │   │   ├── xgui
│               │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   ├── kernel.xml
│               │   ├── kernel.xml.orig
│               │   ├── krnl_sum_scan_clang.log
│               │   ├── krnl_sum_scan.clc.00.bc
│               │   ├── krnl_sum_scan.design.xml
│               │   ├── krnl_sum_scan_hls_transform.log
│               │   ├── krnl_sum_scan_hls_transform.pb
│               │   ├── krnl_sum_scan_kernelinfohash.log
│               │   ├── solution_OCL_REGION_0
│               │   │   ├── impl
│               │   │   │   ├── ip
│               │   │   │   │   ├── autoimpl.log
│               │   │   │   │   ├── auxiliary.xml
│               │   │   │   │   ├── bd
│               │   │   │   │   ├── component.xml
│               │   │   │   │   ├── constraints
│               │   │   │   │   │   └── krnl_sum_scan_ooc.xdc
│               │   │   │   │   ├── doc
│               │   │   │   │   │   └── ReleaseNotes.txt
│               │   │   │   │   ├── drivers
│               │   │   │   │   │   └── krnl_sum_scan_v1_0
│               │   │   │   │   │       ├── data
│               │   │   │   │   │       │   ├── krnl_sum_scan.mdd
│               │   │   │   │   │       │   └── krnl_sum_scan.tcl
│               │   │   │   │   │       └── src
│               │   │   │   │   │           ├── Makefile
│               │   │   │   │   │           ├── xkrnl_sum_scan.c
│               │   │   │   │   │           ├── xkrnl_sum_scan.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_hw.h
│               │   │   │   │   │           ├── xkrnl_sum_scan_linux.c
│               │   │   │   │   │           └── xkrnl_sum_scan_sinit.c
│               │   │   │   │   ├── example
│               │   │   │   │   │   ├── ipi_example.sh
│               │   │   │   │   │   └── ipi_example.tcl
│               │   │   │   │   ├── hdl
│               │   │   │   │   │   ├── ip
│               │   │   │   │   │   │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   │   │   ├── verilog
│               │   │   │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   │   │   └── krnl_sum_scan.v
│               │   │   │   │   │   └── vhdl
│               │   │   │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │   │   │       └── krnl_sum_scan.vhd
│               │   │   │   │   ├── krnl_sum_scan_info.xml
│               │   │   │   │   ├── misc
│               │   │   │   │   │   └── logo.png
│               │   │   │   │   ├── pack.sh
│               │   │   │   │   ├── run_ippack.tcl
│               │   │   │   │   ├── subcore
│               │   │   │   │   │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │   │   │   ├── tmp.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── tmp.hw
│               │   │   │   │   │   └── tmp.lpr
│               │   │   │   │   ├── tmp.ip_user_files
│               │   │   │   │   ├── tmp.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_9_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   │   ├── tmp.xpr
│               │   │   │   │   ├── vivado.jou
│               │   │   │   │   ├── vivado.log
│               │   │   │   │   ├── xgui
│               │   │   │   │   │   └── krnl_sum_scan_v1_0.tcl
│               │   │   │   │   └── xilinx_com_hls_krnl_sum_scan_1_0.zip
│               │   │   │   ├── sdaccel
│               │   │   │   │   ├── kernel.xml
│               │   │   │   │   └── kernel.xo
│               │   │   │   ├── verilog
│               │   │   │   │   ├── extraction.tcl
│               │   │   │   │   ├── impl.sh
│               │   │   │   │   ├── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │   │   │   ├── krnl_sum_scan_control_s_axi.v
│               │   │   │   │   ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.v
│               │   │   │   │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │   │   │   ├── krnl_sum_scan_sums.v
│               │   │   │   │   ├── krnl_sum_scan.v
│               │   │   │   │   ├── krnl_sum_scan.xdc
│               │   │   │   │   ├── project.cache
│               │   │   │   │   │   └── wt
│               │   │   │   │   │       └── project.wpc
│               │   │   │   │   ├── project.hw
│               │   │   │   │   │   └── project.lpr
│               │   │   │   │   ├── project.ip_user_files
│               │   │   │   │   ├── project.srcs
│               │   │   │   │   │   └── sources_1
│               │   │   │   │   │       └── ip
│               │   │   │   │   │           └── krnl_sum_scan_ap_fadd_9_full_dsp_32
│               │   │   │   │   │               ├── hdl
│               │   │   │   │   │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │   │   │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │   │   │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xci
│               │   │   │   │   │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xml
│               │   │   │   │   │               ├── sim
│               │   │   │   │   │               │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   │   │               └── synth
│               │   │   │   │   │                   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │   │   ├── project.xpr
│               │   │   │   │   ├── run_vivado.tcl
│               │   │   │   │   └── settings.tcl
│               │   │   │   └── vhdl
│               │   │   │       ├── extraction.tcl
│               │   │   │       ├── impl.sh
│               │   │   │       ├── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │   │       ├── krnl_sum_scan_control_s_axi.vhd
│               │   │   │       ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.vhd
│               │   │   │       ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │   │       ├── krnl_sum_scan_sums.vhd
│               │   │   │       ├── krnl_sum_scan.vhd
│               │   │   │       ├── krnl_sum_scan.xdc
│               │   │   │       ├── project.cache
│               │   │   │       │   └── wt
│               │   │   │       │       └── project.wpc
│               │   │   │       ├── project.hw
│               │   │   │       │   └── project.lpr
│               │   │   │       ├── project.ip_user_files
│               │   │   │       ├── project.srcs
│               │   │   │       │   └── sources_1
│               │   │   │       │       └── ip
│               │   │   │       │           └── krnl_sum_scan_ap_fadd_9_full_dsp_32
│               │   │   │       │               ├── hdl
│               │   │   │       │               │   ├── axi_utils_v2_0_vh_rfs.vhd
│               │   │   │       │               │   ├── floating_point_v7_1_vh_rfs.vhd
│               │   │   │       │               │   ├── mult_gen_v12_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_bram18k_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_addsub_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_multadd_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_dsp48_wrapper_v3_0_vh_rfs.vhd
│               │   │   │       │               │   ├── xbip_pipe_v3_0_vh_rfs.vhd
│               │   │   │       │               │   └── xbip_utils_v3_0_vh_rfs.vhd
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xci
│               │   │   │       │               ├── krnl_sum_scan_ap_fadd_9_full_dsp_32.xml
│               │   │   │       │               ├── sim
│               │   │   │       │               │   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │       │               └── synth
│               │   │   │       │                   └── krnl_sum_scan_ap_fadd_9_full_dsp_32.vhd
│               │   │   │       ├── project.xpr
│               │   │   │       ├── run_vivado.tcl
│               │   │   │       └── settings.tcl
│               │   │   ├── solution_OCL_REGION_0.aps
│               │   │   ├── solution_OCL_REGION_0.directive
│               │   │   ├── solution_OCL_REGION_0.log
│               │   │   └── syn
│               │   │       ├── report
│               │   │       │   ├── krnl_sum_scan_csynth.rpt
│               │   │       │   └── krnl_sum_scan_csynth.xml
│               │   │       ├── systemc
│               │   │       │   ├── ACMP_fadd.h
│               │   │       │   ├── AESL_comp.h
│               │   │       │   ├── AESL_pkg.h
│               │   │       │   ├── krnl_sum_scan_1.cpp
│               │   │       │   ├── krnl_sum_scan_2.cpp
│               │   │       │   ├── krnl_sum_scan_3.cpp
│               │   │       │   ├── krnl_sum_scan_4.cpp
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.h
│               │   │       │   ├── krnl_sum_scan.h
│               │   │       │   └── krnl_sum_scan_sums.h
│               │   │       ├── verilog
│               │   │       │   ├── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │       │   ├── krnl_sum_scan_control_s_axi.v
│               │   │       │   ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.v
│               │   │       │   ├── krnl_sum_scan_gmem_m_axi.v
│               │   │       │   ├── krnl_sum_scan_sums.v
│               │   │       │   └── krnl_sum_scan.v
│               │   │       └── vhdl
│               │   │           ├── krnl_sum_scan_ap_fadd_9_full_dsp_32_ip.tcl
│               │   │           ├── krnl_sum_scan_control_s_axi.vhd
│               │   │           ├── krnl_sum_scan_fadd_32ns_32ns_32_11_full_dsp.vhd
│               │   │           ├── krnl_sum_scan_gmem_m_axi.vhd
│               │   │           ├── krnl_sum_scan_sums.vhd
│               │   │           └── krnl_sum_scan.vhd
│               │   ├── vivado_hls.app
│               │   └── vivado_hls.log
│               ├── krnl_sum_scan.tcl
│               ├── rundef.js
│               ├── runme.bat
│               ├── runme.log
│               ├── runme.sh
│               ├── vivado_hls.log
│               └── vivado_hls.pb
├── _xocc_krnl_sum_scan_krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0.dir
│   └── impl
│       ├── build
│       │   ├── cpu_em
│       │   │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0
│       │   │       └── csim
│       │   │           ├── krnl_sum_scan
│       │   │           │   ├── hls_transform.tcl
│       │   │           │   ├── krnl_sum_scan_ar.log
│       │   │           │   ├── krnl_sum_scan.clc.00.bc
│       │   │           │   ├── krnl_sum_scan.clc.01.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu.o
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.s
│       │   │           │   ├── krnl_sum_scan.csim_cu.a
│       │   │           │   ├── krnl_sum_scan.csim_cu.o
│       │   │           │   ├── krnl_sum_scan_gpp.log
│       │   │           │   ├── krnl_sum_scan_hls_transform.log
│       │   │           │   ├── krnl_sum_scan_hls_transform.pb
│       │   │           │   ├── krnl_sum_scan_krnl_sum_scan_clang.log
│       │   │           │   ├── krnl_sum_scan_llc.log
│       │   │           │   ├── krnl_sum_scan_llvmlink.log
│       │   │           │   ├── krnl_sum_scan_objcopy.log
│       │   │           │   ├── krnl_sum_scan_opt.log
│       │   │           │   └── vivado_hls.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0_regiongen.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0.so
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0_top_gpp.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0.xclbin
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0_xcl_top_gpp.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0.xml
│       │   │           ├── obj
│       │   │           │   ├── xcl_top.CXXd
│       │   │           │   └── xcl_top.o
│       │   │           └── xcl_top.cpp
│       │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-7v3_1ddr_3_0_xclbincat.log
│       └── kernels
│           └── krnl_sum_scan
│               └── krnl_sum_scan
│                   ├── hls_transform.tcl
│                   ├── kernel.xml
│                   ├── kernel.xml.orig
│                   ├── krnl_sum_scan_clang.log
│                   ├── krnl_sum_scan.clc.00.bc
│                   ├── krnl_sum_scan_hls_transform.log
│                   ├── krnl_sum_scan_hls_transform.pb
│                   ├── krnl_sum_scan_kernelinfohash.log
│                   └── vivado_hls.log
├── _xocc_krnl_sum_scan_krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.dir
│   └── impl
│       ├── build
│       │   ├── cpu_em
│       │   │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1
│       │   │       └── csim
│       │   │           ├── krnl_sum_scan
│       │   │           │   ├── hls_transform.tcl
│       │   │           │   ├── krnl_sum_scan_ar.log
│       │   │           │   ├── krnl_sum_scan.clc.00.bc
│       │   │           │   ├── krnl_sum_scan.clc.01.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu.o
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.bc
│       │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.s
│       │   │           │   ├── krnl_sum_scan.csim_cu.a
│       │   │           │   ├── krnl_sum_scan.csim_cu.o
│       │   │           │   ├── krnl_sum_scan_gpp.log
│       │   │           │   ├── krnl_sum_scan_hls_transform.log
│       │   │           │   ├── krnl_sum_scan_krnl_sum_scan_clang.log
│       │   │           │   ├── krnl_sum_scan_llc.log
│       │   │           │   ├── krnl_sum_scan_llvmlink.log
│       │   │           │   ├── krnl_sum_scan_objcopy.log
│       │   │           │   ├── krnl_sum_scan_opt.log
│       │   │           │   └── vivado_hls.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_regiongen.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.so
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_top_gpp.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_xcl_top_gpp.log
│       │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xml
│       │   │           ├── obj
│       │   │           │   ├── xcl_top.CXXd
│       │   │           │   └── xcl_top.o
│       │   │           └── xcl_top.cpp
│       │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_xclbincat.log
│       └── kernels
│           └── krnl_sum_scan
│               └── krnl_sum_scan
│                   ├── hls_transform.tcl
│                   ├── kernel.xml
│                   ├── kernel.xml.orig
│                   ├── krnl_sum_scan_clang.log
│                   ├── krnl_sum_scan.clc.00.bc
│                   ├── krnl_sum_scan_hls_transform.log
│                   ├── krnl_sum_scan_kernelinfohash.log
│                   └── vivado_hls.log
└── _xocc_krnl_sum_scan_krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.dir
    └── impl
        ├── build
        │   ├── cpu_em
        │   │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2
        │   │       └── csim
        │   │           ├── krnl_sum_scan
        │   │           │   ├── hls_transform.tcl
        │   │           │   ├── krnl_sum_scan_ar.log
        │   │           │   ├── krnl_sum_scan.clc.00.bc
        │   │           │   ├── krnl_sum_scan.clc.01.bc
        │   │           │   ├── krnl_sum_scan.clc.csim_cu.bc
        │   │           │   ├── krnl_sum_scan.clc.csim_cu.o
        │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.bc
        │   │           │   ├── krnl_sum_scan.clc.csim_cu-opt.s
        │   │           │   ├── krnl_sum_scan.csim_cu.a
        │   │           │   ├── krnl_sum_scan.csim_cu.o
        │   │           │   ├── krnl_sum_scan_gpp.log
        │   │           │   ├── krnl_sum_scan_hls_transform.log
        │   │           │   ├── krnl_sum_scan_hls_transform.pb
        │   │           │   ├── krnl_sum_scan_krnl_sum_scan_clang.log
        │   │           │   ├── krnl_sum_scan_llc.log
        │   │           │   ├── krnl_sum_scan_llvmlink.log
        │   │           │   ├── krnl_sum_scan_objcopy.log
        │   │           │   ├── krnl_sum_scan_opt.log
        │   │           │   └── vivado_hls.log
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_regiongen.log
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.so
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_top_gpp.log
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.xclbin
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_xcl_top_gpp.log
        │   │           ├── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2.xml
        │   │           ├── obj
        │   │           │   ├── xcl_top.CXXd
        │   │           │   └── xcl_top.o
        │   │           └── xcl_top.cpp
        │   └── krnl_sum_scan.sw_emu.xilinx_adm-pcie-ku3_2ddr-xpr_3_2_xclbincat.log
        └── kernels
            └── krnl_sum_scan
                └── krnl_sum_scan
                    ├── hls_transform.tcl
                    ├── kernel.xml
                    ├── kernel.xml.orig
                    ├── krnl_sum_scan_clang.log
                    ├── krnl_sum_scan.clc.00.bc
                    ├── krnl_sum_scan_hls_transform.log
                    ├── krnl_sum_scan_hls_transform.pb
                    ├── krnl_sum_scan_kernelinfohash.log
                    └── vivado_hls.log

772 directories, 2286 files
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
emconfigutil --xdevice 'xilinx:adm-pcie-ku3:2ddr-xpr:3.2' --nd 1
```
Once the environment has been configured, the application can be executed by
```
./sum_scan
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
../../../utility/nimbix/nimbix-run.py ./sum_scan
```

***Copy the application files from the Developer to Runtime instances on Nimbix***
* Copy the application *.exe file and xclbin directory to the /data directory
* Launch the application using the Nimbix web interface as described in [Nimbix Getting Started Guide][]
* Make sure that the application launch options in the Nimbix web interface reflect the applications command line syntax
```
./sum_scan
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
SEP2016|1.0|Initial Release
DEC2016|2.0|Update for SDAccel 2016.3

[3-Clause BSD License]:../../../LICENSE.txt
[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx
[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation
[Nimbix Getting Started Guide]: http://www.xilinx.com/support/documentation/sw_manuals/xilinx2016_2/ug1240-sdaccel-nimbix-getting-started.pdf
[Walkthrough Video]: http://bcove.me/6pp0o482
[Nimbix Application Submission README]:../../../utility/nimbix/README.md
[Repository Contribution README]:../../../CONTRIBUTING.md
[SDaccel GUI README]:../../../GUIREADME.md
