module PLL #(
    parameter                  PHASE_BITS = 32,
    parameter [PHASE_BITS-1:0] INITIAL_PHASE_STEP = 0,
    localparam                 MSB = PHASE_BITS - 1
)(
    input i_clk,
    input i_input,
    input [(MSB-1):0]i_step,
    input i_ld,

    output [PHASE_BITS-1:0] o_phase,
    output reg [1:0]        o_err

);




reg [MSB:0] ctr, r_step;
reg agreed_output = 0;
reg lead;
wire phase_err;


initial ctr = 0;
initial r_step = INITIAL_PHASE_STEP;


always @(posedge i_clk) begin
    if(i_ld) begin
        r_step <= { 1'b0, i_step };
    end
end


always @(posedge i_clk) begin
    ctr <= ctr + r_step;
end


always @(posedge i_clk) begin
    if((i_input) && (ctr[MSB])) 
        agreed_output <= 1'b1;
    else if((!i_input) && (!ctr[MSB]))
        agreed_output <= 1'b0;
end


always @(*) begin
    if(agreed_output)
        //We were last high. Lead is true now
        //If the counter goew low before the input
        lead = ((!ctr[MSB])&&(i_input));
    else
        //This will be true if the counter goes high 
        //before the input
        lead = ((ctr[MSB])&&(!i_input));
end


//neschoda mezi vstupnim signalem a rekonstruovanym, bude zaznamenana
assign phase_err =(ctr[MSB] != i_input);


always @(posedge i_clk) begin
    o_err <= (!phase_err) ? 2'b00 :((lead) ? 2'b11 : 2'b01);
end
    
endmodule