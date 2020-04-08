#include <catch2/catch.hpp>
#include <vector>

#include "tsv/table.hpp"

SCENARIO( "Table can be created" ) {
    GIVEN( "field names" ) {
        const std::vector<std::string> fieldNames = {"ID", "NAME", "PHONE"};
        const std::string name = "EMPLOYEES";

        WHEN( "field names are passed" ) {
            tsv::Table table(name, fieldNames);

            THEN( "table can be described" ) {
                REQUIRE( table.describe() == "EMPLOYEES: ID NAME PHONE" );
            }
        }
    }

    GIVEN( "table" ) {
        const std::vector<std::string> fieldNames = {"ID", "NAME", "PHONE"};
        const std::string name = "EMPLOYEES";        
        tsv::Table table(name, fieldNames);

        WHEN( "data is inserted to the table ") {
            const std::vector<std::string> data = {"123", "Dixus", "+456-123"};
            const std::vector<std::vector<std::string>> expected = {data};

            const bool success = table.insert(data);

            THEN( "it can be read" ) {
                REQUIRE( success );
                REQUIRE( table.select() == expected );
            }
        }

        WHEN( "multiple rows are inserted to the table ") {
            const std::vector<std::string> data1 = {"123", "Dixus", "+456-123"};
            const std::vector<std::string> data2 = {"124", "Bixus", "+456-456"};

            const std::vector<std::vector<std::string>> expected = {data1, data2};

            const bool success1 = table.insert(data1);
            const bool success2 = table.insert(data2);

            THEN( "they can be read" ) {
                REQUIRE( (success1 && success2) == true );
                REQUIRE( table.select() == expected );
            }
        }
    }

    GIVEN( "populated table and a query" ) {
        const std::vector<std::string> fieldNames = {"ID", "NAME", "PHONE"};
        const std::string name = "EMPLOYEES";        
        tsv::Table table(name, fieldNames);
        const int ITEM_COUNT = 10;
        const int INITIAL_PHONE = 12345;

        for(int i = 0; i < ITEM_COUNT; i++) {
            const std::vector<std::string> data = {
                std::to_string(i), 
                "Dixus_" + std::to_string(i), 
                std::to_string(i * INITIAL_PHONE)
            };

            table.insert(data); 
        }

        const std::vector<std::string> query = {"ID", "2"};
        const std::vector<std::vector<std::string>> expected = {{"2", "Dixus_2", "24690"}}; 

        WHEN( "data is queried by field name and value" ) {
            const std::vector<std::vector<std::string>> result = table.select(query);

            THEN( "only matching rows are selected" ) {
                REQUIRE( result == expected );
            }
        } 
    }
}
