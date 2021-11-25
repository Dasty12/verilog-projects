#include <stdio.h>
#include <QCoreApplication>
#include "..\Vtest.h"
#include "verilated.h"
#include <QTextStream>
int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    QCoreApplication a(argc, argv);
    Vtest *tb = new Vtest();
    QTextStream out(stdout);
    int timer =0;
    while(timer < 1000){
        tb->clk = 1;
        tb->eval();
        out << tb->out << endl;
        tb->clk = 0;
        tb->eval();
        out << tb->out << endl;
        timer++;
    }

    return a.exec();
}
