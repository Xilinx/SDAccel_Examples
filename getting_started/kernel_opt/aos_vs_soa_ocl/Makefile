

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
aos_vs_soa_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
aos_vs_soa_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS)
aos_vs_soa_LDFLAGS=$(opencl_LDFLAGS)

CXXFLAGS+=-std=c++0x

# Kernel
dot_SRCS=./src/dot.cl

EXES=aos_vs_soa
XCLBINS=dot

# check
check_EXE=aos_vs_soa
check_XCLBINS=dot

CHECKS=check


include $(COMMON_REPO)/utility/rules.mk
