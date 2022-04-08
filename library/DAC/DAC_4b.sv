module DAC_4b (
    input clk_12M,
    input usr_butt,
    output reg[7:0] DAC,
	 output reg[2:0]  LED
);

reg areset = 0;
wire i_clk;
wire locked;

PLL1 pll(.areset(areset),
		 .inclk0(clk_12M),
		 .c0(i_clk),
		 .locked(locked));


reg[4:0] usr_butt_fil = 0;

reg usr_butt_old; 
wire usr_butt_falls;
reg[3:0] counter_fal;
reg LED_old = 0;
reg LEDD = 0;

wire LED_rise;

reg [12:0] cnt;



always @(posedge i_clk) begin
    
	
	if(usr_butt == 0) begin
		if(usr_butt_falls) begin
			counter_fal <= 7;
		end else if(counter_fal > 0) begin
			counter_fal <= counter_fal - 1;
			usr_butt_fil[counter_fal] <= 1;
		end
	end else begin
		usr_butt_fil <= 0;
	end
	
	
	if((usr_butt_fil[4:1] & 4'b1111)== 4'b1111) begin
		LEDD <= 1;
	end else begin 
		LEDD <= 0;
	end 
	
	
	
	if(LED_rise) begin
		///DAC <= DAC + 1;
		LED <= LED + 1;
	end
	
	
	usr_butt_old <= usr_butt;
	LED_old <= LEDD;
end



always @(posedge i_clk) begin 
	
	if(cnt < 20) begin
		cnt <= cnt + 1;
	end else begin
		if(DAC > 0)begin
			DAC <= DAC - 1;	
		end else begin
			DAC <= 255;
		end
		cnt <= 0;
	end
end


assign usr_butt_falls = (~usr_butt) & usr_butt_old;
assign LED_rise = LEDD & (~LED_old);


 
endmodule