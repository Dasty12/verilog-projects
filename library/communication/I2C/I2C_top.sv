module I2C_top
(
    input clk,
    inout SDA,      /**/
    output SCL      /**/
);


localparam s_START = 0;
localparam s_ADDR  = 1;
localparam s_DATA  = 2;
localparam s_STOP  = 3;


parameter kCLK_DIV = 10000;
parameter kCLK_DIV_quad = 10000/4;

reg clk_i2c;
reg [$clog2(kCLK_DIV)-1:0] clk_i2c_cnt = 0;
reg [$clog2(kCLK_DIV)-1:0] SCL_CNT = kCLK_DIV_quad;
reg [2:0] data_cnt = 0;
reg r_SDA = 1;
//přenos bude na 10kHz
reg[1:0] state = S_START;


reg[7:0] test_data[3];

always @(posedge clk) begin
   // if(clk_i2c_cnt < kCLK_DIV - 1)begin
   //     clk_i2c_cnt <= clk_i2c_cnt  + 1;
   // end else begin
   //     clk_i2c_cnt <= 0;
   // end
    case(state)
        s_START: begin
            r_SDA <= 0;
        end
        default:begin end
    endcase


    if(clk_i2c_cnt < (kCLK_DIV - 1)) begin
        clk_i2c_cnt <= clk_i2c_cnt + 1;
    end else begin
        clk_i2c_cnt <= 0;
        if(data_cnt < 7) begin
            data_cnt <= data_cnt + 1;
        end else begin
            data_cnt <= 0;
        end

    end
end



initial begin
    test_data[0] = 10;
    test_data[1] = 25;
    test_data[2] = 60;
end

assign SDA = r_SDA;

endmodule