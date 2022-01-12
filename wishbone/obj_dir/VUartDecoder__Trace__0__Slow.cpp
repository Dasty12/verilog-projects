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
    tracep->declBit(c+12,"i_clk", false,-1);
    tracep->declBus(c+13,"i_data_in", false,-1, 7,0);
    tracep->declBit(c+14,"i_data_valid", false,-1);
    tracep->declBit(c+15,"i_stb", false,-1);
    tracep->declBit(c+16,"o_stb", false,-1);
    tracep->declQuad(c+17,"o_word", false,-1, 33,0);
    tracep->declBit(c+12,"UartDecoder i_clk", false,-1);
    tracep->declBus(c+13,"UartDecoder i_data_in", false,-1, 7,0);
    tracep->declBit(c+14,"UartDecoder i_data_valid", false,-1);
    tracep->declBit(c+15,"UartDecoder i_stb", false,-1);
    tracep->declBit(c+16,"UartDecoder o_stb", false,-1);
    tracep->declQuad(c+17,"UartDecoder o_word", false,-1, 33,0);
    tracep->declBit(c+1,"UartDecoder i_data_valid_old", false,-1);
    tracep->declBit(c+19,"UartDecoder i_data_valid_rise", false,-1);
    tracep->declBit(c+2,"UartDecoder r_i_data_valid_rise", false,-1);
    tracep->declBus(c+3,"UartDecoder o_bits", false,-1, 4,0);
    tracep->declBit(c+4,"UartDecoder i_stb_old", false,-1);
    tracep->declQuad(c+5,"UartDecoder r_word", false,-1, 33,0);
    tracep->declBus(c+7,"UartDecoder array_count", false,-1, 2,0);
    tracep->declBus(c+8,"UartDecoder command", false,-1, 2,0);
    tracep->declBit(c+9,"UartDecoder cmd_loaded", false,-1);
    tracep->declQuad(c+10,"UartDecoder testovaci", false,-1, 33,0);
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
    tracep->fullBit(oldp+2,(vlSelf->UartDecoder__DOT__r_i_data_valid_rise));
    tracep->fullCData(oldp+3,(vlSelf->UartDecoder__DOT__o_bits),5);
    tracep->fullBit(oldp+4,(vlSelf->UartDecoder__DOT__i_stb_old));
    tracep->fullQData(oldp+5,(vlSelf->UartDecoder__DOT__r_word),34);
    tracep->fullCData(oldp+7,(vlSelf->UartDecoder__DOT__array_count),3);
    tracep->fullCData(oldp+8,(vlSelf->UartDecoder__DOT__command),3);
    tracep->fullBit(oldp+9,(vlSelf->UartDecoder__DOT__cmd_loaded));
    tracep->fullQData(oldp+10,(vlSelf->UartDecoder__DOT__testovaci),34);
    tracep->fullBit(oldp+12,(vlSelf->i_clk));
    tracep->fullCData(oldp+13,(vlSelf->i_data_in),8);
    tracep->fullBit(oldp+14,(vlSelf->i_data_valid));
    tracep->fullBit(oldp+15,(vlSelf->i_stb));
    tracep->fullBit(oldp+16,(vlSelf->o_stb));
    tracep->fullQData(oldp+17,(vlSelf->o_word),34);
    tracep->fullBit(oldp+19,(((IData)(vlSelf->i_data_valid) 
                              & (~ (IData)(vlSelf->UartDecoder__DOT__i_data_valid_old)))));
}
