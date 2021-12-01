`timescale 1ns/1ns
`include "sine_table.v"
module sine_table_tb;
    
reg clk = 0;
reg rst = 0;

parameter ROM_WIDTH = 8;
parameter ROM_DEPTH = 64;


reg[$clog2(4*ROM_DEPTH)-1:0] id;
reg[2*ROM_WIDTH-1:0] data;

reg[$clog2(4*ROM_DEPTH)-1:0] cnt_id = 0;

sine_table #(
    .ROM_DEPTH(ROM_DEPTH),
    .ROM_WIDTH(ROM_WIDTH)
)sine_table_inst(
    .id(id),
    .data(data)
);


always @(posedge clk) begin
    if(id < (4*ROM_DEPTH))begin
        cnt_id <= cnt_id + 1;
        id <= id + 1;
    end else begin
        id <= 0;
    end
end

reg signed[2*ROM_WIDTH-1:0] test;
reg[ROM_WIDTH-1:0] tab_dataa = 55;
initial begin
  //  ale_nic = {{5{1'b0}},{5{1'b1}}};
    #5 rst = 1;
    #5 rst = 0;
    #5 test = {2*ROM_WIDTH{1'b0}} - {{ROM_WIDTH{1'b0}},tab_dataa};

    $display("tohle je ta hodnota %d",test);
    $dumpfile("rom_table_waves.vcd");
    $dumpvars;

end

always #5 clk = !clk;

initial begin
    #5000000 $finish;
end

endmodule
