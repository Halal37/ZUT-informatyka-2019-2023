// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby52\Laby5.sch - Wed Apr 08 11:25:11 2020

`timescale 1ns / 1ps

module Laby5_Laby5_sch_tb();

// Inputs
   reg a;
   reg b;
   reg cin;

// Output
   wire cout;
   wire s;

// Bidirs

// Instantiate the UUT
   Laby5 UUT (
		.o_cout(cout), 
		.o_s(s), 
		.i_a(a), 
		.i_b(b), 
		.i_cin(cin)
   );
// Initialize Inputs
       initial begin
		a = 0;
		b = 0;
		cin = 0;
		#10
		a = 0;
		b = 0;
		cin = 1;
		#10
		a = 0;
		b = 1;
		cin = 0;
		#10
		a = 0;
		b = 1;
		cin = 1;
		#10
		a = 1;
		b = 0;
		cin = 0;
		#10
		a = 1;
		b = 0;
		cin = 1;
		#10
		a = 1;
		b = 1;
		cin = 0;
		#10
		a = 1;
		b = 1;
		cin = 1;
   end
endmodule
