#include "../sim/tb_top_Uart.h"
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
class UartRxMon
{
    private:
    DUT *dut;
    public:
        UartRxMon(DUT *dut)
        {
            this->dut = dut;
        }
};
