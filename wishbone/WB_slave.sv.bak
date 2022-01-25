module WB_slave (
    input             i_clk,
    input             i_wb_cyc,
    input             i_wb_stb,
    input             i_wb_we,
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


reg[15:0] memory[9];

initial memory[0] = 15'h0001;
initial memory[1] = 15'h0010;
initial memory[2] = 15'h0020;
initial memory[3] = 15'h0040;
initial memory[4] = 15'h0080;
initial memory[5] = 15'h0090;
initial memory[6] = 15'h00A0;
initial memory[7] = 15'h00B0;
initial memory[8] = 15'h00C0;



always @(posedge i_clk) begin
    if((i_wb_cyc) && (i_wb_stb)) begin

        o_wb_ack <= 1;
        if(i_wb_we) begin
			LEDS <= i_wb_data[7:0];
            o_LEDS <= LEDS;
        end else begin
			o_wb_data[31:16] <= 16'h0;
			o_wb_data[15:0] <= memory[i_wb_addr[2:0]];
		end
		
		o_wb_stall <= 0;

    end else begin
        o_wb_ack <= 0;
		o_wb_stall <= 1;
    end

end

/*
always @(posedge i_clk) begin
   /* if(i_wb_addr == 1) begin
        
		//o_wb_data <= i_wb_data;
    end else begin
       LEDS <= 8'b11111111;
	   
    end



end