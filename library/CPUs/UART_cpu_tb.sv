`timescale 1ns/1ns

module UART_cpu_tb;
    
reg clk;
wire Rx;
wire Tx;
reg USER_btn;


initial clk = 0;
initial USER_btn = 1;

UART_cpu DUT(.clk(clk),
             .Rx(Rx),
             .Tx(Tx),
             .USER_btn(USER_btn)
             );




initial begin
    #1000  USER_btn = 0;
    #10000 USER_btn = 1;
end


always #5 clk = !clk;
initial begin
    $dumpfile("UART_cpu_tb_waves.vcd"); 
    $dumpvars;
end
endmodule