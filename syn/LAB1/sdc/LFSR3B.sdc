###################################################################

# Created by write_sdc on Sat Oct  5 19:52:23 2024

###################################################################
set sdc_version 2.1

set_units -time ns -resistance MOhm -capacitance fF -voltage V -current uA
create_clock [get_ports CLK]  -name CLOCK  -period 1  -waveform {0 0.5}
set_clock_latency -max 0.1  [get_clocks CLOCK]
set_clock_uncertainty -setup 0.1  [get_clocks CLOCK]
set_clock_uncertainty -hold 0.05  [get_clocks CLOCK]
set_input_delay -clock CLOCK  0.1  [get_ports EN]
set_output_delay -clock CLOCK  0.1  [get_ports {OUT[2]}]
set_output_delay -clock CLOCK  0.1  [get_ports {OUT[1]}]
set_output_delay -clock CLOCK  0.1  [get_ports {OUT[0]}]
set_ideal_network -no_propagate [get_ports RSTN]
