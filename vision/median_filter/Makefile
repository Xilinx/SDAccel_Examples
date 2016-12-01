# Median Filter Application

include ../../utility/boards.mk
include ../../libs/oclHelper/oclHelper.mk
include ../../libs/bitmap/bitmap.mk
include ../../libs/opencl/opencl.mk

# Median Filter Host Application
median_SRCS=./src/medianFilter.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
median_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
median_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
median_LDFLAGS=$(opencl_LDFLAGS)

# Median Filter Kernel
krnl_median_SRCS=./src/krnl_medianFilter.cl

EXES=median
XCLBINS=krnl_median

# check
check_EXE=median
check_XCLBINS=krnl_median

CHECKS=check

include ../../utility/rules.mk

