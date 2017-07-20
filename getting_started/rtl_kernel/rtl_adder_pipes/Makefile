################################################################################
COMMON_REPO := ../../..

# Including Common Makefile
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

#RTL Kernel Sources
input_HDLSRCS=src/kernel_input_stage.xml\
			  scripts/gen_input_xo.tcl\
			  scripts/package_kernel_input_stage.tcl\
			  src/input_stage/hdl/*.sv\
			  src/input_stage/hdl/*.v
input_TCL=scripts/gen_input_xo.tcl

adder_HDLSRCS=src/kernel_adder_stage.xml\
			  scripts/gen_adder_xo.tcl\
			  scripts/package_kernel_adder_stage.tcl\
			  src/adder_stage/hdl/*.sv\
			  src/adder_stage/hdl/*.v
adder_TCL=scripts/gen_adder_xo.tcl

output_HDLSRCS=src/kernel_output_stage.xml\
			  scripts/gen_output_xo.tcl\
			  scripts/package_kernel_output_stage.tcl\
			  src/output_stage/hdl/*.sv\
			  src/output_stage/hdl/*.v
output_TCL=scripts/gen_output_xo.tcl

RTLXOS=input adder output

# Kernel
adder_XOS=input adder output
adder_NTARGETS=sw_emu

XCLBINS=adder

EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel*

# check
check_EXE=host
check_XCLBINS=adder
check_NTARGETS=$(adder_NTARGETS)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

include $(COMMON_REPO)/utility/rules.mk

