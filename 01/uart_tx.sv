

module uart_tx(input clk, input rst, input [7:0] data, input Tx_start, output Tx_done, output Tx_EN, output OUT);


typedef enum logic [1:0] {
    IDLE,       //00
    START,      //01   
    DATA,       //10
    STOP        //11
} state_t;



reg unsigned [13:0] baud_clk = 14'd0;
reg [13:0] kbaud = 14'd10416; //100e6 / 9600;
reg next_state = 0;
reg next_next = 0;
reg [3:0]data_cnt;
reg OUT_nTmp = 0;


reg Tx_EN_nTmp;

state_t state;  // skutecny state je posunuty o jednu baud periodu


    always @(posedge clk) begin
        if(rst) begin
            state <= IDLE;   
            Tx_EN_nTmp <= 0; 
            OUT_nTmp <= 1;

            
        end
        else begin
            if(baud_clk < kbaud) begin
                baud_clk <= baud_clk + 1;
                next_state <= 0;
            end
            else begin
                baud_clk <= 14'd0;
                next_state <= 1;
            end
            
        end

    end


    always @(posedge clk) begin
        if(next_state == 1) begin
            case(state)
                IDLE:begin 
                    if(Tx_start == 1) begin
                        state <= START; 
                        Tx_EN_nTmp <=  0;  
                    end
                    else begin
                        data_cnt <= 0;
                        Tx_EN_nTmp <= 1;
                    end
                    OUT_nTmp <= 1;
                end

                START:begin
                    state <= DATA;
                    OUT_nTmp <= 0;
                end

                DATA:begin
                    if(data_cnt < 7)begin
                        data_cnt <= data_cnt + 1;
                        OUT_nTmp <= data[data_cnt];

                    end    
                    else begin 
                        state <= STOP;
                        data_cnt <= 0;
                    end
                
                end

                STOP:begin
                    state <= IDLE;
                    data_cnt <= 0;
                    OUT_nTmp <= 1;
                end

                default:begin
                    state <= IDLE;
                    data_cnt <= 0;
                    OUT_nTmp <= 1;
                end
            endcase


        end
    end

    assign Tx_EN = Tx_EN_nTmp;
    assign OUT   = OUT_nTmp;


endmodule