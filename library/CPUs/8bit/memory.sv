module memory (
    input clk,
    input [7:0] address_bus,
    input write_enable,
    input [7:0] from_cpu,
    output [7:0] to_cpu
    );

reg [7:0] RAM [128];
reg [7:0] ROM [128];


reg [7:0] r_to_cpu;


always @(*) begin
    if(address_bus[7] == 0)begin
        r_to_cpu = RAM[address_bus[6:0]];
    end else begin
        r_to_cpu = ROM[address_bus[6:0]];
    end
end


always @(posedge clk) begin
    if(write_enable) begin
        RAM[address_bus[6:0]] <= from_cpu;
    end
end


assign to_cpu = r_to_cpu;


integer i = 0;


initial begin

for(i=0;i<128;i++) begin
    RAM[i] = 0;
    ROM[i] = 0;
end

/*<HERE>*/

end


endmodule