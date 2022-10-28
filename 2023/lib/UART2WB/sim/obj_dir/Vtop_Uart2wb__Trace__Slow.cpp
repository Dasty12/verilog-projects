// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_Uart2wb__Syms.h"


//======================

void Vtop_Uart2wb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop_Uart2wb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop_Uart2wb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop_Uart2wb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop_Uart2wb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+8,"clk", false,-1);
        tracep->declBit(c+9,"rst", false,-1);
        tracep->declBus(c+10,"UART_in_data", false,-1, 7,0);
        tracep->declBit(c+11,"UART_Rx_done", false,-1);
        tracep->declQuad(c+12,"WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+14,"WB_o_cyc", false,-1);
        tracep->declBit(c+8,"top_Uart2wb clk", false,-1);
        tracep->declBit(c+9,"top_Uart2wb rst", false,-1);
        tracep->declBus(c+10,"top_Uart2wb UART_in_data", false,-1, 7,0);
        tracep->declBit(c+11,"top_Uart2wb UART_Rx_done", false,-1);
        tracep->declQuad(c+12,"top_Uart2wb WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+14,"top_Uart2wb WB_o_cyc", false,-1);
        tracep->declBit(c+8,"top_Uart2wb U2W clk", false,-1);
        tracep->declBit(c+9,"top_Uart2wb U2W rst", false,-1);
        tracep->declBus(c+10,"top_Uart2wb U2W UART_in_data", false,-1, 7,0);
        tracep->declBit(c+11,"top_Uart2wb U2W UART_rx_done", false,-1);
        tracep->declQuad(c+12,"top_Uart2wb U2W WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+14,"top_Uart2wb U2W WB_o_cyc", false,-1);
        tracep->declBus(c+1,"top_Uart2wb U2W asciiToBits", false,-1, 4,0);
        tracep->declBit(c+2,"top_Uart2wb U2W UART_rx_done_1p", false,-1);
        tracep->declQuad(c+3,"top_Uart2wb U2W WB_ctr_w_r", false,-1, 33,0);
        tracep->declQuad(c+5,"top_Uart2wb U2W WB_ctr_w_o", false,-1, 33,0);
        tracep->declBit(c+7,"top_Uart2wb U2W WB_o_cyc_r", false,-1);
    }
}

void Vtop_Uart2wb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop_Uart2wb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop_Uart2wb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits),5);
        tracep->fullBit(oldp+2,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p));
        tracep->fullQData(oldp+3,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r),34);
        tracep->fullQData(oldp+5,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_o),34);
        tracep->fullBit(oldp+7,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r));
        tracep->fullBit(oldp+8,(vlTOPp->clk));
        tracep->fullBit(oldp+9,(vlTOPp->rst));
        tracep->fullCData(oldp+10,(vlTOPp->UART_in_data),8);
        tracep->fullBit(oldp+11,(vlTOPp->UART_Rx_done));
        tracep->fullQData(oldp+12,(vlTOPp->WB_ctr_w),34);
        tracep->fullBit(oldp+14,(vlTOPp->WB_o_cyc));
    }
}
