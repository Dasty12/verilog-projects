
`include "uart_txB.v"
`include "PWM_diag.v"
module UartTx_top (
    input clk,
    input c0,
    output UART_Tx
);


parameter KBAUD = 14'd10416;
parameter CNT_BITS = $clog2(KBAUD);

wire c0;
wire areset;
reg areset_l=0;
wire locked;
reg [7:0] tx_data;
reg Tx_start;
wire Tx_done;
wire Tx_EN;
wire tx_out_l;
wire [CNT_BITS-1:0] baud_clk_wi;
wire [3:0] UT_dataCNT;
reg rst_CNT = 0;
wire PWM_DIAG_r;

wire clk_50kHz;
reg  clk_50kHz_l = 0;
reg [10:0] clk_50kHz_div = 0;

uart_txB uart_tx
(
    .clk(c0),
    .rst(areset), 
    .data(tx_data), 
    .Tx_start(Tx_start), 
    .Tx_done(Tx_done), 
    .Tx_EN(Tx_EN), 
    .OUT(tx_out_l),
    .baud_clk_wi(baud_clk_wi),
    .UT_dataCNT(UT_dataCNT)
);

PWM_diag pwm_diag
(
    .clk(c0),
    .baud_clk_wi(baud_clk_wi),
    .UT_dataCNT(UT_dataCNT),
    .PWM_OUT(PWM_DIAG_r)
);

always @(posedge c0)begin
	if(clk_50kHz_div < 2000) begin
		clk_50kHz_div <= clk_50kHz_div + 1;
	end
	else begin
		clk_50kHz_div <= 0;
		clk_50kHz_l <= !clk_50kHz_l;	
	end
	
end


always @(posedge clk_50kHz) begin
    if(rst_CNT == 0)begin
        rst_CNT = 1;
        areset_l <= 1;
        Tx_start <= 0;
    end
    else begin 
        areset_l <= 0;
        if(Tx_EN)begin
            tx_data <= 177;
            Tx_start <= 1;
        end
        else begin
           Tx_start <= 0; 
        end
    end

end


assign UART_Tx = tx_out_l;
assign UART_Tx_debug = tx_out_l;
assign areset = areset_l;
assign clk_50kHz = clk_50kHz_l;
endmodule