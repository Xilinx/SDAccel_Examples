COMMON_REPO := ../../../

# wide Memory Access Application
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vadd Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# Add vadd kernel
vadd_GOOD_SRCS=./src/vadd.cpp
vadd_GOOD_CLFLAGS=-k vadd

vadd_BAD_SRCS=./src/vadd_bad.cpp
vadd_BAD_CLFLAGS=-k vadd

XOS=vadd_GOOD vadd_BAD

vadd_GOOD_XOS=vadd_GOOD

vadd_BAD_XOS=vadd_BAD
vadd_BAD_LDCLFLAGS=--nk vadd:8
vadd_BAD_NDEVICES=xilinx:adm-pcie-7v3:1ddr

XCLBINS=vadd_GOOD vadd_BAD

# check
check_EXE=host
check_XCLBINS=vadd_GOOD vadd_BAD

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
