`timescale 1ns/1ns

module UartTop_tb;


//testovaci data


reg[7:0] data_tx_tb[2];
logic [7:0] l_data_tx_tb;
reg data_tx_tb_CNT = 0;


//IO port pro UartTop    
reg clk = 0;
//reg [7:0] DUT_in_data;

reg DUT_in_valid;

wire DUT_out_BUSY;
reg  r_DUT_out_BUSY;
wire w_DUT_out_BUSY_fal_edge;

wire DUT_out_signal;
reg DUT_in_signal;
wire DUT_out_valid;

reg [7:0] DUT_out_word;


wire io_RXNE_tb;
reg  DUT_in_RXNE_clear = 0;
wire DUT_out_Rx_ORE;

UartTop DUT(.clk(clk),
            //TRANSMITER 
            .in_w_data(l_data_tx_tb), 
            .in_valid(DUT_in_valid), 
            .out_BUSY(DUT_out_BUSY), 
            .out_signal(DUT_out_signal),
            //RECEIVER 
            .in_signal(DUT_in_signal), 
            .out_word(DUT_out_word),
            .out_RXNE(io_RXNE_tb),
            .in_RXNE_clear(DUT_in_RXNE_clear),
            .out_Rx_ORE(DUT_out_Rx_ORE)
            );
            

//sekvencni logika
always @(posedge clk) begin
    DUT_in_valid <= 1;
    r_DUT_out_BUSY <= DUT_out_BUSY;
        
    //receiver logic, send data from transmiter to receiver
    DUT_in_signal <= DUT_out_signal;

    if(io_RXNE_tb) begin
      //  DUT_in_RXNE_clear = 1;
    end else begin
        DUT_in_RXNE_clear = 0;
    end


end

//kombinacni logika
always @(w_DUT_out_BUSY_fal_edge) begin         //pokud bych to dal na nabeznou hranu(posedge), prvni byte bude nesmysl
    if(w_DUT_out_BUSY_fal_edge == 1) begin      //na dobeznou hranu busy
        if(data_tx_tb_CNT < 1) begin            // pokud
            data_tx_tb_CNT = data_tx_tb_CNT + 1;
        end else begin
            data_tx_tb_CNT = 0;
        end
    end
    l_data_tx_tb = data_tx_tb[data_tx_tb_CNT];
end

assign w_DUT_out_BUSY_fal_edge = (~DUT_out_BUSY) & r_DUT_out_BUSY;

initial begin
    data_tx_tb[0] = 54;
    data_tx_tb[1] = 120;
end

always #5 clk = !clk;
initial begin
    $dumpfile("uart_rx_waves.vcd"); 
    $dumpvars;
end
/*
initial begin
    #5000000 $finish;
end
*/
endmodule