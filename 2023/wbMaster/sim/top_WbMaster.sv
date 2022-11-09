typedef enum logic [1:0] {
     add     = 2'h1,
     sub     = 2'h2,
     nop     = 2'h0
} operation_t /*verilator public*/;


module top_WbMaster
(
    input         clk,
    input         rst,

    input [7:0]   UART_in_data,
    input         UART_Rx_done,
    output [33:0] WB_ctr_w,
    output        WB_o_cyc,
    
    inout [31:0]  io_wb_data,
    output [31:0] o_wb_addr,
    output        o_wb_we,
    output        o_wb_cyc,
    output        o_wb_stb,
   // input       i_wb_stall,
    input         i_wb_ack,

    output        WB2UART_stall,

    output [33:0] WB2UART_word,
    output        WB2UART_cyc,


//output UartTx_out,
    
    output U2Tx_Start,
    output [7:0] U2Tx_DataByte,
    input  U2Tx_fComplete

);

Uart2wb U2wb(
    .clk(clk),
    .rst(rst),
    .UART_in_data(UART_in_data),
    .UART_rx_done(UART_Rx_done),
    .WB_ctr_w(WB_ctr_w),
    .WB_o_cyc(WB_o_cyc)
);

WbMaster WBM (.clk(clk), 
              .rst(rst), 
              
              .in_WB_ctr_w(WB_ctr_w), 
              .in_WB_o_cyc(WB_o_cyc),

              .out_WB2UART_word(WB2UART_word),
              .out_WB2UART_cyc( WB2UART_cyc), 
              
              .io_wb_data(io_wb_data),
              .o_wb_addr(o_wb_addr),
              .o_wb_we(o_wb_we),
              .o_wb_cyc(o_wb_cyc),
              .o_wb_stb(o_wb_stb),
           //   .i_wb_stall(i_wb_stall),
              .i_wb_ack(i_wb_ack));

/* verilator lint_off UNUSED */
//wire [7:0] U2Tx_DataByte;
//wire       U2Tx_Start;
/* verilator lint_off UNDRIVEN */
//reg       U2Tx_fComplete;


WB2UART wb2U(.clk(clk),
             .rst(rst),
             .in_WB2UART_word(WB2UART_word),
             .in_WB2UART_cyc(WB2UART_cyc),
             .out_WB2UART_stall(WB2UART_stall),
             .out_DataByte(U2Tx_DataByte),
             .out_Start(U2Tx_Start),
             .in_fComplete(U2Tx_fComplete));

parameter KBA=5;
/*UartTx #(.KBAUD(KBA))Utx
    (
        .clk(clk),
        .in_DataByte(U2Tx_DataByte),
        .in_Start(U2Tx_Start),
        .out_DataBit(UartTx_out),
        .out_fComplete(U2Tx_fComplete)
    );
*/

endmodule