// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby53\Laby5.sch - Wed Apr 08 15:15:07 2020

`timescale 1ns / 1ps

module Laby5_Laby5_sch_tb();

// Inputs
   reg vin;
   reg b;
   reg a;

// Output
   wire vout;
   wire d;

// Bidirs

// Instantiate the UUT
   Laby5 UUT (
		.o_vout(vout), 
		.o_d(d), 
		.i_vin(vin), 
		.i_b(b), 
		.i_a(a)
   );
// Initialize Inputs
       initial begin
		vin = 0;
		b = 0;
		a = 0;
		#10
		vin = 1;
		b = 0;
		a = 0;
		#10
		vin = 0;
		b = 1;
		a = 0;
		#10
		vin = 1;
		b = 1;
		a = 0;
		#10
		vin = 0;
		b = 0;
		a = 1;
		#10
		vin = 1;
		b = 0;
		a = 1;
		#10
		vin = 0;
		b = 1;
		a = 1;
		#10
		vin = 1;
		b = 1;
		a = 1;
   end
endmodule
