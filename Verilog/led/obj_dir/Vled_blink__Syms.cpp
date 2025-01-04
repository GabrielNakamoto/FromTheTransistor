// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vled_blink__pch.h"
#include "Vled_blink.h"
#include "Vled_blink___024root.h"

// FUNCTIONS
Vled_blink__Syms::~Vled_blink__Syms()
{
}

Vled_blink__Syms::Vled_blink__Syms(VerilatedContext* contextp, const char* namep, Vled_blink* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(19);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
