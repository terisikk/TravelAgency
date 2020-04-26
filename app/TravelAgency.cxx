#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/reader.hpp"
#include "tsv/table.hpp"

#include "TravelAgencyConfig.h"
#include "agency.hpp"
#include "agencybuilder.hpp"
#include "customer.hpp"
#include "customerbuilder.hpp"

template<class T>
auto populateTable(const std::string& filename, tsv::Table<T>* table) -> void {
    std::ifstream ifs;
    ifs.open(filename, std::ios_base::in);

    while(!ifs.eof()) {
        std::vector<std::string> items = tsv::Reader::readRow(ifs);
        if(!items.empty()) {
            Agency agency = AgencyBuilder::build(items);
            table->insert(agency);
        }
    }
}

template<class U>
auto populateCustomerTable(const std::string& filename, tsv::Table<U>* table) -> void {
    std::ifstream ifs;
    ifs.open(filename, std::ios_base::in);

    while(!ifs.eof()) {
        std::vector<std::string> items = tsv::Reader::readRow(ifs);
        if(!items.empty()) {
            Customer customer = CustomerBuilder::build(items);
            table->insert(customer);
        }
    }
}


auto main() -> int
{
    tsv::Table<Agency> agencies("agencies");
    populateAgencyTable("agencies.txt", &agencies);

    tsv::Table<Customer> customers;
    populateCustomerTable("customers.txt", &customers);

    tsv::Query<Agency, std::string> querya("Agency#8", &Agency::getName);

    for(auto& agency : agencies.select(querya)) {
        std::cout << agency.getName() << " " << agency.getStaffCount() << std::endl;
    }

    const int TEST_CUSTOMER_ID = 9031;
    tsv::Query<Customer, int> queryc(TEST_CUSTOMER_ID, &Customer::getID);

    for(auto& customer : customers.select(queryc)) {
        std::cout << customer.getName() << " " << customer.getPhone() << std::endl;
    }

    return 0;
}
