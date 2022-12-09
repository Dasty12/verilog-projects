#include <stdlib.h>
#include <iostream>
#include "tb_top_sdpll.h"
#include "../SW/sdPllsim.h"

#define MAX_SIM_TIME 60000
#define VERIF_START_TIME 5

vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;


void dut_reset(DUT *dut,vluint64_t &sim_time)
{
    if(sim_time < 5)
    { dut->rst = 1;}

}

void set_rnd_out_valid(DUT *dut, vluint64_t &sim_time)
{
   /* if(sim_time >= VERIF_START_TIME)
    { dut->in_valid = rand() % 2;}  // generate values 0 and 1*/
}


int main(int argc, char** argv, char** env) {
    srand (time(NULL));//seed the random number generator

    Verilated::commandArgs(argc, argv); //pro inicializaci signalu na nahodne cislo
    DUT *dut = new DUT;
    //UartRxDrv *Rx = new UartRxDrv(dut, 104);               //Rx controller
    //UartRxMon *RxMon = new UartRxMon(dut, &Rx->char_list); //Rx monitor
    sdPllsim *Drv = new sdPllsim(dut);
    Drv->init();

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    

    while (sim_time < MAX_SIM_TIME) {
        dut->rst = 0;
        dut_reset(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();
        
        if (dut->clk == 1){
            posedge_cnt++;


            set_rnd_out_valid(dut,sim_time);

            if(posedge_cnt > 10)
            { 
                Drv->whenRiseEdge(posedge_cnt);
            }

        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
