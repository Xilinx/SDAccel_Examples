# kernel_global Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
kernel_global_SRCS=./src/kernel_global_bandwidth.c $(xcl_SRCS)
kernel_global_HDRS=$(xcl_HDRS)
kernel_global_CXXFLAGS=$(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
kernel_global_LDFLAGS=$(opencl_LDFLAGS)

# kernel_global Kernel
krnl_kernel_global_SRCS=./src/kernel.cl

EXES=kernel_global
XCLBINS=krnl_kernel_global

include ../../utility/rules.mk

