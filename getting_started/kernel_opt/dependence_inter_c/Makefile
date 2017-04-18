COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(oclHelper_SRCS) $(xcl_SRCS)
host_HDRS=$(xcl_HDRS) $(bitmap_HDRS)
host_CXXFLAGS= -I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
mean_value_SRCS=./src/mean_value.cpp
mean_value_CLFLAGS=-k mean_value

XOS=mean_value

# xclbin
mean_value_XOS=mean_value

XCLBINS=mean_value

# check
check_EXE=host
check_XCLBINS=mean_value

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

