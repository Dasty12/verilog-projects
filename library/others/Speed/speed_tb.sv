`timescale 1ns/1ns
module speed_tb;

reg clk = 0;
reg [15:0] DUT_sq;
reg DUT_dir;
wire DUT_A;
wire DUT_B;



speed DUT(.clk(clk),
          .sq(DUT_sq),
          .dir(DUT_dir),
          .A(DUT_A),
          .B(DUT_B));

initial begin
    DUT_sq <= 1000;
end

always #5 clk =!clk;
initial begin
    $dumpfile("speed_waves.vcd"); 
    $dumpvars;
end
    
endmodule