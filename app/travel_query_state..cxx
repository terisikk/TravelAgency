#include "travel_query_state.hpp"

TravelQueryState::TravelQueryState(tsv::Table* table) {
    this->table = table;
}

auto TravelQueryState::getOutput() -> std::string {
    return "Enter travel ID: ";
}

auto TravelQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::query::EQ idQuery("ID", input);

        std::stringstream output;
        output << "ID\tDriver ID\tStart Time\t\tCustomer ID\tOrigin\t\tDestination\t\t\tPayment" << std::endl;

        for(auto& data : table->select(idQuery)) {
            output << TravelMapper::toString(TravelMapper::build(data));
        }

        return output.str();
    }

    return "";
}