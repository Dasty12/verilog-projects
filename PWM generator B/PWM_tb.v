`timescale 1ns/1ns
`include "PWM_controller.v"

module PWM_tb;

parameter ROM_WIDTH = 8;

reg clk = 0;
reg rst = 0;


reg i_ce;
reg [2*ROM_WIDTH-1:0] data; 
wire PWM_out;


PWM_controller #(ROM_WIDTH) inst(clk,i_ce,data,PWM_out);



initial begin
    #5 rst = 1;
    #5 rst = 0;

    $dumpfile("WAVES.vcd");
    $dumpvars;

end

always #5 clk = !clk;

initial begin
    #5000000 $finish;
end

endmodule