// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled_blink_tb.h for the primary calling header

#include "Vled_blink_tb__pch.h"
#include "Vled_blink_tb__Syms.h"
#include "Vled_blink_tb___024root.h"

void Vled_blink_tb___024root___ctor_var_reset(Vled_blink_tb___024root* vlSelf);

Vled_blink_tb___024root::Vled_blink_tb___024root(Vled_blink_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vled_blink_tb___024root___ctor_var_reset(this);
}

void Vled_blink_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vled_blink_tb___024root::~Vled_blink_tb___024root() {
}
