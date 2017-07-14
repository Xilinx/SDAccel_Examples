# Huffman Codec Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/simplebmp/simplebmp.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Huffman Codec Host Application
huffman_SRCS=./src/bit_io.cpp ./src/huffmancodec_naive.cpp ./src/huffmancodec_optimized_cpuonly.cpp ./src/huffmancodec_optimized.cpp \
	./src/main.cpp $(simplebmp_SRCS) $(xcl_SRCS) $(logger_SRCS) $(cmdparser_SRCS)
huffman_HDRS=./src/bit_io.h ./src/huffmancodec_naive.h ./src/huffmancodec_optimized_cpuonly.h ./src/huffmancodec_optimized.h \
	$(logger_HDRS) $(simplebmp_HDRS) $(xcl_HDRS) $(cmdparser_HDRS)
huffman_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS) $(simplebmp_CXXFLAGS) $(logger_CXXFLAGS)
huffman_LDFLAGS=$(opencl_LDFLAGS)

EXES=huffman

# Huffman Codec Kernel
krnl_huffman_SRCS=./src/krnl_huffman_singleptr.cl
krnl_huffman_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr

XOS=krnl_huffman

# Huffman Codec xclbin
krnl_huffman_XOS=krnl_huffman
krnl_huffman_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr

XCLBINS=krnl_huffman

# check
check_EXE=huffman
check_XCLBINS=krnl_huffman
check_ARGS=-b data/rect_1024.bmp
check_NDEVICES=$(krnl_huffman_NDEVICES)

EXTRA_CLEAN=out.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

