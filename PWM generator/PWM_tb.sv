`include "PWM.sv"
`timescale 1ns/1ns

module PWM_tb;
localparam KPERIOD_PWM =  1000;
reg clk = 0;
reg rst;
reg [$clog2(KPERIOD_PWM)-1:0] CMPA;
wire PWM_OUT;
reg rst_cnt = 0;



PWM #(.KPERIOD(KPERIOD_PWM),.KCLKDIV(10))
    pwm(
    .clk(clk),
    .rst(rst),
    .CMPA(CMPA),
    .PWM_OUT(PWM_OUT)
    );


always @(posedge clk) begin
    if(rst_cnt == 0) begin
        rst_cnt <= rst_cnt + 1;
        rst = 1;
    end
    else begin
      rst = 0;  
    end
end

always #5 clk =!clk;

initial begin
    CMPA = 200;

    $dumpfile("PWM.vcd");
    $dumpvars;
end


initial begin
    #5000000 $finish;
end


endmodule