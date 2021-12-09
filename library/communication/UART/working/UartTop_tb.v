`include "UartTop.v"


`timescale 1ns/1ns

module UartTop_tb;
    
reg clk;
reg [7:0] DUT_in_data;
reg DUT_in_valid;
wire DUT_out_BUSY;
wire DUT_out_signal;
reg DUT_in_signal;
wire DUT_out_valid;

reg [7:0] DUT_out_word;

UartTop DUT(.clk(clk),
            //TRANSMITER 
            .in_data(DUT_in_data), 
            .in_valid(DUT_in_valid), 
            .out_BUSY(DUT_out_BUSY), 
            .out_signal(DUT_out_signal),
            //RECEIVER 
            .in_signal(DUT_in_signal), 
            .out_valid(DUT_out_valid), 
            .out_word(DUT_out_word));















always #5 clk = !clk;
initial begin
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end

initial begin
    #5000000 $finish;
end

endmodule