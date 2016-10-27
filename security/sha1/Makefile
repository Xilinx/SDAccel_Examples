# SHA1 Application

include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
sha1_SRCS=./src/clSha1.cpp ./src/sha1.c ./src/main.cpp $(logger_SRCS) $(cmdparser_SRCS) $(xcl_cpp_SRCS)
sha1_HDRS=./src/clSha1.h ./src/oswendian.h ./src/sha1.h $(logger_HDRS) $(cmdparser_HDRS) $(xcl_cpp_HDRS)
sha1_CXXFLAGS=-std=gnu++0x -I./src/ $(opencl_CXXFLAGS) $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_cpp_CXXFLAGS)
sha1_LDFLAGS=$(opencl_LDFLAGS) -lrt

# SHA1 Kernel
krnl_sha1_SRCS=./src/krnl_clSha1.cl
krnl_sha1_HDRS=./src/clSha1.h
krnl_sha1_CLFLAGS=--nk dev_sha1_update:2

EXES=sha1
XCLBINS=krnl_sha1

include ../../utility/rules.mk

