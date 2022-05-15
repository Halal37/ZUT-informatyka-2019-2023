`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:28:03 04/29/2020 
// Design Name: 
// Module Name:    Laby8 
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
module Laby8(input clk,
  output out
    );


reg [22:0] cnt=0;
always@(posedge clk) cnt=cnt+1;
assign out=cnt[22];

endmodule
