# Edge Detection Application

include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/simplebmp/simplebmp.mk
include ../../libs/lodepng/lodepng.mk
include ../../libs/opencl/opencl.mk

# Edge Detection Host Application
edge_SRCS=./src/edgedetection_app.cpp ./src/main.cpp ./src/sobel_cpuonly.cpp $(simplebmp_SRCS) $(logger_SRCS) $(cmdparser_SRCS) $(xcl_cpp_SRCS) $(lodepng_SRCS)
edge_HDRS=./src/sobel_cpuonly.h ./src/edgedetection_app.h $(xcl_cpp_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS) $(lodepng_HDRS)
edge_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(simplebmp_CXXFLAGS) $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_cpp_CXXFLAGS) $(lodepng_CXXFLAGS)
edge_LDFLAGS=$(opencl_LDFLAGS)

# Edge Detection Kernel
krnl_edge_SRCS=./src/krnl_sobelfilter.cl

EXES=edge
XCLBINS=krnl_edge

include ../../utility/rules.mk

