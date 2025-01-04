// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink.h for the primary calling header

#include "Vled_blink__pch.h"
#include "Vled_blink__Syms.h"
#include "Vled_blink___024root.h"

void Vled_blink___024root___ctor_var_reset(Vled_blink___024root* vlSelf);

Vled_blink___024root::Vled_blink___024root(Vled_blink__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vled_blink___024root___ctor_var_reset(this);
}

void Vled_blink___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vled_blink___024root::~Vled_blink___024root() {
}
