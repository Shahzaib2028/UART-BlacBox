// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VUART_CORE__Syms.h"


//======================

void VUART_CORE::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VUART_CORE::traceInit, &VUART_CORE::traceFull, &VUART_CORE::traceChg, this);
}
void VUART_CORE::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VUART_CORE* t=(VUART_CORE*)userthis;
    VUART_CORE__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VUART_CORE::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VUART_CORE* t=(VUART_CORE*)userthis;
    VUART_CORE__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VUART_CORE::traceInitThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VUART_CORE::traceFullThis(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VUART_CORE::traceInitThis__1(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+20,"clock",-1);
	vcdp->declBit  (c+21,"reset",-1);
	vcdp->declBit  (c+22,"io_ren",-1);
	vcdp->declBit  (c+23,"io_we",-1);
	vcdp->declBus  (c+24,"io_wdata",-1,31,0);
	vcdp->declBus  (c+25,"io_addr",-1,7,0);
	vcdp->declBit  (c+26,"io_rx_i",-1);
	vcdp->declBus  (c+27,"io_rdata",-1,31,0);
	vcdp->declBit  (c+28,"io_tx_o",-1);
	vcdp->declBit  (c+29,"io_intr_tx",-1);
	vcdp->declBit  (c+20,"UART_CORE clock",-1);
	vcdp->declBit  (c+21,"UART_CORE reset",-1);
	vcdp->declBit  (c+22,"UART_CORE io_ren",-1);
	vcdp->declBit  (c+23,"UART_CORE io_we",-1);
	vcdp->declBus  (c+24,"UART_CORE io_wdata",-1,31,0);
	vcdp->declBus  (c+25,"UART_CORE io_addr",-1,7,0);
	vcdp->declBit  (c+26,"UART_CORE io_rx_i",-1);
	vcdp->declBus  (c+27,"UART_CORE io_rdata",-1,31,0);
	vcdp->declBit  (c+28,"UART_CORE io_tx_o",-1);
	vcdp->declBit  (c+29,"UART_CORE io_intr_tx",-1);
	vcdp->declBit  (c+1,"UART_CORE u_core_clk_i",-1);
	vcdp->declBit  (c+2,"UART_CORE u_core_rst_ni",-1);
	vcdp->declBit  (c+22,"UART_CORE u_core_ren",-1);
	vcdp->declBit  (c+23,"UART_CORE u_core_we",-1);
	vcdp->declBus  (c+24,"UART_CORE u_core_wdata",-1,31,0);
	vcdp->declBus  (c+25,"UART_CORE u_core_addr",-1,7,0);
	vcdp->declBit  (c+26,"UART_CORE u_core_rx_i",-1);
	vcdp->declBus  (c+30,"UART_CORE u_core_rdata",-1,31,0);
	vcdp->declBit  (c+7,"UART_CORE u_core_tx_o",-1);
	vcdp->declBit  (c+8,"UART_CORE u_core_intr_tx",-1);
	vcdp->declBit  (c+1,"UART_CORE u_core clk_i",-1);
	vcdp->declBit  (c+2,"UART_CORE u_core rst_ni",-1);
	vcdp->declBit  (c+22,"UART_CORE u_core ren",-1);
	vcdp->declBit  (c+23,"UART_CORE u_core we",-1);
	vcdp->declBus  (c+24,"UART_CORE u_core wdata",-1,31,0);
	vcdp->declBus  (c+30,"UART_CORE u_core rdata",-1,31,0);
	vcdp->declBus  (c+25,"UART_CORE u_core addr",-1,7,0);
	vcdp->declBit  (c+7,"UART_CORE u_core tx_o",-1);
	vcdp->declBit  (c+26,"UART_CORE u_core rx_i",-1);
	vcdp->declBit  (c+8,"UART_CORE u_core intr_tx",-1);
	vcdp->declBus  (c+32,"UART_CORE u_core ADDR_CTRL",-1,31,0);
	vcdp->declBus  (c+33,"UART_CORE u_core ADDR_TX",-1,31,0);
	vcdp->declBus  (c+34,"UART_CORE u_core ADDR_RX",-1,31,0);
	vcdp->declBus  (c+35,"UART_CORE u_core RX_EN",-1,31,0);
	vcdp->declBus  (c+36,"UART_CORE u_core TX_EN",-1,31,0);
	vcdp->declBus  (c+37,"UART_CORE u_core RX_STATUS",-1,31,0);
	vcdp->declBus  (c+38,"UART_CORE u_core RX_SC",-1,31,0);
	vcdp->declBus  (c+12,"UART_CORE u_core control",-1,15,0);
	vcdp->declBus  (c+13,"UART_CORE u_core tx",-1,7,0);
	vcdp->declBus  (c+3,"UART_CORE u_core rx",-1,7,0);
	vcdp->declBus  (c+4,"UART_CORE u_core rx_reg",-1,7,0);
	vcdp->declBit  (c+14,"UART_CORE u_core rx_en",-1);
	vcdp->declBit  (c+15,"UART_CORE u_core tx_en",-1);
	vcdp->declBit  (c+5,"UART_CORE u_core rx_status",-1);
	vcdp->declBit  (c+16,"UART_CORE u_core rx_clr",-1);
	vcdp->declBit  (c+6,"UART_CORE u_core rx_done",-1);
	vcdp->declBus  (c+39,"UART_CORE u_core IDLE",-1,2,0);
	vcdp->declBus  (c+40,"UART_CORE u_core TX_START_BIT",-1,2,0);
	vcdp->declBus  (c+41,"UART_CORE u_core TX_DATA_BITS",-1,2,0);
	vcdp->declBus  (c+42,"UART_CORE u_core TX_STOP_BIT",-1,2,0);
	vcdp->declBus  (c+43,"UART_CORE u_core CLEANUP",-1,2,0);
	vcdp->declBus  (c+17,"UART_CORE u_core r_SM_Main",-1,2,0);
	vcdp->declBus  (c+18,"UART_CORE u_core r_Clock_Count",-1,15,0);
	vcdp->declBus  (c+19,"UART_CORE u_core r_Bit_Index",-1,2,0);
	vcdp->declBus  (c+9,"UART_CORE u_core r_TX_Data",-1,7,0);
	vcdp->declBit  (c+8,"UART_CORE u_core r_TX_Done",-1);
	vcdp->declBit  (c+31,"UART_CORE u_core i_Rx_Serial",-1);
	vcdp->declBus  (c+12,"UART_CORE u_core CLKS_PER_BIT",-1,15,0);
	vcdp->declBit  (c+6,"UART_CORE u_core o_Rx_DV",-1);
	vcdp->declBus  (c+3,"UART_CORE u_core o_Rx_Byte",-1,7,0);
	vcdp->declBus  (c+13,"UART_CORE u_core i_TX_Byte",-1,7,0);
	vcdp->declBit  (c+7,"UART_CORE u_core o_TX_Serial",-1);
	vcdp->declBit  (c+8,"UART_CORE u_core o_TX_Done",-1);
	vcdp->declBus  (c+39,"UART_CORE u_core s_IDLE",-1,2,0);
	vcdp->declBus  (c+40,"UART_CORE u_core s_RX_START_BIT",-1,2,0);
	vcdp->declBus  (c+41,"UART_CORE u_core s_RX_DATA_BITS",-1,2,0);
	vcdp->declBus  (c+42,"UART_CORE u_core s_RX_STOP_BIT",-1,2,0);
	vcdp->declBus  (c+43,"UART_CORE u_core s_CLEANUP",-1,2,0);
	vcdp->declBit  (c+10,"UART_CORE u_core r_Rx_Data_R",-1);
	vcdp->declBit  (c+11,"UART_CORE u_core r_Rx_Data",-1);
	vcdp->declBus  (c+3,"UART_CORE u_core r_Rx_Byte",-1,7,0);
	vcdp->declBit  (c+6,"UART_CORE u_core r_Rx_DV",-1);
    }
}

void VUART_CORE::traceFullThis__1(VUART_CORE__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->UART_CORE__DOT__u_core_clk_i));
	vcdp->fullBit  (c+2,(vlTOPp->UART_CORE__DOT__u_core_rst_ni));
	vcdp->fullBus  (c+3,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte),8);
	vcdp->fullBus  (c+4,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg),8);
	vcdp->fullBit  (c+5,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status));
	vcdp->fullBit  (c+6,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV));
	vcdp->fullBit  (c+7,(vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial));
	vcdp->fullBit  (c+8,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done));
	vcdp->fullBus  (c+9,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Data),8);
	vcdp->fullBit  (c+10,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data_R));
	vcdp->fullBit  (c+11,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data));
	vcdp->fullBus  (c+12,(vlTOPp->UART_CORE__DOT__u_core__DOT__control),16);
	vcdp->fullBus  (c+13,(vlTOPp->UART_CORE__DOT__u_core__DOT__tx),8);
	vcdp->fullBit  (c+14,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en));
	vcdp->fullBit  (c+15,(vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en));
	vcdp->fullBit  (c+16,(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr));
	vcdp->fullBus  (c+17,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main),3);
	vcdp->fullBus  (c+18,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count),16);
	vcdp->fullBus  (c+19,(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index),3);
	vcdp->fullBit  (c+20,(vlTOPp->clock));
	vcdp->fullBit  (c+21,(vlTOPp->reset));
	vcdp->fullBit  (c+22,(vlTOPp->io_ren));
	vcdp->fullBit  (c+23,(vlTOPp->io_we));
	vcdp->fullBus  (c+24,(vlTOPp->io_wdata),32);
	vcdp->fullBus  (c+25,(vlTOPp->io_addr),8);
	vcdp->fullBit  (c+26,(vlTOPp->io_rx_i));
	vcdp->fullBus  (c+27,(vlTOPp->io_rdata),32);
	vcdp->fullBit  (c+28,(vlTOPp->io_tx_o));
	vcdp->fullBit  (c+29,(vlTOPp->io_intr_tx));
	vcdp->fullBus  (c+30,(((0x14U == (IData)(vlTOPp->io_addr))
			        ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status)
			        : ((8U == (IData)(vlTOPp->io_addr))
				    ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg)
				    : 0U))),32);
	vcdp->fullBit  (c+31,((1U & ((~ (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en)) 
				     | (IData)(vlTOPp->io_rx_i)))));
	vcdp->fullBus  (c+32,(0U),32);
	vcdp->fullBus  (c+33,(4U),32);
	vcdp->fullBus  (c+34,(8U),32);
	vcdp->fullBus  (c+35,(0xcU),32);
	vcdp->fullBus  (c+36,(0x10U),32);
	vcdp->fullBus  (c+37,(0x14U),32);
	vcdp->fullBus  (c+38,(0x18U),32);
	vcdp->fullBus  (c+39,(0U),3);
	vcdp->fullBus  (c+40,(1U),3);
	vcdp->fullBus  (c+41,(2U),3);
	vcdp->fullBus  (c+42,(3U),3);
	vcdp->fullBus  (c+43,(4U),3);
    }
}
