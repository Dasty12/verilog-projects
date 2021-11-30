`include "rom_async.sv"
`timescale 1ns/1ns
module rom_async_tb;

parameter ROM_DEPTH = 64;
parameter ROM_WIDTH = 8;
parameter ROM_FILE ="sine_table_64x8.mem";
parameter ADDRW = $clog2(4*ROM_DEPTH);

reg clk = 0;
reg rst = 0;

wire logic [ADDRW-1:0] id;
logic signed[2*ROM_WIDTH-1:0] data;
logic unsigned[10:0]ale_nic;
logic unsigned[10:0] ale_nic_2 = 56;

logic [$clog2(ROM_DEPTH)-1:0] tab_id;
logic [ROM_WIDTH-1:0] tab_data;


rom_async#(
    .WIDTH(ROM_WIDTH),
    .DEPTH(ROM_DEPTH),
    .INIT_F(ROM_FILE)
) sine_rom(
    .addr(tab_id),
    .data(tab_data)
);






initial begin
    ale_nic = {{5{1'b0}},{5{1'b1}}};
    #5 rst = 1;
    #5 rst = 0;


    tab_id = 10;

    $dumpfile("rom_async_tb_waves.vcd");
    $dumpvars;
    $display("hodnota: %b",ale_nic);
end

always #5 clk = !clk;



initial begin
    #5000000 $finish;
end

    
endmodule