`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:21:33 05/13/2020 
// Design Name: 
// Module Name:    LAby10 
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
module LAby10(output oSOUND,
input iCLK
    );
	 reg [23:0]cnt=0;
	 always@(posedge iCLK)cnt=cnt+1;
	 assign oSOUND=cnt[23]?0:cnt[17];


endmodule
