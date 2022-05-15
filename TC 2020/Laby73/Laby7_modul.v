`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:25:36 04/22/2020 
// Design Name: 
// Module Name:    Laby7_modul 
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
module Laby7_modul(clk,cnt);
input clk;
output [3:0] cnt;
reg [3:0] cnt=0;
always@(posedge clk) cnt=cnt+1;

endmodule
