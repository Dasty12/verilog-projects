// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsine_table_tb.h"
#include "Vsine_table_tb__Syms.h"

//============================================================
// Constructors

Vsine_table_tb::Vsine_table_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vsine_table_tb__Syms(_vcontextp__, _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
}

Vsine_table_tb::Vsine_table_tb(const char* _vcname__)
    : Vsine_table_tb(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vsine_table_tb::~Vsine_table_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsine_table_tb___024root___eval_initial(Vsine_table_tb___024root* vlSelf);
void Vsine_table_tb___024root___eval_settle(Vsine_table_tb___024root* vlSelf);
void Vsine_table_tb___024root___eval(Vsine_table_tb___024root* vlSelf);
QData Vsine_table_tb___024root___change_request(Vsine_table_tb___024root* vlSelf);
#ifdef VL_DEBUG
void Vsine_table_tb___024root___eval_debug_assertions(Vsine_table_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsine_table_tb___024root___final(Vsine_table_tb___024root* vlSelf);

static void _eval_initial_loop(Vsine_table_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsine_table_tb___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsine_table_tb___024root___eval_settle(&(vlSymsp->TOP));
        Vsine_table_tb___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vsine_table_tb___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sine_table_tb.sv", 5, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vsine_table_tb___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsine_table_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsine_table_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsine_table_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsine_table_tb___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vsine_table_tb___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sine_table_tb.sv", 5, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vsine_table_tb___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void Vsine_table_tb::final() {
    Vsine_table_tb___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vsine_table_tb::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vsine_table_tb::name() const {
    return vlSymsp->name();
}
