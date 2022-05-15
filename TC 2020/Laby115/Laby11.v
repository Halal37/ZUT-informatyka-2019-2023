`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:10:12 05/26/2020 
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


   
reg [7:0] rNUMSTAN=86;
always @(negedge rTYM)
   begin
    rNUMSTAN=rNUMSTAN+1;
    if (rNUMSTAN==87) rNUMSTAN=0;
end 
 always @*
    begin
	 //w	 
    if (rNUMSTAN==0) oSIG_4Hz=1;
    if (rNUMSTAN==1) oSIG_4Hz=0;
    if (rNUMSTAN==2) oSIG_4Hz=1;
    if (rNUMSTAN==3) oSIG_4Hz=1;
    if (rNUMSTAN==4) oSIG_4Hz=1;
    if (rNUMSTAN==5) oSIG_4Hz=0;
    if (rNUMSTAN==6) oSIG_4Hz=1;
    if (rNUMSTAN==7) oSIG_4Hz=1;
    if (rNUMSTAN==8) oSIG_4Hz=1;
    if (rNUMSTAN==9) oSIG_4Hz=0;
	 //o
	 if (rNUMSTAN==10) oSIG_4Hz=0;
	 if (rNUMSTAN==11) oSIG_4Hz=1;
    if (rNUMSTAN==12) oSIG_4Hz=1;
    if (rNUMSTAN==13) oSIG_4Hz=1;
    if (rNUMSTAN==14) oSIG_4Hz=0;
	 if (rNUMSTAN==15) oSIG_4Hz=1;
    if (rNUMSTAN==16) oSIG_4Hz=1;
    if (rNUMSTAN==17) oSIG_4Hz=1;
    if (rNUMSTAN==18) oSIG_4Hz=0;
	 if (rNUMSTAN==19) oSIG_4Hz=1;
    if (rNUMSTAN==20) oSIG_4Hz=1;
    if (rNUMSTAN==21) oSIG_4Hz=1;
    if (rNUMSTAN==22) oSIG_4Hz=0;
    if (rNUMSTAN==23) oSIG_4Hz=1;
    if (rNUMSTAN==24) oSIG_4Hz=0;
    //j
	 if (rNUMSTAN==25) oSIG_4Hz=0;
	 if (rNUMSTAN==26) oSIG_4Hz=1;
    if (rNUMSTAN==27) oSIG_4Hz=0;
    if (rNUMSTAN==28) oSIG_4Hz=1;
    if (rNUMSTAN==29) oSIG_4Hz=1;
	 if (rNUMSTAN==30) oSIG_4Hz=1;
    if (rNUMSTAN==31) oSIG_4Hz=0;
    if (rNUMSTAN==32) oSIG_4Hz=1;
    if (rNUMSTAN==33) oSIG_4Hz=1;
	 if (rNUMSTAN==34) oSIG_4Hz=1;
    if (rNUMSTAN==35) oSIG_4Hz=0;
    if (rNUMSTAN==36) oSIG_4Hz=1;
    if (rNUMSTAN==37) oSIG_4Hz=1;
    if (rNUMSTAN==38) oSIG_4Hz=1;
    if (rNUMSTAN==39) oSIG_4Hz=0;
	 if (rNUMSTAN==40) oSIG_4Hz=1;
    if (rNUMSTAN==41) oSIG_4Hz=1;
    if (rNUMSTAN==42) oSIG_4Hz=1;
    if (rNUMSTAN==43) oSIG_4Hz=0;
	 //c
	 if (rNUMSTAN==44) oSIG_4Hz=0;
	 if (rNUMSTAN==45) oSIG_4Hz=1;
    if (rNUMSTAN==46) oSIG_4Hz=1;
    if (rNUMSTAN==47) oSIG_4Hz=1;
    if (rNUMSTAN==48) oSIG_4Hz=0;
	 if (rNUMSTAN==49) oSIG_4Hz=1;
    if (rNUMSTAN==50) oSIG_4Hz=0;
    if (rNUMSTAN==51) oSIG_4Hz=1;
    if (rNUMSTAN==52) oSIG_4Hz=1;
	 if (rNUMSTAN==53) oSIG_4Hz=1;
    if (rNUMSTAN==54) oSIG_4Hz=0;
    if (rNUMSTAN==55) oSIG_4Hz=1;
    if (rNUMSTAN==56) oSIG_4Hz=0;
	 //i
	 if (rNUMSTAN==57) oSIG_4Hz=0;
	 if (rNUMSTAN==58) oSIG_4Hz=1;
    if (rNUMSTAN==59) oSIG_4Hz=0;
	 if (rNUMSTAN==60) oSIG_4Hz=1;
    if (rNUMSTAN==61) oSIG_4Hz=0;
	 //e
	 if (rNUMSTAN==62) oSIG_4Hz=0;
	 if (rNUMSTAN==63) oSIG_4Hz=1;
    if (rNUMSTAN==64) oSIG_4Hz=0;
	 //c
	 if (rNUMSTAN==65) oSIG_4Hz=0;
	 if (rNUMSTAN==66) oSIG_4Hz=1;
    if (rNUMSTAN==67) oSIG_4Hz=1;
    if (rNUMSTAN==68) oSIG_4Hz=1;
    if (rNUMSTAN==69) oSIG_4Hz=0;
	 if (rNUMSTAN==70) oSIG_4Hz=1;
    if (rNUMSTAN==71) oSIG_4Hz=0;
    if (rNUMSTAN==72) oSIG_4Hz=1;
    if (rNUMSTAN==73) oSIG_4Hz=1;
	 if (rNUMSTAN==74) oSIG_4Hz=1;
    if (rNUMSTAN==75) oSIG_4Hz=0;
    if (rNUMSTAN==76) oSIG_4Hz=1;
    if (rNUMSTAN==77) oSIG_4Hz=0;
	 //h 
	 if (rNUMSTAN==78) oSIG_4Hz=0;
	 if (rNUMSTAN==79) oSIG_4Hz=1;
    if (rNUMSTAN==80) oSIG_4Hz=0;
	 if (rNUMSTAN==81) oSIG_4Hz=1;
    if (rNUMSTAN==82) oSIG_4Hz=0;
	 if (rNUMSTAN==83) oSIG_4Hz=1;
    if (rNUMSTAN==84) oSIG_4Hz=0;
	 if (rNUMSTAN==85) oSIG_4Hz=1;
    if (rNUMSTAN==86) oSIG_4Hz=0;
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
