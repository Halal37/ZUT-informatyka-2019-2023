`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:18:39 05/27/2020 
// Design Name: 
// Module Name:    Laby11 
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
module Laby11(
input iCLK,
output reg oSIG
);
reg [22:0] rCNT=0;
reg rTYM=0;

always @(negedge iCLK) begin
 rCNT=rCNT+1;
 if (rCNT==250000) begin
    rCNT=0;
    rTYM=!rTYM;
    end
end 


   
reg [3:0] rNUMSTAN=11;
always @(negedge rTYM)
   begin
    rNUMSTAN=rNUMSTAN+1;
    if (rNUMSTAN==12) rNUMSTAN=0;
end 
 always @*
    begin
    if (rNUMSTAN==0) oSIG=0;
    if (rNUMSTAN==1) oSIG=0;
    if (rNUMSTAN==2) oSIG=0;
    if (rNUMSTAN==3) oSIG=1;
    if (rNUMSTAN==4) oSIG=0;
    if (rNUMSTAN==5) oSIG=0;
    if (rNUMSTAN==6) oSIG=0;
    if (rNUMSTAN==7) oSIG=1;
    if (rNUMSTAN==8) oSIG=0;
    if (rNUMSTAN==9) oSIG=1;
	 if (rNUMSTAN==10) oSIG=1;
	 if (rNUMSTAN==11) oSIG=0;
    end
endmodule 