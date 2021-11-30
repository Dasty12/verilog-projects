`default_nettype none
`timescale 1ns / 1ps
`include "sine_table.sv"

module sine_table_tb;
    localparam SF = 2.0**-8.0;
    localparam ROM_DEPTH = 64;
    localparam ROM_WIDTH = 8;
    localparam ROM_FILE = "sine_table_64x8.mem";
    localparam ADDRW = $clog2(4*ROM_DEPTH);

    logic [ADDRW-1:0] id;
    logic signed [2*ROM_WIDTH-1:0] data;

    sine_table #(
        .ROM_DEPTH(ROM_DEPTH),
        .ROM_WIDTH(ROM_WIDTH),
        .ROM_FILE(ROM_FILE)
    ) sine_table_inst(
        .id,
        .data
    );

    initial begin
        #100 id = 0;
        #10 $display("%d = %b (%f)",id, data,$itor(data)*SF);


        #50 $finish();
    end

endmodule