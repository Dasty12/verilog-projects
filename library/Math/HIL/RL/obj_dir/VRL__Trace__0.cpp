// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRL__Syms.h"


void VRL___024root__trace_chg_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep);

void VRL___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_chg_top_0\n"); );
    // Init
    VRL___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRL___024root*>(voidSelf);
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VRL___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VRL___024root__trace_chg_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgBit(oldp+0,(vlSelf->RL__DOT__out_n));
        tracep->chgSData(oldp+1,(vlSelf->RL__DOT__cnt),16);
        tracep->chgSData(oldp+2,(vlSelf->RL__DOT__cnt2),16);
        tracep->chgIData(oldp+3,(vlSelf->RL__DOT__X0),32);
        tracep->chgIData(oldp+4,(vlSelf->RL__DOT__X1),32);
        tracep->chgIData(oldp+5,(vlSelf->RL__DOT__X2),32);
        tracep->chgIData(oldp+6,(vlSelf->RL__DOT__di),32);
        tracep->chgIData(oldp+7,(vlSelf->RL__DOT__I),32);
        tracep->chgCData(oldp+8,(vlSelf->RL__DOT__state),5);
        tracep->chgIData(oldp+9,(vlSelf->RL__DOT__X00),32);
        tracep->chgIData(oldp+10,(vlSelf->RL__DOT__X22),32);
        tracep->chgIData(oldp+11,(vlSelf->RL__DOT__di2),32);
        tracep->chgIData(oldp+12,(vlSelf->RL__DOT__I_1),32);
    }
    tracep->chgBit(oldp+13,(vlSelf->clk));
    tracep->chgBit(oldp+14,(vlSelf->rst));
    tracep->chgBit(oldp+15,(vlSelf->sig1));
    tracep->chgBit(oldp+16,(vlSelf->out));
    tracep->chgSData(oldp+17,(vlSelf->cnt_out),16);
    tracep->chgIData(oldp+18,(vlSelf->out_I),32);
    tracep->chgIData(oldp+19,(vlSelf->out_X0),32);
    tracep->chgIData(oldp+20,(vlSelf->out_X00),32);
    tracep->chgIData(oldp+21,(vlSelf->out_X1),32);
    tracep->chgIData(oldp+22,(vlSelf->out_X2),32);
    tracep->chgIData(oldp+23,(vlSelf->out_X22),32);
    tracep->chgIData(oldp+24,(vlSelf->out_di),32);
    tracep->chgIData(oldp+25,(vlSelf->out_di2),32);
    tracep->chgIData(oldp+26,(vlSelf->out_I_1),32);
}

void VRL___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_cleanup\n"); );
    // Init
    VRL___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRL___024root*>(voidSelf);
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
