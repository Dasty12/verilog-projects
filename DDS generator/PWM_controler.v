`include "../library/PWM/PWM_r01.v"

module PWM_controler #(
    parameter ROM_WIDTH = 8
)(
    input  clk,
    input  i_ce,
    output o_ce,
    input [2*ROM_WIDTH-1:0]data_in
);
parameter KPERIOD_COUNT = 255;

wire PIN_OUT;

reg [7:0]tento;

PWM_r01 #(.CMPA_WIDTH(ROM_WIDTH), .KPERIOD_COUNT(KPERIOD_COUNT)) 
        PWM_inst(.clk(clk),.CMPA_shdw(data_in[7:0]), .PIN_OUT(PIN_OUT)); 

reg [2*ROM_WIDTH-1:0] data_ted;

always @(posedge i_ce) begin
    data_ted <= data_in;
end
    
endmodule