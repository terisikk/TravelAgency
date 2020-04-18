#define CATCH_CONFIG_MAIN 

#include <catch2/catch.hpp>

#include "agency.hpp"
#include "agencybuilder.hpp"

SCENARIO( "Agency builder can build agencies" ) {
    GIVEN( "a builder and data" ) {

        std::vector<std::string> data = {"123", "Agency#1", "2011.02.11", "23", "Boss#1"};
        std::tm expectedDate = {0, 0, 0, 11, 1, 111, 0, 0}; // NOLINT 2011.02.11

        WHEN( "a build process is executed" ) {

            Agency agency = AgencyBuilder::build(data);

            THEN( "the agency is correctly created" ) {

                std::tm actualDate = agency.getRegisteredDate();

                REQUIRE( agency.getID() == 123 );
                REQUIRE( agency.getName() == "Agency#1" );
                REQUIRE( std::mktime(&actualDate) == std::mktime(&expectedDate));
                REQUIRE( agency.getStaffCount() == 23 );
                REQUIRE( agency.getChiefName() == "Boss#1" );
            }
        }
    }
}