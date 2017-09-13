set_property DONT_PARTITION TRUE [get_cells -hier -filter {REF_NAME==dr_krnl_0_0}]
############################################################
#SLR crossing
add_cells_to_pblock [get_pblocks pblock_CL_top]  [get_cells -hierarchical -filter {NAME=~*/krnl_0}]
