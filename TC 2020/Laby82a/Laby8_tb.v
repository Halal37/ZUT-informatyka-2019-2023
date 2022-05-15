`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:23:11 04/29/2020
// Design Name:   Laby8
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby82a/Laby8_tb.v
// Project Name:  Laby82a
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
	reg  SW;

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
end
		// Wait 100 ns for global reset to finish
		always #500000000 SW=!SW;
		always #10 clk=!clk;
     
		

		// Add stimulus here


endmodule

