module WB_slave (
    input             i_clk,
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


reg[15:0] memory[0:7] =  '{ 0, 1, 2, 3, 4, 5, 6, 7};
/*
initial memory[0] = 15'h0001;
initial memory[1] = 15'h0012;
initial memory[2] = 15'h0023;
initial memory[3] = 15'h0044;
initial memory[4] = 15'h0085;
initial memory[5] = 15'h0096;
initial memory[6] = 15'h00A7;
initial memory[7] = 15'h00B8;
initial memory[8] = 15'h00C9;

always @(posedge i_clk) begin
	memory[0] = 15'h0001;
	memory[1] = 15'h0012;
	memory[2] = 15'h0023;
	memory[3] = 15'h0044;
	memory[4] = 15'h0085;
	memory[5] = 15'h0096;
	memory[6] = 15'h00A7;
	memory[7] = 15'h00B8;
	memory[8] = 15'h00C9;

end 
*/


reg [15:0] nevim;


always @(posedge i_clk) begin

	//memory[4] <= 15'h0085;


    if((i_wb_cyc) && (i_wb_stb)) begin
	//	o_LEDS <= o_wb_data[7:0];
        o_wb_ack <= 1;
        if(i_wb_we) begin
			//LEDS <= i_wb_data[7:0];
            //o_LEDS <= LEDS;
			memory[i_wb_addr[2:0]] <= i_wb_data[15:0];
			o_LEDS[7:0] <= 2;
        end else begin
			o_wb_data[31:16] <= 16'h0;
			o_wb_data[15:0] <= memory[i_wb_addr[2:0]];
			o_LEDS[7:0] <= 1;
			
		end
		
		o_wb_stall <= 0;

    end else begin
        o_wb_ack <= 0;
		o_wb_stall <= 1;
    end
	
	
	nevim <= memory[4];
	
//	o_LEDS[7:0] <=  i_wb_addr[7:0];

end
endmodule
