
`define CMD_SUB_RD      2'b00
`define CMD_SUB_WR      2'b01
`define CMD_SUB_BUS     1'b0
`define CMD_SUB_ADDR    2'b10
`define CMD_SUB_SPECIAL 2'b11



`define	RSP_SUB_DATA	2'b00
`define	RSP_SUB_ACK	    2'b01
`define	RSP_SUB_ADDR	2'b10
`define RSP_SUB_SPECIAL 2'b11


`define RSP_WRITE_AKCNOWLEDGEMENT {`RSP_SUB_ACK, 32'h0}
`define RSP_RESET                 {`RSP_SUB_SPECIAL, 3'h0, 29'h00}
`define RSP_BUS_ERROR             {`RSP_SUB_SPECIAL, 3'h1, 29'h00}


module WB_master (
    input             i_clk, i_reset,
	input 			  Usr_button,
	output reg [7:0]  o_LEDS,
    //}}}
    //prikazy od receivera(Uart Decoder)
    //{{{
    input             i_cmd_stb,
    input  [33:0]      i_cmd_word,
    output reg        o_cmd_busy,
    //}}}
    //return command channel
    //{{{
    output reg         o_rsp_stb,   /**/
    output reg [33:0]  o_rsp_word,	/* Upravena data ze slave(i_wb_dat)*/
    //}}}
    // Wishbone output 
    //{{{
    output reg         o_wb_cyc = 0,    /* The cycle output, when assterted, indicates that a valid bus cycle is in progress*/
    output reg         o_wb_stb = 0,    /* Strobe output - indicates a valid data transfer cycle*/
    output reg         o_wb_we = 0,     /* Write enable line - indicates whether the current local bus cycle is a READ=0 or WRITE=1 cycle*/
    output reg [29:0]  o_wb_addr = 0,
    output reg [31:0]  o_wb_data = 0,
    output wire [3:0]  o_wb_sel,    /* Adresa slave */
    //}}}
    // Wishbone inputs 
    //{{{
    input wire         i_wb_stall,  /**/
    input wire         i_wb_ack,    /* Acknowledgement from the slave*/
    input wire         i_wb_err,
    input wire [31:0]  i_wb_data	/* Data ze slave*/
);
    
wire cmd_addr;
wire cmd_read;
wire cmd_write;

	
assign cmd_addr  = i_cmd_stb && (i_cmd_word[33:32] == `CMD_SUB_ADDR);
assign cmd_read  = i_cmd_stb && (i_cmd_word[33:32] == `CMD_SUB_RD);
assign cmd_write = i_cmd_stb && (i_cmd_word[33:32] == `CMD_SUB_WR);


always @(posedge i_clk) begin
	
	if(i_reset) begin
		o_wb_addr <= 0;
		o_wb_data <= 0;
	end else begin


		if(cmd_addr) begin
			o_wb_addr[4:0] <= i_cmd_word[4:0];
			o_wb_stb <= 0;
			o_wb_cyc <= 0;
		end else if(cmd_read) begin
			o_wb_stb <= 1;
			o_wb_cyc <= 1;
			o_wb_we <= 0;
		end else if(cmd_write) begin
			o_wb_stb <= 1;
			o_wb_cyc <= 1;
			o_wb_data[4:0] <= i_cmd_word[4:0];
			o_wb_we <= 1;
		end else begin
			o_wb_stb <= 0;
			o_wb_cyc <= 0;
		end
	
	end

end





always @(posedge i_clk)begin


end

endmodule