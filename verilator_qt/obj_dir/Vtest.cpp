// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtest.h"
#include "Vtest__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtest::Vtest(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vtest__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , sig1{vlSymsp->TOP.sig1}
    , out{vlSymsp->TOP.out}
    , cnt_out{vlSymsp->TOP.cnt_out}
    , out_I{vlSymsp->TOP.out_I}
    , out_X0{vlSymsp->TOP.out_X0}
    , out_X00{vlSymsp->TOP.out_X00}
    , out_X1{vlSymsp->TOP.out_X1}
    , out_X2{vlSymsp->TOP.out_X2}
    , out_X22{vlSymsp->TOP.out_X22}
    , out_di{vlSymsp->TOP.out_di}
    , out_di2{vlSymsp->TOP.out_di2}
    , out_I_1{vlSymsp->TOP.out_I_1}
    , rootp{&(vlSymsp->TOP)}
{
}

Vtest::Vtest(const char* _vcname__)
    : Vtest(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vtest::~Vtest() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtest___024root___eval_initial(Vtest___024root* vlSelf);
void Vtest___024root___eval_settle(Vtest___024root* vlSelf);
void Vtest___024root___eval(Vtest___024root* vlSelf);
#ifdef VL_DEBUG
void Vtest___024root___eval_debug_assertions(Vtest___024root* vlSelf);
#endif  // VL_DEBUG
void Vtest___024root___final(Vtest___024root* vlSelf);

static void _eval_initial_loop(Vtest__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtest___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtest___024root___eval_settle(&(vlSymsp->TOP));
        Vtest___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtest::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtest___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtest___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void Vtest::final() {
    Vtest___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vtest::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vtest::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vtest___024root__trace_init_top(Vtest___024root* vlSelf, VerilatedVcd* tracep);

static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtest___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtest___024root*>(voidSelf);
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtest___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vtest___024root__trace_register(Vtest___024root* vlSelf, VerilatedVcd* tracep);

void Vtest::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtest___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
