module Uart2wb 
(
    input clk,
    input rst,
    /* verilator lint_off UNUSED */
    input [7:0] UART_in_data,
    input UART_rx_done,
    output [33:0] WB_ctr_w,
    output WB_o_cyc
);

reg[4:0] asciiToBits;
reg UART_rx_done_1p;

always @(posedge clk) begin
    if (rst == 1) begin
    end else begin

        if(UART_rx_done)begin
            case (UART_in_data[6:0])
            7'h30: asciiToBits <= 5'h00;
            7'h31: asciiToBits <= 5'h01;
            7'h32: asciiToBits <= 5'h02;
            7'h33: asciiToBits <= 5'h03;
            7'h34: asciiToBits <= 5'h04;
            7'h35: asciiToBits <= 5'h05;
            7'h36: asciiToBits <= 5'h06;
            7'h37: asciiToBits <= 5'h07;
            7'h38: asciiToBits <= 5'h08;
            7'h39: asciiToBits <= 5'h09;
            7'h61: asciiToBits <= 5'h0a;
            7'h62: asciiToBits <= 5'h0b;
            7'h63: asciiToBits <= 5'h0c;
            7'h64: asciiToBits <= 5'h0d;
            7'h65: asciiToBits <= 5'h0e;
            7'h66: asciiToBits <= 5'h0f;
            7'h52: asciiToBits <= 5'h10; // R
            7'h57: asciiToBits <= 5'h11; // W
            7'h41: asciiToBits <= 5'h12; // A
            7'h53: asciiToBits <= 5'h13; // S
            7'h54: asciiToBits <= 5'h16; // T

            default:    //other character, are ignored
                        //nebo jako end of word character
                asciiToBits <= 5'h1f;
            endcase
        end

        UART_rx_done_1p <= UART_rx_done;
    end
end

reg [33:0] WB_ctr_w_r;
reg [33:0] WB_ctr_w_o;
reg WB_o_cyc_r;



always @(posedge clk) begin
    WB_o_cyc_r <= 0;
    if(UART_rx_done_1p) begin   //priznak, dalsiho pismene z uartu, zpozdene o jednu peridou
        if(asciiToBits[4] == 1) begin   //prikazy R,W,A,S,T
            WB_o_cyc_r <= 1;    //pokud jsou to prikazy, odeslat soucasne hodnoty ulozene v WB_ctr_w_r dále
            WB_ctr_w_o <= WB_ctr_w_r;
            WB_ctr_w_r[33:32] <= asciiToBits[1:0]; //ale tohle neplati pro T, todo!!!! 
            WB_ctr_w_r[31:0] <= 0;
        end else begin
            WB_ctr_w_r[31:0] <= {WB_ctr_w_r[26:0],asciiToBits};  
        end
        
    end

end

assign WB_o_cyc = WB_o_cyc_r;
assign WB_ctr_w = WB_ctr_w_o;


endmodule