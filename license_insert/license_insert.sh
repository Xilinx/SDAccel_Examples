#!/bin/bash

echo "Loading license file"

PWD=`pwd`
LICENSE_FILE="xilinx_opensource_lic.txt"
LICENSE_DIR="license_insert"

### C/C++ comment start
C_start='/**********'
C_end="**********/"

# Temp file for the C style comment tags
echo "$C_start" > c1_temp.txt
echo $C_end > c2_temp.txt

echo "Processing CPP Files"
# cpp files
for i in `ls *.cpp`
do
    cat c1_temp.txt ../${LICENSE_DIR}/${LICENSE_FILE} c2_temp.txt $i > ${i}_temp
    mv ${i}_temp $i
done

echo "Processing C Files"
# c files
for i in `ls *.c`
do
    cat c1_temp.txt ../${LICENSE_DIR}/${LICENSE_FILE} c2_temp.txt $i > ${i}_temp
    mv ${i}_temp $i
done

# header files
echo "Processing Header Files"
for i in `ls *.h`
do
    cat c1_temp.txt ../${LICENSE_DIR}/${LICENSE_FILE} c2_temp.txt $i > ${i}_temp
    mv ${i}_temp $i
done

# kernel files
echo "Processing Header Files"
for i in `ls *.cl`
do
    cat c1_temp.txt ../${LICENSE_DIR}/${LICENSE_FILE} c2_temp.txt $i > ${i}_temp
    mv ${i}_temp $i
done

# tcl files
echo "Processing TCL Files"
sed 's/^/#/' ../${LICENSE_DIR}/${LICENSE_FILE} > local_license.txt

for i in `ls *.tcl`
do
    cat local_license.txt $i > ${i}_temp
    mv ${i}_temp $i
done

echo "Final cleanup"
rm c1_temp.txt
rm c2_temp.txt
rm local_license.txt
echo "Done"
