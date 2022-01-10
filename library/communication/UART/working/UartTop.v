`include "UartRx.v"
`include "UartTx.v"

module UartTop (
    input clk,
    //tyto signaly jsou pouze pro transmitera
    input [7:0] in_data, /*pokud je valid = 1, tak jsou to nova data pro transmitera*/   
    input in_valid,      /*je pozadavek na prenos dat*/
    output out_BUSY,     /*znaci,ze dochazi k prenosu*/
    output out_signal,   /*signal odesilany pres UART pryc*/   
    //signaly pro receivera
    input in_signal,     /*signal prijimany pres UART*/   
    output out_valid,    /*doslo k prijmu jednoho bytu, ten je platny do dalsi nabezne hrany,tzn pri zmene dat, bude tento signal nastaven do 101 */
    output[7:0] out_word      /*prijmuta data*/   
);
    
reg [7:0] r_Tx_DataByte; 
reg r_BUSY = 1; 
wire TxComplete;
localparam KBAUD = 14'd10416; 

wire Rx_busy;


UartRx #(.KBAUD(KBAUD)) uartRx(.clk(clk), 
                               .in_data(in_signal), 
                               .out_data(out_word), 
                               .Rx_done(out_valid), 
                               .busy(Rx_busy));

UartTx #(.KBAUD(KBAUD)) uartTx(.clk(clk),
                               .in_DataByte(r_Tx_DataByte), 
                               .in_Start(out_BUSY), 
                               .out_DataBit(out_signal), 
                               .out_fComplete(TxComplete));   

always @(posedge clk) begin
    if((TxComplete) && (in_valid))begin
        r_Tx_DataByte <= in_data;
        r_BUSY <= 0;
    end else begin
       r_BUSY <= 1; 
    end
end





assign out_BUSY = r_BUSY;

endmodule