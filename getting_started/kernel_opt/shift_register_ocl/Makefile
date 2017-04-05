COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
shift_register_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
shift_register_HDRS=${xcl_HDRS}
shift_register_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
shift_register_LDFLAGS=$(opencl_LDFLAGS)

EXES=shift_register

# Kernel
fir_SRCS=./src/fir.cl
fir_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=fir

# xclbin
fir_XOS=fir

XCLBINS=fir

# check
check_EXE=shift_register
check_XCLBINS=fir
check_DEVICES=$(fir_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
