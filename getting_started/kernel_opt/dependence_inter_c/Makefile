COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(oclHelper_SRCS) $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS) $(bitmap_HDRS)
host_CXXFLAGS= -I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
vconv_SRCS=./src/vconv.cpp
vconv_CLFLAGS=-k vconv -I./src/

XOS=vconv

vconv_XOS=vconv

EXES=host
XCLBINS=vconv

# check
check_EXE=host
check_XCLBINS=vconv

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

