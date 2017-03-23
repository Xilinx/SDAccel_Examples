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
vadd_CLFLAGS= -l -k $(vadd_KERNEL) --nk $(vadd_KERNEL):$(vadd_CU)
vadd_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3 
vadd_TARGETS=hw_emu hw

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

DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
