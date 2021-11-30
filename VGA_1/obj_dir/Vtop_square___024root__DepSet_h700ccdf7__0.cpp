// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_square.h for the primary calling header

#include "verilated.h"

#include "Vtop_square___024root.h"

VL_INLINE_OPT void Vtop_square___024root___sequent__TOP__1(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___sequent__TOP__1\n"); );
    // Init
    SData/*9:0*/ __Vdly__sx;
    // Body
    __Vdly__sx = vlSelf->sx;
    if (vlSelf->de) {
        vlSelf->sdl_g = 0x88U;
        if (vlSelf->top_square__DOT__q_draw) {
            vlSelf->sdl_b = 0U;
            vlSelf->sdl_r = 0xffU;
        } else {
            vlSelf->sdl_b = 0xffU;
            vlSelf->sdl_r = 0U;
        }
    } else {
        vlSelf->sdl_g = 0U;
        vlSelf->sdl_b = 0U;
        vlSelf->sdl_r = 0U;
    }
    if ((0x31fU == (IData)(vlSelf->sx))) {
        vlSelf->sy = ((0x20cU == (IData)(vlSelf->sy))
                       ? 0U : (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->sy))));
        __Vdly__sx = 0U;
    } else {
        __Vdly__sx = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->sx)));
    }
    if (vlSelf->rst) {
        vlSelf->sy = 0U;
        __Vdly__sx = 0U;
    }
    vlSelf->sx = __Vdly__sx;
    vlSelf->top_square__DOT__q_draw = (((0x20U > (IData)(vlSelf->sx)) 
                                        & (0x20U > (IData)(vlSelf->sy)))
                                        ? 1U : 0U);
    vlSelf->de = ((0x27fU >= (IData)(vlSelf->sx)) & 
                  (0x1dfU >= (IData)(vlSelf->sy)));
}

void Vtop_square___024root___eval(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_pix) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_pix)))) {
        Vtop_square___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_pix = vlSelf->clk_pix;
}

#ifdef VL_DEBUG
void Vtop_square___024root___eval_debug_assertions(Vtop_square___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_square__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_square___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_pix & 0xfeU))) {
        Verilated::overWidthError("clk_pix");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
