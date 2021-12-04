`timescale 1ns/1ns
`include "../PWM_r01.v"

module PWM_tb;
    
parameter CMPA_WIDTH = 8;
parameter KPERIOD_COUNT = 255;




reg clk = 0;
reg [CMPA_WIDTH - 1:0] STRIDA;
wire PWM_OUT;


PWM_r01 #(.CMPA_WIDTH(CMPA_WIDTH), .KPERIOD_COUNT(KPERIOD_COUNT)) DUT1( .clk(clk), .CMPA_shdw(STRIDA), .PIN_OUT(PWM_OUT));






initial begin
    $dumpfile("WAVE.vcd");
    $dumpvars;
end

always #5 clk =  !clk;



initial begin
    #10 STRIDA =  100;
    #50000 STRIDA =  200;

    #5e6 $finish;

end


endmodule