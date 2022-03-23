module SPI_MEMS(input clk, 
				input rst,
				input RW,
				input ST_rise,		//start RISE
				input  [5:0] address,
				input  [7:0]data_in,
				output [7:0]data_out,
				output SDO,	//SDI pro slave
				input  SDI, //SDO pro slave
				output CS,
				output SPC);
				
				
				
parameter SCK_div = 10 / 2;

reg [$clog2(SCK_div):0] SCK_cnt = 0;
reg r_CS;
reg r_SCK = 0;

reg r_SCK_fall;
wire w_SCK_fall;

 

always @(posedge clk) begin

	if(r_CS == 0) begin
		if(SCK_cnt < SCK_div) begin
			SCK_cnt <= SCK_cnt + 1;
		end else begin
			SCK_cnt <= 0;
			r_SCK <= ~r_SCK;
		end
	end
	r_SCK_fall <= r_SCK;
end

assign w_SCK_fall = r_SCK_fall & (!r_SCK);

 always @(posedge clk) begin
	
	if(rst) begin
	
	end else begin
		if(ST_rise) begin
		
		
		end
	end
	
	
	
	
 end





endmodule;