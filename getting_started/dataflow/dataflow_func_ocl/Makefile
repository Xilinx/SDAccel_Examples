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
adder_SRCS=./src/adder.cl
adder_CLFLAGS= -k adder
#Specifyinng Fifo depth for Dataflow
adder_CLFLAGS+=--xp "param:compiler.xclDataflowFifoDepth=32"

XOS=adder

# xclbin
adder_XOS=adder

XCLBINS=adder

# check
check_EXE=host
check_XCLBINS=adder

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

