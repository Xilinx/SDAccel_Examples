COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

vadd_KERNEL := krnl_vadd_rtl
vadd_CU		:= 1
#RTL Kernel Sources
vadd_HDLSRCS=src/kernel.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v

VIVADO=$(XILINX_SDX)/Vivado/bin/vivado

$(vadd_KERNEL).xo:$(vadd_HDLSRCS)
	$(VIVADO) -mode batch -source ./scripts/gen_xo.tcl

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
vadd_SRCS=$(vadd_KERNEL).xo
vadd_CLFLAGS= -l -k $(vadd_KERNEL) --nk $(vadd_KERNEL):$(vadd_CU) --kernel_frequency "0:150|1:250"
vadd_DEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2 
vadd_TARGETS=hw hw_emu

EXES=host
XCLBINS=vadd
EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel* $(vadd_KERNEL).xo

# check
check_EXE=host
check_XCLBINS=vadd
check_DEVICES=$(vadd_DEVICES)
check_TARGETS=$(vadd_TARGETS)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

DEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2 
include $(COMMON_REPO)/utility/rules.mk
