#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table* table) {
    this->table = table;
}

auto AgencyQueryState::getOutput() -> std::string {
    return "Enter agency name or ID: ";
}

auto AgencyQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", input);

        tsv::query::OR finalQuery(&nameQuery, &idQuery);

        std::stringstream output;
        output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

        for(auto& data : table->select(finalQuery)) {
            output << AgencyMapper::toString(AgencyMapper::build(data));
        }

        return output.str();
    }

    return "";
}