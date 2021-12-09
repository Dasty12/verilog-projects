`include "../UartTx.v"
`timescale 1ns/1ns

module UartTx_tb;

//--------------------------------------------
//PARAMETERS
//--------------------------------------------
parameter KBAUD = 14'd10416;

reg clk = 0;
reg [7:0] DUT_in_DataByte_test[2];
reg [7:0] DUT_in_DataByte;

initial begin
    DUT_in_DataByte_test[0] = 50;
    DUT_in_DataByte_test[1] = 120;
end

wire DUT_in_Start;
reg  r_in_Start = 0;
reg  r_in_Start_old = 0;
wire DUT_out_DataBit;
wire DUT_out_fComplete;

reg start_sim = 0;  //start TB after at some time
reg DataByte_cnt = 0;

UartTx #(.KBAUD(KBAUD)) DUT(.clk(clk), 
                            .in_DataByte(DUT_in_DataByte),
                            .in_Start(DUT_in_Start), 
                            .out_DataBit(DUT_out_DataBit), 
                            .out_fComplete(DUT_out_fComplete));


always #5 clk = !clk;
always #1000 start_sim = 1;  


always @(posedge clk) begin
    if(start_sim)begin
        if(DUT_out_fComplete)begin
            DUT_in_DataByte <= DUT_in_DataByte_test[DataByte_cnt];
            r_in_Start <= 1;
            
        end else begin
            r_in_Start <= 0;
        end

        // detekce náběžné hrany startovaciho signalu, pokud by to bylo v ifu výse, tak se bude inkrementovat 2x a ne pouze jednou,
        // protoze nastavi start, UartTx v dalsi periode detekuje start a soucasne nastavi Complete na nulu a v dalsi periode se detekuje zde v tb, proto 2x
        if(DUT_in_Start)begin   
            DataByte_cnt <= DataByte_cnt + 1;                                           
        end


    end
    r_in_Start_old <= r_in_Start;
end

assign DUT_in_Start = (~r_in_Start_old) & r_in_Start;   //detekce náběžné hrany


initial begin
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end

initial begin
    #5000000 $finish;
end

    
endmodule