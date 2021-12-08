// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_osc.h"
#include "Vtop_osc__Syms.h"

//============================================================
// Constructors

Vtop_osc::Vtop_osc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vtop_osc__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rootp{&(vlSymsp->TOP)}
{
}

Vtop_osc::Vtop_osc(const char* _vcname__)
    : Vtop_osc(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vtop_osc::~Vtop_osc() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtop_osc___024root___eval_initial(Vtop_osc___024root* vlSelf);
void Vtop_osc___024root___eval_settle(Vtop_osc___024root* vlSelf);
void Vtop_osc___024root___eval(Vtop_osc___024root* vlSelf);
#ifdef VL_DEBUG
void Vtop_osc___024root___eval_debug_assertions(Vtop_osc___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_osc___024root___final(Vtop_osc___024root* vlSelf);

static void _eval_initial_loop(Vtop_osc__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtop_osc___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtop_osc___024root___eval_settle(&(vlSymsp->TOP));
        Vtop_osc___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtop_osc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_osc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_osc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtop_osc___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void Vtop_osc::final() {
    Vtop_osc___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vtop_osc::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vtop_osc::name() const {
    return vlSymsp->name();
}
