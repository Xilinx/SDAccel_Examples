COMMON_REPO := ../../../

# wide Memory Access Application
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vadd Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# Switch between GOOD/BAD Examples
KFLOW:=GOOD

# vadd Kernels
ifeq ($(KFLOW), BAD)
    # Add bad kernel
    vadd_SRCS:=./src/vadd_bad.cpp
    vadd_CLFLAGS=--nk vadd:8
    host_CXXFLAGS+=-DBAD
else
    vadd_SRCS:=./src/vadd.cpp
    host_CXXFLAGS+=-DGOOD
endif

vadd_CLFLAGS+=-k vadd

# Generate system estimates
#vadd_CLFLAGS+=--report estimate

EXES=host
XCLBINS=vadd

# check
check_EXE=host
check_XCLBINS=vadd

CHECKS=check


include $(COMMON_REPO)/utility/rules.mk
