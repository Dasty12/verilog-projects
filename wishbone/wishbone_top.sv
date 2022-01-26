module wishbone_top (
    input i_clk_12Mhz,
    input  IO_UART_RX,
    output IO_UART_TX,
    output [7:0] o_LEDS
);

reg[7:0] UART_WORD_RX;
reg[7:0] UART_WORD_TX;

wire uart_Rx_stb;
wire uart_busy;
wire uart_out_RXNE;
wire uart_out_Rx_ORE;
reg in_RXNE_clear = 0;


reg i_reset = 0; 


UartTop uartTop(.clk(i_clk_12Mhz),
                .in_w_data(UART_WORD_TX),
                .in_valid(uart_stb),
                .out_BUSY(uart_busy),
                .out_signal(IO_UART_TX),
                //signals for receivera
                .in_signal(IO_UART_RX),
                .in_RXNE_clear(in_RXNE_clear),
                .out_word(UART_WORD_RX),
                .out_RXNE(uart_out_RXNE),
                .out_Rx_ORE(uart_out_Rx_ORE));


wire [7:0]UART_DECODER_i_data_in;
reg UART_DECODER_i_data_valid;  //muzu  ponechat necinne
reg UART_DECODER_i_stb = 0;
reg UART_DECODER_i_stb_old = 0;
reg Decoder_o_stb;
reg [33:0]Decoder_o_word;
wire UART_DECODER_i_stb_rise;

assign UART_DECODER_i_data_in  = UART_WORD_RX;

UartDecoder uartDecoder(.i_clk(i_clk_12Mhz),
                        .i_data_in(UART_DECODER_i_data_in),
                        .i_data_valid(UART_DECODER_i_data_valid),
                        .i_stb(UART_DECODER_i_stb_rise),
                        .o_stb(Decoder_o_stb),
                        .o_word(Decoder_o_word));


always @(posedge i_clk_12Mhz) begin
    UART_DECODER_i_stb_old <= UART_DECODER_i_stb;
end


always @(posedge i_clk_12Mhz) begin
    if(uart_out_RXNE)begin
        in_RXNE_clear <= 1;
        UART_DECODER_i_stb <= 1;
    end else begin
        in_RXNE_clear <= 0;
        UART_DECODER_i_stb <= 0;
    end

end

assign UART_DECODER_i_stb_rise = UART_DECODER_i_stb &(~UART_DECODER_i_stb_old);





//WB master 
wire o_cmd_busy;
wire o_rsp_stb;
wire [33:0] o_rsp_word;
wire o_wb_cyc;
wire o_wb_stb;
wire o_wb_we;
wire [29:0] o_wb_addr;
wire [31:0] o_wb_data;
wire  [3:0] o_wb_sel;

wire i_wb_stall;
wire i_wb_ack;
wire i_wb_err;
wire [31:0] i_wb_data;

wire [7:0] o_LEDS_dummy;
 
WB_master wb_master(.i_clk(i_clk_12Mhz),
                    .i_reset(i_reset),
                    //prikazy pro receivera
                    .i_cmd_stb(Decoder_o_stb),
                    .i_cmd_word(Decoder_o_word),
                    .o_cmd_busy(o_cmd_busy),
                    // Return command channel
                    .o_rsp_stb(o_rsp_stb),
                    .o_rsp_word(o_rsp_word),
                    // Wishbone output
                    .o_wb_cyc(o_wb_cyc),
                    .o_wb_stb(o_wb_stb),
                    .o_wb_we(o_wb_we),
                    .o_wb_addr(o_wb_addr),
                    .o_wb_data(o_wb_data),
                    .o_wb_sel(o_wb_sel),
                    // Wishbone inputs
                    .i_wb_stall(i_wb_stall),
                    .i_wb_ack(i_wb_ack),
                    .i_wb_err(i_wb_err),
                    .i_wb_data(i_wb_data));





//WB master
WB_slave wb_slave(.i_clk(i_clk_12Mhz),
                  .i_wb_cyc(o_wb_cyc),
                  .i_wb_stb(o_wb_stb),
                  .i_wb_we(o_wb_we),
                  .i_wb_addr(o_wb_addr),
				  .i_wb_data(o_wb_data),
                  .i_wb_sel(o_wb_sel),
         
                  .o_wb_stall(i_wb_stall),
                  .o_wb_ack(i_wb_ack),
                  .o_wb_err(i_wb_err),
                  .o_wb_data(i_wb_data),
                  .o_LEDS(o_LEDS));


//decode information from slave to multiple 8-bit words
wire o_dw_busy;

UartCoder uartCoder(.i_clk(i_clk_12Mhz),
					.i_reset(i_reset),
					.i_stb(o_rsp_stb),
					.o_dw_busy(o_dw_busy),
					.i_word(o_rsp_word),
					.out_char(UART_WORD_TX),
					.i_TxBusy(uart_busy),
					.o_TxStart(uart_stb),
					.i_wb_we(o_wb_we),
					.o_LEDS(o_LEDS_dummy));





endmodule