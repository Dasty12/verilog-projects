`include "../UartRx.v"
`timescale 1ns/1ns

module UartRx_tb;

parameter KBAUD = 14'd10416;

reg clk = 0;

wire[7:0] data_Rx;
//reg[9:0] dataRx_plusStartStop = 10'b; //data jsou po kazdem prenosu inkrementovana, a tak se prenese cele pasmo moznych dat   
reg[3:0] dataRx_cnt = 0; 
reg[$clog2(KBAUD)-1:0] baud_cnt  = KBAUD;

reg IN;
wire Rx_done;
wire busy;


UartRx #(.KBAUD(KBAUD)) 
        DUT(.clk(clk),
            .data_IN(IN),
            .data_OUT(data_Rx), 
            .Rx_done(Rx_done), 
            .busy(busy));




always #5 clk = !clk;

initial begin
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end


initial begin
    #5000000 $finish;
end


endmodule
