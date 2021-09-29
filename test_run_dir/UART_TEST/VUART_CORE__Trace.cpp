// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VUART_CORE__Syms.h"


//======================

void VUART_CORE::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VUART_CORE* t=(VUART_CORE*)userthis;
    VUART_CORE__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VUART_CORE::traceChgThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VUART_CORE::traceChgThis__2(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->UART_CORE__DOT__u_core_clk_i));
	vcdp->chgBit  (c+2,(vlTOPp->UART_CORE__DOT__u_core_rst_ni));
    }
}

void VUART_CORE::traceChgThis__3(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+3,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte),8);
	vcdp->chgBus  (c+4,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg),8);
	vcdp->chgBit  (c+5,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status));
	vcdp->chgBit  (c+6,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV));
    }
}

void VUART_CORE::traceChgThis__4(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+7,(vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial));
	vcdp->chgBit  (c+8,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done));
	vcdp->chgBus  (c+9,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Data),8);
	vcdp->chgBit  (c+10,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data_R));
	vcdp->chgBit  (c+11,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data));
    }
}

void VUART_CORE::traceChgThis__5(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+12,(vlTOPp->UART_CORE__DOT__u_core__DOT__control),16);
	vcdp->chgBus  (c+13,(vlTOPp->UART_CORE__DOT__u_core__DOT__tx),8);
	vcdp->chgBit  (c+14,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en));
	vcdp->chgBit  (c+15,(vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en));
	vcdp->chgBit  (c+16,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr));
	vcdp->chgBus  (c+17,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main),3);
	vcdp->chgBus  (c+18,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count),16);
	vcdp->chgBus  (c+19,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index),3);
    }
}

void VUART_CORE::traceChgThis__6(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+20,(vlTOPp->clock));
	vcdp->chgBit  (c+21,(vlTOPp->reset));
	vcdp->chgBit  (c+22,(vlTOPp->io_ren));
	vcdp->chgBit  (c+23,(vlTOPp->io_we));
	vcdp->chgBus  (c+24,(vlTOPp->io_wdata),32);
	vcdp->chgBus  (c+25,(vlTOPp->io_addr),8);
	vcdp->chgBit  (c+26,(vlTOPp->io_rx_i));
	vcdp->chgBus  (c+27,(vlTOPp->io_rdata),32);
	vcdp->chgBit  (c+28,(vlTOPp->io_tx_o));
	vcdp->chgBit  (c+29,(vlTOPp->io_intr_tx));
	vcdp->chgBus  (c+30,(((0x14U == (IData)(vlTOPp->io_addr))
			       ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status)
			       : ((8U == (IData)(vlTOPp->io_addr))
				   ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg)
				   : 0U))),32);
	vcdp->chgBit  (c+31,((1U & ((~ (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en)) 
				    | (IData)(vlTOPp->io_rx_i)))));
    }
}
