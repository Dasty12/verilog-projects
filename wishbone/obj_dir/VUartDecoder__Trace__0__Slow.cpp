// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VUartDecoder__Syms.h"


VL_ATTR_COLD void VUartDecoder___024root__trace_init_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VUartDecoder___024root__trace_init_top(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_init_top\n"); );
    // Body
    VUartDecoder___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void VUartDecoder___024root__trace_init_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+8,"i_clk", false,-1);
    tracep->declBus(c+9,"i_data_in", false,-1, 7,0);
    tracep->declBit(c+10,"i_data_valid", false,-1);
    tracep->declBit(c+11,"i_stb", false,-1);
    tracep->declBit(c+12,"o_stb", false,-1);
    tracep->declQuad(c+13,"o_word", false,-1, 33,0);
    tracep->declBit(c+8,"UartDecoder i_clk", false,-1);
    tracep->declBus(c+9,"UartDecoder i_data_in", false,-1, 7,0);
    tracep->declBit(c+10,"UartDecoder i_data_valid", false,-1);
    tracep->declBit(c+11,"UartDecoder i_stb", false,-1);
    tracep->declBit(c+12,"UartDecoder o_stb", false,-1);
    tracep->declQuad(c+13,"UartDecoder o_word", false,-1, 33,0);
    tracep->declBit(c+1,"UartDecoder i_data_valid_old", false,-1);
    tracep->declBit(c+15,"UartDecoder i_data_valid_rise", false,-1);
    tracep->declBus(c+2,"UartDecoder o_bits", false,-1, 4,0);
    tracep->declQuad(c+3,"UartDecoder r_word", false,-1, 33,0);
    tracep->declBus(c+5,"UartDecoder array_count", false,-1, 2,0);
    tracep->declBus(c+6,"UartDecoder command", false,-1, 2,0);
    tracep->declBit(c+7,"UartDecoder cmd_loaded", false,-1);
}

VL_ATTR_COLD void VUartDecoder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VUartDecoder___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VUartDecoder___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VUartDecoder___024root__trace_register(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VUartDecoder___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VUartDecoder___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VUartDecoder___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VUartDecoder___024root__trace_full_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VUartDecoder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_full_top_0\n"); );
    // Init
    VUartDecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUartDecoder___024root*>(voidSelf);
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VUartDecoder___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VUartDecoder___024root__trace_full_sub_0(VUartDecoder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VUartDecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUartDecoder___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->UartDecoder__DOT__i_data_valid_old));
    tracep->fullCData(oldp+2,(vlSelf->UartDecoder__DOT__o_bits),5);
    tracep->fullQData(oldp+3,(vlSelf->UartDecoder__DOT__r_word),34);
    tracep->fullCData(oldp+5,(vlSelf->UartDecoder__DOT__array_count),3);
    tracep->fullCData(oldp+6,(vlSelf->UartDecoder__DOT__command),3);
    tracep->fullBit(oldp+7,(vlSelf->UartDecoder__DOT__cmd_loaded));
    tracep->fullBit(oldp+8,(vlSelf->i_clk));
    tracep->fullCData(oldp+9,(vlSelf->i_data_in),8);
    tracep->fullBit(oldp+10,(vlSelf->i_data_valid));
    tracep->fullBit(oldp+11,(vlSelf->i_stb));
    tracep->fullBit(oldp+12,(vlSelf->o_stb));
    tracep->fullQData(oldp+13,(vlSelf->o_word),34);
    tracep->fullBit(oldp+15,(vlSelf->UartDecoder__DOT__i_data_valid_rise));
}
