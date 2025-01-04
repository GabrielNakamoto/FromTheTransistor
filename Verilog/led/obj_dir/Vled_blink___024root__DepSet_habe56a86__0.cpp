// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink.h for the primary calling header

#include "Vled_blink__pch.h"
#include "Vled_blink__Syms.h"
#include "Vled_blink___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink___024root___dump_triggers__act(Vled_blink___024root* vlSelf);
#endif  // VL_DEBUG

void Vled_blink___024root___eval_triggers__act(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vled_blink___024root___dump_triggers__act(vlSelf);
    }
#endif
}
