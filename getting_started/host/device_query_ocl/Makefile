COMMON_REPO := ../../..

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp  $(oclHelper_SRCS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) -std=c++0x
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# check
check_EXE=host

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

