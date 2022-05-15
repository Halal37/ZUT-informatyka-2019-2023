`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:12:20 05/27/2020 
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
module Laby12(input iCLK,
  output oSOUND,
  output rSIG
	);
	  reg rTYM=0;
     reg [22:0] rCNT=0;
    
     always @( posedge iCLK ) begin
        rCNT = rCNT + 1;
        if( rCNT == 6250000) begin
        rCNT = 0;
        rTYM = !rTYM;
        end
    end
 wire [2:0] mTIME [49:0];
    
    //w      
     assign mTIME[0] = 1;
     assign mTIME[1] = 1;
     assign mTIME[2] = 3;
     assign mTIME[3] = 1;
     assign mTIME[4] = 3;
     
     assign mTIME[5] = 3;
     //o
      assign mTIME[6] = 3;
     assign mTIME[7] = 1;
     assign mTIME[8] = 3;
      assign mTIME[9] = 1;
     assign mTIME[10] = 3;
     
     assign mTIME[11] = 3;
     //j
      assign mTIME[12] = 1;
     assign mTIME[13] = 1;
     assign mTIME[14] = 3;
     assign mTIME[15] = 1;
     assign mTIME[16] = 3;
	  assign mTIME[17] = 1;
     assign mTIME[18] = 3;
	  
	  assign mTIME[19] = 3;
     //c
	  assign mTIME[20] = 3;
     assign mTIME[21] = 1;
	  assign mTIME[22] = 1;
     assign mTIME[23] = 1;
	  assign mTIME[24] = 3;
     assign mTIME[25] = 1;
	  assign mTIME[26] = 1;

     assign mTIME[27] = 3;
	  //i
	  assign mTIME[28] = 1;
     assign mTIME[29] = 1;
	  assign mTIME[30] = 1;
	  
	  assign mTIME[31] = 3;
	  //e
	  assign mTIME[32] = 1;
	  
	  assign mTIME[33] = 3;
	  //c
	  assign mTIME[34] = 3;
     assign mTIME[35] = 1;
	  assign mTIME[36] = 1;
     assign mTIME[37] = 1;
	  assign mTIME[38] = 3;
     assign mTIME[39] = 1;
	  assign mTIME[40] = 1;
	  
	  assign mTIME[41] = 3;
	  //h
	  assign mTIME[42] = 1;
     assign mTIME[43] = 1;
	  assign mTIME[44] = 1;
     assign mTIME[45] = 1;
	  assign mTIME[46] = 1;
     assign mTIME[47] = 1;
	  assign mTIME[48] = 1;
	  
     assign mTIME[49] = 7;
	  
	   reg [6:0] rNUMSTAN = 0;
   reg [2:0] rUCNT = 3'b111;
    reg rSIG=1;            
       
    always @(negedge rTYM) begin
        rUCNT = rUCNT + 1;
        if (rUCNT == mTIME[rNUMSTAN]) begin
            rNUMSTAN=rNUMSTAN+1;
            rUCNT=0;
            if (rNUMSTAN==50) rNUMSTAN=0;
            rSIG=!rSIG;
        end
  end
assign oSOUND=rSIG? rCNT[17]:0;
endmodule
