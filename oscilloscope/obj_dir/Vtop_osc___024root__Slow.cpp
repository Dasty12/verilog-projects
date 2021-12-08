// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_osc.h for the primary calling header

#include "verilated.h"

#include "Vtop_osc__Syms.h"
#include "Vtop_osc___024root.h"

void Vtop_osc___024root___ctor_var_reset(Vtop_osc___024root* vlSelf);

Vtop_osc___024root::Vtop_osc___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtop_osc___024root___ctor_var_reset(this);
}

void Vtop_osc___024root::__Vconfigure(Vtop_osc__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop_osc___024root::~Vtop_osc___024root() {
}
