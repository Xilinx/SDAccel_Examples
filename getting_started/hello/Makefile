# Hello Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
hello_SRCS=./src/hello.cpp $(xcl_SRCS)
hello_HDRS=$(xcl_HDRS)
hello_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
hello_LDFLAGS=$(opencl_LDFLAGS)

# hello Kernel
krnl_hello_SRCS=./src/krnl_hello.cl

EXES=hello
XCLBINS=krnl_hello

include ../../utility/rules.mk

