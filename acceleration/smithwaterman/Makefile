# Smithwaterman Application

include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/opencl/opencl.mk

# Smithwaterman Application
smithwaterman_SRCS=./src/main.cpp ./src/genseq.cpp ./src/matcharray.cpp ./src/smithwaterman.cpp
smithwaterman_SRCS+= ./src/intel/ssw.c ./src/intel/sc_demo.c
smithwaterman_SRCS+= $(logger_SRCS) $(cmdparser_SRCS) $(xcl_cpp_SRCS)
smithwaterman_HDRS=./src/matcharray.h ./src/smithwaterman.h ./src/sw.h
smithwaterman_HDRS+= ./src/intel/ssw.h ./src/intel/kseq.h
smithwaterman_HDRS+= $(logger_HDRS) $(cmdparser_HDRS) $(xcl_cpp_HDRS)
smithwaterman_CXXFLAGS=-std=c++0x -DFPGA_DEVICE -I./src/ $(opencl_CXXFLAGS)
smithwaterman_CXXFLAGS+= $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_cpp_CXXFLAGS)
smithwaterman_LDFLAGS=$(opencl_LDFLAGS) -fopenmp -lz

# Smithwaterman Kernel
krnl_smithwaterman_SRCS=./src/opencl_sw_maxscore_systolic.cpp
krnl_smithwaterman_HDRS=./src/sw.h
krnl_smithwaterman_CLFLAGS=--kernel opencl_sw_maxscore

EXES=smithwaterman
XCLBINS=krnl_smithwaterman

include ../../utility/rules.mk

