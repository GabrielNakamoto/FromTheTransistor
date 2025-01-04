// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vled_blink_tb.h for the primary calling header

#ifndef VERILATED_VLED_BLINK_TB___024ROOT_H_
#define VERILATED_VLED_BLINK_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vled_blink_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vled_blink_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ led_blink_tb__DOT__clk;
    CData/*0:0*/ led_blink_tb__DOT__led;
    CData/*0:0*/ __Vtrigprevexpr___TOP__led_blink_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ led_blink_tb__DOT__uut__DOT__counter;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vled_blink_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vled_blink_tb___024root(Vled_blink_tb__Syms* symsp, const char* v__name);
    ~Vled_blink_tb___024root();
    VL_UNCOPYABLE(Vled_blink_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
