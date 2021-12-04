module PWM_controler #(
    parameter ROM_WIDTH = 8
)(
    input  clk,
    input  i_ce,
    output o_ce,
    input [2*ROM_WIDTH-1:0]data_in
);

reg [2*ROM_WIDTH-1:0] data_ted;

always @(posedge i_ce) begin
    data_ted <= data_in;
end
    
endmodule