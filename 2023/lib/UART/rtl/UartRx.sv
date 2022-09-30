module UartRx #(
    parameter KBAUD = 14'D10416
)
(
    input clk,              ///< vstupni hodiny
    input rst,              ///< restartovaci signal

    input UART_IN,          ///< vstupní signál do UARTU
    output [7:0] out_data,  ///< výstupní slovo 
    output Rx_done          ///< nové slovo je projmute- pouze po dobu jedne periody clk
);


parameter CNT_BITS = $clog2(KBAUD);
parameter KBAUD_half  = KBAUD / 2;      ///< polovina periody UARTU

localparam s_IDLE  = 0;
//localparam s_START = 1;
localparam s_DATA  = 2;
localparam s_STOP  = 3;

reg clk_UART;           ///< UART perioda
reg clk_UART_old = 0;   ///< UART perioda, zpozdena o jednu periodu
wire clk_UART_RE;       ///< detekce nabezne hrany UART periody

reg [7:0]UR_data = 0;
reg UART_IN_old = 0;    ///< vstupní signál, zpožděný o jednu periodu
wire UART_IN_FE;        ///< detekce doběžné hrany vstupního signálu


reg[3:0] data_index = 0;          ///< index bitů ve slově

reg[1:0] state = s_IDLE;          ///< stav stavového automatu
reg[1:0] state_old = s_IDLE;      ///< stav stavového automatu, zpozdeneho o jednu periodu
//baud counter
reg [CNT_BITS-1:0] baud_cnt = 0;    ///< čítač UART periody
reg [7:0] r_out_data = 0;           ///< výstupní slovo, registrované
reg startReceive = 0;       ///<signal aktivni pri prijimani celeho slova, povoluje čítání UART děličky

reg Rx_done_r;              ///< indikace úspěšně přijatého slova
reg Rx_done_r_old;          ///< indikace úspěšně přijatého slova, zpožděného o jednu periodu

//reg [13:0] testovaci  = 0;


always @(posedge clk) begin
    if(rst) begin
        clk_UART <= 1;
        clk_UART_old <= 1;
    end else begin
        if(UART_IN_FE && (state == s_IDLE)) begin   //pokud vstupní signál přejde do nuly a stavový automat je v idle
            baud_cnt <= KBAUD_half - 1;
            clk_UART <= 1;
            startReceive <= 1;
        end 
    
        if(startReceive)begin 
            // dělička pro UART hodiny (9600 BAUD / 2)
            if(baud_cnt < KBAUD_half) begin
                baud_cnt <= baud_cnt + 1;
            end else begin
                baud_cnt <= 0;
                clk_UART <= !clk_UART;
            end
        end

        // pokud SA prechazi ze stop do idle, cele se to zastavi
        if((state_old == s_STOP) && (state == s_IDLE)) begin    
            startReceive <= 0;
        end

        clk_UART_old <= clk_UART;
        UART_IN_old <= UART_IN;

    end
end



assign UART_IN_FE = (~UART_IN) & UART_IN_old;
assign clk_UART_RE = clk_UART & (~clk_UART_old);


//modul pro stavovy automat prijimacich slov
always @(posedge clk) begin
    if(clk_UART_RE) begin
        case(state)
            s_IDLE: begin
                state <= s_DATA;
                UR_data <= 0;
                Rx_done_r <= 0;
            end s_DATA: begin
                UR_data[data_index[2:0]] <= UART_IN;
                if(data_index == 7) begin
                    state <= s_STOP;
                end
                data_index <= data_index + 1;
            end s_STOP:begin
                state <= s_IDLE;
                r_out_data <= UR_data;
                data_index <= 0;
                Rx_done_r <= 1;
            end default:begin end
        endcase
        
    end
    state_old <= state;
    Rx_done_r_old <= Rx_done_r;   
end


assign out_data = r_out_data;
assign Rx_done = Rx_done_r & (~Rx_done_r_old);



endmodule