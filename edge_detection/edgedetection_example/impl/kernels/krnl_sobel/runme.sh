#!/bin/sh

# 
# sdaccel(TM)
# runme.sh: a sdaccel-generated Runs Script for UNIX
# Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=:/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/bin:/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/bin
else
  PATH=:/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/bin:/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep vivado_hls -f krnl_sobel.tcl
