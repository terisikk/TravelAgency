#include <utility>

#include "ui/context.hpp"

namespace ui {

Context::Context(State* state) {
    this->transition(state);
}

auto Context::transition(State* state) -> void {
    this->state = state;
}

auto Context::getOutput() -> std::string {
    if(state != nullptr) {
        return state->getOutput();
    } 

    return "";
}

auto Context::getOutput(const std::string& input) -> std::string {
    if(state != nullptr) {
        return state->getOutput(input);
    } 

    return "";
}

} // namespace ui