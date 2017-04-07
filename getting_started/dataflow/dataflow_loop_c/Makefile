COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
adder_SRCS=./src/adder.cpp
adder_CLFLAGS= -k adder
#adder_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=adder

# xclbins
adder_XOS=adder
#adder_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XCLBINS=adder

# check
check_EXE=host
check_XCLBINS=adder
check_DEVICES=$(adder_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
