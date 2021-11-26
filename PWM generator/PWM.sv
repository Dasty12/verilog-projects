module PWM #(parameter KPERIOD = 50, parameter KCLKDIV = 10)
(
    input clk,
    input rst,
    input [$clog2(KPERIOD)-1:0] CMPA,    //period register
    output PWM_OUT
);

parameter KCLKDIV_BIT = $clog2(KCLKDIV);
reg [KCLKDIV_BIT-1:0]clk_pwm_cnt;
reg clk_pwm;
reg [$clog2(KPERIOD)-1:0] TBCTR;
reg PWM_OUT_l;              //PWM OUT LOCAL

always @(posedge clk) begin
    if(rst) begin
        clk_pwm <= 1;
        clk_pwm_cnt <= 0;
        
    end
    else begin
        if(clk_pwm_cnt < KCLKDIV)begin
            clk_pwm_cnt <= clk_pwm_cnt + 1;
        end
        else begin
            clk_pwm_cnt <= 0;
            clk_pwm <= ~clk_pwm;
        end
    end
end

always @(posedge clk_pwm) begin
    if(rst) begin
        TBCTR <= 0;
        PWM_OUT_l <= 0;
    end
    else begin
        if(TBCTR < KPERIOD) begin
            TBCTR <= TBCTR + 1;
        end
        else 
            TBCTR <= 0;

        if(TBCTR < CMPA) begin
            PWM_OUT_l <= 1;           
       end 
       else begin
           PWM_OUT_l <= 0;
       end
    end
end



assign PWM_OUT = PWM_OUT_l;

endmodule