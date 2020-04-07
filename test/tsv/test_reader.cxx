#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "tsv/reader.hpp"

SCENARIO( "Reader can read file data", "[reader]" ) {
    GIVEN( "input stream") {
        std::istringstream stream;
        std::vector<std::string> expected;
        std::vector<std::string> actual;

        WHEN( "empty string is passed" ) {
            stream = std::istringstream("");
            expected = {};
            actual = tsv::Reader::readRow(stream);

            THEN( "empty vector is returned" ) {
                REQUIRE( actual.empty() );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "data with a newline is passed" ) {
            stream = std::istringstream("This is\ta line.\nline\ttwo\nline\tthree");
            expected = {"This is", "a line."};
            actual = tsv::Reader::readRow(stream);

            THEN( "only one row of items is returned" ) {
                REQUIRE( actual.size() == 2 );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "data with single tab is passed" ) {
            stream = std::istringstream("this\tis input");
            expected = {"this", "is input"};
            actual = tsv::Reader::readRow(stream);

            THEN( "data is split to two") {
                REQUIRE( actual.size() == 2 );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "data with multiple tabs is passed" ) {
            stream = std::istringstream("this\tis\tinput");
            expected = {"this", "is", "input"};
            actual = tsv::Reader::readRow(stream);

            THEN( "data is split") {
                REQUIRE( actual.size() == 3 );
                REQUIRE( actual == expected );
            }
        }

        WHEN( "multiple lines are passed") {
            stream = std::istringstream("line\t0\nline\t1\nline\t2\n");
            
            THEN( "data is split in two dimensions") {
                for(int i = 0; i < 3; i++) {
                    expected = {"line", std::to_string(i) };
                    actual = tsv::Reader::readRow(stream);
                    REQUIRE( actual.size() == 2 );
                    REQUIRE( actual == expected );
                }
            }
        }
    }
}
