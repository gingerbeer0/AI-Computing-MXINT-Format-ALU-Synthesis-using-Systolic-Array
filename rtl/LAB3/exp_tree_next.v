module exp_tree_next(
	input CLK,
	input RSTN,
	input [4:0] exp_first,
	input [4:0] exp_second,
	input enable,
	output reg enable_next,
	output reg [4:0] larger_exp
);

	always @(posedge CLK or negedge RSTN) begin
		if (!RSTN) begin
			larger_exp <= 0;
		end else if(enable) begin
			if (exp_first >= exp_second) begin
				larger_exp <= exp_first;
			end else begin
				larger_exp <= exp_second;
			end
			enable_next <= enable;
		end else begin
			larger_exp <= 0;
			enable_next <= 0;
		end
	end

endmodule