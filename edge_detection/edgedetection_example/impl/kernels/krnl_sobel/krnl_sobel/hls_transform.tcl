set xmlPath "/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/kernel.xml"
transform "/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/krnl_sobel.clc.00.bc" -hls -top=krnl_sobel -xcl-xmlinfo=$xmlPath -xcl-flatten -spir-runtime-support -xcl-ports-metadata -spir-link-builtins -kernelxml -f -o /dev/null
exit
