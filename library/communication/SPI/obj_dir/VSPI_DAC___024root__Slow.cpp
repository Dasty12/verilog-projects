// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_DAC.h for the primary calling header

#include "verilated.h"

#include "VSPI_DAC__Syms.h"
#include "VSPI_DAC___024root.h"

void VSPI_DAC___024root___ctor_var_reset(VSPI_DAC___024root* vlSelf);

VSPI_DAC___024root::VSPI_DAC___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSPI_DAC___024root___ctor_var_reset(this);
}

void VSPI_DAC___024root::__Vconfigure(VSPI_DAC__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSPI_DAC___024root::~VSPI_DAC___024root() {
}
