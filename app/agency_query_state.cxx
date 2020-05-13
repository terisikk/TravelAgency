#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table<Agency>* table) {
    this->table = table;
}

auto AgencyQueryState::getOutput() -> std::string {
    return "Enter agency name or ID: ";
}

auto AgencyQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        int queryID = -1;

        try {
            queryID = std::stoi(input);
        } catch(...) {
            queryID = -1;
        }

        tsv::Query<Agency> query([input, queryID](Agency& agency) {return agency.getName() == input || agency.getID() == queryID ;});

        std::stringstream output;
        output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

        for(auto& agency : table->select(query)) {
            output << AgencyMapper::toString(agency);
        }

        return output.str();
    }

    return "";
}