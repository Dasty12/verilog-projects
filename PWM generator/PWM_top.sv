`include "PWM.sv"

module PWM_top (
    input clk,
    output OUT
);
    
reg rst;
reg [13:0] CMPA;

PWM pwm(.clk(clk),
        .rst(rst),
        
        .PWM_OUT(OUT))


endmodule