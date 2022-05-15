`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:24:47 05/26/2020
// Design Name:   Laby11
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby115/Laby11_tb.v
// Project Name:  Laby115
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby11
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby11_tb;

	// Inputs
	reg iCLK;

	// Outputs
	wire oSIG_4Hz;
	wire Sound;

	// Instantiate the Unit Under Test (UUT)
	Laby11 uut (
		.iCLK(iCLK), 
		.oSIG_4Hz(oSIG_4Hz), 
		.Sound(Sound)
	);

	initial begin
		// Initialize Inputs
		iCLK = 0;
end
		// Wait 100 ns for global reset to finish
	always	#10 iCLK=!iCLK;
        
		// Add stimulus here

      
endmodule

