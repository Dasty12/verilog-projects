#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VSPI_ADC.h>
#include  <VSPI_ADC___024root.h>


#define MAX_SIM_TIME 500

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char**argv, char** env)
{
    
	Verilated::commandArgs(argc, argv);	//initialize signals to random values
	VSPI_ADC *dut = new VSPI_ADC;
	
    
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace -> open("waveform.vcd");

    while(sim_time < MAX_SIM_TIME)
    {
        dut->clk ^= 1;
        dut->eval();
		if(dut->clk == 1)
		{
            posedge_cnt ++;

            if(posedge_cnt < 4)
            {dut->rst = 1;}
            else
            {dut->rst = 0;}
        
          /*  if(posedge_cnt == 7)
            { dut-> ST_rise = 1;}
            else
            { dut -> ST_rise = 0;}*/
        }
		
        m_trace->dump(sim_time);
        sim_time ++;
    }
    
    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);

}