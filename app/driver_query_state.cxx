#include "driver_query_state.hpp"

DriverQueryState::DriverQueryState(tsv::Table* table) {
    this->table = table;
}

auto DriverQueryState::getOutput() -> std::string {
    return "Enter driver name or ID: ";
}

auto DriverQueryState::getOutput(const std::string& input) -> std::string {
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
        output << "ID\tAgency ID\tName\t\tEmplyoment date\t\tCar model" << std::endl;

        for(auto& driver : table->select(finalQuery)) {
            output << DriverMapper::toString(driver);
        }

        return output.str();
    }

    return "";
}