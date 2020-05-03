#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "TravelAgencyConfig.h"
#include "agencybuilder.hpp"
#include "customerbuilder.hpp"
#include "driverbuilder.hpp"
#include "trip.hpp"

auto main() -> int
{
    try {
        tsv::Table<Agency> agencies("agencies");
        agencies.populate("agencies.txt", AgencyBuilder::build);

        tsv::Table<Customer> customers("customers");
        customers.populate("customers.txt", CustomerBuilder::build);

        tsv::Table<Driver> drivers("drivers");
        drivers.populate("drivers.txt", DriverBuilder::build);

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


    } catch (...) {
        return 0;
    }

    return 0;
}
