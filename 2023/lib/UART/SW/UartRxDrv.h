#include "../sim/tb_top_Uart.h"
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
class UartRxDrv
{
    private:
        DUT *dut;
        int index_insideCh;
        int index_char;
        vector<char> char_list;
        ///list<int>::iterator it;
        int period;
        int kperiod;
        int state_cnt;

    public: 
        UartRxDrv(DUT *dut,int kperiod)
        {
            this->dut = dut;
            index_insideCh = 0;
            index_char = 0;
            char_list.push_back('a');
            char_list.push_back('b');
            uint8_t pro_prevod = 0xFF;
            char_list.push_back(char(pro_prevod));
            pro_prevod = 0x00;
            char_list.push_back(char(pro_prevod));
            period = 0;
            this->kperiod = kperiod;
            state_cnt = 0;
          //  it = char_list.begin();
        }


        //prevod charu na bity
        int charToBit(int index);
        void resetIndex(void);
        void whenRiseEdge(void);

};