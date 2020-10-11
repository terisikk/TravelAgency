#include "appcontext.hpp"

AppContext::AppContext(ui::State* state) : ui::Context(state) {
    this->defaultState = state;
}

auto AppContext::tranisitionToDefaultState() -> void {
    if(this->defaultState != nullptr) {
        this->transition(this->defaultState);
    }
}