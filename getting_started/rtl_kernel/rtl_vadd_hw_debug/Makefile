COMMON_REPO := ../../..

#AWS_DEBUG_SCRIPTS_DIR:=${AWS_DEBUG_SCRIPTS_DIR}

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk


export DEBUG_LTX_DIR:=$(PWD)/xclbin

ifdef AWS_DEBUG_PLATFORM
ifdef SDACCEL_DIR
export AWS_DEBUG_SCRIPTS_DIR:=$(SDACCEL_DIR)/aws_platform/xilinx_aws-vu9p-f1_4ddr-xpr-2pr-debug_4_0/hw/constraints
endif
endif

D_FLAGS := --xp "vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.POST={$(AWS_DEBUG_SCRIPTS_DIR)/debug_constraints.tcl}" --xp "vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.TCL.POST={$(AWS_DEBUG_SCRIPTS_DIR)/generate_ltx.tcl}"
LDCLFLAGS +=$(D_FLAGS)


# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
EXES=host

vadd_KERNEL := krnl_vadd_rtl

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



