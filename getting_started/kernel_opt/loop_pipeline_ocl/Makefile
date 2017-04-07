

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
loop_pipeline_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
loop_pipeline_HDRS=$(xcl2_HDRS)
loop_pipeline_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
loop_pipeline_LDFLAGS=$(opencl_LDFLAGS)

EXES=loop_pipeline

# Kernel
vector_addition_SRCS=./src/vector_addition.cl
vector_addition_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=vector_addition

# xclbin
vector_addition_XOS=vector_addition
vector_addition_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XCLBINS=vector_addition

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)
check_DEVICES=$(vector_addition_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
