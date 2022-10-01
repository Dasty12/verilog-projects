// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_wbMaster.h for the primary calling header

#include "Vtop_wbMaster.h"
#include "Vtop_wbMaster__Syms.h"

//==========

void Vtop_wbMaster::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_wbMaster::eval\n"); );
    Vtop_wbMaster__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_wbMaster.sv", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_wbMaster::_eval_initial_loop(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_wbMaster.sv", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_wbMaster::_sequent__TOP__2(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_sequent__TOP__2\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlTOPp->out = 0U;
        vlTOPp->top_wbMaster__DOT__b_in_r = 0U;
        vlTOPp->top_wbMaster__DOT__a_in_r = 0U;
        vlTOPp->top_wbMaster__DOT__op_in_r = 0U;
    } else {
        vlTOPp->out = vlTOPp->top_wbMaster__DOT__result;
        vlTOPp->top_wbMaster__DOT__b_in_r = vlTOPp->b_in;
        vlTOPp->top_wbMaster__DOT__a_in_r = vlTOPp->a_in;
        vlTOPp->top_wbMaster__DOT__op_in_r = vlTOPp->op_in;
    }
    vlTOPp->out_valid = ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->top_wbMaster__DOT__in_valid_r));
    vlTOPp->top_wbMaster__DOT__in_valid_r = ((~ (IData)(vlTOPp->rst)) 
                                             & (IData)(vlTOPp->in_valid));
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
}

VL_INLINE_OPT void Vtop_wbMaster::_sequent__TOP__3(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_sequent__TOP__3\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART;
    CData/*0:0*/ __Vdly__top_wbMaster__DOT__rx__DOT__start;
    CData/*1:0*/ __Vdly__top_wbMaster__DOT__rx__DOT__state;
    CData/*7:0*/ __Vdly__top_wbMaster__DOT__rx__DOT__UR_data;
    SData/*13:0*/ __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt;
    // Body
    __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART = vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART;
    __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt = vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt;
    __Vdly__top_wbMaster__DOT__rx__DOT__UR_data = vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data;
    __Vdly__top_wbMaster__DOT__rx__DOT__state = vlTOPp->top_wbMaster__DOT__rx__DOT__state;
    __Vdly__top_wbMaster__DOT__rx__DOT__start = vlTOPp->top_wbMaster__DOT__rx__DOT__start;
    if ((1U & (~ (IData)(vlTOPp->top_wbMaster__DOT__rest)))) {
        vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old 
            = vlTOPp->top_wbMaster__DOT__in_data;
    }
    vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE_old 
        = vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE;
    if ((1U & (~ (IData)(vlTOPp->top_wbMaster__DOT__rest)))) {
        if (((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE) 
             & (0U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state)))) {
            __Vdly__top_wbMaster__DOT__rx__DOT__start = 1U;
        }
        if (((3U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state_old)) 
             & (0U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state)))) {
            __Vdly__top_wbMaster__DOT__rx__DOT__start = 0U;
        }
    }
    if (((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART) 
         & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old)))) {
        if ((1U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state))) {
            __Vdly__top_wbMaster__DOT__rx__DOT__state = 1U;
            __Vdly__top_wbMaster__DOT__rx__DOT__UR_data = 0U;
            vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE = 0U;
        } else {
            if ((0U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state))) {
                __Vdly__top_wbMaster__DOT__rx__DOT__state = 2U;
                __Vdly__top_wbMaster__DOT__rx__DOT__UR_data = 0U;
                vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE = 0U;
            } else {
                if ((2U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state))) {
                    __Vdly__top_wbMaster__DOT__rx__DOT__UR_data 
                        = (((~ ((IData)(1U) << (7U 
                                                & (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt)))) 
                            & (IData)(__Vdly__top_wbMaster__DOT__rx__DOT__UR_data)) 
                           | ((IData)(vlTOPp->top_wbMaster__DOT__in_data) 
                              << (7U & (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt))));
                    if ((7U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt))) {
                        __Vdly__top_wbMaster__DOT__rx__DOT__state = 3U;
                    }
                    vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt)));
                } else {
                    if ((3U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state))) {
                        vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt = 0U;
                        __Vdly__top_wbMaster__DOT__rx__DOT__state = 0U;
                        vlTOPp->top_wbMaster__DOT__rx__DOT__r_out_data 
                            = vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data;
                        vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->top_wbMaster__DOT__rx__DOT__state_old = vlTOPp->top_wbMaster__DOT__rx__DOT__state;
    vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data = __Vdly__top_wbMaster__DOT__rx__DOT__UR_data;
    if (vlTOPp->top_wbMaster__DOT__rest) {
        __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART = 1U;
        vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old = 1U;
    } else {
        if (((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE) 
             & (0U == (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__state)))) {
            __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt = 0x1457U;
            __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART = 1U;
        }
        if (vlTOPp->top_wbMaster__DOT__rx__DOT__start) {
            if ((0x1458U > (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt))) {
                __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt 
                    = (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt)));
            } else {
                __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART 
                    = (1U & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART)));
                vlTOPp->top_wbMaster__DOT__rx__DOT__dalsi_cnt 
                    = (0xfU & ((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__dalsi_cnt) 
                               - (IData)(1U)));
                __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt = 0U;
            }
        }
        vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old 
            = vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART;
    }
    vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART = __Vdly__top_wbMaster__DOT__rx__DOT__clk_UART;
    vlTOPp->top_wbMaster__DOT__rx__DOT__start = __Vdly__top_wbMaster__DOT__rx__DOT__start;
    vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt = __Vdly__top_wbMaster__DOT__rx__DOT__baud_cnt;
    vlTOPp->top_wbMaster__DOT__rx__DOT__state = __Vdly__top_wbMaster__DOT__rx__DOT__state;
    vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE 
        = ((~ (IData)(vlTOPp->top_wbMaster__DOT__in_data)) 
           & (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old));
}

void Vtop_wbMaster::_eval(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_eval\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

VL_INLINE_OPT QData Vtop_wbMaster::_change_request(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_change_request\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop_wbMaster::_change_request_1(Vtop_wbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_change_request_1\n"); );
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_wbMaster::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_wbMaster::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((op_in & 0xfcU))) {
        Verilated::overWidthError("op_in");}
    if (VL_UNLIKELY((a_in & 0xc0U))) {
        Verilated::overWidthError("a_in");}
    if (VL_UNLIKELY((b_in & 0xc0U))) {
        Verilated::overWidthError("b_in");}
    if (VL_UNLIKELY((in_valid & 0xfeU))) {
        Verilated::overWidthError("in_valid");}
}
#endif  // VL_DEBUG
