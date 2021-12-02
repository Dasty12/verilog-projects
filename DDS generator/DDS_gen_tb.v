`timescale 1ns/1ns
`include "sin_table_controler.v"
`include "PWM_controler.v"
module DDS_gen_tb;

parameter ROM_WIDTH = 8;

reg clk = 0;
reg rst = 0;
reg o_ce_1;     //vystup z SIN_TABLE
reg i_ce_2;     //vstup do PWM generatoru
reg o_ce_2;     //vystup z PWM generatoru
wire[2*ROM_WIDTH-1:0] data_sin_table;   //DATA ze sin table


sin_table_controler #(ROM_WIDTH) inst(.clk(clk),.rst(rst),.o_ce(o_ce_1),.data(data_sin_table));
PWM_controler #(ROM_WIDTH) PWM_contr_inst(.clk(clk), .i_ce(o_ce_1), .o_ce(o_ce_2), .data_in(data_sin_table));

initial begin
    #5 rst = 1;
    #5 rst = 0;

    $dumpfile("WAVES.vcd");
    $dumpvars;

end

always #5 clk = !clk;

initial begin
    #5000000 $finish;
end


endmodule