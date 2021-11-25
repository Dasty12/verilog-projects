`include "uart_tx.sv"
`timescale 1ns/1ns


module uart_tx_tb;

reg clk = 0;
reg rst = 0;
reg [7:0] data;
wire Tx_done;
wire Tx_EN;
reg Tx_start;
wire OUT;
reg Tx_En_nTmp;
wire positive_edge;

reg [2:0]positive_edge_cnt = 3'd0;

reg[8:0] index = 9'd0;

reg[3:0] index_string = 4'd0;

wire [7:0] foo [0:15];
assign foo[0]  = "H";
assign foo[1]  = "e";
assign foo[2]  = "l";
assign foo[3]  = "l";
assign foo[4]  = "o";
assign foo[5]  = " ";
assign foo[6]  = "W";
assign foo[7]  = "o";
assign foo[8]  = "r";
assign foo[9]  = "l";
assign foo[10] = "d";
assign foo[11] = "!";
assign foo[12] = " ";
assign foo[13] = " ";
assign foo[14] = " ";
assign foo[15] = " ";
reg [7:0] char;

uart_txB Utx(.clk(clk), .rst(rst), .data(char), .Tx_start(Tx_start), .Tx_done(Tx_done), .Tx_EN(Tx_EN), .OUT(OUT));

always @(posedge clk) begin
    index <= index + 1;
    index_string <= index_string + 1;
    Tx_En_nTmp <= Tx_EN;
    if(positive_edge) begin
        char <= foo[index_string];
        positive_edge_cnt <= 3'd0;
    end


    if(positive_edge_cnt < 5)begin
        positive_edge_cnt <= positive_edge_cnt + 1;
        Tx_start <= 1;
    end
    else begin
        if(Tx_EN == 0) begin
            Tx_start <= 0;
        end
    end

end

/*always @(posedge Tx_En) begin
    char <= foo[index_string];
    Tx_start <= 1;
*/
assign positive_edge =~Tx_En_nTmp & Tx_EN;

always #5 clk = !clk;


initial begin

    #5 rst = 1;
    #5 rst = 0;

    $dumpfile("your_choice_of_name.vcd");
    $dumpvars;


end

initial begin
    #5000000 $finish;
end



endmodule