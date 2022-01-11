// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUartDecoder.h for the primary calling header

#include "verilated.h"

#include "VUartDecoder___024root.h"

VL_ATTR_COLD void VUartDecoder___024root___initial__TOP__1(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___initial__TOP__1\n"); );
    // Body
    vlSelf->o_word = 0x300000000ULL;
    vlSelf->UartDecoder__DOT__cmd_loaded = 0U;
}

VL_ATTR_COLD void VUartDecoder___024root___eval_initial(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___eval_initial\n"); );
    // Body
    VUartDecoder___024root___initial__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
}

void VUartDecoder___024root___settle__TOP__3(VUartDecoder___024root* vlSelf);

VL_ATTR_COLD void VUartDecoder___024root___eval_settle(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___eval_settle\n"); );
    // Body
    VUartDecoder___024root___settle__TOP__3(vlSelf);
}

VL_ATTR_COLD void VUartDecoder___024root___final(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___final\n"); );
}

VL_ATTR_COLD void VUartDecoder___024root___ctor_var_reset(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->i_data_in = VL_RAND_RESET_I(8);
    vlSelf->i_data_valid = VL_RAND_RESET_I(1);
    vlSelf->i_stb = VL_RAND_RESET_I(1);
    vlSelf->o_stb = VL_RAND_RESET_I(1);
    vlSelf->o_word = VL_RAND_RESET_Q(34);
    vlSelf->UartDecoder__DOT__i_data_valid_old = VL_RAND_RESET_I(1);
    vlSelf->UartDecoder__DOT__i_data_valid_rise = VL_RAND_RESET_I(1);
    vlSelf->UartDecoder__DOT__o_bits = VL_RAND_RESET_I(5);
    vlSelf->UartDecoder__DOT__r_word = VL_RAND_RESET_Q(34);
    vlSelf->UartDecoder__DOT__array_count = VL_RAND_RESET_I(3);
    vlSelf->UartDecoder__DOT__command = VL_RAND_RESET_I(3);
    vlSelf->UartDecoder__DOT__cmd_loaded = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
