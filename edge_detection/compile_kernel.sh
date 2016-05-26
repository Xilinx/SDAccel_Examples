#!/bin/bash

xocc -o bin_sobel.xclbin src/krnl_sobelfilter_pipelined_asyncmem.cl -t hw --xdevice xilinx:adm-pcie-ku3:1ddr:2.1

