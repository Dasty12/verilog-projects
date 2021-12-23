module PLL1 (
	input areset,
	input inclk0,
	output c0,
	output locked);

reg r_c0;


initial r_c0 = 0;




always @(posedge inclk0) begin
    r_c0 <= !r_c0;
end

assign c0 = r_c0;






endmodule