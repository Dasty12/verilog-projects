#include "../sim/tb_top_sdpll.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;


class sdPllsim
{
    private:
        DUT *dut;
        int cnt;
        int sim_time;
    public:
        sdPllsim(DUT* dut)
        {
            this->dut = dut;
        }

    void whenRiseEdge(int posedge_cnt);
    void init(void);



};