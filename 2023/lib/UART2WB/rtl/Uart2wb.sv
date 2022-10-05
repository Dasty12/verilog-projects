module Uart2wb 
(
    input clk,
    input rst,
    input [7:0] UART_in_data,
    input UART_rx_done
);

reg[3:0] asciiToBits;

always @(posedge clk) begin

    if(UART_rx_done)begin
        case(UART_in_data[6:0])
        7'h30: asciiToBits <= 0;
        7'h31: asciiToBits <= 1;
        7'h32: asciiToBits <= 2;
        7'h33: asciiToBits <= 3;
        7'h34: asciiToBits <= 4;
        7'h35: asciiToBits <= 5;
        7'h36: asciiToBits <= 6;
        7'h37: asciiToBits <= 7;
        7'h38: asciiToBits <= 8;
        7'h39: asciiToBits <= 9;
        7'h52: asciiToBits <= 10; //R
        7'h57: asciiToBits <= 11; //W
        7'h41: asciiToBits <= 12; //A
        7'h53: asciiToBits <= 5'h13; //S
        7'h54: asciiToBits <= 5'h16;
    end
end


endmodule