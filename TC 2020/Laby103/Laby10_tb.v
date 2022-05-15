`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:39:58 05/13/2020
// Design Name:   Laby10
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby103/Laby10_tb.v
// Project Name:  Laby103
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby10
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
	wire oSIG_4Hz;

	// Instantiate the Unit Under Test (UUT)
	Laby10 uut(
		.iCLK(iCLK), 
		.oSIG_4Hz(oSIG_4Hz), 
	);

	initial begin
		// Initialize Inputs
		iCLK = 0;
end
		// Wait 100 ns for global reset to finish
		always #10 iCLK=!iCLK;
        
		// Add stimulus here


      
endmodule

