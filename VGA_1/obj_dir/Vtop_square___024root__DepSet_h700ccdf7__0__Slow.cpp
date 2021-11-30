// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_square.h for the primary calling header

#include "verilated.h"

#include "Vtop_square___024root.h"

VL_ATTR_COLD void Vtop_square___024root___settle__TOP__2(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->top_square__DOT__q_draw = (((0x20U > (IData)(vlSelf->sx)) 
                                        & (0x20U > (IData)(vlSelf->sy)))
                                        ? 1U : 0U);
    vlSelf->de = ((0x27fU >= (IData)(vlSelf->sx)) & 
                  (0x1dfU >= (IData)(vlSelf->sy)));
}

VL_ATTR_COLD void Vtop_square___024root___eval_initial(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_pix = vlSelf->clk_pix;
}

VL_ATTR_COLD void Vtop_square___024root___eval_settle(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___eval_settle\n"); );
    // Body
    Vtop_square___024root___settle__TOP__2(vlSelf);
}

VL_ATTR_COLD void Vtop_square___024root___final(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___final\n"); );
}

VL_ATTR_COLD void Vtop_square___024root___ctor_var_reset(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_pix = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->sx = VL_RAND_RESET_I(10);
    vlSelf->sy = VL_RAND_RESET_I(10);
    vlSelf->de = VL_RAND_RESET_I(1);
    vlSelf->sdl_r = VL_RAND_RESET_I(8);
    vlSelf->sdl_g = VL_RAND_RESET_I(8);
    vlSelf->sdl_b = VL_RAND_RESET_I(8);
    vlSelf->top_square__DOT__q_draw = VL_RAND_RESET_I(1);
}
