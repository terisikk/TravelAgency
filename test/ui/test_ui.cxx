#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>

#include "ui/context.hpp"
#include "ui/state.hpp"

class ConcreteState1 : public ui::State {
    public:
        auto getOutput() -> std::string override {
            return "This is state1";
        };
};

class ConcreteState2 : public ui::State {
    public:
        auto getOutput() -> std::string override {
            return "This is state2";
        };
};


SCENARIO( "States can be changed" ) {
    GIVEN( "Context and empty state" ) {
        ui::Context context(nullptr);

        WHEN( "state output is requested" ) {
            THEN( "no error is produced" ) {
                context.getOutput();
            }
        }
    }


    GIVEN( "Context and initial state" ) {
        ConcreteState1 state1;
        ui::Context context(&state1);

        WHEN( "state output is requested" ) {
            std::string actual = context.getOutput();
            std::string expected = "This is state1"; 

            THEN( "correct output is produced" ) {
                REQUIRE( actual == expected );
            }
        }
    }

    GIVEN( "Context and two states" ) {
        ConcreteState1 state1;
        ConcreteState2 state2;
        ui::Context context(&state1);

        WHEN( "state output is requested" ) {
            context.transition(&state2);
            std::string expected = "This is state2"; 

            THEN( "correct output is produced" ) {
                REQUIRE( context.getOutput() == expected );
            }
        }
    }
}