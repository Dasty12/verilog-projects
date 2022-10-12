#include "Uart2WbDrv.h"
#include <iostream>

using namespace std;


void Uart2WbDrv::InFromUart(char znak)
{
    dut->UART_in_data = (int)znak;
    dut->UART_Rx_done = 1;
}

void Uart2WbDrv::whenRiseEdge(void)
{
    if(cnt > 0)
    { cnt --;}
    else
    { 
        cnt = 5;
 
    }

    switch(cnt)
    {
        case 1:
            Uart2WbDrv::InFromUart(chars[index]);
            if(index < (sizeOfChars - 1))
            { index ++;}
            else
            { index = 0;}  
            break;
        case 0: 
            dut->UART_Rx_done = 0;
            break;
    }
}