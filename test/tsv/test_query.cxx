#include <catch2/catch.hpp>

#include <functional>
#include <typeinfo>

#include "tsv/query.hpp"

class TestClassQuery {
    public:
        auto getName() -> std::string { return std::string("Test"); }; // NOLINT
        auto getAge() -> int { return 10; }; // NOLINT
};

SCENARIO( "Queries can be created" ) {
    GIVEN( "Query with a method pointer") {
        TestClassQuery test;
        std::string testName("Test");

        tsv::Query<TestClassQuery, std::string> testQuery1(testName, &TestClassQuery::getName);
        tsv::Query<TestClassQuery, int> testQuery2(20, &TestClassQuery::getAge); // NOLINT

        WHEN( "query is executed" ) {
            bool result1 = testQuery1.execute(test);
            bool result2 = testQuery2.execute(test);

            THEN( "the comparison is correct" ) {
                REQUIRE(result1 == true);
                REQUIRE(result2 == false);
            }
        }
    }
}