`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:21:46 04/29/2020
// Design Name:   Laby8
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby82/Laby8_tb.v
// Project Name:  Laby82
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby8
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby8_tb;

	// Inputs
	reg clk;
	reg [1:0] SW;

	// Outputs
	wire out;

	// Instantiate the Unit Under Test (UUT)
	Laby8 uut (
		.clk(clk), 
		.out(out), 
		.SW(SW)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		SW = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

