// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VUartDecoder__Syms.h"


void VUartDecoder___024root__trace_chg_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep);

void VUartDecoder___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_chg_top_0\n"); );
    // Init
    VUartDecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUartDecoder___024root*>(voidSelf);
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VUartDecoder___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VUartDecoder___024root__trace_chg_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgBit(oldp+0,(vlSelf->UartDecoder__DOT__i_data_valid_old));
        tracep->chgBit(oldp+1,(vlSelf->UartDecoder__DOT__r_i_data_valid_rise));
        tracep->chgCData(oldp+2,(vlSelf->UartDecoder__DOT__o_bits),5);
        tracep->chgBit(oldp+3,(vlSelf->UartDecoder__DOT__i_stb_old));
        tracep->chgQData(oldp+4,(vlSelf->UartDecoder__DOT__r_word),34);
        tracep->chgCData(oldp+6,(vlSelf->UartDecoder__DOT__array_count),3);
        tracep->chgCData(oldp+7,(vlSelf->UartDecoder__DOT__command),3);
        tracep->chgBit(oldp+8,(vlSelf->UartDecoder__DOT__cmd_loaded));
        tracep->chgQData(oldp+9,(vlSelf->UartDecoder__DOT__testovaci),34);
    }
    tracep->chgBit(oldp+11,(vlSelf->i_clk));
    tracep->chgCData(oldp+12,(vlSelf->i_data_in),8);
    tracep->chgBit(oldp+13,(vlSelf->i_data_valid));
    tracep->chgBit(oldp+14,(vlSelf->i_stb));
    tracep->chgBit(oldp+15,(vlSelf->o_stb));
    tracep->chgQData(oldp+16,(vlSelf->o_word),34);
    tracep->chgBit(oldp+18,(((IData)(vlSelf->i_data_valid) 
                             & (~ (IData)(vlSelf->UartDecoder__DOT__i_data_valid_old)))));
}

void VUartDecoder___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_cleanup\n"); );
    // Init
    VUartDecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUartDecoder___024root*>(voidSelf);
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
