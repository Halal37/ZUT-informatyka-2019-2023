`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:49:33 05/20/2020 
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
output reg oSIG_4Hz,
output reg Sound
);
reg [22:0] rCNT=0;
reg rTYM=0;
reg [23:0] rCNT2=0;

always @(negedge iCLK) begin
 rCNT=rCNT+1;
 if (rCNT==6250000) begin
    rCNT=0;
    rTYM=!rTYM;
    end
end 


   
reg [4:0] rNUMSTAN=23;
always @(negedge rTYM)
   begin
    rNUMSTAN=rNUMSTAN+1;
    if (rNUMSTAN==24) rNUMSTAN=0;
end 
 always @*
    begin
    if (rNUMSTAN==0) oSIG_4Hz=1;
    if (rNUMSTAN==1) oSIG_4Hz=0;
    if (rNUMSTAN==2) oSIG_4Hz=1;
    if (rNUMSTAN==3) oSIG_4Hz=0;
    if (rNUMSTAN==4) oSIG_4Hz=1;
    if (rNUMSTAN==5) oSIG_4Hz=0;
    if (rNUMSTAN==6) oSIG_4Hz=1;
    if (rNUMSTAN==7) oSIG_4Hz=1;
    if (rNUMSTAN==8) oSIG_4Hz=1;
    if (rNUMSTAN==9) oSIG_4Hz=0;
	 if (rNUMSTAN==10) oSIG_4Hz=1;
    if (rNUMSTAN==11) oSIG_4Hz=1;
    if (rNUMSTAN==12) oSIG_4Hz=1;
    if (rNUMSTAN==13) oSIG_4Hz=0;
	 if (rNUMSTAN==14) oSIG_4Hz=1;
    if (rNUMSTAN==15) oSIG_4Hz=1;
    if (rNUMSTAN==16) oSIG_4Hz=1;
    if (rNUMSTAN==17) oSIG_4Hz=0;
	 if (rNUMSTAN==18) oSIG_4Hz=1;
    if (rNUMSTAN==19) oSIG_4Hz=0;
    if (rNUMSTAN==20) oSIG_4Hz=1;
    if (rNUMSTAN==21) oSIG_4Hz=0;
    if (rNUMSTAN==22) oSIG_4Hz=1;
    if (rNUMSTAN==23) oSIG_4Hz=0;
    end
	 always@(posedge iCLK)
	 if(oSIG_4Hz==1)
	 begin
	 rCNT2=rCNT2+1;
	 assign Sound=rCNT2[17];
	 end
	 else rCNT2=0;
	/* if(oSIG_4Hz==1)
	 begin
	 rCNT2=rCNT2+1;
	 if(rCNT2==125000)
	 begin
	 rCNT2=0;
	 Sound=!Sound;
	 end
	 end
	 else Sound=0;*/
endmodule

