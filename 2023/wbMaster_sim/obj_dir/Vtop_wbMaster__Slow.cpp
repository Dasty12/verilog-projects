// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_wbMaster.h for the primary calling header

#include "Vtop_wbMaster.h"
#include "Vtop_wbMaster__Syms.h"

//==========

VL_CTOR_IMP(Vtop_wbMaster) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_wbMaster__Syms(this, name());
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vtop_wbMaster___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_wbMaster::__Vconfigure(Vtop_wbMaster__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop_wbMaster::~Vtop_wbMaster() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop_wbMaster::_initial__TOP__1(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_initial__TOP__1\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_wbMaster__DOT__rx__DOT__r_out_data = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__state_old = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__state = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt = 2U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__start = 0U;
    vlTOPp->top_wbMaster__DOT__rx__DOT__dalsi_cnt = 0U;
}

void Vtop_wbMaster::_settle__TOP__4(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_settle__TOP__4\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_wbMaster__DOT__result = 0U;
    if (vlTOPp->top_wbMaster__DOT__in_valid_r) {
        vlTOPp->top_wbMaster__DOT__result = (0x3fU 
                                             & ((1U 
                                                 == (IData)(vlTOPp->top_wbMaster__DOT__op_in_r))
                                                 ? 
                                                ((IData)(vlTOPp->top_wbMaster__DOT__a_in_r) 
                                                 + (IData)(vlTOPp->top_wbMaster__DOT__b_in_r))
                                                 : 
                                                ((2U 
                                                  == (IData)(vlTOPp->top_wbMaster__DOT__op_in_r))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlTOPp->top_wbMaster__DOT__a_in_r) 
                                                   + 
                                                   (~ (IData)(vlTOPp->top_wbMaster__DOT__b_in_r))))
                                                  : 0U)));
    }
    vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE 
        = ((~ (IData)(vlTOPp->top_wbMaster__DOT__in_data)) 
           & (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old));
}

void Vtop_wbMaster::_eval_initial(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_eval_initial\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void Vtop_wbMaster::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::final\n"); );
    // Variables
    Vtop_wbMaster__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_wbMaster::_eval_settle(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_eval_settle\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop_wbMaster::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    op_in = VL_RAND_RESET_I(2);
    a_in = VL_RAND_RESET_I(6);
    b_in = VL_RAND_RESET_I(6);
    in_valid = VL_RAND_RESET_I(1);
    out = VL_RAND_RESET_I(6);
    out_valid = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__op_in_r = VL_RAND_RESET_I(2);
    top_wbMaster__DOT__a_in_r = VL_RAND_RESET_I(6);
    top_wbMaster__DOT__b_in_r = VL_RAND_RESET_I(6);
    top_wbMaster__DOT__in_valid_r = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__result = VL_RAND_RESET_I(6);
    top_wbMaster__DOT__in_data = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rest = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__busy = VL_RAND_RESET_I(1);
    top_wbMaster__DOT____Vcellout__rx__o_LEDS = VL_RAND_RESET_I(8);
    top_wbMaster__DOT__rx__DOT__clk_UART = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__clk_UART_old = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__UR_data = VL_RAND_RESET_I(8);
    top_wbMaster__DOT__rx__DOT__data_IN_old = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__data_IN_FE = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__data_cnt = VL_RAND_RESET_I(4);
    top_wbMaster__DOT__rx__DOT__state = VL_RAND_RESET_I(2);
    top_wbMaster__DOT__rx__DOT__state_old = VL_RAND_RESET_I(2);
    top_wbMaster__DOT__rx__DOT__baud_cnt = VL_RAND_RESET_I(14);
    top_wbMaster__DOT__rx__DOT__r_out_data = VL_RAND_RESET_I(8);
    top_wbMaster__DOT__rx__DOT__start = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__dalsi_cnt = VL_RAND_RESET_I(4);
    top_wbMaster__DOT__rx__DOT__Rx_done_RE = VL_RAND_RESET_I(1);
    top_wbMaster__DOT__rx__DOT__Rx_done_RE_old = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
