`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:44:56 04/22/2020
// Design Name:   Laby7sumator_tb
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby71/sas.v
// Project Name:  Laby71
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Laby7sumator_tb
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sas;

	// Inputs
	reg [1:0] a;
	reg [1:0] b;

	// Outputs
	wire [2:0] y;

	// Instantiate the Unit Under Test (UUT)
	Laby7sumator_tb uut (
		.a(a), 
		.b(b), 
		.y(y)
	);

	integer i=0,j=0;
initial begin
for( i=0; i<4; i=i+1 ) begin
for( j=0; j<4; j=j+1 ) begin
a = i; b = j; #10;
end
end
	end
      
endmodule

