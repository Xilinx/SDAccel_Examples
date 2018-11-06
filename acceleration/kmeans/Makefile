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

# Points to Utility Directory
COMMON_REPO = ../../
ABS_COMMON_REPO = $(shell readlink -f $(COMMON_REPO))

include ./utils.mk

TARGETS := hw
TARGET := $(TARGETS)
DEVICES := xilinx_vcu1525_dynamic
DEVICE := $(DEVICES)
XCLBIN := ./xclbin
DSA := $(call device2sandsa, $(DEVICE))

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

CXXFLAGS := $(opencl_CXXFLAGS) -Wall -O0 -g -std=c++14
LDFLAGS := $(opencl_LDFLAGS)

################################################################################
#K-Means Settings
################################################################################
#Select  the data type INT/FLOAT both supported
DATATYPE:=INT
#Select the number of Compute units. 
COMPUTE_UNITS:=2
#NOTE: Kmeans can give better results with more compute units but for all Devices
#More than 2 compute units are not feasible so it is restricted to 2 compute units.
#User can increase the number of Compute units for bigger Devices and can get better
#Results.

#Select the number of parallel points to execute
PARALLEL_POINTS:=4

#Test Setup and files
NCLUSTERS:=5
TEST_FILE:=./data/100
GOLD_FILE:=$(TEST_FILE).gold_c$(NCLUSTERS)
################################################################################
ifeq ($(DATATYPE), INT)
	DATATYPE_ID = 1
	PARALLEL_FEATURES = 2 
else
	DATATYPE_ID = 0
	PARALLEL_FEATURES = 8 
endif

HOST_SRCS = ./src/host.cpp ./src/cluster.c ./src/rmse.c ./src/fpga_kmeans.cpp ./src/kmeans_clustering_cmodel.c

# Host compiler global settings
CXXFLAGS = -I $(XILINX_XRT)/include/ -I/$(XILINX_SDX)/Vivado_HLS/include/ -O0 -g -Wall -fmessage-length=0 -std=c++14
LDFLAGS = -lOpenCL -lpthread -lrt -lstdc++ -L$(XILINX_XRT)/lib/ -lxilinxopencl

# Kernel compiler global settings
CLFLAGS = -t $(TARGET) --platform $(DEVICE) --save-temps 
CLFLAGS += -D "PARALLEL_POINTS=$(PARALLEL_POINTS)" -D "PARALLEL_FEATURES=$(PARALLEL_FEATURES)" -D USE_DATA_TYPE=$(DATATYPE_ID)

CXXFLAGS += -DRECORD_OVERALL_TIME -DUSE_DATA_TYPE=$(DATATYPE_ID) -DPARALLEL_POINTS=$(PARALLEL_POINTS)

EXECUTABLE = host_kmeans

EMCONFIG_DIR = $(XCLBIN)/$(DSA)

BINARY_CONTAINERS += $(XCLBIN)/kmeans.$(TARGET).$(DSA).xclbin
BINARY_CONTAINER_1_OBJS += $(XCLBIN)/kmeans.$(TARGET).$(DSA).xo

#Include Libraries
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
include $(ABS_COMMON_REPO)/libs/logger/logger.mk
include $(ABS_COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(ABS_COMMON_REPO)/libs/xcl2/xcl2.mk
CXXFLAGS += $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl2_CXXFLAGS)
LDFLAGS += $(logger_LDFLAGS) $(cmdparser_LDFLAGS) $(xcl2_LDFLAGS)
HOST_SRCS += $(logger_SRCS) $(cmdparser_SRCS) $(xcl2_SRCS)

CP = cp -rf
DATA = ./data

.PHONY: all clean cleanall docs emconfig
all: $(EXECUTABLE) $(BINARY_CONTAINERS) emconfig

.PHONY: exe
exe: $(EXECUTABLE)

# Building kernel
$(XCLBIN)/kmeans.$(TARGET).$(DSA).xo: ./src/kmeans.cl
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -c -k kmeans -I'$(<D)' -o'$@' '$<'

$(XCLBIN)/kmeans.$(TARGET).$(DSA).xclbin: $(BINARY_CONTAINER_1_OBJS)
	$(XOCC) $(CLFLAGS) -l $(LDCLFLAGS) --nk kmeans:$(COMPUTE_UNITS) -o'$@' $(+)

# Building Host
$(EXECUTABLE): $(HOST_SRCS)
	mkdir -p $(XCLBIN)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) -o '$@' $(LDFLAGS)

emconfig:$(EMCONFIG_DIR)/emconfig.json
$(EMCONFIG_DIR)/emconfig.json:
	emconfigutil --platform $(DEVICE) --od $(EMCONFIG_DIR)

check: all

ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(CP) $(EMCONFIG_DIR)/emconfig.json .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE) -i ./data/100 -c ./data/100.gold_c5 -m 5 -n 5 -g 2
else
	 ./$(EXECUTABLE) -i ./data/100 -c ./data/100.gold_c5 -m 5 -n 5 -g 2
endif
	sdx_analyze profile -i sdaccel_profile_summary.csv -f html

# Cleaning stuff
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) sdaccel_* TempConfig system_estimate.xtxt *.rpt
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)
	-$(RMDIR) ./_x
	-$(RMDIR) ./membership.out


