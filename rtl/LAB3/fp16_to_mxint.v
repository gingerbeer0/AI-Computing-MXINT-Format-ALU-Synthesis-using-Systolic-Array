module fp16_to_mxint #(parameter SF = 4)(
    input CLK,
    input RSTN,  // Asynchronous RSTN
	input enable,
    input [15:0] fp16_in0, input [15:0] fp16_in1, input [15:0] fp16_in2, input [15:0] fp16_in3,
    input [15:0] fp16_in4, input [15:0] fp16_in5, input [15:0] fp16_in6, input [15:0] fp16_in7,
    input [15:0] fp16_in8, input [15:0] fp16_in9, input [15:0] fp16_in10, input [15:0] fp16_in11,
    input [15:0] fp16_in12, input [15:0] fp16_in13, input [15:0] fp16_in14, input [15:0] fp16_in15,
    input [15:0] fp16_in16, input [15:0] fp16_in17, input [15:0] fp16_in18, input [15:0] fp16_in19,
    input [15:0] fp16_in20, input [15:0] fp16_in21, input [15:0] fp16_in22, input [15:0] fp16_in23,
    input [15:0] fp16_in24, input [15:0] fp16_in25, input [15:0] fp16_in26, input [15:0] fp16_in27,
    input [15:0] fp16_in28, input [15:0] fp16_in29, input [15:0] fp16_in30, input [15:0] fp16_in31,

	output reg [15:0] mxint_res0, output reg [15:0] mxint_res1, output reg [15:0] mxint_res2, output reg [15:0] mxint_res3,
	output reg [15:0] mxint_res4, output reg [15:0] mxint_res5, output reg [15:0] mxint_res6, output reg [15:0] mxint_res7,
	output reg [15:0] mxint_res8, output reg [15:0] mxint_res9, output reg [15:0] mxint_res10, output reg [15:0] mxint_res11, output reg [15:0] mxint_res12, output reg [15:0] mxint_res13, output reg [15:0] mxint_res14, output reg [15:0] mxint_res15,
	output reg [15:0] mxint_res16, output reg [15:0] mxint_res17, output reg [15:0] mxint_res18, output reg [15:0] mxint_res19,
	output reg [15:0] mxint_res20, output reg [15:0] mxint_res21, output reg [15:0] mxint_res22, output reg [15:0] mxint_res23,
	output reg [15:0] mxint_res24, output reg [15:0] mxint_res25, output reg [15:0] mxint_res26, output reg [15:0] mxint_res27,
	output reg [15:0] mxint_res28, output reg [15:0] mxint_res29, output reg [15:0] mxint_res30, output reg [15:0] mxint_res31,

    output reg [4:0] shared_exponent_out,
	output reg alu_enable
);

	wire [4:0] shared_exponent;
	wire shared_exponent_enable;

	reg signed [6:0] fp16_in0_shift_amount, fp16_in1_shift_amount, fp16_in2_shift_amount, fp16_in3_shift_amount;
	reg signed [6:0] fp16_in4_shift_amount, fp16_in5_shift_amount, fp16_in6_shift_amount, fp16_in7_shift_amount;
	reg signed [6:0] fp16_in8_shift_amount, fp16_in9_shift_amount, fp16_in10_shift_amount, fp16_in11_shift_amount;
	reg signed [6:0] fp16_in12_shift_amount, fp16_in13_shift_amount, fp16_in14_shift_amount, fp16_in15_shift_amount;
	reg signed [6:0] fp16_in16_shift_amount, fp16_in17_shift_amount, fp16_in18_shift_amount, fp16_in19_shift_amount;
	reg signed [6:0] fp16_in20_shift_amount, fp16_in21_shift_amount, fp16_in22_shift_amount, fp16_in23_shift_amount;
	reg signed [6:0] fp16_in24_shift_amount, fp16_in25_shift_amount, fp16_in26_shift_amount, fp16_in27_shift_amount;
	reg signed [6:0] fp16_in28_shift_amount, fp16_in29_shift_amount, fp16_in30_shift_amount, fp16_in31_shift_amount;


	get_shared_exp u_get_shared_exp (
		.CLK(CLK),
		.RSTN(RSTN),
		.enable(enable),
		.fp16_in0(fp16_in0), .fp16_in1(fp16_in1), .fp16_in2(fp16_in2), .fp16_in3(fp16_in3),
		.fp16_in4(fp16_in4), .fp16_in5(fp16_in5), .fp16_in6(fp16_in6), .fp16_in7(fp16_in7),
		.fp16_in8(fp16_in8), .fp16_in9(fp16_in9), .fp16_in10(fp16_in10), .fp16_in11(fp16_in11),
		.fp16_in12(fp16_in12), .fp16_in13(fp16_in13), .fp16_in14(fp16_in14), .fp16_in15(fp16_in15),
		.fp16_in16(fp16_in16), .fp16_in17(fp16_in17), .fp16_in18(fp16_in18), .fp16_in19(fp16_in19),
		.fp16_in20(fp16_in20), .fp16_in21(fp16_in21), .fp16_in22(fp16_in22), .fp16_in23(fp16_in23),
		.fp16_in24(fp16_in24), .fp16_in25(fp16_in25), .fp16_in26(fp16_in26), .fp16_in27(fp16_in27),
		.fp16_in28(fp16_in28), .fp16_in29(fp16_in29), .fp16_in30(fp16_in30), .fp16_in31(fp16_in31),
		.max_exp(shared_exponent), .done(shared_exponent_enable)
	);

	always @(posedge CLK or negedge RSTN) begin
		if (!RSTN) begin
			fp16_in0_shift_amount <= 5'd0; fp16_in1_shift_amount <= 5'd0; fp16_in2_shift_amount <= 5'd0; fp16_in3_shift_amount <= 5'd0;
			fp16_in4_shift_amount <= 5'd0; fp16_in5_shift_amount <= 5'd0; fp16_in6_shift_amount <= 5'd0; fp16_in7_shift_amount <= 5'd0;
			fp16_in8_shift_amount <= 5'd0; fp16_in9_shift_amount <= 5'd0; fp16_in10_shift_amount <= 5'd0; fp16_in11_shift_amount <= 5'd0;
			fp16_in12_shift_amount <= 5'd0; fp16_in13_shift_amount <= 5'd0; fp16_in14_shift_amount <= 5'd0; fp16_in15_shift_amount <= 5'd0;
			fp16_in16_shift_amount <= 5'd0; fp16_in17_shift_amount <= 5'd0; fp16_in18_shift_amount <= 5'd0; fp16_in19_shift_amount <= 5'd0;
			fp16_in20_shift_amount <= 5'd0; fp16_in21_shift_amount <= 5'd0; fp16_in22_shift_amount <= 5'd0; fp16_in23_shift_amount <= 5'd0;
			fp16_in24_shift_amount <= 5'd0; fp16_in25_shift_amount <= 5'd0; fp16_in26_shift_amount <= 5'd0; fp16_in27_shift_amount <= 5'd0;
			fp16_in28_shift_amount <= 5'd0; fp16_in29_shift_amount <= 5'd0; fp16_in30_shift_amount <= 5'd0; fp16_in31_shift_amount <= 5'd0;
		end else if (shared_exponent_enable) begin
			fp16_in0_shift_amount <= fp16_in0[14:10] - shared_exponent + SF;
			fp16_in1_shift_amount <= fp16_in1[14:10] - shared_exponent + SF;
			fp16_in2_shift_amount <= fp16_in2[14:10] - shared_exponent + SF;
			fp16_in3_shift_amount <= fp16_in3[14:10] - shared_exponent + SF;
			fp16_in4_shift_amount <= fp16_in4[14:10] - shared_exponent + SF;
			fp16_in5_shift_amount <= fp16_in5[14:10] - shared_exponent + SF;
			fp16_in6_shift_amount <= fp16_in6[14:10] - shared_exponent + SF;
			fp16_in7_shift_amount <= fp16_in7[14:10] - shared_exponent + SF;
			fp16_in8_shift_amount <= fp16_in8[14:10] - shared_exponent + SF;
			fp16_in9_shift_amount <= fp16_in9[14:10] - shared_exponent + SF;
			fp16_in10_shift_amount <= fp16_in10[14:10] - shared_exponent + SF;
			fp16_in11_shift_amount <= fp16_in11[14:10] - shared_exponent + SF;
			fp16_in12_shift_amount <= fp16_in12[14:10] - shared_exponent + SF;
			fp16_in13_shift_amount <= fp16_in13[14:10] - shared_exponent + SF;
			fp16_in14_shift_amount <= fp16_in14[14:10] - shared_exponent + SF;
			fp16_in15_shift_amount <= fp16_in15[14:10] - shared_exponent + SF;
			fp16_in16_shift_amount <= fp16_in16[14:10] - shared_exponent + SF;
			fp16_in17_shift_amount <= fp16_in17[14:10] - shared_exponent + SF;
			fp16_in18_shift_amount <= fp16_in18[14:10] - shared_exponent + SF;
			fp16_in19_shift_amount <= fp16_in19[14:10] - shared_exponent + SF;
			fp16_in20_shift_amount <= fp16_in20[14:10] - shared_exponent + SF;
			fp16_in21_shift_amount <= fp16_in21[14:10] - shared_exponent + SF;
			fp16_in22_shift_amount <= fp16_in22[14:10] - shared_exponent + SF;
			fp16_in23_shift_amount <= fp16_in23[14:10] - shared_exponent + SF;
			fp16_in24_shift_amount <= fp16_in24[14:10] - shared_exponent + SF;
			fp16_in25_shift_amount <= fp16_in25[14:10] - shared_exponent + SF;
			fp16_in26_shift_amount <= fp16_in26[14:10] - shared_exponent + SF;
			fp16_in27_shift_amount <= fp16_in27[14:10] - shared_exponent + SF;
			fp16_in28_shift_amount <= fp16_in28[14:10] - shared_exponent + SF;
			fp16_in29_shift_amount <= fp16_in29[14:10] - shared_exponent + SF;
			fp16_in30_shift_amount <= fp16_in30[14:10] - shared_exponent + SF;
			fp16_in31_shift_amount <= fp16_in31[14:10] - shared_exponent + SF;
			
		end else begin
			fp16_in0_shift_amount <= 5'd0; fp16_in1_shift_amount <= 5'd0; fp16_in2_shift_amount <= 5'd0; fp16_in3_shift_amount <= 5'd0;
			fp16_in4_shift_amount <= 5'd0; fp16_in5_shift_amount <= 5'd0; fp16_in6_shift_amount <= 5'd0; fp16_in7_shift_amount <= 5'd0;
			fp16_in8_shift_amount <= 5'd0; fp16_in9_shift_amount <= 5'd0; fp16_in10_shift_amount <= 5'd0; fp16_in11_shift_amount <= 5'd0;
			fp16_in12_shift_amount <= 5'd0; fp16_in13_shift_amount <= 5'd0; fp16_in14_shift_amount <= 5'd0; fp16_in15_shift_amount <= 5'd0;
			fp16_in16_shift_amount <= 5'd0; fp16_in17_shift_amount <= 5'd0; fp16_in18_shift_amount <= 5'd0; fp16_in19_shift_amount <= 5'd0;
			fp16_in20_shift_amount <= 5'd0; fp16_in21_shift_amount <= 5'd0; fp16_in22_shift_amount <= 5'd0; fp16_in23_shift_amount <= 5'd0;
			fp16_in24_shift_amount <= 5'd0; fp16_in25_shift_amount <= 5'd0; fp16_in26_shift_amount <= 5'd0; fp16_in27_shift_amount <= 5'd0;
			fp16_in28_shift_amount <= 5'd0; fp16_in29_shift_amount <= 5'd0; fp16_in30_shift_amount <= 5'd0; fp16_in31_shift_amount <= 5'd0;
		end
	end

    always @(posedge CLK or negedge RSTN) begin
    if (!RSTN) begin
        // 출력 초기화
		mxint_res0 <= 16'd0; mxint_res1 <= 16'd0; mxint_res2 <= 16'd0; mxint_res3 <= 16'd0;
		mxint_res4 <= 16'd0; mxint_res5 <= 16'd0; mxint_res6 <= 16'd0; mxint_res7 <= 16'd0;
		mxint_res8 <= 16'd0; mxint_res9 <= 16'd0; mxint_res10 <= 16'd0; mxint_res11 <= 16'd0;
		mxint_res12 <= 16'd0; mxint_res13 <= 16'd0; mxint_res14 <= 16'd0; mxint_res15 <= 16'd0;
		mxint_res16 <= 16'd0; mxint_res17 <= 16'd0; mxint_res18 <= 16'd0; mxint_res19 <= 16'd0;
		mxint_res20 <= 16'd0; mxint_res21 <= 16'd0; mxint_res22 <= 16'd0; mxint_res23 <= 16'd0;
		mxint_res24 <= 16'd0; mxint_res25 <= 16'd0; mxint_res26 <= 16'd0; mxint_res27 <= 16'd0;
		mxint_res28 <= 16'd0; mxint_res29 <= 16'd0; mxint_res30 <= 16'd0; mxint_res31 <= 16'd0;
		alu_enable <= 1'b0;
		shared_exponent_out <= 5'd0;
    end else if (shared_exponent_enable) begin
        // 각 출력 계산
		mxint_res0 <= (fp16_in0_shift_amount)>=0 ? ((fp16_in0[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in0[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in0[9:0]}+1}
			  : {1'b0,{((fp16_in0[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in0[9:0]}}) <<< (fp16_in0_shift_amount)
			  : ((fp16_in0[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in0[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in0[9:0]}+1}
			  : {1'b0,{((fp16_in0[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in0[9:0]}}) >>> (~fp16_in0_shift_amount+1);

		mxint_res1 <= (fp16_in1_shift_amount)>=0 ? ((fp16_in1[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in1[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in1[9:0]}+1}
			  : {1'b0,{((fp16_in1[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in1[9:0]}}) <<< (fp16_in1_shift_amount)
			  : ((fp16_in1[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in1[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in1[9:0]}+1}
			  : {1'b0,{((fp16_in1[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in1[9:0]}}) >>> (~fp16_in1_shift_amount+1);

		mxint_res2 <= (fp16_in2_shift_amount)>=0 ? ((fp16_in2[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in2[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in2[9:0]}+1}
			  : {1'b0,{((fp16_in2[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in2[9:0]}}) <<< (fp16_in2_shift_amount)
			  : ((fp16_in2[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in2[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in2[9:0]}+1}
			  : {1'b0,{((fp16_in2[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in2[9:0]}}) >>> (~fp16_in2_shift_amount+1);

		mxint_res3 <= (fp16_in3_shift_amount)>=0 ? ((fp16_in3[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in3[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in3[9:0]}+1}
			  : {1'b0,{((fp16_in3[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in3[9:0]}}) <<< (fp16_in3_shift_amount)
			  : ((fp16_in3[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in3[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in3[9:0]}+1}
			  : {1'b0,{((fp16_in3[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in3[9:0]}}) >>> (~fp16_in3_shift_amount+1);

		mxint_res4 <= (fp16_in4_shift_amount)>=0 ? ((fp16_in4[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in4[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in4[9:0]}+1}
			  : {1'b0,{((fp16_in4[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in4[9:0]}}) <<< (fp16_in4_shift_amount)
			  : ((fp16_in4[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in4[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in4[9:0]}+1}
			  : {1'b0,{((fp16_in4[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in4[9:0]}}) >>> (~fp16_in4_shift_amount+1);

		mxint_res5 <= (fp16_in5_shift_amount)>=0 ? ((fp16_in5[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in5[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in5[9:0]}+1}
			  : {1'b0,{((fp16_in5[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in5[9:0]}}) <<< (fp16_in5_shift_amount)
			  : ((fp16_in5[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in5[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in5[9:0]}+1}
			  : {1'b0,{((fp16_in5[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in5[9:0]}}) >>> (~fp16_in5_shift_amount+1);

		mxint_res6 <= (fp16_in6_shift_amount)>=0 ? ((fp16_in6[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in6[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in6[9:0]}+1}
			  : {1'b0,{((fp16_in6[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in6[9:0]}}) <<< (fp16_in6_shift_amount)
			  : ((fp16_in6[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in6[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in6[9:0]}+1}
			  : {1'b0,{((fp16_in6[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in6[9:0]}}) >>> (~fp16_in6_shift_amount+1);

		mxint_res7 <= (fp16_in7_shift_amount)>=0 ? ((fp16_in7[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in7[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in7[9:0]}+1}
			  : {1'b0,{((fp16_in7[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in7[9:0]}}) <<< (fp16_in7_shift_amount)
			  : ((fp16_in7[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in7[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in7[9:0]}+1}
			  : {1'b0,{((fp16_in7[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in7[9:0]}}) >>> (~fp16_in7_shift_amount+1);

		mxint_res8 <= (fp16_in8_shift_amount)>=0 ? ((fp16_in8[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in8[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in8[9:0]}+1}
			  : {1'b0,{((fp16_in8[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in8[9:0]}}) <<< (fp16_in8_shift_amount)
			  : ((fp16_in8[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in8[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in8[9:0]}+1}
			  : {1'b0,{((fp16_in8[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in8[9:0]}}) >>> (~fp16_in8_shift_amount+1);

		mxint_res9 <= (fp16_in9_shift_amount)>=0 ? ((fp16_in9[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in9[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in9[9:0]}+1}
			  : {1'b0,{((fp16_in9[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in9[9:0]}}) <<< (fp16_in9_shift_amount)
			  : ((fp16_in9[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in9[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in9[9:0]}+1}
			  : {1'b0,{((fp16_in9[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in9[9:0]}}) >>> (~fp16_in9_shift_amount+1);

		mxint_res10 <= (fp16_in10_shift_amount)>=0 ? ((fp16_in10[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in10[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in10[9:0]}+1}
			  : {1'b0,{((fp16_in10[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in10[9:0]}}) <<< (fp16_in10_shift_amount)
			  : ((fp16_in10[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in10[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in10[9:0]}+1}
			  : {1'b0,{((fp16_in10[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in10[9:0]}}) >>> (~fp16_in10_shift_amount+1);

		mxint_res11 <= (fp16_in11_shift_amount)>=0 ? ((fp16_in11[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in11[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in11[9:0]}+1}
			  : {1'b0,{((fp16_in11[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in11[9:0]}}) <<< (fp16_in11_shift_amount)
			  : ((fp16_in11[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in11[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in11[9:0]}+1}
			  : {1'b0,{((fp16_in11[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in11[9:0]}}) >>> (~fp16_in11_shift_amount+1);

		mxint_res12 <= (fp16_in12_shift_amount)>=0 ? ((fp16_in12[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in12[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in12[9:0]}+1}
			  : {1'b0,{((fp16_in12[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in12[9:0]}}) <<< (fp16_in12_shift_amount)
			  : ((fp16_in12[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in12[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in12[9:0]}+1}
			  : {1'b0,{((fp16_in12[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in12[9:0]}}) >>> (~fp16_in12_shift_amount+1);

		mxint_res13 <= (fp16_in13_shift_amount)>=0 ? ((fp16_in13[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in13[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in13[9:0]}+1}
			  : {1'b0,{((fp16_in13[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in13[9:0]}}) <<< (fp16_in13_shift_amount)
			  : ((fp16_in13[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in13[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in13[9:0]}+1}
			  : {1'b0,{((fp16_in13[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in13[9:0]}}) >>> (~fp16_in13_shift_amount+1);

		mxint_res14 <= (fp16_in14_shift_amount)>=0 ? ((fp16_in14[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in14[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in14[9:0]}+1}
			  : {1'b0,{((fp16_in14[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in14[9:0]}}) <<< (fp16_in14_shift_amount)
			  : ((fp16_in14[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in14[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in14[9:0]}+1}
			  : {1'b0,{((fp16_in14[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in14[9:0]}}) >>> (~fp16_in14_shift_amount+1);

		mxint_res15 <= (fp16_in15_shift_amount)>=0 ? ((fp16_in15[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in15[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in15[9:0]}+1}
			  : {1'b0,{((fp16_in15[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in15[9:0]}}) <<< (fp16_in15_shift_amount)
			  : ((fp16_in15[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in15[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in15[9:0]}+1}
			  : {1'b0,{((fp16_in15[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in15[9:0]}}) >>> (~fp16_in15_shift_amount+1);

		mxint_res16 <= (fp16_in16_shift_amount)>=0 ? ((fp16_in16[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in16[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in16[9:0]}+1}
			  : {1'b0,{((fp16_in16[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in16[9:0]}}) <<< (fp16_in16_shift_amount)
			  : ((fp16_in16[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in16[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in16[9:0]}+1}
			  : {1'b0,{((fp16_in16[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in16[9:0]}}) >>> (~fp16_in16_shift_amount+1);

		mxint_res17 <= (fp16_in17_shift_amount)>=0 ? ((fp16_in17[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in17[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in17[9:0]}+1}
			  : {1'b0,{((fp16_in17[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in17[9:0]}}) <<< (fp16_in17_shift_amount)
			  : ((fp16_in17[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in17[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in17[9:0]}+1}
			  : {1'b0,{((fp16_in17[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in17[9:0]}}) >>> (~fp16_in17_shift_amount+1);

		mxint_res18 <= (fp16_in18_shift_amount)>=0 ? ((fp16_in18[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in18[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in18[9:0]}+1}
			  : {1'b0,{((fp16_in18[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in18[9:0]}}) <<< (fp16_in18_shift_amount)
			  : ((fp16_in18[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in18[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in18[9:0]}+1}
			  : {1'b0,{((fp16_in18[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in18[9:0]}}) >>> (~fp16_in18_shift_amount+1);

		mxint_res19 <= (fp16_in19_shift_amount)>=0 ? ((fp16_in19[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in19[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in19[9:0]}+1}
			  : {1'b0,{((fp16_in19[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in19[9:0]}}) <<< (fp16_in19_shift_amount)
			  : ((fp16_in19[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in19[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in19[9:0]}+1}
			  : {1'b0,{((fp16_in19[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in19[9:0]}}) >>> (~fp16_in19_shift_amount+1);

		mxint_res20 <= (fp16_in20_shift_amount)>=0 ? ((fp16_in20[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in20[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in20[9:0]}+1}
			  : {1'b0,{((fp16_in20[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in20[9:0]}}) <<< (fp16_in20_shift_amount)
			  : ((fp16_in20[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in20[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in20[9:0]}+1}
			  : {1'b0,{((fp16_in20[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in20[9:0]}}) >>> (~fp16_in20_shift_amount+1);

		mxint_res21 <= (fp16_in21_shift_amount)>=0 ? ((fp16_in21[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in21[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in21[9:0]}+1}
			  : {1'b0,{((fp16_in21[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in21[9:0]}}) <<< (fp16_in21_shift_amount)
			  : ((fp16_in21[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in21[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in21[9:0]}+1}
			  : {1'b0,{((fp16_in21[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in21[9:0]}}) >>> (~fp16_in21_shift_amount+1);

		mxint_res22 <= (fp16_in22_shift_amount)>=0 ? ((fp16_in22[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in22[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in22[9:0]}+1}
			  : {1'b0,{((fp16_in22[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in22[9:0]}}) <<< (fp16_in22_shift_amount)
			  : ((fp16_in22[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in22[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in22[9:0]}+1}
			  : {1'b0,{((fp16_in22[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in22[9:0]}}) >>> (~fp16_in22_shift_amount+1);

		mxint_res23 <= (fp16_in23_shift_amount)>=0 ? ((fp16_in23[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in23[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in23[9:0]}+1}
			  : {1'b0,{((fp16_in23[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in23[9:0]}}) <<< (fp16_in23_shift_amount)
			  : ((fp16_in23[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in23[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in23[9:0]}+1}
			  : {1'b0,{((fp16_in23[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in23[9:0]}}) >>> (~fp16_in23_shift_amount+1);

		mxint_res24 <= (fp16_in24_shift_amount)>=0 ? ((fp16_in24[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in24[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in24[9:0]}+1}
			  : {1'b0,{((fp16_in24[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in24[9:0]}}) <<< (fp16_in24_shift_amount)
			  : ((fp16_in24[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in24[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in24[9:0]}+1}
			  : {1'b0,{((fp16_in24[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in24[9:0]}}) >>> (~fp16_in24_shift_amount+1);

		mxint_res25 <= (fp16_in25_shift_amount)>=0 ? ((fp16_in25[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in25[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in25[9:0]}+1}
			  : {1'b0,{((fp16_in25[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in25[9:0]}}) <<< (fp16_in25_shift_amount)
			  : ((fp16_in25[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in25[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in25[9:0]}+1}
			  : {1'b0,{((fp16_in25[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in25[9:0]}}) >>> (~fp16_in25_shift_amount+1);

		mxint_res26 <= (fp16_in26_shift_amount)>=0 ? ((fp16_in26[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in26[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in26[9:0]}+1}
			  : {1'b0,{((fp16_in26[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in26[9:0]}}) <<< (fp16_in26_shift_amount)
			  : ((fp16_in26[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in26[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in26[9:0]}+1}
			  : {1'b0,{((fp16_in26[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in26[9:0]}}) >>> (~fp16_in26_shift_amount+1);

		mxint_res27 <= (fp16_in27_shift_amount)>=0 ? ((fp16_in27[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in27[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in27[9:0]}+1}
			  : {1'b0,{((fp16_in27[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in27[9:0]}}) <<< (fp16_in27_shift_amount)
			  : ((fp16_in27[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in27[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in27[9:0]}+1}
			  : {1'b0,{((fp16_in27[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in27[9:0]}}) >>> (~fp16_in27_shift_amount+1);

		mxint_res28 <= (fp16_in28_shift_amount)>=0 ? ((fp16_in28[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in28[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in28[9:0]}+1}
			  : {1'b0,{((fp16_in28[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in28[9:0]}}) <<< (fp16_in28_shift_amount)
			  : ((fp16_in28[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in28[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in28[9:0]}+1}
			  : {1'b0,{((fp16_in28[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in28[9:0]}}) >>> (~fp16_in28_shift_amount+1);

		mxint_res29 <= (fp16_in29_shift_amount)>=0 ? ((fp16_in29[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in29[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in29[9:0]}+1}
			  : {1'b0,{((fp16_in29[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in29[9:0]}}) <<< (fp16_in29_shift_amount)
			  : ((fp16_in29[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in29[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in29[9:0]}+1}
			  : {1'b0,{((fp16_in29[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in29[9:0]}}) >>> (~fp16_in29_shift_amount+1);

		mxint_res30 <= (fp16_in30_shift_amount)>=0 ? ((fp16_in30[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in30[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in30[9:0]}+1}
			  : {1'b0,{((fp16_in30[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in30[9:0]}}) <<< (fp16_in30_shift_amount)
			  : ((fp16_in30[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in30[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in30[9:0]}+1}
			  : {1'b0,{((fp16_in30[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in30[9:0]}}) >>> (~fp16_in30_shift_amount+1);

		mxint_res31 <= (fp16_in31_shift_amount)>=0 ? ((fp16_in31[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in31[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in31[9:0]}+1}
			  : {1'b0,{((fp16_in31[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in31[9:0]}}) <<< (fp16_in31_shift_amount)
			  : ((fp16_in31[15] == 1'b1)
			  ? {1'b1, ~{((fp16_in31[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in31[9:0]}+1}
			  : {1'b0,{((fp16_in31[14:10] != 5'b00000) ? 1'b1 : 1'b0), fp16_in31[9:0]}}) >>> (~fp16_in31_shift_amount+1);

		

		
		

		shared_exponent_out <= shared_exponent - 15; //bias
		alu_enable <= 1'b1;
		
    end else begin
        // 출력 초기화
        mxint_res0 <= 16'd0; mxint_res1 <= 16'd0; mxint_res2 <= 16'd0; mxint_res3 <= 16'd0;
		mxint_res4 <= 16'd0; mxint_res5 <= 16'd0; mxint_res6 <= 16'd0; mxint_res7 <= 16'd0;
		mxint_res8 <= 16'd0; mxint_res9 <= 16'd0; mxint_res10 <= 16'd0; mxint_res11 <= 16'd0;
		mxint_res12 <= 16'd0; mxint_res13 <= 16'd0; mxint_res14 <= 16'd0; mxint_res15 <= 16'd0;
		mxint_res16 <= 16'd0; mxint_res17 <= 16'd0; mxint_res18 <= 16'd0; mxint_res19 <= 16'd0;
		mxint_res20 <= 16'd0; mxint_res21 <= 16'd0; mxint_res22 <= 16'd0; mxint_res23 <= 16'd0;
		mxint_res24 <= 16'd0; mxint_res25 <= 16'd0; mxint_res26 <= 16'd0; mxint_res27 <= 16'd0;
		mxint_res28 <= 16'd0; mxint_res29 <= 16'd0; mxint_res30 <= 16'd0; mxint_res31 <= 16'd0;
		shared_exponent_out <= 5'd0;
		alu_enable <= 1'b0;
    end
end

endmodule