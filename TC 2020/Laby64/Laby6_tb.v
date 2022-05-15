// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby64\Laby6.sch - Thu Apr 16 15:16:47 2020

`timescale 1ns / 1ps

module Laby6_Laby6_sch_tb();

// Inputs
   reg a;
   reg b;
   reg c;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby6 UUT (
		.i_a(a), 
		.i_b(b), 
		.i_c(c), 
		.o_y(y)
   );
// Initialize Inputs
       initial begin
		a = 0;
		b = 0;
		c = 0;
		#10
		a = 0;
		b = 0;
		c = 1;
		#10
		a = 0;
		b = 1;
		c = 0;
		#10
		a = 0;
		b = 1;
		c = 1;
		#10
		a = 1;
		b = 0;
		c = 0;
		#10
		a = 1;
		b = 0;
		c = 1;
		#10
		a = 1;
		b = 1;
		c = 0;
		#10
		a = 1;
		b = 1;
		c = 1;
   end
endmodule
