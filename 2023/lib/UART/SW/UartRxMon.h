#include "../sim/tb_top_Uart.h"
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
class UartRxMon
{
    private:
        DUT *dut;
        vector<char> *char_list_toCheck;
        int index_char;
    public:
        UartRxMon(DUT *dut,vector<char> *char_list)
        {
            this->dut = dut;
            char_list_toCheck = char_list;
        }

        void checkChar(void);

};
