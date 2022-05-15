`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:22:39 04/29/2020 
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
  output out,
  input SW
    );


reg [22:0] cnt2=0;
always@(posedge clk) cnt2=cnt2+1;
assign out=SW?cnt2[22]:cnt2[20];

endmodule 