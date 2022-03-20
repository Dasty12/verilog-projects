// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSPI_DAC.h"
#include "VSPI_DAC__Syms.h"

//============================================================
// Constructors

VSPI_DAC::VSPI_DAC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VSPI_DAC__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ST_rise{vlSymsp->TOP.ST_rise}
    , n_CS{vlSymsp->TOP.n_CS}
    , SCK{vlSymsp->TOP.SCK}
    , SDI{vlSymsp->TOP.SDI}
    , rootp{&(vlSymsp->TOP)}
{
}

VSPI_DAC::VSPI_DAC(const char* _vcname__)
    : VSPI_DAC(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VSPI_DAC::~VSPI_DAC() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VSPI_DAC___024root___eval_initial(VSPI_DAC___024root* vlSelf);
void VSPI_DAC___024root___eval_settle(VSPI_DAC___024root* vlSelf);
void VSPI_DAC___024root___eval(VSPI_DAC___024root* vlSelf);
#ifdef VL_DEBUG
void VSPI_DAC___024root___eval_debug_assertions(VSPI_DAC___024root* vlSelf);
#endif  // VL_DEBUG
void VSPI_DAC___024root___final(VSPI_DAC___024root* vlSelf);

static void _eval_initial_loop(VSPI_DAC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VSPI_DAC___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VSPI_DAC___024root___eval_settle(&(vlSymsp->TOP));
        VSPI_DAC___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VSPI_DAC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSPI_DAC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSPI_DAC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VSPI_DAC___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VSPI_DAC::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VSPI_DAC::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VSPI_DAC::final() {
    VSPI_DAC___024root___final(&(vlSymsp->TOP));
}
