module SPI_DAC (input clk,input ST_rise, output n_CS, output SCK, output SDI);//Start Transfer

parameter SCK_div = 5000 / 2;
 
reg [3:0] cfg  = 4'b1100;
reg [7:0] data = 120;

wire [15:0] data_out;
reg [3:0] cnt = 0;
reg [$clog2(SCK_div):0] SCK_cnt = 0;
reg r_SCK = 0;
reg r_SDI ;
reg r_CS = 1;
reg [3:0] index;



always @(posedge clk) begin



	if(SCK_cnt < SCK_div) begin	
		SCK_cnt = SCK_cnt + 1;
	end else begin
		SCK_cnt = 0;
		r_SCK = ~ r_SCK;
	end

	if(ST_rise) begin
		SCK_cnt = 0;
		r_SCK = 0;

	end


end


always @(negedge r_SCK or posedge ST_rise) begin	// datovy signal se bude menit pri falling edge
	if(ST_rise) begin
		///r_SDI <= 0;
		index <= 0;
		r_SDI <= data_out[index];
	end
	else begin
		index <= index + 1;
		r_SDI <= data_out[index];
	end 
	

end


assign n_CS = r_CS;
assign SCK = r_SCK;
assign SDI = r_SDI;
assign data_out = {{cfg, data},{4{1'b0}}};
//assign data_out = {{4{1'b0}},{}}

endmodule;