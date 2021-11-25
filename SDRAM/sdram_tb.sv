`include "sdram.sv"
`timescale 1ns/1ns

module sdram_tb;



reg clk = 0;
reg rst = 0;
wire clk_EN;
wire [13:0] SDRAM_Addr;
wire [1:0] SDRAM_BankAddr;
wire[15:0] SDRAM_data;
wire SDRAM_WE;
wire SDRAM_CHIP_Sel;




sdram sdram_1(.clk(clk),
              .rst(rst),
              .clk_EN(clk_EN),
              .SDRAM_Addr(SDRAM_Addr), 
              .SDRAM_BankAddr(SDRAM_BankAddr), 
              .SDRAM_WE(SDRAM_WE),
              .SDRAM_CHIP_Sel(SDRAM_CHIP_Sel),
              .SDRAM_data(SDRAM_data));



always #5 clk = !clk;

initial begin 
    #5 rst = 1;
    #5 rst = 0;


$dumpfile("sdram_wave.vcd");
$dumpvars;

end

initial begin
    #5000000 $finish;
end


endmodule