// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUartDecoder.h for the primary calling header

#include "verilated.h"

#include "VUartDecoder__Syms.h"
#include "VUartDecoder___024root.h"

void VUartDecoder___024root___ctor_var_reset(VUartDecoder___024root* vlSelf);

VUartDecoder___024root::VUartDecoder___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VUartDecoder___024root___ctor_var_reset(this);
}

void VUartDecoder___024root::__Vconfigure(VUartDecoder__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VUartDecoder___024root::~VUartDecoder___024root() {
}
