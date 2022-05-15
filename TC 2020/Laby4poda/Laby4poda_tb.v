// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby4poda\Laby4poda.sch - Sun Apr 05 21:40:07 2020

`timescale 1ns / 1ps

module Laby4poda_Laby4poda_sch_tb();

// Inputs
   reg b;
   reg c;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Laby4poda UUT (
		.o_y(y), 
		.i_b(b), 
		.i_c(c)
   );
// Initialize Inputs
       initial begin
		b = 0;
		c = 0;
		#10
		b = 0;
		c = 1;
		#10
		b = 1;
		c = 0;
		#10
		b = 1;
		c = 1;
 end
endmodule
