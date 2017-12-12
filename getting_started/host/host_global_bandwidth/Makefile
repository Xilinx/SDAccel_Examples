# host_global Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# host_global Host Application
host_global_SRCS=./src/host.cpp $(xcl_SRCS)
host_global_HDRS=$(xcl_HDRS)
host_global_CXXFLAGS= $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_global_LDFLAGS=$(opencl_LDFLAGS)
EXES=host_global

krnl_host_global_SRCS=./src/kernel.cl
XOS=krnl_host_global

krnl_host_global_XOS=krnl_host_global
XCLBINS=krnl_host_global

# check
check_EXE=host_global
check_XCLBINS=krnl_host_global

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

