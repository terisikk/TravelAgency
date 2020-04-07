#include <catch2/catch.hpp>
#include <sstream>
#include <string>

#include "tsv/reader.hpp"

SCENARIO( "Reader can read file data", "[reader]" ) {
    GIVEN( "input stream") {
        std::istringstream stream("This is a line.\n");
        std::string expected;
        std::string actual;

        WHEN( "input stream is passed" ) {
            expected = "This is a line.\n";
            actual = tsv::Reader::readInputStream(stream);

            THEN( "The content is read" ) {
                REQUIRE( actual == expected );
            }
        }
    }
}
