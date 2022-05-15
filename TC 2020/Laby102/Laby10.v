`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:53:41 05/13/2020 
// Design Name: 
// Module Name:    Laby10 
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
module Laby10(
input iCLK,
output reg oSIG_4Hz=0
);
reg[22:0]cnt=0;
always@(posedge iCLK)
begin
cnt=cnt+1;
if(cnt==6250000)begin
cnt=0;
oSIG_4Hz=!oSIG_4Hz;
end 
end
endmodule
