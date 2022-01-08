module test
(
input clk,
input rst,
input sig1,
output out,
output [15:0] cnt_out,
output [31:0] out_I,
output [31:0] out_X0,
output [31:0] out_X00,
output [31:0] out_X1,
output [31:0] out_X2,
output [31:0] out_X22,
output [31:0] out_di,
output [31:0] out_di2,
output [31:0] out_I_1
);

reg out_n;
reg [15:0] cnt;
reg [15:0] cnt2;

parameter signed R  = 10 ;    // Q5.0
parameter signed L_div  = 100;   // Q8.0
parameter signed U0 = 200 ;  // Q11.0	200*2**8
parameter signed dt = 26;	// Q1.18



reg signed [31:0] X0;
reg signed [31:0] X1;
reg signed [31:0] X2;	//signed Q8.4
reg signed [31:0] di;		//signed Q0.18	
reg signed [31:0] i1;	//signed Q12.19 
reg signed [31:0] I;	//signed Q12.19
reg [4:0] state;
integer X00;
integer X22;
integer di2;
integer I_1;


initial state = 0;
initial I = 0;
	always @(posedge clk) begin
		if(rst)
		begin
			cnt  <= 0;
			cnt2 <= 0;
			state <= 0;
		end else begin
			
			case(state)
				0: X0 <= R * I;				// Q.0= Q.0 * Q.0
				1: X00 <= X0 >> 0;			// Q.0
				2: X1 <= U0 - X00;			// Q.0
				3: X2 <= X1 * L_div;		// Q0
				4: X22 <= X2 >> 0;			// Q0
				5: di <= X22 * dt;			// Q0 * 18 = 18
				6: di2 <= di >> 10;			// Q8
				7: I_1 <= I_1 + di2;        	// Q8  
				8: I  <= I_1 >> 8; 			// Q0
			endcase
		
			if(state < 8) begin
				state <= state + 1;
			end else begin
				state <= 0;
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
		
		
		


	end
assign out = out_n;
assign cnt_out = cnt2;
assign out_I = I;
assign out_X0 = X0;
assign out_X00 = X00;
assign out_X1 = X1;
assign out_X2 = X2;
assign out_X22 = X22;
assign out_di = di;
assign out_di2 = di2;
assign out_I_1 = I_1;
assign out_I = I;



endmodule

/*
AddAB = A + B;
case (AddAB[MSB:MSB-1])
  2’b01 : add = MAX_POS;//Overflow
  2’b10 : add = MAX_NEG;//Underflow
 default: add = AddAB[MSB-1:0]; //In Range
endcase


*/