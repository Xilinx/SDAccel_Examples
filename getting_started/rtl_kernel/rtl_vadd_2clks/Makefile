COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

vadd_KERNEL := krnl_vadd_rtl

#RTL Kernel Sources
vadd_HDLSRCS=src/kernel.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v
vadd_TCL=scripts/gen_xo.tcl

RTLXOS=vadd

# Kernel
vadd_XOS=vadd
vadd_LDCLFLAGS= --kernel_frequency "0:150|1:250"
vadd_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr
vadd_NTARGETS=sw_emu

XCLBINS=vadd
EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel*

# check
check_EXE=host
check_XCLBINS=vadd
check_NDEVICES=$(vadd_NDEVICES)
check_NTARGETS=$(vadd_NTARGETS)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

DEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr 
include $(COMMON_REPO)/utility/rules.mk
