`timescale 1ns/1ns

module EMIF_top_tb;



reg clk = 0;
reg DUT_EMIF_nCS3;
reg DUT_EMIF_nCS4;
reg DUT_EMIF_nWE;
reg DUT_EMIF_nOE;
reg [1:0]  DUT_EMIF_nDQM;
reg [21:0] DUT_EMIF_A;
reg [1:0] DUT_EMIF_BA;
wire [15:0] DUT_EMIF_D;
wire DUT_EMIF_nWAIT;

EMIF_top DUT(.inclk0(clk),
             .EMIF_nCS3(DUT_EMIF_nCS3),
             .EMIF_nCS4(DUT_EMIF_nCS4),
             .EMIF_nWE(DUT_EMIF_nWE),
             .EMIF_nOE(DUT_EMIF_nOE),
             .EMIF_nDQM(DUT_EMIF_nDQM),
             .EMIF_A(DUT_EMIF_A),
             .EMIF_BA(DUT_EMIF_BA),
             .EMIF_D(DUT_EMIF_D),
             .EMIF_nWAIT(DUT_EMIF_nWAIT)
             );






always #5 clk = !clk;

initial begin
    $dumpfile("wave.vcd");
    $dumpvars;
end



endmodule