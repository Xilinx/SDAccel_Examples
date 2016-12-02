# Huffman Codec Application

include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/simplebmp/simplebmp.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/opencl/opencl.mk

# Huffman Codec Host Application
huffman_SRCS=./src/bit_io.cpp ./src/huffmancodec_native.cpp ./src/huffmancodec_optimized_cpuonly.cpp ./src/huffmancodec_optimized.cpp \
	./src/main.cpp $(simplebmp_SRCS) $(xcl_cpp_SRCS) $(logger_SRCS) $(cmdparser_SRCS)
huffman_HDRS=./src/bit_io.h /src/huffmancodec_native.h ./src/huffmancodec_optimized_cpuonly.h ./src/huffmancodec_optimized.h \
	$(logger_HDRS) $(simplebmp_HDRS) $(xcl_cpp_HDRS) $(cmdparser_HDRS)
huffman_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_cpp_CXXFLAGS) $(simplebmp_CXXFLAGS) $(logger_CXXFLAGS)
huffman_LDFLAGS=$(opencl_LDFLAGS)

# Huffman Codec Kernel
krnl_huffman_SRCS=./src/krnl_huffman_singleptr.cl

EXES=huffman
XCLBINS=krnl_huffman

# check
check_EXE=huffman
check_XCLBINS=krnl_huffman

CHECKS=check

include ../../utility/rules.mk

