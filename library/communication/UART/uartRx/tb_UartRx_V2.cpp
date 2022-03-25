#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VUartRx_V2.h>
#include  <VUartRx_V2___024root.h>

using namespace std;

#define MAX_SIM_TIME 40000000

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;
vluint64_t UART_cnt = 0;
vluint64_t UART_div = 10416;
bool UART_clk = false;
bool UART_clk_old = UART_clk;
int data_out = 0;
uint8_t data_index = 0;

int main(int argc, char**argv, char** env)
{
    
	Verilated::commandArgs(argc, argv);	//initialize signals to random values
	VUartRx_V2 *dut = new VUartRx_V2;
	
    
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

            if(posedge_cnt < 10)
            {
                dut->rst = 1;
            }
            else
            {
                dut->rst = 0;
            

                if(UART_cnt > (UART_div / 2))
                { 
                    UART_cnt = 0;
                    
                    UART_clk = !UART_clk;
                   // dut->clk2 = UART_clk;
                }
                else
                { UART_cnt = UART_cnt + 1;}

                //rising edge UART_clk
                if(UART_clk && (!UART_clk_old))
                {
                   // dut->clk3 ^= 1; 
                    if(data_index == 0)
                    {
                        dut->in_data = 0;
                    }
                    if(data_index < 7 + 1)
                    {
                        dut->in_data = (data_out >> (data_index - 1)) & 1u;
                    }
                    else if(data_index < 8 + 1)
                    {
                        dut->in_data = 0u;
                    }
                    else if(data_index < 60 + 1)
                    {
                        dut->in_data = 1u;
                    }


                    if(data_index > 60)
                    {
                        data_index = 0;
                        if(dut->out_data == data_index)
                        {cout << "pass";}
                    // else
                        //{cout << "error: " << dut->out_data <<"hodnota "<<data_out;}

                        data_out++;
                    }
                    else 
                    {
                        data_index = data_index + 1;
                    }
                }
            }
            UART_clk_old = UART_clk;

         /*   if(posedge_cnt < 4)
            {dut->rst = 1;}
            else
            {dut->rst = 0;}
        
            if(posedge_cnt == 7)
            { dut-> ST_rise = 1;}
            else
            { dut -> ST_rise = 0;}
		*/
        }
		
        m_trace->dump(sim_time);
        sim_time ++;
    }
    
    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);

}