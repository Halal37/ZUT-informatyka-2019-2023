// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby63\Laby6.sch - Wed Apr 15 11:23:00 2020

`timescale 1ns / 1ps

module Laby6_Laby6_sch_tb();

// Inputs
   reg b;
   reg a;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby6 UUT (
		.o_y(y), 
		.i_b(b), 
		.i_a(a)
   );
// Initialize Inputs
       initial begin
		 a=0;
		 b=0;
		#10
		b = 0;
		a = 1;
		#10
		b = 1;
		a = 0;
		#10
		a=1;
		b=1;
   end
endmodule
