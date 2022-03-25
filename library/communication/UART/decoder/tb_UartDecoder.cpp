#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VUartDecoder.h>
#include  <VUartDecoder___024root.h>


#define MAX_SIM_TIME 500

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char**argv, char** env)
{
    uint8_t data_in[4] = {65,49,50,82};    // A12
    //uint8_t data_in[4] = {82,82,82,82};    // A12
	uint8_t data_CNT = 0; 
    uint8_t data_index = 0;
	
	Verilated::commandArgs(argc, argv);	//initialize signals to random values
	VUartDecoder *dut = new VUartDecoder;
	
    
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace -> open("waveform.vcd");

    while(sim_time < MAX_SIM_TIME)
    {
        dut->i_clk ^= 1;
        dut->eval();
		if(dut->i_clk == 1)
		{
            dut->i_stb = 0;
            posedge_cnt ++;

            if(posedge_cnt < 4)
            {
                dut->rst = 1;
                dut->i_data_in = 0;
            }
            else
            {dut->rst = 0;}


            if(data_CNT < 10)
            { data_CNT ++;}
            else
            {
                data_CNT = 0;

                dut->i_data_in = data_in[data_index];
                dut->i_stb = 1;
                if(data_index < ((sizeof(data_in)/sizeof(*data_in)) - 1))
                {data_index ++;}
                else
                { data_index = 0;}

            }
         }
		
        m_trace->dump(sim_time);
        sim_time ++;
    }
    
    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);

}