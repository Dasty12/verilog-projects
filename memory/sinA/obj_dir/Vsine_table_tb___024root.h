// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsine_table_tb.h for the primary calling header

#ifndef VERILATED_VSINE_TABLE_TB___024ROOT_H_
#define VERILATED_VSINE_TABLE_TB___024ROOT_H_  // guard

#include "verilated.h"

class Vsine_table_tb__Syms;
VL_MODULE(Vsine_table_tb___024root) {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ sine_table_tb__DOT__id;
    SData/*15:0*/ sine_table_tb__DOT__data;
    SData/*15:0*/ __Vchglast__TOP__sine_table_tb__DOT__data;
    VlUnpacked<CData/*7:0*/, 64> sine_table_tb__DOT__sine_table_inst__DOT__sine_rom__DOT__memory;

    // INTERNAL VARIABLES
    Vsine_table_tb__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vsine_table_tb___024root(const char* name);
    ~Vsine_table_tb___024root();
    VL_UNCOPYABLE(Vsine_table_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vsine_table_tb__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
