`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:36:02 05/06/2020
// Design Name:   Laby9
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby91/Laby9_tb.v
// Project Name:  Laby91
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

	// Outputs
	wire [7:0] oLED;

	// Instantiate the Unit Under Test (UUT)
	Laby9 uut (
		.oLED(oLED), 
		.iCLK(iCLK)
	);

	initial begin
		// Initialize Inputs
		iCLK = 0;
end
		always #10 iCLK=!iCLK;
        
		// Add stimulus here

	
      
endmodule

