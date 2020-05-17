#include <catch2/catch.hpp>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

static const int TEST_AGE = 10;

SCENARIO( "Table can be created" ) {
    GIVEN( "table" ) {
        std::vector<std::string> keys = {"ID", "NAME", "AGE"};
        tsv::Table table(keys);

        WHEN( "data is inserted to the table ") {
            std::vector<std::string> data = {"0", "Dixus", std::to_string(TEST_AGE)};

            const bool success = table.insert(data);

            THEN( "it can be read" ) {
                REQUIRE( success );
                REQUIRE( table.select().front()[0] == data[0] );
            }
        }

        WHEN( "multiple rows are inserted to the table ") {
            std::string id1 = "1";
            std::string id2 = "2";
            std::string expectedName1 = "Dixus";
            std::string expectedName2 = "Bixus";
            
            std::vector<std::string> data1 = {id1, expectedName1, std::to_string(TEST_AGE)};
            std::vector<std::string> data2 = {id2, expectedName2, std::to_string(TEST_AGE)};

            const bool success1 = table.insert(data1);
            const bool success2 = table.insert(data2);

            THEN( "they can be read" ) {
                REQUIRE( (success1 && success2) == true );
                REQUIRE( table.select().front()[1] == expectedName1 );
                REQUIRE( table.select().back()[1] == expectedName2 );
            }
        }
    }

    GIVEN( "populated table" ) {
        std::vector<std::string> keys = {"ID", "NAME", "AGE"};
        tsv::Table table(keys);
        const int ITEM_COUNT = 20;

        for(int i = 0; i < ITEM_COUNT; i++) {
            std::vector<std::string> data = {std::to_string(i), "Dixus_" + std::to_string(i), std::to_string(i * TEST_AGE)}; 
            table.insert(data); 
        }

        WHEN( "data is queried by ID" ) {
            std::string expectedName = "Dixus_4";

            tsv::query::EQ query("ID", "4");
            std::vector<std::vector<std::string>> result = table.select(query);

            THEN( "only matching rows are selected" ) {
                REQUIRE( result.size() == 1 );
                REQUIRE( result.front()[1] == expectedName );
            }
        }

        WHEN( "data is queried by name value" ) {
            std::string expectedName = "Dixus_2";

            tsv::query::EQ query("NAME", expectedName);
            std::vector<std::vector<std::string>> result = table.select(query);

            THEN( "only matching rows are selected" ) {
                REQUIRE( result.size() == 1 );
                REQUIRE( result.front()[1] == expectedName );
            }
        }

        WHEN( "data is queried by nonexisting value" ) {
            std::string falseName = "Praxis";

            tsv::query::EQ query("NAME", falseName);
            std::vector<std::vector<std::string>> result = table.select(query);

            THEN( "empty result set is returned" ) {
                REQUIRE ( result.empty() );
            }
        }
    }
}
