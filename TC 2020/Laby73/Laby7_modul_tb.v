`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:27:01 04/22/2020
// Design Name:   Laby7_modul
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby73/Laby7_modul_tb.v
// Project Name:  Laby73
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby7_modul
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby7_modul_tb;

	// Inputs
	reg clk;

	// Outputs
	wire [3:0] cnt;

	// Instantiate the Unit Under Test (UUT)
	Laby7_modul uut (
		.clk(clk), 
		.cnt(cnt)
	);

	initial begin
		// Initialize Inputs
		clk = 0;

		// Wait 100 ns for global reset to finish
		forever begin
		#10 clk=!clk;
        end
		// Add stimulus here

	end
      
endmodule

