module speed (
    input clk,
    input [15:0] sq,
    input dir,
    output A, 
    output B,
	 input rst
    //todo vypadek otacek
);

reg r_A;
reg r_B;


reg [25:0] sq_cnt = 0;
reg [25:0] sq_half = 0;
reg [25:0] sq_here = 0;

always @(posedge clk) begin
    
	 if(rst == 1) begin
	 r_A <= 0;
	 r_B <= 0;
	 sq_cnt <= 0;
	 sq_half <= 0;
	 end else begin
	 
		 if(sq_cnt < sq_here) begin
			  sq_cnt <= sq_cnt + 1;
			  if(sq_cnt == sq_half) begin
				r_A <= !r_A;
			  end

		 end else begin
			  sq_cnt <= 0;
			  r_B <= !r_B;

		 end
		 sq_here <= {sq,{10{1'b0}}};
		 sq_half <= sq_here >> 1;
	 end
end


assign A = r_A;
assign B = r_B;


endmodule