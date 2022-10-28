typedef enum logic [1:0] {
     add     = 2'h1,
     sub     = 2'h2,
     nop     = 2'h0
} operation_t /*verilator public*/;


module top_WbMaster
(
    input clk,
    input rst,
    
    input [33:0] in_WB_ctr_w,
    input  in_WB_o_cyc,
    
    inout [31:0] io_wb_data,
    output [31:0] o_wb_addr,
    output    o_wb_we,
    output    o_wb_cyc,
    output    o_wb_stb,
    input     i_wb_stall,
    input     i_wb_ack

);

WbMaster WBM (.clk(clk), 
              .rst(rst), 
              
              .in_WB_ctr_w(in_WB_ctr_w), 
              .in_WB_o_cyc(in_WB_o_cyc), 
              
              .io_wb_data(io_wb_data),
              .o_wb_addr(o_wb_addr),
              .o_wb_we(o_wb_we),
              .o_wb_cyc(o_wb_cyc),
              .o_wb_stb(o_wb_stb),
              .i_wb_stall(i_wb_stall),
              .i_wb_ack(i_wb_ack));
endmodule