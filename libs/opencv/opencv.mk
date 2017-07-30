opencv_CXXFLAGS=-I$(XILINX_SDACCEL)/include
opencv_LDFLAGS=-L$(XILINX_SDACCEL)/lnx64/tools/opencv/ -lopencv_core -lopencv_highgui -lopencv_imgproc
