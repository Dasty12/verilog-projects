`include "fal_edge.sv"
`timescale 1ns/1ns

module fal_edge_tb;

reg clk = 0;
reg sig1 = 0;

fal_edge f_edge(.clk(clk),.sig1(sig1));


always #5 clk = !clk;





initial begin
    $dumpfile("test.vcd");
    $dumpvars;
end

initial begin

    #400 sig1 = 1;
    #500 sig1 = 0;
    #5000000 $finish;
end

endmodule
