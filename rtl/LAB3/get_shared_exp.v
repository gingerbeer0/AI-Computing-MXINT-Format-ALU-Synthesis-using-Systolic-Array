module get_shared_exp(
	input CLK,
	input RSTN,
	input enable,
    input [15:0] fp16_in0, input [15:0] fp16_in1, input [15:0] fp16_in2, input [15:0] fp16_in3,
    input [15:0] fp16_in4, input [15:0] fp16_in5, input [15:0] fp16_in6, input [15:0] fp16_in7,
    input [15:0] fp16_in8, input [15:0] fp16_in9, input [15:0] fp16_in10, input [15:0] fp16_in11,
    input [15:0] fp16_in12, input [15:0] fp16_in13, input [15:0] fp16_in14, input [15:0] fp16_in15,
    input [15:0] fp16_in16, input [15:0] fp16_in17, input [15:0] fp16_in18, input [15:0] fp16_in19,
    input [15:0] fp16_in20, input [15:0] fp16_in21, input [15:0] fp16_in22, input [15:0] fp16_in23,
    input [15:0] fp16_in24, input [15:0] fp16_in25, input [15:0] fp16_in26, input [15:0] fp16_in27,
    input [15:0] fp16_in28, input [15:0] fp16_in29, input [15:0] fp16_in30, input [15:0] fp16_in31,
    output wire [4:0] max_exp, output wire done
);
	wire [4:0] larger_exp1, larger_exp2, larger_exp3, larger_exp4, larger_exp5, larger_exp6, larger_exp7, larger_exp8, larger_exp9, larger_exp10, larger_exp11, larger_exp12, larger_exp13, larger_exp14, larger_exp15, larger_exp16;

	wire second_stage_enable;

	wire [4:0] second_stage_exp1, second_stage_exp2, second_stage_exp3, second_stage_exp4, second_stage_exp5, second_stage_exp6, second_stage_exp7, second_stage_exp8;

	wire third_stage_enable;

	wire [4:0] third_stage_exp1, third_stage_exp2, third_stage_exp3, third_stage_exp4;

	wire fourth_stage_enable;

	wire [4:0] fourth_stage_exp1, fourth_stage_exp2;

	wire fifth_stage_enable;

	wire [4:0] fifth_stage_exp1;
    
	exp_tree exp_tree_1(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in0), .fp16_second(fp16_in1), .enable(enable), .enable_next(), .larger_exp(larger_exp1));
	exp_tree exp_tree_2(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in2), .fp16_second(fp16_in3), .enable(enable), .enable_next(), .larger_exp(larger_exp2));
	exp_tree exp_tree_3(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in4), .fp16_second(fp16_in5), .enable(enable), .enable_next(), .larger_exp(larger_exp3));
	exp_tree exp_tree_4(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in6), .fp16_second(fp16_in7), .enable(enable), .enable_next(), .larger_exp(larger_exp4));
	exp_tree exp_tree_5(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in8), .fp16_second(fp16_in9), .enable(enable), .enable_next(), .larger_exp(larger_exp5));
	exp_tree exp_tree_6(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in10), .fp16_second(fp16_in11), .enable(enable), .enable_next(), .larger_exp(larger_exp6));
	exp_tree exp_tree_7(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in12), .fp16_second(fp16_in13), .enable(enable), .enable_next(), .larger_exp(larger_exp7));
	exp_tree exp_tree_8(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in14), .fp16_second(fp16_in15), .enable(enable), .enable_next(), .larger_exp(larger_exp8));
	exp_tree exp_tree_9(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in16), .fp16_second(fp16_in17), .enable(enable), .enable_next(), .larger_exp(larger_exp9));
	exp_tree exp_tree_10(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in18), .fp16_second(fp16_in19), .enable(enable), .enable_next(), .larger_exp(larger_exp10));
	exp_tree exp_tree_11(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in20), .fp16_second(fp16_in21), .enable(enable), .enable_next(), .larger_exp(larger_exp11));
	exp_tree exp_tree_12(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in22), .fp16_second(fp16_in23), .enable(enable), .enable_next(), .larger_exp(larger_exp12));
	exp_tree exp_tree_13(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in24), .fp16_second(fp16_in25), .enable(enable), .enable_next(), .larger_exp(larger_exp13));
	exp_tree exp_tree_14(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in26), .fp16_second(fp16_in27), .enable(enable), .enable_next(), .larger_exp(larger_exp14));
	exp_tree exp_tree_15(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in28), .fp16_second(fp16_in29), .enable(enable), .enable_next(), .larger_exp(larger_exp15));
	exp_tree exp_tree_16(.CLK(CLK), .RSTN(RSTN), .fp16_first(fp16_in30), .fp16_second(fp16_in31), .enable(enable), .enable_next(second_stage_enable), .larger_exp(larger_exp16));
	

	exp_tree_next exp_tree_second_1(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp1), .exp_second(larger_exp2), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp1));
	exp_tree_next exp_tree_second_2(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp3), .exp_second(larger_exp4), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp2));
	exp_tree_next exp_tree_second_3(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp5), .exp_second(larger_exp6), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp3));
	exp_tree_next exp_tree_second_4(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp7), .exp_second(larger_exp8), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp4));
	exp_tree_next exp_tree_second_5(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp9), .exp_second(larger_exp10), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp5));
	exp_tree_next exp_tree_second_6(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp11), .exp_second(larger_exp12), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp6));
	exp_tree_next exp_tree_second_7(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp13), .exp_second(larger_exp14), .enable(second_stage_enable), .enable_next(), .larger_exp(second_stage_exp7));
	exp_tree_next exp_tree_second_8(.CLK(CLK), .RSTN(RSTN), .exp_first(larger_exp15), .exp_second(larger_exp16), .enable(second_stage_enable), .enable_next(third_stage_enable), .larger_exp(second_stage_exp8));

	exp_tree_next exp_tree_third_1(.CLK(CLK), .RSTN(RSTN), .exp_first(second_stage_exp1), .exp_second(second_stage_exp2), .enable(third_stage_enable), .enable_next(), .larger_exp(third_stage_exp1));
	exp_tree_next exp_tree_third_2(.CLK(CLK), .RSTN(RSTN), .exp_first(second_stage_exp3), .exp_second(second_stage_exp4), .enable(third_stage_enable), .enable_next(), .larger_exp(third_stage_exp2));
	exp_tree_next exp_tree_third_3(.CLK(CLK), .RSTN(RSTN), .exp_first(second_stage_exp5), .exp_second(second_stage_exp6), .enable(third_stage_enable), .enable_next(), .larger_exp(third_stage_exp3));
	exp_tree_next exp_tree_third_4(.CLK(CLK), .RSTN(RSTN), .exp_first(second_stage_exp7), .exp_second(second_stage_exp8), .enable(third_stage_enable), .enable_next(fourth_stage_enable), .larger_exp(third_stage_exp4));

	exp_tree_next exp_tree_fourth_1(.CLK(CLK), .RSTN(RSTN), .exp_first(third_stage_exp1), .exp_second(third_stage_exp2), .enable(fourth_stage_enable), .enable_next(), .larger_exp(fourth_stage_exp1));
	exp_tree_next exp_tree_fourth_2(.CLK(CLK), .RSTN(RSTN), .exp_first(third_stage_exp3), .exp_second(third_stage_exp4), .enable(fourth_stage_enable), .enable_next(fifth_stage_enable), .larger_exp(fourth_stage_exp2));

	exp_tree_next exp_tree_fifth_1(.CLK(CLK), .RSTN(RSTN), .exp_first(fourth_stage_exp1), .exp_second(fourth_stage_exp2), .enable(fifth_stage_enable), .enable_next(done), .larger_exp(max_exp));

endmodule
