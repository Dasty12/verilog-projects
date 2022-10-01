// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_WBMASTER_H_
#define _VTOP_WBMASTER_H_  // guard

#include "verilated.h"

//==========

class Vtop_wbMaster__Syms;
class Vtop_wbMaster_VerilatedVcd;
class Vtop_wbMaster___024unit;


//----------

VL_MODULE(Vtop_wbMaster) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_wbMaster___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(op_in,1,0);
    VL_IN8(a_in,5,0);
    VL_IN8(b_in,5,0);
    VL_IN8(in_valid,0,0);
    VL_OUT8(out,5,0);
    VL_OUT8(out_valid,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ top_wbMaster__DOT__op_in_r;
    CData/*5:0*/ top_wbMaster__DOT__a_in_r;
    CData/*5:0*/ top_wbMaster__DOT__b_in_r;
    CData/*0:0*/ top_wbMaster__DOT__in_valid_r;
    CData/*5:0*/ top_wbMaster__DOT__result;
    CData/*0:0*/ top_wbMaster__DOT__in_data;
    CData/*0:0*/ top_wbMaster__DOT__rest;
    CData/*0:0*/ top_wbMaster__DOT__busy;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__clk_UART;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__clk_UART_old;
    CData/*7:0*/ top_wbMaster__DOT__rx__DOT__UR_data;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__data_IN_old;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__data_IN_FE;
    CData/*3:0*/ top_wbMaster__DOT__rx__DOT__data_cnt;
    CData/*1:0*/ top_wbMaster__DOT__rx__DOT__state;
    CData/*1:0*/ top_wbMaster__DOT__rx__DOT__state_old;
    CData/*7:0*/ top_wbMaster__DOT__rx__DOT__r_out_data;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__start;
    CData/*3:0*/ top_wbMaster__DOT__rx__DOT__dalsi_cnt;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__Rx_done_RE;
    CData/*0:0*/ top_wbMaster__DOT__rx__DOT__Rx_done_RE_old;
    SData/*13:0*/ top_wbMaster__DOT__rx__DOT__baud_cnt;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ top_wbMaster__DOT____Vcellout__rx__o_LEDS;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_wbMaster__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_wbMaster);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_wbMaster(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_wbMaster();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop_wbMaster__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_wbMaster__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_wbMaster__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop_wbMaster__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_wbMaster__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_wbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_wbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop_wbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtop_wbMaster__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop_wbMaster__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop_wbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
