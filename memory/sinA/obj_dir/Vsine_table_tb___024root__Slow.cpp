// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsine_table_tb.h for the primary calling header

#include "verilated.h"

#include "Vsine_table_tb__Syms.h"
#include "Vsine_table_tb___024root.h"

void Vsine_table_tb___024root___ctor_var_reset(Vsine_table_tb___024root* vlSelf);

Vsine_table_tb___024root::Vsine_table_tb___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vsine_table_tb___024root___ctor_var_reset(this);
}

void Vsine_table_tb___024root::__Vconfigure(Vsine_table_tb__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vsine_table_tb___024root::~Vsine_table_tb___024root() {
}
