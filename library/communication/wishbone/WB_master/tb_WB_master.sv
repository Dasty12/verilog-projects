`timescale 1 ns/1 ns  // time-unit = 1 ns, precision = 10 ps

module tb_WB_master;


reg clk = 0;
reg reset = 0;
wire [7:0] o_LEDS;
reg i_cmd_stb = 0;
reg [33:0] i_cmd_word;
wire o_cmd_busy;
wire o_rsp_stb;
wire [33:0] o_rsp_word;
wire o_wb_cyc;
wire o_wb_stb;
wire o_wb_we;
wire [29:0]o_wb_addr;
wire [31:0] o_wb_data;
wire [31:0] o_wb_data_mas;
wire [3:0]o_wb_sel;

reg i_wb_stall;
reg i_wb_ack;
reg i_wb_err;
reg [31:0]i_wb_data;


always #5 clk = !clk;

reg[15:0] cnt = 0;
reg[7:0] cnt_div = 0;

WB_master dut(
    .i_clk(clk),
    .i_reset(reset),
    .o_LEDS(o_LEDS),
    .i_cmd_stb(i_cmd_stb),
    .i_cmd_word(i_cmd_word),
    .o_cmd_busy(o_cmd_busy),
    .o_rsp_stb(o_rsp_stb),
    .o_rsp_word(o_rsp_word),
    .o_wb_cyc(o_wb_cyc),
    .o_wb_stb(o_wb_stb),
    .o_wb_we(o_wb_we),
    .o_wb_addr(o_wb_addr),
    .o_wb_data(o_wb_data_mas),
    .o_wb_sel(o_wb_sel),
    .i_wb_stall(o_wb_stall),
    .i_wb_ack(o_wb_ack),
    .i_wb_err(o_wb_err),
    .i_wb_data(o_wb_data));


WB_slave dut_slave(.i_clk(clk),
					.i_rst(reset),
					.i_wb_cyc(o_wb_cyc),
					.i_wb_stb(o_wb_stb),
					.i_wb_we(o_wb_we),
					.i_wb_addr(o_wb_addr),
					.i_wb_data(o_wb_data_mas),
					.i_wb_sel(o_wb_sel),
					.o_wb_stall(o_wb_stall),
					.o_wb_ack(o_wb_ack),
					.o_wb_err(o_wb_err),
					.o_wb_data(o_wb_data),
					.o_LEDS(o_LEDS));

reg[33:0] data_in[0:4];
reg[2:0]  data_cnt = 0;

initial begin
	data_in[0] = 0;
	data_in[1] = 0;
	data_in[2] = 0;
	data_in[3] = 0;
	
	data_in[0][33] = 1;	//address 1
	data_in[0][0]  = 1;
	
	data_in[1][32] = 1;	//write 1
	data_in[1][3:0]  = 5;
	
	data_in[2][33] = 1;//address 1
	data_in[2][0]  = 1;
	
	data_in[3][32] = 0; //read 
	data_in[3][0]  = 0;

	
end


always @(posedge clk) begin

    if(cnt < 32767 - 1)    
        cnt <= cnt + 1;
    else
        $finish;
		
	if(cnt < 5)
		reset <= 1;
	else
		reset <= 0;
		
	if(cnt_div < 10) begin
		cnt_div <= cnt_div + 1;
		i_cmd_stb <= 0;
	end else begin
		cnt_div <= 0;
		if(data_cnt < 3) 
			data_cnt <= data_cnt + 1;
		else
			data_cnt <= 0;
		i_cmd_word <= data_in[data_cnt];
		i_cmd_stb <= 1;
	end
end




initial
 begin
    $dumpfile("WaveIcarus.vcd");
    $dumpvars(0,tb_WB_master);
 end

endmodule