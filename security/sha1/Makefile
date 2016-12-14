# SHA1 Application

include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
sha1_SRCS=./src/clSha1.cpp ./src/sha1.c ./src/main.cpp $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS)
sha1_HDRS=./src/clSha1.h ./src/oswendian.h ./src/sha1.h $(logger_SRCS) $(cmdparser_HDRS) $(xcl_HDRS)
sha1_CXXFLAGS=-std=gnu++0x -I./src/ $(opencl_CXXFLAGS) $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS)
sha1_LDFLAGS=$(opencl_LDFLAGS) -lrt

# SHA1 Kernel
krnl_sha1_SRCS=./src/krnl_clSha1.cl
krnl_sha1_HDRS=./src/clSha1.h
krnl_sha1_CLFLAGS=--nk dev_sha1_update:2

EXES=sha1
XCLBINS=krnl_sha1

# check
check_EXE=sha1
check_XCLBINS=krnl_sha1
check_sw_emu_ARGS=-t 20 -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:3.2' -k ./xclbin/krnl_sha1.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_2.xclbin
check_hw_emu_ARGS=-t 20 -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:3.2' -k ./xclbin/krnl_sha1.hw_emu.xilinx_adm-pcie-ku3_2ddr_3_2.xclbin
check_hw_ARGS=-t 20 -p Xilinx -d 'xilinx:adm-pcie-ku3:2ddr:3.2' -k ./xclbin/krnl_sha1.hw.xilinx_adm-pcie-ku3_2ddr_3_2.xclbin

CHECKS=check

include ../../utility/rules.mk

