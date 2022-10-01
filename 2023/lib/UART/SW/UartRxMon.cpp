#include "UartRxMon.h"
#include <iostream>

using namespace std;
void UartRxMon::checkChar(void)
{
    if(dut->out_RXNE)
    {
        if(uint8_t(char_list_toCheck->at(index_char)) == uint8_t(dut->out_word))
        { cout << "success na indexu" << index_char << " ,chtel jsem: " << uint8_t(char_list_toCheck->at(index_char))<<" ,dostal jsem: " << uint8_t(dut->out_word) << endl;}
        else 
        {cout << "Uart Rx fail na Indexu: " << index_char << " ,chtel jsem: " << uint8_t(char_list_toCheck->at(index_char))<<" ,dostal jsem: " << uint8_t(dut->out_word) << endl;}

        if(index_char < (char_list_toCheck->size() - 1))
        { index_char ++;}
        else
        { index_char = 0;}
    }
}