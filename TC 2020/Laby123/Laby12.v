`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:32:30 06/18/2020 
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
wire [8:0] mTIME [67:0];
assign mTIME[0] = 6;
assign mTIME[1] = 2;
assign mTIME[2] = 6;
assign mTIME[3] = 2;
assign mTIME[4]=  6;
assign mTIME[5]=  2;
//
assign mTIME[6]=  6;
assign mTIME[7]=  2;
assign mTIME[8]=  6;
assign mTIME[9]=  2;
assign mTIME[10]=  6;
assign mTIME[11]=  2;
//
assign mTIME[12]=  6;
assign mTIME[13]=  6;
assign mTIME[14]=  2;
assign mTIME[15]=  12;
assign mTIME[16]=  2;
//
assign mTIME[17]=  6;
assign mTIME[18]=  2;
assign mTIME[19]=  6;
assign mTIME[20]=  2;
assign mTIME[21]=  6;
assign mTIME[22]=  2;
//
assign mTIME[23]=  6;
assign mTIME[24]=  2;
assign mTIME[25]=  6;
assign mTIME[26]=  2;
assign mTIME[27]=  6;
assign mTIME[28]=  2;
//
assign mTIME[29]=  6;
assign mTIME[30]=  6;
assign mTIME[31]=  2;
assign mTIME[32]=  12;
assign mTIME[33]=  2;
//
assign mTIME[34]=  6;
assign mTIME[35]=  2;
assign mTIME[36]=  6;
assign mTIME[37]=  2;
assign mTIME[38]=  6;
assign mTIME[39]=  2;
//
assign mTIME[40]=  6;
assign mTIME[41]=  2;
assign mTIME[42]=  6;
assign mTIME[43]=  2;
assign mTIME[44]=  6;
assign mTIME[45]=  2;
//
assign mTIME[46]=  6;
assign mTIME[47]=  6;
assign mTIME[48]=  2;
assign mTIME[49]=  12;
assign mTIME[50]=  2;
//
assign mTIME[51]=  6;
assign mTIME[52]=  2;
assign mTIME[53]=  6;
assign mTIME[54]=  2;
assign mTIME[55]=  6;
assign mTIME[56]=  2;
//
assign mTIME[57]=  6;
assign mTIME[58]=  2;
assign mTIME[59]=  6;
assign mTIME[60]=  2;
assign mTIME[61]=  6;
assign mTIME[62]=  2;
//
assign mTIME[63]=  6;
assign mTIME[64]=  6;
assign mTIME[65]=  2;
assign mTIME[66]=  12;
assign mTIME[67]=  2;
//
//Pamiec do zapisania czêstotliwoœci dzwieku w stanach
wire [20:0] mFREQUENCY [67:0];
assign mFREQUENCY[0] = 31_888;
assign mFREQUENCY[1] = 0;
assign mFREQUENCY[2] = 37_919;
assign mFREQUENCY[3] = 0;
assign mFREQUENCY[4] = 37_919;
assign mFREQUENCY[5] = 0;
//
assign mFREQUENCY[6] = 35_791;
assign mFREQUENCY[7] = 0;
assign mFREQUENCY[8] = 42_568;
assign mFREQUENCY[9] = 0;
assign mFREQUENCY[10] = 42_568;
assign mFREQUENCY[11] = 0;
//
assign mFREQUENCY[12] = 47_774;
assign mFREQUENCY[13] = 37_919;
assign mFREQUENCY[14] = 0;
assign mFREQUENCY[15] = 31_888;
assign mFREQUENCY[16] = 0;
//
assign mFREQUENCY[17] = 31_888;
assign mFREQUENCY[18] = 0;
assign mFREQUENCY[19] = 37_919;
assign mFREQUENCY[20] = 0;
assign mFREQUENCY[21] = 37_919;
assign mFREQUENCY[22] = 0;
//
assign mFREQUENCY[23] = 35_791;
assign mFREQUENCY[24] = 0;
assign mFREQUENCY[25] = 42_568;
assign mFREQUENCY[26] = 0;
assign mFREQUENCY[27] = 42_568;
assign mFREQUENCY[28] = 0;
//
assign mFREQUENCY[29] = 47_774;
assign mFREQUENCY[30] = 37_919;
assign mFREQUENCY[31] = 0;
assign mFREQUENCY[32] = 47_774;
assign mFREQUENCY[33] = 0;
//
assign mFREQUENCY[34] = 47_774;
assign mFREQUENCY[35] = 0;
assign mFREQUENCY[36] = 37_919;
assign mFREQUENCY[37] = 0;
assign mFREQUENCY[38] = 37_919;
assign mFREQUENCY[39] = 0;
//
assign mFREQUENCY[40] = 35_791;
assign mFREQUENCY[41] = 0;
assign mFREQUENCY[42] = 42_568;
assign mFREQUENCY[43] = 0;
assign mFREQUENCY[44] = 42_568;
assign mFREQUENCY[45] = 0;
//
assign mFREQUENCY[46] = 47_774;
assign mFREQUENCY[47] = 37_791;
assign mFREQUENCY[48] = 0;
assign mFREQUENCY[49] = 31_888;
assign mFREQUENCY[50] = 0;
//
assign mFREQUENCY[51] = 31_888;
assign mFREQUENCY[52] = 0;
assign mFREQUENCY[53] = 37_919;
assign mFREQUENCY[54] = 0;
assign mFREQUENCY[55] = 37_919;
assign mFREQUENCY[56] = 0;
//
assign mFREQUENCY[57] = 35_791;
assign mFREQUENCY[58] = 0;
assign mFREQUENCY[59] = 42_568;
assign mFREQUENCY[60] = 0;
assign mFREQUENCY[61] = 42_568;
assign mFREQUENCY[62] = 0;
//
assign mFREQUENCY[63] = 47_774;
assign mFREQUENCY[64] = 35_791;
assign mFREQUENCY[65] = 0;
assign mFREQUENCY[65] = 47_774;
assign mFREQUENCY[67] = 0;
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
reg [8:0] rNUMSTAN = 0;
reg [3:0] rUCNT = 4'b0000;
reg rSIG=1;
always @(negedge rTYM) begin
rUCNT = rUCNT + 1;
if (rUCNT >= mTIME[rNUMSTAN]) begin
rNUMSTAN=rNUMSTAN+1;
rUCNT=0;
rSIG=!rSIG;
if (rNUMSTAN>=68) rNUMSTAN=0;
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