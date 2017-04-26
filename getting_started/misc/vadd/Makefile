# vadd Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vadd Host Application
vadd_SRCS=./src/host.cpp $(xcl2_SRCS)
vadd_HDRS=$(xcl2_HDRS)
vadd_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
vadd_LDFLAGS=$(opencl_LDFLAGS)

EXES=vadd

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

XOS=krnl_vadd

# vadd xclbin
krnl_vadd_XOS=krnl_vadd

XCLBINS=krnl_vadd

# check
check_EXE=vadd
check_XCLBINS=krnl_vadd

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

