COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vadd Host Application
 host_SRCS=./src/host.cpp $(xcl2_SRCS)
 host_HDRS=$(xcl2_HDRS)
 host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
 host_LDFLAGS=$(opencl_LDFLAGS)

# vadd Kernels
 vadd_SRCS=./src/vadd.cpp
 vadd_CLFLAGS=-k vadd

 EXES=host
 XCLBINS=vadd

 XOS=vadd

 vadd_XOS=vadd

 # check
 check_EXE=host
 check_XCLBINS=vadd

 CHECKS=check

 include $(COMMON_REPO)/utility/rules.mk
