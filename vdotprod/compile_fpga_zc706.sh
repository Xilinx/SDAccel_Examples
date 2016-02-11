#!/bin/bash

##this line sets the path to the dsa for zc706 device and also invokes xocc on the kernel
xocc --xdevice xilinx:zc706:uart:1.0 --xp "prop:solution.device_repo_paths=$PWD/dsa" krnl_vdotprod.cl -o vdotprod.xclbin
