`include "uart_rx.sv"
`include "uart_txB.sv"
`timescale 1ns/1ns

module uart_rx_tb;

parameter KBAUD = 14'd10416;
parameter UART_CNT_BITS = $clog2(KBAUD);



reg clk = 0;
reg rst = 0;

wire data_IN;
reg [7:0]data_OUT;
reg [3:0]indexInChar = 0;
wire Rx_done;
wire busy; 

//testovaci data
wire [7:0] test_data=8'b10101010;


//UART tx
reg Tx_start;
wire Tx_done;
wire Tx_EN;
wire OUT;

reg [UART_CNT_BITS-1:0]  CNT_uart = 0;

uart_rx #(KBAUD) dut(.clk(clk),
            .rst(rst),
            .data_IN(OUT),
            .data_OUT(data_OUT),
            .Rx_done(Rx_done),
            .busy(busy));

uart_txB UartTx(.clk(clk),
               .rst(rst),
               .data(test_data),
               .Tx_start(Tx_start),
               .Tx_done(Tx_done),
               .Tx_EN(Tx_EN),
               .OUT(OUT));




always @(posedge clk) begin
    if (rst) begin
        Tx_start <= 0;
    end
    else begin
        if(CNT_uart < KBAUD) begin
            CNT_uart <= CNT_uart + 1;
        end
        else begin
            CNT_uart <= 0; 
            if (indexInChar < 7) begin
                indexInChar = indexInChar + 1;
                
            end
            else begin
                indexInChar = 0;
            end



            if(Tx_EN) begin
                Tx_start <= 1;
            end
            else begin
                Tx_start <= 0;
            end
        end
    end
end

assign data_IN = test_data[indexInChar];


always #5 clk = !clk;

initial begin
    #5 rst = 1;
    #5 rst = 0;

    
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end


initial begin
   #5000000 $finish;
end

endmodule