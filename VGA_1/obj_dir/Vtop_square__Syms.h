// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_SQUARE__SYMS_H_
#define VERILATED_VTOP_SQUARE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_square.h"

// INCLUDE MODULE CLASSES
#include "Vtop_square___024root.h"

// SYMS CLASS (contains all model state)
class Vtop_square__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_square* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_square___024root          TOP;

    // CONSTRUCTORS
    Vtop_square__Syms(VerilatedContext* contextp, const char* namep, Vtop_square* modelp);
    ~Vtop_square__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
