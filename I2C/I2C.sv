module I2C(input clk, input rst,input start ,inout SDA,output SCL,output test_ack);



reg [7:0] K_ADDRESS = 8'h27;		//0x27 nebo 0x3F
 
reg r_SDA;
reg r_SCL;
reg [2:0] index_address;
reg [11:0] delay_start;



localparam s_IDLE = 0;
localparam s_START = 1;
localparam s_DATA  = 2;
localparam s_ACK   = 3;

reg[2:0] state = s_IDLE;

reg r_test_ack;


always @(posedge clk) begin
	if(rst) begin
		r_SDA <= 1;
		r_SCL <= 1;
		delay_start <= 0;
		r_test_ack <= 0;
		
	end else begin
		if(start) begin
			r_SDA <= 0;
			delay_start <= 2500;
			state <= s_START;
		end
	end
	

	case(state)
		s_START: begin
			if(delay_start > 0)
				delay_start <= delay_start - 1;
			else begin
				r_SCL <= 0;
				state <= s_DATA;
				index_address <= 7;
				delay_start <= 2500;
			end
		end s_DATA: begin
			if(delay_start > 0) begin 
				delay_start <= delay_start - 1;

				if(delay_start == 1875) begin
					r_SCL <= 1;
				end else if(delay_start == 2) begin
					r_SCL <= 0;
				end
			end else begin
				if(index_address > 0) begin
					r_SDA <= K_ADDRESS[index_address];
					
					index_address <= index_address -1;
				end else begin
					state <= s_ACK;
				end
				delay_start <= 2500;	
				
			end
		end s_ACK: begin
			r_test_ack <= 1;
			if(delay_start > 0) begin 
				delay_start <= delay_start - 1;
				if(delay_start == 1875) begin
					r_SCL <= 1;
				end else if(delay_start == 625) begin
					r_SCL <= 0;
				end 
			end else begin
				delay_start <= 2500;
				state <= s_DATA;
				index_address <= 7;
				r_test_ack <= 0;
			end

		end default: begin end
	endcase
	
end



assign SDA = (r_test_ack) ? 1'bz :r_SDA;
assign SCL =  r_SCL;
assign test_ack = r_test_ack;





endmodule