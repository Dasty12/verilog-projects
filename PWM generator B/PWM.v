module PWM #(
    parameter DATA_WIDTH = 8
)(
    input clk,
    input [2*DATA_WIDTH-1:0] CMPA,
    output OUT
);

parameter KMAX_VALUE = (2 ** (DATA_WIDTH))-1; 
parameter 
   = 100000000 / (KMAX_VALUE * 1000);


reg [$clog2(KCNT_MAX)-1:0] CNT_DIV = 0;
reg PMW_TICK = 0;

always @(psoedge clk) begin
    if(CNT_DIV < KCNT_MAX) begin
        CNT_DIV <= CNT_DIV + 1;
        PWM_TICK <= 0;
    end else begin
        CNT_DIV <= 0;
        PWM_TICK <= 1;
    end
end




initial begin
    $display(" maximum je %d",KCNT_MAX);
    
end

endmodule