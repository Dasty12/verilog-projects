

module sdram_controller(
    /*HOST INTERFACE*/
    wr_addr,
    wr_data,
    wr_enable,
    
    rd_addr,
    rd_enable,
    rd_data,
    rd_ready,
    
    busy,
    rst_n,
    clk,

    /*SDRAM INTERFACE*/
    addr,
    bank_addr,
    data,
    clock_enable,
    cs_n,
    ras_n,
    cas_n,
    we_n,
  //  data_mask_low,
  //  data_mask_high

);

parameter ROW_WIDTH  = 12;
parameter COL_WIDTH  = 8;
parameter BANK_WIDTH = 2;

parameter SDRADDR_WIDTH = (ROW_WIDTH > COL_WIDTH) ? ROW_WIDTH : COL_WIDTH;
parameter HADDR_WIDTH = BANK_WIDTH + COL_WIDTH + ROW_WIDTH;


/*HOST INTERFACE*/
input [HADDR_WIDTH-1:0] wr_addr;
input [15:0]            wr_data;
input                   wr_enable;

input [HADDR_WIDTH-1:0] rd_addr;
input                   rd_enable; /* should be set to high once an address is presented
                                      on the addr bus and we wish to read data.*/
input [15:0]            rd_data;
output                  rd_ready;  /*Will go high when data rd_data 
                                     is available on the data bus.*/

output                  busy;  /*Will go high when w/r command is ack,
                                 Will go low when w/r operation is complete */
input                   rst_n;
input                   clk;

/*SDRAM INTERFACE*/
output [SDRADDR_WIDTH-1:0] addr;
output [BANK_WIDTH-1:0]    bank_addr;
inout  [15:0]              data;
output                     clock_enable;    /* CKE */
output                     cs_n;            /* Chip Select*/
output                     ras_n;           /* Row Address Strobe*/
output                     cas_n;           /* Column Address Strobe*/
output                     we_n;            /* Write Enable*/










endmodule