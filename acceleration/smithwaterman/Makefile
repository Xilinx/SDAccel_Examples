# Smithwaterman Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Smithwaterman Application
smithwaterman_SRCS=./src/main.cpp ./src/genseq.cpp ./src/matcharray.cpp ./src/smithwaterman.cpp
smithwaterman_SRCS+= ./src/intel/ssw.c ./src/intel/sc_demo.c
smithwaterman_SRCS+= $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS)
smithwaterman_HDRS=./src/matcharray.h ./src/smithwaterman.h ./src/sw.h
smithwaterman_HDRS+= ./src/intel/ssw.h ./src/intel/kseq.h
smithwaterman_HDRS+= $(logger_HDRS) $(cmdparser_HDRS) $(xcl_HDRS)
smithwaterman_CXXFLAGS=-std=c++0x -DFPGA_DEVICE -I./src/ $(opencl_CXXFLAGS)
smithwaterman_CXXFLAGS+= $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS)
smithwaterman_LDFLAGS=$(opencl_LDFLAGS) -fopenmp -lz

EXES=smithwaterman

# Smithwaterman Kernel
krnl_smithwaterman_SRCS=./src/opencl_sw_maxscore_systolic.cpp
krnl_smithwaterman_HDRS=./src/sw.h
krnl_smithwaterman_CLFLAGS=--kernel opencl_sw_maxscore -I./src/ --kernel_frequency 235 

XOS=krnl_smithwaterman

# Smithwaterman xclbin
krnl_smithwaterman_XOS=krnl_smithwaterman
krnl_smithwaterman_LDCLFLAGS=--nk opencl_sw_maxscore:2

XCLBINS=krnl_smithwaterman

# check
check_EXE=smithwaterman
check_XCLBINS=krnl_smithwaterman

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

