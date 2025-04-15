`define TCK 10
module TB_FREQDIVCHAIN;
/*AUTOREGINPUT*/
// Beginning of automatic reg inputs (for undeclared instantiated-module inputs)
reg                     CLK;                    // To DUT of FREQDIVCHAIN.v
reg                     EN;                     // To DUT of FREQDIVCHAIN.v
reg                     RSTN;                   // To DUT of FREQDIVCHAIN.v
// End of automatics
/*AUTOWIRE*/
// Beginning of automatic wires (for undeclared instantiated-module outputs)
logic                   CLKDIV8;                // From DUT of FREQDIVCHAIN.v
// End of automatics

FREQDIVCHAIN 
  DUT
    (/*AUTOINST*/
     // Outputs
     .CLKDIV8                               (CLKDIV8),
     // Inputs
     .CLK                                   (CLK),
     .RSTN                                  (RSTN),
     .EN                                    (EN));
	  initial begin
				 CLK = 0;
				 forever #(`TCK/2) CLK = ~CLK;
	  end
	  initial begin
				 RSTN = 0;
				 EN =0;
				 #(`TCK*2);
				 RSTN = 1;
				 #(`TCK*2);
				 EN = 1;
				 #(`TCK*2000);
				 EN = 0;
				 #(`TCK*2);
				 $finish;
	  end
	  endmodule
// Local Variables:
// verilog-library-directories: ("." "./../../../rtl/LAB3" )
// End:
