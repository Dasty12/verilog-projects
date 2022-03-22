// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSPI_DAC.h"
#include "VSPI_DAC__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSPI_DAC::VSPI_DAC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VSPI_DAC__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
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
    vlSymsp->__Vm_activity = true;
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
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VSPI_DAC___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void VSPI_DAC::final() {
    VSPI_DAC___024root___final(&(vlSymsp->TOP));
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
// Trace configuration

void VSPI_DAC___024root__trace_init_top(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep);

static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSPI_DAC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSPI_DAC___024root*>(voidSelf);
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSPI_DAC___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VSPI_DAC___024root__trace_register(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep);

void VSPI_DAC::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSPI_DAC___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
