#include "customer_query_state.hpp"

CustomerQueryState::CustomerQueryState(tsv::Table* table) {
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

        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", queryID);

        tsv::query::OR finalQuery(nameQuery, idQuery);

        std::stringstream output;
        output << "ID\t\tName\t\tPhone\t\t\tAddress" << std::endl;

        for(auto& customer : table->select(finalQuery)) {
            output << CustomerMapper::toString(customer);
        }

        return output.str();
    }

    return "";
}