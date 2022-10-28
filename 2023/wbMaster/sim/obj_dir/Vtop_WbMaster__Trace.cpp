// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_WbMaster__Syms.h"


void Vtop_WbMaster::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop_WbMaster::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_rd));
            tracep->chgBit(oldp+1,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_wr));
            tracep->chgBit(oldp+2,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_bus));
            tracep->chgBit(oldp+3,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_addr));
            tracep->chgBit(oldp+4,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_special));
            tracep->chgIData(oldp+5,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_addr),32);
            tracep->chgBit(oldp+6,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc));
            tracep->chgBit(oldp+7,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb));
            tracep->chgBit(oldp+8,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we));
            tracep->chgIData(oldp+9,(vlTOPp->top_WbMaster__DOT__WBM__DOT__rio_wb_data),32);
        }
        tracep->chgBit(oldp+10,(vlTOPp->clk));
        tracep->chgBit(oldp+11,(vlTOPp->rst));
        tracep->chgQData(oldp+12,(vlTOPp->in_WB_ctr_w),34);
        tracep->chgBit(oldp+14,(vlTOPp->in_WB_o_cyc));
        tracep->chgIData(oldp+15,(vlTOPp->io_wb_data),32);
        tracep->chgIData(oldp+16,(vlTOPp->o_wb_addr),32);
        tracep->chgBit(oldp+17,(vlTOPp->o_wb_we));
        tracep->chgBit(oldp+18,(vlTOPp->o_wb_cyc));
        tracep->chgBit(oldp+19,(vlTOPp->o_wb_stb));
        tracep->chgBit(oldp+20,(vlTOPp->i_wb_stall));
        tracep->chgBit(oldp+21,(vlTOPp->i_wb_ack));
        tracep->chgBit(oldp+22,(((2U == (3U & (IData)(
                                                      (vlTOPp->in_WB_ctr_w 
                                                       >> 0x20U))))
                                  ? 1U : 0U)));
        tracep->chgBit(oldp+23,(((1U == (3U & (IData)(
                                                      (vlTOPp->in_WB_ctr_w 
                                                       >> 0x20U))))
                                  ? 1U : 0U)));
        tracep->chgBit(oldp+24,(((0U == (3U & (IData)(
                                                      (vlTOPp->in_WB_ctr_w 
                                                       >> 0x20U))))
                                  ? 1U : 0U)));
        tracep->chgBit(oldp+25,(((1U & (IData)((vlTOPp->in_WB_ctr_w 
                                                >> 0x21U)))
                                  ? 0U : 1U)));
        tracep->chgCData(oldp+26,((3U & (IData)((vlTOPp->in_WB_ctr_w 
                                                 >> 0x20U)))),2);
    }
}

void Vtop_WbMaster::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
