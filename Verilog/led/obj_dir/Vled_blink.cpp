// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vled_blink__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vled_blink::Vled_blink(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vled_blink__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vled_blink::Vled_blink(const char* _vcname__)
    : Vled_blink(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vled_blink::~Vled_blink() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vled_blink___024root___eval_debug_assertions(Vled_blink___024root* vlSelf);
#endif  // VL_DEBUG
void Vled_blink___024root___eval_static(Vled_blink___024root* vlSelf);
void Vled_blink___024root___eval_initial(Vled_blink___024root* vlSelf);
void Vled_blink___024root___eval_settle(Vled_blink___024root* vlSelf);
void Vled_blink___024root___eval(Vled_blink___024root* vlSelf);

void Vled_blink::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vled_blink::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vled_blink___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vled_blink___024root___eval_static(&(vlSymsp->TOP));
        Vled_blink___024root___eval_initial(&(vlSymsp->TOP));
        Vled_blink___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vled_blink___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vled_blink::eventsPending() { return false; }

uint64_t Vled_blink::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vled_blink::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vled_blink___024root___eval_final(Vled_blink___024root* vlSelf);

VL_ATTR_COLD void Vled_blink::final() {
    Vled_blink___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vled_blink::hierName() const { return vlSymsp->name(); }
const char* Vled_blink::modelName() const { return "Vled_blink"; }
unsigned Vled_blink::threads() const { return 1; }
void Vled_blink::prepareClone() const { contextp()->prepareClone(); }
void Vled_blink::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vled_blink::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vled_blink___024root__trace_decl_types(VerilatedVcd* tracep);

void Vled_blink___024root__trace_init_top(Vled_blink___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vled_blink___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vled_blink___024root*>(voidSelf);
    Vled_blink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vled_blink___024root__trace_decl_types(tracep);
    Vled_blink___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vled_blink___024root__trace_register(Vled_blink___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vled_blink::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vled_blink::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vled_blink___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
