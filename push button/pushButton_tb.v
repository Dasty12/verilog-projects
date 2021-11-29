`include "pushButton.v"
`timescale 1ns/1ns

module pushButton_tb;
reg clk = 0;
reg rst;
wire button_fil;
reg button =0;


always #5 clk = !clk;
wire posEdge_detect;
wire falEdge_detect;

pushButton pushbutton(
    .clk(clk),
    .sig_IN(button),
    .posEdge_detect(posEdge_detect),
    .falEdge_detect(falEdge_detect)
);

initial begin
    #100 button = 1;
    #600 button = 0;
end


initial begin

    #5 rst = 1;
    #5 rst = 0;


    $dumpfile("pushbutton_waves.vcd");
    $dumpvars;


end

initial begin
    #5000000 $finish;
end






endmodule