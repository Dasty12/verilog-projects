// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSPI_DAC.h for the primary calling header

#ifndef VERILATED_VSPI_DAC___024ROOT_H_
#define VERILATED_VSPI_DAC___024ROOT_H_  // guard

#include "verilated.h"

class VSPI_DAC__Syms;
VL_MODULE(VSPI_DAC___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(ST_rise,0,0);
    VL_OUT8(n_CS,0,0);
    VL_OUT8(SCK,0,0);
    VL_OUT8(SDI,0,0);
    CData/*3:0*/ SPI_DAC__DOT__SCK_cnt;
    CData/*0:0*/ SPI_DAC__DOT__r_SCK;
    CData/*0:0*/ SPI_DAC__DOT__r_SDI;
    CData/*0:0*/ SPI_DAC__DOT__r_CS;
    CData/*4:0*/ SPI_DAC__DOT__index;
    CData/*0:0*/ SPI_DAC__DOT__r_SCK_fall;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VSPI_DAC__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VSPI_DAC___024root(const char* name);
    ~VSPI_DAC___024root();
    VL_UNCOPYABLE(VSPI_DAC___024root);

    // INTERNAL METHODS
    void __Vconfigure(VSPI_DAC__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
