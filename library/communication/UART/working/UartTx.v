module UartTx #(parameter KBAUD = 14'd10416)
(
    input clk,
    input [7:0] in_DataByte,  /* data, which you have want to send*/
    input in_Start,           /* start of the translation*/
    output out_DataBit,       /* data which are sent to the output*/
    output out_fComplete      /* transmit is completed, for two periods*/
);
    
localparam s_START = 0; /*neco jako idle stav, kdy pri pozadavku na odeslani dat, se nastaví výstup*/
localparam s_DATA  = 1;
localparam s_STOP  = 2;

reg [1:0] state = s_START;
reg [$clog2(KBAUD)-1:0]baud_cnt = 0;

reg [7:0] Data;
reg[3:0] r_data_cnt = 0;

reg r_out_dataBit;
reg r_out_fComplete;

always @(posedge clk) begin

    if(baud_cnt == 0) begin

        case (state)
            s_START:begin
                if(in_Start )begin    // && r_out_fComplete - tohle zalezi na nadrazeny casti, nesmi drzet start na 1
                    Data <= in_DataByte;
                    state <= s_DATA;
                    baud_cnt <= KBAUD - 1;
                    r_data_cnt <= 0;
                    r_out_fComplete <= 0; // translation is processing
                    r_out_dataBit <= 0;
                end else begin
                    baud_cnt <= 0;
                    r_out_fComplete <= 1; // translation is end, or in IDLE
                    r_out_dataBit <= 1;
                end
            end s_DATA:begin
                r_out_dataBit <= Data[r_data_cnt];
                
                if(r_data_cnt == 7)begin
                    state <= s_STOP;
                end
                r_data_cnt <= r_data_cnt + 1;
                baud_cnt <= KBAUD - 1;
            end s_STOP:begin
                baud_cnt <= KBAUD - 1;
                state <= s_START;
                r_out_dataBit <= 1;
                
            end default:begin end 
        endcase

    end else begin
        baud_cnt <= baud_cnt - 1;
    end

end


assign out_DataBit = r_out_dataBit;
assign out_fComplete = r_out_fComplete;

endmodule