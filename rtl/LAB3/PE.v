module PE#(parameter SA=6, parameter FIXED_POINT=8) (
    input CLK,
    input RSTN,
    input signed [15:0] W_IN,          // 16-bit two's complement input W_IN
    input signed [15:0] D_IN,          // 16-bit two's complement input D_IN
    input [1:0] operation,         // Operation code: 00:add, 01:sub, 10:mul
    input [4:0] W_SE,          // Sign extension for the first operand
    input [4:0] D_SE,         // Sign extension for the second operand
    output reg signed [15:0] W_OUT,    // 16-bit two's complement output W_OUT
    output reg signed [15:0] D_OUT,    // 16-bit two's complement output D_OUT
    output reg signed [15:0] RESULT       // 16-bit two's complement RESULT_REG
);
    
    reg signed [19:0] W_IN_SE, D_IN_SE; 
    reg signed [39:0] RESULT_REG;


    always @(posedge CLK or negedge RSTN) begin
        if(!RSTN) begin
            W_IN_SE <= 20'd0;
            D_IN_SE <= 20'd0;
            W_OUT <= 16'd0;
            D_OUT <= 16'd0;
        end else begin
            W_IN_SE <= W_IN <<< W_SE;
            D_IN_SE <= D_IN <<< D_SE;
            W_OUT <= W_IN;
            D_OUT <= D_IN;
        end
    end

    // 연산 수행 단계
    always @(posedge CLK or negedge RSTN) begin
        if (!RSTN) begin
            RESULT_REG <= 40'd0;
        end else if(operation == 2'b00) begin
            RESULT_REG <=  (W_IN_SE * D_IN_SE) >>> (SA + SA + FIXED_POINT); // Mul 연산
        end else if(operation == 2'b01) begin
            RESULT_REG <= (W_IN_SE + D_IN_SE) >>> SA; // Add 연산
        end else if(operation == 2'b10) begin
            RESULT_REG <= (D_IN_SE - W_IN_SE) >>> SA; // Sub 연산
        end else begin
            RESULT_REG <= 40'd0;
        end
    end

    always @(posedge CLK or negedge RSTN) begin
        if(!RSTN) begin
            RESULT <= 16'd0;
        end else begin
            RESULT <= RESULT_REG[15:0];
        end
    end

endmodule
