// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSPI_DAC__Syms.h"


void VSPI_DAC___024root__trace_chg_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep);

void VSPI_DAC___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_chg_top_0\n"); );
    // Init
    VSPI_DAC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSPI_DAC___024root*>(voidSelf);
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VSPI_DAC___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VSPI_DAC___024root__trace_chg_sub_0(VSPI_DAC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgBit(oldp+0,(vlSelf->SPI_DAC__DOT__r_SDI));
        tracep->chgBit(oldp+1,(vlSelf->SPI_DAC__DOT__r_CS));
        tracep->chgCData(oldp+2,(vlSelf->SPI_DAC__DOT__index),4);
    }
    tracep->chgBit(oldp+3,(vlSelf->clk));
    tracep->chgBit(oldp+4,(vlSelf->rst));
    tracep->chgBit(oldp+5,(vlSelf->ST_rise));
    tracep->chgBit(oldp+6,(vlSelf->n_CS));
    tracep->chgBit(oldp+7,(vlSelf->SCK));
    tracep->chgBit(oldp+8,(vlSelf->SDI));
    tracep->chgCData(oldp+9,(vlSelf->SPI_DAC__DOT__SCK_cnt),4);
    tracep->chgBit(oldp+10,(vlSelf->SPI_DAC__DOT__r_SCK));
}

void VSPI_DAC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPI_DAC___024root__trace_cleanup\n"); );
    // Init
    VSPI_DAC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSPI_DAC___024root*>(voidSelf);
    VSPI_DAC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
