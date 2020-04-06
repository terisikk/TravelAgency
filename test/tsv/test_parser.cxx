#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "parser.hpp"

SCENARIO( "Parser can split tabular data", "[parser]" ) {
    GIVEN( "Parser") {
        std::vector<std::string> expected;
        std::vector<std::string> actual;

        WHEN( "empty string is parsed" ) {
            expected = {};
            actual = Parser::parseRow("");

            THEN("empty vector is returned") {
                REQUIRE( actual.empty() );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "non-tabular data is parsed" ) {
            expected = {"this is input"};
            actual = Parser::parseRow("this is input");

            THEN( "data is not split") {
                REQUIRE( actual.size() == 1 );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "data with single tab is parsed" ) {
            expected = {"this", "is input"};
            actual = Parser::parseRow("this\tis input");

            THEN( "data is split to two") {
                REQUIRE( actual.size() == 2 );
                REQUIRE( actual == expected );
            }
        }
        
        WHEN( "data with multiple tabs is parsed" ) {
            expected = {"this", "is", "input"};
            actual = Parser::parseRow("this\tis\tinput");

            THEN( "data is split") {
                REQUIRE( actual.size() == 3 );
                REQUIRE( actual == expected );
            }
        }
    }
}
