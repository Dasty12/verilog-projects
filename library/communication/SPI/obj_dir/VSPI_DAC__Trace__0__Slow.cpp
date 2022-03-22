// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSPI_DAC__Syms.h"


VL_ATTR_COLD void VSPI_DAC___024root__trace_init_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSPI_DAC___024root__trace_init_top(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_init_top\n"); );
    // Body
    VSPI_DAC___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void VSPI_DAC___024root__trace_init_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+8,"clk", false,-1);
    tracep->declBit(c+9,"rst", false,-1);
    tracep->declBit(c+10,"ST_rise", false,-1);
    tracep->declBit(c+11,"n_CS", false,-1);
    tracep->declBit(c+12,"SCK", false,-1);
    tracep->declBit(c+13,"SDI", false,-1);
    tracep->declBit(c+8,"SPI_DAC clk", false,-1);
    tracep->declBit(c+9,"SPI_DAC rst", false,-1);
    tracep->declBit(c+10,"SPI_DAC ST_rise", false,-1);
    tracep->declBit(c+11,"SPI_DAC n_CS", false,-1);
    tracep->declBit(c+12,"SPI_DAC SCK", false,-1);
    tracep->declBit(c+13,"SPI_DAC SDI", false,-1);
    tracep->declBus(c+14,"SPI_DAC SCK_div", false,-1, 31,0);
    tracep->declBus(c+15,"SPI_DAC cfg", false,-1, 3,0);
    tracep->declBus(c+16,"SPI_DAC data", false,-1, 7,0);
    tracep->declBus(c+17,"SPI_DAC data_out", false,-1, 15,0);
    tracep->declBus(c+18,"SPI_DAC cnt", false,-1, 3,0);
    tracep->declBus(c+1,"SPI_DAC SCK_cnt", false,-1, 3,0);
    tracep->declBit(c+2,"SPI_DAC r_SCK", false,-1);
    tracep->declBit(c+3,"SPI_DAC r_SDI", false,-1);
    tracep->declBit(c+4,"SPI_DAC r_CS", false,-1);
    tracep->declBus(c+5,"SPI_DAC index", false,-1, 4,0);
    tracep->declBit(c+6,"SPI_DAC r_SCK_fall", false,-1);
    tracep->declBit(c+7,"SPI_DAC w_SCK_fall", false,-1);
}

VL_ATTR_COLD void VSPI_DAC___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VSPI_DAC___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VSPI_DAC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VSPI_DAC___024root__trace_register(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VSPI_DAC___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VSPI_DAC___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VSPI_DAC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSPI_DAC___024root__trace_full_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSPI_DAC___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_full_top_0\n"); );
    // Init
    VSPI_DAC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSPI_DAC___024root*>(voidSelf);
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VSPI_DAC___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VSPI_DAC___024root__trace_full_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+1,(vlSelf->SPI_DAC__DOT__SCK_cnt),4);
    tracep->fullBit(oldp+2,(vlSelf->SPI_DAC__DOT__r_SCK));
    tracep->fullBit(oldp+3,(vlSelf->SPI_DAC__DOT__r_SDI));
    tracep->fullBit(oldp+4,(vlSelf->SPI_DAC__DOT__r_CS));
    tracep->fullCData(oldp+5,(vlSelf->SPI_DAC__DOT__index),5);
    tracep->fullBit(oldp+6,(vlSelf->SPI_DAC__DOT__r_SCK_fall));
    tracep->fullBit(oldp+7,(((IData)(vlSelf->SPI_DAC__DOT__r_SCK_fall) 
                             & (~ (IData)(vlSelf->SPI_DAC__DOT__r_SCK)))));
    tracep->fullBit(oldp+8,(vlSelf->clk));
    tracep->fullBit(oldp+9,(vlSelf->rst));
    tracep->fullBit(oldp+10,(vlSelf->ST_rise));
    tracep->fullBit(oldp+11,(vlSelf->n_CS));
    tracep->fullBit(oldp+12,(vlSelf->SCK));
    tracep->fullBit(oldp+13,(vlSelf->SDI));
    tracep->fullIData(oldp+14,(5U),32);
    tracep->fullCData(oldp+15,(0xcU),4);
    tracep->fullCData(oldp+16,(0x78U),8);
    tracep->fullSData(oldp+17,(0x78cU),16);
    tracep->fullCData(oldp+18,(0U),4);
}
