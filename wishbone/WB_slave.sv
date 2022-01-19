module WB_slave (
    input         i_clk,
    input         i_wb_cyc,
    input         i_wb_stb,
    input         i_wb_we,
    input     [29:0]  i_wb_addr,
    input     [31:0]  i_wb_data,
    input      [3:0]   i_wb_sel,

    output reg        o_wb_stall,
    output reg        o_wb_ack,
    output            o_wb_err,
    output reg [31:0] o_wb_data,
    output reg [7:0]  o_LEDS
);

initial o_wb_stall = 1'b0;

reg [7:0] LEDS = 0;

always @(posedge i_clk) begin
    if((i_wb_cyc) && (i_wb_stb)) begin

        o_wb_ack <= 1;
        if(i_wb_we) begin
            o_wb_data <= LEDS;
            o_LEDS <= LEDS;
        end

    end else begin
        o_wb_ack <= 0;
    end

end

reg plati = 0;

always @(posedge i_clk) begin
    if(i_wb_addr == 1) begin
        LEDS <= i_wb_data[7:0];
        plati <= 1;
    end else begin
        LEDS <= 8'b11111111;
    end
   /* case(i_wb_addr[29:0])
        30'h1: LEDS <= 8'b00000001;
        30'h2: LEDS <= 8'b00000010;
        30'h3: LEDS <= 8'b00000100;
        30'h4: LEDS <= 8'b00001000;
        30'h5: LEDS <= 8'b00010000;
        30'h6: LEDS <= 8'b00100000;
        30'h7: LEDS <= 8'b01000000;
        30'h8: LEDS <= 8'b10000000;

        default:
            LEDS <= 8'b11111111;
    endcase
*/
end

    
endmodule

/*pro jednoduchost, prvni slave bude blikac,*/