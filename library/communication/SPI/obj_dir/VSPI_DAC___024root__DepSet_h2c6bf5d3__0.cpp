// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_DAC.h for the primary calling header

#include "verilated.h"

#include "VSPI_DAC___024root.h"

VL_INLINE_OPT void VSPI_DAC___024root___sequent__TOP__2(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___sequent__TOP__2\n"); );
    // Body
    if ((0x9c4U > (IData)(vlSelf->SPI_DAC__DOT__SCK_cnt))) {
        vlSelf->SPI_DAC__DOT__SCK_cnt = (0x1fffU & 
                                         ((IData)(1U) 
                                          + (IData)(vlSelf->SPI_DAC__DOT__SCK_cnt)));
    } else {
        vlSelf->SPI_DAC__DOT__SCK_cnt = 0U;
        vlSelf->SPI_DAC__DOT__r_SCK = (1U & (~ (IData)(vlSelf->SPI_DAC__DOT__r_SCK)));
    }
    if (vlSelf->ST_rise) {
        vlSelf->SPI_DAC__DOT__SCK_cnt = 0U;
        vlSelf->SPI_DAC__DOT__r_SCK = 0U;
    }
    vlSelf->SCK = vlSelf->SPI_DAC__DOT__r_SCK;
}

VL_INLINE_OPT void VSPI_DAC___024root___sequent__TOP__4(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___sequent__TOP__4\n"); );
    // Init
    CData/*3:0*/ __Vdly__SPI_DAC__DOT__index;
    // Body
    __Vdly__SPI_DAC__DOT__index = vlSelf->SPI_DAC__DOT__index;
    if (vlSelf->ST_rise) {
        vlSelf->SPI_DAC__DOT__r_SDI = (1U & (0xc780U 
                                             >> (IData)(vlSelf->SPI_DAC__DOT__index)));
        __Vdly__SPI_DAC__DOT__index = 0U;
    } else {
        __Vdly__SPI_DAC__DOT__index = (0xfU & ((IData)(1U) 
                                               + (IData)(vlSelf->SPI_DAC__DOT__index)));
        vlSelf->SPI_DAC__DOT__r_SDI = (1U & (0xc780U 
                                             >> (IData)(vlSelf->SPI_DAC__DOT__index)));
    }
    vlSelf->SPI_DAC__DOT__index = __Vdly__SPI_DAC__DOT__index;
    vlSelf->SDI = vlSelf->SPI_DAC__DOT__r_SDI;
}

void VSPI_DAC___024root___eval(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VSPI_DAC___024root___sequent__TOP__2(vlSelf);
    }
    if ((((~ (IData)(vlSelf->SPI_DAC__DOT__r_SCK)) 
          & (IData)(vlSelf->__Vclklast__TOP__SPI_DAC__DOT__r_SCK)) 
         | ((IData)(vlSelf->ST_rise) & (~ (IData)(vlSelf->__Vclklast__TOP__ST_rise))))) {
        VSPI_DAC___024root___sequent__TOP__4(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__SPI_DAC__DOT__r_SCK = vlSelf->SPI_DAC__DOT__r_SCK;
    vlSelf->__Vclklast__TOP__ST_rise = vlSelf->ST_rise;
}

#ifdef VL_DEBUG
void VSPI_DAC___024root___eval_debug_assertions(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->ST_rise & 0xfeU))) {
        Verilated::overWidthError("ST_rise");}
}
#endif  // VL_DEBUG
