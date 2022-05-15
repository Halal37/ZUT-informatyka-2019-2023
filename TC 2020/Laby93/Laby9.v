`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:02:35 05/06/2020 
// Design Name: 
// Module Name:    Laby9 
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
module Laby9(input iCLK,
input SW,
output reg[7:0] oLED=8'h01

    );	 
reg [18:0] cnt=0;
always@(posedge iCLK) cnt=cnt+1;
always@(posedge cnt[18])
begin
if(SW==1) begin
oLED=oLED>>1; 
if (oLED==0) oLED = 8'h80;
end
else begin
oLED=oLED<<1; 
if (oLED==0) oLED = 8'h01;
end
end
endmodule
