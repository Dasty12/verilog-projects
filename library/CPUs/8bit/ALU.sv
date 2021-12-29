`define OP_ZERO     4'h0
`define OP_LOAD_A   4'h1
`define OP_INC      4'h2
`define OP_DEC      4'h3
`define OP_ASL      4'h4
`define OP_LSR      4'h5
`define OP_ROL      4'h6
`define OP_ROR      4'h7
`define OP_OR       4'h8
`define OP_AND      4'h9
`define OP_XOR      4'ha
`define OP_LOAD_B   4'hb
`define OP_ADD      4'hc
`define OP_SUB      4'hd
`define OP_ADC      4'he
`define OP_SBB      4'hf


module ALU #(parameter N = 8)
(
    input [N-1:0] A,
    input [N-1:0] B,
    input carry,
    input [3:0] aluop,
    output wire [N:0] Y          
);

reg [N:0] r_Y;


always @(*) begin
    case(aluop)
        `OP_ZERO:       r_Y = 0;
        `OP_LOAD_A:     r_Y = {1'b0, A};
        `OP_INC:        r_Y = A + 1;
        `OP_DEC:        r_Y = A - 1;

        `OP_ASL:        r_Y = {A, 1'b0};
        `OP_LSR:        r_Y = {A[0], 1'b0, A[N-1:0]};
        `OP_ROL:        r_Y = {A,carry};
        `OP_ROR:        r_Y = {A[0],carry,A[N-1:1]};

        `OP_OR:         r_Y = {1'b0, A | B};
        `OP_AND:        r_Y = {1'b0, A & B};
        `OP_XOR:        r_Y = {1'b0, A ^ B};
        `OP_LOAD_B:     r_Y = {1'b0, B};

        `OP_ADD:        r_Y = A + B;
        `OP_SUB:        r_Y = A - B;
        `OP_ADC:        r_Y = A + B + (carry ? 1:0);
        `OP_SBB:        r_Y = A - B - (carry ? 1:0);
    endcase
end


assign Y = r_Y;


    
endmodule