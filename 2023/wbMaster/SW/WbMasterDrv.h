#include "../sim/tb_top_WbMaster.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class WbMasterDrv
{
    private:
  

        DUT *dut;
        int cnt;
        int DelayTx;
        int index;
        int sizeOfChars;
        uint16_t previous_char;
        uint16_t previous_char_comm;
        int ack_wait;
        int o_wb_cyc_old = 0;
        int Uart_stall_old = 0;
        int Uart_stall_fall = 0;
        int cnt_stopTed = 0;
        int wait;
        int wait_old;
        int wait_cnt = 0;
        int wait_A_cnt = 0;     //
        int wait_old_old;
        int slave_adresa_old;
        int slave_adresa_old_old;
        int slave_adresa;       // slave adresa
        int dbg_Rx_index = 0;  // Značí počet zobrazených instrukcí, přijatých přes Rx

        int Tx_cmd_size;
        int Tx_cmd_index;
        int Tx_cmd_index_next;      // index následující instrukce, připravané při příštím odeslání Tx
        int Tx_cmd_delay;           // vložení timeoutu mezi jednotlivé instrukce
        int Tx_stop;                // zastavení komunikace z důvodu zaplnění mastera
        int Tx_StartRst_done = 0;   // čítač rst sekvence, po resetu zůstane naplněný

        int Rx_wait;
        int Rx_cmd_cnt = 0;
        int Rx_cmd_done = 0;
        char Rx_cmd_w[10];      // poslední přenášená instrukce
        char Rx_cmd_w_sh[10];   // poslední přenášená instrukce, shadow Arr
        vector<string> str_vtr;
        vector<char> Tx_cmd_all;
    public:
        WbMasterDrv(DUT* dut)
        {
            this -> dut = dut;
            cnt = 0;
            DelayTx;
            index = 0;
            ack_wait = 2;
            slave_adresa = dut->o_wb_addr;    //todo, nebo 0,protoze bude reset
            slave_adresa_old = slave_adresa;
            slave_adresa_old_old = slave_adresa_old;

            wait = 0;
            wait_old = 0;
            wait_old_old = 0;

            for(int i = 0;i < (sizeof(Rx_cmd_w)/sizeof(char) - 1); i++)
            {  Rx_cmd_w[i] = 0;}


            Rx_wait = 0;



            str_vtr.push_back("A40");
            str_vtr.push_back("W5");
            str_vtr.push_back("R");
            str_vtr.push_back("W255");                                                      
            str_vtr.push_back("R");
            str_vtr.push_back("A25");
            str_vtr.push_back("R");
            str_vtr.push_back("A30");
            str_vtr.push_back("A31");
            str_vtr.push_back("A32");
            str_vtr.push_back("R");
            /*TODO tohle taky dodelat, i kdyz se to chova, tak jak je to napsany,
             proste neni zadna periferie, ktera ma adresu vetsi nez 255*/
            //str_vtr.push_back("A258");
            //str_vtr.push_back("R");

            Tx_cmd_size = 0;
            Tx_cmd_index = 0;
            Tx_cmd_index_next = 0;
            Tx_cmd_delay = 0;

         //   str_vtr = new vector<string>();
        };

        void whenRiseEdge(void);
        void init(void);
        void InFromUart(char znak);
        void testWB_out(char znak);
        void simUartTx(void);
        void simUartRX_To_TX(void);
        void UartHost_Rx(void);
        void sim_HostUart(void);
        void UartHost(void);
        void StrToChars(void);
        void simSlave(void);
        void Diag_info(void);
};