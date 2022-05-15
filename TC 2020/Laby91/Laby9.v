`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:22:26 05/06/2020 
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
output reg[7:0] oLED=8'h01

    );
reg [18:0] cnt=0;
always@(posedge iCLK) cnt=cnt+1;
always@(posedge cnt[18])
begin
oLED=oLED<<1; 
if (oLED==0) oLED = 8'h01;
end
endmodule
