// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_square.h for the primary calling header

#include "verilated.h"

#include "Vtop_square__Syms.h"
#include "Vtop_square___024root.h"

void Vtop_square___024root___ctor_var_reset(Vtop_square___024root* vlSelf);

Vtop_square___024root::Vtop_square___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtop_square___024root___ctor_var_reset(this);
}

void Vtop_square___024root::__Vconfigure(Vtop_square__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop_square___024root::~Vtop_square___024root() {
}
