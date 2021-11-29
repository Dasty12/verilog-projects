`include "PWM.sv"

module PWM_top (
    input clk,
    output OUT
);

localparam KPERIOD_PWM = 1000;

reg rst;
reg [$clog2(KPERIOD_PWM)-1:0] CMPA;
reg rst_cnt = 0;


PWM #(.KPERIOD(KPERIOD_PWM),.KCLKDIV(10))
    pwm(.clk(clk),
        .rst(rst),
        .CMPA(CMPA),
        .PWM_OUT(OUT));


always @(posedge clk) begin
    if(rst_cnt == 0) begin
        rst_cnt <= rst_cnt + 1;
        rst = 1;
    end
    else begin
        rst = 0;
    end
    CMPA <= 200;
end

endmodule