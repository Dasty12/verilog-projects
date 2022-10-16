#include "../sim/tb_top_Uart2wb.h"
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class Uart2WbDrv
{
    private:
        DUT *dut;
        int kperiod;
        int cnt;
        int index; 
        char chars[7]= {'A','2','R','A','4','W','2'};
        int sizeOfChars;
        uint16_t previous_char;
        uint16_t previous_char_comm;

    public:
        Uart2WbDrv(DUT *dut, int kperiod)
        {
            this -> dut     = dut;
            this -> kperiod = kperiod;
            cnt = 3;
            index = 0;
            sizeOfChars = sizeof(chars) / sizeof(char);
        };
        
        void whenRiseEdge(void);
        void InFromUart(char znak);
        void testWB_out(char znak);
};