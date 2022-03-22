// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRL__Syms.h"


VL_ATTR_COLD void VRL___024root__trace_init_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VRL___024root__trace_init_top(VRL___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_init_top\n"); );
    // Body
    VRL___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void VRL___024root__trace_init_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+14,"clk", false,-1);
    tracep->declBit(c+15,"rst", false,-1);
    tracep->declBit(c+16,"sig1", false,-1);
    tracep->declBit(c+17,"out", false,-1);
    tracep->declBus(c+18,"cnt_out", false,-1, 15,0);
    tracep->declBus(c+19,"out_I", false,-1, 31,0);
    tracep->declBus(c+20,"out_X0", false,-1, 31,0);
    tracep->declBus(c+21,"out_X00", false,-1, 31,0);
    tracep->declBus(c+22,"out_X1", false,-1, 31,0);
    tracep->declBus(c+23,"out_X2", false,-1, 31,0);
    tracep->declBus(c+24,"out_X22", false,-1, 31,0);
    tracep->declBus(c+25,"out_di", false,-1, 31,0);
    tracep->declBus(c+26,"out_di2", false,-1, 31,0);
    tracep->declBus(c+27,"out_I_1", false,-1, 31,0);
    tracep->declBit(c+14,"RL clk", false,-1);
    tracep->declBit(c+15,"RL rst", false,-1);
    tracep->declBit(c+16,"RL sig1", false,-1);
    tracep->declBit(c+17,"RL out", false,-1);
    tracep->declBus(c+18,"RL cnt_out", false,-1, 15,0);
    tracep->declBus(c+19,"RL out_I", false,-1, 31,0);
    tracep->declBus(c+20,"RL out_X0", false,-1, 31,0);
    tracep->declBus(c+21,"RL out_X00", false,-1, 31,0);
    tracep->declBus(c+22,"RL out_X1", false,-1, 31,0);
    tracep->declBus(c+23,"RL out_X2", false,-1, 31,0);
    tracep->declBus(c+24,"RL out_X22", false,-1, 31,0);
    tracep->declBus(c+25,"RL out_di", false,-1, 31,0);
    tracep->declBus(c+26,"RL out_di2", false,-1, 31,0);
    tracep->declBus(c+27,"RL out_I_1", false,-1, 31,0);
    tracep->declBit(c+1,"RL out_n", false,-1);
    tracep->declBus(c+2,"RL cnt", false,-1, 15,0);
    tracep->declBus(c+3,"RL cnt2", false,-1, 15,0);
    tracep->declBus(c+28,"RL R", false,-1, 31,0);
    tracep->declBus(c+29,"RL L_div", false,-1, 31,0);
    tracep->declBus(c+30,"RL U0", false,-1, 31,0);
    tracep->declBus(c+31,"RL dt", false,-1, 31,0);
    tracep->declBus(c+4,"RL X0", false,-1, 31,0);
    tracep->declBus(c+5,"RL X1", false,-1, 31,0);
    tracep->declBus(c+6,"RL X2", false,-1, 31,0);
    tracep->declBus(c+7,"RL di", false,-1, 31,0);
    tracep->declBus(c+32,"RL i1", false,-1, 31,0);
    tracep->declBus(c+8,"RL I", false,-1, 31,0);
    tracep->declBus(c+9,"RL state", false,-1, 4,0);
    tracep->declBus(c+10,"RL X00", false,-1, 31,0);
    tracep->declBus(c+11,"RL X22", false,-1, 31,0);
    tracep->declBus(c+12,"RL di2", false,-1, 31,0);
    tracep->declBus(c+13,"RL I_1", false,-1, 31,0);
}

VL_ATTR_COLD void VRL___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VRL___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VRL___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VRL___024root__trace_register(VRL___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VRL___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VRL___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VRL___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VRL___024root__trace_full_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VRL___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_full_top_0\n"); );
    // Init
    VRL___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRL___024root*>(voidSelf);
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VRL___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VRL___024root__trace_full_sub_0(VRL___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRL__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRL___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->RL__DOT__out_n));
    tracep->fullSData(oldp+2,(vlSelf->RL__DOT__cnt),16);
    tracep->fullSData(oldp+3,(vlSelf->RL__DOT__cnt2),16);
    tracep->fullIData(oldp+4,(vlSelf->RL__DOT__X0),32);
    tracep->fullIData(oldp+5,(vlSelf->RL__DOT__X1),32);
    tracep->fullIData(oldp+6,(vlSelf->RL__DOT__X2),32);
    tracep->fullIData(oldp+7,(vlSelf->RL__DOT__di),32);
    tracep->fullIData(oldp+8,(vlSelf->RL__DOT__I),32);
    tracep->fullCData(oldp+9,(vlSelf->RL__DOT__state),5);
    tracep->fullIData(oldp+10,(vlSelf->RL__DOT__X00),32);
    tracep->fullIData(oldp+11,(vlSelf->RL__DOT__X22),32);
    tracep->fullIData(oldp+12,(vlSelf->RL__DOT__di2),32);
    tracep->fullIData(oldp+13,(vlSelf->RL__DOT__I_1),32);
    tracep->fullBit(oldp+14,(vlSelf->clk));
    tracep->fullBit(oldp+15,(vlSelf->rst));
    tracep->fullBit(oldp+16,(vlSelf->sig1));
    tracep->fullBit(oldp+17,(vlSelf->out));
    tracep->fullSData(oldp+18,(vlSelf->cnt_out),16);
    tracep->fullIData(oldp+19,(vlSelf->out_I),32);
    tracep->fullIData(oldp+20,(vlSelf->out_X0),32);
    tracep->fullIData(oldp+21,(vlSelf->out_X00),32);
    tracep->fullIData(oldp+22,(vlSelf->out_X1),32);
    tracep->fullIData(oldp+23,(vlSelf->out_X2),32);
    tracep->fullIData(oldp+24,(vlSelf->out_X22),32);
    tracep->fullIData(oldp+25,(vlSelf->out_di),32);
    tracep->fullIData(oldp+26,(vlSelf->out_di2),32);
    tracep->fullIData(oldp+27,(vlSelf->out_I_1),32);
    tracep->fullIData(oldp+28,(0xaU),32);
    tracep->fullIData(oldp+29,(0x64U),32);
    tracep->fullIData(oldp+30,(0xc8U),32);
    tracep->fullIData(oldp+31,(0x1aU),32);
    tracep->fullIData(oldp+32,(vlSelf->RL__DOT__i1),32);
}
