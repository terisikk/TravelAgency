#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "TravelAgencyConfig.h"
#include "agency.hpp"
#include "agencybuilder.hpp"
#include "customer.hpp"
#include "customerbuilder.hpp"


auto main() -> int
{
    try {
        tsv::Table<Agency> agencies("agencies");
        agencies.populate("agencies.txt", AgencyBuilder::build);

        tsv::Table<Customer> customers("customers");
        customers.populate("customers.txt", CustomerBuilder::build);

        tsv::Query<Agency, std::string> querya("Agency#8", &Agency::getName);

        for(auto& agency : agencies.select(querya)) {
            std::cout << agency.getName() << " " << agency.getStaffCount() << std::endl;
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
