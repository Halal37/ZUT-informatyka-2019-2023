// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby61\Laby6.sch - Wed Apr 15 10:29:05 2020

`timescale 1ns / 1ps

module Laby6_Laby6_sch_tb();

// Inputs
   reg d0;
   reg a;
   reg d1;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby6 UUT (
		.i_d0(d0), 
		.o_y(y), 
		.i_a(a), 
		.i_d1(d1)
   );
// Initialize Inputs
       initial begin
		a = 0;
d0 = 0;
d1 = 0;
#10
d0 = 1;
d1 = 0;
#10
d0 = 0;
d1 = 1;
#10
d0 = 1;
d1 = 1;
#10
a = 1;
d0 = 0;
d1 = 0;
#10
d0 = 1;
d1 = 0;
#10
d0 = 0;
d1 = 1;
#10
d0 = 1;
d1 = 1;
   end
endmodule
