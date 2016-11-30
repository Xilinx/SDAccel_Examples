# host_global Application

COMMON_REPO:=../../../
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# host_global Host Application
host_global_SRCS=./src/host_global_bandwidth.c $(xcl_SRCS)
host_global_HDRS=$(xcl_HDRS)
host_global_CXXFLAGS= $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_global_LDFLAGS=$(opencl_LDFLAGS)

krnl_host_global_SRCS=./src/kernel.cl

EXES=host_global
XCLBINS=krnl_host_global

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk

