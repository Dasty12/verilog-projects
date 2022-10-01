// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_Uart__Syms.h"


void Vtop_Uart::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop_Uart::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top_Uart__DOT__r_Tx_DataByte),8);
            tracep->chgBit(oldp+1,(vlTOPp->top_Uart__DOT__r_Tx_start));
            tracep->chgBit(oldp+2,(vlTOPp->top_Uart__DOT__r_Tx_busy));
            tracep->chgBit(oldp+3,(vlTOPp->top_Uart__DOT__in_valid_old));
            tracep->chgBit(oldp+4,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete));
            tracep->chgCData(oldp+5,(vlTOPp->top_Uart__DOT__rst_counter),5);
            tracep->chgCData(oldp+6,(vlTOPp->top_Uart__DOT__bauld_r),7);
            tracep->chgBit(oldp+7,(vlTOPp->top_Uart__DOT__r_rst));
            tracep->chgBit(oldp+8,(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART));
            tracep->chgBit(oldp+9,(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old));
            tracep->chgBit(oldp+10,(((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART) 
                                     & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old)))));
            tracep->chgCData(oldp+11,(vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data),8);
            tracep->chgBit(oldp+12,(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old));
            tracep->chgCData(oldp+13,(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index),4);
            tracep->chgCData(oldp+14,(vlTOPp->top_Uart__DOT__uartRx__DOT__state),2);
            tracep->chgCData(oldp+15,(vlTOPp->top_Uart__DOT__uartRx__DOT__state_old),2);
            tracep->chgCData(oldp+16,(vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt),7);
            tracep->chgCData(oldp+17,(vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data),8);
            tracep->chgBit(oldp+18,(vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive));
            tracep->chgBit(oldp+19,(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r));
            tracep->chgBit(oldp+20,(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r_old));
            tracep->chgCData(oldp+21,(vlTOPp->top_Uart__DOT__uartTx__DOT__state),2);
            tracep->chgCData(oldp+22,(vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt),7);
            tracep->chgCData(oldp+23,(vlTOPp->top_Uart__DOT__uartTx__DOT__Data),8);
            tracep->chgCData(oldp+24,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt),4);
            tracep->chgBit(oldp+25,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit));
        }
        tracep->chgBit(oldp+26,(vlTOPp->clk));
        tracep->chgCData(oldp+27,(vlTOPp->in_w_data),8);
        tracep->chgBit(oldp+28,(vlTOPp->in_valid));
        tracep->chgBit(oldp+29,(vlTOPp->out_BUSY));
        tracep->chgBit(oldp+30,(vlTOPp->out_signal));
        tracep->chgBit(oldp+31,(vlTOPp->UART_IN));
        tracep->chgCData(oldp+32,(vlTOPp->out_word),8);
        tracep->chgBit(oldp+33,(vlTOPp->out_RXNE));
        tracep->chgBit(oldp+34,(vlTOPp->out_Rx_ORE));
        tracep->chgCData(oldp+35,(vlTOPp->bauld),7);
        tracep->chgBit(oldp+36,(vlTOPp->data_ted));
        tracep->chgCData(oldp+37,(vlTOPp->state_cnt),4);
        tracep->chgBit(oldp+38,(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE));
    }
}

void Vtop_Uart::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
