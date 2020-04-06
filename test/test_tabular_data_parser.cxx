#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "tabular_data_parser.hpp"

SCENARIO( "Data parser can split tabular data", "[dataparser]" ) {
    GIVEN( "Dataparser") {
        std::vector<std::string> expected;
        std::vector<std::string> actual;

        WHEN( "non-tabular data is parsed") {
            expected = {"this is input"};
            actual = TabularDataParser::parseRow("this is input");

            THEN( "data is not split") {
                REQUIRE( actual.size() == 1 );
                REQUIRE( actual == expected );
            }
        }
    }
}
