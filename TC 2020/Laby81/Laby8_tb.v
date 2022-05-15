`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:30:15 04/29/2020
// Design Name:   Laby8
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby81/Laby8_tb.v
// Project Name:  Laby81
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

	// Outputs
	wire out;

	// Instantiate the Unit Under Test (UUT)
	Laby8 uut (
		.clk(clk),  
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

