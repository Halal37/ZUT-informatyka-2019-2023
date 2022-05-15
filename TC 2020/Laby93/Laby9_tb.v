`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:16:03 05/06/2020
// Design Name:   Laby9
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby93/Laby9_tb.v
// Project Name:  Laby93
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby9
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby9_tb;

	// Inputs
	reg iCLK;
	reg SW;

	// Outputs
	wire [7:0] oLED;

	// Instantiate the Unit Under Test (UUT)
	Laby9 uut (
		.iCLK(iCLK), 
		.SW(SW), 
		.oLED(oLED)
	);

	initial begin
		// Initialize Inputs
		iCLK = 0;
		SW = 0;
end
		always #500000000 SW=!SW;
		always #10 iCLK=!iCLK;

        
		// Add stimulus here

	
      
endmodule

