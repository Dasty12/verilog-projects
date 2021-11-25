`include "PWM.sv"
`timescale 1ns/1ns

module PWM_tb;

reg clk;
reg rst;
reg [5:0] CMPA;
wire PWM_OUT;

PWM pwm(
    .clk(clk),
    .rst(rst),
    .CMPA(CMPA),
    .PWM_OUT(PWM_OUT)
);

always #5 clk =!clk;

initial begin
    clk = 0;
    #5 rst = 1;
    #5 rst = 0;
    CMPA = 20;

    $dumpfile("PWM.vcd");
    $dumpvars;
end


initial begin
    #5000000 $finish;
end


endmodule