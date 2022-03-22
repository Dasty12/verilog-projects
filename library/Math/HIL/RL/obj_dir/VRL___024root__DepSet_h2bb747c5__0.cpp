// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRL.h for the primary calling header

#include "verilated.h"

#include "VRL___024root.h"

VL_INLINE_OPT void VRL___024root___sequent__TOP__1(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___sequent__TOP__1\n"); );
    // Init
    SData/*15:0*/ __Vdly__RL__DOT__cnt;
    CData/*4:0*/ __Vdly__RL__DOT__state;
    IData/*31:0*/ __Vdly__RL__DOT__X0;
    IData/*31:0*/ __Vdly__RL__DOT__X00;
    IData/*31:0*/ __Vdly__RL__DOT__X1;
    IData/*31:0*/ __Vdly__RL__DOT__X2;
    IData/*31:0*/ __Vdly__RL__DOT__X22;
    IData/*31:0*/ __Vdly__RL__DOT__di;
    IData/*31:0*/ __Vdly__RL__DOT__di2;
    IData/*31:0*/ __Vdly__RL__DOT__I_1;
    // Body
    __Vdly__RL__DOT__cnt = vlSelf->RL__DOT__cnt;
    __Vdly__RL__DOT__state = vlSelf->RL__DOT__state;
    __Vdly__RL__DOT__I_1 = vlSelf->RL__DOT__I_1;
    __Vdly__RL__DOT__di2 = vlSelf->RL__DOT__di2;
    __Vdly__RL__DOT__di = vlSelf->RL__DOT__di;
    __Vdly__RL__DOT__X22 = vlSelf->RL__DOT__X22;
    __Vdly__RL__DOT__X2 = vlSelf->RL__DOT__X2;
    __Vdly__RL__DOT__X1 = vlSelf->RL__DOT__X1;
    __Vdly__RL__DOT__X00 = vlSelf->RL__DOT__X00;
    __Vdly__RL__DOT__X0 = vlSelf->RL__DOT__X0;
    if (vlSelf->rst) {
        vlSelf->RL__DOT__cnt2 = 0U;
        __Vdly__RL__DOT__cnt = 0U;
        __Vdly__RL__DOT__state = 0U;
    } else {
        vlSelf->RL__DOT__cnt2 = (0xffffU & ((IData)(1U) 
                                            + (IData)(vlSelf->RL__DOT__cnt2)));
        if ((0xaU > (IData)(vlSelf->RL__DOT__cnt))) {
            __Vdly__RL__DOT__cnt = (0xffffU & ((IData)(1U) 
                                               + (IData)(vlSelf->RL__DOT__cnt)));
        } else {
            vlSelf->RL__DOT__out_n = (1U & (~ (IData)(vlSelf->RL__DOT__out_n)));
            __Vdly__RL__DOT__cnt = 0U;
        }
        if (((((((((0U == (IData)(vlSelf->RL__DOT__state)) 
                   | (1U == (IData)(vlSelf->RL__DOT__state))) 
                  | (2U == (IData)(vlSelf->RL__DOT__state))) 
                 | (3U == (IData)(vlSelf->RL__DOT__state))) 
                | (4U == (IData)(vlSelf->RL__DOT__state))) 
               | (5U == (IData)(vlSelf->RL__DOT__state))) 
              | (6U == (IData)(vlSelf->RL__DOT__state))) 
             | (7U == (IData)(vlSelf->RL__DOT__state)))) {
            if ((0U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__X0 = VL_MULS_III(32,32,32, (IData)(0xaU), vlSelf->RL__DOT__I);
            } else if ((1U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__X00 = vlSelf->RL__DOT__X0;
            } else if ((2U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__X1 = ((IData)(0xc8U) 
                                       - vlSelf->RL__DOT__X00);
            } else if ((3U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__X2 = VL_MULS_III(32,32,32, (IData)(0x64U), vlSelf->RL__DOT__X1);
            } else if ((4U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__X22 = vlSelf->RL__DOT__X2;
            } else if ((5U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__di = VL_MULS_III(32,32,32, (IData)(0x1aU), vlSelf->RL__DOT__X22);
            } else if ((6U == (IData)(vlSelf->RL__DOT__state))) {
                __Vdly__RL__DOT__di2 = (vlSelf->RL__DOT__di 
                                        >> 0xaU);
            } else {
                __Vdly__RL__DOT__I_1 = (vlSelf->RL__DOT__I_1 
                                        + vlSelf->RL__DOT__di2);
            }
        } else if ((8U == (IData)(vlSelf->RL__DOT__state))) {
            vlSelf->RL__DOT__I = (vlSelf->RL__DOT__I_1 
                                  >> 8U);
        }
        __Vdly__RL__DOT__state = ((8U > (IData)(vlSelf->RL__DOT__state))
                                   ? (0x1fU & ((IData)(1U) 
                                               + (IData)(vlSelf->RL__DOT__state)))
                                   : 0U);
    }
    vlSelf->RL__DOT__cnt = __Vdly__RL__DOT__cnt;
    vlSelf->RL__DOT__state = __Vdly__RL__DOT__state;
    vlSelf->RL__DOT__X0 = __Vdly__RL__DOT__X0;
    vlSelf->RL__DOT__X00 = __Vdly__RL__DOT__X00;
    vlSelf->RL__DOT__X1 = __Vdly__RL__DOT__X1;
    vlSelf->RL__DOT__X2 = __Vdly__RL__DOT__X2;
    vlSelf->RL__DOT__X22 = __Vdly__RL__DOT__X22;
    vlSelf->RL__DOT__di = __Vdly__RL__DOT__di;
    vlSelf->RL__DOT__di2 = __Vdly__RL__DOT__di2;
    vlSelf->RL__DOT__I_1 = __Vdly__RL__DOT__I_1;
    vlSelf->cnt_out = vlSelf->RL__DOT__cnt2;
    vlSelf->out = vlSelf->RL__DOT__out_n;
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

void VRL___024root___eval(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VRL___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VRL___024root___eval_debug_assertions(VRL___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->sig1 & 0xfeU))) {
        Verilated::overWidthError("sig1");}
}
#endif  // VL_DEBUG
