#include "UartRxDrv.h"


void UartRxDrv::charToBit(char ch)
{
    if(index_insideCh < 7)
    { index_insideCh ++;}
    else
    {index_insideCh = 0;}

    dut->UART_IN = (ch >> index_insideCh) & 1;
}

