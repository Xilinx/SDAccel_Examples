################################################################################
COMMON_REPO := ../../..

# Including Common Makefile
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

input_KERNEL := krnl_input_stage_rtl
adder_KERNEL := krnl_adder_stage_rtl
output_KERNEL:= krnl_output_stage_rtl
#RTL Kernel Sources
input_HDLSRCS=src/kernel_input_stage.xml\
			  scripts/gen_input_xo.tcl\
			  scripts/package_kernel_input_stage.tcl\
			  src/input_stage/hdl/*.sv\
			  src/input_stage/hdl/*.v

adder_HDLSRCS=src/kernel_adder_stage.xml\
			  scripts/gen_adder_xo.tcl\
			  scripts/package_kernel_adder_stage.tcl\
			  src/adder_stage/hdl/*.sv\
			  src/adder_stage/hdl/*.v

output_HDLSRCS=src/kernel_output_stage.xml\
			  scripts/gen_output_xo.tcl\
			  scripts/package_kernel_output_stage.tcl\
			  src/output_stage/hdl/*.sv\
			  src/output_stage/hdl/*.v

VIVADO=$(XILINX_SDX)/Vivado/bin/vivado

$(input_KERNEL).xo:$(input_HDLSRCS)
	$(VIVADO) -mode batch -source ./scripts/gen_input_xo.tcl
$(adder_KERNEL).xo:$(adder_HDLSRCS)
	$(VIVADO) -mode batch -source ./scripts/gen_adder_xo.tcl
$(output_KERNEL).xo:$(output_HDLSRCS)
	$(VIVADO) -mode batch -source ./scripts/gen_output_xo.tcl

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) 
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
adder_SRCS=$(input_KERNEL).xo  $(adder_KERNEL).xo $(output_KERNEL).xo
adder_CLFLAGS= -l\
	   -k $(input_KERNEL)  --nk $(input_KERNEL):1:$(input_KERNEL)_cu0 \
	   -k $(adder_KERNEL)  --nk $(adder_KERNEL):1:$(adder_KERNEL)_cu0 \
	   -k $(output_KERNEL) --nk $(output_KERNEL):1:$(output_KERNEL)_cu0   
adder_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3
adder_TARGETS=hw_emu hw

EXES=host
XCLBINS=adder
EXTRA_CLEAN=tmp_kernel_pack* packaged_kernel* *.xo

# check
check_EXE=host
check_XCLBINS=adder
check_DEVICES=$(adder_DEVICES)
check_TARGETS=$(adder_TARGETS)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

#Changing Default device for this example
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
