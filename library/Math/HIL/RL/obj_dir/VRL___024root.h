// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRL.h for the primary calling header

#ifndef VERILATED_VRL___024ROOT_H_
#define VERILATED_VRL___024ROOT_H_  // guard

#include "verilated.h"

class VRL__Syms;
VL_MODULE(VRL___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(sig1,0,0);
    VL_OUT8(out,0,0);
    CData/*0:0*/ RL__DOT__out_n;
    CData/*4:0*/ RL__DOT__state;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT16(cnt_out,15,0);
    SData/*15:0*/ RL__DOT__cnt;
    SData/*15:0*/ RL__DOT__cnt2;
    VL_OUT(out_I,31,0);
    VL_OUT(out_X0,31,0);
    VL_OUT(out_X00,31,0);
    VL_OUT(out_X1,31,0);
    VL_OUT(out_X2,31,0);
    VL_OUT(out_X22,31,0);
    VL_OUT(out_di,31,0);
    VL_OUT(out_di2,31,0);
    VL_OUT(out_I_1,31,0);
    IData/*31:0*/ RL__DOT__X0;
    IData/*31:0*/ RL__DOT__X1;
    IData/*31:0*/ RL__DOT__X2;
    IData/*31:0*/ RL__DOT__di;
    IData/*31:0*/ RL__DOT__i1;
    IData/*31:0*/ RL__DOT__I;
    IData/*31:0*/ RL__DOT__X00;
    IData/*31:0*/ RL__DOT__X22;
    IData/*31:0*/ RL__DOT__di2;
    IData/*31:0*/ RL__DOT__I_1;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VRL__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VRL___024root(const char* name);
    ~VRL___024root();
    VL_UNCOPYABLE(VRL___024root);

    // INTERNAL METHODS
    void __Vconfigure(VRL__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
