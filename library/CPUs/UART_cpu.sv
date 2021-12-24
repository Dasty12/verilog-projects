module UART_cpu (
    input clk,
    input Rx,
    input USER_btn,
    output Tx

);

reg c0;
wire locked;

reg[7:0] dataTx_memory[11];
reg[3:0] dataTx_cnt;
reg[7:0] dataTx;
reg[7:0] dataRx;
reg valid;

wire BUSY;
wire out_RXNE;
wire out_Rx_ORE;
reg RXNE_clear;

reg UserBtn_fil;
reg UserBtn_fil_old;
wire UserBtn_rise;


reg [4:0] smitt_butt_field;
reg [4:0] smitt_butt_field_vymaz;
reg [4:0] smitt_butt_field_vymaz2;
reg [2:0] smitt_butt_cnt;
reg vymaz = 0;
    
initial smitt_butt_field = 0;
initial smitt_butt_cnt = 0;
initial smitt_butt_field_vymaz2 = 0;
initial dataTx_cnt = 0;
integer i;

initial begin
    for(i = 0;i<10;i++)begin
        dataTx_memory[i] <= 48 + i;
    end
    dataTx_memory[10] = 10;
end


PLL1 pll(.areset(areset),
         .inclk0(clk),
         .c0(c0),
         .locked(locked));


UartTop device(.clk(c0),
             //  .in_data(),
               .in_w_data(dataTx),
               .in_valid(valid),
               .out_BUSY(BUSY),
               .out_signal(Tx),
               .in_signal(Rx),
               .in_RXNE_clear(RXNE_clear),
               .out_word(dataRx),
               .out_RXNE(out_RXNE),
               .out_Rx_ORE(out_Rx_ORE));


always @(posedge c0) begin

    if (UserBtn_rise) begin
        valid  <= 1;
        //dataTx <= dataTx_memory[dataTx_cnt];
        if( dataTx_cnt < 10) begin
    //        dataTx_cnt <= dataTx_cnt + 1;
        end else begin
          //  dataTx_cnt <= 0;
        end
    end else begin
        valid  <= 0;
    end
 
    if(smitt_butt_field == 5'b11111) begin  
        UserBtn_fil <= 1;
    end else begin
        UserBtn_fil <= 0;
    end
    smitt_butt_field[smitt_butt_cnt] <= !USER_btn;

    if(smitt_butt_cnt < 4) begin
        smitt_butt_cnt <= smitt_butt_cnt + 1;
    end else begin
        smitt_butt_cnt <= 0;
    end

    UserBtn_fil_old <= UserBtn_fil;



    if(out_RXNE == 1) begin
        dataTx <= dataRx;
    end


end



assign UserBtn_rise = UserBtn_fil & !UserBtn_fil_old;

endmodule