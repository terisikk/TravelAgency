#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table<Agency>* table) {
    this->table = table;
}

auto AgencyQueryState::getOutput() -> std::string {
    return "Enter agency name: ";
}

auto AgencyQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::Query<Agency, std::string> query(input, &Agency::getName);

        std::stringstream output;
        output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

        for(auto& agency : table->select(query)) {
            output << AgencyMapper::toString(agency);
        }

        return output.str();
    }

    return "";
}