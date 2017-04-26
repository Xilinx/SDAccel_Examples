COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
EXES=host

vadd_KERNEL := krnl_vadd_rtl
vadd_CU		:= 1

# RTL Kernel Sources
vadd_HDLSRCS=src/kernel.xml\
			 scripts/package_kernel.tcl\
			 scripts/gen_xo.tcl\
			 src/hdl/*.sv\
		   	 src/hdl/*.v
vadd_TCL=scripts/gen_xo.tcl

RTLXOS=vadd

# Kernel
vadd_XOS=vadd
vadd_LDCLFLAGS=-k $(vadd_KERNEL) --nk $(vadd_KERNEL):$(vadd_CU)
vadd_NTARGETS=sw_emu

XCLBINS=vadd
EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel* $(vadd_KERNEL).xo

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
