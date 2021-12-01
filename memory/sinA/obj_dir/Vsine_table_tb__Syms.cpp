// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsine_table_tb__Syms.h"
#include "Vsine_table_tb.h"
#include "Vsine_table_tb___024root.h"

// FUNCTIONS
Vsine_table_tb__Syms::~Vsine_table_tb__Syms()
{
}

Vsine_table_tb__Syms::Vsine_table_tb__Syms(VerilatedContext* contextp, const char* namep,Vsine_table_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
