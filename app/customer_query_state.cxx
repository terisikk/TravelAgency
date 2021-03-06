#include "customer_query_state.hpp"

CustomerQueryState::CustomerQueryState(tsv::Table* table) {
    this->table = table;
}

auto CustomerQueryState::getOutput() -> std::string {
    return "Enter customer name or ID: ";
}

auto CustomerQueryState::getOutput(const std::string& input) -> std::string {
    std::stringstream output;
    output << "ID\t\tName\t\tPhone\t\t\tAddress" << std::endl;

    for(auto& data : executeQuery(input)) {
        output << CustomerMapper::toString(CustomerMapper::build(data));
    }

    return output.str();
}

auto CustomerQueryState::executeQuery(const std::string& input) -> std::vector<std::vector<std::string>> {
    if (table != nullptr) {
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", input);

        tsv::query::OR finalQuery(&nameQuery, &idQuery);

        return table->select(finalQuery);
    } 
    
    return {};
}