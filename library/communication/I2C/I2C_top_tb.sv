`timescale 1ns/1ns

module I2C_top_tb;

reg clk = 0;
wire DUT_SDA;
wire DUT_SCL;

I2C_top DUT(.clk(clk),
            .SDA(DUT_SDA),
            .SCL(DUT_SCL));


always #5 clk = !clk;
initial begin
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end
endmodule