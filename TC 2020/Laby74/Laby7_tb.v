`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:26:53 04/24/2020
// Design Name:   Laby7
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby74/Laby7_tb.v
// Project Name:  Laby74
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby7
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby7_tb;

	// Inputs
	reg clk;

	// Outputs
	wire out;
	wire [21:0] cnt;

	// Instantiate the Unit Under Test (UUT)
	Laby7 uut (
		.clk(clk), 
		.cnt(cnt),
		.out(out)
	);

	initial begin
		// Initialize Inputs
		clk = 0;

		forever begin
		#10 clk=!clk;
        end
		// Add stimulus here

	end
      
endmodule

