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

wire o_TxStart;
reg i_TxBusy = 0;
always #5 clk = !clk;

reg[18:0] cnt = 0;
reg[7:0] cnt_div = 0;

wire [7:0]out_char;


reg Usr_button = 0;


`ifdef OPT_SIM 
	parameter KBAUD = 14'd1041; 
`else
	parameter KBAUD = 14'd10416; 
`endif


reg IO_UART_RX = 1;
wire IO_UART_TX;

reg[15:0] tt = 0;

wishbone_top dut(.i_clk_12Mhz(clk),
				 .Usr_button(Usr_button),
				 .IO_UART_RX(IO_UART_RX),
				 .IO_UART_TX(IO_UART_TX),
				 .o_LEDS(o_LEDS));

reg[33:0] data_in[0:4];
reg[2:0]  data_cnt = 0;


reg[7:0] data_RX_arr[0:3];

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
	
	
	data_RX_arr[0]  <= 65;
	data_RX_arr[1]  <= 49;
	data_RX_arr[2]  <= 87;
	data_RX_arr[3]  <= 49;

	tt <= KBAUD;
end

`ifdef OPT_SIM_WBMASTER
always @(posedge clk) begin
	
		
	if(cnt_div < 100) begin
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
`else


reg[14:0] baud_cnt = 0;
reg[3:0] baud_BitIndex = 0;
reg[3:0] baud_DataIndex = 0;
always @(posedge clk) begin
	if(baud_cnt < KBAUD) 
		baud_cnt <= baud_cnt + 1;
	else begin
		baud_cnt <= 0;
		if(baud_BitIndex < 11) 
			baud_BitIndex <= baud_BitIndex + 1;
		else begin
			baud_BitIndex <= 0;
			if(baud_DataIndex < 3)
				baud_DataIndex <= baud_DataIndex + 1;
			else
				baud_DataIndex <= 0;
		end
		
		
		if(baud_BitIndex == 0) 
			IO_UART_RX <= 0;
		else if(baud_BitIndex > 8)
			IO_UART_RX <= 1;
		else 
			IO_UART_RX <= data_RX_arr[baud_DataIndex][baud_BitIndex - 1];
		
		
	end

end
`endif



always @(posedge clk) begin
	if(cnt < 327670 - 1) 
		cnt <= cnt + 1;
	else
		$finish;
		
		
	if(cnt < 5)
		reset <= 1;
	else
		reset <= 0;
end


initial
 begin
    $dumpfile("WaveIcarus.vcd");
    $dumpvars(0,tb_WB_master);
 end

endmodule