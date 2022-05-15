// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby4b\Laby4b.sch - Sun Apr 05 22:16:16 2020

`timescale 1ns / 1ps

module Laby4b_Laby4b_sch_tb();

// Inputs
   reg a;
   reg b;
   reg c;
   reg d;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby4b UUT (
		.i_a(a), 
		.o_y(y), 
		.i_b(b), 
		.i_c(c), 
		.i_d(d)
   );
// Initialize Inputs
       initial begin
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		#10
		a = 0;
		b = 0;
		c = 0;
		d = 1;
		#10
		a = 0;
		b = 0;
		c = 1;
		d = 0;
		#10
		a = 0;
		b = 0;
		c = 1;
		d = 1;
		#10
		a = 0;
		b = 1;
		c = 0;
		d = 0;
		#10
		a = 0;
		b = 1;
		c = 0;
		d = 1;
		#10
		a = 0;
		b = 1;
		c = 1;
		d = 0;
		#10
		a = 0;
		b = 1;
		c = 1;
		d = 1;
		#10
		a = 1;
		b = 0;
		c = 0;
		d = 0;
		#10
		a = 1;
		b = 0;
		c = 0;
		d = 1;
		#10
		a = 1;
		b = 0;
		c = 1;
		d = 0;
		#10
		a = 1;
		b = 0;
		c = 1;
		d = 1;
		#10
		a = 1;
		b = 1;
		c = 0;
		d = 0;
		#10
		a = 1;
		b = 1;
		c = 0;
		d = 1;
		#10
		a = 1;
		b = 1;
		c = 1;
		d = 0;
		#10
		a = 1;
		b = 1;
		c = 1;
		d = 1;
   end
endmodule
