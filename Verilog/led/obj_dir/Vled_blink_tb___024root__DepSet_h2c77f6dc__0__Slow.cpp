// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink_tb.h for the primary calling header

#include "Vled_blink_tb__pch.h"
#include "Vled_blink_tb___024root.h"

VL_ATTR_COLD void Vled_blink_tb___024root___eval_static(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vled_blink_tb___024root___eval_final(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vled_blink_tb___024root___eval_settle(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink_tb___024root___dump_triggers__act(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge led_blink_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink_tb___024root___dump_triggers__nba(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge led_blink_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vled_blink_tb___024root___ctor_var_reset(Vled_blink_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink_tb___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->led_blink_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->led_blink_tb__DOT__led = VL_RAND_RESET_I(1);
    vlSelf->led_blink_tb__DOT__uut__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__led_blink_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
}
