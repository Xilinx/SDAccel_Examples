COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
helloworld_SRCS=./src/host.cpp ${oclHelper_SRCS} ${xcl_SRCS}
host_HDRS=${xcl_HDRS}
helloworld_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) ${xcl_CXXFLAGS} ${oclHelper_CXXFLAGS} -std=c++0x
helloworld_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

EXES=helloworld
XCLBINS=vector_addition

# check
check_EXE=helloworld
check_XCLBINS=vector_addition

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
