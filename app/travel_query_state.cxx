#include "travel_query_state.hpp"

TravelQueryState::TravelQueryState(tsv::Table* table) {
    this->table = table;
}

auto TravelQueryState::getOutput() -> std::string {
    return "Enter customer name or ID: ";
}

auto TravelQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        int queryID = -1;

        try {
            queryID = std::stoi(input);
        } catch(...) {
            queryID = -1;
        }

        tsv::query::EQ query("CID", queryID);

        std::stringstream output;
        output << "ID\t\tDriver ID\t\tStart Time\t\tCustomer ID\t\tOrigin\t\tDestination\t\tPayment" << std::endl;

        for(auto& travel : table->select(query)) {
            output << TravelMapper::toString(travel);
        }

        return output.str();
    }

    return "";
}