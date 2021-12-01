// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsine_table_tb.h for the primary calling header

#include "verilated.h"

#include "Vsine_table_tb___024root.h"

VL_ATTR_COLD void Vsine_table_tb___024root___initial__TOP__1(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___initial__TOP__1\n"); );
    // Init
    CData/*5:0*/ sine_table_tb__DOT__sine_table_inst__DOT__tab_id;
    CData/*1:0*/ sine_table_tb__DOT__sine_table_inst__DOT__quad;
    VlWide<5>/*159:0*/ __Vtemp_h23d0e588__0;
    // Body
    VL_WRITEF("creating rom_sync form init file 'sine_table_64x8.mem'.\n");
    __Vtemp_h23d0e588__0[0U] = 0x2e6d656dU;
    __Vtemp_h23d0e588__0[1U] = 0x36347838U;
    __Vtemp_h23d0e588__0[2U] = 0x626c655fU;
    __Vtemp_h23d0e588__0[3U] = 0x655f7461U;
    __Vtemp_h23d0e588__0[4U] = 0x73696eU;
    VL_READMEM_N(true, 8, 64, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_h23d0e588__0)
                 ,  &(vlSelf->sine_table_tb__DOT__sine_table_inst__DOT__sine_rom__DOT__memory)
                 , 0, ~0ULL);
    vlSelf->sine_table_tb__DOT__id = 0U;
    VL_WRITEF("  0 = %b (%f)\n",16,vlSelf->sine_table_tb__DOT__data,
              64,(3.90625000000000000e-03 * VL_ISTOR_D_I(16, (IData)(vlSelf->sine_table_tb__DOT__data))));
    VL_FINISH_MT("sine_table_tb.sv", 29, "");
    sine_table_tb__DOT__sine_table_inst__DOT__quad = 0U;
    sine_table_tb__DOT__sine_table_inst__DOT__tab_id = 0U;
}

VL_ATTR_COLD void Vsine_table_tb___024root___settle__TOP__2(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___settle__TOP__2\n"); );
    // Init
    CData/*5:0*/ sine_table_tb__DOT__sine_table_inst__DOT__tab_id;
    CData/*7:0*/ sine_table_tb__DOT__sine_table_inst__DOT__tab_data;
    CData/*1:0*/ sine_table_tb__DOT__sine_table_inst__DOT__quad;
    // Body
    sine_table_tb__DOT__sine_table_inst__DOT__quad 
        = (3U & ((IData)(vlSelf->sine_table_tb__DOT__id) 
                 >> 6U));
    sine_table_tb__DOT__sine_table_inst__DOT__tab_id 
        = (0x3fU & ((2U & (IData)(sine_table_tb__DOT__sine_table_inst__DOT__quad))
                     ? ((1U & (IData)(sine_table_tb__DOT__sine_table_inst__DOT__quad))
                         ? (- (IData)(vlSelf->sine_table_tb__DOT__id))
                         : (IData)(vlSelf->sine_table_tb__DOT__id))
                     : ((1U & (IData)(sine_table_tb__DOT__sine_table_inst__DOT__quad))
                         ? (- (IData)(vlSelf->sine_table_tb__DOT__id))
                         : (IData)(vlSelf->sine_table_tb__DOT__id))));
    sine_table_tb__DOT__sine_table_inst__DOT__tab_data 
        = vlSelf->sine_table_tb__DOT__sine_table_inst__DOT__sine_rom__DOT__memory
        [sine_table_tb__DOT__sine_table_inst__DOT__tab_id];
    vlSelf->sine_table_tb__DOT__data = ((0x40U == (IData)(vlSelf->sine_table_tb__DOT__id))
                                         ? 0x100U : 
                                        ((0xc0U == (IData)(vlSelf->sine_table_tb__DOT__id))
                                          ? 0xff00U
                                          : (0xffffU 
                                             & ((2U 
                                                 & (IData)(sine_table_tb__DOT__sine_table_inst__DOT__quad))
                                                 ? 
                                                (- (IData)(sine_table_tb__DOT__sine_table_inst__DOT__tab_data))
                                                 : (IData)(sine_table_tb__DOT__sine_table_inst__DOT__tab_data)))));
}

VL_ATTR_COLD void Vsine_table_tb___024root___eval_initial(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___eval_initial\n"); );
    // Body
    Vsine_table_tb___024root___initial__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vsine_table_tb___024root___eval_settle(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___eval_settle\n"); );
    // Body
    Vsine_table_tb___024root___settle__TOP__2(vlSelf);
}

VL_ATTR_COLD void Vsine_table_tb___024root___final(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___final\n"); );
}

VL_ATTR_COLD void Vsine_table_tb___024root___ctor_var_reset(Vsine_table_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsine_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsine_table_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sine_table_tb__DOT__id = VL_RAND_RESET_I(8);
    vlSelf->sine_table_tb__DOT__data = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<64; ++__Vi0) {
        vlSelf->sine_table_tb__DOT__sine_table_inst__DOT__sine_rom__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vchglast__TOP__sine_table_tb__DOT__data = VL_RAND_RESET_I(16);
}
