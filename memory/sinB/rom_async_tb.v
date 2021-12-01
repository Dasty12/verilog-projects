`include "rom_async.v"
`timescale 1ns/1ns
module rom_async_tb;

parameter ROM_DEPTH = 64;
parameter ROM_WIDTH = 8;
parameter ROM_FILE ="sin_table_64x8.mem";
parameter ADDRW = $clog2(4*ROM_DEPTH);
parameter CNT_div = 10;

reg[$clog2(ROM_DEPTH)-1:0] CNT_data = 0;
reg[$clog2(CNT_div)-1:0] CNT = 0;

reg clk = 0;
reg rst = 0;

wire logic [ADDRW-1:0] id;
logic signed[2*ROM_WIDTH-1:0] data;
logic unsigned[10:0]ale_nic;
logic unsigned[10:0] ale_nic_2 = 56;

reg [$clog2(ROM_DEPTH)-1:0] tab_id;
reg [ROM_WIDTH-1:0] tab_data;


rom_async#(
    .WIDTH(ROM_WIDTH),
    .DEPTH(ROM_DEPTH),
    .INIT_F(ROM_FILE)
) sine_rom(
    .clk(clk),
    .addr(tab_id),
    .data(tab_data)
);



always @(posedge clk) begin
    if(CNT < CNT_div) begin
        CNT <= CNT + 1;
    end else begin
        CNT <= 0;
        if(CNT_data < ROM_DEPTH) begin
            tab_id <= CNT_data;
            CNT_data <= CNT_data + 1;
        end
    end

end


initial begin
    ale_nic = {{5{1'b0}},{5{1'b1}}};
    #5 rst = 1;
    #5 rst = 0;


   // tab_id = 10;

    $dumpfile("rom_async_tb_waves.vcd");
    $dumpvars;
    $display("hodnota: %b",ale_nic);
end

always #5 clk = !clk;



initial begin
    #5000000 $finish;
end

    
endmodule