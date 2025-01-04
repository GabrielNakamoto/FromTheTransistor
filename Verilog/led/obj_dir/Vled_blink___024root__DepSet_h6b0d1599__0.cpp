// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink.h for the primary calling header

#include "Vled_blink__pch.h"
#include "Vled_blink___024root.h"

void Vled_blink___024root___eval_act(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vled_blink___024root___nba_sequent__TOP__0(Vled_blink___024root* vlSelf);

void Vled_blink___024root___eval_nba(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vled_blink___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vled_blink___024root___nba_sequent__TOP__0(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__led_blink__DOT__counter;
    __Vdly__led_blink__DOT__counter = 0;
    // Body
    __Vdly__led_blink__DOT__counter = vlSelfRef.led_blink__DOT__counter;
    __Vdly__led_blink__DOT__counter = ((IData)(1U) 
                                       + vlSelfRef.led_blink__DOT__counter);
    if ((0x17d7840U <= vlSelfRef.led_blink__DOT__counter)) {
        vlSelfRef.led = (1U & (~ (IData)(vlSelfRef.led)));
        __Vdly__led_blink__DOT__counter = 0U;
    }
    vlSelfRef.led_blink__DOT__counter = __Vdly__led_blink__DOT__counter;
}

void Vled_blink___024root___eval_triggers__act(Vled_blink___024root* vlSelf);

bool Vled_blink___024root___eval_phase__act(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vled_blink___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vled_blink___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vled_blink___024root___eval_phase__nba(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vled_blink___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink___024root___dump_triggers__nba(Vled_blink___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vled_blink___024root___dump_triggers__act(Vled_blink___024root* vlSelf);
#endif  // VL_DEBUG

void Vled_blink___024root___eval(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vled_blink___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("led_blink.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vled_blink___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("led_blink.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vled_blink___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vled_blink___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vled_blink___024root___eval_debug_assertions(Vled_blink___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled_blink___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
