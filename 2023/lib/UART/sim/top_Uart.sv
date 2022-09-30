//`include "UartRx.v"
//`include "UartTx.v"

typedef enum logic [1:0] {
     add     = 2'h1,
     sub     = 2'h2,
     nop     = 2'h0
} operation_t /*verilator public*/;


module top_Uart #(
    parameter CLK_BAULD = 100
)
(
    input clk,
    //signaly pro transmitera
    input wire [7:0] in_w_data, 		  /* */
    input            in_valid,            /* je pozadavek na prenos dat 			       */
    output           out_BUSY,            /* signalizuje, ze dochazi k prenosu			   */
    output           out_signal,          /* I/O OUTPUT TX signal						   */   
    //signaly pro receivera 
    input            UART_IN,           /* I/O INPUT RX signal			 			   */
    //input            in_RXNE_clear,       /* clear RXNE signal 							   */
    output [7:0]     out_word,            /* received data								   */ 
    output           out_RXNE,            /* receiver dokoncil přenos a jsou nova data     */
    output           out_Rx_ORE,         /* received data isn't read, and occurs override */
    output [$clog2(KBAUD)-1:0] bauld
);



reg [7:0] r_Tx_DataByte; 
reg r_Tx_start = 1;
reg r_Tx_busy = 0;
reg in_valid_old = 0;

wire TxComplete;
wire Tx_start;
reg [4:0] rst_counter = 20; 

`ifdef OPT_SIM
	parameter KBAUD = 1041; 
`else
	parameter KBAUD = 10416; 
`endif

reg [$clog2(KBAUD)-1:0] bauld_r;
assign bauld = bauld_r;
reg r_out_Rx_ORE = 0;
reg r_rst;
wire rst;



always @(posedge clk) begin 
    bauld_r <= KBAUD;

    if(rst_counter > 0) begin
        rst_counter <= rst_counter - 1;
        r_rst <= 1;
    end else begin
        r_rst <= 0;
    end
end


assign rst = r_rst;

UartRx #(.KBAUD(KBAUD)) uartRx(.clk(clk), 
                               .rst(rst),
                               .UART_IN(UART_IN), 
                               .out_data(out_word), //out_word
                               .Rx_done(out_RXNE));

UartTx #(.KBAUD(KBAUD)) uartTx(.clk(clk),
                               .in_DataByte(r_Tx_DataByte), 
                               .in_Start(Tx_start), 
                               .out_DataBit(out_signal), 
                               .out_fComplete(TxComplete));   

always @(posedge clk) begin
    if((TxComplete) && (in_valid))begin
        r_Tx_DataByte <= in_w_data;
        r_Tx_start <= 0;
        r_Tx_busy  <= 1;
    end else if(TxComplete && (in_valid_old == 0)) begin//end else if(TxComplete) begin
        r_Tx_start <= 1;
        r_Tx_busy  <= 0;
      end else begin
        r_Tx_start <= 1;
        r_Tx_busy  <= 1; 
    end

    in_valid_old <= in_valid;
end

assign Tx_start = r_Tx_start;
assign out_Rx_ORE = r_out_Rx_ORE;
assign out_BUSY = r_Tx_busy;




`ifdef  OPT_UART_RE

`else


`endif


endmodule