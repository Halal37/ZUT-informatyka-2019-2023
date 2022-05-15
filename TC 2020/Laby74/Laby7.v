`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:25:07 04/24/2020 
// Design Name: 
// Module Name:    Laby7 
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
module Laby7(clk,cnt,out);
  input clk;
  output out;
output [21:0] cnt;
reg [21:0] cnt=0;
always@(posedge clk) cnt=cnt+1;
assign out=cnt/1;
endmodule
