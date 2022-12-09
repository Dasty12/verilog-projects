#include "sdPllsim.h"
#include <iostream>
#include <vector>

using namespace std;


void sdPllsim::init(void)
{

}

void sdPllsim::whenRiseEdge(int posedge_cnt)
{

    if(posedge_cnt < 30)
    { dut->rst = 1;}
    else
    { dut->rst = 0;}
}