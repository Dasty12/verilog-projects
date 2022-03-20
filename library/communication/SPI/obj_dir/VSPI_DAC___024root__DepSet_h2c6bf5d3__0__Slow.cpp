// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPI_DAC.h for the primary calling header

#include "verilated.h"

#include "VSPI_DAC___024root.h"

VL_ATTR_COLD void VSPI_DAC___024root___initial__TOP__2(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___initial__TOP__2\n"); );
    // Body
    vlSelf->SPI_DAC__DOT__SCK_cnt = 0U;
    vlSelf->SPI_DAC__DOT__r_SCK = 0U;
    vlSelf->SPI_DAC__DOT__index = 0U;
}

VL_ATTR_COLD void VSPI_DAC___024root___settle__TOP__3(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___settle__TOP__3\n"); );
    // Body
    vlSelf->n_CS = vlSelf->SPI_DAC__DOT__r_CS;
    vlSelf->SDI = vlSelf->SPI_DAC__DOT__r_SDI;
    vlSelf->SCK = vlSelf->SPI_DAC__DOT__r_SCK;
}

VL_ATTR_COLD void VSPI_DAC___024root___eval_initial(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    VSPI_DAC___024root___initial__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__SPI_DAC__DOT__r_SCK = 0U;
    vlSelf->__Vclklast__TOP__ST_rise = vlSelf->ST_rise;
}

VL_ATTR_COLD void VSPI_DAC___024root___eval_settle(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___eval_settle\n"); );
    // Body
    VSPI_DAC___024root___settle__TOP__3(vlSelf);
}

VL_ATTR_COLD void VSPI_DAC___024root___final(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___final\n"); );
}

VL_ATTR_COLD void VSPI_DAC___024root___ctor_var_reset(VSPI_DAC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ST_rise = VL_RAND_RESET_I(1);
    vlSelf->n_CS = VL_RAND_RESET_I(1);
    vlSelf->SCK = VL_RAND_RESET_I(1);
    vlSelf->SDI = VL_RAND_RESET_I(1);
    vlSelf->SPI_DAC__DOT__SCK_cnt = VL_RAND_RESET_I(4);
    vlSelf->SPI_DAC__DOT__r_SCK = VL_RAND_RESET_I(1);
    vlSelf->SPI_DAC__DOT__r_SDI = VL_RAND_RESET_I(1);
    vlSelf->SPI_DAC__DOT__r_CS = VL_RAND_RESET_I(1);
    vlSelf->SPI_DAC__DOT__index = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
