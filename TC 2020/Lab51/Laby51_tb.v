// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Lab51\Laby51.sch - Wed Apr 08 10:27:34 2020

`timescale 1ns / 1ps

module Laby51_Laby51_sch_tb();

// Inputs
   reg b;
   reg a;

// Output
   wire c;
   wire s;

// Bidirs

// Instantiate the UUT
   Laby51 UUT (
		.o_c(c), 
		.o_s(s), 
		.i_b(b), 
		.i_a(a)
   );
// Initialize Inputs
       initial begin
      b = 0;
		a = 0;
		#10
		b = 1;
		a = 0;
		#10
		b = 0;
		a = 1;
		#10
		b = 1;
		a = 1;
     end		`
endmodule
