`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:33:23 04/22/2020 
// Design Name: 
// Module Name:    uut-Sumator 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module uut-Sumator(

    );
reg[1:0] a;
reg[1:0] b;

wire [2:0] y;
Sumator uut(
.a(a),
.b(b),
.y(y));

integer i=0,j=0;
initial begin
for( i=0; i<4; i=i+1 ) begin
for( j=0; j<4; j=j+1 ) begin
a = i; b = j; #10;
end
end
end
endmodule
