// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VUartDecoder.h"
#include "VUartDecoder__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VUartDecoder::VUartDecoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VUartDecoder__Syms(_vcontextp__, _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , i_data_in{vlSymsp->TOP.i_data_in}
    , i_data_valid{vlSymsp->TOP.i_data_valid}
    , i_stb{vlSymsp->TOP.i_stb}
    , o_stb{vlSymsp->TOP.o_stb}
    , o_word{vlSymsp->TOP.o_word}
    , rootp{&(vlSymsp->TOP)}
{
}

VUartDecoder::VUartDecoder(const char* _vcname__)
    : VUartDecoder(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VUartDecoder::~VUartDecoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VUartDecoder___024root___eval_initial(VUartDecoder___024root* vlSelf);
void VUartDecoder___024root___eval_settle(VUartDecoder___024root* vlSelf);
void VUartDecoder___024root___eval(VUartDecoder___024root* vlSelf);
#ifdef VL_DEBUG
void VUartDecoder___024root___eval_debug_assertions(VUartDecoder___024root* vlSelf);
#endif  // VL_DEBUG
void VUartDecoder___024root___final(VUartDecoder___024root* vlSelf);

static void _eval_initial_loop(VUartDecoder__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VUartDecoder___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VUartDecoder___024root___eval_settle(&(vlSymsp->TOP));
        VUartDecoder___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VUartDecoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VUartDecoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VUartDecoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VUartDecoder___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VUartDecoder::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VUartDecoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VUartDecoder::final() {
    VUartDecoder___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void VUartDecoder___024root__trace_init_top(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VUartDecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUartDecoder___024root*>(voidSelf);
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VUartDecoder___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VUartDecoder___024root__trace_register(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VUartDecoder::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VUartDecoder___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
