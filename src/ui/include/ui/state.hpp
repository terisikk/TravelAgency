#ifndef UI_STATE_HPP
#define UI_STATE_HPP

#include <string>

namespace ui {

class State {
    public:
        State() = default;
        virtual auto getOutput() -> std::string = 0;
        
};

} // namespace ui

#endif
