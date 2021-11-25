// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest.h for the primary calling header

#include "verilated.h"

#include "Vtest___024root.h"

VL_INLINE_OPT void Vtest___024root___sequent__TOP__1(Vtest___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest___024root___sequent__TOP__1\n"); );
    // Init
    SData/*15:0*/ __Vdly__test__DOT__cnt;
    SData/*15:0*/ __Vdly__test__DOT__cnt2;
    // Body
    __Vdly__test__DOT__cnt = vlSelf->test__DOT__cnt;
    __Vdly__test__DOT__cnt2 = vlSelf->test__DOT__cnt2;
    if (vlSelf->rst) {
        __Vdly__test__DOT__cnt2 = 0U;
    }
    __Vdly__test__DOT__cnt2 = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->test__DOT__cnt2)));
    if (vlSelf->rst) {
        __Vdly__test__DOT__cnt = 0U;
    }
    if ((0xaU > (IData)(vlSelf->test__DOT__cnt))) {
        __Vdly__test__DOT__cnt = (0xffffU & ((IData)(1U) 
                                             + (IData)(vlSelf->test__DOT__cnt)));
    } else {
        vlSelf->test__DOT__out_n = (1U & (~ (IData)(vlSelf->test__DOT__out_n)));
        __Vdly__test__DOT__cnt = 0U;
    }
    vlSelf->test__DOT__cnt2 = __Vdly__test__DOT__cnt2;
    vlSelf->test__DOT__cnt = __Vdly__test__DOT__cnt;
    vlSelf->cnt_out = vlSelf->test__DOT__cnt2;
    vlSelf->out = vlSelf->test__DOT__out_n;
}

void Vtest___024root___eval(Vtest___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtest___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtest___024root___eval_debug_assertions(Vtest___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->sig1 & 0xfeU))) {
        Verilated::overWidthError("sig1");}
}
#endif  // VL_DEBUG
