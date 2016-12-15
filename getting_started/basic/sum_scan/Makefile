# sum_scan Application
COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# sum_scan Host Application
sum_scan_SRCS=./src/sum_scan.cpp $(xcl_SRCS)
sum_scan_HDRS=$(xcl_HDRS)
sum_scan_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
sum_scan_LDFLAGS=$(opencl_LDFLAGS)

# sum_scan Kernel
krnl_sum_scan_SRCS=./src/krnl_sum_scan.cl

EXES=sum_scan
XCLBINS=krnl_sum_scan

# check
check_EXE=sum_scan
check_XCLBINS=krnl_sum_scan

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

