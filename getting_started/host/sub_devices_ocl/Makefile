COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk

# Host Application
sub_devices_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS) 
sub_devices_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(oclHelper_CXXFLAGS) $(xcl2_CXXFLAGS)
sub_devices_LDFLAGS=$(opencl_LDFLAGS) $(xcl2_LDFLAGS)

EXES=sub_devices

# Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_LDCLFLAGS+=--nk krnl_vadd:8

XOS=krnl_vadd

# xclbin
krnl_vadd_XOS=krnl_vadd

XCLBINS=krnl_vadd

# check
check_EXE=sub_devices
check_XCLBINS=krnl_vadd

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
