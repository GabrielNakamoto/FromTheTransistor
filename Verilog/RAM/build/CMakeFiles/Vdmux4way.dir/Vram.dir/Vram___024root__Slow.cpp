// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram.h for the primary calling header

#include "Vram__pch.h"
#include "Vram__Syms.h"
#include "Vram___024root.h"

void Vram___024root___ctor_var_reset(Vram___024root* vlSelf);

Vram___024root::Vram___024root(Vram__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vram___024root___ctor_var_reset(this);
}

void Vram___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vram___024root::~Vram___024root() {
}
