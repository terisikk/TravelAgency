#include "travel_query_state.hpp"

TravelQueryState::TravelQueryState(tsv::Table* table) {
    this->table = table;
}

auto TravelQueryState::getOutput() -> std::string {
    return "Enter customer ID: ";
}

auto TravelQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::query::EQ query("CID", input);

        std::stringstream output;
        output << "ID\tDriver ID\tStart Time\t\tCustomer ID\tOrigin\t\tDestination\t\tPayment" << std::endl;

        for(auto& data : table->select(query, "STIME")) {
            output << TravelMapper::toString(TravelMapper::build(data));
        }

        return output.str();
    }

    return "";
}