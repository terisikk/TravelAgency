#ifndef UI_STATE_HPP
#define UI_STATE_HPP

#include <string>

namespace ui {

class Context;

class State {
    private:
        Context* context = nullptr;

    public:
        State() = default;
        virtual auto getOutput() -> std::string = 0;
        virtual auto getOutput(const std::string& input) -> std::string = 0;

        auto setContext(Context* context) -> void { this->context = context; };
        auto getContext() -> Context* { return context; };
};

} // namespace ui

#endif
