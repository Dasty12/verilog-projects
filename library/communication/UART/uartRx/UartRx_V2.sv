module UartRx_V2
#(parameter KBAUD = 14'D10416)
(
    input clk,
    input rst,
    input in_data,
    output [7:0] out_data,
    output Rx_done,
    output busy,
    output reg [7:0] o_LEDS
);


parameter CNT_BITS = $clog2(KBAUD);
parameter KBAUD_half  = KBAUD / 2;
parameter KBAUD_period = KBAUD / 2;

localparam s_IDLE  = 0;
localparam s_START = 1;
localparam s_DATA  = 2;
localparam s_STOP  = 3;

reg clk_UART;
reg clk_UART_old = 0;
wire clk_UART_RE;

reg [7:0]UR_data = 0;
reg data_IN_old = 0;
wire data_IN_FE;

reg[3:0] data_cnt = 0;

reg[1:0] state = s_IDLE;
reg[1:0] state_old = s_IDLE;
//baud counter
reg [CNT_BITS-1:0] baud_cnt = 14'd2;
reg [7:0] r_out_data = 0;
reg start = 0;
reg [3:0] dalsi_cnt = 0;

reg Rx_done_RE;
reg Rx_done_RE_old;


always @(posedge clk) begin


    if(rst) begin
        clk_UART <= 1;
        clk_UART_old <= 1;
    end else begin


        if(data_IN_FE && (state == s_IDLE)) begin
            baud_cnt <= KBAUD_half - 1;
            clk_UART <= 1;
            start <= 1;
        end 
    
        if(start)begin 
            if(baud_cnt < KBAUD_period) begin
                baud_cnt <= baud_cnt + 1;
            end else begin
                baud_cnt <= 0;
                clk_UART <= !clk_UART;
                dalsi_cnt <= dalsi_cnt - 1;
            end
        end

        if((state_old == s_STOP) && (state == s_IDLE)) begin
            start <= 0;
        end



        clk_UART_old <= clk_UART;
        data_IN_old <= in_data;

    end
end



assign data_IN_FE = (~in_data) & data_IN_old;
assign clk_UART_RE = clk_UART & (~clk_UART_old);


always @(posedge clk) begin
    if(clk_UART_RE) begin
        case(state)
            s_START: begin
                state <= s_START;
                UR_data <= 0;
                Rx_done_RE <= 0;
            end s_IDLE: begin
                state <= s_DATA;
                UR_data <= 0;
                Rx_done_RE <= 0;
            end s_DATA: begin
                UR_data[data_cnt[2:0]]<= in_data;
                if(data_cnt == 7) begin
                    state <= s_STOP;
                end
                data_cnt <= data_cnt + 1;
            end s_STOP:begin
                state <= s_IDLE;
                
                r_out_data <= UR_data;
                o_LEDS <= r_out_data;
                data_cnt <= 0;
                Rx_done_RE <= 1;
            end default:begin end
        endcase
        
    end
    state_old <= state;
    Rx_done_RE_old <= Rx_done_RE;

end

assign out_data = r_out_data;
assign Rx_done = Rx_done_RE & (!Rx_done_RE_old);



endmodule;