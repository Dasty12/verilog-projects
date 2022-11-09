#include "WbMasterDrv.h"
#include <iostream>

using namespace std;

void WbMasterDrv::InFromUart(char znak)
{
    dut->UART_in_data = (int)znak;
    dut->UART_Rx_done = 1;

    WbMasterDrv::testWB_out(znak);
}



void WbMasterDrv::whenRiseEdge(void)
{
    //counter, ktery se dekrementuje od 5 do 0

    if(cnt > 0)
    { cnt --;}
    else
    { cnt = 40;}
    
    switch(cnt)
    {
        case 1: //simulace UartRx
            WbMasterDrv::InFromUart(chars[index]);
            if(index < (sizeOfChars - 1))
            { index ++;}
            else
            { index = 0;}  
            break;
        case 0: //po odeslani slova z UartRx se vynuluje priznak odeslaneho slova
            dut->UART_Rx_done = 0;
            break;
    }


    if(dut->o_wb_cyc == 1 && (o_wb_cyc_old == 0))
    { 
        dut->i_wb_ack = 0;
        ack_wait = 2;
    }
    else if(ack_wait > 0)
    {
        if(ack_wait == 1)
        { 
            dut->i_wb_ack = 1;
            if(dut->o_wb_we == 0)
            { dut->io_wb_data = 5;}
        }
        else
        { dut->i_wb_ack = 0;}
        ack_wait = ack_wait - 1;
        
    }
    else
    { dut->i_wb_ack = 0;}

    o_wb_cyc_old = dut->o_wb_cyc;

    WbMasterDrv::simUartTx();


}


void WbMasterDrv::testWB_out(char znak)
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

        
void WbMasterDrv::simUartTx(void)
{
    if(dut->U2Tx_Start == 1)
    { 
       DelayTx = 4;
    }

    if(DelayTx > 0)
    {
        if(DelayTx == 1)
        { dut->U2Tx_fComplete = 1;}
        else
        { dut->U2Tx_fComplete = 0;}
        DelayTx --;    
    }



}

void WbMasterDrv::simUartRX_To_TX(void)
{
   // if((dut->UART_Rx_done == 1))
   // {
   //     CNT_Rx_to_Tx = 0;
   // }
}