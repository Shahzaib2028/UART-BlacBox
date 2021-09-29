// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUART_CORE.h for the primary calling header

#include "VUART_CORE.h"        // For This
#include "VUART_CORE__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VUART_CORE) {
    VUART_CORE__Syms* __restrict vlSymsp = __VlSymsp = new VUART_CORE__Syms(this, name());
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VUART_CORE::__Vconfigure(VUART_CORE__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VUART_CORE::~VUART_CORE() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VUART_CORE::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VUART_CORE::eval\n"); );
    VUART_CORE__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VUART_CORE::_eval_initial_loop(VUART_CORE__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VUART_CORE::_combo__TOP__1(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_combo__TOP__1\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->UART_CORE__DOT__u_core_clk_i = (1U & (~ (IData)(vlTOPp->clock)));
}

void VUART_CORE::_settle__TOP__2(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_settle__TOP__2\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->UART_CORE__DOT__u_core_clk_i = (1U & (~ (IData)(vlTOPp->clock)));
    vlTOPp->io_tx_o = vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial;
    vlTOPp->io_intr_tx = vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done;
    vlTOPp->io_rdata = ((0x14U == (IData)(vlTOPp->io_addr))
			 ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status)
			 : ((8U == (IData)(vlTOPp->io_addr))
			     ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg)
			     : 0U));
    vlTOPp->UART_CORE__DOT__u_core_rst_ni = (1U & (~ (IData)(vlTOPp->reset)));
}

VL_INLINE_OPT void VUART_CORE::_sequent__TOP__3(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_sequent__TOP__3\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main 
	= vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main;
    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
	= vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count;
    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index 
	= vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index;
    // ALWAYS at /home/shahzaib/UART/chisel-quickstart/test_run_dir/UART_TEST/uart_core.v:390
    if (vlTOPp->UART_CORE__DOT__u_core_rst_ni) {
	if (vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV) {
	    vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg 
		= vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte;
	    vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status = 1U;
	} else {
	    if ((1U & (~ (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr)))) {
		vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status = 0U;
	    }
	}
    } else {
	vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg = 0U;
    }
    // ALWAYS at /home/shahzaib/UART/chisel-quickstart/test_run_dir/UART_TEST/uart_core.v:236
    if (vlTOPp->UART_CORE__DOT__u_core_rst_ni) {
	if ((4U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
	    if ((2U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
	    } else {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
		} else {
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
		    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV = 0U;
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 < ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
			    - (IData)(1U)))) {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 3U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV = 1U;
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 4U;
		    }
		} else {
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 < ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
			    - (IData)(1U)))) {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte 
			    = (((~ ((IData)(1U) << (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index))) 
				& (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte)) 
			       | ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data) 
				  << (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index)));
			if ((7U > (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index))) {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index 
				= (7U & ((IData)(1U) 
					 + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index)));
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
			} else {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 3U;
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 == (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
			      - (IData)(1U)) >> 1U))) {
			if (vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data) {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
			} else {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
			}
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 1U;
		    }
		} else {
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
		    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV = 0U;
		    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte = 0U;
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main 
			= ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data)
			    ? 0U : 1U);
		}
	    }
	}
    } else {
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_DV = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Byte = 0U;
    }
}

VL_INLINE_OPT void VUART_CORE::_sequent__TOP__4(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_sequent__TOP__4\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__UART_CORE__DOT__u_core__DOT__r_TX_Data,7,0);
    VL_SIG8(__Vdly__UART_CORE__DOT__u_core__DOT__r_Rx_Data_R,0,0);
    // Body
    __Vdly__UART_CORE__DOT__u_core__DOT__r_Rx_Data_R 
	= vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data_R;
    __Vdly__UART_CORE__DOT__u_core__DOT__r_TX_Data 
	= vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Data;
    // ALWAYS at /home/shahzaib/UART/chisel-quickstart/test_run_dir/UART_TEST/uart_core.v:223
    if (vlTOPp->UART_CORE__DOT__u_core_rst_ni) {
	vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data 
	    = vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data_R;
	__Vdly__UART_CORE__DOT__u_core__DOT__r_Rx_Data_R 
	    = (1U & ((~ (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en)) 
		     | (IData)(vlTOPp->io_rx_i)));
    } else {
	__Vdly__UART_CORE__DOT__u_core__DOT__r_Rx_Data_R = 1U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data = 1U;
    }
    // ALWAYS at /home/shahzaib/UART/chisel-quickstart/test_run_dir/UART_TEST/uart_core.v:87
    if (vlTOPp->UART_CORE__DOT__u_core_rst_ni) {
	if ((4U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
	    if ((2U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
	    } else {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
		} else {
		    vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done = 1U;
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial = 1U;
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 < (0xffffU & ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
				       - (IData)(1U))))) {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 3U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done = 1U;
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 4U;
		    }
		} else {
		    vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial 
			= (1U & ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Data) 
				 >> (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index)));
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 < (0xffffU & ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
				       - (IData)(1U))))) {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			if ((7U > (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index))) {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index 
				= (7U & ((IData)(1U) 
					 + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index)));
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
			} else {
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
			    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 3U;
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main))) {
		    vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial = 0U;
		    if (((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count) 
			 < ((IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__control) 
			    - (IData)(1U)))) {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count 
			    = (0xffffU & ((IData)(1U) 
					  + (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count)));
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 1U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 2U;
		    }
		} else {
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
		    vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
		    vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial = 1U;
		    vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done = 0U;
		    if (vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en) {
			__Vdly__UART_CORE__DOT__u_core__DOT__r_TX_Data 
			    = vlTOPp->UART_CORE__DOT__u_core__DOT__tx;
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 1U;
		    } else {
			vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
		    }
		}
	    }
	}
    } else {
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = 0U;
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = 0U;
	vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = 0U;
	__Vdly__UART_CORE__DOT__u_core__DOT__r_TX_Data = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done = 0U;
    }
    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Rx_Data_R 
	= __Vdly__UART_CORE__DOT__u_core__DOT__r_Rx_Data_R;
    vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Data 
	= __Vdly__UART_CORE__DOT__u_core__DOT__r_TX_Data;
    vlTOPp->io_intr_tx = vlTOPp->UART_CORE__DOT__u_core__DOT__r_TX_Done;
    vlTOPp->io_tx_o = vlTOPp->UART_CORE__DOT__u_core__DOT__o_TX_Serial;
}

VL_INLINE_OPT void VUART_CORE::_combo__TOP__5(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_combo__TOP__5\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_rdata = ((0x14U == (IData)(vlTOPp->io_addr))
			 ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_status)
			 : ((8U == (IData)(vlTOPp->io_addr))
			     ? (IData)(vlTOPp->UART_CORE__DOT__u_core__DOT__rx_reg)
			     : 0U));
}

VL_INLINE_OPT void VUART_CORE::_sequent__TOP__6(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_sequent__TOP__6\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->UART_CORE__DOT__u_core__DOT__r_SM_Main 
	= vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main;
    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Clock_Count 
	= vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count;
    vlTOPp->UART_CORE__DOT__u_core__DOT__r_Bit_Index 
	= vlTOPp->__Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index;
    // ALWAYS at /home/shahzaib/UART/chisel-quickstart/test_run_dir/UART_TEST/uart_core.v:357
    if (vlTOPp->UART_CORE__DOT__u_core_rst_ni) {
	if (((~ (IData)(vlTOPp->io_ren)) & (IData)(vlTOPp->io_we))) {
	    if ((0U == (IData)(vlTOPp->io_addr))) {
		vlTOPp->UART_CORE__DOT__u_core__DOT__control 
		    = (0xffffU & vlTOPp->io_wdata);
	    } else {
		if ((4U == (IData)(vlTOPp->io_addr))) {
		    vlTOPp->UART_CORE__DOT__u_core__DOT__tx 
			= (0xffU & vlTOPp->io_wdata);
		} else {
		    if ((0xcU == (IData)(vlTOPp->io_addr))) {
			vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en 
			    = (1U & vlTOPp->io_wdata);
		    } else {
			if ((0x10U == (IData)(vlTOPp->io_addr))) {
			    vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en 
				= (1U & vlTOPp->io_wdata);
			} else {
			    if ((0x18U == (IData)(vlTOPp->io_addr))) {
				vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr 
				    = (1U & vlTOPp->io_wdata);
			    } else {
				vlTOPp->UART_CORE__DOT__u_core__DOT__control = 0U;
				vlTOPp->UART_CORE__DOT__u_core__DOT__tx = 0U;
				vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en = 0U;
				vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en = 0U;
				vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr = 1U;
			    }
			}
		    }
		}
	    }
	}
    } else {
	vlTOPp->UART_CORE__DOT__u_core__DOT__control = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__tx = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__rx_en = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__tx_en = 0U;
	vlTOPp->UART_CORE__DOT__u_core__DOT__rx_clr = 1U;
    }
}

VL_INLINE_OPT void VUART_CORE::_combo__TOP__7(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_combo__TOP__7\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->UART_CORE__DOT__u_core_rst_ni = (1U & (~ (IData)(vlTOPp->reset)));
}

void VUART_CORE::_eval(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_eval\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if ((((IData)(vlTOPp->UART_CORE__DOT__u_core_clk_i) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__UART_CORE__DOT__u_core_clk_i))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->UART_CORE__DOT__u_core_clk_i) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__UART_CORE__DOT__u_core_clk_i)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    if ((((IData)(vlTOPp->UART_CORE__DOT__u_core_clk_i) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__UART_CORE__DOT__u_core_clk_i))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__UART_CORE__DOT__u_core_clk_i 
	= vlTOPp->UART_CORE__DOT__u_core_clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni 
	= vlTOPp->__VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni;
    vlTOPp->__VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni 
	= vlTOPp->UART_CORE__DOT__u_core_rst_ni;
}

void VUART_CORE::_eval_initial(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_eval_initial\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VUART_CORE::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::final\n"); );
    // Variables
    VUART_CORE__Syms* __restrict vlSymsp = this->__VlSymsp;
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VUART_CORE::_eval_settle(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_eval_settle\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VUART_CORE::_change_request(VUART_CORE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_change_request\n"); );
    VUART_CORE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->UART_CORE__DOT__u_core_rst_ni ^ vlTOPp->__Vchglast__TOP__UART_CORE__DOT__u_core_rst_ni));
    VL_DEBUG_IF( if(__req && ((vlTOPp->UART_CORE__DOT__u_core_rst_ni ^ vlTOPp->__Vchglast__TOP__UART_CORE__DOT__u_core_rst_ni))) VL_DBG_MSGF("        CHANGE: UART_CORE.v:14: UART_CORE.u_core_rst_ni\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__UART_CORE__DOT__u_core_rst_ni 
	= vlTOPp->UART_CORE__DOT__u_core_rst_ni;
    return __req;
}

#ifdef VL_DEBUG
void VUART_CORE::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_ren & 0xfeU))) {
	Verilated::overWidthError("io_ren");}
    if (VL_UNLIKELY((io_we & 0xfeU))) {
	Verilated::overWidthError("io_we");}
    if (VL_UNLIKELY((io_rx_i & 0xfeU))) {
	Verilated::overWidthError("io_rx_i");}
}
#endif // VL_DEBUG

void VUART_CORE::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_CORE::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_ren = VL_RAND_RESET_I(1);
    io_we = VL_RAND_RESET_I(1);
    io_wdata = VL_RAND_RESET_I(32);
    io_addr = VL_RAND_RESET_I(8);
    io_rx_i = VL_RAND_RESET_I(1);
    io_rdata = VL_RAND_RESET_I(32);
    io_tx_o = VL_RAND_RESET_I(1);
    io_intr_tx = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core_clk_i = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core_rst_ni = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__control = VL_RAND_RESET_I(16);
    UART_CORE__DOT__u_core__DOT__tx = VL_RAND_RESET_I(8);
    UART_CORE__DOT__u_core__DOT__rx_reg = VL_RAND_RESET_I(8);
    UART_CORE__DOT__u_core__DOT__rx_en = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__tx_en = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__rx_status = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__rx_clr = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__r_SM_Main = VL_RAND_RESET_I(3);
    UART_CORE__DOT__u_core__DOT__r_Clock_Count = VL_RAND_RESET_I(16);
    UART_CORE__DOT__u_core__DOT__r_Bit_Index = VL_RAND_RESET_I(3);
    UART_CORE__DOT__u_core__DOT__r_TX_Data = VL_RAND_RESET_I(8);
    UART_CORE__DOT__u_core__DOT__r_TX_Done = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__o_TX_Serial = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__r_Rx_Data_R = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__r_Rx_Data = VL_RAND_RESET_I(1);
    UART_CORE__DOT__u_core__DOT__r_Rx_Byte = VL_RAND_RESET_I(8);
    UART_CORE__DOT__u_core__DOT__r_Rx_DV = VL_RAND_RESET_I(1);
    __Vdly__UART_CORE__DOT__u_core__DOT__r_SM_Main = VL_RAND_RESET_I(3);
    __Vdly__UART_CORE__DOT__u_core__DOT__r_Clock_Count = VL_RAND_RESET_I(16);
    __Vdly__UART_CORE__DOT__u_core__DOT__r_Bit_Index = VL_RAND_RESET_I(3);
    __VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni = VL_RAND_RESET_I(1);
    __Vclklast__TOP__UART_CORE__DOT__u_core_clk_i = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__UART_CORE__DOT__u_core_rst_ni = VL_RAND_RESET_I(1);
    __Vchglast__TOP__UART_CORE__DOT__u_core_rst_ni = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
