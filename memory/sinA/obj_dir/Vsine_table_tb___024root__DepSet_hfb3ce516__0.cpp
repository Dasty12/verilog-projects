// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsine_table_tb.h for the primary calling header

#include "verilated.h"

#include "Vsine_table_tb___024root.h"

void Vsine_table_tb___024root___eval(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___eval\n"); );
}

QData Vsine_table_tb___024root___change_request_1(Vsine_table_tb___024root* vlSelf);

VL_INLINE_OPT QData Vsine_table_tb___024root___change_request(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___change_request\n"); );
    // Body
    return (Vsine_table_tb___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vsine_table_tb___024root___change_request_1(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->sine_table_tb__DOT__data ^ vlSelf->__Vchglast__TOP__sine_table_tb__DOT__data));
    VL_DEBUG_IF( if(__req && ((vlSelf->sine_table_tb__DOT__data ^ vlSelf->__Vchglast__TOP__sine_table_tb__DOT__data))) VL_DBG_MSGF("        CHANGE: sine_table_tb.sv:13: sine_table_tb.data\n"); );
    // Final
    vlSelf->__Vchglast__TOP__sine_table_tb__DOT__data 
        = vlSelf->sine_table_tb__DOT__data;
    return __req;
}

#ifdef VL_DEBUG
void Vsine_table_tb___024root___eval_debug_assertions(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
