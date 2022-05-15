// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby4bpod\Laby4bpod.sch - Sun Apr 05 22:33:44 2020

`timescale 1ns / 1ps

module Laby4bpod_Laby4bpod_sch_tb();

// Inputs
   reg c;
   reg b;
   reg d;
   reg a;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby4bpod UUT (
		.o_y(y), 
		.i_c(c), 
		.i_b(b), 
		.i_d(d), 
		.i_a(a)
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
