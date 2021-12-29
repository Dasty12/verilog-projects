`timescale 1ns/1ns


module cpu8_top_tb;
    
reg clk;
reg reset;


initial clk = 0;
initial reset = 1;


cpu8_top DUT(.clk(clk),
             .reset(reset));




always #500 clk = !clk;
initial begin
    #1000 reset = 0;
end


initial begin
    $dumpfile("cpu8_waves.vcd");
    $dumpvars;
end
endmodule