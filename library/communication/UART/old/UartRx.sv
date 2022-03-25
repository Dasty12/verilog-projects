module UartRx
#(parameter KBAUD = 14'd10416)
(
    input clk,
	input rst,
    input in_data,         /* příchozí jednotlivá data, sériově     */
    output[7:0] out_data,  /* data budou poslána do UART kontroleru */
    output Rx_done,        /* 1 BYTE dat je úspěšně přijat          */
    output busy,            /* Aktuálně dochází k přijmu dat         */
    output [7:0] o_LEDS
);

localparam s_IDLE  = 0;
localparam s_START = 1;
localparam s_DATA  = 2;
localparam s_STOP  = 3;


parameter CNT_BITS = $clog2(KBAUD);
parameter KBAUD_half = KBAUD / 2;



//rising edge signal detector
reg data_IN_old;
wire data_IN_falEdge;       // detektor doběžné hrany
reg Rx_start = 0;
reg [7:0]UR_data = 0;
reg Rx_done_nTmp = 1;
reg Rx_done_nTmp_old = 1;
reg r_busy;    
reg [7:0]r_out_data = 0;  



//baud counter
reg [CNT_BITS-1:0] baud_cnt = 14'd0;

reg[1:0] state = s_IDLE;
reg[3:0] r_data_cnt = 0;



always @(posedge clk) begin
    if(baud_cnt == 0) begin
        case(state)
            s_IDLE: begin
                if(data_IN_falEdge) begin
                    baud_cnt <= KBAUD_half - 1;
                    state <= s_START;
                end 
                r_data_cnt <= 0;
                Rx_done_nTmp <= 0;
                
            end s_START: begin
                baud_cnt <= KBAUD - 1;
                state <= s_DATA;

            end s_DATA: begin
                baud_cnt <= KBAUD - 1;
                UR_data[r_data_cnt[2:0]] <= in_data; 
                if(r_data_cnt == 7) begin
                    state <= s_STOP;
                end
                r_data_cnt <= r_data_cnt + 1;
            end s_STOP: begin
                state <= s_IDLE;
                r_out_data <= UR_data;
                Rx_done_nTmp <= 1;
                o_LEDS <= UR_data;
            end default:begin end
        endcase    
    end else begin
        baud_cnt <= baud_cnt - 1;
    end

    data_IN_old <= in_data; 
    Rx_done_nTmp_old <= Rx_done_nTmp; 
end


assign out_data = r_out_data;
assign data_IN_falEdge = data_IN_old & (~in_data);
assign Rx_done = Rx_done_nTmp & (~Rx_done_nTmp_old);

endmodule