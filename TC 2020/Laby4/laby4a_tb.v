// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby4\Laby4a.sch - Fri Apr 03 08:52:50 2020

`timescale 1ns / 1ps

module Laby4a_Laby4a_sch_tb();

// Inputs
   reg a;
   reg b;
   reg c;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby4a UUT (
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
