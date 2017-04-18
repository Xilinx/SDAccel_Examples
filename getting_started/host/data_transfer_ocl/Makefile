COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
data_transfer_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
data_transfer_HDRS=$(xcl_HDRS)
data_transfer_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
data_transfer_LDFLAGS=$(opencl_LDFLAGS)

EXES=data_transfer

# check
check_EXE=data_transfer

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
