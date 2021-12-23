

/*
    -nDQM -- these pins are connected to byte enables

*/



module EMIF_top (
    input inclk0,           // 25 Mhz vstupni frekvence z desky
    input EMIF_nCS3,        /*Active-low chip enable pins for asynchronous devices */
    input EMIF_nCS4,
    input EMIF_nWE,         /*Active-low write enable*/
    input EMIF_nOE,         /*Active-low pin enable for asynchronous devices*/
    input [1:0]  EMIF_nDQM, /*Active-low byte enables*/
    input [21:0] EMIF_A,    /*adresy*/
    input [1:0]  EMIF_BA,   /*bank address*/
    inout [15:0] EMIF_D,    /*data*/
    output EMIF_nWAIT,       /*Wait input with programmable polarity*/


    output HET2_2,
    output HET2_4,
    output HET2_8,
    output HET2_10
);


parameter kdiv_clk =  250000;
reg[$clog2(kdiv_clk)-1:0] div_cnt;


parameter kRAM_length = 128;
parameter kRAM_bits = $clog2(kRAM_length) - 1;

reg [15:0] ram [kRAM_length];
reg [23:0]realAddress;
reg [kRAM_bits:0] maskAddress_8;
reg [23:0] maskAddress;


reg [15:0] r_EMIF_D; 


reg r_HET2_2=0;
reg r_HET2_4=1;
reg r_HET2_8;
reg r_HET2_10=1;
reg speed_dir1 = 0;


reg areset = 0;
reg c0;
reg locked = 0;


reg [15:0] ram_copy;
reg [15:0] ram_3_copy;
reg [15:0] ram_123_copy;
initial begin
    ram[0] = 0;
end


wire nic1;
wire nic2;
reg rst = 0;
integer i;

speed speed_mod(.clk(inclk0),
                .sq(ram[60]),
                .dir(speed_dir1),
                .A(HET2_2),
                .B(HET2_4),
					 .rst(rst));

PLL1 pll (
				.areset(areset),
				.inclk0(inclk0),
				.c0(c0),
				.locked(locked));


always @(posedge c0) begin
    if(EMIF_nCS3 == 0)begin
    //{{
        maskAddress   <= {{(kRAM_bits + 1){1'b0}}, EMIF_A[kRAM_bits - 1 : 0], EMIF_BA[1]};
        maskAddress_8 <= {EMIF_A[kRAM_bits - 1 : 0], EMIF_BA[1]};
        realAddress   <= {EMIF_BA[0], EMIF_A, EMIF_BA[1]};

        if(maskAddress == realAddress)begin
            if(EMIF_nOE == 0) begin /*read from FPGA*/
                r_EMIF_D <= ram[maskAddress_8];
            end else if(EMIF_nWE == 0) begin /*write to FPGA*/    
                ram[maskAddress_8] <= EMIF_D;
            end else begin
                r_EMIF_D <= 16'bZ;
            end 

        end else begin
            r_EMIF_D <= 16'bZ;
        end

	ram[0] <= ram_copy;
	ram[4] <= ram_3_copy;
	ram[70]<= ram[60];
/*	for(i = 5;i< 128;i = i + 1)begin
		ram[i] <= i;
	end
*/
    //}}
    end else begin  
        r_EMIF_D <= 16'bZ;  
    end
end




always @(posedge inclk0) begin
    if(div_cnt < kdiv_clk)begin
        div_cnt <= div_cnt + 1;
    end else begin
        div_cnt <= 0;
  /*      r_HET2_2  <= !r_HET2_2;
        r_HET2_4  <= !r_HET2_4;
        r_HET2_8  <= !r_HET2_8;
        r_HET2_10 <= !r_HET2_10;
    */	ram_copy <= ram_copy + 1;
    end
	 

	
end



always @(posedge c0) begin

	

end


assign EMIF_D  = r_EMIF_D;
assign HET2_8 = r_HET2_8;
assign HET2_10 = r_HET2_10;



endmodule