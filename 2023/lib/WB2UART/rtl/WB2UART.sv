module WB2UART
(
    input clk,
    input rst,
    
    //prikazy z mastera
    /* verilator lint_off UNUSED */
    input [33:0] in_WB2UART_word,
    input        in_WB2UART_cyc,

    //prikazi pro UartTx transmitera (lib/UART/rtl/UartTx.sv)
    /* verilator lint_off UNDRIVEN */
    output [7:0] out_DataByte,  // pozadovane pismeno k odeslani
    output       out_Start,     // pozadavek pro odeslani dalsiho pisnema
    input        in_fComplete   // prenos pismene, hotov
);

reg[3:0] index;
reg ted;
reg in_fComplete_old;
wire in_fComplete_r;

always @(posedge clk) begin
    ted <= 0;
    if(rst) begin
        index <= 0;
        in_fComplete_old <= 0;
    end else begin
        if(in_WB2UART_cyc) begin
            index <= 8;  
            ted <= 1;     
        end
    end

    if((in_fComplete_r || ted) && (index > 0)) begin

        index <= index - 1;
    end

    in_fComplete_old <= in_fComplete;
end

assign in_fComplete_r = in_fComplete & (~in_fComplete_old);


endmodule