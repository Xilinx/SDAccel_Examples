# kernel Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

#set this value to GOOD to avoid Deadlock
#or set its value to BAD to shows Deadlock 
KFLOW:=GOOD

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# kernel Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

kernel_BAD_SRCS=./src/kernel.cpp
kernel_BAD_CLFLAGS=-k dummy_op -DDEADLOCK=1

kernel_GOOD_SRCS=./src/kernel.cpp
kernel_GOOD_CLFLAGS=-k dummy_op -DDEADLOCK=0

XOS=kernel_GOOD kernel_BAD

kernel_GOOD_XOS=kernel_GOOD
kernel_BAD_XOS=kernel_BAD

XCLBINS=kernel_GOOD kernel_BAD

# check
check_EXE=host
check_XCLBINS=kernel_$(KFLOW)
check_ARGS=kernel_$(KFLOW)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

