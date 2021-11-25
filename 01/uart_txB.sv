

module uart_txB
#(parameter KBAUD = 14'd10416)
(
    input clk,
    input rst, 
    input [7:0] data, 
    input Tx_start, 
    output Tx_done, 
    output Tx_EN, 
    output OUT
);


typedef enum logic [1:0] {
    IDLE,       //00
    START,      //01   
    DATA,       //10
    STOP        //11
} state_t;

parameter CNT_BITS = $clog2(KBAUD);

reg unsigned [CNT_BITS-1:0] baud_clk;
reg [CNT_BITS-1:0] kbaud; //100e6 / 9600;
reg baud_TICK;
reg next_next = 0;
reg [3:0]data_cnt = 0;
reg [3:0]UT_dataCNT;
reg [3:0]UT_dataCNT_old;
reg OUT_nTmp = 0;


reg Tx_EN_nTmp;

state_t state;  // skutecny state je posunuty o jednu baud periodu


    always @(posedge clk) begin
        if(rst) begin
            state <= IDLE;   
            Tx_EN_nTmp <= 0; 
            OUT_nTmp <= 1;
            baud_clk <= 0;
            baud_TICK <= 0;

            
        end
        else begin
            if(state == IDLE ) begin
                baud_clk <= 0;
                baud_TICK <= 0;
            end
            else if(baud_clk < KBAUD)begin
                baud_clk <= baud_clk + 1;
                baud_TICK <= 0;
            end
            else begin
                baud_clk <= 0;
                baud_TICK <= 1;
            end
            
        end

    end


    always @(posedge clk) begin
        if(rst) begin
            UT_dataCNT <= 0;  
            Tx_EN_nTmp <= 0;  
            UT_dataCNT_old <= 0;
            //Tx_done <= 0;
        end
        else begin
            if((state==IDLE))begin
                if(Tx_start)begin
                    state <= START;
                    Tx_EN_nTmp <= 0;  
                end
                else begin
                   Tx_EN_nTmp <= 1;    
                end 
            end
            else if(baud_TICK)begin
                case(state)
                    START:begin
                        state <= DATA;
                        OUT_nTmp <= 0;  
                    end
                    
                    DATA:begin

                        OUT_nTmp <= data[UT_dataCNT];
                        if(UT_dataCNT < 7) begin
                            //OUT_nTmp = data[UT_dataCNT_old];
                            UT_dataCNT <= UT_dataCNT + 1;
                            UT_dataCNT_old <= UT_dataCNT;
                            
                        end 
                        else begin
                            UT_dataCNT <= 0;
                            state <= STOP;
                        end   
                    end

                    STOP:begin
                        state <= IDLE;
                        OUT_nTmp <= 1;
                        //Tx_done <= 1;
                    end

                    default:begin
                        state <= IDLE;
                        data_cnt <= 0;
                        OUT_nTmp = 1;
                    end    
                endcase    
            end
        end
    end

    assign Tx_EN = Tx_EN_nTmp;
    assign OUT   = OUT_nTmp;
    


endmodule