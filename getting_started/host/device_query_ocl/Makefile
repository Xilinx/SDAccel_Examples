COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp  ${oclHelper_SRCS} ${xcl_SRCS}
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) ${xcl_CXXFLAGS} ${oclHelper_CXXFLAGS} -std=c++0x
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk
