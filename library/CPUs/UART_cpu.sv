module UART_cpu (
    input clk,
    input Rx,
    input USER_btn,
    output Tx,
    output [7:0] LEDS
);

reg c0;
wire locked;

reg[7:0] dataTx_memory[11];
reg[3:0] dataTx_cnt;
reg[7:0] dataTx;
reg[7:0] dataTx_old;
reg[7:0] dataRx;
reg[7:0] dataRx_old;
reg[7:0] a_index;
reg[7:0] dataRx_field[10];
reg[15:0] status_reg = 33812;
reg[3:0] dataRx_field_cnt = 0; 
reg valid;

wire BUSY;
wire out_RXNE;
wire out_Rx_ORE;
reg RXNE_clear = 0;
wire w_dataTx;

reg UserBtn_fil;
reg UserBtn_fil_old;
wire UserBtn_rise;
reg transmit = 0;
reg transmit_old = 0;
wire transmit_rise;
reg busy_old = 0;
wire busy_falling_edge;
reg receive = 0;
reg receive_old = 0;
wire receive_rise;


reg [4:0] smitt_butt_field;  
reg [2:0] smitt_butt_cnt;
reg [3:0] kTransmit_cnt = 0;
reg [3:0] transmit_cnt = 0;

reg[7:0] data;
reg[7:0] adresa;
reg[3:0] receive_cnt = 0;

reg out_RXNE_old;
    
initial smitt_butt_field = 0;
initial smitt_butt_cnt = 0;
initial dataTx_cnt = 0;
initial a_index = 0;
integer i;

initial begin
    for(i = 0; i<10; i++)begin
        dataTx_memory[i] <= 48 + i;
        dataRx_field[i] <= 0;
    end
    dataTx_memory[10] <= 10;
end


PLL1 pll(.areset(areset),
         .inclk0(clk),
         .c0(c0),
         .locked(locked));


UartTop device(.clk(c0),
               .in_w_data(dataTx),
               .in_valid(valid),
               .out_BUSY(BUSY),
               .out_signal(Tx),
               .in_signal(Rx),
               .in_RXNE_clear(RXNE_clear),
               .out_word(dataRx),
               .out_RXNE(out_RXNE),
               .out_Rx_ORE(out_Rx_ORE));


always @(posedge clk) begin
    if(UserBtn_rise == 1) begin
        
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
end


always @(posedge clk) begin

    if(transmit && (BUSY == 0) && (transmit_rise || busy_falling_edge)) begin
        if(transmit_cnt < kTransmit_cnt) begin
            transmit_cnt <= transmit_cnt + 1;
            if(transmit_cnt == 0) begin
                dataTx <= adresa;
            end else begin
                dataTx <= data;
            end
        end else begin
            transmit <= 0; 
            transmit_cnt <= 0;
            dataTx <= 10;   
        end
        valid <= 1;
    end else begin
        valid <= 0;
    end



    if(receive_rise && (transmit == 0)) begin
        if(receive_cnt == 2) begin
            transmit <= 1;
            kTransmit_cnt <= receive_cnt;
            receive_cnt <= 0;
        end else begin
            if(receive_cnt == 0) begin
                adresa <= dataRx_old;
            end else begin
                data <= dataRx_old;
            end
            receive_cnt <= receive_cnt + 1;
            
        end
    end
 

    if(out_RXNE == 1) begin
        dataRx_old <= dataRx;
        receive <= 1;
        RXNE_clear <= 1;
    end else begin
        RXNE_clear <= 0;
        receive <= 0;
    end

    out_RXNE_old <= out_RXNE;
    dataTx_old <= dataTx;
    transmit_old <= transmit;
    busy_old <= BUSY;
    receive_old <= receive;

    
end

assign receive_rise = receive & (!receive_old);
assign transmit_rise = transmit & (!transmit_old);
assign busy_falling_edge = (!BUSY) & busy_old;
assign UserBtn_rise = UserBtn_fil & !UserBtn_fil_old;


assign LEDS = adresa;

endmodule