`include "rom_async.sv"
module sine_table 
#(
    parameter ROM_DEPTH = 64,
    parameter ROM_WIDTH = 8,
    parameter ROM_FILE = "",
    parameter ADDRW=$clog2(4*ROM_DEPTH)
) (
    input wire logic [ADDRW-1:0] id,
    output logic signed[2*ROM_WIDTH-1:0] data
);
    

logic [$clog2(ROM_DEPTH)-1:0] tab_id;
logic [ROM_WIDTH-1:0] tab_data;
rom_async #(
    .WIDTH(ROM_WIDTH),
    .DEPTH(ROM_DEPTH),
    .INIT_F(ROM_FILE)
) sine_rom(
    .addr(tab_id),
    .data(tab_data)
);

logic [1:0] quad;
always_comb begin 
    quad = id[ADDRW-1:ADDRW-2];
    case(quad)
        2'b00: tab_id = id[ADDRW-3:0];
        2'b01: tab_id = 2*ROM_DEPTH - id[ADDRW-3:0];
        2'b10: tab_id = id[ADDRW-3:0] - 2*ROM_DEPTH;
        2'b11: tab_id = 4*ROM_DEPTH - id[ADDRW-3:0];
    endcase
end

always_comb begin 
    if(id == ROM_DEPTH) begin //sin(90) = +1.0
        data = {{ROM_WIDTH-1{1'b0}}, 1'b1, {ROM_WIDTH{1'b0}}};
    end else if(id == 3*ROM_DEPTH) begin //sin(270) = -1.0
        data = {{ROM_WIDTH{1'b1}}, {ROM_WIDTH{1'b0}}};
    end else begin
        if(quad[1] == 0) begin //positive in quadrant I and II
            data = {{ROM_WIDTH{1'b0}},tab_data};
        end else begin
            data = {{2*ROM_WIDTH{1'b0}} - {{ROM_WIDTH{1'b0}},tab_data}};
        end
    end
end


endmodule