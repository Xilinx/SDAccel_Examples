# Huffman Codec Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/simplebmp/simplebmp.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Huffman Codec Host Application
huffman_SRCS=./src/bit_io.cpp ./src/huffmancodec_naive.cpp ./src/huffmancodec_optimized_cpuonly.cpp ./src/huffmancodec_optimized.cpp \
	./src/main.cpp $(simplebmp_SRCS) $(xcl2_SRCS) $(logger_SRCS) $(cmdparser_SRCS)
huffman_HDRS=./src/bit_io.h ./src/huffmancodec_naive.h ./src/huffmancodec_optimized_cpuonly.h ./src/huffmancodec_optimized.h \
	$(logger_HDRS) $(simplebmp_HDRS) $(xcl2_HDRS) $(cmdparser_HDRS)
huffman_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl2_CXXFLAGS) $(simplebmp_CXXFLAGS) $(logger_CXXFLAGS)
huffman_LDFLAGS=$(opencl_LDFLAGS)

EXES=huffman

# Huffman Codec Kernel
krnl_huffman_SRCS=./src/krnl_huffman_singleptr.cl
krnl_huffman_CLFLAGS=--xp "param:compiler.version=31"

XOS=krnl_huffman

# Huffman Codec xclbin
krnl_huffman_XOS=krnl_huffman

XCLBINS=krnl_huffman

# check
check_EXE=huffman
check_XCLBINS=krnl_huffman
check_ARGS=-b data/rect_1024.bmp

EXTRA_CLEAN=out.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

