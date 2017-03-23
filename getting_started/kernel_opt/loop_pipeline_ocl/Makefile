

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
loop_pipeline_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
loop_pipeline_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS)
loop_pipeline_LDFLAGS=$(opencl_LDFLAGS)
CXXFLAGS+=-std=c++0x

# Kernel
vector_addition_SRCS=./src/vector_addition.cl
vector_addition_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3


EXES=loop_pipeline
XCLBINS=vector_addition

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)
check_DEVICES=$(vector_addition_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk
