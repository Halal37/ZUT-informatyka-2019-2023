// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby54\Laby5.sch - Wed Apr 08 15:30:16 2020

`timescale 1ns / 1ps

module Laby5_Laby5_sch_tb();

// Inputs
   reg b;
   reg a;

// Output
   wire yamb;
   wire yarb;
   wire ya_wieksze_b;

// Bidirs

// Instantiate the UUT
   Laby5 UUT (
		.i_b(b), 
		.o_yamb(yamb), 
		.o_yarb(yarb), 
		.o_ya_wieksze_b(ya_wieksze_b), 
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
