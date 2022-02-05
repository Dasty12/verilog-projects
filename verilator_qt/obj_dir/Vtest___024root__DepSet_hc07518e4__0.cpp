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
    CData/*4:0*/ __Vdly__test__DOT__state;
    IData/*31:0*/ __Vdly__test__DOT__X0;
    IData/*31:0*/ __Vdly__test__DOT__X00;
    IData/*31:0*/ __Vdly__test__DOT__X1;
    IData/*31:0*/ __Vdly__test__DOT__X2;
    IData/*31:0*/ __Vdly__test__DOT__X22;
    IData/*31:0*/ __Vdly__test__DOT__di;
    IData/*31:0*/ __Vdly__test__DOT__di2;
    IData/*31:0*/ __Vdly__test__DOT__I_1;
    // Body
    __Vdly__test__DOT__cnt = vlSelf->test__DOT__cnt;
    __Vdly__test__DOT__state = vlSelf->test__DOT__state;
    __Vdly__test__DOT__I_1 = vlSelf->test__DOT__I_1;
    __Vdly__test__DOT__di2 = vlSelf->test__DOT__di2;
    __Vdly__test__DOT__di = vlSelf->test__DOT__di;
    __Vdly__test__DOT__X22 = vlSelf->test__DOT__X22;
    __Vdly__test__DOT__X2 = vlSelf->test__DOT__X2;
    __Vdly__test__DOT__X1 = vlSelf->test__DOT__X1;
    __Vdly__test__DOT__X00 = vlSelf->test__DOT__X00;
    __Vdly__test__DOT__X0 = vlSelf->test__DOT__X0;
    if (vlSelf->rst) {
        vlSelf->test__DOT__cnt2 = 0U;
        __Vdly__test__DOT__cnt = 0U;
        __Vdly__test__DOT__state = 0U;
    } else {
        vlSelf->test__DOT__cnt2 = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->test__DOT__cnt2)));
        if ((0xaU > (IData)(vlSelf->test__DOT__cnt))) {
            __Vdly__test__DOT__cnt = (0xffffU & ((IData)(1U) 
                                                 + (IData)(vlSelf->test__DOT__cnt)));
        } else {
            vlSelf->test__DOT__out_n = (1U & (~ (IData)(vlSelf->test__DOT__out_n)));
            __Vdly__test__DOT__cnt = 0U;
        }
        if (((((((((0U == (IData)(vlSelf->test__DOT__state)) 
                   | (1U == (IData)(vlSelf->test__DOT__state))) 
                  | (2U == (IData)(vlSelf->test__DOT__state))) 
                 | (3U == (IData)(vlSelf->test__DOT__state))) 
                | (4U == (IData)(vlSelf->test__DOT__state))) 
               | (5U == (IData)(vlSelf->test__DOT__state))) 
              | (6U == (IData)(vlSelf->test__DOT__state))) 
             | (7U == (IData)(vlSelf->test__DOT__state)))) {
            if ((0U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__X0 = VL_MULS_III(32, (IData)(0xaU), vlSelf->test__DOT__I);
            } else if ((1U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__X00 = vlSelf->test__DOT__X0;
            } else if ((2U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__X1 = ((IData)(0xc8U) 
                                         - vlSelf->test__DOT__X00);
            } else if ((3U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__X2 = VL_MULS_III(32, (IData)(0x64U), vlSelf->test__DOT__X1);
            } else if ((4U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__X22 = vlSelf->test__DOT__X2;
            } else if ((5U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__di = VL_MULS_III(32, (IData)(0x1aU), vlSelf->test__DOT__X22);
            } else if ((6U == (IData)(vlSelf->test__DOT__state))) {
                __Vdly__test__DOT__di2 = (vlSelf->test__DOT__di 
                                          >> 0xaU);
            } else {
                __Vdly__test__DOT__I_1 = (vlSelf->test__DOT__I_1 
                                          + vlSelf->test__DOT__di2);
            }
        } else if ((8U == (IData)(vlSelf->test__DOT__state))) {
            vlSelf->test__DOT__I = (vlSelf->test__DOT__I_1 
                                    >> 8U);
        }
        __Vdly__test__DOT__state = ((8U > (IData)(vlSelf->test__DOT__state))
                                     ? (0x1fU & ((IData)(1U) 
                                                 + (IData)(vlSelf->test__DOT__state)))
                                     : 0U);
    }
    vlSelf->test__DOT__cnt = __Vdly__test__DOT__cnt;
    vlSelf->test__DOT__state = __Vdly__test__DOT__state;
    vlSelf->test__DOT__X0 = __Vdly__test__DOT__X0;
    vlSelf->test__DOT__X00 = __Vdly__test__DOT__X00;
    vlSelf->test__DOT__X1 = __Vdly__test__DOT__X1;
    vlSelf->test__DOT__X2 = __Vdly__test__DOT__X2;
    vlSelf->test__DOT__X22 = __Vdly__test__DOT__X22;
    vlSelf->test__DOT__di = __Vdly__test__DOT__di;
    vlSelf->test__DOT__di2 = __Vdly__test__DOT__di2;
    vlSelf->test__DOT__I_1 = __Vdly__test__DOT__I_1;
    vlSelf->cnt_out = vlSelf->test__DOT__cnt2;
    vlSelf->out = vlSelf->test__DOT__out_n;
    vlSelf->out_X0 = vlSelf->test__DOT__X0;
    vlSelf->out_X00 = vlSelf->test__DOT__X00;
    vlSelf->out_X1 = vlSelf->test__DOT__X1;
    vlSelf->out_X2 = vlSelf->test__DOT__X2;
    vlSelf->out_X22 = vlSelf->test__DOT__X22;
    vlSelf->out_di = vlSelf->test__DOT__di;
    vlSelf->out_di2 = vlSelf->test__DOT__di2;
    vlSelf->out_I_1 = vlSelf->test__DOT__I_1;
    vlSelf->out_I = vlSelf->test__DOT__I;
    vlSelf->out_I = vlSelf->test__DOT__I;
}

void Vtest___024root___eval(Vtest___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtest___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
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
