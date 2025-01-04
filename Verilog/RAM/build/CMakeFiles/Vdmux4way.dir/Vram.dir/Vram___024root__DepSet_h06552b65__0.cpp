// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram.h for the primary calling header

#include "Vram__pch.h"
#include "Vram___024root.h"

void Vram___024root___ico_sequent__TOP__0(Vram___024root* vlSelf);

void Vram___024root___eval_ico(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vram___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vram___024root___ico_sequent__TOP__0(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ dmux4way__DOT__h1;
    dmux4way__DOT__h1 = 0;
    CData/*0:0*/ dmux4way__DOT__h2;
    dmux4way__DOT__h2 = 0;
    // Body
    dmux4way__DOT__h1 = ((~ ((IData)(vlSelfRef.sel) 
                             >> 1U)) & (IData)(vlSelfRef.in));
    dmux4way__DOT__h2 = ((IData)(vlSelfRef.in) & ((IData)(vlSelfRef.sel) 
                                                  >> 1U));
    vlSelfRef.a = ((~ (IData)(vlSelfRef.sel)) & (IData)(dmux4way__DOT__h1));
    vlSelfRef.b = ((IData)(dmux4way__DOT__h1) & (IData)(vlSelfRef.sel));
    vlSelfRef.c = ((~ (IData)(vlSelfRef.sel)) & (IData)(dmux4way__DOT__h2));
    vlSelfRef.d = ((IData)(dmux4way__DOT__h2) & (IData)(vlSelfRef.sel));
}

void Vram___024root___eval_triggers__ico(Vram___024root* vlSelf);

bool Vram___024root___eval_phase__ico(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vram___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vram___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vram___024root___eval_act(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vram___024root___eval_nba(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vram___024root___eval_triggers__act(Vram___024root* vlSelf);

bool Vram___024root___eval_phase__act(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vram___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vram___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vram___024root___eval_phase__nba(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vram___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram___024root___dump_triggers__ico(Vram___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vram___024root___dump_triggers__nba(Vram___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vram___024root___dump_triggers__act(Vram___024root* vlSelf);
#endif  // VL_DEBUG

void Vram___024root___eval(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vram___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/raine/FromTheTransistor/Verilog/RAM/ram.v", 17, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vram___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vram___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/raine/FromTheTransistor/Verilog/RAM/ram.v", 17, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vram___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/raine/FromTheTransistor/Verilog/RAM/ram.v", 17, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vram___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vram___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vram___024root___eval_debug_assertions(Vram___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.in & 0xfeU))) {
        Verilated::overWidthError("in");}
    if (VL_UNLIKELY((vlSelfRef.sel & 0xfcU))) {
        Verilated::overWidthError("sel");}
}
#endif  // VL_DEBUG
