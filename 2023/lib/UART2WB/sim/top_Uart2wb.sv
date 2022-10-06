typedef enum logic [1:0] {
     add     = 2'h1,
     sub     = 2'h2,
     nop     = 2'h0
} operation_t /*verilator public*/;

module top_Uart2wb 
(
	input clk,
     input rst,
	input [7:0] UART_in_data,
	input UART_Rx_done,
     output [33:0] WB_ctr_w,
     output WB_o_cyc

);

Uart2wb U2W(.clk(clk), .rst(rst), .UART_in_data(UART_in_data), .UART_rx_done(UART_Rx_done), .WB_ctr_w(WB_ctr_w), .WB_o_cyc(WB_o_cyc));

endmodule
