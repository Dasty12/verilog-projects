module rom_async#(
    parameter WIDTH = 8,
    parameter DEPTH = 256,
    parameter INIT_F = "",
    localparam ADDRW = $clog2(DEPTH)
) (
    input [ADDRW-1:0] addr,
    output [WIDTH-1:0] data
);
    
reg [WIDTH-1:0] memory_r[DEPTH];

initial begin
    if(INIT_F != 0)begin
        $display("Creating rom_async from init file '%s'.", INIT_F);
        $readmemh(INIT_F, memory_r);
    end 
end
assign data = memory_r[addr];

endmodule