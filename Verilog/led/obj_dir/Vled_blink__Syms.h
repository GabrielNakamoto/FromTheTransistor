// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLED_BLINK__SYMS_H_
#define VERILATED_VLED_BLINK__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vled_blink.h"

// INCLUDE MODULE CLASSES
#include "Vled_blink___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vled_blink__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vled_blink* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vled_blink___024root           TOP;

    // CONSTRUCTORS
    Vled_blink__Syms(VerilatedContext* contextp, const char* namep, Vled_blink* modelp);
    ~Vled_blink__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
