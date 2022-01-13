module wishbone_top (
    input i_clk_12Mhz,
    input  IO_UART_RX,
    output IO_UART_TX
);

reg[7:0] UART_WORD_RX;
reg[7:0] UART_WORD_TX;

wire uart_Rx_stb;
wire uart_busy;
wire uart_Tx_valid;




UartTop uartTop(.clk(i_clk_12Mhz),
                .in_data(UART_WORD_RX),
                .in_valid(uart_stb),
                .out_BUSY(uart_busy),
                .out_signal(IO_UART_TX),
                .in_signal(IO_UART_RX),
                .out_valid(uart_Tx_valid),
                .out_word(UART_WORD_TX));


wire [7:0]UART_DECODER_i_data_in;
reg UART_DECODER_i_data_valid;  //muzu  ponechat necinne
reg UART_DECODER_i_stb;
reg UART_DECODER_i_stb_old;
reg UART_DECODER_o_stb;
reg [33:0]UART_DECODER_o_word;
wire UART_DECODER_i_stb_rise;

assign UART_DECODER_i_data_in  = UART_WORD_RX;

UartDecoder uartDecoder(.i_clk(i_clk_12Mhz),
                        .i_data_in(UART_DECODER_i_data_in),
                        .i_data_valid(UART_DECODER_i_data_valid),
                        .i_stb(UART_DECODER_i_stb_rise),
                        .o_stb(UART_DECODER_o_stb),
                        .o_word(UART_DECODER_o_word));


always @(posedge i_clk_12Mhz) begin
    UART_DECODER_i_stb_old <= UART_DECODER_i_stb;
end

assign UART_DECODER_i_stb_rise = UART_DECODER_i_stb &(~UART_DECODER_i_stb_old);


endmodule