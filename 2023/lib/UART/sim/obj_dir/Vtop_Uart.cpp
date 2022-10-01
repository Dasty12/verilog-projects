// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_Uart.h for the primary calling header

#include "Vtop_Uart.h"
#include "Vtop_Uart__Syms.h"

//==========

void Vtop_Uart::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_Uart::eval\n"); );
    Vtop_Uart__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("top_Uart.sv", 11, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_Uart::_eval_initial_loop(Vtop_Uart__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("top_Uart.sv", 11, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_Uart::_sequent__TOP__3(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_sequent__TOP__3\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART;
    CData/*6:0*/ __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt;
    CData/*0:0*/ __Vdly__top_Uart__DOT__uartRx__DOT__startReceive;
    CData/*1:0*/ __Vdly__top_Uart__DOT__uartRx__DOT__state;
    CData/*7:0*/ __Vdly__top_Uart__DOT__uartRx__DOT__UR_data;
    CData/*7:0*/ __Vdly__top_Uart__DOT__uartTx__DOT__Data;
    CData/*1:0*/ __Vdly__top_Uart__DOT__uartTx__DOT__state;
    CData/*6:0*/ __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt;
    CData/*3:0*/ __Vdly__top_Uart__DOT__uartTx__DOT__r_data_cnt;
    CData/*0:0*/ __Vdly__top_Uart__DOT__uartTx__DOT__r_out_fComplete;
    // Body
    __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART = vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART;
    __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt = vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt;
    __Vdly__top_Uart__DOT__uartTx__DOT__r_out_fComplete 
        = vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete;
    __Vdly__top_Uart__DOT__uartTx__DOT__Data = vlTOPp->top_Uart__DOT__uartTx__DOT__Data;
    __Vdly__top_Uart__DOT__uartTx__DOT__r_data_cnt 
        = vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt;
    __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt = vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt;
    __Vdly__top_Uart__DOT__uartTx__DOT__state = vlTOPp->top_Uart__DOT__uartTx__DOT__state;
    __Vdly__top_Uart__DOT__uartRx__DOT__UR_data = vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data;
    __Vdly__top_Uart__DOT__uartRx__DOT__state = vlTOPp->top_Uart__DOT__uartRx__DOT__state;
    __Vdly__top_Uart__DOT__uartRx__DOT__startReceive 
        = vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive;
    vlTOPp->top_Uart__DOT__bauld_r = 0x68U;
    if ((1U & (~ (IData)(vlTOPp->top_Uart__DOT__r_rst)))) {
        vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old 
            = vlTOPp->UART_IN;
    }
    if ((0U == (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt))) {
        if ((0U == (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__state))) {
            if (((~ (IData)(vlTOPp->top_Uart__DOT__r_Tx_start)) 
                 & (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete))) {
                __Vdly__top_Uart__DOT__uartTx__DOT__Data 
                    = vlTOPp->top_Uart__DOT__r_Tx_DataByte;
                __Vdly__top_Uart__DOT__uartTx__DOT__state = 1U;
                __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt = 0x67U;
                __Vdly__top_Uart__DOT__uartTx__DOT__r_data_cnt = 0U;
                __Vdly__top_Uart__DOT__uartTx__DOT__r_out_fComplete = 0U;
                vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit = 0U;
            } else {
                __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt = 0U;
                __Vdly__top_Uart__DOT__uartTx__DOT__r_out_fComplete = 1U;
                vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__state))) {
                vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit 
                    = (1U & ((IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__Data) 
                             >> (7U & (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt))));
                __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt = 0x67U;
                if ((7U == (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt))) {
                    __Vdly__top_Uart__DOT__uartTx__DOT__state = 2U;
                }
                __Vdly__top_Uart__DOT__uartTx__DOT__r_data_cnt 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt)));
            } else {
                if ((2U == (IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__state))) {
                    __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt = 0x67U;
                    __Vdly__top_Uart__DOT__uartTx__DOT__state = 0U;
                    vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit = 1U;
                }
            }
        }
    } else {
        __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt 
            = (0x7fU & ((IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt) 
                        - (IData)(1U)));
    }
    vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r_old 
        = vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r;
    if ((1U & (~ (IData)(vlTOPp->top_Uart__DOT__r_rst)))) {
        if (((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE) 
             & (0U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state)))) {
            __Vdly__top_Uart__DOT__uartRx__DOT__startReceive = 1U;
        }
        if (((3U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state_old)) 
             & (0U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state)))) {
            __Vdly__top_Uart__DOT__uartRx__DOT__startReceive = 0U;
        }
    }
    vlTOPp->top_Uart__DOT__uartTx__DOT__Data = __Vdly__top_Uart__DOT__uartTx__DOT__Data;
    vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt = __Vdly__top_Uart__DOT__uartTx__DOT__baud_cnt;
    vlTOPp->top_Uart__DOT__uartTx__DOT__state = __Vdly__top_Uart__DOT__uartTx__DOT__state;
    vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt 
        = __Vdly__top_Uart__DOT__uartTx__DOT__r_data_cnt;
    vlTOPp->bauld = vlTOPp->top_Uart__DOT__bauld_r;
    vlTOPp->out_signal = vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit;
    if (((IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete) 
         & (IData)(vlTOPp->in_valid))) {
        vlTOPp->top_Uart__DOT__r_Tx_DataByte = vlTOPp->in_w_data;
    }
    if (((IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete) 
         & (IData)(vlTOPp->in_valid))) {
        vlTOPp->top_Uart__DOT__r_Tx_start = 0U;
        vlTOPp->top_Uart__DOT__r_Tx_busy = 1U;
    } else {
        if (((IData)(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete) 
             & (~ (IData)(vlTOPp->top_Uart__DOT__in_valid_old)))) {
            vlTOPp->top_Uart__DOT__r_Tx_start = 1U;
            vlTOPp->top_Uart__DOT__r_Tx_busy = 0U;
        } else {
            vlTOPp->top_Uart__DOT__r_Tx_start = 1U;
            vlTOPp->top_Uart__DOT__r_Tx_busy = 1U;
        }
    }
    if (((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART) 
         & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old)))) {
        if ((0U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state))) {
            __Vdly__top_Uart__DOT__uartRx__DOT__state = 2U;
            __Vdly__top_Uart__DOT__uartRx__DOT__UR_data = 0U;
            vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r = 0U;
        } else {
            if ((2U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state))) {
                __Vdly__top_Uart__DOT__uartRx__DOT__UR_data 
                    = (((~ ((IData)(1U) << (7U & (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index)))) 
                        & (IData)(__Vdly__top_Uart__DOT__uartRx__DOT__UR_data)) 
                       | ((IData)(vlTOPp->UART_IN) 
                          << (7U & (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index))));
                if ((7U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index))) {
                    __Vdly__top_Uart__DOT__uartRx__DOT__state = 3U;
                }
                vlTOPp->top_Uart__DOT__uartRx__DOT__data_index 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index)));
            } else {
                if ((3U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state))) {
                    vlTOPp->top_Uart__DOT__uartRx__DOT__data_index = 0U;
                    __Vdly__top_Uart__DOT__uartRx__DOT__state = 0U;
                    vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data 
                        = vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data;
                    vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r = 1U;
                }
            }
        }
    }
    vlTOPp->top_Uart__DOT__uartRx__DOT__state_old = vlTOPp->top_Uart__DOT__uartRx__DOT__state;
    vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete 
        = __Vdly__top_Uart__DOT__uartTx__DOT__r_out_fComplete;
    vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data = __Vdly__top_Uart__DOT__uartRx__DOT__UR_data;
    vlTOPp->out_BUSY = vlTOPp->top_Uart__DOT__r_Tx_busy;
    vlTOPp->top_Uart__DOT__in_valid_old = vlTOPp->in_valid;
    vlTOPp->out_word = vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data;
    vlTOPp->out_RXNE = ((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r) 
                        & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r_old)));
    if (vlTOPp->top_Uart__DOT__r_rst) {
        __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART = 1U;
        vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old = 1U;
    } else {
        if (((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE) 
             & (0U == (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__state)))) {
            __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt = 0x33U;
            __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART = 1U;
        }
        if (vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive) {
            if ((0x34U > (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt))) {
                __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt 
                    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt)));
            } else {
                __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART 
                    = (1U & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART)));
                __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt = 0U;
            }
        }
        vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old 
            = vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART;
    }
    vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART = __Vdly__top_Uart__DOT__uartRx__DOT__clk_UART;
    vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive 
        = __Vdly__top_Uart__DOT__uartRx__DOT__startReceive;
    vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt = __Vdly__top_Uart__DOT__uartRx__DOT__baud_cnt;
    vlTOPp->top_Uart__DOT__uartRx__DOT__state = __Vdly__top_Uart__DOT__uartRx__DOT__state;
    if ((0U < (IData)(vlTOPp->top_Uart__DOT__rst_counter))) {
        vlTOPp->top_Uart__DOT__rst_counter = (0x1fU 
                                              & ((IData)(vlTOPp->top_Uart__DOT__rst_counter) 
                                                 - (IData)(1U)));
        vlTOPp->top_Uart__DOT__r_rst = 1U;
    } else {
        vlTOPp->top_Uart__DOT__r_rst = 0U;
    }
}

VL_INLINE_OPT void Vtop_Uart::_combo__TOP__5(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_combo__TOP__5\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE 
        = ((~ (IData)(vlTOPp->UART_IN)) & (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old));
}

void Vtop_Uart::_eval(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_eval\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vtop_Uart::_change_request(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_change_request\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop_Uart::_change_request_1(Vtop_Uart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_change_request_1\n"); );
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_Uart::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((in_valid & 0xfeU))) {
        Verilated::overWidthError("in_valid");}
    if (VL_UNLIKELY((UART_IN & 0xfeU))) {
        Verilated::overWidthError("UART_IN");}
    if (VL_UNLIKELY((data_ted & 0xfeU))) {
        Verilated::overWidthError("data_ted");}
    if (VL_UNLIKELY((state_cnt & 0xf0U))) {
        Verilated::overWidthError("state_cnt");}
}
#endif  // VL_DEBUG
