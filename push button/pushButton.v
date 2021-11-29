module pushButton
#(parameter FIL_ORDER = 10)
(
    input clk,
    input sig_IN,
    output posEdge_detect,
    output falEdge_detect
);
parameter INCR_BITS = $clog2(FIL_ORDER);
parameter [FIL_ORDER-1:0] MAX = {FIL_ORDER{1'b1}};
reg[FIL_ORDER-1:0] button_old;
reg[INCR_BITS-1:0] i;
reg button_fil_rise_r;
reg button_fil_rise_olf_r;
reg button_fil_fall_r;
reg button_fil_fall_old_r;
reg button_rise_r;



always @(posedge clk) begin
    button_old[0] <= sig_IN;
    for(i = 1; i < FIL_ORDER; i = i + 1)begin
        button_old[i] <= button_old[i-1];
    end

    if((button_old==MAX) && (sig_IN==1)) begin
        button_fil_rise_r <= 1;
    end
    else if((button_old ==0) && (sig_IN==0))begin
        button_fil_fall_r <= 1;
    end
    else begin
        button_fil_rise_r <= 0;
        button_fil_fall_r <= 0;
    end

    button_fil_rise_olf_r <= button_fil_rise_r;
    button_fil_fall_old_r <= button_fil_fall_r;
end

assign posEdge_detect = ~button_fil_rise_olf_r & button_fil_rise_r;
assign falEdge_detect =  ~button_fil_fall_old_r & button_fil_fall_r;

endmodule