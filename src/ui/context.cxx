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

} // namespace ui