// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Lab2\funkcja.sch - Wed Mar 25 10:52:55 2020

`timescale 1ns / 1ps

module funkcja_funkcja_sch_tb();

// Inputs
   reg a;
   reg b;
   reg c;

// Output
   wire yx;

// Bidirs

// Instantiate the UUT
   funkcja UUT (
		.i_a(a), 
		.i_b(b), 
		.i_c(c), 
		.y(yx)
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
