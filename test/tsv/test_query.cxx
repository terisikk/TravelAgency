#include <catch2/catch.hpp>

#include <functional>
#include <typeinfo>

#include "tsv/query.hpp"

class TestClass {
    public:
        int getName() { return 10; };
};

SCENARIO( "Queries can be created" ) {
    GIVEN( "two queries with different types" ) {
        tsv::Query<std::string, std::string> name;
        tsv::Query<int, int> number;

        WHEN( "query types are compared" ) {
            bool result = typeid(name) == typeid(number);

            THEN( "query types are not equal") {
                REQUIRE(result == false);
            }
        }
    }

    GIVEN( "two queries with same type" ) {
        tsv::Query<std::string, std::string> firstName;
        tsv::Query<std::string, std::string> lastName;

        WHEN( "query types are compared" ) {
            bool result = typeid(firstName) == typeid(lastName);

            THEN( "query types are equal") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN( "Query with a method pointer") {
        std::function<int(TestClass&)> methodPointer = &TestClass::getName;

        TestClass test;
        tsv::Query<TestClass, int> testQuery;

        WHEN( "query is executed" ) {
            bool result1 = testQuery.execute(test, methodPointer, 10);
            bool result2 = testQuery.execute(test, methodPointer, 20);

            THEN( "the comparison is correct" ) {
                REQUIRE(result1 == true);
                REQUIRE(result2 == false);
            }
        }
    }
}