// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_square.h"
#include "Vtop_square__Syms.h"

//============================================================
// Constructors

Vtop_square::Vtop_square(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vtop_square__Syms(_vcontextp__, _vcname__, this)}
    , clk_pix{vlSymsp->TOP.clk_pix}
    , rst{vlSymsp->TOP.rst}
    , de{vlSymsp->TOP.de}
    , sdl_r{vlSymsp->TOP.sdl_r}
    , sdl_g{vlSymsp->TOP.sdl_g}
    , sdl_b{vlSymsp->TOP.sdl_b}
    , sx{vlSymsp->TOP.sx}
    , sy{vlSymsp->TOP.sy}
    , rootp{&(vlSymsp->TOP)}
{
}

Vtop_square::Vtop_square(const char* _vcname__)
    : Vtop_square(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vtop_square::~Vtop_square() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtop_square___024root___eval_initial(Vtop_square___024root* vlSelf);
void Vtop_square___024root___eval_settle(Vtop_square___024root* vlSelf);
void Vtop_square___024root___eval(Vtop_square___024root* vlSelf);
#ifdef VL_DEBUG
void Vtop_square___024root___eval_debug_assertions(Vtop_square___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_square___024root___final(Vtop_square___024root* vlSelf);

static void _eval_initial_loop(Vtop_square__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtop_square___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtop_square___024root___eval_settle(&(vlSymsp->TOP));
        Vtop_square___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtop_square::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_square::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_square___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtop_square___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void Vtop_square::final() {
    Vtop_square___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vtop_square::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vtop_square::name() const {
    return vlSymsp->name();
}
