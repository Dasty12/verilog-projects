`timescale 1ns/1ns

module I2C_top_tb;

reg clk = 0;
reg reset = 1;
wire DUT_SDA;
wire DUT_SCL;

I2C_top DUT(.clk(clk),
            .SDA(DUT_SDA),
            .SCL(DUT_SCL));


always #5 clk = !clk;
initial begin
    $dumpfile("I2C_waves.vcd"); 
    $dumpvars;
end
reg[18:0] cnt = 0;

always @(posedge clk) begin
	if(cnt < 327670/4 - 1)
		cnt <= cnt +1;
	else
		$finish;
		
	if(cnt < 5)
		reset <= 1;
	else
		reset <= 0;
end


endmodule