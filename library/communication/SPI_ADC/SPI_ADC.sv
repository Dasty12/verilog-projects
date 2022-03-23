module SPI_ADC(input clk, input rst, input ST_rise);


reg ahoj;

always @(posedge clk) begin


	ahoj <= ST_rise;

end



endmodule;