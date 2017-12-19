COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
adder_SRCS=./src/adder.cl
adder_CLFLAGS= -k adder
#Specifying Fifo depth for Dataflow
adder_CLFLAGS+=--xp "param:compiler.xclDataflowFifoDepth=32"

XOS=adder

# xclbin
adder_XOS=adder
adder_NDEVICES=xilinx:kcu1500:dynamic xilinx_kcu1500_dynamic_5_0

XCLBINS=adder

# check
check_EXE=host
check_XCLBINS=adder
check_NDEVICES=$(adder_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

