#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "ui/context.hpp"

#include "TravelAgencyConfig.h"
#include "agency_query_state.hpp"
#include "customer_query_state.hpp"
#include "driver_query_state.hpp"
#include "travel_query_state.hpp"

auto main() -> int
{
    try {
        std::cout << "Loading database...";

        tsv::Table agencies({"ID", "NAME", "RDATE", "SCOUNT", "CNAME"});
        agencies.populate("agencies.txt", AgencyMapper::build);

        tsv::Table customers({"ID", "NAME", "PHONE", "ADDRESS"});
        customers.populate("customers.txt", CustomerMapper::build);

        tsv::Table drivers({"ID", "AID", "NAME", "EDATE", "CAR"});
        drivers.populate("drivers.txt", DriverMapper::build);

        tsv::Table travels({"ID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        travels.populate("travels.txt", TravelMapper::build);

        std::cout << " done." << std::endl;

        //AgencyQueryState agencyQueryState(&agencies);
        //DriverQueryState driverQueryState(&drivers);
        //CustomerQueryState customerQueryState(&customers);
        TravelQueryState travelQueryState(&travels);
        ui::Context uiContext(&travelQueryState);

        while(true) {
            std::cout << uiContext.getOutput();

            std::string input;
            std::cin >> input;

            std::cout << uiContext.getOutput(input);

        }

    } catch (...) {
        return 0;
    }

    return 0;
}
