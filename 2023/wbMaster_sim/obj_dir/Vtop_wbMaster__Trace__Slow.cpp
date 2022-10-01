// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_wbMaster__Syms.h"


//======================

void Vtop_wbMaster::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop_wbMaster::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop_wbMaster::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop_wbMaster::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop_wbMaster::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+23,"clk", false,-1);
        tracep->declBit(c+24,"rst", false,-1);
        tracep->declBus(c+25,"op_in", false,-1, 1,0);
        tracep->declBus(c+26,"a_in", false,-1, 5,0);
        tracep->declBus(c+27,"b_in", false,-1, 5,0);
        tracep->declBit(c+28,"in_valid", false,-1);
        tracep->declBus(c+29,"out", false,-1, 5,0);
        tracep->declBit(c+30,"out_valid", false,-1);
        tracep->declBus(c+31,"top_wbMaster WIDTH", false,-1, 31,0);
        tracep->declBit(c+23,"top_wbMaster clk", false,-1);
        tracep->declBit(c+24,"top_wbMaster rst", false,-1);
        tracep->declBus(c+25,"top_wbMaster op_in", false,-1, 1,0);
        tracep->declBus(c+26,"top_wbMaster a_in", false,-1, 5,0);
        tracep->declBus(c+27,"top_wbMaster b_in", false,-1, 5,0);
        tracep->declBit(c+28,"top_wbMaster in_valid", false,-1);
        tracep->declBus(c+29,"top_wbMaster out", false,-1, 5,0);
        tracep->declBit(c+30,"top_wbMaster out_valid", false,-1);
        tracep->declBus(c+1,"top_wbMaster op_in_r", false,-1, 1,0);
        tracep->declBus(c+2,"top_wbMaster a_in_r", false,-1, 5,0);
        tracep->declBus(c+3,"top_wbMaster b_in_r", false,-1, 5,0);
        tracep->declBit(c+4,"top_wbMaster in_valid_r", false,-1);
        tracep->declBus(c+5,"top_wbMaster result", false,-1, 5,0);
        tracep->declBit(c+32,"top_wbMaster in_data", false,-1);
        tracep->declBit(c+33,"top_wbMaster rest", false,-1);
        tracep->declBus(c+6,"top_wbMaster out_data", false,-1, 7,0);
        tracep->declBit(c+7,"top_wbMaster Rx_done", false,-1);
        tracep->declBit(c+34,"top_wbMaster busy", false,-1);
        tracep->declBit(c+35,"top_wbMaster o_LEDS", false,-1);
        tracep->declBus(c+36,"top_wbMaster rx KBAUD", false,-1, 13,0);
        tracep->declBit(c+23,"top_wbMaster rx clk", false,-1);
        tracep->declBit(c+33,"top_wbMaster rx rst", false,-1);
        tracep->declBit(c+32,"top_wbMaster rx in_data", false,-1);
        tracep->declBus(c+6,"top_wbMaster rx out_data", false,-1, 7,0);
        tracep->declBit(c+7,"top_wbMaster rx Rx_done", false,-1);
        tracep->declBit(c+34,"top_wbMaster rx busy", false,-1);
        tracep->declBus(c+37,"top_wbMaster rx o_LEDS", false,-1, 7,0);
        tracep->declBus(c+38,"top_wbMaster rx CNT_BITS", false,-1, 31,0);
        tracep->declBus(c+39,"top_wbMaster rx KBAUD_half", false,-1, 31,0);
        tracep->declBus(c+39,"top_wbMaster rx KBAUD_period", false,-1, 31,0);
        tracep->declBus(c+40,"top_wbMaster rx s_IDLE", false,-1, 31,0);
        tracep->declBus(c+41,"top_wbMaster rx s_START", false,-1, 31,0);
        tracep->declBus(c+42,"top_wbMaster rx s_DATA", false,-1, 31,0);
        tracep->declBus(c+43,"top_wbMaster rx s_STOP", false,-1, 31,0);
        tracep->declBit(c+8,"top_wbMaster rx clk_UART", false,-1);
        tracep->declBit(c+9,"top_wbMaster rx clk_UART_old", false,-1);
        tracep->declBit(c+10,"top_wbMaster rx clk_UART_RE", false,-1);
        tracep->declBus(c+11,"top_wbMaster rx UR_data", false,-1, 7,0);
        tracep->declBit(c+12,"top_wbMaster rx data_IN_old", false,-1);
        tracep->declBit(c+13,"top_wbMaster rx data_IN_FE", false,-1);
        tracep->declBit(c+14,"top_wbMaster rx data_IN_RE", false,-1);
        tracep->declBus(c+15,"top_wbMaster rx data_cnt", false,-1, 3,0);
        tracep->declBus(c+16,"top_wbMaster rx state", false,-1, 1,0);
        tracep->declBus(c+17,"top_wbMaster rx state_old", false,-1, 1,0);
        tracep->declBus(c+18,"top_wbMaster rx baud_cnt", false,-1, 13,0);
        tracep->declBus(c+6,"top_wbMaster rx r_out_data", false,-1, 7,0);
        tracep->declBit(c+19,"top_wbMaster rx start", false,-1);
        tracep->declBus(c+20,"top_wbMaster rx dalsi_cnt", false,-1, 3,0);
        tracep->declBit(c+21,"top_wbMaster rx Rx_done_RE", false,-1);
        tracep->declBit(c+22,"top_wbMaster rx Rx_done_RE_old", false,-1);
        tracep->declBus(c+44,"top_wbMaster rx testovaci", false,-1, 13,0);
        tracep->declBit(c+45,"top_wbMaster rx start_cnt", false,-1);
        tracep->declBus(c+46,"top_wbMaster rx cnt_delay", false,-1, 15,0);
        tracep->declBus(c+47,"top_wbMaster rx jednou", false,-1, 1,0);
    }
}

void Vtop_wbMaster::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop_wbMaster::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop_wbMaster::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_wbMaster__Syms* __restrict vlSymsp = static_cast<Vtop_wbMaster__Syms*>(userp);
    Vtop_wbMaster* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->top_wbMaster__DOT__op_in_r),2);
        tracep->fullCData(oldp+2,(vlTOPp->top_wbMaster__DOT__a_in_r),6);
        tracep->fullCData(oldp+3,(vlTOPp->top_wbMaster__DOT__b_in_r),6);
        tracep->fullBit(oldp+4,(vlTOPp->top_wbMaster__DOT__in_valid_r));
        tracep->fullCData(oldp+5,(vlTOPp->top_wbMaster__DOT__result),6);
        tracep->fullCData(oldp+6,(vlTOPp->top_wbMaster__DOT__rx__DOT__r_out_data),8);
        tracep->fullBit(oldp+7,(((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE) 
                                 & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE_old)))));
        tracep->fullBit(oldp+8,(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART));
        tracep->fullBit(oldp+9,(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old));
        tracep->fullBit(oldp+10,(((IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART) 
                                  & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__clk_UART_old)))));
        tracep->fullCData(oldp+11,(vlTOPp->top_wbMaster__DOT__rx__DOT__UR_data),8);
        tracep->fullBit(oldp+12,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old));
        tracep->fullBit(oldp+13,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_FE));
        tracep->fullBit(oldp+14,(((IData)(vlTOPp->top_wbMaster__DOT__in_data) 
                                  & (~ (IData)(vlTOPp->top_wbMaster__DOT__rx__DOT__data_IN_old)))));
        tracep->fullCData(oldp+15,(vlTOPp->top_wbMaster__DOT__rx__DOT__data_cnt),4);
        tracep->fullCData(oldp+16,(vlTOPp->top_wbMaster__DOT__rx__DOT__state),2);
        tracep->fullCData(oldp+17,(vlTOPp->top_wbMaster__DOT__rx__DOT__state_old),2);
        tracep->fullSData(oldp+18,(vlTOPp->top_wbMaster__DOT__rx__DOT__baud_cnt),14);
        tracep->fullBit(oldp+19,(vlTOPp->top_wbMaster__DOT__rx__DOT__start));
        tracep->fullCData(oldp+20,(vlTOPp->top_wbMaster__DOT__rx__DOT__dalsi_cnt),4);
        tracep->fullBit(oldp+21,(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE));
        tracep->fullBit(oldp+22,(vlTOPp->top_wbMaster__DOT__rx__DOT__Rx_done_RE_old));
        tracep->fullBit(oldp+23,(vlTOPp->clk));
        tracep->fullBit(oldp+24,(vlTOPp->rst));
        tracep->fullCData(oldp+25,(vlTOPp->op_in),2);
        tracep->fullCData(oldp+26,(vlTOPp->a_in),6);
        tracep->fullCData(oldp+27,(vlTOPp->b_in),6);
        tracep->fullBit(oldp+28,(vlTOPp->in_valid));
        tracep->fullCData(oldp+29,(vlTOPp->out),6);
        tracep->fullBit(oldp+30,(vlTOPp->out_valid));
        tracep->fullIData(oldp+31,(6U),32);
        tracep->fullBit(oldp+32,(vlTOPp->top_wbMaster__DOT__in_data));
        tracep->fullBit(oldp+33,(vlTOPp->top_wbMaster__DOT__rest));
        tracep->fullBit(oldp+34,(vlTOPp->top_wbMaster__DOT__busy));
        tracep->fullBit(oldp+35,((1U & (IData)(vlTOPp->top_wbMaster__DOT____Vcellout__rx__o_LEDS))));
        tracep->fullSData(oldp+36,(0x28b0U),14);
        tracep->fullCData(oldp+37,(vlTOPp->top_wbMaster__DOT____Vcellout__rx__o_LEDS),8);
        tracep->fullIData(oldp+38,(0xeU),32);
        tracep->fullIData(oldp+39,(0x1458U),32);
        tracep->fullIData(oldp+40,(0U),32);
        tracep->fullIData(oldp+41,(1U),32);
        tracep->fullIData(oldp+42,(2U),32);
        tracep->fullIData(oldp+43,(3U),32);
        tracep->fullSData(oldp+44,(0U),14);
        tracep->fullBit(oldp+45,(0U));
        tracep->fullSData(oldp+46,(0U),16);
        tracep->fullCData(oldp+47,(0U),2);
    }
}
