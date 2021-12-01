`include "rom_async.v"

module sine_table #(
 parameter ROM_DEPTH = 64,
 parameter ROM_WIDTH = 8,
 parameter ADDRW = $clog2(4*ROM_DEPTH)
)(
    input [ADDRW-1:0] id,
    output [2*ROM_WIDTH-1:0] data
);


reg[$clog2(ROM_DEPTH)-1:0] tab_id;
reg[ROM_WIDTH-1:0] tab_data;
reg[2*ROM_WIDTH-1:0] data_r;
reg[2*ROM_WIDTH-1:0] data_ted=0;

rom_async #(
    .WIDTH(ROM_WIDTH),
    .DEPTH(ROM_DEPTH),
    .INIT_F("sine_table_64x8.mem")
)sine_rom(
    .addr(tab_id),
    .data(tab_data)
);

reg[1:0] quad;
always @(*) begin    //zajimavy, ze kdyz byla v senzitivnim listu jen id, tak to inkrementovalo jen kazdou druhou hodnotu
    quad = id[ADDRW-1:ADDRW-2];
    case (quad)
        2'b00: tab_id = id[ADDRW-3:0];
        2'b01: tab_id = 2*ROM_DEPTH - id[ADDRW-3:0]; 
        2'b10: tab_id = id[ADDRW-3:0] - 2*ROM_DEPTH; 
        2'b11: tab_id = 4*ROM_DEPTH - id[ADDRW-3:0];  
    endcase
end



always @(id) begin
    if(id == ROM_DEPTH) begin
       data_r = {{ROM_WIDTH-1{1'b0}},1'b1,{ROM_WIDTH{1'b0}}};
       data_ted = {{ROM_WIDTH-1{1'b0}},1'b1,{ROM_WIDTH{1'b0}}};
    end else begin
        if(quad[1]==0) begin
            data_r = {{ROM_WIDTH{1'b0}},tab_data};
        end else begin
            data_r = {2*ROM_WIDTH{1'b0}} - {{ROM_WIDTH{1'b0}}, tab_data};
        end
            
    end
end
    
assign data = data_r;

endmodule