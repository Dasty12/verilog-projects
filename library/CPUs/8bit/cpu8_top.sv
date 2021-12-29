module cpu8_top (
    input clk,
    input reset
);

wire [7:0] to_cpu;
wire [7:0] from_cpu;
wire [7:0] address;

wire write_enable;



cpu8 cpu (.clk(clk),
          .reset(reset),
          .data_in(to_cpu),
          .address(address),
          .data_out(from_cpu),
          .write(write_enable));

memory mem(.clk(clk),
           .address_bus(address),
           .write_enable(write_enable),
           .from_cpu(from_cpu),
           .to_cpu(to_cpu));


    
endmodule