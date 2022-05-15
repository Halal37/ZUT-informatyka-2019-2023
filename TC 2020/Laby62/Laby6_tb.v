// Verilog test fixture created from schematic C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby62\Lab6.sch - Wed Apr 15 10:55:29 2020

`timescale 1ns / 1ps

module Lab6_Lab6_sch_tb();

// Inputs
   reg d0;
   reg d1;
   reg d2;
   reg d3;
   reg a1;
   reg a0;

// Output
   wire y;

// Bidirs

// Instantiate the UUT
   Lab6 UUT (
		.o_y(y), 
		.i_d0(d0), 
		.i_d1(d1), 
		.i_d2(d2), 
		.i_d3(d3), 
		.i_a1(a1), 
		.i_a0(a0)
   );
// Initialize Inputs
       initial begin
		a1 = 0;
		a0 = 0;
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		a1 = 0;
		a0 = 1;
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 1;
#10
		a1 = 1;
		a0 = 0;
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		a1 = 1;
		a0 = 1;
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 0;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 0;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 0;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 0;
		d1 = 1;
		d2 = 1;
		d3 = 1;
		#10
		d0 = 1;
		d1 = 1;
		d2 = 1;
		d3 = 1;
   end
endmodule