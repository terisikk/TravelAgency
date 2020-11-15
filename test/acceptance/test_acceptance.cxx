#define CATCH_CONFIG_MAIN 

#include <catch2/catch.hpp>

#include "agency_query_state.hpp"
#include "customer_query_state.hpp"
#include "delete_travel_state.hpp"
#include "driver_for_customer_query_state.hpp"
#include "driver_query_state.hpp"
#include "insert_travel_state.hpp"
#include "travel_for_customer_query_state.hpp"
#include "travel_query_state.hpp"

SCENARIO( "Finding agencies based on name or ID" ) {
    GIVEN( "a state with agency table" ) {

        std::vector<std::string> expectedData = {"123", "Agency#1", "2011.02.11", "23", "Boss#1"};
        std::vector<std::string> extraData = {"1234", "Agency#12", "2011.02.11", "23", "Boss#1"};

        tsv::Table table({"ID", "NAME", "RDATE", "SCOUNT", "CNAME"});
        table.insert(expectedData);
        table.insert(extraData);

        AgencyQueryState state(&table);

        WHEN( "an name is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("Agency#1");

            THEN( "the agency is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }

        WHEN( "an ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("123");

            THEN( "the agency is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }
    }
}

SCENARIO( "Finding drivers based on name or ID" ) {
    GIVEN( "a state with driver table" ) {

        std::vector<std::string> expectedData = {"123", "1", "Driver#1", "2011.02.11", "Grit Dixus"};
        std::vector<std::string> extraData = {"1234", "2", "Driver#12", "2011.02.11", "Swot Hixus"};

        tsv::Table table({"ID", "AID", "NAME", "EDATE", "CAR"});
        table.insert(extraData);
        table.insert(expectedData);

        DriverQueryState state(&table);

        WHEN( "an name is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("Driver#1");

            THEN( "the driver is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }

        WHEN( "an ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("123");

            THEN( "the driver is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }
    }
}

SCENARIO( "Finding customers based on name or ID" ) {
    GIVEN( "a state with customer table" ) {

        std::vector<std::string> expectedData = {"123", "Customer#1", "+3587503673254", "Sreet#9031"};
        std::vector<std::string> extraData = {"1234", "Customer#12", "+3587509924227", "Sreet#90312"};

        tsv::Table table({"ID", "NAME", "PHONE", "ADDRESS"});
        table.insert(extraData);
        table.insert(expectedData);

        CustomerQueryState state(&table);

        WHEN( "an name is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("Customer#1");

            THEN( "the customer is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }

        WHEN( "an ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("123");

            THEN( "the customer is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }
    }
}

SCENARIO( "Finding travels based on ID" ) {
    GIVEN( "a state with travel table" ) {

        std::vector<std::string> expectedData = {"123", "456", "2016.12.06 09:43", "2481", "Source#99990", "Destination#99990", "20.00"};
        std::vector<std::string> extraData = {"1234", "4567", "2016.12.02 09:43", "2481", "Source#99990", "Destination#99990", "30.00"};

        tsv::Table table({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        table.insert(extraData);
        table.insert(expectedData);

        TravelQueryState state(&table);

        WHEN( "an ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("123");

            THEN( "the travel is correctly returned" ) {
                REQUIRE(result.size() == 1);
                REQUIRE(result.front() == expectedData);
            }
        }
    }
}

SCENARIO( "Inserting travels" ) {
    GIVEN( "a state with travel table" ) {

        std::vector<std::string> travel1 = {"123", "456", "2016.12.06 09:43", "2481", "Source#99990", "Destination#99990", "20.00"};
        std::vector<std::string> travel2 = {"1234", "4567", "2016.12.02 09:43", "2481", "Source#99990", "Destination#99990", "30.00"};

        tsv::Table table({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        table.insert(travel1);
        table.insert(travel2);

        InsertTravelState state(&table);

        WHEN( "a travel is given as an input" ) {
            std::vector<std::string> travel3 = {"354", "4567", "2016.12.03 09:43", "2482", "Source#99990", "Destination#99990", "30.00"};
            state.executeQuery(travel3);

            THEN( "the travel is correctly added to the table" ) {
                std::vector<std::vector<std::string>> result = table.select();

                REQUIRE(result.size() == 3);
                REQUIRE(result.back() == travel3);
            }
        }
    }
}

SCENARIO( "Deleting travels" ) {
    GIVEN( "a state with travel table" ) {

        std::vector<std::string> travel1 = {"123", "456", "2016.12.06 09:43", "2481", "Source#99990", "Destination#99990", "20.00"};
        std::vector<std::string> travel2 = {"1234", "4567", "2016.12.02 09:43", "2481", "Source#99990", "Destination#99990", "30.00"};

        tsv::Table table({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        table.insert(travel1);
        table.insert(travel2);

        DeleteTravelState state(&table);

        WHEN( "a travel ID is given as an input" ) {
            state.executeQuery("1234");

            THEN( "the travel is correctly deleted from the table" ) {
                std::vector<std::vector<std::string>> result = table.select();

                REQUIRE(result.size() == 1);
                REQUIRE(result.front() != travel2);
            }
        }
    }
}

SCENARIO( "Finding travels based on customer ID" ) {
    GIVEN( "a state with travel table and driver table" ) {

        std::vector<std::string> travel1 = {"123", "456", "2016.12.06 09:43", "2481", "Source#99990", "Destination#99990", "20.00"};
        std::vector<std::string> travel2 = {"1234", "4567", "2016.12.02 09:43", "2481", "Source#99990", "Destination#99990", "30.00"};
        std::vector<std::string> travel3 = {"354", "4567", "2016.12.03 09:43", "2482", "Source#99990", "Destination#99990", "30.00"};


        tsv::Table table({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        table.insert(travel1);
        table.insert(travel2);
        table.insert(travel3);

        TravelForCustomerQueryState state(&table);

        WHEN( "a customer ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("2481");

            THEN( "customer travels are correctly returned and sorted" ) {
                REQUIRE(result.size() == 2);
                REQUIRE(result.front() == travel2);
            }
        }
    }
}

SCENARIO( "Finding drivers based on customer ID" ) {
    GIVEN( "a state with driver table" ) {

        std::vector<std::string> travel1 = {"123", "123", "2016.12.06 09:43", "2481", "Source#99990", "Destination#99990", "20.00"};
        std::vector<std::string> travel2 = {"1234", "1234", "2016.12.02 09:43", "2481", "Source#99990", "Destination#99990", "30.00"};
        std::vector<std::string> travel3 = {"354", "4567", "2016.12.03 09:43", "2482", "Source#99990", "Destination#99990", "30.00"};

        tsv::Table travels({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        travels.insert(travel1);
        travels.insert(travel2);
        travels.insert(travel3);

        std::vector<std::string> driver1 = {"123", "1", "Driver B", "2011.02.11", "Grit Dixus"};
        std::vector<std::string> driver2 = {"1234", "2", "Driver A", "2011.02.11", "Swot Hixus"};
        std::vector<std::string> driver3 = {"345", "2", "Driver C", "2011.02.11", "Swot Hixus"};

        tsv::Table drivers({"ID", "AID", "NAME", "EDATE", "CAR"});
        drivers.insert(driver1);
        drivers.insert(driver2);
        drivers.insert(driver3);

        DriverForCustomerQueryState state(&drivers, &travels);

        WHEN( "a customer ID is given as an input" ) {

            std::vector<std::vector<std::string>> result = state.executeQuery("2481");

            THEN( "customer drivers are correctly returned and sorted" ) {
                REQUIRE(result.size() == 2);
                REQUIRE(result.front() == driver2);
            }
        }
    }
}

