// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_square.h for the primary calling header

#ifndef VERILATED_VTOP_SQUARE___024ROOT_H_
#define VERILATED_VTOP_SQUARE___024ROOT_H_  // guard

#include "verilated.h"

class Vtop_square__Syms;
VL_MODULE(Vtop_square___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_pix,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    CData/*0:0*/ top_square__DOT__q_draw;
    CData/*0:0*/ __Vclklast__TOP__clk_pix;
    VL_OUT16(sx,9,0);
    VL_OUT16(sy,9,0);

    // INTERNAL VARIABLES
    Vtop_square__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtop_square___024root(const char* name);
    ~Vtop_square___024root();
    VL_UNCOPYABLE(Vtop_square___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vtop_square__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
