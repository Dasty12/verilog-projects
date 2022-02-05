// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUartDecoder.h for the primary calling header

#include "verilated.h"

#include "VUartDecoder___024root.h"

extern const VlUnpacked<CData/*4:0*/, 256> VUartDecoder__ConstPool__TABLE_h09631c4c_0;

VL_INLINE_OPT void VUartDecoder___024root___sequent__TOP__2(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___sequent__TOP__2\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    QData/*33:0*/ __Vdly__UartDecoder__DOT__r_word;
    // Body
    __Vdly__UartDecoder__DOT__r_word = vlSelf->UartDecoder__DOT__r_word;
    vlSelf->UartDecoder__DOT__i_data_valid_old = vlSelf->i_data_valid;
    if (vlSelf->i_stb) {
        vlSelf->UartDecoder__DOT__i_stb_old = 1U;
        vlSelf->UartDecoder__DOT__r_i_data_valid_rise = 1U;
        if ((4U == (7U & ((IData)(vlSelf->UartDecoder__DOT__o_bits) 
                          >> 2U)))) {
            vlSelf->UartDecoder__DOT__command = (7U 
                                                 & (IData)(vlSelf->UartDecoder__DOT__o_bits));
            vlSelf->UartDecoder__DOT__array_count = 0U;
            __Vdly__UartDecoder__DOT__r_word = ((QData)((IData)(
                                                                (3U 
                                                                 & (IData)(vlSelf->UartDecoder__DOT__o_bits)))) 
                                                << 0x20U);
        } else if ((0x1fU != (IData)(vlSelf->UartDecoder__DOT__o_bits))) {
            vlSelf->UartDecoder__DOT__array_count = 
                (7U & ((IData)(1U) + (IData)(vlSelf->UartDecoder__DOT__array_count)));
            __Vdly__UartDecoder__DOT__r_word = ((0x300000000ULL 
                                                 & __Vdly__UartDecoder__DOT__r_word) 
                                                | (IData)((IData)(
                                                                  (((IData)(vlSelf->UartDecoder__DOT__r_word) 
                                                                    << 4U) 
                                                                   | (0xfU 
                                                                      & (IData)(vlSelf->UartDecoder__DOT__o_bits))))));
        } else {
            vlSelf->UartDecoder__DOT__array_count = 0U;
        }
    } else {
        vlSelf->UartDecoder__DOT__i_stb_old = 0U;
        vlSelf->UartDecoder__DOT__r_i_data_valid_rise = 0U;
    }
    if (vlSelf->o_stb) {
        vlSelf->UartDecoder__DOT__testovaci = vlSelf->o_word;
    }
    if (vlSelf->i_stb) {
        vlSelf->o_word = vlSelf->UartDecoder__DOT__r_word;
    }
    vlSelf->o_stb = (((IData)(vlSelf->i_stb) & (IData)(vlSelf->UartDecoder__DOT__cmd_loaded)) 
                     & ((IData)(vlSelf->UartDecoder__DOT__o_bits) 
                        >> 4U));
    vlSelf->UartDecoder__DOT__r_word = __Vdly__UartDecoder__DOT__r_word;
    if (vlSelf->i_stb) {
        vlSelf->UartDecoder__DOT__cmd_loaded = (4U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->UartDecoder__DOT__o_bits) 
                                                    >> 2U)));
    }
    __Vtableidx1 = vlSelf->i_data_in;
    vlSelf->UartDecoder__DOT__o_bits = VUartDecoder__ConstPool__TABLE_h09631c4c_0
        [__Vtableidx1];
}

void VUartDecoder___024root___eval(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->i_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__i_clk)))) {
        VUartDecoder___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
}

#ifdef VL_DEBUG
void VUartDecoder___024root___eval_debug_assertions(VUartDecoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((vlSelf->i_data_valid & 0xfeU))) {
        Verilated::overWidthError("i_data_valid");}
    if (VL_UNLIKELY((vlSelf->i_stb & 0xfeU))) {
        Verilated::overWidthError("i_stb");}
}
#endif  // VL_DEBUG
