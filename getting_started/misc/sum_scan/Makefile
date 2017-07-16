# sum_scan Application
COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# sum_scan Host Application
sum_scan_SRCS=./src/host.cpp $(xcl2_SRCS)
sum_scan_HDRS=$(xcl2_HDRS)
sum_scan_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
sum_scan_LDFLAGS=$(opencl_LDFLAGS)

EXES=sum_scan

# sum_scan Kernel
krnl_sum_scan_SRCS=./src/krnl_sum_scan.cl
krnl_sum_scan_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

XOS=krnl_sum_scan

# sum_scan xclbin
krnl_sum_scan_XOS=krnl_sum_scan
krnl_sum_scan_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

XCLBINS=krnl_sum_scan

# check
check_EXE=sum_scan
check_XCLBINS=krnl_sum_scan
check_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

