// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_UART2WB_H_
#define _VTOP_UART2WB_H_  // guard

#include "verilated.h"

//==========

class Vtop_Uart2wb__Syms;
class Vtop_Uart2wb_VerilatedVcd;
class Vtop_Uart2wb___024unit;


//----------

VL_MODULE(Vtop_Uart2wb) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_Uart2wb___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(UART_in_data,7,0);
    VL_IN8(UART_Rx_done,0,0);
    VL_OUT8(WB_o_cyc,0,0);
    VL_OUT64(WB_ctr_w,33,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ top_Uart2wb__DOT__U2W__DOT__asciiToBits;
    CData/*0:0*/ top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p;
    CData/*0:0*/ top_Uart2wb__DOT__U2W__DOT__WB_o_cyc_r;
    QData/*33:0*/ top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_r;
    QData/*33:0*/ top_Uart2wb__DOT__U2W__DOT__WB_ctr_w_o;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*1:0*/ __Vtablechg1[1024];
    CData/*0:0*/ __Vm_traceActivity[2];
    static CData/*4:0*/ __Vtable1_top_Uart2wb__DOT__U2W__DOT__asciiToBits[1024];
    static CData/*0:0*/ __Vtable1_top_Uart2wb__DOT__U2W__DOT__UART_rx_done_1p[1024];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_Uart2wb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_Uart2wb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_Uart2wb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_Uart2wb();
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
    static void _eval_initial_loop(Vtop_Uart2wb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_Uart2wb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_Uart2wb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop_Uart2wb__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_Uart2wb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_Uart2wb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_Uart2wb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop_Uart2wb__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop_Uart2wb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
