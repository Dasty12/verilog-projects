// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_WbMaster.h for the primary calling header

#include "Vtop_WbMaster.h"
#include "Vtop_WbMaster__Syms.h"

//==========

VL_CTOR_IMP(Vtop_WbMaster) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_WbMaster__Syms(this, name());
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vtop_WbMaster___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_WbMaster::__Vconfigure(Vtop_WbMaster__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop_WbMaster::~Vtop_WbMaster() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop_WbMaster::_settle__TOP__2(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_settle__TOP__2\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

void Vtop_WbMaster::_eval_initial(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_eval_initial\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop_WbMaster::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::final\n"); );
    // Variables
    Vtop_WbMaster__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_WbMaster::_eval_settle(Vtop_WbMaster__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_eval_settle\n"); );
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop_WbMaster::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_WbMaster::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    in_WB_ctr_w = VL_RAND_RESET_Q(34);
    in_WB_o_cyc = VL_RAND_RESET_I(1);
    io_wb_data = VL_RAND_RESET_I(32);
    o_wb_addr = VL_RAND_RESET_I(32);
    o_wb_we = VL_RAND_RESET_I(1);
    o_wb_cyc = VL_RAND_RESET_I(1);
    o_wb_stb = VL_RAND_RESET_I(1);
    i_wb_stall = VL_RAND_RESET_I(1);
    i_wb_ack = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__i_cmd_rd = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__i_cmd_wr = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__i_cmd_bus = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__i_cmd_addr = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__i_cmd_special = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__ro_wb_addr = VL_RAND_RESET_I(32);
    top_WbMaster__DOT__WBM__DOT__ro_wb_cyc = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__ro_wb_stb = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__ro_wb_we = VL_RAND_RESET_I(1);
    top_WbMaster__DOT__WBM__DOT__rio_wb_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
