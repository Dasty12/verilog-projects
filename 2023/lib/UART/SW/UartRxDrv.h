#include "../sim/tb_top_Uart.h"
class UartRxDrv
{
    private:
        DUT *dut;
        int index_insideCh;
    public: 
        UartRxDrv(DUT *dut)
        {
            this->dut = dut;
            index_insideCh = 0;
        }
        void charToBit(char ch);

};