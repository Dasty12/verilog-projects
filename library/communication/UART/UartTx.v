module UartTx (
    input clk,
    input [7:0] in_DataByte,  /* data, which you have to send*/
    input in_Start,           /* start the translation*/
    output out_DataBit,       /* data which are sent to output*/
    output out_fComplete      /* transmit is completed, just for one clk duration*/
);
    
endmodule