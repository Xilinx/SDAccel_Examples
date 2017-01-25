opencv_CXXFLAGS=-I$(XILINX_SDACCEL)/Vivado_HLS/include
opencv_LDFLAGS=-L$(XILINX_SDACCEL)/Vivado_HLS/lnx64/tools/opencv/ -lopencv_core -lopencv_highgui -lopencv_imgproc
