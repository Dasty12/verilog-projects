`timescale 1ns/1ns

module UART_cpu_tb;
    
reg clk;
wire Rx;
wire Tx;
reg USER_btn;
reg [7:0] DUT_in_DataByte = 0; 
reg DUT_in_Start;
wire DUT_out_dataBit;
wire DUT_fComplete;
reg  DUT_fComplete_old;
wire DUT_fComplete_rise;
reg [3:0]index_testData = 0;
wire Tx_start;



reg[7:0] test_data [3];
reg init = 1;
reg init_old = 1;
wire init_fal;
wire [7:0] LEDS;
localparam KBAUD = 14'd10416; 

initial clk = 0;
initial USER_btn = 1;

initial test_data[0] = 70;
initial test_data[1] = 73;
initial test_data[2] = 10;
initial DUT_in_Start = 1;


UART_cpu DUT(.clk(clk),
             .Rx(Rx),
             .Tx(Tx),
             .USER_btn(USER_btn),
             .LEDS(LEDS)
             );

UartTx #(.KBAUD(KBAUD)) uartTx(.clk(clk),
                               .in_DataByte(DUT_in_DataByte),
                               .in_Start(Tx_start),
                               .out_DataBit(Rx),
                               .out_fComplete(DUT_fComplete));

always @(posedge clk) begin
    if(init == 0) begin
        if(DUT_fComplete) begin
            DUT_in_Start <= 0;
            


        end else begin
            DUT_in_Start <= 1;
        end

        if(DUT_fComplete_rise) begin
            if(index_testData < 2) begin
                index_testData = index_testData + 1;
            end else begin
                index_testData = 0;
            end 
        end  
    end
    DUT_in_DataByte <= test_data[index_testData];
    DUT_fComplete_old <= DUT_fComplete;
    init_old <= init;

end

assign Tx_start = DUT_in_Start;
assign init_fal = (!init) & init_old;
assign DUT_fComplete_rise = DUT_fComplete & (!DUT_fComplete_old);

initial begin
    #100 init = 0;
    #1000  USER_btn = 0;
    #10000 USER_btn = 1;
end


always #5 clk = !clk;
initial begin
    $dumpfile("UART_cpu_tb_waves.vcd"); 
    $dumpvars;
end
endmodule