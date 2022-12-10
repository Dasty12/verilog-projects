module NixieTube(
    input clk,
    input rst,
    output [7:0] Nixie_AtoH,
    input [4:0] input_bits
);


reg [7:0] Nixie_AtoH_r = 0;

always @(posedge clk) begin
    case(input_bits)
        0 : Nixie_AtoH_r <= ~(0011_1111);
        1 : Nixie_AtoH_r <= ~(0000_0110);
        2 : Nixie_AtoH_r <= ~(0101_1011);
        3 : Nixie_AtoH_r <= 0100_1111;
        default : Nixie_AtoH_r <= 0000_0000;
    endcase;
end


assign Nixie_AtoH = Nixie_AtoH_r;

endmodule