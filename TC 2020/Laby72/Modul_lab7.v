`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:04:38 04/22/2020 
// Design Name: 
// Module Name:    Modul_lab7 
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
module Modul_lab7(
input [1:0] a,
    input [3:0] d,
    output y
    );
	 
	 reg y;
	 always @(d or a)
	 begin
	 if(a==0) y=d[0];
	 if(a==1) y=d[1];
	 if(a==2) y=d[2];
	 if(a==3) y=d[3];
end

endmodule
