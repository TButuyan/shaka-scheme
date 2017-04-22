#ifndef SHAKA_CORE_EVAL_SETUPTOPLEVEL_IMPL_H
#define SHAKA_CORE_EVAL_SETUPTOPLEVEL_IMPL_H

#include "core/base/Core.h"
#include "core/eval/SetupTopLevel.h"
#include "core/eval/Define.h"

#include "core/proc/primitives.h"
#include "core/proc/Numbers_Arithmetic_impl.h"


namespace shaka { 
    
/// Encapsulates the EvaluatorStrategy classes
namespace eval {

/// @brief returns a std::shared_ptr to the child node
NodePtr SetupTopLevel::evaluate(
    NodePtr node,
    EnvPtr env
) {
    std::cout << "@SetupTopLevel" << std::endl;

    // Turn off node unused warning.
    static_cast<void>(node);

    // These procedures come from core/proc/primitives.h
    //
    // They implement the primitive expressions as defined in R7RS.
    env->set_value(Symbol("define"),
                   make_node(PrimitiveProcedure(shaka::proc::define, 2)));

    env->set_value(Symbol("quote"),
                   make_node(PrimitiveProcedure(shaka::proc::quote, 1)));

    // Numbers Arithmetic section.
    env->set_value(Symbol("+"),
                   make_node(PrimitiveProcedure(shaka::stdproc::add, 1, true)));

    env->set_value(Symbol("-"),
                   make_node(PrimitiveProcedure(shaka::stdproc::sub, 1, true)));

    env->set_value(Symbol("*"),
                   make_node(PrimitiveProcedure(shaka::stdproc::mul, 1, true)));

    env->set_value(Symbol("/"),
                   make_node(PrimitiveProcedure(shaka::stdproc::div, 1, true)));

    env->set_value(Symbol("abs"),
                   make_node(PrimitiveProcedure(shaka::stdproc::abs, 1)));


    env->print_bindings(std::cout);

    return nullptr;
}


} // namespace eval

} // namespace shaka

#endif // SHAKA_CORE_EVAL_SETUPTOPLEVEL_IMPL_H