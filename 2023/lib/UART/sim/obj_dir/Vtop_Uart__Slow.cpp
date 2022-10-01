// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_Uart.h for the primary calling header

#include "Vtop_Uart.h"
#include "Vtop_Uart__Syms.h"

//==========

VL_CTOR_IMP(Vtop_Uart) {
    Vtop_Uart__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_Uart__Syms(this, name());
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vtop_Uart___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_Uart::__Vconfigure(Vtop_Uart__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop_Uart::~Vtop_Uart() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop_Uart::_settle__TOP__1(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_settle__TOP__1\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_Rx_ORE = 0U;
    vlTOPp->bauld = vlTOPp->top_Uart__DOT__bauld_r;
    vlTOPp->out_signal = vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit;
    vlTOPp->out_RXNE = ((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r) 
                        & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r_old)));
}

void Vtop_Uart::_initial__TOP__2(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_initial__TOP__2\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_Uart__DOT__r_Tx_busy = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old = 0U;
    vlTOPp->top_Uart__DOT__r_Tx_start = 1U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__state_old = 0U;
    vlTOPp->top_Uart__DOT__uartTx__DOT__state = 0U;
    vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt = 0U;
    vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt = 0U;
    vlTOPp->top_Uart__DOT__in_valid_old = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__data_index = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__state = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt = 0U;
    vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive = 0U;
    vlTOPp->top_Uart__DOT__rst_counter = 0x14U;
}

void Vtop_Uart::_settle__TOP__4(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_settle__TOP__4\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_BUSY = vlTOPp->top_Uart__DOT__r_Tx_busy;
    vlTOPp->out_word = vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data;
    vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE 
        = ((~ (IData)(vlTOPp->UART_IN)) & (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old));
}

void Vtop_Uart::_eval_initial(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_eval_initial\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop_Uart::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::final\n"); );
    // Variables
    Vtop_Uart__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_Uart::_eval_settle(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_eval_settle\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void Vtop_Uart::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    in_w_data = VL_RAND_RESET_I(8);
    in_valid = VL_RAND_RESET_I(1);
    out_BUSY = VL_RAND_RESET_I(1);
    out_signal = VL_RAND_RESET_I(1);
    UART_IN = VL_RAND_RESET_I(1);
    out_word = VL_RAND_RESET_I(8);
    out_RXNE = VL_RAND_RESET_I(1);
    out_Rx_ORE = VL_RAND_RESET_I(1);
    bauld = VL_RAND_RESET_I(7);
    data_ted = VL_RAND_RESET_I(1);
    state_cnt = VL_RAND_RESET_I(4);
    top_Uart__DOT__r_Tx_DataByte = VL_RAND_RESET_I(8);
    top_Uart__DOT__r_Tx_start = VL_RAND_RESET_I(1);
    top_Uart__DOT__r_Tx_busy = VL_RAND_RESET_I(1);
    top_Uart__DOT__in_valid_old = VL_RAND_RESET_I(1);
    top_Uart__DOT__rst_counter = VL_RAND_RESET_I(5);
    top_Uart__DOT__bauld_r = VL_RAND_RESET_I(7);
    top_Uart__DOT__r_rst = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__clk_UART = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__clk_UART_old = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__UR_data = VL_RAND_RESET_I(8);
    top_Uart__DOT__uartRx__DOT__UART_IN_old = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__UART_IN_FE = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__data_index = VL_RAND_RESET_I(4);
    top_Uart__DOT__uartRx__DOT__state = VL_RAND_RESET_I(2);
    top_Uart__DOT__uartRx__DOT__state_old = VL_RAND_RESET_I(2);
    top_Uart__DOT__uartRx__DOT__baud_cnt = VL_RAND_RESET_I(7);
    top_Uart__DOT__uartRx__DOT__r_out_data = VL_RAND_RESET_I(8);
    top_Uart__DOT__uartRx__DOT__startReceive = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__Rx_done_r = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartRx__DOT__Rx_done_r_old = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartTx__DOT__state = VL_RAND_RESET_I(2);
    top_Uart__DOT__uartTx__DOT__baud_cnt = VL_RAND_RESET_I(7);
    top_Uart__DOT__uartTx__DOT__Data = VL_RAND_RESET_I(8);
    top_Uart__DOT__uartTx__DOT__r_data_cnt = VL_RAND_RESET_I(4);
    top_Uart__DOT__uartTx__DOT__r_out_dataBit = VL_RAND_RESET_I(1);
    top_Uart__DOT__uartTx__DOT__r_out_fComplete = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
