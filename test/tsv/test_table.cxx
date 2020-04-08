#include <catch2/catch.hpp>
#include <vector>

#include "tsv/table.hpp"

SCENARIO( "Table can be created" ) {
    GIVEN( "field names" ) {
        std::vector<std::string> headers = {"ID", "NAME", "PHONE"};
        std::string name = "EMPLOYEES";

        WHEN( "field names are passed" ) {
            tsv::Table table(name, headers);

            THEN( "table can be described" ) {
                REQUIRE( table.describe() == "EMPLOYEES: ID NAME PHONE" );
            }
        }
    }

    GIVEN ( "table" ) {
        std::vector<std::string> headers = {"ID", "NAME", "PHONE"};
        std::string name = "EMPLOYEES";        
        tsv::Table table(name, headers);

        WHEN( "data is inserted to the table ") {
            std::vector<std::string> data = {"123", "Dixus", "+456-123"};
            std::vector<std::vector<std::string>> expected = {data};

            bool success = table.insert(data);

            THEN( "it can be read" ) {
                REQUIRE( success );
                REQUIRE( expected == table.select() );
            }
        }

        WHEN( "multiple rows are inserted to the table ") {
            std::vector<std::string> data1 = {"123", "Dixus", "+456-123"};
            std::vector<std::string> data2 = {"124", "Bixus", "+456-456"};

            std::vector<std::vector<std::string>> expected = {data1, data2};

            bool success1 = table.insert(data1);
            bool success2 = table.insert(data2);

            THEN( "they can be read" ) {
                REQUIRE( (success1 && success2) == true );
                REQUIRE( expected == table.select() );
            }
        }
    }
}
