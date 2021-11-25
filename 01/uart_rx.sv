module uart_rx
#(parameter KBAUD = 14'd10416)
(
    input clk,
    input rst,
    input data_IN,         /* interface s okolím                    */
    output[7:0] data_OUT,  /* data budou poslána do UART kontroleru */
    output Rx_done,        /* V data_OUT jsou dostupná nová data    */
    output busy            /* Aktuálně dochází k přenosu dat        */
);


typedef enum logic[1:0]{
    IDLE,       //00
    START,      //01
    DATA,       //10
    STOP        //11
}state_t;

parameter CNT_BITS = $clog2(KBAUD);

reg unsigned [CNT_BITS - 1:0] baud_clk;


//rising edge signal detector
reg data_IN_nTmp;
wire data_IN_falEdge;
reg baud_TICK;
reg Rx_start;
reg [3:0]UR_dataCNT;
reg [7:0]UR_data;
reg Rx_done_nTmp;

//baud counter
reg unsigned [CNT_BITS-1:0] baud_cnt = 14'd0;

state_t URstate;    //Uart Receiver state
  
    always @(posedge clk) begin
        if(rst == 1) begin
            baud_clk <= 0;
        end
        else begin
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


    end


    always @(posedge clk) begin
        if(rst == 1) begin
            Rx_start <= 0; 
            URstate <= IDLE;
            UR_dataCNT <= 0; 
            UR_data <= 0;
        end
        else begin
            if(URstate == IDLE)begin
                    //pokud dojde k náběžné hraně
                if(data_IN_falEdge)begin
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
                        
                    end

                    DATA:begin
                        UR_data[UR_dataCNT] <= data_IN;
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

                    end
                    default:begin
                        URstate <= IDLE;
                        UR_dataCNT <= 0;
                    end
                endcase
            end


            data_IN_nTmp <= data_IN;   
        end

    
    end //always

assign data_OUT = UR_data;
assign data_IN_falEdge = data_IN_nTmp & (~data_IN);
assign Rx_done = Rx_done_nTmp;

endmodule