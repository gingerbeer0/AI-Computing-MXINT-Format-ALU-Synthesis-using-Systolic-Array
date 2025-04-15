###################################################################
# CLOCK
###################################################################
# Define main clock
sg_create_clock [sg_get_ports CLK] -name CLOCK -period 15 -waveform {0 5}

# Specify clock latency for minimum and maximum delays
sg_set_clock_latency -min 0.05 -max 0.10 [sg_get_clocks CLOCK]

# Define clock uncertainty for setup and hold
sg_set_clock_uncertainty -setup 0.2 [sg_get_clocks CLOCK]
sg_set_clock_uncertainty -hold 0.05 [sg_get_clocks CLOCK]

###################################################################
# INPUT
###################################################################
# Specify input delays with min and max constraints
sg_set_input_delay -min 0.05 -max 0.15 -clock CLOCK [sg_remove_from_collection [sg_all_inputs] [sg_get_ports {CLK RSTN}]]

###################################################################
# OUTPUT
###################################################################
# Define output delays with min and max constraints
sg_set_output_delay -min 0.2 -max 0.6 -clock CLOCK [sg_all_outputs]

# Set output load for all outputs
sg_set_load 0.5 [sg_all_outputs]

###################################################################
# CAPACITANCE CONSTRAINTS
###################################################################
# Set maximum capacitance for all nets
sg_set_max_capacitance 8.0 [all_nets]

# Limit fanout to reduce capacitance violations
sg_set_max_fanout 4 [all_nets]

###################################################################
# MAX TRANSITION CONSTRAINTS
###################################################################
# Set maximum transition time for all nets
sg_set_max_transition 0.5 [all_nets]

###################################################################
# FANOUT OPTIMIZATION
###################################################################
# Insert buffers for high-fanout nets to reduce transition time and capacitance violations
insert_buffer -name BUFx [sg_get_nets -of_objects [sg_all_inputs]]

###################################################################
# HOLD TIME FIX
###################################################################
# Fix hold violations automatically
sg_set_fix_hold [sg_get_clocks CLOCK]

###################################################################
# TIMING-DRIVEN OPTIMIZATION
###################################################################
# Enable timing-driven optimization during placement and routing
opt_design -transition
route_design -timing_driven
