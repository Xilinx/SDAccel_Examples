COMMON_REPO := ../../../

# wide Memory Access Application
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk
# cnn Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# cnn Kernels
cnn_GOOD_SRCS=./src/cnn_convolution.cl
cnn_GOOD_CLFLAGS=-k cnn -I./src/

cnn_BAD_SRCS=./src/cnn_convolution_bad.cl
cnn_BAD_CLFLAGS=-k cnn -I./src/

XOS=cnn_GOOD cnn_BAD

# cnn xclbins

cnn_GOOD_XOS=cnn_GOOD
cnn_GOOD_LDCLFLAGS=--nk cnn:4

cnn_BAD_XOS=cnn_BAD

XCLBINS=cnn_GOOD

# check
check_EXE=host
check_XCLBINS=cnn_GOOD

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
