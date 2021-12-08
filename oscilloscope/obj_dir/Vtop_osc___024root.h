// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_osc.h for the primary calling header

#ifndef VERILATED_VTOP_OSC___024ROOT_H_
#define VERILATED_VTOP_OSC___024ROOT_H_  // guard

#include "verilated.h"

class Vtop_osc__Syms;
VL_MODULE(Vtop_osc___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);

    // INTERNAL VARIABLES
    Vtop_osc__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtop_osc___024root(const char* name);
    ~Vtop_osc___024root();
    VL_UNCOPYABLE(Vtop_osc___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vtop_osc__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
