module RL (
    input i_clk,
    input [7 : 0] epwmDCLim1,
    output reg [7:0] i_sim
);
parameter R_sim     = 0;
parameter L_div_sim = 0;
parameter dt_sim    = 0;

reg [7:0] di_sim = 0;


initial i_sim = 0;

always @(posedge i_clk) begin
    
end

endmodule