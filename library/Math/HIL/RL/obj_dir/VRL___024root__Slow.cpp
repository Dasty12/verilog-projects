// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRL.h for the primary calling header

#include "verilated.h"

#include "VRL__Syms.h"
#include "VRL___024root.h"

void VRL___024root___ctor_var_reset(VRL___024root* vlSelf);

VRL___024root::VRL___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VRL___024root___ctor_var_reset(this);
}

void VRL___024root::__Vconfigure(VRL__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VRL___024root::~VRL___024root() {
}
