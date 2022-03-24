module SPI_DAC (input clk, input rst, input ST_rise, output n_CS, output SCK, output SDI);//Start Transfer

parameter SCK_div = 10 / 2; 	///5000/2
 
reg [3:0] cfg  = 4'b1100;
reg [7:0] data = 120;

wire [15:0] data_out;
reg [3:0] cnt = 0;
reg [$clog2(SCK_div):0] SCK_cnt = 0;
reg r_SCK = 0;
reg r_SDI;
reg r_CS;
reg [4:0] index = 0;

reg r_SCK_fall;

wire w_SCK_fall;

always @(posedge clk) begin

	if(r_CS == 0) begin
	
		if(SCK_cnt < SCK_div) begin
			SCK_cnt <= SCK_cnt + 1;
		end else begin
			SCK_cnt <= 0;
			r_SCK <= ~ r_SCK;
		end
	
	end
	
	
	r_SCK_fall <= r_SCK;
end


assign data_out = {{4{1'b0}},{data,cfg}};
assign w_SCK_fall = r_SCK_fall & (!r_SCK);

always @(posedge clk) begin	// datovy signal se bude menit pri falling edge

	if(rst)begin
		r_CS <= 1;
		index <= 15;
	end else begin
		
		if(ST_rise) begin
			index <= 0;
			r_SDI <= data_out[index[3:0]];
			r_CS  <= 0;
		end
		else begin
			if((index < 16) && (w_SCK_fall)) begin
				index <= index + 1;
				r_SDI <= data_out[index[3:0]];
				
			end else if(index > 15) begin
				r_CS  <= 1;
				index <= 0;
			end
			
		end 
	end
end


assign n_CS = r_CS;
assign SCK = r_SCK;
assign SDI = r_SDI;

//assign data_out = {{4{1'b0}},{}}

endmodule;