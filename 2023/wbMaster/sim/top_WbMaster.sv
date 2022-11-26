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
    output [31:0] o_wb_addr,  // adresa pro slaves
    output        o_wb_we,
    output        o_wb_cyc,
    output        o_wb_stb,
`ifdef SLAVE_SIM 
    input         i_wb_ack,
`endif

    output        WB2UART_stall,

    output [33:0] WB2UART_word,
    output        WB2UART_cyc,


    //START DEBUG C++
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] tst1,
    input [31:0] tst2,
    input [31:0] tst3,
    input [31:0] tst4,
    input [31:0] Rx_wait,
    input [31:0] wait_A_cnt,
    input [31:0] wait_cnt,
    input [31:0] cmd_index,
    input [31:0] slave_adresa,
    //END DEBUG C++


    
    output U2Tx_Start,         //pozadavek na odeslani dalsiho znaku z WB2Uart do UartTx
    output [7:0] U2Tx_DataByte,
    input  U2Tx_fComplete       //signál z UartTx, úspěšný přenos znaku

);



Uart2wb U2wb(
    .clk(clk),
    .rst(rst),
    .UART_in_data(UART_in_data),
    .UART_rx_done(UART_Rx_done),
    .WB_ctr_w(WB_ctr_w),
    .WB_o_cyc(WB_o_cyc)
);




`ifndef SLAVE_SIM
wire i_wb_ack;
wb_memory WBmemory
(
    .clk(clk),
    .rst(rst),

    .i_wb_we(o_wb_we),  // write enable 
    .i_wb_cyc(o_wb_cyc), // jde do nuly az o jednu periodu dele
    .i_wb_stb(o_wb_stb), //stb jde do nuly hned potom

    .o_wb_ack(i_wb_ack), //potvrzeni od tohoto
    
    .io_wb_data(io_wb_data),
    .i_wb_addr(o_wb_addr)

);

`endif




WbMaster WBM (.clk(clk), 
              .rst(rst), 
              
              .in_WB_ctr_w(WB_ctr_w), 
              .in_WB_o_cyc(WB_o_cyc),

              .out_WB2UART_word(WB2UART_word),
              .out_WB2UART_cyc(WB2UART_cyc), 
              
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
