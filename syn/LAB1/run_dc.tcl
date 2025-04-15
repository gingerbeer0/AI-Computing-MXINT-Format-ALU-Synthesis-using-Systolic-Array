set TOPDESIGN if_1
read_verilog ${TOPDESIGN}.v
analyze -format verilog ${TOPDESIGN}.v
link
elaborate ${TOPDESIGN}
compile
