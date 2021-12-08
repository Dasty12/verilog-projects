// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_osc.h for the primary calling header

#include "verilated.h"

#include "Vtop_osc___024root.h"

void Vtop_osc___024root___eval(Vtop_osc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_osc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_osc___024root___eval\n"); );
}

#ifdef VL_DEBUG
void Vtop_osc___024root___eval_debug_assertions(Vtop_osc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_osc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_osc___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
