// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\zzzz2lab2\test.sch - Wed Mar 25 11:39:46 2020

`timescale 1ns / 1ps

module test_test_sch_tb();

// Inputs
   reg a;
   reg b;
   reg c;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   test UUT (
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
