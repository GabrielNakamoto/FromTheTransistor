// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink_tb.h for the primary calling header

#include "Vled_blink_tb__pch.h"
#include "Vled_blink_tb__Syms.h"
#include "Vled_blink_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vled_blink_tb___024root___eval_initial__TOP__Vtiming__1(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6c696e6bU;
    __Vtemp_1[2U] = 0x65645f62U;
    __Vtemp_1[3U] = 0x6cU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x5f5e100ULL, 
                                         nullptr, "tb.sv", 
                                         26);
    VL_FINISH_MT("tb.sv", 27, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink_tb___024root___dump_triggers__act(Vled_blink_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vled_blink_tb___024root___eval_triggers__act(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.led_blink_tb__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__led_blink_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__led_blink_tb__DOT__clk__0 
        = vlSelfRef.led_blink_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vled_blink_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
