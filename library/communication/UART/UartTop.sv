//`include "UartRx.v"
//`include "UartTx.v"

module UartTop (
    input clk,
    //signaly pro transmitera
    input wire [7:0] in_w_data, 		  /* */
    input            in_valid,            /* je pozadavek na prenos dat 			       */
    output           out_BUSY,            /* signalizuje, ze dochazi k prenosu			   */
    output           out_signal,          /* I/O OUTPUT TX signal						   */   
    //signaly pro receivera 
    input            in_signal,           /* I/O INPUT RX signal			 			   */
    input            in_RXNE_clear,       /* clear RXNE signal 							   */
    output [7:0]     out_word,            /* received data								   */ 
    output           out_RXNE,            /* receiver dokoncil přenos a jsou nova data     */
    output           out_Rx_ORE,          /* received data isn't read, and occurs override */
    output [7:0]     o_LEDS
);



reg [7:0] r_Tx_DataByte; 
reg [7:0] r_Rx_DataByte = 0; 
reg r_Tx_start = 1;
reg r_Tx_busy = 0;
reg in_valid_old = 0;

wire TxComplete;
reg TxComplete_old;
wire TxCompleteRise;
wire Tx_start;
reg [4:0] rst_counter = 20; 

localparam KBAUD = 14'd10416; 

wire Rx_busy;
reg r_RXNE = 0;
reg r_RXNE_clear_old;
wire w_RXNE_clear_rise;
reg r_Rx_done;
reg r_out_Rx_ORE = 0;
reg [7:0] r_Rx_data;
reg r_rst;
wire rst;

always @(posedge clk) begin 
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
                               .in_data(in_signal), 
                               .out_data(r_Rx_data), //out_word
                               .Rx_done(r_Rx_done), 
                               .busy(Rx_busy),
                               .o_LEDS(o_LEDS));

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


    if(r_Rx_done) begin
      /*  if(r_RXNE == 1) begin
            r_out_Rx_ORE <= 1;
        end else begin
            r_out_Rx_ORE <= 0;
        end*/
        r_RXNE <= 1;
        r_Rx_DataByte <= r_Rx_data;
    end else if(w_RXNE_clear_rise) begin
        r_RXNE <= 0;
    end

    r_RXNE_clear_old <= in_RXNE_clear;  
    TxComplete_old <= TxComplete;
    in_valid_old <= in_valid;
end

assign TxCompleteRise = TxComplete & (!TxComplete_old);
assign out_RXNE = r_RXNE;
assign Tx_start = r_Tx_start;
assign w_RXNE_clear_rise = in_RXNE_clear & (~r_RXNE_clear_old);
assign out_Rx_ORE = r_out_Rx_ORE;
assign out_BUSY = r_Tx_busy;
assign out_word = r_Rx_DataByte;
endmodule