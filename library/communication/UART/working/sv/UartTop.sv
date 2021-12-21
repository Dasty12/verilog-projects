//`include "UartRx.v"
//`include "UartTx.v"

module UartTop (
    input clk,
    //tyto signaly jsou pouze pro transmitra
    input [7:0] in_data,        /*pokud je valid = 1, tak jsou to nova data pro transmitera*/   
    input wire [7:0] in_w_data, /**/
    input in_valid,             /*je pozadavek na prenos dat*/
    output out_BUSY,            /*znaci, ze dochazi k prenosu*/
    output out_signal,          /*signal odesilany pres UART pryc*/   
    //signaly pro receivera
    input in_signal,            /*signal prijimany pres UART*/
    input  in_RXNE_clear,       /*clear RXNE signal*/
    output[7:0] out_word,       /*prijmuta data*/ 
    output out_RXNE,            /*receiver dokoncil přenos a jsou nova data*/
    output out_Rx_ORE           /*received data isnt read, and occurs override*/
);



reg [7:0] r_Tx_DataByte; 
reg [7:0] r_Rx_DataByte = 0; 
reg r_BUSY = 1; 
wire TxComplete;
localparam KBAUD = 14'd10416; 

wire Rx_busy;
reg r_RXNE = 0;
reg r_RXNE_clear_old;
wire w_RXNE_clear_rise;
reg r_Rx_done;
reg r_out_Rx_ORE = 0;

UartRx #(.KBAUD(KBAUD)) uartRx(.clk(clk), 
                               .in_data(in_signal), 
                               .out_data(out_word), 
                               .Rx_done(r_Rx_done), 
                               .busy(Rx_busy));

UartTx #(.KBAUD(KBAUD)) uartTx(.clk(clk),
                               .in_DataByte(r_Tx_DataByte), 
                               .in_Start(out_BUSY), 
                               .out_DataBit(out_signal), 
                               .out_fComplete(TxComplete));   

always @(posedge clk) begin
    if((TxComplete) && (in_valid))begin
        r_Tx_DataByte <= in_w_data;
        r_BUSY <= 0;
    end else begin
        r_BUSY <= 1; 
    end


    if(r_Rx_done) begin
        if(r_RXNE == 1) begin
            r_out_Rx_ORE <= 1;
        end else begin
            r_out_Rx_ORE <= 0;
        end
        r_RXNE <= 1;
        r_Rx_DataByte <= out_word;
    end else if(w_RXNE_clear_rise) begin
        r_RXNE <= 0;
    end

    r_RXNE_clear_old <= in_RXNE_clear;  
end


assign out_RXNE = r_RXNE;
assign out_BUSY = r_BUSY;
assign w_RXNE_clear_rise = in_RXNE_clear & (~r_RXNE_clear_old);
assign out_Rx_ORE = r_out_Rx_ORE;
endmodule