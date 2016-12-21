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
├── data
│   ├── input.bmp
│   ├── rect_1024.bmp
│   ├── rect_32.bmp
│   ├── rect_512.bmp
│   ├── rect_64.bmp
│   └── sdaccel.bmp
├── description.json
├── emconfig.json
├── Makefile
├── README.md
├── src
│   ├── bit_io.cpp
│   ├── bit_io.h
│   ├── huffmancodec_naive.cpp
│   ├── huffmancodec_naive.h
│   ├── huffmancodec_optimized.cpp
│   ├── huffmancodec_optimized_cpuonly.cpp
│   ├── huffmancodec_optimized_cpuonly.h
│   ├── huffmancodec_optimized.h
│   ├── krnl_huffman.cl
│   ├── krnl_huffman_singleptr.cl
│   └── main.cpp
├── TempConfig
├── xclbin
│   └── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin
└── _xocc_krnl_huffman_singleptr_krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.dir
    └── impl
        ├── build
        │   ├── hw_em
        │   │   └── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1
        │   │       └── sv
        │   │           ├── decode
        │   │           │   ├── decode.ar.log
        │   │           │   ├── decode.clc.bc
        │   │           │   ├── decode.clc.noopt.bc
        │   │           │   ├── decode.clc.offline.bc
        │   │           │   ├── decode.clc.offline.o
        │   │           │   ├── decode.clc.offline.s
        │   │           │   ├── decode.gcc_archive.log
        │   │           │   ├── decode.hls.log
        │   │           │   ├── decode.llc.log
        │   │           │   ├── decode.llvmlink.log
        │   │           │   ├── decode.objcopy.log
        │   │           │   ├── decode.offline.a
        │   │           │   ├── decode.offline.o
        │   │           │   ├── decode.opt.log
        │   │           │   ├── hls_transform.tcl
        │   │           │   ├── krnl_huffman_singleptr.cl
        │   │           │   ├── krnl_huffman_singleptr.clang.log
        │   │           │   ├── krnl_huffman_singleptrclc.00.bc
        │   │           │   └── vivado_hls.log
        │   │           ├── encode
        │   │           │   ├── encode.ar.log
        │   │           │   ├── encode.clc.bc
        │   │           │   ├── encode.clc.noopt.bc
        │   │           │   ├── encode.clc.offline.bc
        │   │           │   ├── encode.clc.offline.o
        │   │           │   ├── encode.clc.offline.s
        │   │           │   ├── encode.gcc_archive.log
        │   │           │   ├── encode.hls.log
        │   │           │   ├── encode.llc.log
        │   │           │   ├── encode.llvmlink.log
        │   │           │   ├── encode.objcopy.log
        │   │           │   ├── encode.offline.a
        │   │           │   ├── encode.offline.o
        │   │           │   ├── encode.opt.log
        │   │           │   ├── hls_transform.tcl
        │   │           │   ├── krnl_huffman_singleptr.cl
        │   │           │   ├── krnl_huffman_singleptr.clang.log
        │   │           │   ├── krnl_huffman_singleptrclc.00.bc
        │   │           │   └── vivado_hls.log
        │   │           ├── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.gpp_so.log
        │   │           ├── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_ipi
        │   │           │   ├── ipiprj
        │   │           │   │   ├── ipiprj.cache
        │   │           │   │   │   └── wt
        │   │           │   │   │       ├── project.wpc
        │   │           │   │   │       └── xsim.wdf
        │   │           │   │   ├── ipiprj.hw
        │   │           │   │   │   └── ipiprj.lpr
        │   │           │   │   ├── ipiprj.ip_user_files
        │   │           │   │   │   ├── bd
        │   │           │   │   │   │   └── opencldesign
        │   │           │   │   │   │       ├── hdl
        │   │           │   │   │   │       │   └── opencldesign.v
        │   │           │   │   │   │       ├── ip
        │   │           │   │   │   │       │   ├── opencldesign_auto_cc_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_cc_0.v
        │   │           │   │   │   │       │   ├── opencldesign_auto_cc_1
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_cc_1.v
        │   │           │   │   │   │       │   ├── opencldesign_auto_rs_w_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_rs_w_0.v
        │   │           │   │   │   │       │   ├── opencldesign_auto_rs_w_1
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_rs_w_1.v
        │   │           │   │   │   │       │   ├── opencldesign_auto_us_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_us_0.v
        │   │           │   │   │   │       │   ├── opencldesign_auto_us_1
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_auto_us_1.v
        │   │           │   │   │   │       │   ├── opencldesign_c0_ddr_clk_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_c0_ddr_clk_0.v
        │   │           │   │   │   │       │   ├── opencldesign_c0_kernel_clk_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_c0_kernel_clk_0.v
        │   │           │   │   │   │       │   ├── opencldesign_c0_ui_clk_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_c0_ui_clk_0.v
        │   │           │   │   │   │       │   ├── opencldesign_c1_ddr_clk_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_c1_ddr_clk_0.v
        │   │           │   │   │   │       │   ├── opencldesign_decode_1_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_decode_1_0.v
        │   │           │   │   │   │       │   ├── opencldesign_encode_1_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_encode_1_0.v
        │   │           │   │   │   │       │   ├── opencldesign_m00_regslice_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_m00_regslice_0.v
        │   │           │   │   │   │       │   ├── opencldesign_m01_regslice_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_m01_regslice_0.v
        │   │           │   │   │   │       │   ├── opencldesign_master_bridge_0_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_master_bridge_0_0.vhd
        │   │           │   │   │   │       │   ├── opencldesign_master_bridge_1_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_master_bridge_1_0.vhd
        │   │           │   │   │   │       │   ├── opencldesign_s00_mmu_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_s00_mmu_0.v
        │   │           │   │   │   │       │   ├── opencldesign_s00_regslice_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_s00_regslice_0.v
        │   │           │   │   │   │       │   ├── opencldesign_s01_mmu_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_s01_mmu_0.v
        │   │           │   │   │   │       │   ├── opencldesign_s01_regslice_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_s01_regslice_0.v
        │   │           │   │   │   │       │   ├── opencldesign_sdaccel_generic_pcie_0_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_sdaccel_generic_pcie_0_0.sv
        │   │           │   │   │   │       │   ├── opencldesign_slave_bridge_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_slave_bridge_0.vhd
        │   │           │   │   │   │       │   ├── opencldesign_xbar_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xbar_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xbar_1
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xbar_1.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_1_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_1_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_2_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_2_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_3_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_3_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_38_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_38_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_4_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_4_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_512_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_512_0.v
        │   │           │   │   │   │       │   ├── opencldesign_xlconstant_zero_64_0
        │   │           │   │   │   │       │   │   └── sim
        │   │           │   │   │   │       │   │       └── opencldesign_xlconstant_zero_64_0.v
        │   │           │   │   │   │       │   └── opencldesign_xlconstant_zero_8_0
        │   │           │   │   │   │       │       └── sim
        │   │           │   │   │   │       │           └── opencldesign_xlconstant_zero_8_0.v
        │   │           │   │   │   │       └── ipshared
        │   │           │   │   │   │           └── xilinx.com
        │   │           │   │   │   │               ├── clk_gen_v1_0
        │   │           │   │   │   │               │   └── hdl
        │   │           │   │   │   │               │       └── clk_gen.v
        │   │           │   │   │   │               ├── ocl_axifull_bridge_v1_0
        │   │           │   │   │   │               │   └── hdl
        │   │           │   │   │   │               │       └── axifull_bridge.vhd
        │   │           │   │   │   │               ├── ocl_axilite_bridge_v1_0
        │   │           │   │   │   │               │   └── hdl
        │   │           │   │   │   │               │       └── axilite_bridge.vhd
        │   │           │   │   │   │               ├── sdaccel_generic_pcie_v1_0
        │   │           │   │   │   │               │   └── sim
        │   │           │   │   │   │               │       └── cmodel
        │   │           │   │   │   │               │           ├── libperformance_monitor.so
        │   │           │   │   │   │               │           └── libsdaccel_generic_pcie.so
        │   │           │   │   │   │               └── xlconstant_v1_1
        │   │           │   │   │   │                   └── xlconstant.v
        │   │           │   │   │   ├── ipstatic
        │   │           │   │   │   │   ├── axi_infrastructure_v1_1
        │   │           │   │   │   │   │   └── hdl
        │   │           │   │   │   │   │       └── verilog
        │   │           │   │   │   │   │           ├── axi_infrastructure_v1_1_0_header.vh
        │   │           │   │   │   │   │           ├── axi_infrastructure_v1_1_axi2vector.v
        │   │           │   │   │   │   │           ├── axi_infrastructure_v1_1_axic_srl_fifo.v
        │   │           │   │   │   │   │           └── axi_infrastructure_v1_1_vector2axi.v
        │   │           │   │   │   │   ├── decode_v1_0
        │   │           │   │   │   │   │   └── hdl
        │   │           │   │   │   │   │       └── verilog
        │   │           │   │   │   │   │           ├── decode_control_s_axi.v
        │   │           │   │   │   │   │           ├── decode_gmem_m_axi.v
        │   │           │   │   │   │   │           ├── decode_ht.v
        │   │           │   │   │   │   │           ├── decode_leaf_bitcodes.v
        │   │           │   │   │   │   │           ├── decode_leaf_symbols.v
        │   │           │   │   │   │   │           └── decode.v
        │   │           │   │   │   │   └── encode_v1_0
        │   │           │   │   │   │       └── hdl
        │   │           │   │   │   │           └── verilog
        │   │           │   │   │   │               ├── encode_alphabet_to_htree_node.v
        │   │           │   │   │   │               ├── encode_alphabet_usage.v
        │   │           │   │   │   │               ├── encode_control_s_axi.v
        │   │           │   │   │   │               ├── encode_gmem_m_axi.v
        │   │           │   │   │   │               ├── encode_ht.v
        │   │           │   │   │   │               ├── encode.v
        │   │           │   │   │   │               └── encode_visited.v
        │   │           │   │   │   └── README.txt
        │   │           │   │   ├── ipiprj.sim
        │   │           │   │   │   └── sim_1
        │   │           │   │   │       ├── behav
        │   │           │   │   │       │   ├── compile.log
        │   │           │   │   │       │   ├── compile.sh
        │   │           │   │   │       │   ├── elaborate.log
        │   │           │   │   │       │   ├── elaborate.sh
        │   │           │   │   │       │   ├── glbl.v
        │   │           │   │   │       │   ├── libperformance_monitor.so
        │   │           │   │   │       │   ├── libsdaccel_generic_pcie.so
        │   │           │   │   │       │   ├── opencldesign.tcl
        │   │           │   │   │       │   ├── opencldesign_vhdl.prj
        │   │           │   │   │       │   ├── opencldesign_vlog.prj
        │   │           │   │   │       │   ├── simulate.log
        │   │           │   │   │       │   ├── simulate.sh
        │   │           │   │   │       │   ├── simulate_sysemulation.sh
        │   │           │   │   │       │   ├── xelab.pb
        │   │           │   │   │       │   ├── xsim.dir
        │   │           │   │   │       │   │   ├── opencldesign_behav
        │   │           │   │   │       │   │   │   ├── Compile_Options.txt
        │   │           │   │   │       │   │   │   ├── xsim.dbg
        │   │           │   │   │       │   │   │   ├── xsimk
        │   │           │   │   │       │   │   │   ├── xsim.mem
        │   │           │   │   │       │   │   │   ├── xsim.reloc
        │   │           │   │   │       │   │   │   ├── xsim.rtti
        │   │           │   │   │       │   │   │   ├── xsim.svtype
        │   │           │   │   │       │   │   │   ├── xsim.type
        │   │           │   │   │       │   │   │   └── xsim.xdbg
        │   │           │   │   │       │   │   ├── xil_defaultlib
        │   │           │   │   │       │   │   │   ├── axifull_bridge.vdb
        │   │           │   │   │       │   │   │   ├── axilite_bridge.vdb
        │   │           │   │   │       │   │   │   ├── clk_gen.sdb
        │   │           │   │   │       │   │   │   ├── decode_control_s_axi.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_buffer.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_decoder.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_fifo.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_read.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_reg_slice.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_throttl.sdb
        │   │           │   │   │       │   │   │   ├── decode_gmem_m_axi_write.sdb
        │   │           │   │   │       │   │   │   ├── decode_ht_ram.sdb
        │   │           │   │   │       │   │   │   ├── decode_ht.sdb
        │   │           │   │   │       │   │   │   ├── decode_leaf_bitcodes_ram.sdb
        │   │           │   │   │       │   │   │   ├── decode_leaf_bitcodes.sdb
        │   │           │   │   │       │   │   │   ├── decode_leaf_symbols_ram.sdb
        │   │           │   │   │       │   │   │   ├── decode_leaf_symbols.sdb
        │   │           │   │   │       │   │   │   ├── decode.sdb
        │   │           │   │   │       │   │   │   ├── encode_alphabet_to_htree_node_ram.sdb
        │   │           │   │   │       │   │   │   ├── encode_alphabet_to_htree_node.sdb
        │   │           │   │   │       │   │   │   ├── encode_alphabet_usage_ram.sdb
        │   │           │   │   │       │   │   │   ├── encode_alphabet_usage.sdb
        │   │           │   │   │       │   │   │   ├── encode_control_s_axi.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_buffer.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_decoder.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_fifo.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_read.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_reg_slice.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_throttl.sdb
        │   │           │   │   │       │   │   │   ├── encode_gmem_m_axi_write.sdb
        │   │           │   │   │       │   │   │   ├── encode_ht_ram.sdb
        │   │           │   │   │       │   │   │   ├── encode_ht.sdb
        │   │           │   │   │       │   │   │   ├── encode.sdb
        │   │           │   │   │       │   │   │   ├── encode_visited_ram.sdb
        │   │           │   │   │       │   │   │   ├── encode_visited.sdb
        │   │           │   │   │       │   │   │   ├── glbl.sdb
        │   │           │   │   │       │   │   │   ├── m00_couplers_imp_14@w61@v9.sdb
        │   │           │   │   │       │   │   │   ├── m00_couplers_imp_17@o1@k@i@c.sdb
        │   │           │   │   │       │   │   │   ├── m01_couplers_imp_10@p@e@x@i@t.sdb
        │   │           │   │   │       │   │   │   ├── @o@c@l_@region_0_imp_11@y@r@h@r@e.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_cc_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_cc_1.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_rs_w_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_rs_w_1.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_us_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_auto_us_1.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_c0_ddr_clk_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_c0_kernel_clk_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_c0_ui_clk_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_c1_ddr_clk_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_decode_1_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_encode_1_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_m00_regslice_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_m01_regslice_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_master_bridge_0_0.vdb
        │   │           │   │   │       │   │   │   ├── opencldesign_master_bridge_1_0.vdb
        │   │           │   │   │       │   │   │   ├── opencldesign_m_axi_interconnect_@m00_@a@x@i_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_s00_mmu_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_s00_regslice_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_s01_mmu_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_s01_regslice_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_s_axi_interconnect_0_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_sdaccel_generic_pcie_0_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_slave_bridge_0.vdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xbar_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xbar_1.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_1_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_2_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_3_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_38_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_4_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_512_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_64_0.sdb
        │   │           │   │   │       │   │   │   ├── opencldesign_xlconstant_zero_8_0.sdb
        │   │           │   │   │       │   │   │   ├── s00_couplers_imp_13@g@m@k@v@a.sdb
        │   │           │   │   │       │   │   │   ├── s00_couplers_imp_@z@k@u@n@r@b.sdb
        │   │           │   │   │       │   │   │   ├── s01_couplers_imp_15@x0@z5@z.sdb
        │   │           │   │   │       │   │   │   ├── $unit_1.sdb
        │   │           │   │   │       │   │   │   ├── xil_defaultlib.rlx
        │   │           │   │   │       │   │   │   ├── xlconstant.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_array_single.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_async_rst.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_gray.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_handshake.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_pulse.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_single.sdb
        │   │           │   │   │       │   │   │   ├── xpm_cdc_sync_rst.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_base.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_dpdistram.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_dprom.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_sdpram.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_spram.sdb
        │   │           │   │   │       │   │   │   ├── xpm_memory_sprom.sdb
        │   │           │   │   │       │   │   │   └── xpm_memory_tdpram.sdb
        │   │           │   │   │       │   │   ├── xpm
        │   │           │   │   │       │   │   │   ├── vcomponents.vdb
        │   │           │   │   │       │   │   │   └── xpm.rlx
        │   │           │   │   │       │   │   └── xsim.svtype
        │   │           │   │   │       │   ├── xsim.ini
        │   │           │   │   │       │   ├── xsim.ini.bak
        │   │           │   │   │       │   ├── xvhdl.log
        │   │           │   │   │       │   ├── xvhdl.pb
        │   │           │   │   │       │   ├── xvlog.log
        │   │           │   │   │       │   └── xvlog.pb
        │   │           │   │   │       └── behav.xcix
        │   │           │   │   ├── ipiprj.srcs
        │   │           │   │   │   └── sources_1
        │   │           │   │   │       └── bd
        │   │           │   │   │           └── opencldesign
        │   │           │   │   │               ├── hdl
        │   │           │   │   │               │   ├── opencldesign.hwdef
        │   │           │   │   │               │   ├── opencldesign.v
        │   │           │   │   │               │   └── opencldesign_wrapper.v
        │   │           │   │   │               ├── hw_handoff
        │   │           │   │   │               │   ├── opencldesign_bd.tcl
        │   │           │   │   │               │   └── opencldesign.hwh
        │   │           │   │   │               ├── ip
        │   │           │   │   │               │   ├── opencldesign_auto_cc_0
        │   │           │   │   │               │   │   ├── opencldesign_auto_cc_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_cc_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_cc_0.v
        │   │           │   │   │               │   ├── opencldesign_auto_cc_1
        │   │           │   │   │               │   │   ├── opencldesign_auto_cc_1.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_cc_1.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_cc_1.v
        │   │           │   │   │               │   ├── opencldesign_auto_rs_w_0
        │   │           │   │   │               │   │   ├── opencldesign_auto_rs_w_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_rs_w_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_rs_w_0.v
        │   │           │   │   │               │   ├── opencldesign_auto_rs_w_1
        │   │           │   │   │               │   │   ├── opencldesign_auto_rs_w_1.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_rs_w_1.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_rs_w_1.v
        │   │           │   │   │               │   ├── opencldesign_auto_us_0
        │   │           │   │   │               │   │   ├── opencldesign_auto_us_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_us_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_us_0.v
        │   │           │   │   │               │   ├── opencldesign_auto_us_1
        │   │           │   │   │               │   │   ├── opencldesign_auto_us_1.xci
        │   │           │   │   │               │   │   ├── opencldesign_auto_us_1.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_auto_us_1.v
        │   │           │   │   │               │   ├── opencldesign_c0_ddr_clk_0
        │   │           │   │   │               │   │   ├── opencldesign_c0_ddr_clk_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_c0_ddr_clk_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_c0_ddr_clk_0.v
        │   │           │   │   │               │   ├── opencldesign_c0_kernel_clk_0
        │   │           │   │   │               │   │   ├── opencldesign_c0_kernel_clk_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_c0_kernel_clk_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_c0_kernel_clk_0.v
        │   │           │   │   │               │   ├── opencldesign_c0_ui_clk_0
        │   │           │   │   │               │   │   ├── opencldesign_c0_ui_clk_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_c0_ui_clk_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_c0_ui_clk_0.v
        │   │           │   │   │               │   ├── opencldesign_c1_ddr_clk_0
        │   │           │   │   │               │   │   ├── opencldesign_c1_ddr_clk_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_c1_ddr_clk_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_c1_ddr_clk_0.v
        │   │           │   │   │               │   ├── opencldesign_decode_1_0
        │   │           │   │   │               │   │   ├── constraints
        │   │           │   │   │               │   │   │   └── decode_ooc.xdc
        │   │           │   │   │               │   │   ├── opencldesign_decode_1_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_decode_1_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_decode_1_0.v
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_decode_1_0.v
        │   │           │   │   │               │   ├── opencldesign_encode_1_0
        │   │           │   │   │               │   │   ├── constraints
        │   │           │   │   │               │   │   │   └── encode_ooc.xdc
        │   │           │   │   │               │   │   ├── opencldesign_encode_1_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_encode_1_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_encode_1_0.v
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_encode_1_0.v
        │   │           │   │   │               │   ├── opencldesign_m00_regslice_0
        │   │           │   │   │               │   │   ├── opencldesign_m00_regslice_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_m00_regslice_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_m00_regslice_0.v
        │   │           │   │   │               │   ├── opencldesign_m01_regslice_0
        │   │           │   │   │               │   │   ├── opencldesign_m01_regslice_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_m01_regslice_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_m01_regslice_0.v
        │   │           │   │   │               │   ├── opencldesign_master_bridge_0_0
        │   │           │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_master_bridge_0_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_master_bridge_0_0.vhd
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_master_bridge_0_0.vhd
        │   │           │   │   │               │   ├── opencldesign_master_bridge_1_0
        │   │           │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_master_bridge_1_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_master_bridge_1_0.vhd
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_master_bridge_1_0.vhd
        │   │           │   │   │               │   ├── opencldesign_m_axi_interconnect_M00_AXI_0
        │   │           │   │   │               │   │   ├── opencldesign_m_axi_interconnect_M00_AXI_0.xci
        │   │           │   │   │               │   │   └── opencldesign_m_axi_interconnect_M00_AXI_0.xml
        │   │           │   │   │               │   ├── opencldesign_s00_mmu_0
        │   │           │   │   │               │   │   ├── opencldesign_s00_mmu_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_s00_mmu_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_s00_mmu_0.v
        │   │           │   │   │               │   ├── opencldesign_s00_regslice_0
        │   │           │   │   │               │   │   ├── opencldesign_s00_regslice_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_s00_regslice_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_s00_regslice_0.v
        │   │           │   │   │               │   ├── opencldesign_s01_mmu_0
        │   │           │   │   │               │   │   ├── opencldesign_s01_mmu_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_s01_mmu_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_s01_mmu_0.v
        │   │           │   │   │               │   ├── opencldesign_s01_regslice_0
        │   │           │   │   │               │   │   ├── opencldesign_s01_regslice_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_s01_regslice_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_s01_regslice_0.v
        │   │           │   │   │               │   ├── opencldesign_s_axi_interconnect_0_0
        │   │           │   │   │               │   │   ├── opencldesign_s_axi_interconnect_0_0.xci
        │   │           │   │   │               │   │   └── opencldesign_s_axi_interconnect_0_0.xml
        │   │           │   │   │               │   ├── opencldesign_sdaccel_generic_pcie_0_0
        │   │           │   │   │               │   │   ├── opencldesign_sdaccel_generic_pcie_0_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_sdaccel_generic_pcie_0_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_sdaccel_generic_pcie_0_0.sv
        │   │           │   │   │               │   ├── opencldesign_slave_bridge_0
        │   │           │   │   │               │   │   ├── opencldesign_slave_bridge_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_slave_bridge_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_slave_bridge_0.vhd
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_slave_bridge_0.vhd
        │   │           │   │   │               │   ├── opencldesign_xbar_0
        │   │           │   │   │               │   │   ├── opencldesign_xbar_0_ooc.xdc
        │   │           │   │   │               │   │   ├── opencldesign_xbar_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xbar_0.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_xbar_0.v
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_xbar_0.v
        │   │           │   │   │               │   ├── opencldesign_xbar_1
        │   │           │   │   │               │   │   ├── opencldesign_xbar_1_ooc.xdc
        │   │           │   │   │               │   │   ├── opencldesign_xbar_1.xci
        │   │           │   │   │               │   │   ├── opencldesign_xbar_1.xml
        │   │           │   │   │               │   │   ├── sim
        │   │           │   │   │               │   │   │   └── opencldesign_xbar_1.v
        │   │           │   │   │               │   │   └── synth
        │   │           │   │   │               │   │       └── opencldesign_xbar_1.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_1_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_1_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_1_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_2_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_2_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_2_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_3_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_3_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_3_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_38_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_38_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_38_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_4_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_4_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_4_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_512_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_512_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_512_0.v
        │   │           │   │   │               │   ├── opencldesign_xlconstant_zero_64_0
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xci
        │   │           │   │   │               │   │   ├── opencldesign_xlconstant_zero_64_0.xml
        │   │           │   │   │               │   │   └── sim
        │   │           │   │   │               │   │       └── opencldesign_xlconstant_zero_64_0.v
        │   │           │   │   │               │   └── opencldesign_xlconstant_zero_8_0
        │   │           │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xci
        │   │           │   │   │               │       ├── opencldesign_xlconstant_zero_8_0.xml
        │   │           │   │   │               │       └── sim
        │   │           │   │   │               │           └── opencldesign_xlconstant_zero_8_0.v
        │   │           │   │   │               ├── ipshared
        │   │           │   │   │               │   └── xilinx.com
        │   │           │   │   │               │       ├── axi_clock_converter_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_clock_converter_v2_1_axi_clock_converter.v
        │   │           │   │   │               │       │           ├── axi_clock_converter_v2_1_axic_sample_cycle_ratio.v
        │   │           │   │   │               │       │           └── axi_clock_converter_v2_1_axic_sync_clock_converter.v
        │   │           │   │   │               │       ├── axi_crossbar_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_addr_arbiter_sasd.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_addr_arbiter.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_addr_decoder.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_arbiter_resp.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_axi_crossbar.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_crossbar_sasd.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_crossbar.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_decerr_slave.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_si_transactor.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_splitter.v
        │   │           │   │   │               │       │           ├── axi_crossbar_v2_1_wdata_mux.v
        │   │           │   │   │               │       │           └── axi_crossbar_v2_1_wdata_router.v
        │   │           │   │   │               │       ├── axi_data_fifo_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_data_fifo_v2_1_axic_fifo.v
        │   │           │   │   │               │       │           ├── axi_data_fifo_v2_1_axic_reg_srl_fifo.v
        │   │           │   │   │               │       │           ├── axi_data_fifo_v2_1_axic_srl_fifo.v
        │   │           │   │   │               │       │           ├── axi_data_fifo_v2_1_axi_data_fifo.v
        │   │           │   │   │               │       │           ├── axi_data_fifo_v2_1_fifo_gen.v
        │   │           │   │   │               │       │           └── axi_data_fifo_v2_1_ndeep_srl.v
        │   │           │   │   │               │       ├── axi_dwidth_converter_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_a_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_a_upsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_axi4lite_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_axi4lite_upsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_axi_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_axi_upsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_b_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_r_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_r_upsizer_pktfifo.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_r_upsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_top.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_w_downsizer.v
        │   │           │   │   │               │       │           ├── axi_dwidth_converter_v2_1_w_upsizer_pktfifo.v
        │   │           │   │   │               │       │           └── axi_dwidth_converter_v2_1_w_upsizer.v
        │   │           │   │   │               │       ├── axi_infrastructure_v1_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_infrastructure_v1_1_0_header.vh
        │   │           │   │   │               │       │           ├── axi_infrastructure_v1_1_axi2vector.v
        │   │           │   │   │               │       │           ├── axi_infrastructure_v1_1_axic_srl_fifo.v
        │   │           │   │   │               │       │           └── axi_infrastructure_v1_1_vector2axi.v
        │   │           │   │   │               │       ├── axi_mmu_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_mmu_v2_1_addr_decoder.v
        │   │           │   │   │               │       │           ├── axi_mmu_v2_1_decerr_slave.v
        │   │           │   │   │               │       │           └── axi_mmu_v2_1_top.v
        │   │           │   │   │               │       ├── axi_protocol_converter_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_a_axi3_conv.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_axi3_conv.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_axilite_conv.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_axi_protocol_converter.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_ar_channel.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_aw_channel.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_b_channel.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_cmd_translator.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_incr_cmd.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_r_channel.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_simple_fifo.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_wrap_cmd.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_b_downsizer.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_decerr_slave.v
        │   │           │   │   │               │       │           ├── axi_protocol_converter_v2_1_r_axi3_conv.v
        │   │           │   │   │               │       │           └── axi_protocol_converter_v2_1_w_axi3_conv.v
        │   │           │   │   │               │       ├── axi_register_slice_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── axi_register_slice_v2_1_axic_register_slice.v
        │   │           │   │   │               │       │           └── axi_register_slice_v2_1_axi_register_slice.v
        │   │           │   │   │               │       ├── blk_mem_gen_v8_3
        │   │           │   │   │               │       │   ├── hdl
        │   │           │   │   │               │       │   │   ├── blk_mem_gen_v8_3.vhd
        │   │           │   │   │               │       │   │   └── blk_mem_gen_v8_3_vhsyn_rfs.vhd
        │   │           │   │   │               │       │   └── simulation
        │   │           │   │   │               │       │       └── blk_mem_gen_v8_3.v
        │   │           │   │   │               │       ├── clk_gen_v1_0
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── clk_gen.v
        │   │           │   │   │               │       ├── decode_v1_0
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── decode_control_s_axi.v
        │   │           │   │   │               │       │           ├── decode_gmem_m_axi.v
        │   │           │   │   │               │       │           ├── decode_ht.v
        │   │           │   │   │               │       │           ├── decode_leaf_bitcodes.v
        │   │           │   │   │               │       │           ├── decode_leaf_symbols.v
        │   │           │   │   │               │       │           └── decode.v
        │   │           │   │   │               │       ├── encode_v1_0
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── encode_alphabet_to_htree_node.v
        │   │           │   │   │               │       │           ├── encode_alphabet_usage.v
        │   │           │   │   │               │       │           ├── encode_control_s_axi.v
        │   │           │   │   │               │       │           ├── encode_gmem_m_axi.v
        │   │           │   │   │               │       │           ├── encode_ht.v
        │   │           │   │   │               │       │           ├── encode.v
        │   │           │   │   │               │       │           └── encode_visited.v
        │   │           │   │   │               │       ├── fifo_generator_v13_1
        │   │           │   │   │               │       │   ├── hdl
        │   │           │   │   │               │       │   │   ├── fifo_generator_v13_1_rfs.v
        │   │           │   │   │               │       │   │   ├── fifo_generator_v13_1_rfs.vhd
        │   │           │   │   │               │       │   │   ├── fifo_generator_v13_1.vhd
        │   │           │   │   │               │       │   │   └── fifo_generator_v13_1_vhsyn_rfs.vhd
        │   │           │   │   │               │       │   └── simulation
        │   │           │   │   │               │       │       └── fifo_generator_vlog_beh.v
        │   │           │   │   │               │       ├── generic_baseblocks_v2_1
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── verilog
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_carry_and.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_carry_latch_and.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_carry_latch_or.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_carry_or.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_carry.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_command_fifo.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_mask_static.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_mask.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_sel_mask_static.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_sel_mask.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_sel_static.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_sel.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator_static.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_comparator.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_mux_enc.v
        │   │           │   │   │               │       │           ├── generic_baseblocks_v2_1_mux.v
        │   │           │   │   │               │       │           └── generic_baseblocks_v2_1_nto1_mux.v
        │   │           │   │   │               │       ├── ocl_axifull_bridge_v1_0
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── axifull_bridge.vhd
        │   │           │   │   │               │       ├── ocl_axilite_bridge_v1_0
        │   │           │   │   │               │       │   └── hdl
        │   │           │   │   │               │       │       └── axilite_bridge.vhd
        │   │           │   │   │               │       ├── sdaccel_generic_pcie_v1_0
        │   │           │   │   │               │       │   └── sim
        │   │           │   │   │               │       │       └── cmodel
        │   │           │   │   │               │       │           ├── libperformance_monitor.so
        │   │           │   │   │               │       │           └── libsdaccel_generic_pcie.so
        │   │           │   │   │               │       └── xlconstant_v1_1
        │   │           │   │   │               │           └── xlconstant.v
        │   │           │   │   │               ├── opencldesign.bd
        │   │           │   │   │               ├── opencldesign.bxml
        │   │           │   │   │               └── opencldesign_ooc.xdc
        │   │           │   │   └── ipiprj.xpr
        │   │           │   ├── ipirun.tcl
        │   │           │   ├── map.tcl
        │   │           │   ├── opencldesign_ooc_copy.xdc
        │   │           │   ├── sdaccel.jou
        │   │           │   ├── sdaccel.log
        │   │           │   └── vivado.log
        │   │           ├── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.ipiMapping
        │   │           ├── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_regiongen.log
        │   │           ├── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin
        │   │           └── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xml
        │   └── krnl_huffman.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_1_xclbincat.log
        └── kernels
            ├── decode
            │   ├── decode
            │   │   ├── decode_clang.log
            │   │   ├── decode.clc.00.bc
            │   │   ├── decode.design.xml
            │   │   ├── decode_hls_transform.log
            │   │   ├── decode_kernelinfohash.log
            │   │   ├── hls_transform.tcl
            │   │   ├── ip
            │   │   │   ├── autoimpl.log
            │   │   │   ├── auxiliary.xml
            │   │   │   ├── bd
            │   │   │   ├── component.xml
            │   │   │   ├── constraints
            │   │   │   │   └── decode_ooc.xdc
            │   │   │   ├── decode_info.xml
            │   │   │   ├── doc
            │   │   │   │   └── ReleaseNotes.txt
            │   │   │   ├── drivers
            │   │   │   │   └── decode_v1_0
            │   │   │   │       ├── data
            │   │   │   │       │   ├── decode.mdd
            │   │   │   │       │   └── decode.tcl
            │   │   │   │       └── src
            │   │   │   │           ├── Makefile
            │   │   │   │           ├── xdecode.c
            │   │   │   │           ├── xdecode.h
            │   │   │   │           ├── xdecode_hw.h
            │   │   │   │           ├── xdecode_linux.c
            │   │   │   │           └── xdecode_sinit.c
            │   │   │   ├── example
            │   │   │   │   ├── ipi_example.sh
            │   │   │   │   └── ipi_example.tcl
            │   │   │   ├── hdl
            │   │   │   │   ├── verilog
            │   │   │   │   │   ├── decode_control_s_axi.v
            │   │   │   │   │   ├── decode_gmem_m_axi.v
            │   │   │   │   │   ├── decode_ht.v
            │   │   │   │   │   ├── decode_leaf_bitcodes.v
            │   │   │   │   │   ├── decode_leaf_symbols.v
            │   │   │   │   │   └── decode.v
            │   │   │   │   └── vhdl
            │   │   │   │       ├── decode_control_s_axi.vhd
            │   │   │   │       ├── decode_gmem_m_axi.vhd
            │   │   │   │       ├── decode_ht.vhd
            │   │   │   │       ├── decode_leaf_bitcodes.vhd
            │   │   │   │       ├── decode_leaf_symbols.vhd
            │   │   │   │       └── decode.vhd
            │   │   │   ├── misc
            │   │   │   │   └── logo.png
            │   │   │   ├── pack.sh
            │   │   │   ├── run_ippack.tcl
            │   │   │   ├── subcore
            │   │   │   ├── vivado.jou
            │   │   │   ├── vivado.log
            │   │   │   ├── xgui
            │   │   │   │   └── decode_v1_0.tcl
            │   │   │   └── xilinx_com_hls_decode_1_0.zip
            │   │   ├── kernel.xml
            │   │   ├── kernel.xml.orig
            │   │   ├── solution_OCL_REGION_0
            │   │   │   ├── impl
            │   │   │   │   ├── ip
            │   │   │   │   │   ├── autoimpl.log
            │   │   │   │   │   ├── auxiliary.xml
            │   │   │   │   │   ├── bd
            │   │   │   │   │   ├── component.xml
            │   │   │   │   │   ├── constraints
            │   │   │   │   │   │   └── decode_ooc.xdc
            │   │   │   │   │   ├── decode_info.xml
            │   │   │   │   │   ├── doc
            │   │   │   │   │   │   └── ReleaseNotes.txt
            │   │   │   │   │   ├── drivers
            │   │   │   │   │   │   └── decode_v1_0
            │   │   │   │   │   │       ├── data
            │   │   │   │   │   │       │   ├── decode.mdd
            │   │   │   │   │   │       │   └── decode.tcl
            │   │   │   │   │   │       └── src
            │   │   │   │   │   │           ├── Makefile
            │   │   │   │   │   │           ├── xdecode.c
            │   │   │   │   │   │           ├── xdecode.h
            │   │   │   │   │   │           ├── xdecode_hw.h
            │   │   │   │   │   │           ├── xdecode_linux.c
            │   │   │   │   │   │           └── xdecode_sinit.c
            │   │   │   │   │   ├── example
            │   │   │   │   │   │   ├── ipi_example.sh
            │   │   │   │   │   │   └── ipi_example.tcl
            │   │   │   │   │   ├── hdl
            │   │   │   │   │   │   ├── verilog
            │   │   │   │   │   │   │   ├── decode_control_s_axi.v
            │   │   │   │   │   │   │   ├── decode_gmem_m_axi.v
            │   │   │   │   │   │   │   ├── decode_ht.v
            │   │   │   │   │   │   │   ├── decode_leaf_bitcodes.v
            │   │   │   │   │   │   │   ├── decode_leaf_symbols.v
            │   │   │   │   │   │   │   └── decode.v
            │   │   │   │   │   │   └── vhdl
            │   │   │   │   │   │       ├── decode_control_s_axi.vhd
            │   │   │   │   │   │       ├── decode_gmem_m_axi.vhd
            │   │   │   │   │   │       ├── decode_ht.vhd
            │   │   │   │   │   │       ├── decode_leaf_bitcodes.vhd
            │   │   │   │   │   │       ├── decode_leaf_symbols.vhd
            │   │   │   │   │   │       └── decode.vhd
            │   │   │   │   │   ├── misc
            │   │   │   │   │   │   └── logo.png
            │   │   │   │   │   ├── pack.sh
            │   │   │   │   │   ├── run_ippack.tcl
            │   │   │   │   │   ├── subcore
            │   │   │   │   │   ├── vivado.jou
            │   │   │   │   │   ├── vivado.log
            │   │   │   │   │   ├── xgui
            │   │   │   │   │   │   └── decode_v1_0.tcl
            │   │   │   │   │   └── xilinx_com_hls_decode_1_0.zip
            │   │   │   │   ├── sdaccel
            │   │   │   │   │   ├── kernel.xml
            │   │   │   │   │   └── kernel.xo
            │   │   │   │   ├── verilog
            │   │   │   │   │   ├── decode_control_s_axi.v
            │   │   │   │   │   ├── decode_gmem_m_axi.v
            │   │   │   │   │   ├── decode_ht.v
            │   │   │   │   │   ├── decode_leaf_bitcodes.v
            │   │   │   │   │   ├── decode_leaf_symbols.v
            │   │   │   │   │   ├── decode.v
            │   │   │   │   │   ├── decode.xdc
            │   │   │   │   │   ├── extraction.tcl
            │   │   │   │   │   ├── impl.sh
            │   │   │   │   │   ├── project.cache
            │   │   │   │   │   │   └── wt
            │   │   │   │   │   │       └── project.wpc
            │   │   │   │   │   ├── project.hw
            │   │   │   │   │   │   └── project.lpr
            │   │   │   │   │   ├── project.ip_user_files
            │   │   │   │   │   ├── project.xpr
            │   │   │   │   │   ├── run_vivado.tcl
            │   │   │   │   │   └── settings.tcl
            │   │   │   │   └── vhdl
            │   │   │   │       ├── decode_control_s_axi.vhd
            │   │   │   │       ├── decode_gmem_m_axi.vhd
            │   │   │   │       ├── decode_ht.vhd
            │   │   │   │       ├── decode_leaf_bitcodes.vhd
            │   │   │   │       ├── decode_leaf_symbols.vhd
            │   │   │   │       ├── decode.vhd
            │   │   │   │       ├── decode.xdc
            │   │   │   │       ├── extraction.tcl
            │   │   │   │       ├── impl.sh
            │   │   │   │       ├── project.cache
            │   │   │   │       │   └── wt
            │   │   │   │       │       └── project.wpc
            │   │   │   │       ├── project.hw
            │   │   │   │       │   └── project.lpr
            │   │   │   │       ├── project.ip_user_files
            │   │   │   │       ├── project.xpr
            │   │   │   │       ├── run_vivado.tcl
            │   │   │   │       └── settings.tcl
            │   │   │   ├── solution_OCL_REGION_0.aps
            │   │   │   ├── solution_OCL_REGION_0.directive
            │   │   │   ├── solution_OCL_REGION_0.log
            │   │   │   └── syn
            │   │   │       ├── report
            │   │   │       │   ├── decode_csynth.rpt
            │   │   │       │   └── decode_csynth.xml
            │   │   │       ├── systemc
            │   │   │       │   ├── decode_1.cpp
            │   │   │       │   ├── decode_2.cpp
            │   │   │       │   ├── decode_3.cpp
            │   │   │       │   ├── decode_4.cpp
            │   │   │       │   ├── decode.h
            │   │   │       │   ├── decode_ht.h
            │   │   │       │   ├── decode_leaf_bitcodes.h
            │   │   │       │   └── decode_leaf_symbols.h
            │   │   │       ├── verilog
            │   │   │       │   ├── decode_control_s_axi.v
            │   │   │       │   ├── decode_gmem_m_axi.v
            │   │   │       │   ├── decode_ht.v
            │   │   │       │   ├── decode_leaf_bitcodes.v
            │   │   │       │   ├── decode_leaf_symbols.v
            │   │   │       │   └── decode.v
            │   │   │       └── vhdl
            │   │   │           ├── decode_control_s_axi.vhd
            │   │   │           ├── decode_gmem_m_axi.vhd
            │   │   │           ├── decode_ht.vhd
            │   │   │           ├── decode_leaf_bitcodes.vhd
            │   │   │           ├── decode_leaf_symbols.vhd
            │   │   │           └── decode.vhd
            │   │   ├── vivado_hls.app
            │   │   ├── vivado_hls.log
            │   │   ├── xcl_tmp.bc
            │   │   └── xcl_tmp.cpp
            │   ├── decode.tcl
            │   ├── htr.txt
            │   ├── ISEWrap.js
            │   ├── ISEWrap.sh
            │   ├── rundef.js
            │   ├── runme.bat
            │   ├── runme.log
            │   ├── runme.sh
            │   └── vivado_hls.log
            └── encode
                ├── encode
                │   ├── encode_clang.log
                │   ├── encode.clc.00.bc
                │   ├── encode.design.xml
                │   ├── encode_hls_transform.log
                │   ├── encode_kernelinfohash.log
                │   ├── hls_transform.tcl
                │   ├── ip
                │   │   ├── autoimpl.log
                │   │   ├── auxiliary.xml
                │   │   ├── bd
                │   │   ├── component.xml
                │   │   ├── constraints
                │   │   │   └── encode_ooc.xdc
                │   │   ├── doc
                │   │   │   └── ReleaseNotes.txt
                │   │   ├── drivers
                │   │   │   └── encode_v1_0
                │   │   │       ├── data
                │   │   │       │   ├── encode.mdd
                │   │   │       │   └── encode.tcl
                │   │   │       └── src
                │   │   │           ├── Makefile
                │   │   │           ├── xencode.c
                │   │   │           ├── xencode.h
                │   │   │           ├── xencode_hw.h
                │   │   │           ├── xencode_linux.c
                │   │   │           └── xencode_sinit.c
                │   │   ├── encode_info.xml
                │   │   ├── example
                │   │   │   ├── ipi_example.sh
                │   │   │   └── ipi_example.tcl
                │   │   ├── hdl
                │   │   │   ├── verilog
                │   │   │   │   ├── encode_alphabet_to_htree_node.v
                │   │   │   │   ├── encode_alphabet_usage.v
                │   │   │   │   ├── encode_control_s_axi.v
                │   │   │   │   ├── encode_gmem_m_axi.v
                │   │   │   │   ├── encode_ht.v
                │   │   │   │   ├── encode.v
                │   │   │   │   └── encode_visited.v
                │   │   │   └── vhdl
                │   │   │       ├── encode_alphabet_to_htree_node.vhd
                │   │   │       ├── encode_alphabet_usage.vhd
                │   │   │       ├── encode_control_s_axi.vhd
                │   │   │       ├── encode_gmem_m_axi.vhd
                │   │   │       ├── encode_ht.vhd
                │   │   │       ├── encode.vhd
                │   │   │       └── encode_visited.vhd
                │   │   ├── misc
                │   │   │   └── logo.png
                │   │   ├── pack.sh
                │   │   ├── run_ippack.tcl
                │   │   ├── subcore
                │   │   ├── vivado.jou
                │   │   ├── vivado.log
                │   │   ├── xgui
                │   │   │   └── encode_v1_0.tcl
                │   │   └── xilinx_com_hls_encode_1_0.zip
                │   ├── kernel.xml
                │   ├── kernel.xml.orig
                │   ├── solution_OCL_REGION_0
                │   │   ├── impl
                │   │   │   ├── ip
                │   │   │   │   ├── autoimpl.log
                │   │   │   │   ├── auxiliary.xml
                │   │   │   │   ├── bd
                │   │   │   │   ├── component.xml
                │   │   │   │   ├── constraints
                │   │   │   │   │   └── encode_ooc.xdc
                │   │   │   │   ├── doc
                │   │   │   │   │   └── ReleaseNotes.txt
                │   │   │   │   ├── drivers
                │   │   │   │   │   └── encode_v1_0
                │   │   │   │   │       ├── data
                │   │   │   │   │       │   ├── encode.mdd
                │   │   │   │   │       │   └── encode.tcl
                │   │   │   │   │       └── src
                │   │   │   │   │           ├── Makefile
                │   │   │   │   │           ├── xencode.c
                │   │   │   │   │           ├── xencode.h
                │   │   │   │   │           ├── xencode_hw.h
                │   │   │   │   │           ├── xencode_linux.c
                │   │   │   │   │           └── xencode_sinit.c
                │   │   │   │   ├── encode_info.xml
                │   │   │   │   ├── example
                │   │   │   │   │   ├── ipi_example.sh
                │   │   │   │   │   └── ipi_example.tcl
                │   │   │   │   ├── hdl
                │   │   │   │   │   ├── verilog
                │   │   │   │   │   │   ├── encode_alphabet_to_htree_node.v
                │   │   │   │   │   │   ├── encode_alphabet_usage.v
                │   │   │   │   │   │   ├── encode_control_s_axi.v
                │   │   │   │   │   │   ├── encode_gmem_m_axi.v
                │   │   │   │   │   │   ├── encode_ht.v
                │   │   │   │   │   │   ├── encode.v
                │   │   │   │   │   │   └── encode_visited.v
                │   │   │   │   │   └── vhdl
                │   │   │   │   │       ├── encode_alphabet_to_htree_node.vhd
                │   │   │   │   │       ├── encode_alphabet_usage.vhd
                │   │   │   │   │       ├── encode_control_s_axi.vhd
                │   │   │   │   │       ├── encode_gmem_m_axi.vhd
                │   │   │   │   │       ├── encode_ht.vhd
                │   │   │   │   │       ├── encode.vhd
                │   │   │   │   │       └── encode_visited.vhd
                │   │   │   │   ├── misc
                │   │   │   │   │   └── logo.png
                │   │   │   │   ├── pack.sh
                │   │   │   │   ├── run_ippack.tcl
                │   │   │   │   ├── subcore
                │   │   │   │   ├── vivado.jou
                │   │   │   │   ├── vivado.log
                │   │   │   │   ├── xgui
                │   │   │   │   │   └── encode_v1_0.tcl
                │   │   │   │   └── xilinx_com_hls_encode_1_0.zip
                │   │   │   ├── sdaccel
                │   │   │   │   ├── kernel.xml
                │   │   │   │   └── kernel.xo
                │   │   │   ├── verilog
                │   │   │   │   ├── encode_alphabet_to_htree_node.v
                │   │   │   │   ├── encode_alphabet_usage.v
                │   │   │   │   ├── encode_control_s_axi.v
                │   │   │   │   ├── encode_gmem_m_axi.v
                │   │   │   │   ├── encode_ht.v
                │   │   │   │   ├── encode.v
                │   │   │   │   ├── encode_visited.v
                │   │   │   │   ├── encode.xdc
                │   │   │   │   ├── extraction.tcl
                │   │   │   │   ├── impl.sh
                │   │   │   │   ├── project.cache
                │   │   │   │   │   └── wt
                │   │   │   │   │       └── project.wpc
                │   │   │   │   ├── project.hw
                │   │   │   │   │   └── project.lpr
                │   │   │   │   ├── project.ip_user_files
                │   │   │   │   ├── project.xpr
                │   │   │   │   ├── run_vivado.tcl
                │   │   │   │   └── settings.tcl
                │   │   │   └── vhdl
                │   │   │       ├── encode_alphabet_to_htree_node.vhd
                │   │   │       ├── encode_alphabet_usage.vhd
                │   │   │       ├── encode_control_s_axi.vhd
                │   │   │       ├── encode_gmem_m_axi.vhd
                │   │   │       ├── encode_ht.vhd
                │   │   │       ├── encode.vhd
                │   │   │       ├── encode_visited.vhd
                │   │   │       ├── encode.xdc
                │   │   │       ├── extraction.tcl
                │   │   │       ├── impl.sh
                │   │   │       ├── project.cache
                │   │   │       │   └── wt
                │   │   │       │       └── project.wpc
                │   │   │       ├── project.hw
                │   │   │       │   └── project.lpr
                │   │   │       ├── project.ip_user_files
                │   │   │       ├── project.xpr
                │   │   │       ├── run_vivado.tcl
                │   │   │       └── settings.tcl
                │   │   ├── solution_OCL_REGION_0.aps
                │   │   ├── solution_OCL_REGION_0.directive
                │   │   ├── solution_OCL_REGION_0.log
                │   │   └── syn
                │   │       ├── report
                │   │       │   ├── encode_csynth.rpt
                │   │       │   └── encode_csynth.xml
                │   │       ├── systemc
                │   │       │   ├── encode_1.cpp
                │   │       │   ├── encode_2.cpp
                │   │       │   ├── encode_3.cpp
                │   │       │   ├── encode_4.cpp
                │   │       │   ├── encode_alphabet_to_htree_node.h
                │   │       │   ├── encode_alphabet_usage.h
                │   │       │   ├── encode.h
                │   │       │   ├── encode_ht.h
                │   │       │   └── encode_visited.h
                │   │       ├── verilog
                │   │       │   ├── encode_alphabet_to_htree_node.v
                │   │       │   ├── encode_alphabet_usage.v
                │   │       │   ├── encode_control_s_axi.v
                │   │       │   ├── encode_gmem_m_axi.v
                │   │       │   ├── encode_ht.v
                │   │       │   ├── encode.v
                │   │       │   └── encode_visited.v
                │   │       └── vhdl
                │   │           ├── encode_alphabet_to_htree_node.vhd
                │   │           ├── encode_alphabet_usage.vhd
                │   │           ├── encode_control_s_axi.vhd
                │   │           ├── encode_gmem_m_axi.vhd
                │   │           ├── encode_ht.vhd
                │   │           ├── encode.vhd
                │   │           └── encode_visited.vhd
                │   ├── vivado_hls.app
                │   ├── vivado_hls.log
                │   ├── xcl_tmp.bc
                │   └── xcl_tmp.cpp
                ├── encode.tcl
                ├── htr.txt
                ├── ISEWrap.js
                ├── ISEWrap.sh
                ├── rundef.js
                ├── runme.bat
                ├── runme.log
                ├── runme.sh
                └── vivado_hls.log

349 directories, 790 files
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
emconfigutil --xdevice 'xilinx:adm-pcie-ku3:2ddr-xpr:3.2' --nd 1
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
