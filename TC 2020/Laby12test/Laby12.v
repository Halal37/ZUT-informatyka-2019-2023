`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:11:33 06/18/2020 
// Design Name: 
// Module Name:    Laby12 
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
module Laby12(
input iCLK,
output oSOUND
);
//Pamiec do zapisania czasu trwania stanow
wire [2:0] mTIME [5:0];
assign mTIME[0] = 6;
assign mTIME[1] = 2;
assign mTIME[2] = 6;
assign mTIME[3] = 2;
assign mTIME[4]=  6;
assign mTIME[5]=  2;
//Pamiec do zapisania czêstotliwoœci dzwieku w stanach
wire [20:0] mFREQUENCY [5:0];
assign mFREQUENCY[0] = 31_888;
assign mFREQUENCY[1] = 0;
assign mFREQUENCY[2] = 37_919;
assign mFREQUENCY[3] = 0;
assign mFREQUENCY[4] = 37_919;
assign mFREQUENCY[5] = 0;
// Generacja sygna³u rTYM o okresie rownym czasowi trwania najkrotszego stanu
reg rTYM=0;
reg [22:0] rCNT=0;
always @( posedge iCLK ) begin
rCNT = rCNT + 1;
if( rCNT == 6_250_000) begin
rCNT = 0;
rTYM = !rTYM;
end
 end 
// Generacja numeru stanu i sygnalu rUCNT do zmiany stanow
reg [8:0] rNUMSTAN = 5;
reg [3:0] rUCNT = 2'b00;
reg rSIG=1;
always @(negedge rTYM) begin
rUCNT = rUCNT + 1;
if (rUCNT >= mTIME[rNUMSTAN]) begin
rNUMSTAN=rNUMSTAN+1;
rUCNT=0;
rSIG=!rSIG;
if (rNUMSTAN>=6) rNUMSTAN=0;
end
end
// Generacja sygnalu rSOUND o czêstotliwoœci zaleznej od numeru stanu gdy dzwiek ma byæ emitowany
reg [20:0] rCNT_S=0;
reg rSOUND=0;
always @( posedge iCLK ) begin
if (rSIG==1) begin
rCNT_S=rCNT_S+1;
if (rCNT_S==mFREQUENCY[rNUMSTAN]) begin
rCNT_S=0;
rSOUND=!rSOUND;
end
end
if (rSIG==0) begin
	rSOUND = 0;
end
end
assign oSOUND=rSOUND;
endmodule 