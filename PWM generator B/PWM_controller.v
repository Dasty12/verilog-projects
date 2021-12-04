`include "PWM.v"

module PWM_controller # (
    parameter ROM_WIDTH = 8
)(
    input clk,
    input i_ce,
    input [2*ROM_WIDTH-1:0] data_in,
    output OUT
);

reg [2*ROM_WIDTH-1:0] data_r;

always @(posedge(i_ce)) begin
  data_r <= data_in;
end
    
PWM #(ROM_WIDTH) pwm_inst(.clk(clk), .CMPA(data_r),.OUT(OUT));


endmodule