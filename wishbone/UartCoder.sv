module UartCoder (
    input i_clk,
    input i_reset,
    input i_stb,
    output o_dw_busy,
    input [33:0] i_word,
	//UART top
    output reg [7:0] out_char,
	input  i_TxBusy,
	output reg o_TxStart,
	output reg [7:0] o_LEDS
);



reg [3:0]to_Coder = 0; 
reg [7:0]from_Coder = 0;
wire i_stb_rise;

reg i_stb_old;

reg transmit_on_vym = 0;
reg [33:0] r_word;
reg [33:0] r_word_test = 0;

reg [2:0] transmit_counter = 0;

initial o_TxStart <= 1'b0;


reg TxBusy_old;

wire TxBusy_rise; 


reg TxStart_r = 0;

initial o_LEDS = 0;

always@(posedge i_clk) begin
	
	
	if((transmit_counter > 0) && (!TxStart_r) && (!i_TxBusy)) begin
		transmit_counter <= transmit_counter - 1;
		to_Coder <= r_word[3:0];
		r_word <= {{(4){1'b0}},r_word[33:4]};
		TxStart_r <= 1'b1;
	end else if(i_TxBusy) begin
		transmit_on_vym <= 0;
		TxStart_r <= 1'b0;
	end
	
	
	
	
	if(i_stb) begin	// nereagovat na S příkaz
		if(i_word[33:32] == 2'b01)begin
			//r_word <= i_word;
			r_word <= 83;
<<<<<<< Updated upstream
			transmit_counter <= 0;	
		end else if(i_word[33:32] == 2'b00)begin
			//r_word <= 9;
			//r_word <= i_word;
			//o_LEDS[7:2] <= i_word[5:0];
			o_LEDS <= o_LEDS + 1;
			transmit_counter <= 2;
		end else if(i_word[33:32] == 2'b10) begin
		end else begin
		end
		
	//	o_LEDS[1:0] <= i_word[33:32];
		
=======
			transmit_counter <= 2;			
		end 
		r_word_test <= i_word;
>>>>>>> Stashed changes
	end
	
	i_stb_old <= i_stb;
	
	
	o_TxStart <= TxStart_r;
	
end




always@(posedge i_clk) begin
	
	case(to_Coder)
		4'h0: out_char <= 8'h30;
		4'h1: out_char <= 8'h31;
		4'h2: out_char <= 8'h32;
		4'h3: out_char <= 8'h33;
		4'h4: out_char <= 8'h34;
		4'h5: out_char <= 8'h35;
		4'h6: out_char <= 8'h36;
		4'h7: out_char <= 8'h37;
		4'h8: out_char <= 8'h38;
		4'h9: out_char <= 8'h39;
		
		4'ha: out_char <= 8'h61;
		4'hb: out_char <= 8'h62;
		4'hc: out_char <= 8'h63;
		4'hd: out_char <= 8'h64;
		4'he: out_char <= 8'h65;
		4'hf: out_char <= 8'h66;
		default:
			out_char <= 8'hff;
	endcase
end



//todo prevest 4 bitove slovo na 8 bitove
// a o jednu periodu pozdeji poslat


assign i_stb_rise = i_stb & (~i_stb_old);

    
endmodule

//pokud je read(1.0000), tak se prenesou horni 2 ridici bity a zbytek jsou ctena data