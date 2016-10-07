# sum_scan Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# sum_scan Host Application
sum_scan_SRCS=./src/sum_scan.cpp $(xcl_SRCS)
sum_scan_HDRS=$(xcl_HDRS)
sum_scan_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
sum_scan_LDFLAGS=$(opencl_LDFLAGS)

# sum_scan Kernel
krnl_sum_scan_SRCS=./src/krnl_sum_scan.cl

EXES=sum_scan
XCLBINS=krnl_sum_scan

include ../../utility/rules.mk

