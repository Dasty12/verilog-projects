module I2C(input clk, input rst,input start ,inout SDA,output SCL,output test_ack);



reg [7:0] K_ADDRESS = 8'h27;		//0x27 nebo 0x3F
reg [7:0] data_array [3];
 
reg r_SDA;
reg r_SCL;
reg [2:0] index_address;
reg [11:0] delay_start;
reg [11:0] delay_STOP;

reg [3:0] data_length = 0;

localparam s_IDLE = 0;
localparam s_START = 1;
localparam s_DATA  = 2;
localparam s_ACK   = 3;
localparam s_STOP  = 4;

reg[2:0] state = s_IDLE;

reg r_test_ack;
reg  [7:0]test_vymaz;

initial begin 

end


always @(posedge clk) begin



	if(rst) begin
		r_SDA <= 1;
		r_SCL <= 1;
		delay_start <= 0;
		r_test_ack <= 0;
		delay_STOP <= 0;
		data_array[0] <= 8'h27;
		data_array[1] <= 8'h81;
		data_array[2] <= 8'h02;

		
	end else begin
		if(start) begin
			r_SDA <= 0;
			delay_start <= 2500;
			state <= s_START;
			delay_STOP <= 0;
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
					index_address <= index_address - 1;
				end else begin
					state <= s_ACK;
				end
				delay_start <= 2500;	
				
			end
			r_SDA <=data_array[data_length][index_address]; 
			test_vymaz <= data_array[data_length];
			
			
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
				r_SDA <= 0;
				
				if(data_length < 2) begin
					data_length <= data_length + 1;
					state <= s_DATA;
					index_address <= 7;
				end else begin
					state <= s_STOP;
				end
			end
			

		end s_STOP: begin

			r_SDA <= 0;
			
			if(delay_STOP < (delay_start / (4 - 1)) )begin
				delay_STOP <= delay_STOP + 1;
			end else begin
				r_SCL <= 1;
			end
			
			if(delay_start > 0) begin
				delay_start <= delay_start - 1;
			end else begin 
				state <= s_IDLE;
				r_SDA <= 1;
			end
		end default: begin end
	endcase
	
end



assign SDA = (r_test_ack) ? 1'bz :r_SDA;
assign SCL =  r_SCL;
assign test_ack = r_test_ack;





endmodule