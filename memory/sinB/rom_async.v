`include "mem.v"
module rom_async #(
    parameter WIDTH = 8,
    parameter DEPTH = 256,
    parameter INIT_F="",
    localparam ADDRW =$clog2(DEPTH)
) (
    input wire logic clk,
    input wire logic [ADDRW-1:0]addr,
    output  [WIDTH-1:0]data
);

logic [WIDTH - 1:0] memory [DEPTH];
reg[7:0] mem_r[64];
reg[7:0] mem_rr;
reg[7:0] fifo;

//mem mem_inst(clk,mem_r);

//assign data = mem_r[addr];
always @(posedge clk) begin
    fifo <= mem_r[addr];
end
integer fd;
integer index = 0;
initial begin
 $readmemh("sine_table_64x8.mem", mem_r);

end

assign data = fifo;

endmodule