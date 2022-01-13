module UartRx
#(parameter KBAUD = 14'd10416)
(
    input clk,
    input in_data,         /* příchozí jednotlivá data, sériově     */
    output[7:0] out_data,  /* data budou poslána do UART kontroleru */
    output Rx_done,        /* 1 BYTE dat je úspěšně přijat          */
    output busy            /* Aktuálně dochází k přijmu dat         */
);


typedef enum logic[1:0]{
    IDLE,       //00
    START,      //01
    DATA,       //10
    STOP        //11
}state_t;

parameter CNT_BITS = $clog2(KBAUD);

//reg unsigned [CNT_BITS - 1:0] baud_clk;


//rising edge signal detector
reg data_IN_nTmp;
wire data_IN_falEdge;       // detektor doběžné hrany
reg baud_TICK;
reg Rx_start = 0;
reg [3:0]UR_dataCNT = 0;
reg [7:0]UR_data = 0;
reg Rx_done_nTmp = 1;
reg r_busy;             

//baud counter
reg unsigned [CNT_BITS-1:0] baud_cnt = 14'd0;

state_t URstate = IDLE;    //Uart Receiver state
  
always @(posedge clk) begin
    if(data_IN_falEdge && (URstate == IDLE))begin
        baud_cnt <= KBAUD / 2;    
    end
    else if(URstate != IDLE) begin
        if(baud_cnt < KBAUD) begin
            baud_cnt <= baud_cnt + 1;
            baud_TICK <= 0;
        end
        else begin
            baud_cnt <= 0;
            baud_TICK <= 1;
        end
    end
    else begin
    end
    
end

always @(posedge clk) begin
    if(URstate == IDLE)begin  
        if(data_IN_falEdge)begin //pokud dojde k náběžné hraně
            URstate <= START;
            Rx_start <= 1;
        end
    end 
    else if(baud_TICK) begin
        case(URstate)
            START:begin
                URstate <= DATA;
                Rx_done_nTmp <= 0;
                UR_data <= 0;
                r_busy <= 1;
            end

            DATA:begin
                UR_data[UR_dataCNT] <= in_data;
                if(UR_dataCNT < 7) begin
                    UR_dataCNT <= UR_dataCNT + 1; 
                end 
                else begin
                    UR_dataCNT <= 0;
                    URstate <= STOP;
                end   
            end

            STOP:begin
                URstate <= IDLE;
                Rx_done_nTmp <= 1;
                r_busy <= 0;

            end
            default:begin
                URstate <= IDLE;
                UR_dataCNT <= 0;
            end
        endcase
    end
    data_IN_nTmp <= in_data;   

end //always

assign out_data = UR_data;
assign data_IN_falEdge = data_IN_nTmp & (~in_data);
assign Rx_done = Rx_done_nTmp;

endmodule