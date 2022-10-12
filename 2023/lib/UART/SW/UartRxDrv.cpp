#include "UartRxDrv.h"
#include <iostream>

using namespace std;
int UartRxDrv::charToBit(int index)
{
    //cout <<"index je: "<< index << endl;
    return (char_list.at(index_char) >> index) & 1;
}

void UartRxDrv::resetIndex(void)
{ index_insideCh = 0;}

//tato funkce se zavolá pokaždé když je náběžná hrana hodin
void UartRxDrv::whenRiseEdge(void)
{
    if(period < kperiod)
    { period ++;}
    else
    {
        dut->data_ted = 0;
        if(state_cnt == 0)//start bit
        { dut->UART_IN = 0;}
        else if((state_cnt > 0) && (state_cnt < 9)) //data
        { 
            dut->UART_IN = UartRxDrv::charToBit(state_cnt - 1);
            dut->data_ted = 1;
        }
        else if(state_cnt == 9)//stop bit
        {
            dut->UART_IN = 1;
            if(index_char < (char_list.size() - 1))
            { index_char ++;}
            else
            { index_char = 0;}
        }
        else
        { cout << "UartRxDrv: vole asi neco spatne ne ?" << endl;}

        dut -> state_cnt = state_cnt;

        if(state_cnt < 9)
        { state_cnt ++;}
        else
        { state_cnt = 0;}
        period = 0; 
        
    }
}

