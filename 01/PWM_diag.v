module PWM_diag 
#(parameter KBAUD = 14'd10416)
(   
    input clk,
    input [CNT_BITS-1:0]baud_clk_wi,
    input [3:0] UT_dataCNT, //data counter
    output PWM_OUT
);


parameter CNT_BITS = $clog2(KBAUD);   

localparam CNT_ERR =$rtoi(KBAUD*0.95);
localparam CNT_0 =$rtoi(KBAUD*0.05);
localparam CNT_1 =$rtoi(KBAUD*0.20);
localparam CNT_2 =$rtoi(KBAUD*0.30);
localparam CNT_3 =$rtoi(KBAUD*0.40);
localparam CNT_4 =$rtoi(KBAUD*0.50);
localparam CNT_5 =$rtoi(KBAUD*0.60);
localparam CNT_6 =$rtoi(KBAUD*0.70);
localparam CNT_7 =$rtoi(KBAUD*0.80);
reg PWM_OUT_r;

reg [CNT_BITS-1:0] local_CNT=0;

always @(posedge clk) begin
    if(UT_dataCNT == 0)
        local_CNT=CNT_0;
    else if(UT_dataCNT == 1)
        local_CNT =CNT_1;
    else if(UT_dataCNT == 2)
        local_CNT =CNT_2;
    else if(UT_dataCNT == 3)
        local_CNT =CNT_3;
    else if(UT_dataCNT == 4)
        local_CNT =CNT_4;
    else if(UT_dataCNT == 5)
        local_CNT =CNT_5;
    else if(UT_dataCNT == 6)
        local_CNT =CNT_6;
    else if(UT_dataCNT == 7)
        local_CNT =CNT_7;
    else
        local_CNT <= CNT_ERR;

    if(baud_clk_wi > local_CNT) 
        PWM_OUT_r = 0;

    if(baud_clk_wi == 0)
        PWM_OUT_r <= 1;


    

end
assign PWM_OUT = PWM_OUT_r;

endmodule