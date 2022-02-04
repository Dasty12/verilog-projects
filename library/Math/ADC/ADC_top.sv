module ADC_top (
    input clk
);
    
reg reset;
reg adc_pll_clock_clk;
reg adc_pll_locked_export;
wire        command_valid;
wire [4:0]  command_channel;
wire        command_startofpacket;
wire        command_endofpacket;
wire        command_ready;
wire        response_valid;
wire        response_startofpacket;
wire        response_endofpacket;
wire [0:0]  response_empty;
wire [4:0]  response_channel;
wire [11:0] response_data;
ADC1 u0 (
		.clock_clk              (clk),              //          clock.clk
		.reset_sink_reset_n     (reset),     //     reset_sink.reset_n
		.adc_pll_clock_clk      (adc_pll_clock_clk),      //  adc_pll_clock.clk
		.adc_pll_locked_export  (adc_pll_locked_export),  // adc_pll_locked.export
		.command_valid          (command_valid),          //        command.valid
		.command_channel        (command_channel),        //               .channel
		.command_startofpacket  (command_startofpacket),  //               .startofpacket
		.command_endofpacket    (command_endofpacket),    //               .endofpacket
		.command_ready          (command_ready),          //               .ready
		.response_valid         (response_valid),         //       response.valid
		.response_startofpacket (response_startofpacket), //               .startofpacket
		.response_endofpacket   (response_endofpacket),   //               .endofpacket
		.response_empty         (response_empty),         //               .empty
		.response_channel       (response_channel),       //               .channel
		.response_data          (response_data)           //               .data
);


	 
	 
endmodule