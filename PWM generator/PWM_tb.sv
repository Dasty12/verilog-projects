`include "PWM.sv"
`timescale 1ns/1ns

module PWM_tb;

reg clk;
reg rst;
reg [13:0] CMPA;
wire PWM_OUT;

PWM pwm(
    .clk(clk),
    .rst(rst),
    .CMPA(CMPA),
    .PWM_OUT(PWM_OUT)
);

endmodule