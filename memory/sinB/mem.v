module mem (
    output [7:0] memory[64]
);
    
reg [7:0] memory_r[64];


initial begin
    memory_r[0]=125;
    memory_r[1]=165;
	memory_r[3]=165;
	memory_r[4]=165;
end


endmodule