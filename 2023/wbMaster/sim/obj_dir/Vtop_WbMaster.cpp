// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_WbMaster.h for the primary calling header

#include "Vtop_WbMaster.h"
#include "Vtop_WbMaster__Syms.h"

//==========

void Vtop_WbMaster::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_WbMaster::eval\n"); );
    Vtop_WbMaster__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("top_WbMaster.sv", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_WbMaster::_eval_initial_loop(Vtop_WbMaster__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("top_WbMaster.sv", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_WbMaster::_sequent__TOP__1(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_sequent__TOP__1\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_special = 0U;
    }
    if (vlTOPp->rst) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_addr = 0U;
    } else {
        if (vlTOPp->in_WB_o_cyc) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_addr 
                = (2U == (3U & (IData)((vlTOPp->in_WB_ctr_w 
                                        >> 0x20U))));
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_bus = 0U;
    } else {
        if (vlTOPp->in_WB_o_cyc) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_bus 
                = (1U & (~ (IData)((vlTOPp->in_WB_ctr_w 
                                    >> 0x21U))));
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_rd = 0U;
    } else {
        if (vlTOPp->in_WB_o_cyc) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_rd 
                = (0U == (3U & (IData)((vlTOPp->in_WB_ctr_w 
                                        >> 0x20U))));
        }
    }
    if (((2U == (3U & (IData)((vlTOPp->in_WB_ctr_w 
                               >> 0x20U)))) ? 1U : 0U)) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_addr 
            = (IData)(vlTOPp->in_WB_ctr_w);
    }
    vlTOPp->top_WbMaster__DOT__WBM__DOT__rio_wb_data 
        = (((IData)(vlTOPp->i_wb_ack) & (~ ((1U == 
                                             (3U & (IData)(
                                                           (vlTOPp->in_WB_ctr_w 
                                                            >> 0x20U))))
                                             ? 1U : 0U)))
            ? vlTOPp->io_wb_data : (IData)(vlTOPp->in_WB_ctr_w));
    if ((1U & ((~ (IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc)) 
               & (~ (IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb))))) {
        if (((1U & (IData)((vlTOPp->in_WB_ctr_w >> 0x21U)))
              ? 0U : 1U)) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc = 1U;
            vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb = 1U;
            vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we 
                = vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_wr;
        }
    } else {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb = 0U;
        if (vlTOPp->i_wb_ack) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc = 0U;
        }
    }
    vlTOPp->o_wb_addr = vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_addr;
    vlTOPp->o_wb_cyc = vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc;
    vlTOPp->o_wb_stb = vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb;
    vlTOPp->o_wb_we = vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we;
    vlTOPp->io_wb_data = (((((IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we)
                              ? vlTOPp->top_WbMaster__DOT__WBM__DOT__rio_wb_data
                              : 0U) & ((IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we)
                                        ? 0xffffffffU
                                        : 0U)) & ((IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we)
                                                   ? 0xffffffffU
                                                   : 0U)) 
                          & ((IData)(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we)
                              ? 0xffffffffU : 0U));
    if (vlTOPp->rst) {
        vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_wr = 0U;
    } else {
        if (vlTOPp->in_WB_o_cyc) {
            vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_wr 
                = (1U == (3U & (IData)((vlTOPp->in_WB_ctr_w 
                                        >> 0x20U))));
        }
    }
}

void Vtop_WbMaster::_eval(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_eval\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vtop_WbMaster::_change_request(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_change_request\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop_WbMaster::_change_request_1(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_change_request_1\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_WbMaster::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((in_WB_ctr_w & 0ULL))) {
        Verilated::overWidthError("in_WB_ctr_w");}
    if (VL_UNLIKELY((in_WB_o_cyc & 0xfeU))) {
        Verilated::overWidthError("in_WB_o_cyc");}
    if (VL_UNLIKELY((i_wb_stall & 0xfeU))) {
        Verilated::overWidthError("i_wb_stall");}
    if (VL_UNLIKELY((i_wb_ack & 0xfeU))) {
        Verilated::overWidthError("i_wb_ack");}
}
#endif  // VL_DEBUG
