module fal_edge(input clk,input sig1);

reg sig1_nTmp;
wire falEdge_detect;

always @(posedge clk) begin
    sig1_nTmp <= sig1;

end

assign falEdge_detect = sig1_nTmp & (~sig1);

endmodule