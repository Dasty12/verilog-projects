// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtest.h for the primary calling header

#ifndef VERILATED_VTEST___024ROOT_H_
#define VERILATED_VTEST___024ROOT_H_  // guard

#include "verilated.h"

class Vtest__Syms;
VL_MODULE(Vtest___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(sig1,0,0);
    VL_OUT8(out,0,0);
    CData/*0:0*/ test__DOT__out_n;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT16(cnt_out,15,0);
    SData/*15:0*/ test__DOT__cnt;
    SData/*15:0*/ test__DOT__cnt2;

    // INTERNAL VARIABLES
    Vtest__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtest___024root(const char* name);
    ~Vtest___024root();
    VL_UNCOPYABLE(Vtest___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vtest__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
