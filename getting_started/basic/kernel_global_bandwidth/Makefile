# kernel_global Application
COMMON_REPO:=../../../
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# hello Host Application
kernel_global_SRCS=./src/kernel_global_bandwidth.c $(xcl_SRCS)
kernel_global_HDRS=$(xcl_HDRS)
kernel_global_CXXFLAGS=$(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
kernel_global_LDFLAGS=$(opencl_LDFLAGS)

# kernel_global Kernel
krnl_kernel_global_SRCS=./src/kernel.cl

EXES=kernel_global
XCLBINS=krnl_kernel_global

# check
check_EXE=kernel_global
check_XCLBINS=krnl_kernel_global

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
