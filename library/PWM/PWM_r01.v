
//verze r01 - registr CMPA, se bude ze vstupu načítat, až po uplynuti periody shadow registru


module PWM_r01 #(
    parameter CMPA_WIDTH = 8,
    parameter KPERIOD_COUNT =  255
) (
    input clk,
    input [CMPA_WIDTH-1:0]CMPA_shdw, //shadow
    output PIN_OUT
);
    
reg [$clog2(KPERIOD_COUNT ) -1 :0] CNT_period = 0; //period counter
reg [CMPA_WIDTH -1 :0] r_CMPA = KPERIOD_COUNT;
reg r_PIN_OUT;


always @(posedge clk) begin
    if(CNT_period < KPERIOD_COUNT) begin
        if(CNT_period < r_CMPA)begin
            r_PIN_OUT <= 1;
        end else begin
            r_PIN_OUT <= 0;
        end
        CNT_period <= CNT_period + 1;
        
    end else begin
        CNT_period <= 0;
        r_CMPA <= CMPA_shdw;
    end
end



assign PIN_OUT = r_PIN_OUT;

endmodule