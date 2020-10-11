#ifndef APPCONTEXT_HPP
#define APPCONTEXT_HPP

#include "ui/context.hpp"
#include "ui/state.hpp"

class AppContext : public ui::Context {
    ui::State* defaultState;
    
    public:
        explicit AppContext(ui::State* state);

        auto tranisitionToDefaultState() -> void;

};

#endif