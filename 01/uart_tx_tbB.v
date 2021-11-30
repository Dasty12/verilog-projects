`include "UartTx_top.v"
`timescale 1ns/1ns

module uart_tx_tbB;

reg clk_50kHz = 0;
reg c0 = 0;
wire UART_Tx = 0;
reg rst = 0;    


UartTx_top uartTx_top (
    .clk(clk),
    .c0(c0),
    .UART_Tx(UART_Tx)
);



always #5 c0 = !c0;

always #10000 clk_50kHz =!clk_50kHz;   //50khz


initial begin
    #5 rst = 1;
    #5 rst = 0;

    
    $dumpfile("uart_tx_waves.vcd"); 
    $dumpvars;
end


initial begin
    #5000000 $finish;
end




endmodule
