
`timescale 1 ns/1 ns  // time-unit = 1 ns, precision = 10 ps
module tb_I2C;

reg clk = 0;
reg reset = 0;
reg[18:0] cnt = 0;
reg r_start;

wire SDA ;
wire SCL;
wire test_ack;

reg r_SDA;

I2C dut(.clk(clk),
		.rst(reset),
		.start(r_start),	
		.SDA(SDA),	
		.SCL(SCL),
		.test_ack(test_ack));



always #5 clk = !clk;

always @(posedge clk) begin
	if(cnt < 327670 - 1) 
		cnt <= cnt + 1;
	else
		$finish;
		
		
	if(cnt < 5)
		reset <= 1;
	else
		reset <= 0;
		
	if(cnt == 25)
		r_start <= 1;
	else 
		r_start <= 0;

	if(test_ack)
		r_SDA <= 0;
	else 
		r_SDA <= 1;


end


assign SDA = (test_ack) ? r_SDA : 1'bz;

initial
 begin
    $dumpfile("WaveIcarus.vcd");
    $dumpvars(0,tb_I2C);
 end


endmodule;