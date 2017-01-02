COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
device_query_SRCS=./src/host.cpp  $(oclHelper_SRCS) 
device_query_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
device_query_LDFLAGS=$(opencl_LDFLAGS)

EXES=device_query

# check
check_EXE=device_query

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
