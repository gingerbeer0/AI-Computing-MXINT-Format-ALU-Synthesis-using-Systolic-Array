###################################################################
# CLOCK
###################################################################
#MAINCLOCK
create_clock [get_ports CLK]  -name CLOCK  -period 15  -waveform {0 5}
set_clock_latency -max 0.1  [get_clocks CLOCK]
set_clock_uncertainty -setup 0.3  [get_clocks CLOCK]
set_clock_uncertainty -hold 0.1  [get_clocks CLOCK]
set_ideal_network -no_propagate [get_ports RSTN]



###################################################################
# INPUT
###################################################################
set_input_delay 0.1 -clock CLOCK [remove_from_collection [all_inputs] [get_ports {CLK RSTN}]]

###################################################################
# OUTPUT
###################################################################
set_output_delay 0.4 -clock CLOCK [all_outputs]
set_load 0.5 [all_outputs]
set_fix_hold [all_clocks]
