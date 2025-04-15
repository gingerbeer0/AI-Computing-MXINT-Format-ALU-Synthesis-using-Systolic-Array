module exp_tree(
	input CLK,
	input RSTN,
	input [15:0] fp16_first,
	input [15:0] fp16_second,
	input enable,
	output reg enable_next,
	output reg [4:0] larger_exp
);

	always @(posedge CLK or negedge RSTN) begin
		if (!RSTN) begin
			larger_exp <= 0;
			enable_next <= 0;
		end else if(enable) begin
			if (fp16_first[14:10] >= fp16_second[14:10]) begin
				larger_exp <= fp16_first[14:10];
			end else begin
				larger_exp <= fp16_second[14:10];
			end
			enable_next <= enable;
		end else begin
			larger_exp <= 0;
			enable_next <= 0;
		end
	end

endmodule