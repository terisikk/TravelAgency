#include "travel_for_customer_query_state.hpp"

TravelForCustomerQueryState::TravelForCustomerQueryState(tsv::Table* table) {
    this->table = table;
}

auto TravelForCustomerQueryState::getOutput() -> std::string {
    return "Enter customer ID: ";
}

auto TravelForCustomerQueryState::getOutput(const std::string& input) -> std::string {
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