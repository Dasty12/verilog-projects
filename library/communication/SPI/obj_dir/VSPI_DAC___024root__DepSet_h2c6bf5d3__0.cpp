// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_DAC.h for the primary calling header

#include "verilated.h"

#include "VSPI_DAC___024root.h"

VL_INLINE_OPT void VSPI_DAC___024root___sequent__TOP__1(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__SPI_DAC__DOT__r_SCK;
    CData/*0:0*/ __Vdly__SPI_DAC__DOT__r_SCK_fall;
    CData/*4:0*/ __Vdly__SPI_DAC__DOT__index;
    // Body
    __Vdly__SPI_DAC__DOT__index = vlSelf->SPI_DAC__DOT__index;
    __Vdly__SPI_DAC__DOT__r_SCK_fall = vlSelf->SPI_DAC__DOT__r_SCK_fall;
    __Vdly__SPI_DAC__DOT__r_SCK = vlSelf->SPI_DAC__DOT__r_SCK;
    if ((1U & (~ (IData)(vlSelf->SPI_DAC__DOT__r_CS)))) {
        if ((5U > (IData)(vlSelf->SPI_DAC__DOT__SCK_cnt))) {
            vlSelf->SPI_DAC__DOT__SCK_cnt = (0xfU & 
                                             ((IData)(1U) 
                                              + (IData)(vlSelf->SPI_DAC__DOT__SCK_cnt)));
        } else {
            __Vdly__SPI_DAC__DOT__r_SCK = (1U & (~ (IData)(vlSelf->SPI_DAC__DOT__r_SCK)));
            vlSelf->SPI_DAC__DOT__SCK_cnt = 0U;
        }
    }
    __Vdly__SPI_DAC__DOT__r_SCK_fall = vlSelf->SPI_DAC__DOT__r_SCK;
    if (vlSelf->rst) {
        vlSelf->SPI_DAC__DOT__r_CS = 1U;
        __Vdly__SPI_DAC__DOT__index = 0xfU;
    } else if (vlSelf->ST_rise) {
        vlSelf->SPI_DAC__DOT__r_SDI = (1U & (0x78cU 
                                             >> (0xfU 
                                                 & (IData)(vlSelf->SPI_DAC__DOT__index))));
        vlSelf->SPI_DAC__DOT__r_CS = 0U;
        __Vdly__SPI_DAC__DOT__index = 0U;
    } else if (((0xfU > (IData)(vlSelf->SPI_DAC__DOT__index)) 
                & ((IData)(vlSelf->SPI_DAC__DOT__r_SCK_fall) 
                   & (~ (IData)(vlSelf->SPI_DAC__DOT__r_SCK))))) {
        __Vdly__SPI_DAC__DOT__index = (0x1fU & ((IData)(1U) 
                                                + (IData)(vlSelf->SPI_DAC__DOT__index)));
        vlSelf->SPI_DAC__DOT__r_SDI = (1U & (0x78cU 
                                             >> (0xfU 
                                                 & (IData)(vlSelf->SPI_DAC__DOT__index))));
    } else if ((0xfU < (IData)(vlSelf->SPI_DAC__DOT__index))) {
        vlSelf->SPI_DAC__DOT__r_CS = 1U;
    }
    vlSelf->SPI_DAC__DOT__r_SCK_fall = __Vdly__SPI_DAC__DOT__r_SCK_fall;
    vlSelf->SPI_DAC__DOT__index = __Vdly__SPI_DAC__DOT__index;
    vlSelf->SPI_DAC__DOT__r_SCK = __Vdly__SPI_DAC__DOT__r_SCK;
    vlSelf->n_CS = vlSelf->SPI_DAC__DOT__r_CS;
    vlSelf->SDI = vlSelf->SPI_DAC__DOT__r_SDI;
    vlSelf->SCK = vlSelf->SPI_DAC__DOT__r_SCK;
}

void VSPI_DAC___024root___eval(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VSPI_DAC___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VSPI_DAC___024root___eval_debug_assertions(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->ST_rise & 0xfeU))) {
        Verilated::overWidthError("ST_rise");}
}
#endif  // VL_DEBUG
