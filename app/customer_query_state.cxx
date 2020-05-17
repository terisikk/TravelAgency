#include "customer_query_state.hpp"

CustomerQueryState::CustomerQueryState(tsv::Table<Customer>* table) {
    this->table = table;
}

auto CustomerQueryState::getOutput() -> std::string {
    return "Enter customer name or ID: ";
}

auto CustomerQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        int queryID = -1;

        try {
            queryID = std::stoi(input);
        } catch(...) {
            queryID = -1;
        }

        tsv::Query<Customer> query([input, queryID](Customer& customer) {return customer.getName() == input || customer.getID() == queryID ;});

        std::stringstream output;
        output << "ID\t\tName\t\tPhone\t\t\tAddress" << std::endl;

        for(auto& customer : table->select(query)) {
            output << CustomerMapper::toString(customer);
        }

        return output.str();
    }

    return "";
}