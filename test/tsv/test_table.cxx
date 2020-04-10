#include <catch2/catch.hpp>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

const int TEST_AGE = 10;

class TestClassTable {
    std::string name;
    int age;

    public:
        explicit TestClassTable(const std::string& name, const int age) { this->name = name; this->age = age;};
        auto getName() -> std::string { return name; };
        auto getAge() -> int { return age; }; // NOLINT
};

SCENARIO( "Table can be created" ) {
    GIVEN( "table" ) {
        const std::string name = "EMPLOYEES";        
        tsv::Table<TestClassTable> table(name);

        WHEN( "data is inserted to the table ") {
            TestClassTable data("Dixus", TEST_AGE);
            std::string expected = data.getName();

            const bool success = table.insert(data);

            THEN( "it can be read" ) {
                REQUIRE( success );
                REQUIRE( table.select().front().getName() == expected );
            }
        }

        WHEN( "multiple rows are inserted to the table ") {
            std::string expectedName1 = "Dixus";
            std::string expectedName2 = "Bixus";
            
            TestClassTable data1(expectedName1, TEST_AGE);
            TestClassTable data2(expectedName2, TEST_AGE);

            const bool success1 = table.insert(data1);
            const bool success2 = table.insert(data2);

            THEN( "they can be read" ) {
                REQUIRE( (success1 && success2) == true );
                REQUIRE( table.select().front().getName() == expectedName1 );
                REQUIRE( table.select().back().getName() == expectedName2 );
            }
        }
    }

    GIVEN( "populated table" ) {
        const std::string name = "EMPLOYEES";        
        tsv::Table<TestClassTable> table(name);
        const int ITEM_COUNT = 20;

        for(int i = 0; i < ITEM_COUNT; i++) {
            TestClassTable data("Dixus_" + std::to_string(i), i); 
            table.insert(data); 
        }

        WHEN( "data is queried by name value" ) {
            std::string expectedName = "Dixus_2";

            tsv::Query<TestClassTable, std::string> query(expectedName, &TestClassTable::getName);
            std::vector<TestClassTable> result = table.select(query);

            THEN( "only matching rows are selected" ) {
                REQUIRE( result.size() == 1 );
                REQUIRE( result.front().getName() == expectedName );
            }
        }

        WHEN( "data is queried by two different types sequentially" ) {
            std::string expectedName = "Dixus_2";
            int expectedAge = TEST_AGE;

            tsv::Query<TestClassTable, std::string> query1(expectedName, &TestClassTable::getName);
            std::vector<TestClassTable> result1 = table.select(query1);

            tsv::Query<TestClassTable, int> query2(expectedAge, &TestClassTable::getAge);
            std::vector<TestClassTable> result2 = table.select(query2);

            THEN( "only matching rows are selected" ) {
                REQUIRE( result1.size() == 1 );
                REQUIRE( result1.front().getName() == expectedName );

                REQUIRE( result2.size() == 1 );
                REQUIRE( result2.front().getAge() == expectedAge );
            }            
        }

        WHEN( "data is queried by nonexisting value" ) {
            std::string falseName = "Praxis";

            tsv::Query<TestClassTable, std::string> query(falseName, &TestClassTable::getName);
            std::vector<TestClassTable> result = table.select(query);

            THEN( "empty result set is returned" ) {
                REQUIRE ( result.empty() );
            }
        }
    }
}
