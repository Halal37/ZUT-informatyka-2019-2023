`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:34:14 05/13/2020 
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
reg [22:0] rCNT=0;
reg rTYM=0;

always @(negedge iCLK) begin
 rCNT=rCNT+1;
 if (rCNT==6250000) begin
    rCNT=0;
    rTYM=!rTYM;
    end
end 
reg [3:0] rNUMSTAN=9;

 

always @(negedge rTYM)
   begin
    rNUMSTAN=rNUMSTAN+1;
    if (rNUMSTAN==10) rNUMSTAN=0;
end 