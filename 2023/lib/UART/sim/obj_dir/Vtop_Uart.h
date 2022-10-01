// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_UART_H_
#define _VTOP_UART_H_  // guard

#include "verilated.h"

//==========

class Vtop_Uart__Syms;
class Vtop_Uart_VerilatedVcd;
class Vtop_Uart___024unit;


//----------

VL_MODULE(Vtop_Uart) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_Uart___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(in_w_data,7,0);
    VL_IN8(in_valid,0,0);
    VL_OUT8(out_BUSY,0,0);
    VL_OUT8(out_signal,0,0);
    VL_IN8(UART_IN,0,0);
    VL_OUT8(out_word,7,0);
    VL_OUT8(out_RXNE,0,0);
    VL_OUT8(out_Rx_ORE,0,0);
    VL_OUT8(bauld,6,0);
    VL_IN8(data_ted,0,0);
    VL_IN8(state_cnt,3,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ top_Uart__DOT__r_Tx_DataByte;
    CData/*0:0*/ top_Uart__DOT__r_Tx_start;
    CData/*0:0*/ top_Uart__DOT__r_Tx_busy;
    CData/*0:0*/ top_Uart__DOT__in_valid_old;
    CData/*4:0*/ top_Uart__DOT__rst_counter;
    CData/*6:0*/ top_Uart__DOT__bauld_r;
    CData/*0:0*/ top_Uart__DOT__r_rst;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__clk_UART;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__clk_UART_old;
    CData/*7:0*/ top_Uart__DOT__uartRx__DOT__UR_data;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__UART_IN_old;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__UART_IN_FE;
    CData/*3:0*/ top_Uart__DOT__uartRx__DOT__data_index;
    CData/*1:0*/ top_Uart__DOT__uartRx__DOT__state;
    CData/*1:0*/ top_Uart__DOT__uartRx__DOT__state_old;
    CData/*6:0*/ top_Uart__DOT__uartRx__DOT__baud_cnt;
    CData/*7:0*/ top_Uart__DOT__uartRx__DOT__r_out_data;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__startReceive;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__Rx_done_r;
    CData/*0:0*/ top_Uart__DOT__uartRx__DOT__Rx_done_r_old;
    CData/*1:0*/ top_Uart__DOT__uartTx__DOT__state;
    CData/*6:0*/ top_Uart__DOT__uartTx__DOT__baud_cnt;
    CData/*7:0*/ top_Uart__DOT__uartTx__DOT__Data;
    CData/*3:0*/ top_Uart__DOT__uartTx__DOT__r_data_cnt;
    CData/*0:0*/ top_Uart__DOT__uartTx__DOT__r_out_dataBit;
    CData/*0:0*/ top_Uart__DOT__uartTx__DOT__r_out_fComplete;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_Uart__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_Uart);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_Uart(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_Uart();
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
    static void _eval_initial_loop(Vtop_Uart__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_Uart__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_Uart__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop_Uart__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__5(Vtop_Uart__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_Uart__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_Uart__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_Uart__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vtop_Uart__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vtop_Uart__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vtop_Uart__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__4(Vtop_Uart__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
