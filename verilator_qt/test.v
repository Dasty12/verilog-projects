module test
(
input clk,
input rst,
input sig1,
output out,
output [15:0]cnt_out
);

reg out_n;
reg [15:0] cnt;
reg [15:0] cnt2;

	always @(posedge clk) begin
		if(rst)
		begin
			cnt  <= 0;
			cnt2 <= 0;
		end
		if(cnt < 10) begin
			cnt <= cnt + 1;

		end
		else begin
			out_n <= ~out_n;
			cnt <= 0;
		end
		
		cnt2 <= cnt2 + 1;

	end
assign out = out_n;
assign cnt_out = cnt2;

endmodule