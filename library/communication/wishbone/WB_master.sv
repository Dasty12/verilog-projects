
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
    input [33:0]      i_cmd_word,
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
    output reg         o_wb_stb = 0,    /* Strobe output -indicates a valid data transfer cycle*/
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
    

// Local declarations
// {{{
reg newaddr = 1'b0;
reg inc = 0;
wire i_cmd_addr, i_cmd_wr, i_cmd_rd, i_cmd_bus;

reg bude_inc = 1'b1;

reg [33:0] i_cmd_word_old = 0;

reg  i_cmd_stb_old = 0;


always @(posedge i_clk) begin


	if(i_cmd_stb) begin	//tady to krasne sedi
		o_LEDS[1:0] <= i_cmd_word[33:32];	
		
		i_cmd_stb_old <= 1;
	end
	else if(i_cmd_stb_old) begin
		o_LEDS[7:2] <= i_cmd_word[5:0];
	end


	if(Usr_button) begin	
		
	end else begin	//tlacitko je zmacknute
		o_LEDS <= 0;
	end
	

end

always @(posedge i_clk) begin
	i_cmd_word_old <= i_cmd_word;

end



//}}}
// Decode our input commands

assign i_cmd_addr = (i_cmd_stb) && (i_cmd_word_old[33:32] == `CMD_SUB_ADDR);  // Set an address, if bit 31 is set, we will add this value to the current bus address.
                                                                          // If bit 30 is set, the address will be incremented upon each bus access
assign i_cmd_rd   = (i_cmd_stb) && (i_cmd_word_old[33:32] == `CMD_SUB_RD);    // Read request, ignore the rest of the 32 bits,
assign i_cmd_wr   = (i_cmd_stb) && (i_cmd_word_old[33:32] == `CMD_SUB_WR);    // Write request, the 32 bit data contains the word to be written
assign i_cmd_bus  = (i_cmd_stb) && (i_cmd_word_old[33]    == `CMD_SUB_BUS);   // Signalizuje W/R


//initial o_wb_cyc = 1'b0;
initial o_wb_stb = 1'b0;


always @(posedge i_clk) begin
    if((i_reset) || ((i_wb_err) && (o_wb_cyc))) begin
        o_wb_cyc <= 1'b0;
        o_wb_stb <= 1'b0;
    end else if(o_wb_stb) begin
        if(!i_wb_stall)
            o_wb_stb <= 1'b0;
		if((!i_wb_stall) && (i_wb_ack))
			o_wb_cyc <= 1'b0;

    end else if(o_wb_cyc) begin //BUS WAIT
        if(i_wb_ack)
            o_wb_cyc <= 1'b0;
    end else begin  //IDLE STATE
        if(i_cmd_bus) begin
                // we have been asked to start a bus cycle from our
                // command word, either RD or WR
            o_wb_cyc <= 1'b1;
            o_wb_stb <= 1'b1;
        end
    end
end

//whether or not we are too busy to accept anything else from the command port.
//This will be changed, if we want accept multiple write command per bus cycle.
assign o_cmd_busy = o_wb_cyc;


always @(posedge i_clk) begin
    if(!o_wb_cyc) begin
        o_wb_we <= (i_cmd_wr);
    end
end


//intial newaddr = 1'b0;

always @(posedge i_clk) begin
    if((i_cmd_addr) && (!o_cmd_busy)) begin

        o_wb_addr <= i_cmd_word[29:0];
  end

    newaddr <= ((!i_reset) && (i_cmd_addr) && (!o_cmd_busy));
end

always @(posedge i_clk) begin
    if((!o_wb_stb) || (!i_wb_stall))//pokud neni request
        o_wb_data <= i_cmd_word_old[31:0];
end


assign o_wb_sel = 4'hf;

initial o_rsp_stb = 1'b0;
initial o_rsp_word = `RSP_RESET;

always @(posedge i_clk) begin
    if(i_reset) begin
        o_rsp_stb  <= 1'b1;
        o_rsp_word <= `RSP_BUS_ERROR;
    end else if(i_wb_err) begin
        o_rsp_stb <= 1'b1;
        o_rsp_word <= `RSP_BUS_ERROR;
    end else if(o_wb_cyc) begin
        o_rsp_stb <= (i_wb_ack);

        if(o_wb_we) begin
            o_rsp_word <= `RSP_WRITE_AKCNOWLEDGEMENT;
        end else begin
            o_rsp_word <= {`RSP_SUB_DATA, i_wb_data };
        end 
    end else begin

        //jinak jsem v IDLE rezimu

        //echo any new addres back up the command chain

        o_rsp_stb <= newaddr;
		o_rsp_word <= {{1{2'b00}},`RSP_SUB_ADDR,o_wb_addr};
      //  o_rsp_word <= {`RSP_SUB_ADDR, {(30 - 30){1'b0}}, o_wb_addr, 1'b0, inc};    
    end
end

endmodule