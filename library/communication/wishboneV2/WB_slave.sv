module WB_slave (
    input             i_clk,
	input 			  i_rst,
    input             i_wb_cyc, /* WB_master/o_wb_cyc - the cycle output, when asserted indicates that a valid bus cycle is in progress*/
    input             i_wb_stb,	/* WB_master/o_wb_stb - indicates a valid data transfer cycle*/
    input             i_wb_we,  /* WB_master/o_wb_we  - write enable line - indicates if is READ=0 or WRITE=1 */ 
    input     [29:0]  i_wb_addr,
    input     [31:0]  i_wb_data,
    input      [3:0]  i_wb_sel,

    output reg        o_wb_stall,
    output reg        o_wb_ack,
    output reg        o_wb_err,
    output reg [31:0] o_wb_data,
    output reg [7:0]  o_LEDS
);

initial o_wb_stall = 1'b0;


reg [7:0] LEDS = 0;

initial o_wb_err = 0;

reg[15:0] memory[0:7];// =  '{ 0, 1, 2, 3, 4, 5, 6, 7};


always @(posedge i_clk) begin
	if(i_rst) begin
		memory[0] <= 0;
		memory[1] <= 1;
		memory[2] <= 2;
		memory[3] <= 3;
		memory[4] <= 4;
		memory[5] <= 5;
		memory[6] <= 6;
		memory[7] <= 7;
		
	end else begin
		if((i_wb_cyc) && (i_wb_stb)) begin
			o_wb_ack <= 1;
			if(i_wb_we) begin	//pri požadavku na zápis
				memory[i_wb_addr[15:0]] <= i_wb_data[15:0];
				o_LEDS[5:3] <= i_wb_addr[2:0];
			end else begin		// při požadavku na čtení
				o_wb_data[31:16] <= 16'h0;
				o_wb_data[15:0] <= memory[i_wb_addr[15:0]];
				o_LEDS[2:0] <= i_wb_addr[2:0];
			end
			
			o_wb_stall <= 0;

		end else begin
			o_wb_ack <= 0;
			o_wb_stall <= 1;
		end
	end
	
end



reg [7:0] ahoj;

always @(posedge i_clk)

	ahoj <= memory[1][7:0];

endmodule
