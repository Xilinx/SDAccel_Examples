COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
data_transfer_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
data_transfer_HDRS=$(xcl2_HDRS)
data_transfer_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS)
data_transfer_LDFLAGS=$(opencl_LDFLAGS)

EXES=data_transfer

dummy_kernel_SRCS=./src/dummy_kernel.cl
XOS=dummy_kernel

dummy_kernel_XOS=dummy_kernel
XCLBINS=dummy_kernel

# check
check_EXE=data_transfer
check_XCLBINS=dummy_kernel

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
