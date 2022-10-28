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

class Vtop_WbMaster__Syms;
class Vtop_WbMaster_VerilatedVcd;
class Vtop_WbMaster___024unit;


//----------

VL_MODULE(Vtop_WbMaster) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_WbMaster___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(in_WB_o_cyc,0,0);
    VL_OUT8(o_wb_we,0,0);
    VL_OUT8(o_wb_cyc,0,0);
    VL_OUT8(o_wb_stb,0,0);
    VL_IN8(i_wb_stall,0,0);
    VL_IN8(i_wb_ack,0,0);
    VL_INOUT(io_wb_data,31,0);
    VL_OUT(o_wb_addr,31,0);
    VL_IN64(in_WB_ctr_w,33,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__i_cmd_rd;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__i_cmd_wr;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__i_cmd_bus;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__i_cmd_addr;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__i_cmd_special;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__ro_wb_cyc;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__ro_wb_stb;
    CData/*0:0*/ top_WbMaster__DOT__WBM__DOT__ro_wb_we;
    IData/*31:0*/ top_WbMaster__DOT__WBM__DOT__ro_wb_addr;
    IData/*31:0*/ top_WbMaster__DOT__WBM__DOT__rio_wb_data;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_WbMaster__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_WbMaster);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_WbMaster(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_WbMaster();
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
    static void _eval_initial_loop(Vtop_WbMaster__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_WbMaster__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_WbMaster__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop_WbMaster__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_WbMaster__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_WbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_WbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop_WbMaster__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop_WbMaster__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
