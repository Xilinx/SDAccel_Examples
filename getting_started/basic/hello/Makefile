# Hello Application
COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# hello Host Application
hello_SRCS=./src/hello.cpp $(xcl_SRCS)
hello_HDRS=$(xcl_HDRS)
hello_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
hello_LDFLAGS=$(opencl_LDFLAGS)

EXES=hello

# hello Kernel
krnl_hello_SRCS=./src/krnl_hello.cl
XOS=krnl_hello

# hello xclbin
krnl_hello_XOS=krnl_hello
XCLBINS=krnl_hello

# check
check_EXE=hello
check_XCLBINS=krnl_hello

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

