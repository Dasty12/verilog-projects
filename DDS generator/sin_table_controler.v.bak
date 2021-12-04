`include "sine_table.v"

module sin_table_controler #(
    parameter ROM_WIDTH = 8
)(
    input clk,      //100Mhz
    input rst,
    output[2*ROM_WIDTH-1:0] data,
    output o_ce 
);

parameter ROM_DEPTH = 64;
parameter kCOUNT = 39;   // 100MHz/256kHz

reg[$clog2(4*ROM_DEPTH)-1:0] id = 0;
//wire [2*ROM_WIDTH-1:0] data;

reg[$clog2(kCOUNT)-1:0] DDS_counter = 0;
reg o_ce_r = 0;

always @(posedge clk) begin
    if(DDS_counter < kCOUNT) begin
        DDS_counter <= DDS_counter + 1;
        o_ce_r <= 0;
    end else begin
        DDS_counter <= 0;
        o_ce_r <= 1;
        id <= id + 1;
    end

end

sine_table #(
    .ROM_DEPTH(ROM_DEPTH),
    .ROM_WIDTH(ROM_WIDTH)
)s_table_inst (
    .id(id),
    .data(data)
);

assign o_ce = o_ce_r;

endmodule