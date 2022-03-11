#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"
#include "Valu___024unit.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char** argv, char** env) {
    Valu *dut = new Valu;
	
	vector<int> l;
	vector<int> time;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut->clk ^= 1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
		if(dut->clk == 1)
		{
			posedge_cnt++;
			
			if(posedge_cnt == 5)
			{
				//dut->in_valid = 1;
			}
		}
		l.push_back(dut->lin);
		time.push_back(sim_time);
		
    }

    m_trace->close();
    delete dut;
	
	
	ofstream myfile;
	myfile.open("example.csv");
	
	
	for(int i = 0; i < time.size(); i++)
	{
		myfile << time.at(i) <<"," <<l.at(i) <<"," <<"\n" ;
		
	}
	
	//myfile << "ted";
	myfile.close();
	
	
	
	
    exit(EXIT_SUCCESS);
}