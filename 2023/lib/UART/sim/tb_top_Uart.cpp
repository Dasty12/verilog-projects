#include <stdlib.h>
#include <iostream>
#include "tb_top_Uart.h"
#include "../SW/UartRxDrv.h"
#include "../SW/UartRxMon.h"



#define MAX_SIM_TIME 60000
#define VERIF_START_TIME 5
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0; ///< counter nabeznych hran


void dut_reset(DUT *dut,vluint64_t &sim_time)
{
    if(sim_time < 5)
    { dut->UART_IN = 1;}

}

void set_rnd_out_valid(DUT *dut, vluint64_t &sim_time)
{
    if(sim_time >= VERIF_START_TIME)
    { dut->in_valid = rand() % 2;}  // generate values 0 and 1
}


int main(int argc, char** argv, char** env) {
    srand (time(NULL));//seed the random number generator

    Verilated::commandArgs(argc, argv); //pro inicializaci signalu na nahodne cislo
    DUT *dut = new DUT;
    UartRxDrv *Rx = new UartRxDrv(dut, 104);               //Rx controller
    UartRxMon *RxMon = new UartRxMon(dut, &Rx->char_list); //Rx monitor

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    

    while (sim_time < MAX_SIM_TIME) {
        
        dut_reset(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();
        
        if (dut->clk == 1){
            dut->in_valid = 0;
            posedge_cnt++;


            set_rnd_out_valid(dut,sim_time);

            if(posedge_cnt > 10)
            { 
                Rx->whenRiseEdge();
                RxMon->checkChar();
            }
            
            switch(posedge_cnt){
                case 5:
                    std::cout << "baud: " << dut->bauld << std::endl;
                   // dut->in_valid = 1;
                    break;
                case 7:
                    break;
                   /* if(dut->out_valid != 1)
                    {   std::cout << "ERROR!" << std::endl;}
                    else
                    { std::cout <<"Test passed!"<<std::endl;}*/
                /*case 10:
                    dut->in_valid = 1;
                    dut->a_in = 5;
                    dut->b_in = 3;
                    dut->op_in = Valu___024unit::operation_t::add;
                    break;
                case 12:
                    if(dut->out != 8)
                        std::cout << "Addition failed @ " << sim_time <<std::endl;
                    break;
                case 20:
                    dut->in_valid = 1;
                    dut->a_in = 5;
                    dut->b_in = 3;
                    dut->op_in = Valu___024unit::operation_t::sub;
                    break;
                case 22:
                    if(dut->out != 2)
                    { std::cout << "Sub failed @"<<sim_time<<std::endl;}
                    break;*/
            }

            //check_out_valid(dut, sim_time);
        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}