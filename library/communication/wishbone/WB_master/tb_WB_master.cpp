#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VWB_master.h>
#include  <VWB_master___024root.h>


#define MAX_SIM_TIME 500

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char**argv, char** env)
{
    uint8_t data_in[4] = {65,49,50,82};    // A12
    //uint8_t data_in[4] = {82,82,82,82};    // A12
	uint8_t data_CNT = 0; 
    uint8_t data_index = 0;
    
    uint8_t CLK_div = 0;
    uint8_t i_cmd_stb = 0;
    uint8_t i_reset = 1;
    uint8_t i_wb_err = 0;


    uint64_t cmd_word[4] = {0x200000001, 0x100000001,0x200000001,0x000000000}; //A1W1, A1R
    uint64_t cmd_mask = 0x3FFFFFFFF;
    uint64_t i_cmd_word = 0;
	
	Verilated::commandArgs(argc, argv);	//initialize signals to random values
	VWB_master *dut = new VWB_master;
	
    
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace -> open("waveform.vcd");



    while(sim_time < MAX_SIM_TIME)
    {
        if(CLK_div < 4) 
        {
            CLK_div = CLK_div + 1;
            if((CLK_div == 1) && (dut->i_clk))
            {
                dut->i_cmd_word = i_cmd_word;
                dut->i_cmd_stb = i_cmd_stb;
                dut->i_reset = i_reset;
                dut->i_wb_err = i_wb_err;
            }
        }
        else
        {   
            CLK_div = 0;
            dut->i_clk ^= 1;
            dut->eval();


            if(dut->i_clk == 1)
            {
                posedge_cnt ++;
            }
            if(posedge_cnt < 10) 
            {
                 i_reset = 1;
                 i_cmd_word = 0;
                 i_wb_err = 0;
            }
            else
            {
                if(data_CNT < 10)
                {
                    data_CNT = data_CNT + 1;
                    i_cmd_stb = 0;
                }
                else
                {
                    data_CNT = 0;
                    i_cmd_word = cmd_word[data_index] & cmd_mask;
                    i_cmd_stb = 1;
                    if(data_index < ((sizeof(cmd_word)/sizeof(*cmd_word)) - 1))
                        {data_index ++;}
                    else
                        {data_index = 0;}
                }
                i_reset = 0;
            }
        }

        dut->eval();

        m_trace->dump(sim_time);
        sim_time ++;
    }
    
    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);

}


/*


        dut->i_clk ^= 1;
        dut->eval();
        
        
		if(dut->i_clk == 1)
		{
            dut->i_cmd_stb = 0u;
            posedge_cnt ++;

            if(posedge_cnt < 10) 
            {
                 dut->i_reset = 1;
                 dut->i_cmd_word = 0;
                 dut->i_wb_err = 0;
            }
            else
            {
                 dut->i_reset = 0;


                 if(data_CNT < 10)
                 {data_CNT = data_CNT + 1;}
                 else
                 {
                     data_CNT = 0;

                     i_cmd_word = cmd_word[data_index] & cmd_mask;
                     dut->i_cmd_stb = 1u;
                     if(data_index < ((sizeof(cmd_word)/sizeof(*cmd_word)) - 1))
                     {data_index ++;}
                     else
                     {data_index = 0;}
                 }
            }
        }
        else
        {
            
            if(data_CNT == 5)
            { dut->i_wb_ack = 1;}
            else
            { dut->i_wb_ack = 0;}
            dut->i_cmd_word = i_cmd_word;
        }

        

		
        m_trace->dump(sim_time);
        sim_time ++;


        */