module wb_1 (
    input        i_rst,
    input        i_cmd_stb,   // aktivuje slave
    input [33:0] i_cmd_word,
    output reg   o_cmd_busy   // odpovida masteru, zdali je pripraven odpovidat
);
    
endmodule