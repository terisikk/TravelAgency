#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "ui/context.hpp"

#include "TravelAgencyConfig.h"
#include "agency_query_state.hpp"
#include "agencymapper.hpp"
#include "customerbuilder.hpp"
#include "driverbuilder.hpp"
#include "travelbuilder.hpp"

auto main() -> int
{
    try {
        std::cout << "Loading database...";

        tsv::Table<Agency> agencies("agencies");
        agencies.populate("agencies.txt", AgencyMapper::build);

        tsv::Table<Customer> customers("customers");
        customers.populate("customers.txt", CustomerBuilder::build);

        tsv::Table<Driver> drivers("drivers");
        drivers.populate("drivers.txt", DriverBuilder::build);

        tsv::Table<Travel> travels("travels");
        travels.populate("travels.txt", TravelBuilder::build);

        std::cout << " done." << std::endl;

        AgencyQueryState agencyQueryState(&agencies);
        ui::Context uiContext(&agencyQueryState);

        while(true) {
            std::cout << uiContext.getOutput();

            std::string agencyName;
            std::cin >> agencyName;

            std::cout << uiContext.getOutput(agencyName);

        }

        /*
        tsv::Query<Agency, std::string> querya("Agency#7", &Agency::getName);
        for(auto& agency : agencies.select(querya)) {
            std::cout << agency.getName() << " " << agency.getStaffCount() << std::endl;
        }

        tsv::Query<Driver, std::string> queryd("Grit Dixus", &Driver::getCarModel);
        for(auto& driver : drivers.select(queryd)) {
            std::cout << driver.getName() << " " << driver.getCarModel() << std::endl;
        }

        const int TEST_CUSTOMER_ID = 9031;
        tsv::Query<Customer, int> queryc(TEST_CUSTOMER_ID, &Customer::getID);
        for(auto& customer : customers.select(queryc)) {
            std::cout << customer.getName() << " " << customer.getPhone() << std::endl;
        }

        const int TEST_TRAVEL_ID = 8274;
        tsv::Query<Travel, int> queryt(TEST_TRAVEL_ID, &Travel::getID);
        for(auto& travel : travels.select(queryt)) {
            std::cout << travel.getOrigin() << " -> " << travel.getDestination() << std::endl;
        }*/

    } catch (...) {
        return 0;
    }

    return 0;
}
