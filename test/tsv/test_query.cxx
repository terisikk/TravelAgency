#include <catch2/catch.hpp>

#include <functional>
#include <typeinfo>

#include "tsv/query.hpp"

class TestClass {
    public:
        auto getName() -> std::string { return "Test"; }; // NOLINT
        auto getAge() -> int { return 10; }; // NOLINT
};

SCENARIO( "Queries can be created" ) {
    GIVEN( "two queries with different types" ) {
        tsv::Query<TestClass> name;
        tsv::Query<tsv::Query<TestClass>> number;

        WHEN( "query types are compared" ) {
            bool result = typeid(name) == typeid(number);

            THEN( "query types are not equal") {
                REQUIRE(result == false);
            }
        }
    }

    GIVEN( "two queries with same type" ) {
        tsv::Query<TestClass> firstName;
        tsv::Query<TestClass> lastName;

        WHEN( "query types are compared" ) {
            bool result = typeid(firstName) == typeid(lastName);

            THEN( "query types are equal") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN( "Query with a method pointer") {
        TestClass test;
        tsv::Query<TestClass> testQuery;
        std::string testName = "Test";

        WHEN( "query is executed" ) {
            bool result1 = testQuery.execute(testName, test, &TestClass::getName);
            bool result2 = testQuery.execute(20, test, &TestClass::getAge); // NOLINT

            THEN( "the comparison is correct" ) {
                REQUIRE(result1 == true);
                REQUIRE(result2 == false);
            }
        }
    }
}