module wishbone_top_quartus (
    input i_clk_12Mhz,
    input  IO_UART_RX,
    input Usr_button,
	 output IO_UART_TX,
    output [7:0] o_LEDS
	 
);







wire i_clk_100Mhz;
wire i_clk_1Mhz;
reg areset = 0;
wire locked;


PLL_1 pll(
	areset,
	i_clk_12Mhz,
	i_clk_100Mhz,
	i_clk_1Mhz,
	locked);




wishbone_top wb_top(
    .i_clk_12Mhz(i_clk_100Mhz),
    .IO_UART_RX(IO_UART_RX),
    .IO_UART_TX(IO_UART_TX),
    .o_LEDS(o_LEDS),
	 .Usr_button(Usr_button));
    
endmodule