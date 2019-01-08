.PHONY: help

help::
	$(ECHO) "Makefile Usage:"
	$(ECHO) "  make all TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to generate the design for specified Target and Device."
	$(ECHO) ""
	$(ECHO) "  make clean "
	$(ECHO) "      Command to remove the generated non-hardware files."
	$(ECHO) ""
	$(ECHO) "  make cleanall"
	$(ECHO) "      Command to remove all the generated files."
	$(ECHO) ""
	$(ECHO) "  make check TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to run application in emulation."
	$(ECHO) ""
	$(ECHO) "  make run_nimbix DEVICE=<FPGA platform>"
	$(ECHO) "      Command to run application on Nimbix Cloud."
	$(ECHO) ""
	$(ECHO) "  make aws_build DEVICE=<FPGA platform>"
	$(ECHO) "      Command to build AWS xclbin application on AWS Cloud."
	$(ECHO) ""

# Points to Utility Directory
COMMON_REPO = ../../
ABS_COMMON_REPO = $(shell readlink -f $(COMMON_REPO))

TARGETS := hw
TARGET := $(TARGETS)
DEVICE := $(DEVICES)
XCLBIN := ./xclbin

include ./utils.mk

DSA := $(call device2sandsa, $(DEVICE))
BUILD_DIR := ./_x.$(TARGET).$(DSA)

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

#Include Libraries
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
include $(ABS_COMMON_REPO)/libs/logger/logger.mk
include $(ABS_COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(ABS_COMMON_REPO)/libs/xcl2/xcl2.mk
CXXFLAGS += $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl2_CXXFLAGS)
LDFLAGS += $(logger_LDFLAGS) $(cmdparser_LDFLAGS) $(xcl2_LDFLAGS)
HOST_SRCS += $(logger_SRCS) $(cmdparser_SRCS) $(xcl2_SRCS)

CXXFLAGS += -lz -fopenmp
CXXFLAGS += $(opencl_CXXFLAGS) -Wall -O0 -g -std=c++14
LDFLAGS += $(opencl_LDFLAGS)

HOST_SRCS += ./src/main.cpp ./src/genseq.cpp ./src/matcharray.cpp ./src/smithwaterman.cpp ./src/intel/ssw.c ./src/intel/sc_demo.c
HOST_HDRS += ./src/matcharray.h ./src/smithwaterman.h ./src/sw.h ./src/intel/ssw.h ./src/intel/kseq.h

# Host compiler global settings
CXXFLAGS += -fmessage-length=0 -DFPGA_DEVICE -I./src/ -I $(XILINX_VIVADO)/include/
LDFLAGS += -lrt -lstdc++ 

# Kernel compiler global settings
CLFLAGS += -t $(TARGET) --platform $(DEVICE) --save-temps --temp_dir $(BUILD_DIR) 
CLFLAGS += -I./src/ --kernel_frequency 235



EXECUTABLE = smithwaterman

EMCONFIG_DIR = $(XCLBIN)/$(DSA)

BINARY_CONTAINERS += $(XCLBIN)/krnl_smithwaterman.$(TARGET).$(DSA).xclbin
BINARY_CONTAINER_krnl_smithwaterman_OBJS += $(XCLBIN)/opencl_sw_maxscore.$(TARGET).$(DSA).xo

CP = cp -rf

.PHONY: all clean cleanall docs emconfig
all: check-devices $(EXECUTABLE) $(BINARY_CONTAINERS) emconfig

.PHONY: exe
exe: $(EXECUTABLE)

# Building kernel
$(XCLBIN)/opencl_sw_maxscore.$(TARGET).$(DSA).xo: src/opencl_sw_maxscore_systolic.cpp
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -c -k opencl_sw_maxscore -I'$(<D)' -o'$@' '$<'
$(XCLBIN)/krnl_smithwaterman.$(TARGET).$(DSA).xclbin: $(BINARY_CONTAINER_krnl_smithwaterman_OBJS)
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -l $(LDCLFLAGS) --nk opencl_sw_maxscore:2 -o'$@' $(+)

# Building Host
$(EXECUTABLE): $(HOST_SRCS) $(HOST_HDRS)
	mkdir -p $(XCLBIN)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) $(HOST_HDRS) -o '$@' $(LDFLAGS)

emconfig:$(EMCONFIG_DIR)/emconfig.json
$(EMCONFIG_DIR)/emconfig.json:
	emconfigutil --platform $(DEVICE) --od $(EMCONFIG_DIR)

check: all
ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(CP) $(EMCONFIG_DIR)/emconfig.json .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE)
else
	 ./$(EXECUTABLE)
endif
ifneq ($(TARGET),$(findstring $(TARGET), sw_emu hw))
$(warning WARNING:Application supports only sw_emu hw TARGET. Please use the target for running the application)
endif

	sdx_analyze profile -i sdaccel_profile_summary.csv -f html

run_nimbix: all
	$(COMMON_REPO)/utility/nimbix/run_nimbix.py $(EXECUTABLE) $(DSA)

aws_build: all check-aws_repo
	$(COMMON_REPO)/utility/aws/run_aws.py $(BINARY_CONTAINERS)

# Cleaning stuff
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) sdaccel_* TempConfig system_estimate.xtxt *.rpt
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)
	-$(RMDIR) _x.*

