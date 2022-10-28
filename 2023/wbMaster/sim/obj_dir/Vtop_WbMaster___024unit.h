// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_WbMaster.h for the primary calling header

#ifndef _VTOP_WBMASTER___024UNIT_H_
#define _VTOP_WBMASTER___024UNIT_H_  // guard

#include "verilated.h"

//==========

class Vtop_WbMaster__Syms;
class Vtop_WbMaster_VerilatedVcd;


//----------

VL_MODULE(Vtop_WbMaster___024unit) {
  public:
    
    // TYPEDEFS
    // That were declared public
    enum operation_t {
        add = 1U,
        sub = 2U,
        nop = 0U
    };
    
    // INTERNAL VARIABLES
  private:
    Vtop_WbMaster__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_WbMaster___024unit);  ///< Copying not allowed
  public:
    Vtop_WbMaster___024unit(const char* name = "TOP");
    ~Vtop_WbMaster___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop_WbMaster__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
