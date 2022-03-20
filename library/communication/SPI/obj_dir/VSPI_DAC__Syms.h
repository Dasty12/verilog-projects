// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPI_DAC__SYMS_H_
#define VERILATED_VSPI_DAC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VSPI_DAC.h"

// INCLUDE MODULE CLASSES
#include "VSPI_DAC___024root.h"

// SYMS CLASS (contains all model state)
class VSPI_DAC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSPI_DAC* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VSPI_DAC___024root             TOP;

    // CONSTRUCTORS
    VSPI_DAC__Syms(VerilatedContext* contextp, const char* namep, VSPI_DAC* modelp);
    ~VSPI_DAC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
