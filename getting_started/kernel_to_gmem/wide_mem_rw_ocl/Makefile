COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vadd Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# vadd Kernels
vadd_SRCS=./src/vadd.cl
vadd_CLFLAGS=-k vadd
vadd_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

EXES=host
XCLBINS=vadd

# check
check_EXE=host
check_XCLBINS=vadd
check_DEVICES=$(vadd_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk

