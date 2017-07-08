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
vadd0_HDLSRCS=src/kernel_0.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_vadd0_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v
vadd0_TCL=scripts/gen_vadd0_xo.tcl

vadd1_HDLSRCS=src/kernel_1.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_vadd1_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v
vadd1_TCL=scripts/gen_vadd1_xo.tcl

RTLXOS=vadd0 vadd1

# Kernel
vadd_XOS=vadd0 vadd1
vadd_LDCLFLAGS= \
	   -k krnl_vadd_rtl_0 --nk krnl_vadd_rtl_0:1:krnl_vadd_rtl_0 \
	   -k krnl_vadd_rtl_1 --nk krnl_vadd_rtl_0:1:krnl_vadd_rtl_1

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
