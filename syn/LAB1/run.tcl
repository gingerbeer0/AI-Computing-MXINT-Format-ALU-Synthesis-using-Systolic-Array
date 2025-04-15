set TOPDESIGN INFEREDLATCH
read_file -format verilog ${TOPDESIGN}_SOLVED.v
analyze -format verilog ${TOPDESIGN}_SOLVED.v
elaborate ${TOPDESIGN}
link
check_design
source ./sdc/${TOPDESIGN}.sdc -verbose
check_timing
write_file -format ddc -output ./outputs/${TOPDESIGN}_unmapped.ddc
compile
report_constraint -all_violators
write_file -format verilog -output ./outputs/${TOPDESIGN}_gate.v
write_file -format ddc -output ./outputs/${TOPDESIGN}_gate.ddc
write_sdf ./outputs/${TOPDESIGN}_gate.sdf
