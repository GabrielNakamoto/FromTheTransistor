// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vram.h for the primary calling header

#ifndef VERILATED_VRAM___024ROOT_H_
#define VERILATED_VRAM___024ROOT_H_  // guard

#include "verilated.h"


class Vram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vram___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(in,0,0);
    VL_IN8(sel,1,0);
    VL_OUT8(a,0,0);
    VL_OUT8(b,0,0);
    VL_OUT8(c,0,0);
    VL_OUT8(d,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vram___024root(Vram__Syms* symsp, const char* v__name);
    ~Vram___024root();
    VL_UNCOPYABLE(Vram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
