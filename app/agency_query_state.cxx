#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table* table) {
    this->table = table;
}

auto AgencyQueryState::getOutput() -> std::string {
    return "Enter agency name or ID: ";
}

auto AgencyQueryState::getOutput(const std::string& input) -> std::string {
    std::stringstream output;
    output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

    for(auto& data : executeQuery(input)) {
        output << AgencyMapper::toString(AgencyMapper::build(data));
    }

    return output.str();
}

auto AgencyQueryState::executeQuery(const std::string& input) -> std::vector<std::vector<std::string>> {
    if (table != nullptr) {
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", input);

        tsv::query::OR finalQuery(&nameQuery, &idQuery);

        return table->select(finalQuery);
    } 
    
    return {};
}