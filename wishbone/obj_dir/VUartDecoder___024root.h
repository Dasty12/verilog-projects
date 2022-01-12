// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VUartDecoder.h for the primary calling header

#ifndef VERILATED_VUARTDECODER___024ROOT_H_
#define VERILATED_VUARTDECODER___024ROOT_H_  // guard

#include "verilated.h"

class VUartDecoder__Syms;
VL_MODULE(VUartDecoder___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_IN8(i_data_in,7,0);
    VL_IN8(i_data_valid,0,0);
    VL_IN8(i_stb,0,0);
    VL_OUT8(o_stb,0,0);
    CData/*0:0*/ UartDecoder__DOT__i_data_valid_old;
    CData/*0:0*/ UartDecoder__DOT__r_i_data_valid_rise;
    CData/*4:0*/ UartDecoder__DOT__o_bits;
    CData/*0:0*/ UartDecoder__DOT__i_stb_old;
    CData/*2:0*/ UartDecoder__DOT__array_count;
    CData/*2:0*/ UartDecoder__DOT__command;
    CData/*0:0*/ UartDecoder__DOT__cmd_loaded;
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    VL_OUT64(o_word,33,0);
    QData/*33:0*/ UartDecoder__DOT__r_word;
    QData/*33:0*/ UartDecoder__DOT__testovaci;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VUartDecoder__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VUartDecoder___024root(const char* name);
    ~VUartDecoder___024root();
    VL_UNCOPYABLE(VUartDecoder___024root);

    // INTERNAL METHODS
    void __Vconfigure(VUartDecoder__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
