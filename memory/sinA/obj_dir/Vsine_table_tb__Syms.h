// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSINE_TABLE_TB__SYMS_H_
#define VERILATED_VSINE_TABLE_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsine_table_tb.h"

// INCLUDE MODULE CLASSES
#include "Vsine_table_tb___024root.h"

// SYMS CLASS (contains all model state)
class Vsine_table_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsine_table_tb* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsine_table_tb___024root       TOP;

    // CONSTRUCTORS
    Vsine_table_tb__Syms(VerilatedContext* contextp, const char* namep, Vsine_table_tb* modelp);
    ~Vsine_table_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
