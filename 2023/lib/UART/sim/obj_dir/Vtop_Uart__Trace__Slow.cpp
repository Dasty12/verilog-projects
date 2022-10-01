// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_Uart__Syms.h"


//======================

void Vtop_Uart::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop_Uart::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop_Uart::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop_Uart::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop_Uart::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+27,"clk", false,-1);
        tracep->declBus(c+28,"in_w_data", false,-1, 7,0);
        tracep->declBit(c+29,"in_valid", false,-1);
        tracep->declBit(c+30,"out_BUSY", false,-1);
        tracep->declBit(c+31,"out_signal", false,-1);
        tracep->declBit(c+32,"UART_IN", false,-1);
        tracep->declBus(c+33,"out_word", false,-1, 7,0);
        tracep->declBit(c+34,"out_RXNE", false,-1);
        tracep->declBit(c+35,"out_Rx_ORE", false,-1);
        tracep->declBus(c+36,"bauld", false,-1, 6,0);
        tracep->declBit(c+37,"data_ted", false,-1);
        tracep->declBus(c+38,"state_cnt", false,-1, 3,0);
        tracep->declBus(c+40,"top_Uart CLK_BAULD", false,-1, 31,0);
        tracep->declBit(c+27,"top_Uart clk", false,-1);
        tracep->declBus(c+28,"top_Uart in_w_data", false,-1, 7,0);
        tracep->declBit(c+29,"top_Uart in_valid", false,-1);
        tracep->declBit(c+30,"top_Uart out_BUSY", false,-1);
        tracep->declBit(c+31,"top_Uart out_signal", false,-1);
        tracep->declBit(c+32,"top_Uart UART_IN", false,-1);
        tracep->declBus(c+33,"top_Uart out_word", false,-1, 7,0);
        tracep->declBit(c+34,"top_Uart out_RXNE", false,-1);
        tracep->declBit(c+35,"top_Uart out_Rx_ORE", false,-1);
        tracep->declBus(c+36,"top_Uart bauld", false,-1, 6,0);
        tracep->declBit(c+37,"top_Uart data_ted", false,-1);
        tracep->declBus(c+38,"top_Uart state_cnt", false,-1, 3,0);
        tracep->declBus(c+1,"top_Uart r_Tx_DataByte", false,-1, 7,0);
        tracep->declBit(c+2,"top_Uart r_Tx_start", false,-1);
        tracep->declBit(c+3,"top_Uart r_Tx_busy", false,-1);
        tracep->declBit(c+4,"top_Uart in_valid_old", false,-1);
        tracep->declBit(c+5,"top_Uart TxComplete", false,-1);
        tracep->declBit(c+2,"top_Uart Tx_start", false,-1);
        tracep->declBus(c+6,"top_Uart rst_counter", false,-1, 4,0);
        tracep->declBus(c+41,"top_Uart KBAUD", false,-1, 31,0);
        tracep->declBus(c+7,"top_Uart bauld_r", false,-1, 6,0);
        tracep->declBit(c+42,"top_Uart r_out_Rx_ORE", false,-1);
        tracep->declBit(c+8,"top_Uart r_rst", false,-1);
        tracep->declBit(c+8,"top_Uart rst", false,-1);
        tracep->declBus(c+41,"top_Uart uartRx KBAUD", false,-1, 31,0);
        tracep->declBit(c+27,"top_Uart uartRx clk", false,-1);
        tracep->declBit(c+8,"top_Uart uartRx rst", false,-1);
        tracep->declBit(c+32,"top_Uart uartRx UART_IN", false,-1);
        tracep->declBus(c+33,"top_Uart uartRx out_data", false,-1, 7,0);
        tracep->declBit(c+34,"top_Uart uartRx Rx_done", false,-1);
        tracep->declBus(c+43,"top_Uart uartRx CNT_BITS", false,-1, 31,0);
        tracep->declBus(c+44,"top_Uart uartRx KBAUD_half", false,-1, 31,0);
        tracep->declBus(c+45,"top_Uart uartRx s_IDLE", false,-1, 31,0);
        tracep->declBus(c+46,"top_Uart uartRx s_DATA", false,-1, 31,0);
        tracep->declBus(c+47,"top_Uart uartRx s_STOP", false,-1, 31,0);
        tracep->declBit(c+9,"top_Uart uartRx clk_UART", false,-1);
        tracep->declBit(c+10,"top_Uart uartRx clk_UART_old", false,-1);
        tracep->declBit(c+11,"top_Uart uartRx clk_UART_RE", false,-1);
        tracep->declBus(c+12,"top_Uart uartRx UR_data", false,-1, 7,0);
        tracep->declBit(c+13,"top_Uart uartRx UART_IN_old", false,-1);
        tracep->declBit(c+39,"top_Uart uartRx UART_IN_FE", false,-1);
        tracep->declBus(c+14,"top_Uart uartRx data_index", false,-1, 3,0);
        tracep->declBus(c+15,"top_Uart uartRx state", false,-1, 1,0);
        tracep->declBus(c+16,"top_Uart uartRx state_old", false,-1, 1,0);
        tracep->declBus(c+17,"top_Uart uartRx baud_cnt", false,-1, 6,0);
        tracep->declBus(c+18,"top_Uart uartRx r_out_data", false,-1, 7,0);
        tracep->declBit(c+19,"top_Uart uartRx startReceive", false,-1);
        tracep->declBit(c+20,"top_Uart uartRx Rx_done_r", false,-1);
        tracep->declBit(c+21,"top_Uart uartRx Rx_done_r_old", false,-1);
        tracep->declBus(c+41,"top_Uart uartTx KBAUD", false,-1, 31,0);
        tracep->declBit(c+27,"top_Uart uartTx clk", false,-1);
        tracep->declBus(c+1,"top_Uart uartTx in_DataByte", false,-1, 7,0);
        tracep->declBit(c+2,"top_Uart uartTx in_Start", false,-1);
        tracep->declBit(c+31,"top_Uart uartTx out_DataBit", false,-1);
        tracep->declBit(c+5,"top_Uart uartTx out_fComplete", false,-1);
        tracep->declBus(c+45,"top_Uart uartTx s_START", false,-1, 31,0);
        tracep->declBus(c+48,"top_Uart uartTx s_DATA", false,-1, 31,0);
        tracep->declBus(c+46,"top_Uart uartTx s_STOP", false,-1, 31,0);
        tracep->declBus(c+22,"top_Uart uartTx state", false,-1, 1,0);
        tracep->declBus(c+23,"top_Uart uartTx baud_cnt", false,-1, 6,0);
        tracep->declBus(c+24,"top_Uart uartTx Data", false,-1, 7,0);
        tracep->declBus(c+25,"top_Uart uartTx r_data_cnt", false,-1, 3,0);
        tracep->declBit(c+26,"top_Uart uartTx r_out_dataBit", false,-1);
        tracep->declBit(c+5,"top_Uart uartTx r_out_fComplete", false,-1);
    }
}

void Vtop_Uart::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop_Uart::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop_Uart::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop_Uart__Syms* __restrict vlSymsp = static_cast<Vtop_Uart__Syms*>(userp);
    Vtop_Uart* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->top_Uart__DOT__r_Tx_DataByte),8);
        tracep->fullBit(oldp+2,(vlTOPp->top_Uart__DOT__r_Tx_start));
        tracep->fullBit(oldp+3,(vlTOPp->top_Uart__DOT__r_Tx_busy));
        tracep->fullBit(oldp+4,(vlTOPp->top_Uart__DOT__in_valid_old));
        tracep->fullBit(oldp+5,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_fComplete));
        tracep->fullCData(oldp+6,(vlTOPp->top_Uart__DOT__rst_counter),5);
        tracep->fullCData(oldp+7,(vlTOPp->top_Uart__DOT__bauld_r),7);
        tracep->fullBit(oldp+8,(vlTOPp->top_Uart__DOT__r_rst));
        tracep->fullBit(oldp+9,(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART));
        tracep->fullBit(oldp+10,(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old));
        tracep->fullBit(oldp+11,(((IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART) 
                                  & (~ (IData)(vlTOPp->top_Uart__DOT__uartRx__DOT__clk_UART_old)))));
        tracep->fullCData(oldp+12,(vlTOPp->top_Uart__DOT__uartRx__DOT__UR_data),8);
        tracep->fullBit(oldp+13,(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_old));
        tracep->fullCData(oldp+14,(vlTOPp->top_Uart__DOT__uartRx__DOT__data_index),4);
        tracep->fullCData(oldp+15,(vlTOPp->top_Uart__DOT__uartRx__DOT__state),2);
        tracep->fullCData(oldp+16,(vlTOPp->top_Uart__DOT__uartRx__DOT__state_old),2);
        tracep->fullCData(oldp+17,(vlTOPp->top_Uart__DOT__uartRx__DOT__baud_cnt),7);
        tracep->fullCData(oldp+18,(vlTOPp->top_Uart__DOT__uartRx__DOT__r_out_data),8);
        tracep->fullBit(oldp+19,(vlTOPp->top_Uart__DOT__uartRx__DOT__startReceive));
        tracep->fullBit(oldp+20,(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r));
        tracep->fullBit(oldp+21,(vlTOPp->top_Uart__DOT__uartRx__DOT__Rx_done_r_old));
        tracep->fullCData(oldp+22,(vlTOPp->top_Uart__DOT__uartTx__DOT__state),2);
        tracep->fullCData(oldp+23,(vlTOPp->top_Uart__DOT__uartTx__DOT__baud_cnt),7);
        tracep->fullCData(oldp+24,(vlTOPp->top_Uart__DOT__uartTx__DOT__Data),8);
        tracep->fullCData(oldp+25,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_data_cnt),4);
        tracep->fullBit(oldp+26,(vlTOPp->top_Uart__DOT__uartTx__DOT__r_out_dataBit));
        tracep->fullBit(oldp+27,(vlTOPp->clk));
        tracep->fullCData(oldp+28,(vlTOPp->in_w_data),8);
        tracep->fullBit(oldp+29,(vlTOPp->in_valid));
        tracep->fullBit(oldp+30,(vlTOPp->out_BUSY));
        tracep->fullBit(oldp+31,(vlTOPp->out_signal));
        tracep->fullBit(oldp+32,(vlTOPp->UART_IN));
        tracep->fullCData(oldp+33,(vlTOPp->out_word),8);
        tracep->fullBit(oldp+34,(vlTOPp->out_RXNE));
        tracep->fullBit(oldp+35,(vlTOPp->out_Rx_ORE));
        tracep->fullCData(oldp+36,(vlTOPp->bauld),7);
        tracep->fullBit(oldp+37,(vlTOPp->data_ted));
        tracep->fullCData(oldp+38,(vlTOPp->state_cnt),4);
        tracep->fullBit(oldp+39,(vlTOPp->top_Uart__DOT__uartRx__DOT__UART_IN_FE));
        tracep->fullIData(oldp+40,(0x64U),32);
        tracep->fullIData(oldp+41,(0x68U),32);
        tracep->fullBit(oldp+42,(0U));
        tracep->fullIData(oldp+43,(7U),32);
        tracep->fullIData(oldp+44,(0x34U),32);
        tracep->fullIData(oldp+45,(0U),32);
        tracep->fullIData(oldp+46,(2U),32);
        tracep->fullIData(oldp+47,(3U),32);
        tracep->fullIData(oldp+48,(1U),32);
    }
}
