#include "delete_travel_state.hpp"

DeleteTravelState::DeleteTravelState(tsv::Table* table) {
    this->table = table;
}

auto DeleteTravelState::getOutput() -> std::string {
    return "Enter travel ID to remove: ";
}

auto DeleteTravelState::getOutput(const std::string& input) -> std::string {
    return executeQuery(input);
}

auto DeleteTravelState::executeQuery(const std::string& input) -> std::string {
    tsv::query::EQ idQuery("ID", input);

    if(table != nullptr) {
        table->remove(idQuery);
        return "Travels removed succesfully.\n";
    }
    
    return "";
}
