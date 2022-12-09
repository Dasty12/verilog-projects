typedef enum logic [1:0] {
     add     = 2'h1,
     sub     = 2'h2,
     nop     = 2'h0
} operation_t /*verilator public*/;


module top_sdpll(
    input clk,
    input rst,
    input ld,
    input [30:0] step,
    input ce,
    input i_input,
    input [4:0] lgcoeff,
    

    output [31:0] phase,
    output [1:0]err,
    output [13:0] dbg
);


sdpll dut(
    .i_clk(clk),
    .i_ld(ld),
    .i_step(step),
    .i_ce(ce),
    .i_input(i_input),
    .i_lgcoeff(lgcoeff),
    .o_phase(phase),
    .o_err(err),
    .o_dbg(dbg)

);



endmodule

