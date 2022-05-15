////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: Laby4a_synthesis.v
// /___/   /\     Timestamp: Fri Apr 03 09:32:50 2020
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim Laby4a.ngc Laby4a_synthesis.v 
// Device	: xc3s500e-4-fg320
// Input file	: Laby4a.ngc
// Output file	: C:\Users\JaSzw\OneDrive\Pulpit\ISE\Laby4\netgen\synthesis\Laby4a_synthesis.v
// # of Modules	: 1
// Design Name	: Laby4a
// Xilinx        : C:\Xilinx\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module Laby4a (
  o_y, i_a, i_b, i_c
);
  output o_y;
  input i_a;
  input i_b;
  input i_c;
  wire XLXN_1;
  wire XLXN_15;
  wire XLXN_16;
  wire XLXN_17;
  wire XLXN_24;
  wire XLXN_25;
  wire XLXN_28;
  wire XLXN_29;
  wire XLXN_4;
  wire XLXN_5;
  wire XLXN_6;
  wire i_a_IBUF_12;
  wire i_b_IBUF_14;
  wire i_c_IBUF_16;
  wire o_y_OBUF_18;
  OR2   XLXI_1 (
    .I0(i_b_IBUF_14),
    .I1(i_a_IBUF_12),
    .O(XLXN_5)
  );
  OR2   XLXI_2 (
    .I0(XLXN_29),
    .I1(XLXN_5),
    .O(XLXN_16)
  );
  OR2   XLXI_3 (
    .I0(i_c_IBUF_16),
    .I1(i_a_IBUF_12),
    .O(XLXN_6)
  );
  OR2   XLXI_4 (
    .I0(XLXN_24),
    .I1(XLXN_6),
    .O(XLXN_17)
  );
  OR2   XLXI_5 (
    .I0(i_b_IBUF_14),
    .I1(XLXN_28),
    .O(XLXN_15)
  );
  OR2   XLXI_6 (
    .I0(XLXN_25),
    .I1(XLXN_15),
    .O(XLXN_4)
  );
  AND2   XLXI_7 (
    .I0(XLXN_17),
    .I1(XLXN_16),
    .O(XLXN_1)
  );
  AND2   XLXI_8 (
    .I0(XLXN_4),
    .I1(XLXN_1),
    .O(o_y_OBUF_18)
  );
  INV   XLXI_9 (
    .I(i_c_IBUF_16),
    .O(XLXN_25)
  );
  INV   XLXI_10 (
    .I(i_c_IBUF_16),
    .O(XLXN_29)
  );
  INV   XLXI_13 (
    .I(i_b_IBUF_14),
    .O(XLXN_24)
  );
  INV   XLXI_14 (
    .I(i_a_IBUF_12),
    .O(XLXN_28)
  );
  IBUF   i_a_IBUF (
    .I(i_a),
    .O(i_a_IBUF_12)
  );
  IBUF   i_b_IBUF (
    .I(i_b),
    .O(i_b_IBUF_14)
  );
  IBUF   i_c_IBUF (
    .I(i_c),
    .O(i_c_IBUF_16)
  );
  OBUF   o_y_OBUF (
    .I(o_y_OBUF_18),
    .O(o_y)
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

