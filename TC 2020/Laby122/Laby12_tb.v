`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:24:17 06/03/2020
// Design Name:   Lab12
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby122/Laby12_tb.v
// Project Name:  Laby122
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Lab12
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby12_tb;
reg iCLK;
	// Outputs
	wire oSOUND;

	// Instantiate the Unit Under Test (UUT)
	Lab12 uut (
	.iCLK(iCLK),
		.oSOUND(oSOUND)
	);

	initial begin
		// Initialize Inputs
iCLK=0;
end
		// Wait 100 ns for global reset to finish
always		#10iCLK=!iCLK;
        
		// Add stimulus here

      
endmodule

