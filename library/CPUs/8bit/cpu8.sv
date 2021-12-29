`define DEST_A   2'b00
`define DEST_B   2'b01
`define DEST_IP  2'b10
`define DEST_NOP 2'b11 



/*
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

`define DEST_A   2'b00
`define DEST_B   2'b01
`define DEST_IP  2'b10
`define DEST_NOP 2'b11 

// instruction macros
`define I_COMPUTE(dest,op) {2'b00, (dest), (op)}
`define I_COMPUTE_IMM(dest,op) {2'b01, (dest), (op)}
`define I_COMPUTE_READB(dest,op) {2'b11, (dest), (op)}
`define I_CONST_IMM_A {2'b01, `DEST_A, `OP_LOAD_B}
`define I_CONST_IMM_B {2'b01, `DEST_B,`OP_LOAD_B}
`define I_JUMP_IMM {2'b01,`DEST_IP,`OP_LOAD_B}
`define I_STORE_A(addr) {4'b1001,(addr)}
`define I_BRANCH_IF(zv,zu,cv,cu) {4'b1010, (zv), (zu), (cv),(cu)}
`define I_CLEAR_CARRY{8'b10001000}
`define I_SWAP_AB{8'b10000001}
`define I_RESET {8'b10111111}

//convenience macros
`define I_ZERO_A `I_COMPUTE(`DEST_A, `OP_ZERO)
`define I_ZERO_B `I_COMPUTE(`DEST_B, `OP_ZERO)
`define I_BRANCH_IF_CARRY(carry) `I_BRANCH_IF(1'b0,1'b0,carry,1'b1)
`define I_BRANCH_IF_ZERO(zero) ` I_BRANCH_IF(zero,1'b1,1'b0,1'b0)
`define I_CLEAR_ZERO `I_COMPUTE(`DEST_NOP,`OP_ZERO)


*/



module cpu8 (
    input clk,
    input reset,
    input  [7:0] data_in,
    output [7:0] address,
    output [7:0] data_out,
    output write
);



localparam N = 8;

reg r_write;
reg [7:0] r_address;
reg [7:0] r_data_out;

reg [7:0] IP;
reg [7:0] A,B;
reg [8:0] Y;
reg [2:0] state;

reg carry;
reg zero;
wire [1:0] flags = {zero, carry};

reg [7:0] opcode;
wire [3:0] aluop = opcode[3:0];
wire [1:0] opdest = opcode[5:4];
wire B_or_data = opcode[6];

localparam S_RESET   = 0;
localparam S_SELECT  = 1;
localparam S_DECODE  = 2;
localparam S_COMPUTE = 3;
localparam S_READ_IP = 4;
    
ALU #(.N(N)) alu(
    .A(A),
    .B(B_or_data ? data_in :B),
    .Y(Y),
    .aluop(aluop),
    .carry(carry)
);

always @(posedge clk) begin
    if(reset) begin
        state <= 0;
        r_write <= 0;
    end else begin
        case(state)
        S_RESET:begin
            IP <= 8'h80;
            r_write <= 0;
            state <= S_SELECT;
        end
        S_SELECT:begin //select opcode address
            r_address <= IP;
            IP <= IP + 1;
            r_write <= 0;
            state <= S_DECODE;
        end
        S_DECODE:begin  //read/decode opcode
            opcode <= data_in;
            casez(data_in)
                8'b00??????:begin   //ALU A + B -> dest
                    state <= S_COMPUTE;
                end
                8'b01??????:begin   //ALU A + immediate -> dest
                    r_address <= IP;
                    IP <= IP + 1;
                    state <= S_COMPUTE;
                end
                8'b11??????:begin   //ALU A + read[B] -> dest
                    r_address <= B;
                    state <= S_COMPUTE;
                end
                8'b1001????:begin   // A -> write[nnnn]
                    r_address <= {4'b0, data_in[3:0]};
                    r_data_out <= A;
                    r_write <= 1;
                    state <= S_SELECT;
                end
                8'b10000001:begin //swap A,B
                    A <= B;
                    B <= A;
                    state <= S_SELECT;
                end
                8'b1010????:begin //conditional branch
                    if((data_in[0] && (data_in[1] == carry)) ||             //branch if carry set/clear
                       (data_in[2] && (data_in[3] == zero))) begin          //branch if zero set/clear
                        r_address <= IP;
                        state <= S_READ_IP;
                    end else begin
                        state <= S_SELECT;
                    end
                    IP <= IP + 1; //skip immediate
                end
            default:begin
                state <= S_RESET;
            end
            endcase
        end
        S_COMPUTE:begin //compute ALU op and flags
            case(opdest)
                `DEST_A: A   <= Y[7:0];
                `DEST_B: B   <= Y[7:0];
                `DEST_IP: IP <= Y[7:0];
                `DEST_NOP: ;
            endcase

            if(aluop[2]) carry <= Y[8];
            //set zero flag
            zero <= ~|Y[7:0];

            state <= S_SELECT;
        end
        S_READ_IP:begin
            IP <= data_in;
            state <= S_SELECT;
        end
        endcase
    end
end

assign write = r_write;
assign address = r_address;
assign data_out = r_data_out;

endmodule 