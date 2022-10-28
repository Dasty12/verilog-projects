// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTOP_UART2WB__SYMS_H_
#define _VTOP_UART2WB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtop_Uart2wb.h"
#include "Vtop_Uart2wb___024unit.h"

// SYMS CLASS
class Vtop_Uart2wb__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtop_Uart2wb*                  TOPp;
    
    // CREATORS
    Vtop_Uart2wb__Syms(Vtop_Uart2wb* topp, const char* namep);
    ~Vtop_Uart2wb__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
