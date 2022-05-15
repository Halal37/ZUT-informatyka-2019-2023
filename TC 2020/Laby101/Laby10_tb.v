`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:28:37 05/13/2020
// Design Name:   LAby10
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby101/Laby10_tb.v
// Project Name:  Laby101
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: LAby10
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby10_tb;

	// Inputs
	reg iCLK;

	// Outputs
	wire oSOUND;

	// Instantiate the Unit Under Test (UUT)
	LAby10 uut (
		.oSOUND(oSOUND), 
		.iCLK(iCLK)
	);

	initial begin
		// Initialize Inputs
		iCLK = 0;
		end

		// Wait 100 ns for global reset to finish
		always #10 iCLK=!iCLK;
       
		// Add stimulus here

	
      
endmodule

