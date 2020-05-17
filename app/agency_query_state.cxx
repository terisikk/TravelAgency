#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table* table) {
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
        
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", queryID);

        tsv::query::OR finalQuery(nameQuery, idQuery);

        std::stringstream output;
        output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

        for(auto& agency : table->select(finalQuery)) {
            output << AgencyMapper::toString(agency);
        }

        return output.str();
    }

    return "";
}