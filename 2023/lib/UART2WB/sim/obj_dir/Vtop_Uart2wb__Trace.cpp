// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_Uart2wb__Syms.h"


void Vtop_Uart2wb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop_Uart2wb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits),5);
            tracep->chgBit(oldp+1,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p));
            tracep->chgQData(oldp+2,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r),34);
            tracep->chgQData(oldp+4,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_o),34);
            tracep->chgBit(oldp+6,(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r));
        }
        tracep->chgBit(oldp+7,(vlTOPp->clk));
        tracep->chgBit(oldp+8,(vlTOPp->rst));
        tracep->chgCData(oldp+9,(vlTOPp->UART_in_data),8);
        tracep->chgBit(oldp+10,(vlTOPp->UART_Rx_done));
        tracep->chgQData(oldp+11,(vlTOPp->WB_ctr_w),34);
        tracep->chgBit(oldp+13,(vlTOPp->WB_o_cyc));
    }
}

void Vtop_Uart2wb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop_Uart2wb__Syms* __restrict vlSymsp = static_cast<Vtop_Uart2wb__Syms*>(userp);
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
