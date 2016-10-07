# kernel_global Application

include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
kernel_global_SRCS=./src/kernel_global_bandwidth.c
kernel_global_CXXFLAGS=$(opencl_CXXFLAGS)
kernel_global_LDFLAGS=$(opencl_LDFLAGS)

# kernel_global Kernel
krnl_kernel_global_SRCS=./src/kernel.cl

EXES=kernel_global
XCLBINS=krnl_kernel_global

include ../../utility/rules.mk

