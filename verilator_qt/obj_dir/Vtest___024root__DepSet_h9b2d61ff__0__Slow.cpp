// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest.h for the primary calling header

#include "verilated.h"

#include "Vtest__Syms.h"
#include "Vtest___024root.h"

VL_ATTR_COLD void Vtest___024root___initial__TOP__1(Vtest___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest___024root___initial__TOP__1\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h0a8c0bb9__0;
    // Body
    __Vtemp_h0a8c0bb9__0[0U] = 0x2e766364U;
    __Vtemp_h0a8c0bb9__0[1U] = 0x61766573U;
    __Vtemp_h0a8c0bb9__0[2U] = 0x72785f77U;
    __Vtemp_h0a8c0bb9__0[3U] = 0x6172745fU;
    __Vtemp_h0a8c0bb9__0[4U] = 0x75U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_h0a8c0bb9__0));
    vlSymsp->_traceDumpOpen();
}
