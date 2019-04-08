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

For Setup instructions, please refer: [setup.md][]

[setup.md]: setup.md

