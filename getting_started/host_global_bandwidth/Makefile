# host_global Application

include ../../utility/boards.mk
include ../../libs/opencl/opencl.mk

# host_global Host Application
host_global_SRCS=./src/host_global_bandwidth.c
host_global_CXXFLAGS=$(opencl_CXXFLAGS)
host_global_X86_LDFLAGS=$(opencl_X86_LDFLAGS)
host_global_POWER_LDFLAGS=$(opencl_POWER_LDFLAGS)

krnl_host_global_SRCS=./src/kernel.cl

EXES=host_global
XCLBINS=krnl_host_global

include ../../utility/rules.mk

