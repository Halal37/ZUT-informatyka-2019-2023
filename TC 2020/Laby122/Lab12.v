`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:02:51 06/03/2020 
// Design Name: 
// Module Name:    Lab12 
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
wire [1:0] mTIME [3:0];
assign mTIME[0] = 2;
assign mTIME[1] = 1;
assign mTIME[2] = 1;
assign mTIME[3] = 1;
assign mTime[4]= 1;
assign mTime[5]= 1;
//Pamiec do zapisania czêstotliwoœci dzwieku w stanach
wire [20:0] mFREQUENCY [3:0];
assign mFREQUENCY[0] = 0;
assign mFREQUENCY[1] = 0;
assign mFREQUENCY[2] = 31_888;
assign mFREQUENCY[3] = 37_919;
assign mFREQUENCY[4] = 0;
assign mFREQUENCY[5] = 37_919;
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
reg [1:0] rNUMSTAN = 3;
reg [1:0] rUCNT = 2'b00;
reg rSIG=0;
always @(negedge rTYM) begin
rUCNT = rUCNT + 1;
if (rUCNT >= mTIME[rNUMSTAN]) begin
rNUMSTAN=rNUMSTAN+1;
rUCNT=0;
rSIG=!rSIG;
if (rNUMSTAN>=4) rNUMSTAN=0;
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
end
assign oSOUND=rSOUND;
endmodule 