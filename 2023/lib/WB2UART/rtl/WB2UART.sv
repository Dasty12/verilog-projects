module WB2UART
(
    input clk,
    input rst,
    
    //prikazy z mastera
    /* verilator lint_off UNUSED */
    input [33:0] in_WB2UART_word,
    input        in_WB2UART_cyc,
    output       out_WB2UART_stall, /*signál aktivního přenosu*/

    //prikazi pro UartTx transmitera (lib/UART/rtl/UartTx.sv)
    /* verilator lint_off UNDRIVEN */
    output [7:0] out_DataByte,  // pozadovane pismeno k odeslani
    output       out_Start,     // pozadavek pro odeslani dalsiho znaku
    input        in_fComplete   // pismeno bylo uspesne prenesene
);

reg[3:0] index;
reg ted;
reg in_fComplete_old;
wire in_fComplete_r;
reg r_fComplete_r_old;

reg [4:0] Rout_DataByte;
reg [31:0] regInWord;
reg test2;
reg rOut_Start;

reg r_WB2UART_stall;


always @(posedge clk) begin
    ted <= 0;
    test2 <= 0;
    rOut_Start <= 0;
    if((rst) || (in_WB2UART_word[33:32] == 3)) begin
        index <= 0;
        in_fComplete_old <= 0;
        regInWord <= 0;
        r_WB2UART_stall <= 0;
        r_fComplete_r_old <= 0;

        
    end else begin
        if(in_WB2UART_cyc) begin
            index <= 8;     //1 řídící + 8 datovych znaků
            Rout_DataByte[4:4] <= 1;
            Rout_DataByte[0:0] <= in_WB2UART_word[32:32];
            Rout_DataByte[3:1] <= 0; 
            ted <= 1; 
            rOut_Start <= 1;
            r_WB2UART_stall <= 1;   
            regInWord <= in_WB2UART_word[31:0]; 
        end
    end

    if((in_fComplete_r) && (index > 0)) begin
        test2 <= 1;
        index <= index - 1;
        Rout_DataByte[4:4] <= 0;
        Rout_DataByte[3:0] <= regInWord[31:28];
        regInWord <= {regInWord[27:0],4'h0};
        rOut_Start <= 1;

    end

    if(index == 0 && (r_fComplete_r_old == 1)) begin
        r_WB2UART_stall <= 0;
    end

    in_fComplete_old <= in_fComplete;

    r_fComplete_r_old <= in_fComplete_r;
end

assign out_Start = rOut_Start;
assign out_WB2UART_stall = r_WB2UART_stall;

reg [6:0] out_DataByte2;

always @(ted or in_fComplete_r) begin
   // out_DataByte = 
    case(Rout_DataByte[4:0]) 
        5'h00: out_DataByte2 <= 7'h30;
        5'h01: out_DataByte2 <= 7'h31;
        5'h02: out_DataByte2 <= 7'h32;
        5'h03: out_DataByte2 <= 7'h33;
        5'h04: out_DataByte2 <= 7'h34;
        5'h05: out_DataByte2 <= 7'h35;
        5'h06: out_DataByte2 <= 7'h36;
        5'h07: out_DataByte2 <= 7'h37;
        5'h08: out_DataByte2 <= 7'h38;
        5'h09: out_DataByte2 <= 7'h39;
        5'h0a: out_DataByte2 <= 7'h61;
        5'h0b: out_DataByte2 <= 7'h62;
        5'h0c: out_DataByte2 <= 7'h63;
        5'h0d: out_DataByte2 <= 7'h64;
        5'h0e: out_DataByte2 <= 7'h65;
        5'h0f: out_DataByte2 <= 7'h66;

        5'h10: out_DataByte2 <= 7'h52;
        5'h11: out_DataByte2 <= 7'h57; 
default:
    out_DataByte2 <= 7'h14;
    endcase
end

assign out_DataByte[6:0] = out_DataByte2;





assign in_fComplete_r = in_fComplete & (~in_fComplete_old);
//assign out_DataByte = Rout_DataByte;

endmodule
