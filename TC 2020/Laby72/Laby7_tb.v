`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:06:38 04/22/2020
// Design Name:   Modul_lab7
// Module Name:   C:/Users/JaSzw/OneDrive/Pulpit/ISE/Laby72/Laby7_tb.v
// Project Name:  Laby72
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Modul_lab7
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Laby7_tb;
reg [1:0] a;
reg [3:0] d;
	// Outputs
	wire y;
integer i;
	// Instantiate the Unit Under Test (UUT)
	Modul_lab7 uut (
		.a(a),
		.d(d),
		.y(y)
	);

initial
begin
for( i = 0; i <= 30; i = i + 1)
begin
a = i;
d = 0; #1;
d = 1; #1;
d = 2; #1;
d = 3; #1;
d = 4; #1;
d = 5; #1; d = 6; #1;
d = 7; #1;
d = 8; #1;
d = 9; #1;
d = 10; #1;
d = 11; #1;
d = 12; #1;
d = 13; #1;
d = 14; #1;
d = 15; #1;
end
end
endmodule
