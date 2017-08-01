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

# RTL Kernel Sources
rtl_vadd_HDLSRCS=src/kernel.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_rtl_vadd_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v
rtl_vadd_TCL=scripts/gen_rtl_vadd_xo.tcl

vadd_SRCS=./src/krnl_vadd.cl
vadd_CLFLAGS=-k krnl_vadd -I./src


RTLXOS=rtl_vadd
XOS=vadd

# Kernel
vadd_XOS= rtl_vadd vadd
vadd_NTARGETS=sw_emu

XCLBINS=vadd
EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel*

# check
check_EXE=host
check_XCLBINS=vadd
check_NTARGETS=$(vadd_NTARGETS)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

include $(COMMON_REPO)/utility/rules.mk
