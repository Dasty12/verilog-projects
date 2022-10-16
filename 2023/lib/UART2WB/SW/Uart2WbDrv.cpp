#include "Uart2WbDrv.h"
#include <iostream>

using namespace std;


void Uart2WbDrv::InFromUart(char znak)
{
    dut->UART_in_data = (int)znak;
    dut->UART_Rx_done = 1;

    Uart2WbDrv::testWB_out(znak);
}


void Uart2WbDrv::whenRiseEdge(void)
{
    if(cnt > 0)
    { cnt --;}
    else
    {  cnt = 5;}

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


void Uart2WbDrv::testWB_out(char znak)
{
    uint16_t prevedene = 0;
    switch(znak)
    {
        case '0': prevedene = 0x00; break;
        case '1': prevedene = 0x01; break;
        case '2': prevedene = 0x02; break;
        case '3': prevedene = 0x03; break;
        case '4': prevedene = 0x04; break;
        case '5': prevedene = 0x05; break;
        case '6': prevedene = 0x06; break;
        case '7': prevedene = 0x07; break;
        case '8': prevedene = 0x08; break;
        case '9': prevedene = 0x09; break;
        case 'a': prevedene = 0x0A; break;
        case 'b': prevedene = 0x0B; break;
        case 'c': prevedene = 0x0C; break;
        case 'd': prevedene = 0x0D; break;
        case 'e': prevedene = 0x0E; break;
        case 'f': prevedene = 0x0F; break;
        
        case 'R': prevedene = 0x10; break;
        case 'W': prevedene = 0x11; break;
        case 'A': prevedene = 0x12; break;
        case 'S': prevedene = 0x13; break;
        case 'T': prevedene = 0x16; break;
        default: cout << "chyba!!!" << endl; break;
    }

    uint8_t Indic_prikaz = (prevedene & (1 << 4)) >> 4;
    cout << "cely znak: " << prevedene << ",part of znak:" << Indic_prikaz << endl;
    if(Indic_prikaz)
    {
        cout <<" prikaz " << endl;
        previous_char_comm = prevedene;
    }
    else
    {
        previous_char = prevedene;
    }



}