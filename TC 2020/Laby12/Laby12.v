`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:49:46 05/27/2020 
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
 wire [2:0] mTIME [17:0];
    
         
     assign mTIME[0] = 1;
     assign mTIME[1] = 1;
     assign mTIME[2] = 1;
     assign mTIME[3] = 1;
     assign mTIME[4] = 1;
     
     assign mTIME[5] = 3;
     
      assign mTIME[6] = 3;
     assign mTIME[7] = 1;
     assign mTIME[8] = 3;
      assign mTIME[9] = 1;
     assign mTIME[10] = 3;
     
     assign mTIME[11] = 3;
     
      assign mTIME[12] = 1;
     assign mTIME[13] = 1;
     assign mTIME[14] = 1;
     assign mTIME[15] = 1;
     assign mTIME[16] = 1;
     
     assign mTIME[17] = 7;
	  
	   reg [5:0] rNUMSTAN = 0;
   reg [2:0] rUCNT = 3'b111;
    reg rSIG=1;            
       
    always @(negedge rTYM) begin
        rUCNT = rUCNT + 1;
        if (rUCNT == mTIME[rNUMSTAN]) begin
            rNUMSTAN=rNUMSTAN+1;
            rUCNT=0;
            if (rNUMSTAN==18) rNUMSTAN=0;
            rSIG=!rSIG;
        end
  end
assign oSOUND=rSIG? rCNT[17]:0;
endmodule
