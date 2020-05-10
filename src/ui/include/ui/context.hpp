#ifndef UI_CONTEXT_HPP
#define UI_CONTEXT_HPP

#include <string>

#include "ui/state.hpp"

namespace ui {

class Context {
    private:
        State* state = nullptr;

    public:
        Context() = default;
        explicit Context(State* state);

        auto transition(State* state) -> void;
        auto getOutput() -> std::string;
};

} // namespace ui

#endif
 