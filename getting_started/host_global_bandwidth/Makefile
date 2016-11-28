# host_global Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# host_global Host Application
host_global_SRCS=./src/host_global_bandwidth.c $(xcl_SRCS)
host_global_HDRS=$(xcl_HDRS)
host_global_CXXFLAGS= $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_global_LDFLAGS=$(opencl_LDFLAGS)

krnl_host_global_SRCS=./src/kernel.cl

EXES=host_global
XCLBINS=krnl_host_global

include ../../utility/rules.mk

