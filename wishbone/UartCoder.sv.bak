module UartCoder (
    input i_clk,
    input i_reset,
    input i_stb,
    output o_dw_busy,
    input [33:0] i_word,
    output [7:0] out_char
);


always@(posedge i_clk) begin
	if(i_word[33:32] == 2'b0) begin//todo read instrukce 
			//čte se, dokud neni zakoncovaci znak nebo jina instrukce
	end
end

    
endmodule

//pokud je read(1.0000), tak se prenesou horni 2 ridici bity a zbytek jsou ctena data