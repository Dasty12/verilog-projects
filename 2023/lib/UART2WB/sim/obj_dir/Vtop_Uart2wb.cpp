// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_Uart2wb.h for the primary calling header

#include "Vtop_Uart2wb.h"
#include "Vtop_Uart2wb__Syms.h"

//==========

void Vtop_Uart2wb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_Uart2wb::eval\n"); );
    Vtop_Uart2wb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("top_Uart2wb.sv", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_Uart2wb::_eval_initial_loop(Vtop_Uart2wb__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("top_Uart2wb.sv", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_Uart2wb::_sequent__TOP__1(Vtop_Uart2wb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart2wb::_sequent__TOP__1\n"); );
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vtableidx1;
    QData/*33:0*/ __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r;
    // Body
    __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r 
        = vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r;
    vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r = 0U;
    if (vlTOPp->top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p) {
        if ((0x10U & (IData)(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits))) {
            vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r = 1U;
        }
    }
    if (vlTOPp->top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p) {
        if ((0x10U & (IData)(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits))) {
            vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_o 
                = vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r;
            __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r 
                = ((0xffffffffULL & __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r) 
                   | ((QData)((IData)((3U & (IData)(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits)))) 
                      << 0x20U));
            __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r 
                = (0x300000000ULL & __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r);
        } else {
            __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r 
                = ((0x300000000ULL & __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r) 
                   | (IData)((IData)(((0xfffffff0U 
                                       & ((IData)(vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r) 
                                          << 4U)) | 
                                      (0xfU & (IData)(vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits))))));
        }
    }
    vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r 
        = __Vdly__top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r;
    vlTOPp->WB_o_cyc = vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r;
    vlTOPp->WB_ctr_w = vlTOPp->top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_o;
    __Vtableidx1 = (((IData)(vlTOPp->UART_in_data) 
                     << 2U) | (((IData)(vlTOPp->UART_Rx_done) 
                                << 1U) | (IData)(vlTOPp->rst)));
    if ((1U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->top_Uart2wb__DOT__U2W__DOT__asciiToBits 
            = vlTOPp->__Vtable1_top_Uart2wb__DOT__U2W__DOT__asciiToBits
            [__Vtableidx1];
    }
    if ((2U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p 
            = vlTOPp->__Vtable1_top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p
            [__Vtableidx1];
    }
}

void Vtop_Uart2wb::_eval(Vtop_Uart2wb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart2wb::_eval\n"); );
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vtop_Uart2wb::_change_request(Vtop_Uart2wb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart2wb::_change_request\n"); );
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop_Uart2wb::_change_request_1(Vtop_Uart2wb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart2wb::_change_request_1\n"); );
    Vtop_Uart2wb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_Uart2wb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_Uart2wb::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((UART_Rx_done & 0xfeU))) {
        Verilated::overWidthError("UART_Rx_done");}
}
#endif  // VL_DEBUG
