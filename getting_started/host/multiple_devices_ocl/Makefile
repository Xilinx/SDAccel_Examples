
COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
multiple_devices_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
multiple_devices_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
multiple_devices_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

EXES=multiple_devices
XCLBINS=vector_addition


# check
check_EXE=multiple_devices
check_XCLBINS=vector_addition
check_ARGS=$(XCLBIN_GOALS)

CHECKS=check

NUM_DEVICES:=2
include $(COMMON_REPO)/utility/rules.mk
