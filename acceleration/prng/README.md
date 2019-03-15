pseudo random number generator
======================

This is an optimized implementation of the pseudo random number generator algorithm
The method used to generate a random number sequence is called complementary multiply with carry (CMWC)
targeting exection on an SDAccel support FPGA acceleration card

### PERFORMANCE
Board|Total Number of Samples|Kernel Duration
-----|-----|-----
xilinx:adm-pcie-ku3:2ddr-xpr|16777216|59.1ms

For more information, please refer: [details.md][]

[details.md]: details.md

