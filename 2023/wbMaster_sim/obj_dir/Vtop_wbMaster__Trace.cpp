// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_wbMaster__Syms.h"


void Vtop_wbMaster::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop_wbMaster::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top_wbMaster__DOT__op_in_r),2);
            tracep->chgCData(oldp+1,(vlTOPp->top_wbMaster__DOT__a_in_r),6);
            tracep->chgCData(oldp+2,(vlTOPp->top_wbMaster__DOT__b_in_r),6);
            tracep->chgBit(oldp+3,(vlTOPp->top_wbMaster__DOT__in_valid_r));
            tracep->chgCData(oldp+4,(vlTOPp->top_wbMaster__DOT__result),6);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+5,(vlTOPp->top_wbMaster__DOT__rx__DOT__r_out_data),8);
            tracep->chgBit(oldp+6,(((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE) 
                                    & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE_old)))));
            tracep->chgBit(oldp+7,(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART));
            tracep->chgBit(oldp+8,(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old));
            tracep->chgBit(oldp+9,(((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART) 
                                    & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old)))));
            tracep->chgCData(oldp+10,(vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data),8);
            tracep->chgBit(oldp+11,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old));
            tracep->chgBit(oldp+12,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE));
            tracep->chgBit(oldp+13,(((IData)(vlTOPp->top_wbMaster__DOT__in_data) 
                                     & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old)))));
            tracep->chgCData(oldp+14,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt),4);
            tracep->chgCData(oldp+15,(vlTOPp->top_wbMaster__DOT__rx__DOT__state),2);
            tracep->chgCData(oldp+16,(vlTOPp->top_wbMaster__DOT__rx__DOT__state_old),2);
            tracep->chgSData(oldp+17,(vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt),14);
            tracep->chgBit(oldp+18,(vlTOPp->top_wbMaster__DOT__rx__DOT__start));
            tracep->chgCData(oldp+19,(vlTOPp->top_wbMaster__DOT__rx__DOT__dalsi_cnt),4);
            tracep->chgBit(oldp+20,(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE));
            tracep->chgBit(oldp+21,(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE_old));
        }
        tracep->chgBit(oldp+22,(vlTOPp->clk));
        tracep->chgBit(oldp+23,(vlTOPp->rst));
        tracep->chgCData(oldp+24,(vlTOPp->op_in),2);
        tracep->chgCData(oldp+25,(vlTOPp->a_in),6);
        tracep->chgCData(oldp+26,(vlTOPp->b_in),6);
        tracep->chgBit(oldp+27,(vlTOPp->in_valid));
        tracep->chgCData(oldp+28,(vlTOPp->out),6);
        tracep->chgBit(oldp+29,(vlTOPp->out_valid));
    }
}

void Vtop_wbMaster::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
