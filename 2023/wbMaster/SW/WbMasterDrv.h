#include "../sim/tb_top_WbMaster.h"
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class WbMasterDrv
{
    private:
        DUT *dut;
        int cnt;
        int DelayTx;
        int index;
        char chars[12]= {'A','2','R','A','4','W','2','A','1','1','2','R'};
        int sizeOfChars;
        uint16_t previous_char;
        uint16_t previous_char_comm;
        int ack_wait;
        int o_wb_cyc_old = 0;
        int Uart_stall_old = 0;
        int Uart_stall_fall = 0;
        int cnt_stopTed = 0;

    public:
        WbMasterDrv(DUT* dut)
        {
            this -> dut = dut;
            cnt = 0;
            DelayTx;
            index = 0;
            sizeOfChars = sizeof(chars) / sizeof(char);
            ack_wait = 2;
        };

        void whenRiseEdge(void);
        void InFromUart(char znak);
        void testWB_out(char znak);
        void simUartTx(void);
        void simUartRX_To_TX(void);
};