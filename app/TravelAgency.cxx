#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "TravelAgencyConfig.h"
#include "agencybuilder.hpp"
#include "customerbuilder.hpp"
#include "driverbuilder.hpp"
#include "travelbuilder.hpp"

auto main() -> int
{
    try {
        std::cout << "Loading database...";

        tsv::Table<Agency> agencies("agencies");
        agencies.populate("agencies.txt", AgencyBuilder::build);

        tsv::Table<Customer> customers("customers");
        customers.populate("customers.txt", CustomerBuilder::build);

        tsv::Table<Driver> drivers("drivers");
        drivers.populate("drivers.txt", DriverBuilder::build);

        tsv::Table<Travel> travels("travels");
        travels.populate("travels.txt", TravelBuilder::build);

        std::cout << " done." << std::endl;

        while(true) {
            std::cout << "Enter agency name: ";

            std::string agencyName;
            std::cin >> agencyName;

            tsv::Query<Agency, std::string> query(agencyName, &Agency::getName);
            for(auto& agency : agencies.select(query)) {
                const std::tm& time = std::tm(agency.getRegisteredDate());

                std::cout << "ID:\t\t" << agency.getID() << std::endl
                    << "Name:\t\t" << agency.getName() << std::endl
                    << "Registered:\t" << std::put_time(&time, "%Y.%m.%d")  << std::endl
                    << "Staff count:\t" << agency.getStaffCount() << std::endl
                    << "Chief:\t\t" << agency.getChiefName() << std::endl
                    << std::endl;
            } 
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
