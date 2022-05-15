// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby5nowy1\Laby5.sch - Wed Apr 08 11:40:50 2020

`timescale 1ns / 1ps

module Laby5_Laby5_sch_tb();

// Inputs
   reg b;
   reg a;

// Output
   wire c;
   wire s;

// Bidirs

// Instantiate the UUT
   Laby5 UUT (
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
   end
endmodule
