module UartDecoder (
    input i_clk,
    input [7:0] i_data_in,
    input i_data_valid,
	
	//
    input i_stb, // True if something is valid on input
    output reg o_stb,
	output reg [33:0]  o_word
);

reg i_data_valid_old;
wire i_data_valid_rise;
reg r_i_data_valid_rise;
reg [4:0]o_bits;
reg i_stb_old;


//reg [3:0] o_bits_FIFO[8];
//reg [33:0] o_word;
reg [33:0] r_word;
reg[2:0] array_count;
reg [2:0] command;
reg cmd_loaded;

initial o_word[33:32] = 2'b11;
initial cmd_loaded = 1'b0;

always @(posedge i_clk) begin
    
    i_data_valid_old <= i_data_valid;
end


always @(posedge i_clk) begin
    case(i_data_in[6:0])
        7'h30: o_bits <= 5'h00;
        7'h31: o_bits <= 5'h01;
        7'h32: o_bits <= 5'h02;
        7'h33: o_bits <= 5'h03;
        7'h34: o_bits <= 5'h04;
        7'h35: o_bits <= 5'h05;
        7'h36: o_bits <= 5'h06;
        7'h37: o_bits <= 5'h07;
        7'h38: o_bits <= 5'h08;
        7'h39: o_bits <= 5'h09;

        7'h61: o_bits <= 5'h0a;
        7'h62: o_bits <= 5'h0b;
        7'h63: o_bits <= 5'h0c;
        7'h64: o_bits <= 5'h0d;
        7'h65: o_bits <= 5'h0e;
        7'h66: o_bits <= 5'h0f;

        //other characters set out of band information (o_bits[4])
        //instrukce 
        7'h52: o_bits <= 5'h10;     // 'R', or read command
        7'h57: o_bits <= 5'h11;     // 'W', or write command
        7'h41: o_bits <= 5'h12;     // 'A', set address
        7'h53: o_bits <= 5'h13;     // 'S', "special".. reserved for later
        7'h45: o_bits <= 5'h14;     // 'E' značí konec slova napr. A20W1E [tohle ale nepatri do - b100]
        7'h54: o_bits <= 5'h16;     // 'T', --set for from only

        default://an "other" character, to be subsequently ignored.
                // Also used as an end of word character, if received
            o_bits <= 5'h1f;    
    endcase
end



initial o_word[31:0] = 0;
always @(posedge i_clk) begin

    if(i_stb) begin
		r_i_data_valid_rise <= 1;
    
    //new command arrived
        if(o_bits[4:2] == 3'b100) begin  
            array_count <= 0;
            command <= o_bits[2:0];
           
            cmd_loaded <= 1'b1;
            r_word[33:32] <= o_bits[1:0];
            r_word[31:0] <= 0;
			
        end else if(o_bits != 5'h1f) begin
           array_count <= array_count + 1;
           r_word[31:0] <= {r_word[27:0],o_bits[3:0]};
           cmd_loaded <= 1'b0;
           
        end else begin
            /*chyba tohle se nema stat*/
            array_count <= 0;
            cmd_loaded <= 1'b0;
        end
    end else begin
		r_i_data_valid_rise <= 0;
	end

end

always @(posedge i_clk) begin
    o_stb <= (i_stb) && (cmd_loaded) && (o_bits[4]);
end

always @(posedge i_clk)begin
	if(i_stb) begin
		o_word <= r_word;
	end
	
end
reg[33:0]testovaci = 0;
always @(posedge i_clk) begin
	
	if(o_stb)
			testovaci <= o_word;
	
	
	i_stb_old <= i_stb;
end



assign i_data_valid_rise = i_data_valid & (~i_data_valid_old);

    
endmodule