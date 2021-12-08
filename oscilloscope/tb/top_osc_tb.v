`timescale 1ns/1ns
`include "../top_osc.v"
`include "../../library/memory/ROM/rom_async.v"
`include "../../library/memory/ROM/rom_table.v"
`include "../../library/memory/ROM/sine_table_64x8.mem"
module top_osc_tb;
    
reg clk = 0;


top_osc DUT(.clk(clk));




initial begin   
    $dumpfile("WAVES.vcd");
    $dumpvars;
end

always #5 clk = !clk;

initial begin
    #5000000 $finish;
end

endmodule