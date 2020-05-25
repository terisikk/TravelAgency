#include "customer_query_state.hpp"

CustomerQueryState::CustomerQueryState(tsv::Table* table) {
    this->table = table;
}

auto CustomerQueryState::getOutput() -> std::string {
    return "Enter customer name or ID: ";
}

auto CustomerQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", input);

        tsv::query::OR finalQuery(&nameQuery, &idQuery);

        std::stringstream output;
        output << "ID\t\tName\t\tPhone\t\t\tAddress" << std::endl;

        for(auto& data : table->select(finalQuery)) {
            output << CustomerMapper::toString(CustomerMapper::build(data));
        }

        return output.str();
    }

    return "";
}