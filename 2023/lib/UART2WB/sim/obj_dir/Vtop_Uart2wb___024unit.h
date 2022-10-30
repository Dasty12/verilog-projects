// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_Uart2wb.h for the primary calling header

#ifndef _VTOP_UART2WB___024UNIT_H_
#define _VTOP_UART2WB___024UNIT_H_  // guard

#include "verilated.h"

//==========

class Vtop_Uart2wb__Syms;
class Vtop_Uart2wb_VerilatedVcd;


//----------

VL_MODULE(Vtop_Uart2wb___024unit) {
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
    Vtop_Uart2wb__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_Uart2wb___024unit);  ///< Copying not allowed
  public:
    Vtop_Uart2wb___024unit(const char* name = "TOP");
    ~Vtop_Uart2wb___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop_Uart2wb__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard