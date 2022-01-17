`timescale 1ns/1ns


module wishbone_top_tb;
    
reg clk = 0;
reg i_reset = 0; 

wire IO_UART_RX;
wire IO_UART_TX;


reg [7:0] test_DataByte = 8'b0;

reg test_in_signal;
reg test_in_RXNE_clear;
wire [7:0]test_out_word;
wire out_RXNE;
wire test_out_Rx_ORE;
reg test_in_valid;
wire test_out_BUSY;

reg [21:0] wait_counter = 0;
reg [21:0] kwait_counter = 20000;

reg[9:0] afterStart_cnt = 1000;


reg[7:0] ram[6] = {8'h41, 8'h33 ,8'h34 ,8'h31 ,8'h30 ,8'h52};
reg[2:0] ram_counter = 0;






wishbone_top DUT(.i_clk_12Mhz(clk),
                 .IO_UART_RX(IO_UART_RX),
                 .IO_UART_TX(IO_UART_TX));



UartTop UART_test(.clk(clk),
                  .in_w_data(test_DataByte),
                  .in_valid(test_in_valid),
                  .out_BUSY(test_out_BUSY),
                  .out_signal(IO_UART_RX),
                  
                  .in_signal(test_in_signal),
                  .in_RXNE_clear(test_in_RXNE_clear),
                  .out_word(test_out_word),
                  .out_RXNE(out_RXNE),
                  .out_Rx_ORE(test_out_Rx_ORE));






always @(posedge clk) begin
    if(afterStart_cnt > 0) 
        afterStart_cnt <= afterStart_cnt - 1;
end


always @(posedge clk) begin

    test_in_valid <= 0;

    if(test_out_BUSY == 0) begin
        if(wait_counter < (kwait_counter - 1)) begin
            wait_counter <= wait_counter + 1;
            test_DataByte <= ram[ram_counter];
        end else begin
            wait_counter <= 0;
           if(ram_counter < (6-1)) begin
                ram_counter <= ram_counter + 1;

            end else begin
                ram_counter <= 0;
            end

            test_in_valid <= 1;

       end
    end


    if(afterStart_cnt == 1)
        test_in_valid <= 1;
end





always #5 clk = !clk;

initial begin
    $dumpfile("wishboneWaves.vcd"); 
    $dumpvars;
end

/*
initial begin
    #5000000 $finish;
end
*/
endmodule