// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_WbMaster__Syms.h"


//======================

void Vtop_WbMaster::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop_WbMaster::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop_WbMaster::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop_WbMaster::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop_WbMaster::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+11,"clk", false,-1);
        tracep->declBit(c+12,"rst", false,-1);
        tracep->declQuad(c+13,"in_WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+15,"in_WB_o_cyc", false,-1);
        tracep->declBus(c+16,"io_wb_data", false,-1, 31,0);
        tracep->declBus(c+17,"o_wb_addr", false,-1, 31,0);
        tracep->declBit(c+18,"o_wb_we", false,-1);
        tracep->declBit(c+19,"o_wb_cyc", false,-1);
        tracep->declBit(c+20,"o_wb_stb", false,-1);
        tracep->declBit(c+21,"i_wb_stall", false,-1);
        tracep->declBit(c+22,"i_wb_ack", false,-1);
        tracep->declBit(c+11,"top_WbMaster clk", false,-1);
        tracep->declBit(c+12,"top_WbMaster rst", false,-1);
        tracep->declQuad(c+13,"top_WbMaster in_WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+15,"top_WbMaster in_WB_o_cyc", false,-1);
        tracep->declBus(c+16,"top_WbMaster io_wb_data", false,-1, 31,0);
        tracep->declBus(c+17,"top_WbMaster o_wb_addr", false,-1, 31,0);
        tracep->declBit(c+18,"top_WbMaster o_wb_we", false,-1);
        tracep->declBit(c+19,"top_WbMaster o_wb_cyc", false,-1);
        tracep->declBit(c+20,"top_WbMaster o_wb_stb", false,-1);
        tracep->declBit(c+21,"top_WbMaster i_wb_stall", false,-1);
        tracep->declBit(c+22,"top_WbMaster i_wb_ack", false,-1);
        tracep->declBit(c+11,"top_WbMaster WBM clk", false,-1);
        tracep->declBit(c+12,"top_WbMaster WBM rst", false,-1);
        tracep->declQuad(c+13,"top_WbMaster WBM in_WB_ctr_w", false,-1, 33,0);
        tracep->declBit(c+15,"top_WbMaster WBM in_WB_o_cyc", false,-1);
        tracep->declBus(c+16,"top_WbMaster WBM io_wb_data", false,-1, 31,0);
        tracep->declBus(c+17,"top_WbMaster WBM o_wb_addr", false,-1, 31,0);
        tracep->declBit(c+18,"top_WbMaster WBM o_wb_we", false,-1);
        tracep->declBit(c+19,"top_WbMaster WBM o_wb_cyc", false,-1);
        tracep->declBit(c+20,"top_WbMaster WBM o_wb_stb", false,-1);
        tracep->declBit(c+21,"top_WbMaster WBM i_wb_stall", false,-1);
        tracep->declBit(c+22,"top_WbMaster WBM i_wb_ack", false,-1);
        tracep->declBit(c+1,"top_WbMaster WBM i_cmd_rd", false,-1);
        tracep->declBit(c+2,"top_WbMaster WBM i_cmd_wr", false,-1);
        tracep->declBit(c+3,"top_WbMaster WBM i_cmd_bus", false,-1);
        tracep->declBit(c+4,"top_WbMaster WBM i_cmd_addr", false,-1);
        tracep->declBit(c+5,"top_WbMaster WBM i_cmd_special", false,-1);
        tracep->declBit(c+23,"top_WbMaster WBM w_cmd_addr", false,-1);
        tracep->declBit(c+24,"top_WbMaster WBM w_cmd_write", false,-1);
        tracep->declBit(c+25,"top_WbMaster WBM w_cmd_read", false,-1);
        tracep->declBit(c+26,"top_WbMaster WBM w_cmd_bus", false,-1);
        tracep->declBus(c+27,"top_WbMaster WBM i_WB_cmd", false,-1, 1,0);
        tracep->declBus(c+6,"top_WbMaster WBM ro_wb_addr", false,-1, 31,0);
        tracep->declBit(c+7,"top_WbMaster WBM ro_wb_cyc", false,-1);
        tracep->declBit(c+8,"top_WbMaster WBM ro_wb_stb", false,-1);
        tracep->declBit(c+9,"top_WbMaster WBM ro_wb_we", false,-1);
        tracep->declBus(c+10,"top_WbMaster WBM rio_wb_data", false,-1, 31,0);
    }
}

void Vtop_WbMaster::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop_WbMaster::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop_WbMaster::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_WbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_WbMaster__Syms*>(userp);
    Vtop_WbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_rd));
        tracep->fullBit(oldp+2,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_wr));
        tracep->fullBit(oldp+3,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_bus));
        tracep->fullBit(oldp+4,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_addr));
        tracep->fullBit(oldp+5,(vlTOPp->top_WbMaster__DOT__WBM__DOT__i_cmd_special));
        tracep->fullIData(oldp+6,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_addr),32);
        tracep->fullBit(oldp+7,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_cyc));
        tracep->fullBit(oldp+8,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_stb));
        tracep->fullBit(oldp+9,(vlTOPp->top_WbMaster__DOT__WBM__DOT__ro_wb_we));
        tracep->fullIData(oldp+10,(vlTOPp->top_WbMaster__DOT__WBM__DOT__rio_wb_data),32);
        tracep->fullBit(oldp+11,(vlTOPp->clk));
        tracep->fullBit(oldp+12,(vlTOPp->rst));
        tracep->fullQData(oldp+13,(vlTOPp->in_WB_ctr_w),34);
        tracep->fullBit(oldp+15,(vlTOPp->in_WB_o_cyc));
        tracep->fullIData(oldp+16,(vlTOPp->io_wb_data),32);
        tracep->fullIData(oldp+17,(vlTOPp->o_wb_addr),32);
        tracep->fullBit(oldp+18,(vlTOPp->o_wb_we));
        tracep->fullBit(oldp+19,(vlTOPp->o_wb_cyc));
        tracep->fullBit(oldp+20,(vlTOPp->o_wb_stb));
        tracep->fullBit(oldp+21,(vlTOPp->i_wb_stall));
        tracep->fullBit(oldp+22,(vlTOPp->i_wb_ack));
        tracep->fullBit(oldp+23,(((2U == (3U & (IData)(
                                                       (vlTOPp->in_WB_ctr_w 
                                                        >> 0x20U))))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+24,(((1U == (3U & (IData)(
                                                       (vlTOPp->in_WB_ctr_w 
                                                        >> 0x20U))))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+25,(((0U == (3U & (IData)(
                                                       (vlTOPp->in_WB_ctr_w 
                                                        >> 0x20U))))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+26,(((1U & (IData)((vlTOPp->in_WB_ctr_w 
                                                 >> 0x21U)))
                                   ? 0U : 1U)));
        tracep->fullCData(oldp+27,((3U & (IData)((vlTOPp->in_WB_ctr_w 
                                                  >> 0x20U)))),2);
    }
}
