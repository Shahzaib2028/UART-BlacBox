// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VUART_CORE_H_
#define _VUART_CORE_H_

#include "verilated.h"

class VUART_CORE__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VUART_CORE) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_ren,0,0);
    VL_IN8(io_we,0,0);
    VL_IN8(io_addr,7,0);
    VL_IN8(io_rx_i,0,0);
    VL_OUT8(io_tx_o,0,0);
    VL_OUT8(io_intr_tx,0,0);
    VL_IN(io_wdata,31,0);
    VL_OUT(io_rdata,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(UART_CORE__DOT__u_core_clk_i,0,0);
    VL_SIG8(UART_CORE__DOT__u_core_rst_ni,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__tx,7,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__rx_reg,7,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__rx_en,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__tx_en,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__rx_status,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__rx_clr,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_SM_Main,2,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_Bit_Index,2,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_TX_Data,7,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_TX_Done,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__o_TX_Serial,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_Rx_Data_R,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_Rx_Data,0,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_Rx_Byte,7,0);
    VL_SIG8(UART_CORE__DOT__u_core__DOT__r_Rx_DV,0,0);
    VL_SIG16(UART_CORE__DOT__u_core__DOT__control,15,0);
    VL_SIG16(UART_CORE__DOT__u_core__DOT__r_Clock_Count,15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main,2,0);
    VL_SIG8(__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index,2,0);
    VL_SIG8(__VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni,0,0);
    VL_SIG8(__Vclklast__TOP__UART_CORE__DOT__u_core_clk_i,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni,0,0);
    VL_SIG8(__Vchglast__TOP__UART_CORE__DOT__u_core_rst_ni,0,0);
    VL_SIG16(__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count,15,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VUART_CORE__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VUART_CORE& operator= (const VUART_CORE&);  ///< Copying not allowed
    VUART_CORE(const VUART_CORE&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VUART_CORE(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VUART_CORE();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VUART_CORE__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VUART_CORE__Syms* symsp, bool first);
  private:
    static QData _change_request(VUART_CORE__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VUART_CORE__Syms* __restrict vlSymsp);
    static void _combo__TOP__5(VUART_CORE__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(VUART_CORE__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(VUART_CORE__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VUART_CORE__Syms* __restrict vlSymsp);
    static void _eval_settle(VUART_CORE__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VUART_CORE__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VUART_CORE__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(VUART_CORE__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VUART_CORE__Syms* __restrict vlSymsp);
    static void traceChgThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
