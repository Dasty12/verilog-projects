module WB_slave (
    input         i_clk,
    input         i_wb_cyc,
    input         i_wb_stb,
    input         i_wb_we,
    input [29:0]  i_wb_addr,
    input [31:0]  i_wb_data,
    input [3:0]   i_wb_sel,

    output reg    o_wb_stall,
    output reg    o_wb_ack,
    output        o_wb_err,
    output [31:0] o_wb_data
);

initial o_wb_stall = 1'b0;



always @(posedge i_clk) begin
    if((i_wb_cyc)&&(i_wb_stb)) begin
        o_wb_ack <= 1;
    end else begin
        o_wb_ack <= 0;
    end

end
    
endmodule