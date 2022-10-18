module top_wbMaster
{
    input clk, 
    input rst,

    //data z Uart2wb 
    input [33:0] in_WB_ctr_w,
    input        in_WB_o_cyc,


    //prikazi pri slavy
    inout [31:0]  io_wb_data,
    output [31:0] o_wb_addr,
    output        o_wb_we,  //write enable (write=1,read=0)
    output        o_wb_cyc,
    output        o_wb_stb,
    input         i_wb_stall,
    input         i_wb_ack
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

reg [31:0] ro_wb_addr;

always @(posedge clk) begin
    if(i_cmd_addr)
        ro_wb_addr <= in_WB_ctr_w[31:0];
end

assign o_wb_addr = ro_wb_addr;



reg ro_wb_cyc;
reg ro_wb_stb;
reg ro_wb_we;

reg [31:0] rio_wb_data;

always @(posedge clk)begin

    if(!ro_wb_cyc && !ro_wb_stb) begin
        if(i_WB_bus)begin
            ro_wb_cyc <= 1;
            ro_wb_stb <= 1;
            ro_wb_we <= i_cmd_wr;
        end
    end 
    else begin
        ro_wb_stb <= 0; //strobe se nastavuje vzdycky o periodu dele
        if(i_wb_ack) begin  //cyc az ve chvili kdy prijde ack
            ro_wb_cyc <= 0;
        end
    end
end

always @(posedge clk) begin
    if(i_wb_ack && !i_cmd_wr)   //i_cmd_mozna uz tou dobou bude v nule
        rio_wb_data <= io_wb_data;
    else
        rio_wb_data <= in_WB_ctr_w[31:0]; //todo nebo misto toho pouzit ro_wb_addr
end

assign o_wb_cyc = ro_wb_cyc;
assign o_wb_stb = ro_wb_stb;
assign o_wb_we = ro_wb_we;

assign io_wb_data = (ro_wb_we) ? rio_wb_data: 32'hZZZZ_ZZZZ;    // pri zapisu se posle hodnota regu, jinak vysoka impedance


endmodule