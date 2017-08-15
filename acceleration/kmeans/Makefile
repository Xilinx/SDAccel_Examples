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

host_kmeans_SRCS=src/cluster.c src/rmse.c src/fpga_kmeans.cpp src/host.cpp src/kmeans_clustering_cmodel.c 
host_kmeans_SRCS+= $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS) $(oclHelper_SRCS)
host_kmeans_HDRS = $(logger_SRCS) $(cmdparser_HDRS) $(xcl_HDRS) $(oclHelper_HDRS)
host_kmeans_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) -D RECORD_OVERALL_TIME -D USE_DATA_TYPE=$(DATATYPE_ID) #-DVERIFY_USING_CMODEL 
host_kmeans_CXXFLAGS+= $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) 
host_kmeans_LDFLAGS=$(opencl_LDFLAGS) -lxilinxopencl -lpthread -lrt

EXES=host_kmeans

#Kmeans Kernel
kmeans_SRCS=./src/kmeans.cl
kmeans_CLFLAGS=-D PARALLEL_POINTS=$(PARALLEL_POINTS) -D PARALLEL_FEATURES=$(PARALLEL_FEATURES) -D USE_DATA_TYPE=$(DATATYPE_ID)

XOS=kmeans

# Kmeans xclbin
kmeans_XOS=kmeans
kmeans_LDCLFLAGS=--nk kmeans:$(COMPUTE_UNITS)

XCLBINS=kmeans

EXTRA_CLEAN=membership.out

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)
check_ARGS= -i $(TEST_FILE) -m $(NCLUSTERS) -n $(NCLUSTERS) -c $(GOLD_FILE) -g $(COMPUTE_UNITS) 

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

