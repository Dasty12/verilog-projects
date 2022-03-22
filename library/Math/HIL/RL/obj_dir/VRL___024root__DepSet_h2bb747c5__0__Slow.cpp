// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRL.h for the primary calling header

#include "verilated.h"

#include "VRL___024root.h"

VL_ATTR_COLD void VRL___024root___initial__TOP__2(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___initial__TOP__2\n"); );
    // Body
    vlSelf->RL__DOT__state = 0U;
    vlSelf->RL__DOT__I = 0U;
}

VL_ATTR_COLD void VRL___024root___settle__TOP__3(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___settle__TOP__3\n"); );
    // Body
    vlSelf->out = vlSelf->RL__DOT__out_n;
    vlSelf->cnt_out = vlSelf->RL__DOT__cnt2;
    vlSelf->out_X0 = vlSelf->RL__DOT__X0;
    vlSelf->out_X00 = vlSelf->RL__DOT__X00;
    vlSelf->out_X1 = vlSelf->RL__DOT__X1;
    vlSelf->out_X2 = vlSelf->RL__DOT__X2;
    vlSelf->out_X22 = vlSelf->RL__DOT__X22;
    vlSelf->out_di = vlSelf->RL__DOT__di;
    vlSelf->out_di2 = vlSelf->RL__DOT__di2;
    vlSelf->out_I_1 = vlSelf->RL__DOT__I_1;
    vlSelf->out_I = vlSelf->RL__DOT__I;
    vlSelf->out_I = vlSelf->RL__DOT__I;
}

VL_ATTR_COLD void VRL___024root___eval_initial(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    VRL___024root___initial__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void VRL___024root___eval_settle(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___eval_settle\n"); );
    // Body
    VRL___024root___settle__TOP__3(vlSelf);
}

VL_ATTR_COLD void VRL___024root___final(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___final\n"); );
}

VL_ATTR_COLD void VRL___024root___ctor_var_reset(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->sig1 = VL_RAND_RESET_I(1);
    vlSelf->out = VL_RAND_RESET_I(1);
    vlSelf->cnt_out = VL_RAND_RESET_I(16);
    vlSelf->out_I = VL_RAND_RESET_I(32);
    vlSelf->out_X0 = VL_RAND_RESET_I(32);
    vlSelf->out_X00 = VL_RAND_RESET_I(32);
    vlSelf->out_X1 = VL_RAND_RESET_I(32);
    vlSelf->out_X2 = VL_RAND_RESET_I(32);
    vlSelf->out_X22 = VL_RAND_RESET_I(32);
    vlSelf->out_di = VL_RAND_RESET_I(32);
    vlSelf->out_di2 = VL_RAND_RESET_I(32);
    vlSelf->out_I_1 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__out_n = VL_RAND_RESET_I(1);
    vlSelf->RL__DOT__cnt = VL_RAND_RESET_I(16);
    vlSelf->RL__DOT__cnt2 = VL_RAND_RESET_I(16);
    vlSelf->RL__DOT__X0 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__X1 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__X2 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__di = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__i1 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__I = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__state = VL_RAND_RESET_I(5);
    vlSelf->RL__DOT__X00 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__X22 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__di2 = VL_RAND_RESET_I(32);
    vlSelf->RL__DOT__I_1 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
