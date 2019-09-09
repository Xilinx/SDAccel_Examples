Affine
======================

Affine transformation is a linear mapping method that preserves points, straight lines, and planes. Sets of parallel lines remain parallel after an affine transformation. The affine transformation technique is typically used to correct for geometric distortions or deformations that occur with non-ideal camera angles. The demo performs a 30 degree X rotation and a 50% X and Y scaling on a 512 by 512, 16 bits per pixels grayscale, raw MRI image.

### PERFORMANCE
Task|Xilinx Execution Time (in ns)|GTX 780 Execution Time (in ns)
-----|-----|-----
Host to Device|1,009,087|1,828,606
Device to Host|774,714|563,740
Device to Kernel|46,460,532|195,938,535
Total Execution|48,244,355|198,330,886
Frames per Second|21.5|5.1
## SUPPORTED PLATFORMS
Platform | Board             | Software Version
---------|-------------------|-----------------
xilinx_u200_qdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u50_xdma|Xilinx Alveo U50|SDx 2019.1
xilinx_u250_qdma|Xilinx Alveo U250|SDx 2019.1
xilinx_u200_xdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u280_xdma|Xilinx Alveo U280|SDx 2019.1
xilinx_u250_xdma|Xilinx Alveo U250|SDx 2019.1


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
data/CT-MONO2-16-brain.raw
src/affine.cpp
src/krnl_affine.cl
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./affine <krnl_affine XCLBIN> ./data/CT-MONO2-16-brain.raw
```

