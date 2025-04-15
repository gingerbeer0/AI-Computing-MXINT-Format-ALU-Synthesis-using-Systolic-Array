module if_1(/*AUTOARG*/
            // Outputs
            out,
            // Inputs
            a, b, sel
            );
   input a;
   input b;
   input sel;
   output reg out;
   always@(*) begin
      if(sel) begin
         out = a;
      end
      else begin
         out = b;
      end
   end
endmodule

