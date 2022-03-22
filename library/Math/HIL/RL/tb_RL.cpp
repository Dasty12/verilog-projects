#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VRL.h>
#include  <VRL___024root.h>
#include <fstream>
#include <vector>

using namespace std;

#define MAX_SIM_TIME 1000000

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char**argv, char** env)
{
    vector<int> time;
	vector<int> l;
	
	
	Verilated::commandArgs(argc, argv);	//initialize signals to random values
	VRL *dut = new VRL;
	
	
    
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
        
        //    if(posedge_cnt == 7)
         //   { dut-> ST_rise = 1;}
         //   else
         //   { dut -> ST_rise = 0;}
	 
			time.push_back((int)posedge_cnt);
			l.push_back((int)dut->out_I);
	 
	 
	 
        }
		
        m_trace->dump(sim_time);
        sim_time ++;
    }
    
    m_trace->close();
    delete dut;
	
	ofstream myfile;
	myfile.open("example.csv");
	
	
	for(int i = 0; i < time.size(); i++)
	{
		if(i % 1000)
		{
			myfile << time.at(i) <<"," <<l.at(i) <<"," <<"\n" ;
		}
		
	}
	myfile.close();
	
	
	
	
    exit(EXIT_SUCCESS);

}