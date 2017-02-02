COMMON_REPO:=../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk

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

kmeans_SRCS=src/cluster.c src/rmse.c src/fpga_kmeans.cpp src/host.cpp src/kmeans_clustering_cmodel.c  src/read_input.cpp
kmeans_SRCS+= $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS) $(oclHelper_SRCS)
kmeans_HDRS = $(logger_SRCS) $(cmdparser_HDRS) $(xcl_HDRS) $(oclHelper_HDRS)
kmeans_EXE=kmeans
kmeans_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) -D RECORD_OVERALL_TIME -D USE_DATA_TYPE=$(DATATYPE_ID) 
kmeans_CXXFLAGS+= $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) 
kmeans_LDFLAGS=$(opencl_LDFLAGS) -lxilinxopencl -lpthread -lrt

#Kmeans Kernel
krnl_kmeans_SRCS=./src/kmeans.cl
krnl_kmeans_CLFLAGS= --nk kmeans:$(COMPUTE_UNITS) -D PARALLEL_POINTS=$(PARALLEL_POINTS) -D PARALLEL_FEATURES=$(PARALLEL_FEATURES) -D USE_DATA_TYPE=$(DATATYPE_ID)

EXES=kmeans
XCLBINS=krnl_kmeans
EXTRA_CLEAN=membership.out

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)


# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = -k ./xclbin/$(XCLBINS).$(1).$(call sanitize_dsa,$(2)).xclbin -i $(TEST_FILE) -m $(NCLUSTERS) -n $(NCLUSTERS) -c $(GOLD_FILE) -g $(COMPUTE_UNITS) 
endef
$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))
CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

