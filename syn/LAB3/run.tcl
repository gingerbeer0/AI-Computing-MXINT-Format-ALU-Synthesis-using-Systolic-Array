set TOPDESIGN TOP
set RTL_FILES { \
		  "PE.v" \
		  "exp_tree.v" \
                  "exp_tree_next.v" \
                  "get_shared_exp.v" \
                  "fp16_to_mxint.v" \
                  "stair_array.v" \
                  "output_buffer.v" \
                  "TOP.v" \
}
read_file -format verilog $RTL_FILES
analyze -format verilog $RTL_FILES
elaborate ${TOPDESIGN}
link
check_design
source ./sdc/${TOPDESIGN}.sdc -verbose
check_timing
write_file -format ddc -output ./outputs/${TOPDESIGN}_unmapped.ddc
compile_ultra -no_autoungroup
report_constraint -all_violators
write_file -format verilog -hierarchy -output ./outputs/${TOPDESIGN}_gate.v
write_file -format ddc -hierarchy -output ./outputs/${TOPDESIGN}_gate.ddc
write_sdf ./outputs/${TOPDESIGN}_gate.sdf
report_timing -delay_type max > outputs/${TOPDESIGN}_timing_report_max.txt
report_timing -delay_type min > outputs/${TOPDESIGN}_timing_report_min.txt
report_area > outputs/${TOPDESIGN}_area_report.txt
report_power > outputs/${TOPDESIGN}_power_report.txt
