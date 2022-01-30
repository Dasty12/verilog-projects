module sdram(
	input         i_clk,
	input         rst,
	
	//
	output        sdram_clk,	// clock input
	output        sdram_cle,    // clock enable
	output 		  sdram_cs,     // chip select
	output 		  sdram_cas,    // Column Address Strobe
	output        sdram_ras,	// Row Address Strobe
	output 		  sdram_we,		// Write Enable
	output        sdram_dqm,	// Lower/Upper Data Mask
	output  [1:0] sdram_ba,		// bank address //
 	output [12:0] sdram_a,	    // address //
	inout  [15:0] sdram_dq,     // data //
	
	
	// ==== User interface ====// 
	//bude se chovat jako wb slave
	input 	       i_wb_stb,
	output         o_wb_stall,
	input  [15:0]  i_wb_data,
	input  [11:0]  i_wb_addr,
	output [15:0]  o_wb_data,
	
	
);


localparam s_INIT   = 0;
localparam s_IDLE   = 1;
localparam s_ACTIVE = 2;
localparam s_READ   = 2;



reg [3:0] state = s_INIT;



endmodule