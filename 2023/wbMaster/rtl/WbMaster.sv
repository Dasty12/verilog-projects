module top_wbMaster
{
    input clk, 
    input rst,

    //data z Uart2wb 
    input [33:0] in_WB_ctr_w,
    input        in_WB_o_cyc,


    //prikazi pri slavy
    inout [31:0]  o_wb_data,
    output [31:0] o_wb_addr,
    output        o_wb_we,  //write enable (write=1,read=0)
    output        o_wb_cyc,
    output        o_wb_stb,
    input         i_wb_stall
};

reg i_cmd_rd;       // prikaz je read
reg i_cmd_wr;       // prikaz je write
reg i_cmd_bus;      // prikaz je write nebo read
reg i_cmd_addr;     // prikaz je addresa
reg i_cmd_special;  // prikaz je specialni instrukce

wire [1:0] i_WB_cmd;


assign i_WB_cmd = in_WB_ctr_w[33:32];


always @(posedge clk)begin
    if(rst == 1) begin
        i_cmd_rd <= 0;
        i_cmd_wr <= 0;
        i_cmd_bus <= 0;
        i_cmd_addr <= 0;
        i_cmd_special <= 0;
    end else begin
        if(in_WB_o_cyc == 1) begin
            if(i_WB_cmd == 0) i_cmd_rd <= 1;
            else i_cmd_rd <= 0;

            if(i_WB_cmd == 1) i_cmd_wr <= 1;
            else i_cmd_wr <= 0;

            if(i_WB_cmd == 2) i_cmd_addr <= 1;
            else i_cmd_addr <= 0;

            if(i_WB_cmd[1]==0) i_cmd_bus <= 1;
            else i_cmd_bus <= 0;
        end
    end
end

endmodule