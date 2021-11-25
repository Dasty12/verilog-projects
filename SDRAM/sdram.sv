
module sdram (
    input clk,
    input rst,
    output clk_EN,
    output [13:0] SDRAM_Addr,
    output [1:0] SDRAM_BankAddr,
    output SDRAM_WE,
    output SDRAM_CHIP_Sel,
    inout [15:0] SDRAM_data
);
    
endmodule