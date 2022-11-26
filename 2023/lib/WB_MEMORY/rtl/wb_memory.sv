

module wb_memory
(
    input clk,
    input rst,

    input i_wb_we,  // write enable 
    input i_wb_cyc, // jde do nuly az o jednu periodu dele
    input i_wb_stb, //stb jde do nuly hned potom

    output o_wb_ack, //potvrzeni od tohoto

    inout [31 : 0] io_wb_data,
    input [31 : 0] i_wb_addr

);


reg read_enable;
reg ro_wb_ack;
reg[31:0] memory [0:63];

reg [31:0] rout_wb_data;

always @(posedge clk) begin
    if(rst == 1)begin
        rout_wb_data <= 0;
        read_enable <= 0;
        ro_wb_ack <= 0;
    end else begin
        if(i_wb_stb && i_wb_cyc && (i_wb_addr < 255)) begin
            if(i_wb_we) begin   //tady znamena cteni
                memory[i_wb_addr[5:0]] <= io_wb_data;
            end else begin
                rout_wb_data <= memory[i_wb_addr[5:0]];
            end

           /* if((i_wb_addr[31:6] == 0)) begin
                if(!i_wb_we) begin
                    read_enable <= 1;
                end*/
                ro_wb_ack <= 1;
            /*end else begin
                read_enable <= 0;
                ro_wb_ack <= 0;
            end*/



        end else if(ro_wb_ack) begin
            ro_wb_ack <= 0;
            read_enable <= 0;   
        end
    end 
end

assign o_wb_ack = ro_wb_ack;
assign io_wb_data = (read_enable) ? rout_wb_data : 32'hZZZZ_ZZZZ;



endmodule
