#include "WbMasterDrv.h"
#include <iostream>
#include <vector>

using namespace std;


#define SIM_SLAVE_EN 0


/// @brief odešle data a nastaví příznak úspěšného odeslání
/// @param znak - znak, který se odešle
void WbMasterDrv::InFromUart(char znak)
{
    dut->UART_in_data = (int)znak;
    dut->UART_Rx_done = 1;

    WbMasterDrv::testWB_out(znak);
}

void WbMasterDrv::init(void)
{
    WbMasterDrv::StrToChars();

    cout << "----Start init----" << endl;

    if(SIM_SLAVE_EN == 1)
    { cout << "Sim slave on" << endl;}
    else
    { cout << "Sim slave Off" << endl;}

    cout << "----End Init----" << endl;
}

void WbMasterDrv::whenRiseEdge(void)
{
    //counter, ktery se dekrementuje od 5 do 0




    if((dut->WB2UART_stall == 0) && (Uart_stall_old == 1))
    { Uart_stall_fall = 1;}
    else 
    { Uart_stall_fall = 0;}

    Uart_stall_old = dut->WB2UART_stall;
    
  /*  switch(cnt)
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
*/

    WbMasterDrv::UartHost();
    


    //simulace slave
    if(SIM_SLAVE_EN == 1)
    { WbMasterDrv::simSlave();}
    



    //WbMasterDrv::simUartTx();
    WbMasterDrv::sim_HostUart();



    WbMasterDrv::Diag_info();
}


void WbMasterDrv::testWB_out(char znak)
{
    uint16_t prevedene = 0; // WbCommand
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

    uint8_t fIsCommand = (prevedene & (1 << 4)) >> 4; // zjistuje jestli je znak příkaz (jestli 4 bit je rovný 1)
   // cout << "celý znak: " << prevedene << ", Část znaku:" << fIsCommand << endl;
    if(fIsCommand)
    {
     //   cout <<" prikaz: " << endl;
        previous_char_comm = prevedene;
    }
    else
    {
        previous_char = prevedene;
    }
}

//        
void WbMasterDrv::simUartTx(void)
{
    //pozadovany prenos dat z UartTx
    if(dut->U2Tx_Start == 1)
    { 
       DelayTx = 4; //nastavi se delay
    }

    if(DelayTx > 0) 
    {
        if(DelayTx == 1)    //pokud se delay rovna 1
        { dut->U2Tx_fComplete = 1;} // posle se z UartTx, hotovy prenos dat
        else
        { dut->U2Tx_fComplete = 0;} // signal je pouze jednu periodu dlouhy, proto vynulovat
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

//@brief: jednoduchá simulace slave
//@ při požadavku na čtení instrukce read = 1, se vrátí hodnota podle poslední nastavené adresy
void WbMasterDrv::simSlave(void)
{
    #ifdef SLAVE_SIM
    slave_adresa = dut->o_wb_addr;  //instrukce nastaveni adresy
    if(slave_adresa != slave_adresa_old)
    {
        slave_adresa_old_old = slave_adresa_old;
        slave_adresa_old = slave_adresa;
    }
   
    if((dut->o_wb_cyc == 1) && (o_wb_cyc_old == 0))
    { 
        dut->i_wb_ack = 0;
        ack_wait = 2;
        slave_adresa_old = slave_adresa;
    }
    else if(ack_wait > 0)
    {
        if(ack_wait == 1)
        { 
            dut->i_wb_ack = 1;
            if(dut->o_wb_we == 0)
            { 
                //slave_adresa = dut->o_wb_addr;
                dut->io_wb_data = slave_adresa;
            }//tady 5
        }
        else
        { dut->i_wb_ack = 0;}
        ack_wait = ack_wait - 1;
        
    }
    else
    { dut->i_wb_ack = 0;}

    o_wb_cyc_old = dut->o_wb_cyc;
    #endif
}

/**
 * @brief simuluje Hosta i Rx/Tx jednotky
 * tzn budou se posílat/přijímat celé znaky
 */
void WbMasterDrv::sim_HostUart(void)
{

    if(Tx_StartRst_done >= 6) //po restart sekvenci
    {
         //pozadovany prenos dat z UartTx (WB2Uart->UartTx)
        if(dut->U2Tx_Start == 1)
        { 
            DelayTx = 4; //nastavi se delay, po kterém se nastaví úspěšný přenos znaku (UartTx->WB2Uart)
        }

        if(DelayTx > 0) 
        {
            if(DelayTx == 1)    // pokud se delay rovna 1
            { 
                dut->U2Tx_fComplete = 1;
                Rx_cmd_w_sh[Rx_cmd_cnt] = dut->U2Tx_DataByte; 
                Rx_cmd_cnt ++;
            } // pošle se z UartTx, hotový přenos dat
            else
            { dut->U2Tx_fComplete = 0;} // signál je pouze jednu periodu dlouhý, proto vynulovat
            DelayTx --;    
        }
    }
    else
    {
     
    }

    //po příjmu 9 bytů, nastavit příznak, správně přijaté zprávy
    if(Rx_cmd_cnt == 9)
    {
        Rx_cmd_done = 1;
        Rx_cmd_cnt = 0;
        
        //kvuli zamezeni zaneřádění cmd, zobrazit pouze 25 instrukcí
        if(dbg_Rx_index < 25)
        { cout << "Instrukce - " << dbg_Rx_index << ": ";}
        
        for(int i = 0; i < (sizeof(Rx_cmd_w) / sizeof(char) - 1); i++)
        {
            Rx_cmd_w[i] = Rx_cmd_w_sh[i];
            Rx_cmd_w_sh[i] = 0;

            if(dbg_Rx_index < 25)
            { cout << Rx_cmd_w[i] << ", ";}
        }
        if(dbg_Rx_index < 25)
        { cout << endl;}

        dbg_Rx_index ++;

    }   
    dut -> tst1 = Rx_cmd_w[0];
    dut -> tst2 = Rx_cmd_done;
}


/*
 * simulace přijímá data, na hostovacím zařízení
 * todo možná rozdělit na 3 částí
 * dvě simulační 1. bude simulovat hosta i UART Tx/Rx jednotky - budou se přímo posílat celá slova
 *  tak i přijímat celá slova
 *               2. bude simulovat pouze hosta, tzn budou se testovat Tx/Rx jednotky 
 * jedna funkční - bude komunikovat se skutečnou jednotkou
*/
void WbMasterDrv::UartHost_Rx(void)
{

    //pro simulaci WB2UART jsou potřeba:
    // 1. WB2UART_word
    // 2. WB2UART_cyc

}

/*
 * @brief this is sim of the application in a PC
*/
void WbMasterDrv::UartHost(void)
{
    //1. todo jako prvni se posle reset signal
    //2. odesle se jakykoliv signal
    //3. pokud prikaz v kroku 2 byl w/r, tak o jeden prikaz dele, bude ten pozadovany
    
    //todo je potreba zasilat idealne cele instrukce, tzn. napr. A25,R,W44 atd... 

    /*19.11
        1.
    */
    vector<vector<int>> vec;
    vector<vector<char>> commands;

    dut->UART_Rx_done = 0;

    int nTmp = Tx_cmd_all[Tx_cmd_index];


    if(Rx_cmd_done)
    {
        Rx_cmd_done = 0;
        wait_cnt --;        //wait_cnt = 0;
        wait_A_cnt = 0;
    }


    //pokud je znak prikazu, zkontroluj zda nejsou nastaveny citace, od odeslanych prikazů
    //citace odeslanych prikazu                                                        
    if(((nTmp == 'R') || (nTmp == 'W') || (nTmp == 'A')) && ((wait_cnt + wait_A_cnt) >= 2)) 
    { Tx_stop = 1;}
    else if((wait_cnt + wait_A_cnt) < 2)
    { Tx_stop = 0;}
    else
    { /*do nothing*/}

   // else todo nulovat se musi az po prijmu nektere zpravy

    dut->Rx_wait = nTmp;
    dut->wait_A_cnt = wait_A_cnt;
    dut->wait_cnt = wait_cnt;
    dut->cmd_index = Tx_cmd_index;
    dut->tst3 = Tx_stop;
    dut->tst4 = Tx_cmd_delay;

    if((Tx_cmd_delay == 0) && (Tx_stop == 0))
    {
        if((Tx_cmd_all[Tx_cmd_index] == 'R') || (Tx_cmd_all[Tx_cmd_index] == 'W'))
        {
            /*
            1.tohle je spatne, protoze mezi tim se mi vynuluje wait signal,
            2.counter, taky neni uplne 100%, protoze kdyz prijde instrukce A, tak ta taky necha odeslat
            predchozi instrukci takze kdyz jsou instrukce RWA, tak R se odesle chybne.
            */
            if(wait_old == 0)
            { wait_old = wait;}
            wait = 1;
            wait_cnt ++;
        }
        //instrukce je adresa
        else if(Tx_cmd_all[Tx_cmd_index] == 'A')
        { 
            if(wait_cnt > 0) //pouze pokud je v WB komunikaci jiz instrukce typu R/W
            { wait_A_cnt ++;}
            
        }
        else
        { 
            wait = 0;
        }//pokud je adresa
        

        if(wait_old == 1)       
        { /*ocekavam nejaka data*/}
        else
        { /*nic neocekavam*/}

        //po uplynuti rst casovace, se zacnou posilat prikazy z pole str_vtr
        if(Tx_StartRst_done >= 6)        
        {
            WbMasterDrv::InFromUart(Tx_cmd_all[Tx_cmd_index]);  //odesle se instrukce
            Tx_cmd_delay = 8;

            if(Tx_cmd_index < (Tx_cmd_size - 1))
            { Tx_cmd_index ++;}
            else
            { Tx_cmd_index = 0;}

            Tx_cmd_index_next = Tx_cmd_index;
            if(Tx_cmd_index_next < (Tx_cmd_size - 1))
            {Tx_cmd_index_next ++;}
            else
            {Tx_cmd_index_next = 0;}
        }
        else//na zacatku se 3x posle reset
        {
            Tx_cmd_delay = 8;
            WbMasterDrv::InFromUart('S');
            Tx_StartRst_done ++;
        }
    }
    else if(Tx_cmd_delay)
    { Tx_cmd_delay --;}
    else
    {/*do nothing*/}

    

}


//todo pri odeslani se hlida, jestli se odeslala instrukce w/r, pokud ano, tak se stejne musi odeslat dalsi
//instrukce pas, ta predchozi se do mastera odesla az po této druhé instrukci. 
//@brief convert string to array of chars(maybe to vector<vector<char>> )
void WbMasterDrv::StrToChars(void)
{
    cout << "prvni znak: " << str_vtr[0][0] << endl;
    cout << "delka prvniho: " << str_vtr[0].length() << endl;
    cout << "delka prvniho znaku: " << str_vtr.size() << endl;

    for(int i = 0; i < str_vtr.size(); i++)//projede se cele pole str_vtr
    {
  
        for(int j = 0; j < str_vtr[i].length(); j++)//tady se rozlusit jednotlive znaky z instrukce 
        { Tx_cmd_all.push_back(str_vtr[i][j]);}

    //pokud se odeslalo w/r, jiz podruhe, pockat na prijem dat,
    }

    Tx_cmd_size = Tx_cmd_all.size();
    
    cout << "Velikost celeho pole: " << Tx_cmd_size << endl;
}


// 

//pro test idealne udelat slave, ze ktereho budu číst data, a ty budu kontrolovat v simulaci prijimane zpravy,



/// @brief promenne, ktere se posilaji do top_WbMastera, pro zobrazeni gtkWave
/// @param  
void WbMasterDrv::Diag_info(void)
{
    dut->slave_adresa = slave_adresa;
}